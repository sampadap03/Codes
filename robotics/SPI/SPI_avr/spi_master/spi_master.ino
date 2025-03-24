// spi master
//arduino spi pin
//10 (SS), 11 (MOSI), 12 (MISO), 13 (SCK)

#include <SPI.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "pins_arduino.h"

#define SDRDY 9 // slave data ready

#define mackPin PINB3

byte t=0;
byte r=0;
void setup() {
  pinMode(SDRDY, INPUT);
  SPI_MasterInit();
}

void loop() {
  digitalWrite(SS, LOW);
  t = r + 1;
  if (t>=16) t=0;
  t=SPI_MasterTransmit(t);

  //block when slave data is not ready (not write to SPDR yet)  
  while (digitalRead(SDRDY) == LOW)
   ; 

  r = SPI_MasterReceive();

  digitalWrite(SS, HIGH);
}

void SPI_MasterInit(void)
{
  pinMode(SCK, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(SS, OUTPUT);

  digitalWrite(SCK, LOW);
  digitalWrite(MOSI, LOW);
  digitalWrite(SS, HIGH);

  // Warning: if the SS pin ever becomes a LOW INPUT then SPI
  // automatically switches to Slave, so the data direction of
  // the SS pin MUST be kept as OUTPUT.
  SPCR |= _BV(MSTR);
  SPCR |= _BV(SPE);
  
 
  //change it to osc/16
  setClockDivider(SPI_CLOCK_DIV32);  
}

byte SPI_MasterTransmit(byte cData)
{
  /* Start transmission */
  SPDR = cData;
  /* Wait for transmission complete */
  while(!(SPSR & (1<<SPIF)))
  ;
  return SPDR;
}

byte SPI_MasterReceive(void)
{
  SPDR = 0x00;
  /* Wait for reception complete */
  while(!(SPSR & (1<<SPIF)))
    ;
    digitalWrite(2,HIGH);
    delay(2000);
    digitalWrite(2,LOW);
    delay(2000);
    
  /* Return Data Register */
  return SPDR;  
}

void setClockDivider(byte rate)
{
  SPCR = (SPCR & ~SPI_CLOCK_MASK) | (rate & SPI_CLOCK_MASK);
  SPSR = (SPSR & ~SPI_2XCLOCK_MASK) | (rate & SPI_2XCLOCK_MASK);
}
