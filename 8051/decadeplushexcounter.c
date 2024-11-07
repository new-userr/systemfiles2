//decade and hex counter-:          
#include  <reg51.h>
void delay(); 

void main() {
    unsigned char i; 
    while (1) {
        for (i=0; i<=9; i++) {     // Counts from 0 to 9              // for hex counter i<=15
            P2 = i;                    // Output the count on P2
            delay();                   // Delay between counts
        }
    }
}

void delay() {
    TMOD = 0x01;      // Set Timer 0 in mode 1 (16-bit timer)
    TL0 = 0x00;       // F6 FOR increse delay
    TH0 = 0x00;       // Adjust TH0 for a specific delay if needed   //for hex counter TH0=0X01     //66 for increse delay           
    TR0 = 1;     
    while (TF0 == 0); 
    TR0 = 0;     
    TF0 = 0;   
}
