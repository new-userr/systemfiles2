#include <reg51.h>

sbit wave = P2^1;

void timer0_isr(void) __interrupt(1)
{
    wave = ~wave;
    TH0 = 0xFF;  // Reload timer values
    TL0 = 0xF9;
}

void main(void)
{
    TMOD = 0x01;  // Timer 0, 16-bit mode
    TH0 = 0xFF;   // Initial timer value
    TL0 = 0xF9;
    IE = 0x82;    // Enable Timer 0 interrupt
    TR0 = 1;      // Start Timer 0

    while(1)
    {
        // Main loop - can perform other tasks here
    }
}