void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(7,INPUT);
  pinMode(10,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(5,INPUT);

}

void loop() {

if(digitalRead(7)==1)
  {
    digitalWrite(13,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(10,LOW);
  }
  if(digitalRead(7)!=1)
  {
    digitalWrite(13,LOW);
    digitalWrite(8,LOW);
    digitalWrite(12,LOW);
    digitalWrite(10,LOW);
  }
  
}
