#include  <reg51.h>
void delay();

void main() {
unsigned char code1[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int k;
while(1) {
for(k=0; k<10; k++) {  
P2 = code1[k];        
delay();             
}
}
}
void delay() {
int i;
for(i=0; i<12; i++) {      
TMOD = 0x01;              
TL0 = 0x00;                
TH0 = 0x00;                
TR0 = 1;                   
while(TF0 == 0);          
TR0 = 0;                   
TF0 = 0;                   
}
}

