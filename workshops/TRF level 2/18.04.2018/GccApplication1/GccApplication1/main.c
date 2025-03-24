	/*
 * GccApplication1.c
 *
 * Created: 18-04-2018 11:34:21
 * Author : HP15-BR011TX
 */ 

#include <avr/io.h>


int main(void)
{
    DDRB=(1<<3) | (0<<2); //replace with your application code
    while (1) 
    {
		//PORTB=0b00000100;
		if((PINB & 0b00000100)==0b00000100)
		{
			
			PORTB=0b00001000;  //(1<<3)
		}
 		else
		 {
		 PORTB=0b00000000;
		 }
    }
}

