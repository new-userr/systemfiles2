expt-5 pic_interfacing of_led_relay_buzzers-:#include <PIC18F4550.H>

// Function to introduce a delay
void delay(){
    unsigned int i;
    for(i=0; i<30000; i++); // Loop for delay
}

void main(){
    unsigned char i, key = 0;
    
    TRISB = 0x00;  // Set PORTB as output (for LEDs)
    ADCON1 = 0x0F; // Set all analog pins as digital
    TRISAbits.TRISA2 = 1;  // Set RA2 as input (key1)
    TRISAbits.TRISA3 = 1;  // Set RA3 as input (key2)
    TRISAbits.TRISA5 = 0;  // Set RA5 as output (buzzer)
    TRISAbits.TRISA4 = 0;  // Set RA4 as output (relay)

    while(1){
        // Check if keys are pressed (RA2 or RA3)
        if(PORTAbits.RA2 == 0) key = 0; // key 0 if RA2 is pressed
        if(PORTAbits.RA3 == 0) key = 1; // key 1 if RA3 is pressed

        if(key == 0){ // If key is 0
            PORTAbits.RA4 = 0;  // Turn off relay (RA4)
            PORTAbits.RA5 = 1;  // Turn on buzzer (RA5)
            for(i = 0; i < 8; i++){ // Shift pattern across PORTB
                PORTB = 1 << i;   // Set bit in PORTB
                delay();          // Delay for visual effect
                PORTB = 0x00;     // Clear PORTB
                delay();          // Delay for visual effect
            }
        }
        if(key == 1){ // If key is 1
            PORTAbits.RA4 = 0;  // Turn off relay (RA4)
            PORTAbits.RA5 = 1;  // Turn on buzzer (RA5)
            for(i = 7; i > 0; i--){ // Reverse shift pattern across PORTB
                PORTB = 1 << i;   // Set bit in PORTB
                delay();          // Delay for visual effect
                PORTB = 0x00;     // Clear PORTB
                delay();          // Delay for visual effect
            }
        }
    }
}
