const int c1 = 3;
const int c2 = 2;
const int c3 = A5;
const int c4 = A4;
const int ra = 7;
const int rb = 6;
const int rc = 5;
const int rd = 4;

#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int a,b,answer;
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
  //lcd.write(getnumber());
}

void loop() {
/* //if(Serial.available()){
  //  Serial.read();
  a=getnumber();
  lcd.write(a);
  b=getnumber();
  lcd.write(getnumber());
  lcd.write(b);
  lcd.write(getnumber());
  //}
  */
  lcd.write(getnumber());
}
int addition(int x, int y){
  return x+y;
  }

 int subtraction(int x, int y){
  return x-y;
  }

  int multiplication(int x, int y){
    return x*y;
  }

  int division(int x, int y){
    return x/y;
  }

 int getnumber(){
  digitalWrite(ra,LOW); 
  
  if (digitalRead(c1) == LOW) {
    lcd.print("7");
    //return 7;
  }
  if (digitalRead(c2) == LOW){
    lcd.print("8");
    //return 8;
  }
  if (digitalRead(c3) == LOW) 
  {
    lcd.print("9");
    //return 9;
  }
  /*if (digitalRead(c4) == LOW) {
  answer = division(a,b);

  }*/
 
  digitalWrite(ra,HIGH);
  delay(50);
  digitalWrite(rb,LOW);
 
  if (digitalRead(c1) == LOW) {
    lcd.print("4");
    //return 4;
  }
  
  if (digitalRead(c2) == LOW) {
    lcd.print("5");
   // return 5;
  }
  if (digitalRead(c3) == LOW){
    lcd.print("6");
    //return 6;
  }
  /*if (digitalRead(c4) == LOW) {
    answer = multiplication(a,b);
  }
 */
  digitalWrite(rb,HIGH);
 delay(50);
  digitalWrite(rc,LOW);
 
  if (digitalRead(c1) == LOW) {
    lcd.print("1");
    //return 1;
  }
  if (digitalRead(c2) == LOW){
    lcd.print("2");
    //return 2;
  }
  if (digitalRead(c3) == LOW) {
    lcd.print("3");
    //return 3;
  }
  /*if (digitalRead(c4) == LOW) {
    answer = subtraction(a,b);
  }
  */
  digitalWrite(rc,HIGH);
 delay(50);
  digitalWrite(rd,LOW);
 
  if (digitalRead(c1) == LOW) lcd.clear();
  if (digitalRead(c2) == LOW) {
    lcd.print("0");
    //return 0;
  }
  /*if (digitalRead(c3) == LOW) lcd.write(answer);
  if (digitalRead(c4) == LOW) {
    answer = addition(a,b);
  }
  */
  digitalWrite(rd,HIGH);
 
  delay(20);
}


