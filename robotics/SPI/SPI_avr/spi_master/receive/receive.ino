#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
//defining spi pins pb2-pb5

#define SS 2
#define MOSI 3
#define MISO 4
#define SCK 5

int main(void)
{
  int i = 0;
  DDRC = 0xFF;    //Defining C, and D pins as output
  DDRD = 0xFF;
  DDRB = (1<<MISO);   //Set MISO as o/p
  SPCR = (1<<SPE);   //Enable SPI, MSTR -> 0 SLAVE mode, sck drived by mstr
  
  PORTC = SPDR = i;  // write 0x02 to SPI bus and port c
  while ((SPDR & (1<<SPIF)) == 0)    // it waits for SPIF flag 
  PORTD = SPDR;    //print data received on port D
  
    while(1)
    {
        PORTC = SPDR = i;  // write 0x02 by slave
    while ((SPDR & (1<<SPIF)) == 0);
    PORTD = SPDR; 
    _delay_ms(600);
    i--;
    if (i < 0)
    i=8;
    
    }
}
