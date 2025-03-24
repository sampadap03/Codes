int r=0;
char c;
    
#define l_w1_d1 13
#define l_w1_d2 12

/*#define l_w2_d1 13
#define l_w2_d2 4

#define r_w1_d1 A2
#define r_w1_d2 12

#define r_w2_d1 7
#define r_w2_d2 A3


#define PWML1 10
#define PWML2 9
/*#define PWMR1 11
#define PWMR2 6
*/
/*#define cutter A0

int cut=0; //D0 is Rx
*/

void setup() {

pinMode(l_w1_d1,OUTPUT);
pinMode(l_w1_d2,OUTPUT);
pinMode(A5,OUTPUT);



Serial.begin(9600);

}

void loop()
{
  //Serial.println("inside loop");
 if(Serial.available()>0)
 {
  Serial.println("inside serial");
 c=Serial.read();
 digitalWrite(A5,HIGH);
 delay(500);
  digitalWrite(A5,LOW);
  delay(500);
   Serial.println(c);
 switch  (c)
 {
  case 'F':
  digitalWrite(l_w1_d1,HIGH);
  digitalWrite(l_w1_d2,LOW);
 
 
 }
 }
}

