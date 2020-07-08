/*
 * adc.c
 *
 * 	Created: 09-11-2014 16:01:40
 *  	Author: 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRC=0xff;			//Configure Port C as ouput
	PORTC=0xff;			
	ADMUX= 0xc0;			//Setting up ADC0
	ADCSRA= 0xEF;
	sei();
	
    while(1)
    {      
    }
}

ISR(ADC_vect)
{
	cli();
	PORTC= ADCH;
	sei();
}