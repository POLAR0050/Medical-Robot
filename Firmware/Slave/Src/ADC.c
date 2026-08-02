#include "ADC.h"

void ADC_init(void)
{
	ADMUX = 0x40;
	ADCSRA = 0x06;
}

void ADC_voidEnable(void)
{
	ADCSRA |= 0x80;
}

void ADC_voidDisable(void)
{
	ADCSRA &= 0x7F;
}

void ADC_voidStartConversion(u8 addresscpy)
{
	ADMUX &= 0b11000000;
	ADMUX |= addresscpy;
	ADCSRA |= 0x40;
}

u8 ADC_u8ReadADC(void)
{
	while((ADCSRA & 0x10) == 0);

	ADCSRA |= 0x10;

	return ADCH;
}

u16 ADC_u16ReadADCInMV(void)
{
	u16 ADCValue;

	while((ADCSRA & 0x10) == 0);

	ADCSRA |= 0x10;

	ADCValue = ADC;

	return (ADCValue * 5000UL) / 1023;
}
