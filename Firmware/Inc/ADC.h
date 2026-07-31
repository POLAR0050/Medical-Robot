#ifndef ADC.h
#define F_CPU 8000000UL
#include <util/delay.h>

#define ADMUX  *( (volatile u8*) 0x27)
#define ADCSRA  *( (volatile u8*) 0x26)
#define ADCH  *( (volatile u8*) 0x25)
#define ADCL  *( (volatile u8*) 0x24)
#define ADC     *((volatile u16*)0x24)



void ADC_INIT (void);
void ADC_Enable (void);
void ADC_Disable (void);
u16 ADC_u16Read(void);


#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIF  4
#define ADSC  6
#define ADEN  7
#define REFS0 6

#endif
