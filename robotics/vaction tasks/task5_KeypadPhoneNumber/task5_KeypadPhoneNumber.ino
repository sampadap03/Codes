const int ra = 4;
const int rb = 3;
const int rc = 2;
const int rd = A5;
const int c1 = 7;
const int c2 = 6;
const int c3 = 5;

#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

void setup(){
 
  pinMode(ra,OUTPUT);
  pinMode(rb,OUTPUT);
  pinMode(rc,OUTPUT);
  pinMode(rd,OUTPUT);
  pinMode(c1,INPUT_PULLUP);
  pinMode(c2,INPUT_PULLUP);
  pinMode(c3,INPUT_PULLUP); 
  lcd.begin(16,2);
  Serial.begin(9600); 
}

void loop(){
  getnumber();
}

void getnumber(){
  digitalWrite(ra,LOW); 
  
  if (digitalRead(c1) == LOW) lcd.print("1");
  if (digitalRead(c2) == LOW) lcd.print("2");
  if (digitalRead(c3) == LOW) lcd.print("3");
 
  digitalWrite(ra,HIGH);
  
 digitalWrite(rb,LOW);
 
  if (digitalRead(c1) == LOW) lcd.print("4");
  if (digitalRead(c2) == LOW) lcd.print("5");
  if (digitalRead(c3) == LOW) lcd.print("6");
  
  digitalWrite(rb,HIGH);
 
 digitalWrite(rc,LOW);
 
  if (digitalRead(c1) == LOW) lcd.print("7");
  if (digitalRead(c2) == LOW) lcd.print("8");
  if (digitalRead(c3) == LOW) lcd.print("9");
  
  digitalWrite(rc,HIGH);
 
  digitalWrite(rd,LOW);
 
  if (digitalRead(c1) == LOW) lcd.print("*");
  if (digitalRead(c2) == LOW) lcd.print("0");
  if (digitalRead(c3) == LOW) lcd.print("#");
  
  digitalWrite(rd,HIGH);
 
  delay(20);
}


