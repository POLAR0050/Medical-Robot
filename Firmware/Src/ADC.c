
void ADC_INIT (void)
{
	ADMUX=0b01000000 ;
	ADCSRA=0b00000111 ;  // dev by 128 
}


void ADC_Enable (void)
{
	ADCSRA=0b10000000;
	
}


void ADC_Disable (void)
{
	ADCSRA=0b01111111;
}


u16 ADC_u16Read(void)
{
	SET_BIT (ADCSRA,ADCS);  //3shan tstart conversion y7owel mn anlog l dig
	SET_BIT(ADCSRA, ADIF);   
	while(!(ADCSRA & (1<<ADIF)));    // nstna elhardware y5alas
	return (ADC * 5000UL) / 1023;
}
