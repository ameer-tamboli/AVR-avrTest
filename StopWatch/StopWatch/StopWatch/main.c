/*
 * StopWatch.c
 *
 * Created: 19-03-2019 14:43:42
 * Author : desd
 */ 

#include<avr/io.h>
#include<avr/interrupt.h>
#include "delay.h"


#define LDDR DDRC
#define LPORT PORTC  

#define SDDRD DDRD
#define SPORTD PORTD
#define SPIND PIND

#define BDDR DDRA
#define BPORTA PORTA

void stopWatch(void);
void Switch_6(void);
void Switch_7(void);

//ISR(TIMER1_OVF_vect);

unsigned int count;

int main(void)
{
    /* Replace with your application code */
	DDRC=0xff;
	PORTC=0xff;

	/*TCCR1B=0x05;
	TCNT1=0xc2f5;
	TIMSK=0x04;*/
	sei();
    while (1) 
    {
		//stopWatch();
		//PORTC=~PORTC;
		//delay(1);
		Switch_7();
		Switch_6();
    }
}

ISR(TIMER1_OVF_vect)
{
	cli();
	count++;
	PORTC=~PORTC ;
	TCNT1=0xC2F5;
	TCCR1B=0x05;
/*	if(count==10)
	{
		TCCR1B=0x00;
		TIMSK=0x00;
	}*/
	Switch_6();
	
	//PORTC|=(1<<TOV1);
	sei();
	
}

/*void stopWatch(void)
{
	SDDRD = 0x00;
	SPORTD= 0xff;
	if((PIND&0x80)==0)
	{
		delay_ms(10);
		if((PIND&0x80)==0)	
		{
			Switch_7();
		}
	}
	if((PIND&0x40)==0)
	{
		delay_ms(10);
		if((PIND&0x40)==0)
		{

		}
	}
}*/
void Switch_6(void)
{
	SDDRD=0x00;
	SPORTD=0xff;
	if((PIND&0x40)==0)
	{
		delay_ms(10);
		if((PIND&0x40)==0)
		{
			TCCR1B=0x00;
			TIMSK=0x00;
			cli();
			PORTC=0x0f;
			delay(1);
			PORTC=0xFf;
			delay(1);
			TCCR1B=0x05;
			sei();
		}
	}
}

void Switch_7(void)
{
	DDRD=0x00;
	PORTD=0xff;
	if((PIND&0x80)==0)
	{
		delay_ms(10);
		if((PIND&0x80)==0)
		{
			TCCR1B=0x05;
			TCNT1=0xC2F5;
			TIMSK=0x04;
			sei();
			/*PORTC=0xF3;
			delay(1);
			PORTC=0xFF;
			delay(1);*/
		}
	}
}