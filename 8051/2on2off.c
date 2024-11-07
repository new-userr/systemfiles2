//TWO on two off -: 
#include  <reg51.h>

void main(){
  while(1){
  P2=0XCC;    // FOR ALTERNATE AA
  Delay();
  P2=0X33;    // 55
  Delay();
 }
}
 
Delay(){
 unsigned char j;
 for(j=0;j<20;j++){
  TMOD=0X01;
  TH0=0XDC;
  TL0=0X00;
  while(TF0==1);
  TR0=0;
  TF0=0;
 }
}

//ALTERNATE
//1010 1010 AA
//0101 0101 55
