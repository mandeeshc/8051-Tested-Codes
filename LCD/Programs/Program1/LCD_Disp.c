// ***** Program to Display any character on the LCD ***** //
#include <REGX51.H>
#define LCD P0		 // LCD data bus 

sbit RS = P1^0;	     // LCD Register Select
sbit RW = P1^1;		 //	Read or Write
sbit EN = P1^2;	     // LCD Enable

void delay(int);

void delay1(unsigned int);
void lcd_data(char);  // For display data
void lcd_cmd(char);	  // For Commands to LCD controller
unsigned char disp[]={'M','B','A'}; // Change Array as per requirement

void lcd_init()		  // Initialization Commands
{
RS=0;				  // Command Mode
lcd_cmd(0x38);		  // 2 lines, 5*7 Matrix 
lcd_cmd(0x01);		  // Clear the Display
lcd_cmd(0x0C);		  // Display on Cursor off
lcd_cmd(0x06);		  // Increment cursor
lcd_cmd(0x80);		  // Force the cursor to the Beginning of New line  
EN=1;
delay(6);			  // High to Low pulse with a Delay
EN=0;

}

void lcd_data(char dta)
{
RS=1;					// Data Mode
LCD = dta;				// Send the Data to be Displayed : P2
EN=1;
delay(6);				// High to Low Pulse to Latch to the data
EN=0;
}

void lcd_cmd(char cmd)
{
RS=0;					// Command Mode
LCD = cmd;				// Send the Command to the Data Pins : P2
EN=1;
delay(6);				// High to Low Pulse to latch to the data
EN=0;
}


void delay(int DD)
{
unsigned int i ,j;
for(i=1;i<=DD;i++)
{
for(j=1;j<=50;j++);
}
}

void main(void)
{	// For writing on the LCD
	unsigned int kk;
	RW=0;
	lcd_init();	 
	for(kk=0;kk<3;kk++)
	{
		lcd_data(disp[kk]);    // To Display "MBA"
	}
}

 











