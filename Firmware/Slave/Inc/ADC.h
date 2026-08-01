#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

void ADC_init(void);

void ADC_voidEnable(void);

void ADC_voidDisable(void);

void ADC_voidStartConversion(u8 addresscpy);

u8 ADC_u8ReadADC(void);

u16 ADC_u16ReadADCInMV(void);

#endif
