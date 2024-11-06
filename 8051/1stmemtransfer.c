#include<reg51.h>
void main(void)
{
unsigned char x, y, z, m, n, t;
x=0x04;
y=0x02;
z=x+y;
P0=z;
m=x-y;
P1=m;
n=x*y;
P2=n;
t=x/y;
P3=t;
}
