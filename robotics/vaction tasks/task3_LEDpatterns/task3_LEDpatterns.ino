void setup() {
 pinMode(13,OUTPUT);
 pinMode(12,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(5,INPUT);
}

void loop() {
  int i=1,j=1;
  while(digitalRead(5)==1)
  {
  if(i%5==1)
  {
    digitalWrite(7,HIGH);
    delay(100);
  }
   else if(i%5==2)
   {
     digitalWrite(8,HIGH);
     delay(150);     
   }
   else if(i%5==3)
   {
     digitalWrite(12,HIGH);
      delay(100);      
   }
   else if(i%5==4)
   {
    digitalWrite(13,HIGH);
     delay(150);     
   }
   else if(i%5==0)
   {
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
    delay(100);    
   }
    i++;
  }
  }
