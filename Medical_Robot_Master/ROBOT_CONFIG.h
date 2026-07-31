#ifndef ROBOT_CONFIG_H_
#define ROBOT_CONFIG_H_

#include "DIO.h"

/******** LCD ********/

#define LCD_RS_PORT PORTC_ID
#define LCD_RS_PIN  PIN6

#define LCD_RW_PORT PORTC_ID
#define LCD_RW_PIN  PIN5

#define LCD_EN_PORT PORTC_ID
#define LCD_EN_PIN  PIN7

#define LCD_DATA_PORT PORTD_ID

/******** Keypad ********/

#define KEYPAD_PORT PORTA_ID

/******** UART ********/

#define UART_BAUD 9600

/******** Bluetooth ********/

#define BT_NAME "MedicalRobot"

#endif