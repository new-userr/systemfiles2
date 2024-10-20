#include<reg51.h>
void delay();
void main(){
unsigned char code1[]={0X80,0X40,0X20,0X10,0X08,0X04,0X02,0X01};
int k;
while(1)
{ for(k=0; k<10; k++){
P2=code1[k];
delay();}
}
}
 void delay(){
int i;
for(i=0;i<12;i++){
TMOD = 0X01;
TL0 = 0X00;
TH0 = 0X00;
TR0=1;
while(TF0=0);
TR0 = 0;
TF0 = 0;
}
}
// ring counter