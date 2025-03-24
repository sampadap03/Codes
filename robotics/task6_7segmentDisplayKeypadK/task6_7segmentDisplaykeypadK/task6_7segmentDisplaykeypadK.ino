#include<Keypad.h>

const  byte ROWS=4;
const  byte COLS=4;
char keys[ROWS][COLS]={
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'C','0','=','+'}
  };
 const byte rowpins[ROWS]={2,A5,A4,A3};
const  byte colpins[COLS]={6,5,4,3};
 Keypad keypad = Keypad( makeKeymap(keys),rowpins,colpins,ROWS,COLS); 

void setup() {
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);
pinMode(8,OUTPUT);
pinMode(7,OUTPUT);
// SegmentDisplay_CD4511B ssd( 13, 12, 11, 10, 9, 8, 7);
Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  char key=keypad.getKey();
  switch(key)
  {
    case '0':
    digitalWrite(13,1);
    digitalWrite(12,1);
    digitalWrite(11,1);
    digitalWrite(10,1);
    digitalWrite(9,1);
    digitalWrite(8,1);
    digitalWrite(7,0);
    delay(100);
    break;

    case '1':
    digitalWrite(13,0);
    digitalWrite(12,1);
    digitalWrite(11,1);
    digitalWrite(10,0);
    digitalWrite(9,0);
    digitalWrite(8,0);
    digitalWrite(7,0);
    delay(100);
    break;
          
    case '2':
    digitalWrite(13,1);
    digitalWrite(12,1);
    digitalWrite(11,0);
    digitalWrite(10,1);
    digitalWrite(9,1);
    digitalWrite(8,0);
    digitalWrite(7,1);
    delay(100);
    break;

    case '3':
    digitalWrite(13,1);
    digitalWrite(12,1);
    digitalWrite(11,1);
    digitalWrite(10,1);
    digitalWrite(9,0);
    digitalWrite(8,0);
    digitalWrite(7,1);
    delay(100);
    break;

    case '4':
    digitalWrite(13,0);
    digitalWrite(12,1);
    digitalWrite(11,1);
    digitalWrite(10,0);
    digitalWrite(9,0);
    digitalWrite(8,1);
    digitalWrite(7,1);
    delay(100);
    break;

    case '5':
    digitalWrite(13,1);
    digitalWrite(12,0);
    digitalWrite(11,1);
    digitalWrite(10,1);
    digitalWrite(9,0);
    digitalWrite(8,1);
    digitalWrite(7,1);
    delay(100);
    break;

    case '6':
    digitalWrite(13,1);
    digitalWrite(12,0);
    digitalWrite(11,1);
    digitalWrite(10,1);
    digitalWrite(9,1);
    digitalWrite(8,1);
    digitalWrite(7,1);
    delay(100);
    break;

    case '7':
    digitalWrite(13,1);
    digitalWrite(12,1);
    digitalWrite(11,1);
    digitalWrite(10,0);
    digitalWrite(9,0);
    digitalWrite(8,0);
    digitalWrite(7,0);
    delay(100);
    break;

    case '8':
    digitalWrite(13,1);
    digitalWrite(12,1);
    digitalWrite(11,1);
    digitalWrite(10,1);
    digitalWrite(9,1);
    digitalWrite(8,1);
    digitalWrite(7,1);
    delay(100);
    break;

    case '9':
    digitalWrite(13,1);
    digitalWrite(12,1);
    digitalWrite(11,1);
    digitalWrite(10,1);
    digitalWrite(9,0);
    digitalWrite(8,1);
    digitalWrite(7,1);
    delay(100);
    break;

    case '=':
    digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,1);
    digitalWrite(9,0);
    digitalWrite(8,0);
    digitalWrite(7,1);
    delay(100);
    break;

    case 'C':
    digitalWrite(13,1);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,1);
    digitalWrite(9,1);
    digitalWrite(8,1);
    digitalWrite(7,0);
    delay(100);
    break;

    case '-':
    digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,0);
    digitalWrite(9,0);
    digitalWrite(8,0);
    digitalWrite(7,1);
    delay(100);
    break;

    
    }
  }
