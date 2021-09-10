// ***** Program to Blink Alternate LED's on Port 0 Using Timer1 : Mode 1 ***** //
#include <REGX51.H>
#define LED P0
void delay_timer()
{
	TMOD = 0x10; 			// Mode 1 - 16 Bit Non Autoreload Mode, Timer1
	TH1  = 0xEE;			// Higher Byte Value Loaded in TH1
	TL1  = 0x00;			// Lower  Byte  Value  Loaded in TL1
	TR1  = 1;				// Starting the Timer
	while(TF1==0);			// Waiting for Timer Overflow Flag to be Set
	TR1  = 0;				// Clearing the Timer
	TF1  = 0;				// Clearing the Overflow Flag
}
void main()
{
	while(1)
  {
	  LED=0xaa;
	  delay_timer();	// Timer Delay for Precise 5 ms
	  LED=0x55;
	  delay_timer();	// Timer Delay for Precise 5 ms
	 }
}