#define F_CPU
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void setup()
{
  Serial.begin(9600);
}


void spi_init_master (void)
{
    DDRB = (1<<5)|(1<<3);              
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0); 
                                       
}


unsigned char spi_tranceiver (unsigned char data)
{
    SPDR = data;                       
    while(!(SPSR & (1<<SPIF) ));       
    //return(SPDR);  
    Serial.println("transmitted");
    }


//Main
int main(void)
{
    spi_init_master();                  //Initialize SPI Master


    unsigned char data;                 //
  //  uint8_t x = 0;                      //Counter value which is sent

                    //Wait
    
}
