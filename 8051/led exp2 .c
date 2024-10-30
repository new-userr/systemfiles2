#include <reg51.h>

void delay(void); // Function prototype

void main() {
   P2 = 0xFF; // Turn on all LEDs
   delay();
   P2 = 0x00; // Turn off all LEDs
   delay();   
}

void delay() { 
  TMOD = 0x01; // Set Timer0 in mode 1 (16-bit timer)
  TH0 = 0x0C;  // Load higher byte
  TL0 = 0x00;  // Load lower byte
  TR0 = 1;     // Start Timer0
  while (TF0 == 0); // Wait for overflow
  TR0 = 0; // Stop Timer0
  TF0 = 0; // Clear overflow flag
}
