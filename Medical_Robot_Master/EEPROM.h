#ifndef EEPROM_H_
#define EEPROM_H_

#include "STD_TYPES.h"

void EEPROM_WriteByte(u16 Address,u8 Data);

u8 EEPROM_ReadByte(u16 Address);

#endif