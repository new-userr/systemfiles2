ring counter-:    #include  <reg51.h>
void delay();

void main() {
    // Array for ring counter pattern (LEDs light up one at a time)
    unsigned char code1[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
    int k;
    
    while(1) {
        for(k=0; k<8; k++) {  // Loop through each bit in the pattern
            P2 = code1[k];        // Output pattern to port P2
            delay();              // Short delay between steps
        }
    }
}

void delay() {
    int i;
    for(i=0; i<12; i++) {      // Repeat to create a longer delay
        TMOD = 0x01;               // Set Timer 0 in mode 1 (16-bit timer)
        TL0 = 0x00;                // Set initial timer low byte
        TH0 = 0x00;                // Set initial timer high byte
        TR0 = 1;                   // Start Timer 0
        while(TF0 == 0);           // Wait until timer overflows
        TR0 = 0;                   // Stop Timer 0
        TF0 = 0;                   // Clear overflow flag
    }
}
// This is a ring counter program: LEDs light up one at a time in sequence.
