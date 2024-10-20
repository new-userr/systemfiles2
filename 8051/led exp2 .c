  // program for led flashing all led on - off
# include <reg51.h>
void delay();
void main()
{
   P2=0xFF;
   delay();
   p2=0x00;
   delay();   
 }
delay()
{ 
  TMOD 0x01;
  TH0=0x0c;
  TL0=0x00;
  TR0=1;
  while(TF0==0);
  TR0=0;
  TF0=0:
  }