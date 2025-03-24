#include <Encoder.h>
Encoder myEnc(5, 6);
void setup() {
  Serial.begin(9600);
  digitalWrite(IN1, LOW);//max left
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);//max right
    digitalWrite(IN4, HIGH);
  Serial.println("Basic Encoder Test:");
}
long oldPosition  = -999;

void loop() {
 long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.println(newPosition);
  }

}

void up()
{
  
  }
