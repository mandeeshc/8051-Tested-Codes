// ***** Program for a 4-bit Binary Counter ***** //
#include <REGX51.H>						// Header File
#define LED P2							// P2 defined as LED 
void delay(unsigned int del)			// Function declared and defined before main function 
{
	unsigned int i,j;					// Declaration of Variables
  for(i=0;i<=1275;i++)				// Use of for Loops
		for(j=0;j<=del;j++);
}
void main()								// Main function
{
	while(1)								// While(1) : Repeat forever
  { 
		unsigned char k;
	  P2=0x00; 
    for(k=0;k<15;k++)
		{ 
			P2++;
			delay(100);
    }
	}  
}