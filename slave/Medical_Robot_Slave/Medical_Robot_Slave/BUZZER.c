#include "BUZZER.h"
#include "DIO.h"

#define BUZZER_PORT PORTC_ID
#define BUZZER_PIN  PIN2

void BUZZER_Init(void)
{
	DIO_SetPinDirection(BUZZER_PORT, BUZZER_PIN, PIN_OUTPUT);
	DIO_SetPinValue(BUZZER_PORT, BUZZER_PIN, PIN_LOW);
}

void BUZZER_On(void)
{
	DIO_SetPinValue(BUZZER_PORT, BUZZER_PIN, PIN_HIGH);
}

void BUZZER_Off(void)
{
	DIO_SetPinValue(BUZZER_PORT, BUZZER_PIN, PIN_LOW);
}