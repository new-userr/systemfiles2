#include <reg51.h>

sbit wave = P2^0;
void delay();
void main()
{
	wave=0;
	while(1)
	{
		wave=1;
		delay();
		wave=0;
		delay();
		
		
	
	}
	
}

void delay()
{
	unsigned char i;
	TMOD=0X10;
	for (i=0;i<14;i++)
	{ 
		TH1=0X00;
		TL1=0X00;
		TR1=1;
		while(TF1==0);
		TF1=0;
		
		
	}
}

