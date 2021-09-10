// ***** Program to Blink Alternate LED's on Port 2 Using Timer0 : Mode 1 ***** //
#include <REGX51.H>
#define LED P2
void delay_timer(unsigned int del)
{
	unsigned int i;  	 
	for(i == 0;i < del ; i++)	// Subroutine for 50ms delay, Total Delay = (50 * del) ms
	{
		TMOD = 0x01; 			// Mode 1 - 16 Bit Non Autoreload Mode, Timer0
		TH0  = 0x4B;			// Higher Byte Value Loaded in TH0
		TL0  = 0xFD;			// Lower  Byte  Value  Loaded in TL0
		TR0  = 1;				// Starting the Timer
		while(TF0==0);			// Waiting for Timer Overflow Flag to be Set
		TR0  = 0;				// Clearing the Timer
		TF0  = 0;				// Clearing the Overflow Flag
	}
}
void main()
{
	while(1)
  {
		LED=0xaa;
	  delay_timer(20);	// Timer Delay for Precise 1s
	  LED=0x55;
	  delay_timer(20);	// Timer Delay for Precise 1s
	}
}