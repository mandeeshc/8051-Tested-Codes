#include <REGX51.H>
sbit SEVa = P1^0;
sbit SEVb = P1^1;
sbit SEVc = P1^2;
sbit SEVd = P1^3;
sbit SEVe = P1^4;
sbit SEVf = P1^5;
sbit SEVg = P1^6;

//sbit SW1 = P3^0;
//sbit SW2 = P3^1;

void delay(unsigned int del)
{
	unsigned int i,j;
  for(i=0;i<=1275;i++)
		for(j=0;j<=del;j++);
}
void main()
{	
	P1= 0xff;
  //  
	while(1)
  {
		P1=0x48;		delay(50);
		P1=0xed;		delay(50);
		P1=0x98;		delay(50);
		P1=0x89;		delay(50);
		P1=0x2d;		delay(50);
		P1=0x0b;		delay(50);
		P1=0x0a;		delay(50);
		P1=0xe9;		delay(50);
		P1=0x08;		delay(50);
		P1=0x09;		delay(50);
 	}
}
