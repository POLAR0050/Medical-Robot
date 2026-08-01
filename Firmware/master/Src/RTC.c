

#include "RTC.h"
#include "TWI.h"

#define RTC_ADDRESS_WRITE 0xD0
#define RTC_ADDRESS_READ  0xD1

static u8 DEC_TO_BCD(u8 value)
{
	return ((value/10)<<4)|(value%10);
}

static u8 BCD_TO_DEC(u8 value)
{
	return (((value>>4)*10)+(value&0x0F));
}

void RTC_Init(void)
{
	TWI_Init();
}

void RTC_SetTime(u8 Hour,u8 Minute,u8 Second)
{
	TWI_Start();

	TWI_Write(RTC_ADDRESS_WRITE);

	TWI_Write(0x00);

	TWI_Write(DEC_TO_BCD(Second));

	TWI_Write(DEC_TO_BCD(Minute));

	TWI_Write(DEC_TO_BCD(Hour));

	TWI_Stop();
}

void RTC_ReadTime(u8 *Hour,u8 *Minute,u8 *Second)
{
	TWI_Start();

	TWI_Write(RTC_ADDRESS_WRITE);

	TWI_Write(0x00);

	TWI_Start();

	TWI_Write(RTC_ADDRESS_READ);

	*Second = BCD_TO_DEC(TWI_Read_ACK());

	*Minute = BCD_TO_DEC(TWI_Read_ACK());

	*Hour = BCD_TO_DEC(TWI_Read_NACK());

	TWI_Stop();
}
