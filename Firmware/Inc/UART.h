#ifndef UART_H_
#include <avr/io.h>

#define UCSRA  *( (volatile u8*) 0x2B)
#define UDRE 5 
#define RXC 7 

#define UCSRB  *( (volatile u8*) 0x2A)
#define RXEN 4
#define TXEN 3
#define UCSZ2 2

#define UCSRC  *( (volatile u8*) 0x40)
#define URSEL 7
#define UCSZ0 1
#define UCSZ1 2
#define UPM0 4
#define UPM1 5
#define USBS 3

#define UBRRL  *( (volatile u8*) 0x29)
#define UDR (*(volatile u8*)0x2C)

void UART_INIT(void);
void UART_SendData(u8 data);
u8 UART_ReceiveData(void);
#endif
