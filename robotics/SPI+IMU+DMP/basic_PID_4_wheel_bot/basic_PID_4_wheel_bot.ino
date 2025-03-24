//TFL
#define d1 4
#define s1 5
//TBL
#define d2 20
#define s2 11
//TFR
#define d3 7
#define s3 6
//TBR
#define d3 7
#define s3 6

//0 - clockwise
//1 - anticlockwise
#include <PID_v1.h>
#include <Wire.h>

//MPU6050 variables
#define INTERRUPT_PIN 2 

//PID variables and all
double setpoint, input, output, Kp=10, Ki=0, Kd=0;

PID myPID(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT);
int error=0;
int flag=0;

double initial_speed = 40;
double left_motor_speed,right_motor_speed;

void setup()
{
      Serial.begin(9600);
      Serial1.begin(9600);
      pinMode(d1, OUTPUT);
      pinMode(s1, OUTPUT);
      pinMode(d2, OUTPUT);
      pinMode(s2, OUTPUT);
      pinMode(d3, OUTPUT);
      pinMode(s3, OUTPUT);
      pinMode(d4, OUTPUT);
      pinMode(s4, OUTPUT);
   
      Serial.println("Starting the I2C interface.");
      
      Wire.begin();//Start the I2C interface.
      myPID.SetMode(AUTOMATIC);
      //myPID.SetTuning(Kp,Ki,Kd);
      

      
      while(flag==0)
        {
        setpoint=getsetpoint();
        }
      
}
//Ourmainprogramloop.
void loop()
{


     
      myPID.Compute();
      
      double error1 = setpoint - headingDegrees;
      if(error1 >2)
      { 
          double left_motor_speed = constrain(initial_speed - output, 0, 50);
          double right_motor_speed = constrain(initial_speed + output, 0, 50);
      }
      else
      {
          left_motor_speed = initial_speed;
          right_motor_speed = initial_speed;
            
      }
char ch;
    
if(Serial1.available())
{
  ch= Serial1.read();
  //Serial.println(c);


switch(ch)
{
  flag1 = 0;
  case 'F':
      Serial.println("F");
      //for TFL
      digitalWrite(d1, 1);
      analogWrite(s1, left_motor_speed); 
      //for TBL
      digitalWrite(d2, 1);
      analogWrite(s2, left_motor_speed);
      //for TFR
      digitalWrite(d3, 0); 
      analogWrite(s3, right_motor_speed);
      //for TBR
      digitalWrite(d4, 0); 
      analogWrite(s4, right_motor_speed);
    }
    break;
 
  case 'B':
  Serial.println("B");
      //for TFL
      digitalWrite(d1, 0);
      analogWrite(s1, left_motor_speed); 
      //for TBL
      digitalWrite(d2, 0);
      analogWrite(s2, left_motor_speed);
      //for TFR
      digitalWrite(d3, 1); 
      analogWrite(s3, right_motor_speed);
      //for TBR
      digitalWrite(d4, 1); 
      analogWrite(s4, right_motor_speed);
    }
    break;

  
    case 'S':  
    Serial.println("S"); 
     //for TFL
      digitalWrite(d1,0);
      analogWrite(s1, 0); 
      //for TBL
      digitalWrite(d2, 0);
      analogWrite(s2, 0);
      //for TFR
      digitalWrite(d3, 0); 
      analogWrite(s3, 0);
      //for TBR
      digitalWrite(d4, 0); 
      analogWrite(s4, 0);  
    
    break; 
    
    default:
    Serial.println("G");
      //for TFL
      digitalWrite(d1,0);
      analogWrite(s1, 0); 
      //for TBL
      digitalWrite(d2, 0);
      analogWrite(s2, 0);
      //for TFR
      digitalWrite(d3, 0); 
      analogWrite(s3, 0);
      //for TBR
      digitalWrite(d4, 0); 
      analogWrite(s4, 0);
    break;
  }


}

      
    


}
