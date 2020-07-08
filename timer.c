/*
 * timer.c
 *
 * Created: 02-09-2016 08:37:06
 *  Author: Administrator
 */ 


#include <avr/io.h>
#define sbi(port,bit)	port |= (1<<bit)
#define cbi(port,bit)	port &= ~(1<<bit)
#define cb(port,bit)	port & (1<<bit)

void timer_init()
{
	TCCR1A=0x00;
	sbi(TCCR1B,CS10);
	TCNT1=0xC180;
	
}
int main(void)
{
	unsigned int i; 
	DDRC=0xff;
	PORTC=0xff;
	timer_init();
	sbi(TCCR1B,CS10);
    while(1)
    {
			for(i=0;i<500;i++)
			{
				while(!(cb(TIFR,TOV1)));
				sbi(TIFR,TOV1);
				TCNT1=0xc180;
			}
			PORTC = ~PORTC;
    }
}