// ***** Program to Blink Alternate LED's on Port 2 ***** //
#include <REGX51.H>
#define LED P2
// Software Delay 
void delay(unsigned int del)
{
	unsigned int i,j;
  for(i=0;i<=1275;i++)
		for(j=0;j<=del;j++);
}
// Main Loop
void main()
{
	// Infinite Loop
	while(1)
  {
		LED=0xaa;
	  delay(10);
	  LED=0x55;
	  delay(10);
	}
}