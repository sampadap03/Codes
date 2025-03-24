//i2c Slave(LEONARDO)
#include <Wire.h>
int i= 45;
char str[10];
void setup()
{
  Serial.begin(9600);
  Wire.begin(8);
  Wire.onRequest(requestEvent);
}

void loop()
{
  Serial.write("started");
  itoa(i, str, 10);
  
  Serial.println("sent");
}

void requestEvent()
{
  Wire.write(78);
  //Wire.write("\r\n");
}
