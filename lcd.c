#include<lpc21xx.h>
#include "defines.h"
#include "delay.h"
#include "lcd_defines.h"

void writeLCD(unsigned char anybyte)
{
	IOCLR0=1<<LCD_RW;
	WRITEBYTE(IOPIN0,LCD_DATA,anybyte);
	IOSET0=1<<LCD_EN;
	delay_us(1);
	IOCLR0=1<<LCD_EN;
	delay_ms(2);
}


void cmdLCD(unsigned char cmd)
{
	IOCLR0=1<<LCD_RS;
	writeLCD(cmd);
	//delay_ms(2);
}


void charLCD(unsigned char asciivalue)
{
	IOSET0=1<<LCD_RS;
	writeLCD(asciivalue);
}


void Init_LCD(void)
{
	IODIR0|=(255<<LCD_DATA)|(1<<LCD_RS)|(1<<LCD_RW)|(1<<LCD_EN);
	cmdLCD(0x30);
	delay_ms(4);
  delay_us(100);
  cmdLCD(0x30);
  delay_us(100);
  cmdLCD(0x30);
  cmdLCD(0x38);
	cmdLCD(0x0E);
	cmdLCD(0X01);
  cmdLCD(SHIFT_CUR_RIGHT);
}


void U32LCD(unsigned int num)
{
	unsigned char a[10];
	int i=0;
	if(num==0)
	{
		charLCD('0');
	}
	else
	{
	while(num>0)
	{
		a[i]=(num%10)+'0';
		i++;
		num=num/10;
	}
	for(--i;i>=0;i--)
	{
		charLCD(a[i]);
	}
  }
}

void S32LCD(int snum)
{
	if(snum<0)
	{
		charLCD('-');
		snum=-snum;
	}
	U32LCD(snum);
}
	
void strLCD(char *p)
{
	while(*p)
	{
		charLCD(*p++);
	}
}

void BinLCD(unsigned int n,char nbd)
{
	int i;
	for(i=(nbd-1);i>=0;i--)
	{
		charLCD(((n>>i)&1)+48);
	}
}

void F32LCD(float fNum,unsigned char nDP)
{
	unsigned int num,i;
	if(fNum<0.0)
	{
		charLCD(' ');
		fNum=-fNum;
	}
	num=fNum;
	U32LCD(num);
	charLCD('.');
	for(i=0;i<nDP;i++)
	{
		fNum=(fNum-num)*10;
		num=fNum;
		charLCD(num+48);
	}
}