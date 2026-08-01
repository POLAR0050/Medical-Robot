#include <avr/io.h>
#include <util/delay.h>

#include "SERVO.h"
#include "DIO.h"

#define SERVO_PORT PORTD_ID
#define SERVO_PIN  PIN7

#define SERVO_MIN_PULSE_US 1000   /* 0 ????   */
#define SERVO_MAX_PULSE_US 2000   /* 180 ???? */

void SERVO_Init(void)
{
	DIO_SetPinDirection(SERVO_PORT, SERVO_PIN, PIN_OUTPUT);
	DIO_SetPinValue(SERVO_PORT, SERVO_PIN, PIN_LOW);
}

void SERVO_SetAngle(u8 angle)
{
	u16 pulse_us;
	u16 i;

	if(angle > 180)
	{
		angle = 180;
	}

	pulse_us = SERVO_MIN_PULSE_US + (((u32)angle * (SERVO_MAX_PULSE_US - SERVO_MIN_PULSE_US)) / 180);

	DIO_SetPinValue(SERVO_PORT, SERVO_PIN, PIN_HIGH);

	for(i = 0; i < pulse_us; i++)
	{
		_delay_us(1);
	}

	DIO_SetPinValue(SERVO_PORT, SERVO_PIN, PIN_LOW);
}