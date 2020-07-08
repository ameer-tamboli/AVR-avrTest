/*
 * timerr.c
 *
 * 	Created: 09-11-2014 10:12:56
 *  	
 */ 

#include <avr/io.h>

int main(void)
{
	DDRC=0xff;
	PORTC=0xaa;
	TCNT1= 0x0000;
	OCR1B= 0x3E7F;
	TCCR1B=(1<<WGM12)|(1<<CS10);//ctc mode and clock with no prescalar
    while(1)
    {
		
		for(i=0;i<500;i++)
			{
				while(TIFR!=(TIFR|(1<<OCF1B)));
		
				TIFR|=(1<<OCF1B);
				TCNT1=0x0000;
			}
		PORTC= ~PORTC;
    }
}