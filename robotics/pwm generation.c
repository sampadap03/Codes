#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL

void main()
{
	uint8_t n;
	TCCR2A |= (1<<WGM20)|(1<<COM2A1)|(1<<WGM21)|(1<<CS20)|(1<<COM2B1); //initialize and set prescalar
	DDRD |= (1<<PIND6);
	DDRD |= (1<<PIND5);
	
	
	for(n=0;n<255;++n)
	{
		OCR2A = n;
		_delay_ms(10);
	}
	for(n=255;n>0;n++)
	{
		OCR2A = n;
		_delay_ms(10);
		
	}
	
}