#include <lpc21xx.h>
#include "rtc_defines.h"
#include "lcd_defines.h"
#include "lcd.h"
#include "types_prj.h"
char week[][4]={"SUN","MON","TUE","WED","THUR","FRI","SAT"};


void SetRTCTime(u32 hour,u32 minute,u32 second)
{
	HOUR=hour;
	MIN=minute;
	SEC=second;
}
	
void GetRTCTime(u32 *hour,u32 *minute,u32 *second)
{
	*hour=HOUR;
	*minute=MIN;
	*second=SEC;
}

void DisplayRTCTime(u32 hour,u32 minute,u32 second)
{
	cmdLCD(GOTO_LINE1_POS0);
	charLCD((hour/10)+48);
	charLCD((hour%10)+48);
	charLCD(':');
	charLCD((minute/10)+48);
	charLCD((minute%10)+48);
	charLCD(':');
	charLCD((second/10)+48);
	charLCD((second%10)+48);
}
void RTC_Init(void) 
{
  // Disable and reset the RTC
	CCR = RTC_RESET;

#if (CPU == LPC2129)	
  // Set prescaler integer and fractional parts
	PREINT = PREINT_VAL;
	PREFRAC = PREFRAC_VAL;
	CCR = RTC_ENABLE; 
#elif(CPU == LPC2148)
  // Enable the RTC
	CCR = RTC_ENABLE | RTC_CLKSRC;  
#endif
}

void SetRTCdate(u32 date,u32 month,u32 year)
{
	DOM=date;
	MONTH=month;
	YEAR=year;
}
	
void GetRTCdate(u32 *date,u32 *month,u32 *year)
{
	*date=DOM;
	*month=MONTH;
	*year=YEAR;
}

void DisplayRTCdate(u32 date,u32 month,u32 year)
{
	cmdLCD(GOTO_LINE2_POS0);
	charLCD((date/10)+48);
	charLCD((date%10)+48);
	charLCD('/');
	charLCD((month/10)+48);
	charLCD((month%10)+48);
	charLCD('/');
	U32LCD(year);
}

void SetRTCDay(u32 day)
{
	DOW=day;
}
	
void GetRTCDay(u32 *day)
{
	*day=DOW;
}

void DisplayRTCDay(u32 day)
{
	cmdLCD(GOTO_LINE1_POS0+10);
	strLCD(week[day]);
}
	
	
	
	