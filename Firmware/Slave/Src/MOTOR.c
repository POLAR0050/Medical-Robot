#include <avr/io.h>

#include "MOTOR.h"
#include "DIO.h"



#define M1_IN1 PIN0
#define M1_IN2 PIN1

#define M2_IN1 PIN2
#define M2_IN2 PIN3

#define M3_IN1 PIN4
#define M3_IN2 PIN5

#define M4_IN1 PIN6
#define M4_IN2 PIN7

#define MOTOR_PORT PORTB_ID



static void MOTOR_SetLeftSpeed(u8 speed)
{
	u16 duty;

	if(speed > 100)
	{
		speed = 100;
	}

	duty = ((u16)speed * 255) / 100;

	OCR1AL = (u8)duty;
}

static void MOTOR_SetRightSpeed(u8 speed)
{
	u16 duty;

	if(speed > 100)
	{
		speed = 100;
	}

	duty = ((u16)speed * 255) / 100;

	OCR1BL = (u8)duty;
}

void MOTOR_Init(void)
{
	
	DIO_SetPortDirection(MOTOR_PORT, PORT_OUTPUT);


	DIO_SetPinDirection(PORTD_ID, PIN5, PIN_OUTPUT);
	DIO_SetPinDirection(PORTD_ID, PIN4, PIN_OUTPUT);

	
	TCCR1A = (1<<COM1A1) | (1<<COM1B1) | (1<<WGM10);
	TCCR1B = (1<<WGM12) | (1<<CS11);

	OCR1AL = 0;
	OCR1BL = 0;

	MOTOR_Stop();
}

void MOTOR_Forward(u8 speed)
{
	DIO_SetPinValue(MOTOR_PORT,M1_IN1,PIN_HIGH);
	DIO_SetPinValue(MOTOR_PORT,M1_IN2,PIN_LOW);

	DIO_SetPinValue(MOTOR_PORT,M2_IN1,PIN_HIGH);
	DIO_SetPinValue(MOTOR_PORT,M2_IN2,PIN_LOW);

	DIO_SetPinValue(MOTOR_PORT,M3_IN1,PIN_HIGH);
	DIO_SetPinValue(MOTOR_PORT,M3_IN2,PIN_LOW);

	DIO_SetPinValue(MOTOR_PORT,M4_IN1,PIN_HIGH);
	DIO_SetPinValue(MOTOR_PORT,M4_IN2,PIN_LOW);

	MOTOR_SetSpeed(speed, speed);
}

void MOTOR_Backward(u8 speed)
{
	DIO_SetPinValue(MOTOR_PORT,M1_IN1,PIN_LOW);
	DIO_SetPinValue(MOTOR_PORT,M1_IN2,PIN_HIGH);

	DIO_SetPinValue(MOTOR_PORT,M2_IN1,PIN_LOW);
	DIO_SetPinValue(MOTOR_PORT,M2_IN2,PIN_HIGH);

	DIO_SetPinValue(MOTOR_PORT,M3_IN1,PIN_LOW);
	DIO_SetPinValue(MOTOR_PORT,M3_IN2,PIN_HIGH);

	DIO_SetPinValue(MOTOR_PORT,M4_IN1,PIN_LOW);
	DIO_SetPinValue(MOTOR_PORT,M4_IN2,PIN_HIGH);

	MOTOR_SetSpeed(speed, speed);
}

void MOTOR_Left(u8 speed)
{
	/* ????? ?????? ????? ???? ?????? ????? ???? -> ??? ?????? ???? */
	DIO_SetPinValue(MOTOR_PORT,M1_IN1,PIN_LOW);
	DIO_SetPinValue(MOTOR_PORT,M1_IN2,PIN_HIGH);

	DIO_SetPinValue(MOTOR_PORT,M2_IN1,PIN_LOW);
	DIO_SetPinValue(MOTOR_PORT,M2_IN2,PIN_HIGH);

	DIO_SetPinValue(MOTOR_PORT,M3_IN1,PIN_HIGH);
	DIO_SetPinValue(MOTOR_PORT,M3_IN2,PIN_LOW);

	DIO_SetPinValue(MOTOR_PORT,M4_IN1,PIN_HIGH);
	DIO_SetPinValue(MOTOR_PORT,M4_IN2,PIN_LOW);

	MOTOR_SetSpeed(speed, speed);
}

void MOTOR_Right(u8 speed)
{
	/* ????? ?????? ????? ???? ?????? ????? ???? -> ??? ?????? ???? */
	DIO_SetPinValue(MOTOR_PORT,M1_IN1,PIN_HIGH);
	DIO_SetPinValue(MOTOR_PORT,M1_IN2,PIN_LOW);

	DIO_SetPinValue(MOTOR_PORT,M2_IN1,PIN_HIGH);
	DIO_SetPinValue(MOTOR_PORT,M2_IN2,PIN_LOW);

	DIO_SetPinValue(MOTOR_PORT,M3_IN1,PIN_LOW);
	DIO_SetPinValue(MOTOR_PORT,M3_IN2,PIN_HIGH);

	DIO_SetPinValue(MOTOR_PORT,M4_IN1,PIN_LOW);
	DIO_SetPinValue(MOTOR_PORT,M4_IN2,PIN_HIGH);

	MOTOR_SetSpeed(speed, speed);
}

void MOTOR_SetSpeed(u8 left_speed, u8 right_speed)
{
	MOTOR_SetLeftSpeed(left_speed);
	MOTOR_SetRightSpeed(right_speed);
}

void MOTOR_Stop(void)
{
	DIO_SetPortValue(MOTOR_PORT, 0x00);

	MOTOR_SetSpeed(0, 0);
}
