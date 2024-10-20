#include<reg51.h>
void delay();
void main()
{
int i;
while(1){
for( i = 0; i<16; i++){
P2=i;
delay();
}
}
}
void delay(){
TMOD=0x01;
TL0=0X00;
TH0=0X01;
TR0=1;
while (TF0==0);
TR0=0;
TF0=0;
}
