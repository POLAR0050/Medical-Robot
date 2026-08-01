#include <util/delay.h>

#include "KEYPAD.h"
#include "DIO.h"

void KEYPAD_Init(void)
{
	u8 pin;

	for(pin=0; pin<4; pin++)
	{
		DIO_SetPinDirection(PORTA_ID,pin,PIN_OUTPUT);
		DIO_SetPinValue(PORTA_ID,pin,PIN_HIGH);
	}

	for(pin=4; pin<8; pin++)
	{
		DIO_SetPinDirection(PORTA_ID,pin,PIN_INPUT);
		DIO_SetPinValue(PORTA_ID,pin,PIN_HIGH);
	}
}

u8 KEYPAD_GetKey(void)
{
	u8 row,column;

	const u8 Keys[4][4]=
	{
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'C','0','=','+'}
	};

	for(row=0; row<4; row++)
	{
		DIO_SetPinValue(PORTA_ID,PIN0,PIN_HIGH);
		DIO_SetPinValue(PORTA_ID,PIN1,PIN_HIGH);
		DIO_SetPinValue(PORTA_ID,PIN2,PIN_HIGH);
		DIO_SetPinValue(PORTA_ID,PIN3,PIN_HIGH);

		DIO_SetPinValue(PORTA_ID,row,PIN_LOW);

		for(column=0; column<4; column++)
		{
			if(DIO_GetPinValue(PORTA_ID,column+4)==PIN_LOW)
			{
				_delay_ms(20);

				if(DIO_GetPinValue(PORTA_ID,column+4)==PIN_LOW)
				{
					while(DIO_GetPinValue(PORTA_ID,column+4)==PIN_LOW);

					_delay_ms(20);

					return Keys[row][column];
				}
			}
		}
	}

	return 0;
}
