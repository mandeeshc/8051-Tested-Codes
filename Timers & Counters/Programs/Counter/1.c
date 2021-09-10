// ***** Program to use the Timer Module as a Counter (Timer0 : Mode 2) ***** //
#include <REGX51.H>
sbit PIN = P3^5;
void main()
{
	int i;
	PIN = 1;
	TMOD = 0x06;
	TH0 = 0;
	do
  {
		TR0 = 1;
		P0 = TL0;
		i = P1;
	}
	while(TF0 == 0);
	TR0 = 0;
	TF0 = 0;
}