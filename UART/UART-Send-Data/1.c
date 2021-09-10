// ***** Program to Transmit and Send data via UART using Timer-1 Auto-Reload mode ***** //
#include <REGX51.H>
sbit SW = P1^0;
void UART_init()
{
	TMOD = 0x20; 			// Mode 2 - 8 Bit Autoreload Mode, Timer1
	TH1  = 0xFD;			// 9600 bps Baud Rate
	SCON = 0x50;			// Setting the Serial Control Register 
	TR1  = 1;				// Starting the Timer
}
void main()
{
	unsigned char z;
  unsigned char fname[] = "MANDEESH ";
  unsigned char lname[] = " SINGH ";
  UART_init();
  while(1)
  {
		if(SW == 0)
	  {
			for(z = 0; z < 9; z++)
		 	{
				SBUF = fname[z];
				while(TI == 0);
				TI = 0;
			}
		}
	  
		else
	  {
			for(z = 0; z < 8; z++)
			{
				SBUF = lname[z];
				while(TI == 0);
				TI = 0;
			}
	 	}
  }
}