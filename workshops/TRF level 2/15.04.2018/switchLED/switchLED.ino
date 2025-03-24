/*
TRF LEVEL 2: SUBMISSION 1
DATE: 15/04/2018
Topic: Generate a blinking LED using switch on ARDUINO in PROTEUS
Author: SAMPADA PETKAR
*/
void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,INPUT);
  
}
void loop() {
int val3=0;
  val3=digitalRead(12);
 
  if(val3==1)   //LED will be ON when switch is closed and vise versa
  {
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
  }
else if(val3==0)
{
  digitalWrite(13,LOW);
}

}
