#define F_CPU
#define F_CPU 16000000UL


#include <avr/io.h>
#include <avr/interrupt.h>

void spi_init_slave (void)
{
    DDRB=(1<<6);                                  //MISO as OUTPUT
    SPCR=(1<<SPE);                                //Enable SPI
}


 char spi_tranceiver ()
{
//    SPDR = data;                                  //Load data into buffer
    while(!(SPSR & (1<<SPIF) ));                  //Wait until transmission complete
    return(SPDR);                                 //Return received data
}

int main(void)
{
    spi_init_slave();                             //Initialize slave SPI
     char data, buffer[10];
    
        data = spi_tranceiver();               //Receive data, send ACK
        Serial.print(data);
}
