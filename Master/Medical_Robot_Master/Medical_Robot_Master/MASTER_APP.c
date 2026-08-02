#include "MASTER_APP.h"

#include <util/delay.h>

#include "LCD.h"
#include "KEYPAD.h"
#include "UART.h"
#include "BLUETOOTH.h"

u16 Room = 0;
u8 Medicine = 0;

u16 MASTER_ReadNumber(void)
{
	u16 Number = 0;
	u8 Key;

	while(1)
	{
		Key = KEYPAD_GetKey();

		if(Key >= '0' && Key <= '9')
		{
			Number = (Number * 10) + (Key - '0');

			LCD_SendData(Key);
		}

		else if(Key == 'C')
		{
			Number = 0;

			LCD_GoTo(1,0);
			LCD_SendString((u8*)"                    ");
			LCD_GoTo(1,0);
		}

		else if(Key == '=')
		{
			return Number;
		}
	}
}

void MASTER_Init(void)
{
	LCD_Init();

	KEYPAD_Init();

	LCD_Clear();
}

void MASTER_Welcome(void)
{
	u8 Key = 0;

	LCD_Clear();

	LCD_GoTo(0,3);
	LCD_SendString((u8*)"Medical Robot");

	LCD_GoTo(1,2);
	LCD_SendString((u8*)"Delivery System");

	LCD_GoTo(2,5);
	LCD_SendString((u8*)"Press =");

	while(1)
	{
		Key = KEYPAD_GetKey();

		if(Key == '=')
		{
			break;
		}

		_delay_ms(20);
	}
}

void MASTER_SelectRoom(void)
{
	LCD_Clear();

	LCD_GoTo(0,0);
	LCD_SendString((u8*)"Enter Room No.");

	LCD_GoTo(1,0);
	LCD_SendString((u8*)"Room : ");

	LCD_GoTo(2,0);

	Room = MASTER_ReadNumber();
}

void MASTER_SelectMedicine(void)
{
	while(1)
	{
		LCD_Clear();

		LCD_GoTo(0,0);
		LCD_SendString((u8*)"Select Medicine");

		LCD_GoTo(1,0);
		LCD_SendString((u8*)"1.Panadol");

		LCD_GoTo(1,11);
		LCD_SendString((u8*)"2.Ins");

		LCD_GoTo(2,0);
		LCD_SendString((u8*)"3.Anti");

		LCD_GoTo(2,11);
		LCD_SendString((u8*)"4.Vit");

		LCD_GoTo(3,0);
		LCD_SendString((u8*)"Choice : ");

		Medicine = KEYPAD_GetKey();

		if(Medicine >= '1' && Medicine <= '4')
		{
			LCD_SendData(Medicine);
			break;
		}
	}
}

void MASTER_StartMission(void)
{
	LCD_Clear();

	LCD_GoTo(0,0);
	LCD_SendString((u8*)"Sending Data...");

	UART_SendChar((Room >> 8) & 0xFF);
	UART_SendChar(Room & 0xFF);

	UART_SendChar(Medicine);

	UART_SendChar('S');

	LCD_Clear();

	LCD_GoTo(0,0);
	LCD_SendString((u8*)"Mission Running");

	LCD_GoTo(1,0);
	LCD_SendString((u8*)"Room : ");
	LCD_SendNumber(Room);

	LCD_GoTo(2,0);
	LCD_SendString((u8*)"Drug : ");
	LCD_SendData(Medicine);
}

void MASTER_WaitResponse(void)
{
	u8 Data;

	Data = UART_ReceiveChar();

	LCD_Clear();

	if(Data == 'K')
	{
		LCD_GoTo(1,2);
		LCD_SendString((u8*)"Mission Done");
	}
	else if(Data == 'E')
	{
		LCD_GoTo(1,2);
		LCD_SendString((u8*)"Mission Error");
	}
	else
	{
		LCD_GoTo(1,2);
		LCD_SendString((u8*)"Unknown Reply");
	}

	_delay_ms(3000);
}