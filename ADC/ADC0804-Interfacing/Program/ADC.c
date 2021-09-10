#include<regx51.h>
#include "lcd.c"
sbit CS   = P1^7;
sbit RDD  = P1^2;
sbit WRT  = P1^3;
sbit INTR = P1^4;

char arr[10];
int pos;

void delay(unsigned int xdel)
  {
  unsigned int k,l;
  for(k=0;k<=xdel;k++)
     for(l=0;l<=200;l++);
  }

void store_arr(int val)
	{
	int in=0, v1 = 0;
	pos=0;
	for(in=0;in<=9;in++)
		{	
		arr[in]=' ';
		}
	in=0;
	while(val!=0)
		{
	   	arr[in]=val%10;
	   	arr[in]=arr[in]+48;
	   	val=val/10;
	   	in++;
	   	pos++;	
		}
    for(v1=pos-1;v1>=0;v1--)
		{
		lcd_data(arr[v1]);
		}
	}
  
   													
void main()
	{
	unsigned int value = 0, val1,loopv =0;
  lcd_init();
	main_lcd();
	lcd_clr();
	lcd_string("VALUE :");
	while(1)
	{
	for(loopv=0;loopv<50;loopv++)
		{
		CS = 0;
		WRT = 0;
		delay(1);
		WRT = 1;
		CS = 1;
		while(INTR==1);
		CS = 0;
		RDD = 0;
		delay(1);
		RDD = 1;
		value = P3 + value;
		CS = 1;
		delay(5);	
		}
		value = value/50;
		//P3=value;				// Debugging
	if(value > 99 && val1 < 100 || value < 100 && val1 > 99)
	  {
	  lcd_cmd(0xC0);
	  lcd_string("                ");
	  }
	lcd_cmd(0xC0);
	//lcd_string("                ");
	//lcd_cmd(0xC0);
	val1 = value;
	store_arr(value);
	delay(50);
	value = 0;	
	}
	}
























