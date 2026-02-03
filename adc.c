#include<lpc21xx.h>
#include "pin_connect_block.h"
#include "adc_defines.h"
#include "delay.h"

void Init_ADC(void)
{
	//cfg p0.28 as ain0 input pin
	cfgportpinfunc(0,28,1);
	//cfg ADCR
	ADCR=(CLKDIV<<CLKDIV_BITS)|(1<<PDN_BIT);
}

void Read_ADC(unsigned int chNo,unsigned int* adcDVal,float *eAR)
{
	ADCR&=0xFFFFFF00;//mask any prevchannel value
	//write channel 1 for analog read,
	//&start adc conversion wrt that channel
	ADCR|=(1<<chNo)|(1<<ADC_CONV_START_BIT);
	delay_us(3);
	//wait until conversion complete status
	while(((ADDR>>DONE_BIT)&1)==0);
	//stop adc convert wrt that channel
	ADCR&=~(1<<ADC_CONV_START_BIT);
	//read digital data
	*adcDVal=((ADDR>>DIGITAL_DATA_BITS)&1023);
	//equivalent analog representation
	*eAR=(*adcDVal*(3.3)/1023);
}