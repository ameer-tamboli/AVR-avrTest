/*
 * lcd.c
 *
 * 	Created: 09-11-2014 17:39:24
 *  	Author: 
 */ 

#ifndef _LCD_H 
#define _LCD_H
 
#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>



void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void clear_bit(unsigned int);
void set_bit(unsigned int);
void enable(void);
void lcd_string(char *);
void lcd_goto(unsigned int x, unsigned int y);
void lcd_showvalue(unsigned char);



void lcd_init()
{
	DDRA=0xff;
	lcd_cmd(0x28);
	clear_bit(0);
	enable();
	lcd_cmd(0x14);
	lcd_cmd(0x06);
	lcd_cmd(0x0e);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
}

void lcd_cmd(unsigned char ch)
{
	PORTA= (ch&0xf0);
	clear_bit(0);
	enable();
	ch = ch<<4;
	PORTA= (ch&0xf0);
	clear_bit(0);
	enable();	
}


void lcd_data(unsigned char ch)
{
	PORTA= (ch&0xf0);
	set_bit(0);
	enable();
	ch = ch<<4;
	PORTA= (ch&0xf0);
	set_bit(0);
	enable();
}

void clear_bit(unsigned int bit)
{
	PORTA= PORTA&(~(1<<bit));
}


void set_bit(unsigned int bit)
{
	PORTA= PORTA|(1<<bit);
}


void enable(void)
{
	set_bit(2);
	_delay_ms(20);
	clear_bit(2);
	_delay_ms(20);
}

void lcd_string(char *str)
{
	while(*str!='\0')
	{
		lcd_data(*str++);
	}
}


void lcd_goto(unsigned int x, unsigned int y)
{
	if(x==0)
		lcd_cmd(0x80|y);
	if(x==1)
		lcd_cmd(0xc0|y);
}

void lcd_showvalue(unsigned char num)
{
	unsigned char H=0,T=0,O=0;
	H=num/100;
	T=(num - (H*100))/10;
	O=(num - (H*100) - (T*10));
	
	lcd_data(H+48);
	lcd_data(T+48);
	lcd_data(O+48);
}

#endif