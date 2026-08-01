#ifndef LM35_H_
#define LM35_H_

#include "STD_TYPES.h"

/*
 * ==========================================================
 *  LM35 PIN MAPPING
 * ==========================================================
 *  Vout : PA0 (ADC Channel 0)
 * ==========================================================
 */

void LM35_Init(void);

u8 LM35_GetTemperature(void);

#endif
