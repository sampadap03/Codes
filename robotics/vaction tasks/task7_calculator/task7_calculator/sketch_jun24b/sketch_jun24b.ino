const int c1 = 3;
const int c2 = 2;
const int c3 = A5;
const int c4 = A4;
const int ra = 7;
const int rb = 6;
const int rc = 5;
const int rd = 4;
int a=-1,b=-1,answer;
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
  pinMode(c4,INPUT_PULLUP); 
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop(){
  getnumber();
 
}

int add(int x,int y)
{
  return x+y;
}
int sub(int x,int y)
{
  return x-y;
}
int mult(int x,int y)
{
  return x*y;
}
int divn(int x,int y)
{
  return x/y;
}

void getnumber(){
  
  digitalWrite(ra,LOW);
      if (digitalRead(c1) == LOW) {
            lcd.print("7");
            if(a==-1)
            {
              a=7;
            }
            else
            {
              b=7;
            }
            
      }
      if (digitalRead(c2) == LOW) {
            lcd.print("8");
            if(a==-1)
            {
              a=8;
            }
            else
            {
              b=8;
            }
      }
      if (digitalRead(c3) == LOW) {
            lcd.print("9");
            if(a==-1)
            {
              a=9;
            }
            else
            {
              b=9;
            }
      }
      if (digitalRead(c4) == LOW) 
          {
            lcd.setCursor(0,0);
            lcd.clear();
            lcd.print(a);
            lcd.print("/");
            lcd.print(b);
            answer = divn(a,b);
            a=-1;
            b=-1;
          }
  delay(60);
  digitalWrite(ra,HIGH);

  digitalWrite(rb,LOW);
      if (digitalRead(c1) == LOW) {
            lcd.print("4");
            if(a==-1)
            {
              a=4;
            }
            else
            {
              b=4;
            }
      }
      if (digitalRead(c2) == LOW) {
            lcd.print("5");
            if(a==-1)
            {
              a=5;
            }
            else
            {
              b=5;
            }
      }
      if (digitalRead(c3) == LOW) {
            lcd.print("6");
            if(a==-1)
            {
              a=6;
            }
            else
            {
              b=6;
            }
      }
      if (digitalRead(c4) == LOW) 
          {
            lcd.setCursor(0,0);
            lcd.clear();
            lcd.print(a);
            lcd.print("X");
            lcd.print(b);
            answer = mult(a,b);
            a=-1;
            b=-1;
          }
  delay(60);
  digitalWrite(rb,HIGH);
 
  digitalWrite(rc,LOW);
      if (digitalRead(c1) == LOW) {
          lcd.print("1");
          if(a==-1)
          {
            a=1;
          }
          else
          {
            b=1;
          }
        
      }
      if (digitalRead(c2) == LOW) {
          lcd.print("2");
          if(a==-1)
          {
            a=2;
          }
          else
          {
            b=2;
          }
      }
      if (digitalRead(c3) == LOW) {
          lcd.print("3");
          if(a==-1)
          {
            a=3;
          }
          else
          {
            b=3;
          }
      }
      if (digitalRead(c4) == LOW) 
      {
        lcd.setCursor(0,0);
        lcd.clear();
        lcd.print(a);
        lcd.print("-");
        lcd.print(b);
        answer = sub(a,b);
        a=-1;
        b=-1;
      }
  delay(60);
  digitalWrite(rc,HIGH);
 
  digitalWrite(rd,LOW);
 
      if (digitalRead(c1) == LOW) lcd.clear();
      if (digitalRead(c2) == LOW) {
        lcd.print("0");
        if(a==-1)
              {
                a=0;
              }
              else
              {
                b=0;
              }
      }  
      if (digitalRead(c3) == LOW) 
        {
          lcd.print("=");
          lcd.print(answer);
          
         
        }
      if (digitalRead(c4) == LOW) 
      {
        lcd.setCursor(0,0);
        lcd.clear();
        lcd.print(a);
        lcd.print("+");
        lcd.print(b);
        answer = add(a,b);
        a=-1;
        b=-1;
      }
  delay(60);
  digitalWrite(rd,HIGH);

}




