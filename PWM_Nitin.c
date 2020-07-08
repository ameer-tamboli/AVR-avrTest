/*
 * Timer_1.c
 *
 * Created: 3/2/2017 3:24:27 PM
 *  Author: Nitin
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include<avr/interrupt.h>
void timer_init();


int i=0;
int main(void)
{
	
	DDRA=0b00001000;
	
	timer_init();
    while(1)
    {
		for(int i=0;i<=255;i++)
		{
			OCR3C=i;
			_delay_ms(10);
		}
		for(int i=255;i>=0;i--)
		{
			OCR3C=i;
			_delay_ms(10);
		}
	}
}

void timer_init()
{
	
	TCCR3A|=(1<<WGM30)|(1<<WGM31)|(1<<COM3C1)|(1<<COM3C0);
	TCCR3B|=(1<<CS30)|(1<<WGM32);
	DDRE|=(1<<PE5);
	TCNT3=0;

}
