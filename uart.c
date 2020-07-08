/*
 * uart.c
 *
 * 	Created: 09-11-2014 11:37:07
 *  	Author: 
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

void USART_Init( unsigned int ubrr );
unsigned char USART_Receive( void );
void USART_Transmit( unsigned char data );


void main( void )
{
	USART_Init ( MYUBRR );
	DDRC=0xff;
	PORTC=0xff;
	while(1)
	{	unsigned char data;
		
		data= (USART_Receive());
		_delay_ms(20);
		USART_Transmit(data);	
		PORTC= data;
	}
}

void USART_Init( unsigned int ubrr )
{
							/* Set baud rate */
	UBRR1H = (unsigned char)(ubrr>>8);
	UBRR1L = (unsigned char)ubrr;
							/* Enable receiver and transmitter */
	UCSR1B = (1<<RXEN)|(1<<TXEN);
							/* Set frame format: 8data, 2stop bit */
	UCSR1C = (1<<USBS)|(3<<UCSZ0);
}

void USART_Transmit( unsigned char data )
{
							/* Wait for empty transmit buffer */
	while ( !( UCSR1A & (1<<UDRE)) );
							/* Put data into buffer, sends the data */
	UDR1 = data;
}

unsigned char USART_Receive( void )
{
							/* Wait for data to be received */
	while (!(UCSR1A & (1<<RXC)) );
							/* Get and return received data from buffer */	
	return UDR1;
}