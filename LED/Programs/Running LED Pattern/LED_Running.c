// ***** Program for Running LED's on Port 2 ***** //
#include <REGX51.H>						// Header File
#define LED P2
void delay(unsigned int del)
{
	unsigned int i,j;
  for(i=0;i<=1275;i++)
		for(j=0;j<=del;j++);
}
void main()
{
	unsigned int i;
  LED=0x01;
  delay(100);
  for(i=0;i<7;i++)
  {
		LED=LED<<1;
		delay(100);
	}
}