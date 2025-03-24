#include "I2Cdev.h"
//#include "MPU6050.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "Wire.h"
#include "Kalman.h" // Source: https://github.com/TKJElectronics/KalmanFilter

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif
MPU6050 mpu;

#define RESTRICT_PITCH // Comment out to restrict roll to ±90deg instead - please read: http://www.freescale.com/files/sensors/doc/app_note/AN3461.pdf

Kalman kalmanX, kalmanY, kalmanZ; // Create the Kalman instances

const uint8_t MPU6050 = 0x68; // If AD0 is logic low on the PCB the address is 0x68, otherwise set this to 0x69
const uint8_t HMC5883L = 0x1E; // Address of magnetometer
double accX, accY, accZ;
double gyroX, gyroY, gyroZ;
double magX, magY, magZ;
int16_t tempRaw;

double roll, pitch, yaw; // Roll and pitch are calculated using the accelerometer while yaw is calculated using the magnetometer

double gyroXangle, gyroYangle, gyroZangle; // Angle calculate using the gyro only
double compAngleX, compAngleY, compAngleZ; // Calculated angle using a complementary filter
double kalAngleX, kalAngleY, kalAngleZ; // Calculated angle using a Kalman filter

uint32_t timer;
uint8_t i2cData[14]; // Buffer for I2C data

#define MAG0MAX 603
#define MAG0MIN -578

#define MAG1MAX 542
#define MAG1MIN -701

#define MAG2MAX 547
#define MAG2MIN -556

float magOffset[3] = { (MAG0MAX + MAG0MIN) / 2, (MAG1MAX + MAG1MIN) / 2, (MAG2MAX + MAG2MIN) / 2 };
double magGain[3];



// give the addresss as the 0x68 as the AD0 is low
#define OUTPUT_READABLE_YAWPITCHROLL

#define INTERRUPT_PIN 2  // use pin 2 on Arduino Uno & most boards
#define LED_PIN 13 // (Arduino is 13, Teensy is 11, Teensy++ is 6)
bool blinkState = false;

// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
    mpuInterrupt = true;
}

void setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
    delay(100); // Wait for sensors to get ready

  Serial.begin(115200);
  Wire.begin();
  TWBR = ((F_CPU / 400000L) - 16) / 2; // Set I2C frequency to 400kHz

  i2cData[0] = 7; // Set the sample rate to 1000Hz - 8kHz/(7+1) = 1000Hz
  i2cData[1] = 0x00; // Disable FSYNC and set 260 Hz Acc filtering, 256 Hz Gyro filtering, 8 KHz sampling
  i2cData[2] = 0x00; // Set Gyro Full Scale Range to ±250deg/s
  i2cData[3] = 0x00; // Set Accelerometer Full Scale Range to ±2g
  while (i2cWrite(MPU6050, 0x19, i2cData, 4, false)); // Write to all four registers at once
  while (i2cWrite(MPU6050, 0x6B, 0x01, true)); // PLL with X axis gyroscope reference and disable sleep mode

  while (i2cRead(MPU6050, 0x75, i2cData, 1));
  if (i2cData[0] != 0x68) { // Read "WHO_AM_I" register
    Serial.print(F("Error reading sensor"));
    while (1);
  }
  
//=================================================
while (i2cWrite(HMC5883L, 0x02, 0x00, true)); // Configure device for continuous mode
  calibrateMag();

  delay(100); // Wait for sensors to stabilize

  /* Set Kalman and gyro starting angle */
  updateMPU6050();
  updateHMC5883L();
  updatePitchRoll();
  updateYaw();

  kalmanX.setAngle(roll); // First set roll starting angle
  gyroXangle = roll;
  compAngleX = roll;

  kalmanY.setAngle(pitch); // Then pitch
  gyroYangle = pitch;
  compAngleY = pitch;

  kalmanZ.setAngle(yaw); // And finally yaw
  gyroZangle = yaw;
  compAngleZ = yaw;

  timer = micros(); // Initialize the timer
      
    while (!Serial); // wait for Leonardo enumeration, others continue immediately
