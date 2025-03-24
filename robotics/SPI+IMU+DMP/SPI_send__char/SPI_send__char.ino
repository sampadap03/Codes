#include <SPI.h>

void setup (void)
{
  Serial.begin(115200);
  digitalWrite(SS, HIGH);
  SPI.begin ();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
}

void loop (void)
{
  int a=360;

  // enable Slave Select
  digitalWrite(SS, LOW);    // SS is pin 10
  // send test string
//  for (const char * p = "Hello, world!\n" ; c = *p; p++) {
    SPI.transfer(a%10);
    Serial.println(a%10);
 
  // disable Slave Select
  digitalWrite(SS, HIGH);
digitalWrite(SS, LOW);
   SPI.transfer(a/10);
    Serial.println(a/10);
    
digitalWrite(SS, HIGH);
 delay (20);
}
