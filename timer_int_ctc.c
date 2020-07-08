/*
 * timer1_interrupt.c
 *
 * Created: 29-09-2014 08:38:59
 *  Author: admin
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRC	= 0XFF;
	PORTC	= 0XFF;
	OCR1B	= 0X3E7F;
	TCNT1	= 0X0000; 
    TIMSK	= 0X08;
	TCCR1B	= 0X0D;
	sei();
	while(1)
    {
        //TODO:: Please write your application code 
    }
}

ISR(TIMER1_COMPB_vect)
{
	PORTC	= ~PORTC;
	TCNT1	= 0x0000;
}