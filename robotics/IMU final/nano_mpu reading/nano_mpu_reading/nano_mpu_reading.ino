 #include <Wire.h>
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
//  #include <Wire.h>
#endif
MPU6050 mpu;

#define OUTPUT_READABLE_YAWPITCHROLL
int flags =0;
//MPU6050 variables
#define INTERRUPT_PIN 2
// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO

uint8_t fifoBuffer[64]; // FIFO storage buffer
// orientation/motion vars
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

char c;
float setpoint;
bool flag_setpoint = 0;
int headingdegrees;

double getyaw()
{
  if (!dmpReady) return;


  while (!mpuInterrupt && fifoCount < packetSize) {
    if (mpuInterrupt && fifoCount < packetSize) {
      // try to get out of the infinite loop
      fifoCount = mpu.getFIFOCount();
    }
  }


  mpuInterrupt = false;
  mpuIntStatus = mpu.getIntStatus();

  fifoCount = mpu.getFIFOCount();

  if ((mpuIntStatus & _BV(MPU6050_INTERRUPT_FIFO_OFLOW_BIT)) || fifoCount >= 1024) {
    // reset so we can continue cleanly
    mpu.resetFIFO();
    fifoCount = mpu.getFIFOCount();
    Serial.println(F("FIFO overflow!"));
  }
  else if (mpuIntStatus & _BV(MPU6050_INTERRUPT_DMP_INT_BIT)) {

    while (fifoCount < packetSize) 
    fifoCount = mpu.getFIFOCount();
    mpu.getFIFOBytes(fifoBuffer, packetSize);

    fifoCount -= packetSize;
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
   
    return (ypr[0] * 180 / M_PI);
    
  }
}
  void setup()
  {
    long int x = millis();
     Serial.begin(9600);
     Serial.println("inside setup");
  // #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    //Wire.begin();
    //Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
//#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
//    Fastwire::setup(400, true);
//#endif
   
    //I2C communication
    Wire.begin(8);      //join I2C for address 8 or any you have to send
   // Wire.onRequest(requestEvent);   //event
     
    while (!Serial);
    Serial.println(F("Initializing I2C devices..."));
    mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);

    Serial.println(F("Testing device connections..."));
    Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));
    devStatus = mpu.dmpInitialize();
    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1788);

    if (devStatus == 0)
    {

      Serial.println(F("Enabling DMP..."));
      mpu.setDMPEnabled(true);


      Serial.print(F("Enabling interrupt detection (Arduino external interrupt "));
      Serial.print(digitalPinToInterrupt(INTERRUPT_PIN));
      Serial.println(F(")..."));
      attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
      mpuIntStatus = mpu.getIntStatus();


      Serial.println(F("DMP ready! Waiting for first interrupt..."));
      dmpReady = true;


      packetSize = mpu.dmpGetFIFOPacketSize();
    }
    else {
      // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
      Serial.print(F("DMP Initialization failed (code "));
      Serial.print(devStatus);
      Serial.println(F(")"));
    }

   
    Serial.println(millis());
    
  }

  //Ourmainprogramloop.
  void loop()
  {

    if(millis()>10000 && flag_setpoint == 0)
    {
      setpoint = getyaw();
      flag_setpoint =1;
    }
    headingdegrees = getyaw();
     Serial.println(headingdegrees);
    if(headingdegrees<(-2) || headingdegrees>2)
    {
      Serial.println("sd");
      Wire.begin(8);
       Wire.onRequest(requestEvent);
    }
  }

  void requestEvent()
{
  //Wire.write();
  Wire.write(headingdegrees);

}
