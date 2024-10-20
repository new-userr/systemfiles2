// Program to count in hexadecimal
#include <p18f4550.h>

void delay(unsigned int time)
{
    unsigned int i, j;
    for(i = 0; i < time; i++)
        for(j = 0; j < 5000; j++);
}

void main(void)
{
    unsigned char counter = 0;

    TRISB = 0x00;
    while(1)
    {
        PORTB = counter;
        delay(100);
        counter++;
        if(counter > 0x0F)
            counter = 0;
    }
}

