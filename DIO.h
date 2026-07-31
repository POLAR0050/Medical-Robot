
typedef unsigned char u8;


#define PORTA_ID   0
#define PORTB_ID   1
#define PORTC_ID   2
#define PORTD_ID   3


#define PIN0       0
#define PIN1       1
#define PIN2       2
#define PIN3       3
#define PIN4       4
#define PIN5       5
#define PIN6       6
#define PIN7       7


#define PIN_INPUT   0
#define PIN_OUTPUT  1


#define PIN_LOW     0
#define PIN_HIGH    1


#define PORT_INPUT   0x00
#define PORT_OUTPUT  0xFF

#define PORTA_ID   0
#define PORTB_ID   1
#define PORTC_ID   2
#define PORTD_ID   3
#define PIN0       0
#define PIN1       1
#define PIN2       2
#define PIN3       3
#define PIN4       4
#define PIN5       5
#define PIN6       6
#define PIN7       7
#define PIN_INPUT   0
#define PIN_OUTPUT  1
#define PIN_LOW     0
#define PIN_HIGH    1


void DIO_SetPinDirection(u8 port, u8 pin, u8 direction);
void DIO_SetPinValue(u8 port, u8 pin, u8 value);
void DIO_TogglePinValue(u8 port, u8 pin);
u8 DIO_GetPinValue(u8 port, u8 pin);

void DIO_SetPortDirection(u8 port, u8 direction);
void DIO_SetPortValue(u8 port, u8 value);
u8 DIO_GetPortValue(u8 port);
void DIO_TogglePortValue(u8 port);