Serial.println(F("Initializing I2C devices..."));
    mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);

    Serial.println(F("Testing device connections..."));
    Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

  Serial.println(F("\nSend any character to begin DMP programming and demo: "));
    while (Serial.available() && Serial.read()); // empty buffer
    while (!Serial.available());                 // wait for data
    while (Serial.available() && Serial.read()); // empty buffer again
Serial.println(F("Initializing DMP..."));
    devStatus = mpu.dmpInitialize();

 mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1788); // 1688 factory default for my test chip
    if (devStatus == 0) 
    {
        // turn on the DMP, now that it's ready
        Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);

        // enable Arduino interrupt detection
        Serial.print(F("Enabling interrupt detection (Arduino external interrupt "));
        Serial.print(digitalPinToInterrupt(INTERRUPT_PIN));
        Serial.println(F(")..."));
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();

        // set our DMP Ready flag so the main loop() function knows it's okay to use it
        Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;
 packetSize = mpu.dmpGetFIFOPacketSize();
    } else {
        // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }
}


void loop() {
 updateMPU6050();
  updateHMC5883L();

  double dt = (double)(micros() - timer) / 1000000; // Calculate delta time
  timer = micros();


  /* Roll and pitch estimation */
  updatePitchRoll();
  double gyroXrate = gyroX / 131.0; // Convert to deg/s
  double gyroYrate = gyroY / 131.0; // Convert to deg/s

#ifdef RESTRICT_PITCH
  // This fixes the transition problem when the accelerometer angle jumps between -180 and 180 degrees
  if ((roll < -90 && kalAngleX > 90) || (roll > 90 && kalAngleX < -90)) {
    kalmanX.setAngle(roll);
    compAngleX = roll;
    kalAngleX = roll;
    gyroXangle = roll;
  } else
    kalAngleX = kalmanX.getAngle(roll, gyroXrate, dt); // Calculate the angle using a Kalman filter

  if (abs(kalAngleX) > 90)
    gyroYrate = -gyroYrate; // Invert rate, so it fits the restricted accelerometer reading
  kalAngleY = kalmanY.getAngle(pitch, gyroYrate, dt);
#else
  // This fixes the transition problem when the accelerometer angle jumps between -180 and 180 degrees
  if ((pitch < -90 && kalAngleY > 90) || (pitch > 90 && kalAngleY < -90)) {
    kalmanY.setAngle(pitch);
    compAngleY = pitch;
    kalAngleY = pitch;
    gyroYangle = pitch;
  } else
    kalAngleY = kalmanY.getAngle(pitch, gyroYrate, dt); // Calculate the angle using a Kalman filter

  if (abs(kalAngleY) > 90)
    gyroXrate = -gyroXrate; // Invert rate, so it fits the restricted accelerometer reading
  kalAngleX = kalmanX.getAngle(roll, gyroXrate, dt); // Calculate the angle using a Kalman filter
#endif


  /* Yaw estimation */
  updateYaw();
  double gyroZrate = gyroZ / 131.0; // Convert to deg/s
  // This fixes the transition problem when the yaw angle jumps between -180 and 180 degrees
  if ((yaw < -90 && kalAngleZ > 90) || (yaw > 90 && kalAngleZ < -90)) {
    kalmanZ.setAngle(yaw);
    compAngleZ = yaw;
    kalAngleZ = yaw;
    gyroZangle = yaw;
  } else
    kalAngleZ = kalmanZ.getAngle(yaw, gyroZrate, dt); // Calculate the angle using a Kalman filter


  /* Estimate angles using gyro only */
  gyroXangle += gyroXrate * dt; // Calculate gyro angle without any filter
  gyroYangle += gyroYrate * dt;
  gyroZangle += gyroZrate * dt;
  //gyroXangle += kalmanX.getRate() * dt; // Calculate gyro angle using the unbiased rate from the Kalman filter
  //gyroYangle += kalmanY.getRate() * dt;
  //gyroZangle += kalmanZ.getRate() * dt;

  /* Estimate angles using complimentary filter */
  compAngleX = 0.93 * (compAngleX + gyroXrate * dt) + 0.07 * roll; // Calculate the angle using a Complimentary filter
  compAngleY = 0.93 * (compAngleY + gyroYrate * dt) + 0.07 * pitch;
  compAngleZ = 0.92 * (compAngleZ + gyroZrate * dt) + 0.08 * yaw;

  // Reset the gyro angles when they has drifted too much
  if (gyroXangle < -180 || gyroXangle > 180)
    gyroXangle = kalAngleX;
  if (gyroYangle < -180 || gyroYangle > 180)
    gyroYangle = kalAngleY;
  if (gyroZangle < -180 || gyroZangle > 180)
    gyroZangle = kalAngleZ;


  /* Print Data */
#if 1

Serial.print(yaw); Serial.print("\t");
  //Serial.print(gyroZangle); Serial.print("\t");
  Serial.print(compAngleZ); Serial.print("\t");
  Serial.print(kalAngleZ); Serial.print("\t");
#endif
#if 0 // Set to 1 to print the IMU data
  Serial.print(accX / 16384.0); Serial.print("\t"); // Converted into g's
  Serial.print(accY / 16384.0); Serial.print("\t");
  Serial.print(accZ / 16384.0); Serial.print("\t");

  Serial.print(gyroXrate); Serial.print("\t"); // Converted into degress per second
  Serial.print(gyroYrate); Serial.print("\t");
  Serial.print(gyroZrate); Serial.print("\t");

  Serial.print(magX); Serial.print("\t"); // After gain and offset compensation
  Serial.print(magY); Serial.print("\t");
  Serial.print(magZ); Serial.print("\t");
#endif
#if 0 // Set to 1 to print the temperature
  Serial.print("\t");
  
#endif
Serial.println();

  delay(10);


  

    // if programming failed, don't try to do anything
    if (!dmpReady) 
    return;

    // wait for MPU interrupt or extra packet(s) available
    while (!mpuInterrupt && fifoCount < packetSize) {
        if (mpuInterrupt && fifoCount < packetSize) {
          // try to get out of the infinite loop 
          fifoCount = mpu.getFIFOCount();
        }  
    }
          mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();

    // get current FIFO count
    fifoCount = mpu.getFIFOCount();


if ((mpuIntStatus & _BV(MPU6050_INTERRUPT_FIFO_OFLOW_BIT)) || fifoCount >= 1024) {
        // reset so we can continue cleanly
        mpu.resetFIFO();
        fifoCount = mpu.getFIFOCount();
        Serial.println(F("FIFO overflow!"));
}

else if (mpuIntStatus & _BV(MPU6050_INTERRUPT_DMP_INT_BIT)) {
        // wait for correct available data length, should be a VERY short wait
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
                mpu.getFIFOBytes(fifoBuffer, packetSize);
      
fifoCount -= packetSize;

        #ifdef OUTPUT_READABLE_QUATERNION
            // display quaternion values in easy matrix form: w x y z
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            Serial.print("quat\t");
            Serial.print(q.w);
            Serial.print("\t");
            Serial.print(q.x);
            Serial.print("\t");
            Serial.print(q.y);
            Serial.print("\t");
            Serial.println(q.z);
        #endif

        #ifdef OUTPUT_READABLE_EULER
            // display Euler angles in degrees
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetEuler(euler, &q);
            Serial.print("euler\t");
            Serial.print(euler[0] * 180/M_PI);
            Serial.print("\t");
            Serial.print(euler[1] * 180/M_PI);
            Serial.print("\t");
            Serial.println(euler[2] * 180/M_PI);
        #endif

 #ifdef OUTPUT_READABLE_YAWPITCHROLL
            // display Euler angles in degrees
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
            Serial.print("ypr\t");
            Serial.print(ypr[0] * 180/M_PI);
            Serial.print("\t");
            Serial.print(ypr[1] * 180/M_PI);
            Serial.print("\t");
            Serial.println(ypr[2] * 180/M_PI);
        #endif

    }
    }
  

