//i2c Master(UNO)
#include <Wire.h>
int c;
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println("sdf");
  
  
}

void loop()
{
  Wire.requestFrom(8, 1);
  while(Wire.available())
  {
    //Serial.println("ada");
    c = Wire.read();
    Serial.println(c);
    Serial.println("fljdsfkj");
  }
  
}
