//LED flashing (p2 , Counter decade)
#include<reg51.h>

void main(){
	unsigned char i;
	while(1){
	for(i=0;i<=9;i++){
 		P2=0x0i;  
	   delay();	 }
}	
}
delay(){
	TMOD=0x01;
	TL0=0x00;
	TH0=0x00;
	TR0=1;
	while(TF0==0);
	TR0=0;
	TF0=0;
}