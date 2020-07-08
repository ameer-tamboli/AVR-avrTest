/*
 * timerr.c
 *
 * 	Created: 09-11-2014 10:12:56
 *  	Author: Mandar Sabhapatikar
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRC=0xff;
	PORTC=0xaa;
	TCNT1= 0xC2F6;
	TCCR1B= 0b00000101;
	TIMSK= (1<<TOIE1);
	sei();
    while(1)
    {
        
    }
}

ISR(TIMER1_OVF_vect)
{
		PORTC= ~PORTC;
		TCNT1= 0xC2F6;	
}