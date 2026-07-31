#include "LCD.h"
#include <util/delay.h>

static void LCD_EnablePulse(void)
{
	DIO_SetPinValue(PORT_C,PIN7,HIGH);
	_delay_ms(2);
	DIO_SetPinValue(PORT_C,PIN7,LOW);
}

void LCD_Command(unsigned char cmd)
{
	DIO_SetPinValue(PORT_D,PIN0,(cmd>>0)&1);
	DIO_SetPinValue(PORT_D,PIN1,(cmd>>1)&1);
	DIO_SetPinValue(PORT_D,PIN2,(cmd>>2)&1);
	DIO_SetPinValue(PORT_D,PIN3,(cmd>>3)&1);
	DIO_SetPinValue(PORT_D,PIN4,(cmd>>4)&1);
	DIO_SetPinValue(PORT_D,PIN5,(cmd>>5)&1);
	DIO_SetPinValue(PORT_D,PIN6,(cmd>>6)&1);
	DIO_SetPinValue(PORT_D,PIN7,(cmd>>7)&1);

	DIO_SetPinValue(PORT_C,PIN5,LOW);   // RS
	DIO_SetPinValue(PORT_C,PIN6,LOW);   // RW

	LCD_EnablePulse();

	_delay_ms(2);
}

void LCD_Char(unsigned char data)
{
	DIO_SetPinValue(PORT_D,PIN0,(data>>0)&1);
	DIO_SetPinValue(PORT_D,PIN1,(data>>1)&1);
	DIO_SetPinValue(PORT_D,PIN2,(data>>2)&1);
	DIO_SetPinValue(PORT_D,PIN3,(data>>3)&1);
	DIO_SetPinValue(PORT_D,PIN4,(data>>4)&1);
	DIO_SetPinValue(PORT_D,PIN5,(data>>5)&1);
	DIO_SetPinValue(PORT_D,PIN6,(data>>6)&1);
	DIO_SetPinValue(PORT_D,PIN7,(data>>7)&1);

	DIO_SetPinValue(PORT_C,PIN5,HIGH);  // RS
	DIO_SetPinValue(PORT_C,PIN6,LOW);   // RW

	LCD_EnablePulse();

	_delay_ms(2);
}

void LCD_String(char *str)
{
	while(*str)
	{
		LCD_Char(*str);
		str++;
	}
}

void LCD_Clear(void)
{
	LCD_Command(0x01);
	_delay_ms(2);
}

void LCD_Goto(unsigned char row,unsigned char col)
{
	if(row==0)
	LCD_Command(0x80+col);
	else
	LCD_Command(0xC0+col);
}

void LCD_Number(long num)
{
	char txt[16];
	ltoa(num,txt,10);
	LCD_String(txt);
}

void LCD_Init(void)
{
	
	DIO_SetPinDirection(PORT_D,PIN0,OUTPUT);
	DIO_SetPinDirection(PORT_D,PIN1,OUTPUT);
	DIO_SetPinDirection(PORT_D,PIN2,OUTPUT);
	DIO_SetPinDirection(PORT_D,PIN3,OUTPUT);
	DIO_SetPinDirection(PORT_D,PIN4,OUTPUT);
	DIO_SetPinDirection(PORT_D,PIN5,OUTPUT);
	DIO_SetPinDirection(PORT_D,PIN6,OUTPUT);
	DIO_SetPinDirection(PORT_D,PIN7,OUTPUT);

	DIO_SetPinDirection(PORT_C,PIN5,OUTPUT);
	DIO_SetPinDirection(PORT_C,PIN6,OUTPUT);
	DIO_SetPinDirection(PORT_C,PIN7,OUTPUT);

	_delay_ms(20);

	LCD_Command(0x38);
	LCD_Command(0x0C);
	LCD_Command(0x06);
	LCD_Command(0x01);
}
