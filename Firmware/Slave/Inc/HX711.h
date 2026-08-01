#ifndef HX711_H_
#define HX711_H_

#include "STD_TYPES.h"

/*
 * ==========================================================
 *  HX711 PIN MAPPING (Load Cell Amplifier)
 * ==========================================================
 *  SCK (Clock) : PC4
 *  DT  (Data)  : PC5
 * ==========================================================
 */

void HX711_Init(void);
u8 HX711_IsReady(void);
s32 HX711_ReadRaw(void);

#endif
