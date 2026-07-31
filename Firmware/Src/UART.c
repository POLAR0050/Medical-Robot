#include "UART.h"
void UART_INIT(void)
{
	UBRRL=51 ;
	SET_BIT(UCSRB, RXEN);
	SET_BIT(UCSRB, TXEN);
	SET_BIT(UCSRC, URSEL);
	SET_BIT(UCSRC, UCSZ0);
	SET_BIT(UCSRC, UCSZ1);
	CLR_BIT(UCSRB, UCSZ2);
	// No Parity
	CLR_BIT(UCSRC, UPM0);
	CLR_BIT(UCSRC, UPM1);

	// 1 Stop Bit
	CLR_BIT(UCSRC, USBS);
}

void UART_SendData(u8 data)
{
	while(!(UCSRA & (1<<UDRE))); // yetamen 2nha fadya

	UDR = data;
}

u8 UART_ReceiveData(void)
{
	while(!(UCSRA & (1<<RXC))); // recive complete ,yestana l7d ma wosal 7arf tany

	return UDR;
}
