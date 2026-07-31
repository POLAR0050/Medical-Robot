#include "Keypad.h"
#include <util/delay.h>
char Keys[4][4]=
{
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'C','0','=','+'}
};

void Keypad_Init(void)
{
	
	DIO_SetPinDirection(PORT_B,PIN7,OUTPUT);
	DIO_SetPinDirection(PORT_B,PIN6,OUTPUT);
	DIO_SetPinDirection(PORT_B,PIN5,OUTPUT);
	DIO_SetPinDirection(PORT_B,PIN4,OUTPUT);

	
	DIO_SetPinDirection(PORT_B,PIN3,INPUT);
	DIO_SetPinDirection(PORT_B,PIN2,INPUT);
	DIO_SetPinDirection(PORT_B,PIN1,INPUT);
	DIO_SetPinDirection(PORT_B,PIN0,INPUT);

	
	DIO_SetPinValue(PORT_B,PIN3,HIGH);
	DIO_SetPinValue(PORT_B,PIN2,HIGH);
	DIO_SetPinValue(PORT_B,PIN1,HIGH);
	DIO_SetPinValue(PORT_B,PIN0,HIGH);

	
	DIO_SetPinValue(PORT_B,PIN7,HIGH);
	DIO_SetPinValue(PORT_B,PIN6,HIGH);
	DIO_SetPinValue(PORT_B,PIN5,HIGH);
	DIO_SetPinValue(PORT_B,PIN4,HIGH);
}

char Keypad_GetKey(void)
{
	unsigned char row,col;

	while(1)
	{
		for(row=0; row<4; row++)
		{
			
			DIO_SetPinValue(PORT_B,PIN7,HIGH);
			DIO_SetPinValue(PORT_B,PIN6,HIGH);
			DIO_SetPinValue(PORT_B,PIN5,HIGH);
			DIO_SetPinValue(PORT_B,PIN4,HIGH);

			
			DIO_SetPinValue(PORT_B,PIN7-row,LOW);

			for(col=0; col<4; col++)
			{
				if(DIO_GetPinValue(PORT_B,col)==LOW)
				{
					_delay_ms(20);

					while(DIO_GetPinValue(PORT_B,col)==LOW);

					return Keys[row][col];
				}
			}
		}
	}
}
