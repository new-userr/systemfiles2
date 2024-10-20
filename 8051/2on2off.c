
//LED flashing (p2 , 2 ON , 2 OFF)
#include<reg51.h>

void main(){
	while(1){
	P2=0xCC;
	delay();
	P2=0x00;
	delay();
	}
}
delay(){
	TMOD=0x01;
	TL0=0x00;
	TH0=0x00;
	TR0=1;
	while(TF0==0)
	TR0=0;
	TF0=0;
}
		  
