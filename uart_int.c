/*
 * uart.c
 *
 * Created: 09-11-2014 11:37:07
 *  Author: admin
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/interrupt.h>

#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1




void USART_Init( unsigned int ubrr );

void main( void )
{
	USART_Init ( MYUBRR );
	DDRC=0xff;
	PORTC=0xff;
	sei();
	while(1)
	{	
	}
}
void USART_Init( unsigned int ubrr )
{
							/* Set baud rate */
	UBRR1H = (unsigned char)(ubrr>>8);
	UBRR1L = (unsigned char)ubrr;
							/* Enable receiver and transmitter */
	UCSR1B = (1<<RXEN)|(1<<TXEN)|(1<<RXCIE);
							/* Set frame format: 8data, 2stop bit */
	UCSR1C = (1<<USBS)|(3<<UCSZ0);
}

ISR(USART1_RX_vect)
{
	PORTC= ~(UDR1-48);	
}

