#include <avr/io.h>

#include "DIO.h"
#include "BIT_MATH.h"

void DIO_SetPinDirection(u8 port, u8 pin, u8 direction)
{
	if(pin <= PIN7)
	{
		switch(port)
		{
			case PORTA_ID:
			if(direction == PIN_OUTPUT)
			SET_BIT(DDRA,pin);
			else
			CLR_BIT(DDRA,pin);
			break;

			case PORTB_ID:
			if(direction == PIN_OUTPUT)
			SET_BIT(DDRB,pin);
			else
			CLR_BIT(DDRB,pin);
			break;

			case PORTC_ID:
			if(direction == PIN_OUTPUT)
			SET_BIT(DDRC,pin);
			else
			CLR_BIT(DDRC,pin);
			break;

			case PORTD_ID:
			if(direction == PIN_OUTPUT)
			SET_BIT(DDRD,pin);
			else
			CLR_BIT(DDRD,pin);
			break;
		}
	}
}

void DIO_SetPinValue(u8 port, u8 pin, u8 value)
{
	if(pin <= PIN7)
	{
		switch(port)
		{
			case PORTA_ID:
			if(value == PIN_HIGH)
			SET_BIT(PORTA,pin);
			else
			CLR_BIT(PORTA,pin);
			break;

			case PORTB_ID:
			if(value == PIN_HIGH)
			SET_BIT(PORTB,pin);
			else
			CLR_BIT(PORTB,pin);
			break;

			case PORTC_ID:
			if(value == PIN_HIGH)
			SET_BIT(PORTC,pin);
			else
			CLR_BIT(PORTC,pin);
			break;

			case PORTD_ID:
			if(value == PIN_HIGH)
			SET_BIT(PORTD,pin);
			else
			CLR_BIT(PORTD,pin);
			break;
		}
	}
}

u8 DIO_GetPinValue(u8 port, u8 pin)
{
	u8 value = PIN_LOW;

	if(pin <= PIN7)
	{
		switch(port)
		{
			case PORTA_ID:
			value = GET_BIT(PINA,pin);
			break;

			case PORTB_ID:
			value = GET_BIT(PINB,pin);
			break;

			case PORTC_ID:
			value = GET_BIT(PINC,pin);
			break;

			case PORTD_ID:
			value = GET_BIT(PIND,pin);
			break;
		}
	}

	return value;
}

void DIO_TogglePinValue(u8 port, u8 pin)
{
	if(pin <= PIN7)
	{
		switch(port)
		{
			case PORTA_ID:
			TOG_BIT(PORTA,pin);
			break;

			case PORTB_ID:
			TOG_BIT(PORTB,pin);
			break;

			case PORTC_ID:
			TOG_BIT(PORTC,pin);
			break;

			case PORTD_ID:
			TOG_BIT(PORTD,pin);
			break;
		}
	}
}

void DIO_SetPortDirection(u8 port, u8 direction)
{
	switch(port)
	{
		case PORTA_ID:
		DDRA = direction;
		break;

		case PORTB_ID:
		DDRB = direction;
		break;

		case PORTC_ID:
		DDRC = direction;
		break;

		case PORTD_ID:
		DDRD = direction;
		break;
	}
}

void DIO_SetPortValue(u8 port, u8 value)
{
	switch(port)
	{
		case PORTA_ID:
		PORTA = value;
		break;

		case PORTB_ID:
		PORTB = value;
		break;

		case PORTC_ID:
		PORTC = value;
		break;

		case PORTD_ID:
		PORTD = value;
		break;
	}
}

u8 DIO_GetPortValue(u8 port)
{
	u8 value = 0;

	switch(port)
	{
		case PORTA_ID:
		value = PINA;
		break;

		case PORTB_ID:
		value = PINB;
		break;

		case PORTC_ID:
		value = PINC;
		break;

		case PORTD_ID:
		value = PIND;
		break;
	}

	return value;
}

void DIO_TogglePortValue(u8 port)
{
	switch(port)
	{
		case PORTA_ID:
		PORTA ^= 0xFF;
		break;

		case PORTB_ID:
		PORTB ^= 0xFF;
		break;

		case PORTC_ID:
		PORTC ^= 0xFF;
		break;

		case PORTD_ID:
		PORTD ^= 0xFF;
		break;
	}
}