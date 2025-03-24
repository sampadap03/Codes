const int c1 = 3;
const int c2 = 2;
const int c3 = A5;
const int ra = 7;
const int rb = 6;
const int rc = 5;
const int rd = 4;
int a[6];

int b[] = {"-1","-1","-1","-1","-1","-1"};
int count=0, count2=0;
int i=0;
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

void setup(){
 
  pinMode(ra,OUTPUT);
  pinMode(rb,OUTPUT);
  pinMode(rc,OUTPUT);
  pinMode(rd,OUTPUT);
  pinMode(c1,INPUT_PULLUP);
  pinMode(c2,INPUT_PULLUP);
  pinMode(c3,INPUT_PULLUP); 
  pinMode(A4,OUTPUT);
  pinMode(A3,INPUT);

  a[0]=3;
  a[1]=0;
  a[2]=3;
  a[3]=3;
  a[4]=0;
  a[5]=3;
  lcd.begin(16,2);
  Serial.begin(9600); 
  
}

void loop() {
  getnumber();
    if(digitalRead(A3)==HIGH)
    {
      lcd.clear();
      digitalWrite(A4,LOW);
      count2=0;
      i=0;
      count=0;
    }
}

void getnumber(){
  if(i==6&&count==6)
  {
    lcd.clear();
    lcd.print("Right password");
    digitalWrite(A4,HIGH);
    
  }
 if(i>=6&&count2>=6&&count!=6)
  {
    lcd.clear();
    lcd.print("Wrong password");
    count2=0;
    i=0;
    count=0;
    digitalWrite(A4,LOW);
  }
  
  digitalWrite(ra,LOW); 
  
  if (digitalRead(c1) == LOW) {
    count2++;
    lcd.print("1");
    if(i<6){
      b[i]=1;
      //lcd.print(b[i]);
      //lcd.print(a[i]);
        if(b[i]==a[i])
        {
          count++;
          //lcd.print(count);
        }
        //lcd.print(i);
        i++;
    }
    
  }
  if (digitalRead(c2) == LOW) {
    count2++;
    lcd.print("2");
     if(i<6){
      b[i]=2;
       //lcd.print(b[i]);
      //lcd.print(a[i]);
       if(b[i]==a[i])
        {
          count++;
          //lcd.print(count);
        }
        i++;
    }
    
  }
  if (digitalRead(c3) == LOW) {
    count2++;
    lcd.print("3");
     if(i<6){
      b[i]=3;
      //lcd.print(b[i]);
      //lcd.print(a[i]);
       if(b[i]==a[i])
        {
          count++;
          //lcd.print(count);
        }
        i++;
    }
    
  }
 delay(60);
  digitalWrite(ra,HIGH);
  
 digitalWrite(rb,LOW);
 
  if (digitalRead(c1) == LOW) {
    count2++;
    lcd.print("4");
     if(i<6){
      b[i]=4;
      //lcd.print(b[i]);
      //lcd.print(a[i]);
       if(b[i]==a[i])
        {
          count++;
          //lcd.print(count);
        }
        i++;
    }
    
  }
  if (digitalRead(c2) == LOW) {
    count2++;
    lcd.print("5");
     if(i<6){
      b[i]=5;
      //lcd.print(b[i]);
      //lcd.print(a[i]);
       if(b[i]==a[i])
        {
          count++;
          //lcd.print(count);
        }
        i++;
    }
    
  }
  if (digitalRead(c3) == LOW) {
    count2++;
    lcd.print("6");
     if(i<6){
      b[i]=6;
      //lcd.print(b[i]);
      //lcd.print(a[i]);
       if(b[i]==a[i])
        {
          count++;
          //lcd.print(count);
        }
        i++;
    }
    
  }
  delay(60);
  digitalWrite(rb,HIGH);
 
 digitalWrite(rc,LOW);
 
  if (digitalRead(c1) == LOW) {
    count2++;
    lcd.print("7");
     if(i<6){
      b[i]=7;
       if(b[i]==a[i])
        {
          count++;
        }
        i++;
    }
    
  }
  if (digitalRead(c2) == LOW) {
    count2++;
    lcd.print("8");
     if(i<6){
      b[i]=8;
       if(b[i]==a[i])
        {
          count++;
        }
        i++;
    }
    
  }
  if (digitalRead(c3) == LOW) {
    count2++;
    lcd.print("9");
     if(i<6){
      b[i]=9;
      if(b[i]==a[i])
        {
          count++;
        }
        i++;
    }
    
  }
  delay(60);
  digitalWrite(rc,HIGH);
 
  digitalWrite(rd,LOW);
 
  if (digitalRead(c1) == LOW) {
    count2++;
    b[i]='*';
    i++;
    lcd.print("*");
  }
  if (digitalRead(c2) == LOW) {
    count2++;
    lcd.print("0");
     if(i<6){
      b[i]=0;
      if(b[i]==a[i])
        {
          count++;
        }
        i++;
    }
    
  }
  if (digitalRead(c3) == LOW) {
    count2++;
    b[i]='#';
    i++;
    lcd.print("#");
  }
  
  digitalWrite(rd,HIGH);
  delay(60);
}


