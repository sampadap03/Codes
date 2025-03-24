void setup() {
  pinMode(13,INPUT);
  pinMode(12,OUTPUT);

}

void loop() {
  int count=0;
  int val=0;
  val=digitalRead(13);
  if(val==1)
  {
    count++;
    if(count==2)
    {
      digitalWrite(12,HIGH);
      delay(100);
      
      }
      if(count==3){
        digitalWrite(12,LOW);
        count=0;
        }
    }
  else if(val==0)
  {
    digitalWrite(12,LOW);
    }
}
