// spi slave

//arduino spi pin
//10 (SS), 11 (MOSI), 12 (MISO), 13 (SCK)
// arduino spi library only use arduino as master
//#include <SPI.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "pins_arduino.h"

#define SDRDY 9 // slave data ready

byte t = 0;
byte r = 0;

void setup() {
   SPI_SlaveInit();
   pinMode(9, OUTPUT);
   digitalWrite(9, LOW);
   Serial.begin(9600);
}

void loop() {
  r = SPI_SlaveReceive();

  t = SPI_SlaveTransmit(r+1);
}

void SPI_SlaveInit(void)
{
   pinMode(MISO, OUTPUT);
   digitalWrite(MISO, LOW);
   SPCR |= _BV(SPE);
} 

char SPI_SlaveReceive(void)
{
  /* Wait for reception complete */
  while(!(SPSR & (1<<SPIF)))
    ;
    digitalWrite(2,HIGH);
    Serial.println("2");
  /* Return Data Register */
  return SPDR;
}

char SPI_SlaveTransmit(byte cData)
{
  /* Start transmission */
  SPDR = cData;
  // assert drdy signal(to master)
  digitalWrite(9, HIGH);
  Serial.println(SPDR);
  /* Wait for transmission complete */
  while(!(SPSR & (1<<SPIF)))
  ;
  
  // deassert drdy signal
  digitalWrite(9, LOW);
  
  return SPDR;  
}

