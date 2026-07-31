#ifndef DIO_H_
#define DIO_H_


#include <avr/io.h>


#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3


#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


#define INPUT  0
#define OUTPUT 1


#define LOW  0
#define HIGH 1

void DIO_SetPinDirection(unsigned char port,unsigned char pin,unsigned char direction);
void DIO_SetPinValue(unsigned char port,unsigned char pin,unsigned char value);
void DIO_TogglePinValue(unsigned char port,unsigned char pin);
unsigned char DIO_GetPinValue(unsigned char port,unsigned char pin);

#endif
