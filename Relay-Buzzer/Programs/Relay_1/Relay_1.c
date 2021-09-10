#include <REGX51.H>
sbit REL1 = P1^0;
sbit REL2 = P1^1;
sbit SW1 = P3^0;
sbit SW2 = P3^1;
void delay(unsigned int del)
  {
   unsigned int i,j;
   for(i=0;i<=1275;i++)
     for(j=0;j<=del;j++);
  }
void main()
  {	P1= 0x00;
   
   while(1)
     {
	  if(SW1==0)
	    {
		 delay(5);
	     REL1=1;
		}
	  else if(SW2==0)
	    {
		 delay(5);
	     REL2=1;
		}
	   else   
	   P1=0x00;	 
	 }

  }
