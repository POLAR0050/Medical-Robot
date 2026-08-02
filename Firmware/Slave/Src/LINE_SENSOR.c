#include "LINE_SENSOR.h"
#include "DIO.h"

#define LINE_PORT PORTA_ID

static const u8 LINE_PINS[3] = { PIN1, PIN2, PIN3 };

void LINE_SENSOR_Init(void)
{
	u8 i;

	for(i = 0; i < 3; i++)
	{
		DIO_SetPinDirection(LINE_PORT, LINE_PINS[i], PIN_INPUT);
	}
}

u8 LINE_SENSOR_Read(u8 sensor)
{
	if(sensor > LINE_RIGHT)
	{
		return PIN_LOW;
	}

	return DIO_GetPinValue(LINE_PORT, LINE_PINS[sensor]);
}
