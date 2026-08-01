#include <util/delay.h>

#include "LCD.h"
#include "DIO.h"

void LCD_SendCommand(u8 command)
{
	DIO_SetPinValue(PORTC_ID,PIN6,PIN_LOW);
	DIO_SetPinValue(PORTC_ID,PIN5,PIN_LOW);

	DIO_SetPortValue(PORTB_ID,command);

	DIO_SetPinValue(PORTC_ID,PIN7,PIN_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(PORTC_ID,PIN7,PIN_LOW);
	_delay_ms(100);
}

void LCD_SendData(u8 data)
{
	DIO_SetPinValue(PORTC_ID,PIN6,PIN_HIGH);
	DIO_SetPinValue(PORTC_ID,PIN5,PIN_LOW);

	DIO_SetPortValue(PORTB_ID,data);

	DIO_SetPinValue(PORTC_ID,PIN7,PIN_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(PORTC_ID,PIN7,PIN_LOW);
	_delay_ms(100);
}

void LCD_Init(void)
{
	DIO_SetPinDirection(PORTC_ID,PIN5,PIN_OUTPUT);
	DIO_SetPinDirection(PORTC_ID,PIN6,PIN_OUTPUT);
	DIO_SetPinDirection(PORTC_ID,PIN7,PIN_OUTPUT);

	DIO_SetPortDirection(PORTB_ID,PORT_OUTPUT);

	_delay_ms(50);

	LCD_SendCommand(0x38);
	_delay_ms(5);

	LCD_SendCommand(0x0C);
	_delay_ms(5);

	LCD_SendCommand(0x01);
	_delay_ms(5);

	LCD_SendCommand(0x06);
	_delay_ms(5);
}

void LCD_SendString(u8 *str)
{
	while(*str)
	{
		LCD_SendData(*str);
		str++;
	}
}

void LCD_Clear(void)
{
	LCD_SendCommand(0x01);
	_delay_ms(2);
}

void LCD_GoTo(u8 row,u8 column)
{
	switch(row)
	{
		case 0:
		LCD_SendCommand(0x80+column);
		break;

		case 1:
		LCD_SendCommand(0xC0+column);
		break;

		case 2:
		LCD_SendCommand(0x94+column);
		break;

		case 3:
		LCD_SendCommand(0xD4+column);
		break;
	}
}

void LCD_SendNumber(s32 number)
{
	u8 buffer[12];
	u8 i=0,j;
	u8 temp;
	u32 value;

	if(number==0)
	{
		LCD_SendData('0');
		return;
	}

	if(number<0)
	{
		LCD_SendData('-');
		value=-number;
	}
	else
	{
		value=number;
	}

	while(value>0)
	{
		buffer[i++]=(value%10)+'0';
		value/=10;
	}

	for(j=0;j<i/2;j++)
	{
		temp=buffer[j];
		buffer[j]=buffer[i-j-1];
		buffer[i-j-1]=temp;
	}

	buffer[i]='\0';

	LCD_SendString(buffer);
}
