#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"

void DIO_SetPinDirection(u8 Port,u8 Pin,u8 Direction)
{
	switch(Port)
	{
		case PORT_A:
		if(Direction==OUTPUT)
		SET_BIT(DDRA,Pin);
		else
		CLR_BIT(DDRA,Pin);
		break;

		case PORT_B:
		if(Direction==OUTPUT)
		SET_BIT(DDRB,Pin);
		else
		CLR_BIT(DDRB,Pin);
		break;

		case PORT_C:
		if(Direction==OUTPUT)
		SET_BIT(DDRC,Pin);
		else
		CLR_BIT(DDRC,Pin);
		break;

		case PORT_D:
		if(Direction==OUTPUT)
		SET_BIT(DDRD,Pin);
		else
		CLR_BIT(DDRD,Pin);
		break;
	}
}

void DIO_SetPinValue(u8 Port,u8 Pin,u8 Value)
{
	switch(Port)
	{
		case PORT_A:
		if(Value==HIGH)
		SET_BIT(PORTA,Pin);
		else
		CLR_BIT(PORTA,Pin);
		break;

		case PORT_B:
		if(Value==HIGH)
		SET_BIT(PORTB,Pin);
		else
		CLR_BIT(PORTB,Pin);
		break;

		case PORT_C:
		if(Value==HIGH)
		SET_BIT(PORTC,Pin);
		else
		CLR_BIT(PORTC,Pin);
		break;

		case PORT_D:
		if(Value==HIGH)
		SET_BIT(PORTD,Pin);
		else
		CLR_BIT(PORTD,Pin);
		break;
	}
}

void DIO_TogglePinValue(u8 Port,u8 Pin)
{
	switch(Port)
	{
		case PORT_A: TOG_BIT(PORTA,Pin); break;
		case PORT_B: TOG_BIT(PORTB,Pin); break;
		case PORT_C: TOG_BIT(PORTC,Pin); break;
		case PORT_D: TOG_BIT(PORTD,Pin); break;
	}
}

u8 DIO_GetPinValue(u8 Port,u8 Pin)
{
	switch(Port)
	{
		case PORT_A: return GET_BIT(PINA,Pin);
		case PORT_B: return GET_BIT(PINB,Pin);
		case PORT_C: return GET_BIT(PINC,Pin);
		case PORT_D: return GET_BIT(PIND,Pin);
	}

	return 0;
}
