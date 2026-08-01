
 * TWI.c
 *
 * Created: 7/31/2026 11:31:21 AM
 *  Author: User
 
#include "TWI.h"

void TWI_Init(void)
{
	TWBR = 32;

	TWSR = 0x00;

	TWAR = 0x00;

	SET_BIT(TWCR,TWEN);
}

void TWI_Start(void)
{
	TWCR = 0x00;

	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWEN);

	while(GET_BIT(TWCR,TWINT)==0);
}

void TWI_Stop(void)
{
	TWCR = 0x00;

	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWSTO);
	SET_BIT(TWCR,TWEN);
}

void TWI_Write(u8 Data)
{
	TWDR = Data;

	TWCR = 0x00;

	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWEN);

	while(GET_BIT(TWCR,TWINT)==0);
}

u8 TWI_Read_ACK(void)
{
	TWCR = 0x00;

	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWEA);
	SET_BIT(TWCR,TWEN);

	while(GET_BIT(TWCR,TWINT)==0);

	return TWDR;
}

u8 TWI_Read_NACK(void)
{
	TWCR = 0x00;

	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWEN);

	while(GET_BIT(TWCR,TWINT)==0);

	return TWDR;
}
