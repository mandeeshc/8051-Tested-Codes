// ***** Program to Blink LED's based on Switch pressed  ***** //
#include <REGX51.H>
#define LED P2
sbit SW1 = P1^0;
sbit SW2 = P1^1;
sbit SW3 = P1^2;
sbit SW4 = P1^3;

void delay(unsigned int del)
{
	unsigned int i,j;
	for(i=0;i<=1275;i++)
		for(j=0;j<=del;j++);
}
void main()
{
	while(1)
  {
		if(SW1==0)
	  {
			delay(5);
			LED=0x01;
		}
	  else if(SW2==0)
	  {
			delay(5);
			LED=0x02;
		}
	  else if(SW3==0)
	  {
			delay(5);
			LED=0xaa;
		}
	  else if(SW4 == 0)
	  {
			delay(5);
			LED=0x00;
		}
	  else
		{ 
			LED = 0xff;
		}			 
	}
}