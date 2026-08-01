#ifndef LINE_SENSOR_H_
#define LINE_SENSOR_H_

#include "STD_TYPES.h"

/*
 * ==========================================================
 *  LINE SENSOR PIN MAPPING (3x Digital IR)
 * ==========================================================
 *  Left   : PA1
 *  Middle : PA2
 *  Right  : PA3
 * ==========================================================
 */

#define LINE_LEFT    0
#define LINE_MIDDLE  1
#define LINE_RIGHT   2

void LINE_SENSOR_Init(void);
u8 LINE_SENSOR_Read(u8 sensor);

#endif
