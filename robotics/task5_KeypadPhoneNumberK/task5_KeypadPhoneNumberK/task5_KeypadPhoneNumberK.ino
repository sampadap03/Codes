#include<Keypad.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const byte ROWS=4;
const byte COLS=3;
char keys[ROWS][COLS]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','*'}
  };
  byte rowpins[ROWS]={8, 7, 6, A5};
  byte colpins[COLS]={13, 10, 9};
 Keypad keypad = Keypad( makeKeymap(keys),rowpins,colpins,ROWS,COLS); 

void setup() {
  lcd.begin(16,2);
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key=keypad.getKey();
  if(key){
    lcd.print(key);
  }
}
