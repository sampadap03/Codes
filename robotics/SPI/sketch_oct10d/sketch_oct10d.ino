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
  int a;

  // enable Slave Select
  digitalWrite(SS, LOW);    // SS is pin 10

  // send test string
//  for (const char * p = "Hello, world!\n" ; c = *p; p++) {
    SPI.transfer (a);
    Serial.print(a);
  

  // disable Slave Select
  digitalWrite(SS, HIGH);

// delay(1000);
}





