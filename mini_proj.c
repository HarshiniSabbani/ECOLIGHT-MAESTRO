#include<lpc21xx.h>
#include<stdlib.h>
#include "defines.h"
#include "pin_connect_block.h"
#include "eint_prj.h"
#include "lcd.h"
#include "lcd_defines.h"
#include "types_prj.h"
#include "rtc_prj.h"
#include "kpm.h"
#include "adc.h"
#include "adc_defines.h"
#include "delay.h"
#define LED_AH 10
void edit_RTC(void);
unsigned int hour,minute,second,day,date,month,year;
		
int interrupt_flag=0;
int main()
{
	unsigned int adcDVal;
	float eAR;
	
	WRITENIBBLE(IODIR0,LED_AH,15);
	RTC_Init();
	Init_LCD();
	Init_KPM();
	Init_ADC();
	SetRTCTime(4,41,47);
	SetRTCDay(0);
	SetRTCdate(7,8,25);
	enable_eint0();
	while(1)
	{
		GetRTCTime(&hour,&minute,&second);
		DisplayRTCTime(hour,minute,second);
    
		GetRTCDay(&day);
    DisplayRTCDay(day);
	
		GetRTCdate(&date,&month,&year);
		DisplayRTCdate(date,month,year);
		//enable_eint0();
		Read_ADC(2,&adcDVal,&eAR);
		if(interrupt_flag==1)
	    {
		   edit_RTC();
				interrupt_flag=0;
	    }
			if((HOUR>=6)&&(HOUR<=18))
			{
			  cmdLCD(GOTO_LINE2_POS0+9);
				F32LCD(eAR,2);	
			  charLCD(' ');
				U32LCD(adcDVal);		
				if(eAR<1.5)
				{
					WRITENIBBLE(IOPIN0,LED_AH,15);
					delay_ms(500);
			//IOSET0|=15<<LED_AH;
				}
			}
  }
}

void edit_RTC(void)
{
	char ch,c;
	unsigned int keyy;
	cmdLCD(CLEAR_LCD);
	strLCD("1:edit time 2:exit");
	ch=keyscan();
	cmdLCD(CLEAR_LCD);
	switch(ch)
	{
		case '1':strLCD("1:hr 2:min 3:sec");
		c=keyscan();
		cmdLCD(CLEAR_LCD);
	           switch(c)
	           {
		         case '1':strLCD("enter hour");
							        read_num(&hour,&keyy);
							           if(hour<24)
							             {
		                           HOUR=hour;
							             }
							           else
							             {
														 cmdLCD(CLEAR_LCD);
						               		 strLCD("error!!retry");
														  delay_s(2);
						             	 }
							        break;
		         case '2':strLCD("enter minute");
							        read_num(&minute,&keyy);
													  if(minute<60)
							              {
		                          MIN=minute;
							              }
						            	 else
					                	 {
															 cmdLCD(CLEAR_LCD);
					              			 strLCD("error!!retry");
															 delay_s(2);
						               	 }
							        break;
		         case '3':strLCD("enter second");
							        read_num(&second,&keyy);
		                         if(second<60)
							               {
		                           SEC=second;
							               }
							             else
							               {
															 cmdLCD(CLEAR_LCD);
								                strLCD("error!!,retry");
															  delay_s(2);
							               }
							        break;
	           }
						 break;
		case '2':exit(0);
	}
	cmdLCD(CLEAR_LCD);
	GetRTCTime(&hour,&minute,&second);
	DisplayRTCTime(hour,minute,second);
}