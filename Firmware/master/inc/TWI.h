


#ifndef TWI_H_
#define TWI_H_

#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

void TWI_Init(void);

void TWI_Start(void);

void TWI_Stop(void);

void TWI_Write(u8 Data);

u8 TWI_Read_ACK(void);

u8 TWI_Read_NACK(void);

#endif
