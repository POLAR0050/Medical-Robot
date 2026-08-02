#include "LED.h"
#include "DIO.h"

#define LED_PORT PORTC_ID
#define LED_PIN  PIN1

void LED_Init(void)
{
	DIO_SetPinDirection(LED_PORT, LED_PIN, PIN_OUTPUT);
	DIO_SetPinValue(LED_PORT, LED_PIN, PIN_LOW);
}

void LED_On(void)
{
	DIO_SetPinValue(LED_PORT, LED_PIN, PIN_HIGH);
}

void LED_Off(void)
{
	DIO_SetPinValue(LED_PORT, LED_PIN, PIN_LOW);
}

void LED_Toggle(void)
{
	DIO_TogglePinValue(LED_PORT, LED_PIN);
}
