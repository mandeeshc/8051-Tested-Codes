#include <REGX51.H>
#define LCD P2
sbit RS = P1^0;	     //LCD Register Select
sbit EN = P1^1;	     //LCD Enable

void delay2(unsigned int);
void lcd_data(unsigned char);
void lcd_cmd(char);
void lcd_clr();

void lcd_init()
	{
	RS=0;
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x0C);
	lcd_cmd(0x06);
	lcd_cmd(0x80);
	EN=1;
	delay2(6);
	EN=0;
   }
void main_lcd()
	{
	lcd_clr();
	lcd_data('O');
	lcd_data('K');
	delay2(500);
	lcd_clr();
	}

void lcd_data(unsigned char dta)
{
RS=1;
LCD = dta;
EN=1;
delay2(6);
EN=0;
}

void lcd_cmd(char cmmd)
{
RS=0;
LCD = cmmd;
EN=1;
delay2(6);
EN=0;
}


void delay2(unsigned int DD)
{unsigned int i,j;
for(i=1;i<=DD;i++)
{
for(j=1;j<=50;j++);
}
}

void lcd_string(char *dat)
	{
	while(*dat)
	lcd_data(*dat++);
	}

void lcd_clr()
	{
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	}

