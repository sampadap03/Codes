//Front   
#define d1 6
#define s1 7
//right
#define d2 9
#define s2 10

//left
#define d3 5
#define s3 4

//0 - clockwise
//1 - anticlockwise
#include <PID_v1.h>
#include <Wire.h>
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
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

//PID variables and all
double setpoint, input, output, Kp = 0.06,Ki= 0, Kd = 0;
char c;
PID myPID(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT);
int error1 = 0;
int flag = 0, flag1 = 0;

double initial_speed_l =50, initial_speed_r=45, headingDegrees ;
double left_motor_speed =50, right_motor_speed=45;
//Serial.println("i am here");
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
    flag = 1; 
    flag1 = 1;

    return (ypr[0] * 180 / M_PI);
    
  }
}
  void setup()
  {
    long int x = millis();
     Serial.begin(9600);
     Serial.println("inside setup");
   #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
    Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(400, true);
#endif
   

    //Serial1.begin(9600);
    pinMode(d1, OUTPUT);
    pinMode(s1, OUTPUT);
    pinMode(d2, OUTPUT);
    pinMode(s2, OUTPUT);
    pinMode(d3, OUTPUT);
    pinMode(s3, OUTPUT);

    
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
      Serial.print(F("DMP Initialization failed (code "));
      Serial.print(devStatus);
      Serial.println(F(")"));
    }

    myPID.SetMode(AUTOMATIC);
    //myPID.SetTuning(Kp,Ki,Kd);
    Serial.println(millis());
    
  }

  //Ourmainprogramloop.
  void loop()
  {
    if((millis())>10000)
    {
      if(flags==0)
      {
      Serial.println(millis());
      setpoint = getyaw();
    
    Serial.print("heading degrees is:  ");
    Serial.println(setpoint);
    flags =1;
      }
    }
    headingDegrees = getyaw();
   //Serial.println(headingDegrees);
   /*
    if(headingDegrees<-2*PI)
      headingDegrees+=2*PI;
     
      if(headingDegrees>2*PI)
      headingDegrees-=2*PI;*/

    //myPID.Compute();
   
    double error1 = setpoint - headingDegrees;
    //Serial.print("Value pf error1:  ");
    output = Kp * error1;
    
    //Serial.println(error1);
    if (error1 > 2 or error1< -2 )
    {
     //Serial.println("in if");
      left_motor_speed = left_motor_speed  - output;
      right_motor_speed = right_motor_speed + output;
      left_motor_speed = constrain(left_motor_speed, 0, 40);
      right_motor_speed = constrain(right_motor_speed, 0, 40);
    }
    else
    {
      //Serial.println("in else :)");
       //digitalWrite(d2, 1);
        //digitalWrite(d3, 0);
      left_motor_speed = initial_speed_l;
      right_motor_speed = initial_speed_r;

    }
    /*char ch;

    if (Serial1.available())
    {
      ch = Serial1.read();
      c=ch;
      Serial.println(c);

    }
 switch (ch)
    {
          flag1 = 0;
        case 'F':*/
          //Serial.println("F");
          //Serial.print("left motor speed:  ");Serial.print(left_motor_speed);Serial.print(" \tright motor speed:  ");Serial.println(right_motor_speed);
          //for Front
          digitalWrite(d1, 0);
          analogWrite(s1, 0);
          //for right
          digitalWrite(d2, 0);
          analogWrite(s2, right_motor_speed);
          //for left
          digitalWrite(d3, 1);
          analogWrite(s3, left_motor_speed);
          Serial.println(right_motor_speed- left_motor_speed);
          Serial. print("error value is:   ");Serial.println(error1);
       /*  
      
      break;

    case 'B':
      Serial.println("B");
      //for front
      digitalWrite(d1, 0);
      analogWrite(s1, 0);
      //for left
      digitalWrite(d2, 1);
      analogWrite(s2, left_motor_speed);
      //for right
      digitalWrite(d3, 1);
      analogWrite(s3, right_motor_speed);
     
    
    break;


  case 'S':
    Serial.println("S");
    //for front
    digitalWrite(d1, 0);
    analogWrite(s1, 0);
    //for left
    digitalWrite(d2, 0);
    analogWrite(s2, 0);
    //for right
    digitalWrite(d3, 0);
    analogWrite(s3, 0);
   
  break;
s
  default:
      Serial.println("G");
      //for front
      digitalWrite(d1, 0);
      analogWrite(s1, 0);
      //for left
      digitalWrite(d2, 0);
      analogWrite(s2, 0);
      //for right
      digitalWrite(d3, 0);
      analogWrite(s3, 0);
   
  }

c = ch;*/
//Serial.flush();
}


