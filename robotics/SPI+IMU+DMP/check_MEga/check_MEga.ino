//Front   
#define d1 6
#define s1 7
//right
#define d2 9
#define s2 10

//left
#define d3 5
#define s3 4
char c;
void setup() {
  Serial.begin(9600);
    
    pinMode(d1, OUTPUT);
    pinMode(s1, OUTPUT);
    pinMode(d2, OUTPUT);
    pinMode(s2, OUTPUT);
    pinMode(d3, OUTPUT);
    pinMode(s3, OUTPUT);

}
double left_motor_speed =50, right_motor_speed = 50;
void loop() {

         /* Serial.println("F");
          //for Front
          digitalWrite(d1, 0);
          analogWrite(s1, 0);
          //for right
          digitalWrite(d2, 0);
          analogWrite(s2, left_motor_speed);
          //for left
          digitalWrite(d3, 1);
          analogWrite(s3, right_motor_speed);**/

  
      Serial.println("B");
      //for front
      digitalWrite(d1, 0);
      analogWrite(s1, 0);
      //for right
      digitalWrite(d2, 1);
      analogWrite(s2, left_motor_speed);
      //for left
      digitalWrite(d3, 0);
      analogWrite(s3, right_motor_speed);
     
  /*  
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
   */
  }


