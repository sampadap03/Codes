int ra = 3; 
int rb = 2; 
int rc = A5 ; 
int rd = A4; 
int c1 = 6; 
int c2 = 5; 
int c3 = 4;
char key;


void setup() {
  pinMode(ra,OUTPUT);
  pinMode(rb,OUTPUT);
  pinMode(rc,OUTPUT);
  pinMode(rd,OUTPUT);
  pinMode(c1,INPUT_PULLUP);
  pinMode(c2,INPUT_PULLUP);
  pinMode(c3,INPUT_PULLUP); 
   
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {
   leerpad();
  switch(key)
  {
    case '0':
    digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,0);
    digitalWrite(9,0);
    digitalWrite(8,0);
    digitalWrite(7,1);
    delay(100);
    break;

    case '1':
    digitalWrite(13,1);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,1);
    digitalWrite(9,1);
    digitalWrite(8,1);
    digitalWrite(7,1);
    delay(100);
    break;
        
    case '2':
    digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,1);
    digitalWrite(10,0);
    digitalWrite(9,0);
    digitalWrite(8,1);
    digitalWrite(7,0);
    delay(100);
    break;

    case '3':
    digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,0);
    digitalWrite(9,1);
    digitalWrite(8,1);
    digitalWrite(7,0);
    delay(100);
    break;

    case '4':
    digitalWrite(13,1);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,1);
    digitalWrite(9,1);
    digitalWrite(8,0);
    digitalWrite(7,0);
    delay(100);
    break;

    case '5':
    digitalWrite(13,0);
    digitalWrite(12,1);
    digitalWrite(11,0);
    digitalWrite(10,0);
    digitalWrite(9,1);
    digitalWrite(8,0);
    digitalWrite(7,0);
    delay(100);
    break;

    case '6':
    digitalWrite(13,0);
    digitalWrite(12,1);
    digitalWrite(11,0);
    digitalWrite(10,0);
    digitalWrite(9,0);
    digitalWrite(8,0);
    digitalWrite(7,0);
    delay(100);
    break;

    case '7':
    digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,1);
    digitalWrite(9,1);
    digitalWrite(8,1);
    digitalWrite(7,1);
    delay(100);
    break;

    case '8':
    digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,0);
    digitalWrite(9,0);
    digitalWrite(8,0);
    digitalWrite(7,0);
    delay(100);
    break;

    case '9':
    digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,0);
    digitalWrite(9,1);
    digitalWrite(8,0);
    digitalWrite(7,0);
    delay(100);
    break;
  }
  }

  void leerpad(){
  digitalWrite(ra,LOW); 
  
  if (digitalRead(c1) == LOW) key='1';
  if (digitalRead(c2) == LOW) key='2';
  if (digitalRead(c3) == LOW) key='3';
  
  digitalWrite(ra,HIGH);
  
 digitalWrite(rb,LOW);
 
  if (digitalRead(c1) == LOW) key='4';
  if (digitalRead(c2) == LOW) key='5';
  if (digitalRead(c3) == LOW) key='6';
  
  digitalWrite(rb,HIGH);
 
 digitalWrite(rc,LOW);
 
  if (digitalRead(c1) == LOW) key='7';
  if (digitalRead(c2) == LOW)key='8';
  if (digitalRead(c3) == LOW) key='9';
  
  digitalWrite(rc,HIGH);
 
  digitalWrite(rd,LOW);
 
  if (digitalRead(c1) == LOW) key='#';
  if (digitalRead(c2) == LOW) key='0';
  if (digitalRead(c3) == LOW) key='#';
  
  digitalWrite(rd,HIGH);
 
  
}



