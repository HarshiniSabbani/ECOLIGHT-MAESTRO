#include<lpc21xx.h>
#include "defines.h"
#include "kpm_defines.h"

unsigned char kpmLUT[4][4]= 

{
{'7','8','9','/'},
{'4','5','6','*'},
{'1','2','3','-'},
{'*','0','=','+'},
};

void Init_KPM(void)
{
	IODIR1|=15<<ROW0;
}

unsigned int colscan(void)
{
	unsigned int status;
	status=((READNIBBLE(IOPIN1,COL0)<15)?0:1);
	return status;
}

unsigned int rowcheck(void)
{
	unsigned int r;
	for(r=0;r<=3;r++)
	{
		WRITENIBBLE(IOPIN1,ROW0,~(1<<r));
		if(colscan()==0)
		{
			break;
		}
	}
	WRITENIBBLE(IOPIN1,ROW0,0);
	return r;
}
		
unsigned int colcheck(void)
{
	unsigned int c;
	for(c=0;c<=3;c++)
	{
		if(READBIT(IOPIN1,(COL0+c))==0)
		{
			break;
		}
	}
	return c;
}

unsigned char keyscan(void)
{
	unsigned int key,r,c;
	while(colscan());
	r=rowcheck();
	c=colcheck();
	key=kpmLUT[r][c];
	while(!colscan());
	return key;
}
void read_num(unsigned int *hour,unsigned int *key)
{
	*hour=0;
	while(1)
	{
		*key=keyscan();
	if((*key<='9')&&(*key>='0'))
	{
	*hour=((*hour)*10)+(*key-'0');
		while(colscan()==0);
	}
	else 
	{
		while(colscan()==0);
		break;
	}
  }
}