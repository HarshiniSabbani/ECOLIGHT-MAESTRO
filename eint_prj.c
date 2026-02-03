#include<lpc21xx.h>
#include "pin_connect_block.h"
#include "delay.h"
#define EINT0 14

extern int interrupt_flag;
void eint0_isr(void)__irq
{
	interrupt_flag=1;
	delay_ms(200);
	EXTINT=1<<0;//clear the interrupt
	VICVectAddr0=0;//tells the VIC that ISR finished
}	
	
void enable_eint0(void)
{
	cfgportpinfunc(0,16,1);//pin 16 as eint0,, that is here pin no 16 is the eint input pin i.e., switch
	VICIntSelect=0;//type of interrupt is irq
	VICIntEnable=1<<EINT0;//channel number 14
	VICVectCntl0=(1<<5)|EINT0;//5th bit is the enabled bit and eint0 binary
	VICVectAddr0=(unsigned int)eint0_isr;//assigneg the address of isr
	EXTMODE=1<<0;//edge triggering;
	//already falling edge so no expolar condition because for falling it is 0
}


	
		