//======================================================================================================
void updateMPU6050() {
  while (i2cRead(MPU6050, 0x3B, i2cData, 14)); // Get accelerometer and gyroscope values
  accX = ((i2cData[0] << 8) | i2cData[1]);
  accY = -((i2cData[2] << 8) | i2cData[3]);
  accZ = ((i2cData[4] << 8) | i2cData[5]);
  tempRaw = (i2cData[6] << 8) | i2cData[7];
  gyroX = -(i2cData[8] << 8) | i2cData[9];
  gyroY = (i2cData[10] << 8) | i2cData[11];
  gyroZ = -(i2cData[12] << 8) | i2cData[13];
}

void updateHMC5883L() {
  while (i2cRead(HMC5883L, 0x03, i2cData, 6)); // Get magnetometer values
  magX = ((i2cData[0] << 8) | i2cData[1]);
  magZ = ((i2cData[2] << 8) | i2cData[3]);
  magY = ((i2cData[4] << 8) | i2cData[5]);
}

void updatePitchRoll() {
  // Source: http://www.freescale.com/files/sensors/doc/app_note/AN3461.pdf eq. 25 and eq. 26
  // atan2 outputs the value of -π to π (radians) - see http://en.wikipedia.org/wiki/Atan2
  // It is then converted from radians to degrees
#ifdef RESTRICT_PITCH // Eq. 25 and 26
  roll = atan2(accY, accZ) * RAD_TO_DEG;
  pitch = atan(-accX / sqrt(accY * accY + accZ * accZ)) * RAD_TO_DEG;
#else // Eq. 28 and 29
  roll = atan(accY / sqrt(accX * accX + accZ * accZ)) * RAD_TO_DEG;
  pitch = atan2(-accX, accZ) * RAD_TO_DEG;
#endif
}

