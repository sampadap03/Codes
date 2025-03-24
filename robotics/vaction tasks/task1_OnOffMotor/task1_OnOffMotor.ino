void setup() {
    pinMode(12,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(7,INPUT);
    pinMode(5,INPUT);
}

void loop() {
 
  //Serial.print(digitalRead(A0));

  while(digitalRead(7)==1)
  {
      if(digitalRead(5)==1)
      {
         digitalWrite(12,LOW);
         digitalWrite(8,LOW);
      }
      else
      {
        digitalWrite(12,HIGH);
        }
     if(digitalRead(7)!=1)
     {
        break;
     }      
  }
}
