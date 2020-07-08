/*
 * ext_int.c
 *
 * 	Created: 09-11-2014 14:46:56
 *  	Author: 
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

int main(void)
{	
	DDRE= 0x00;		//Configuring Port E as input
	DDRD=0x00;		//Configuring Port D as input
	PORTE=0xff;		//Enable pull up resistor
	PORTD=0xff;		//Enable pull up resistor
	DDRC=0xff;
	PORTC= 0xff;
	
    while(1)
    {
        if((PINE&0x80)==0x00)
		{
								/*Switch 4 is pressed*/
			_delay_ms(10);				//Debouncing delay
			if((PINE&0x80)==0x00)
				PORTC=0x3F;
				_delay_ms(10);
				
				
		}
		else if((PINE&0x40)==0x00) 
		{
								/*Switch 3 is pressed*/
			_delay_ms(10);				//Debouncing delay
			if((PINE&0x40)==0x00)
				PORTC=0xCF;
		}
		
		else if((PIND&0x80)==0x00) 
		{
								/*Switch 2 is pressed*/
			_delay_ms(10);				//Debouncing delay
			if((PIND&0x80)==0x00)
				PORTC=0xF3;
		}
		else if((PIND&0x40)==0x00) 
		{
								/*Switch 1 is pressed*/
			_delay_ms(10);				//Debouncing delay
			if((PIND&0x40)==0x00)
				PORTC=0xFC;
		}
   }
}