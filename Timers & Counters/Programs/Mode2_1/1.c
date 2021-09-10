// ***** Program to Create a 10 Khz Signal on Pin 2.1 Using Timer0 : Mode 2 ***** //
#include <REGX51.H>
sbit PIN = P2^1;
void delay_freq()
{
	TMOD = 0x02; 			// Mode 2 - 8 Bit Autoreload Mode, Timer0
	TH0  = 0x2F;			// Only Higher Byte Value Loaded in TH0, Same Value copied in TL0
	TR0  = 1;				// Starting the Timer
	while(TF0==0);			// Waiting for Timer Overflow Flag to be Set
	TR0  = 0;				// Clearing the Timer
	TF0  = 0;				// Clearing the Overflow Flag
}
void main()
{
	while(1)
  {
		PIN = 1;
		delay_freq();
		PIN = 0;
		delay_freq();
	}
}