#include <avr/io.h>

#include "EEPROM.h"

void EEPROM_WriteByte(u16 Address,u8 Data)
{
	while(EECR & (1<<EEWE));

	EEAR = Address;

	EEDR = Data;

	EECR |= (1<<EEMWE);

	EECR |= (1<<EEWE);
}

u8 EEPROM_ReadByte(u16 Address)
{
	while(EECR & (1<<EEWE));

	EEAR = Address;

	EECR |= (1<<EERE);

	return EEDR;
}