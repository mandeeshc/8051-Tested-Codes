#include <REGX51.H>
sbit MOT1P = P1^0;
sbit MOT1N = P1^1;
sbit MOT2P = P1^2;
sbit MOT2N = P1^3;
sbit SW1 = P3^0;
sbit SW2 = P3^1;
void delay(unsigned int del)
{
	unsigned int i,j;
  for(i=0;i<=1275;i++)
		for(j=0;j<=del;j++);
}
void main()
{	
	P1= 0x00;
  while(1)
  {
		if(SW1==0)
	  {
			delay(5);
	    MOT1P=1;
			MOT1N=0;
		}
	  else if(SW2==0)
	  {
			delay(5);
	    MOT1P=0;
			MOT1N=1;
		}
	  else   
	   P1=0x00;	 
	}
}
