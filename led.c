/*
 * led.c
 *
 * 	Created: 09-11-2014 10:08:06
 *  	Author: Tarun Bharani
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

int main(void)
{
	DDRC=0xff;			//Configure portc as output port
	PORTC= 0x00;
    while(1)
    {
	_delay_ms(1000);
	PORTC=~PORTC;
    }
}