void updateYaw() { // See: http://www.freescale.com/files/sensors/doc/app_note/AN4248.pdf
  magX *= -1; // Invert axis - this it done here, as it should be done after the calibration
  magZ *= -1;

  magX *= magGain[0];
  magY *= magGain[1];
  magZ *= magGain[2];

  magX -= magOffset[0];
  magY -= magOffset[1];
  magZ -= magOffset[2];

  double rollAngle = kalAngleX * DEG_TO_RAD;
  double pitchAngle = kalAngleY * DEG_TO_RAD;

  double Bfy = magZ * sin(rollAngle) - magY * cos(rollAngle);
  double Bfx = magX * cos(pitchAngle) + magY * sin(pitchAngle) * sin(rollAngle) + magZ * sin(pitchAngle) * cos(rollAngle);
  yaw = atan2(-Bfy, Bfx) * RAD_TO_DEG;

  yaw *= -1;
}

void calibrateMag() { // Inspired by: https://code.google.com/p/open-headtracker/
  i2cWrite(HMC5883L, 0x00, 0x11, true);
  delay(100); // Wait for sensor to get ready
  updateHMC5883L(); // Read positive bias values

  int16_t magPosOff[3] = { magX, magY, magZ };

  i2cWrite(HMC5883L, 0x00, 0x12, true);
  delay(100); // Wait for sensor to get ready
  updateHMC5883L(); // Read negative bias values

  int16_t magNegOff[3] = { magX, magY, magZ };

  i2cWrite(HMC5883L, 0x00, 0x10, true); // Back to normal

  magGain[0] = -2500 / float(magNegOff[0] - magPosOff[0]);
  magGain[1] = -2500 / float(magNegOff[1] - magPosOff[1]);
  magGain[2] = -2500 / float(magNegOff[2] - magPosOff[2]);

#if 0
  Serial.print("Mag cal: ");
  Serial.print(magNegOff[0] - magPosOff[0]);
  Serial.print(",");
  Serial.print(magNegOff[1] - magPosOff[1]);
  Serial.print(",");
  Serial.println(magNegOff[2] - magPosOff[2]);

  Serial.print("Gain: ");
  Serial.print(magGain[0]);
  Serial.print(",");
  Serial.print(magGain[1]);
  Serial.print(",");
  Serial.println(magGain[2]);
#endif
}



