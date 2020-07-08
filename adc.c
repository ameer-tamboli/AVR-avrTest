 /*
 * adc.c
 *
 * 	Created: 09-11-2014 16:01:40
 *  	 
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
int main(void)
{
	DDRC=0xff;
	PORTC=0xff;
	ADMUX= (1<<REFS0)|(1<<ADLAR);\\0x60 for Reference voltage and Left Adjust Result
	ADCSRA= 0xE7;\\(1<<ADEN)|(1<<ADSC)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)\\ADC Enable , ADC Start Conversion, Prescalar selection
			\\ADCSRA|(1<<ADIE)
	
	
    while(1)
    {
		while(ADCSRA!=(ADCSRA|(1<<ADIF)));
		PORTC= ADCH;
		_delay_ms(100);
           
    }
}