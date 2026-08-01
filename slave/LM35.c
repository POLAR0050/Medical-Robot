#include "LM35.h"
#include "ADC.h"

#define LM35_CHANNEL 0   /* PA0 */

void LM35_Init(void)
{
	ADC_init();
	ADC_voidEnable();
}

u8 LM35_GetTemperature(void)
{
	u16 voltage_mv;

	ADC_voidStartConversion(LM35_CHANNEL);

	voltage_mv = ADC_u16ReadADCInMV();

	/* LM35: 10 mV ??? ???? ????? */
	return (u8)(voltage_mv / 10);
}