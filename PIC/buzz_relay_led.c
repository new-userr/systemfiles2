#include<P18F4550.h>

void delay()
{
	unsigned int i;
	for(i=0;i<30000;i++);
}

void main()
{
    unsigned char i, key = 0;

    TRISB = 0x00;                           //LED pins as output
    //LATB = 0x00;

    ADCON1 = 0x0F;                          //set pins as Digital
    TRISAbits.TRISA2 = 1;                   //set RA2 as input
    TRISAbits.TRISA3 = 1;                   //set RA3 as input

    TRISAbits.TRISA5 = 0;                   //set buzzer pin RA5 as output
    TRISAbits.TRISA4 = 0;                   //set relay pin RA4 as output

    while(1)
    {
        //LATAbits.LA2 = 1;
        //LATAbits.LA3 = 1;

        if(PORTAbits.RA2 == 0) key =0;      //If button1 pressed
        if(PORTAbits.RA3 == 0) key =1;      //If button2 pressed

        if(key == 0)
        {
            PORTAbits.RA4 = 1;             //Relay OFF
            PORTAbits.RA5 = 0;             //Buzzer OFF
            for(i=0;i<8;i++)                //Chase LED right to left
            {
                PORTB = 1<<i;
                delay();
                PORTB = 0x00;
                delay();
            }
        }
        if(key == 1)
        {
            PORTAbits.RA4 = 0;             //Relay ON
            PORTAbits.RA5 = 1;             //Buzzer ON
            for(i=7;i> 0;i--)               //Chase LED left to right
            {
                PORTB = 1<<i;
                delay();
                PORTB = 0x00;
                delay();
            }
        }

    }
}