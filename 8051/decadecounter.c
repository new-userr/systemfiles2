#include <reg51.h>

void delay(); 

void main() {
unsigned char i; 
while (1) {
for (i = 0; i <= 9; i++) {
P2 = 0x00; 
delay();   
P2 = 0xFF;  
delay();    
}
}
}
void delay() {
    TMOD = 0x01; // Set Timer 0 in mode 1 (16-bit timer)
    TL0 = 0x00;  
    TH0 = 0x00;  
    TR0 = 1;     
    while (TF0 == 0); 
    TR0 = 0;     
    TF0 = 0;   
}
