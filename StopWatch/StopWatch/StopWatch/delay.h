
/*
 * TimerSwitchLED.c
 *
 * Created: 17-03-2019 13:50:12
 * Author : desd
 */ 

#define TOV1 2

void delay(unsigned int);

void delay_ms(unsigned int);

void delay_us(unsigned int);


void delay(unsigned int x)
{
	unsigned int i;
	TCNT1=0xC2F5;
	TCCR1A=0x00;
	TCCR1B=0x05;				//prescale by 1024
	
	for(i=0;i<x;i++)
	{
		while((TIFR&(1<<TOV1))!=0x04);
		TCNT1=0xC2F5;
		TIFR=0x04;
	}
}

void delay_ms(unsigned int x)
{
	unsigned int i;
	TCNT1=0xC180;
	TCCR1A=0x00;
	TCCR1B=0x01;				//no prescale
	
	for(i=0;i<x;i++)
	{
		while((TIFR&(1<<TOV1))!=0x04);
		TCNT1=0xC180;
		TIFR=0x04;
	}
}
void delay_us(unsigned int x)
{
	unsigned int i;
	TCNT1=0x0010;
	TCCR1A=0x00;
	TCCR1B=0x05;				//no prescale
	
	for(i=0;i<x;i++)
	{
		while((TIFR&(1<<TOV1))!=0x04);
		TCNT1=0x0010;
		TIFR=0x04;
	}
}