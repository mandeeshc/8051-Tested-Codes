// Program to test ADC 0808. The output pins are connected to LED's. 
//Controller interrupt is used to generate the clock for driving the ADC 0808.
#include <REGX51.H>
#include "lcd.c"

sbit ale = P1^6;  //address latch enable
sbit oe  = P1^4;  //output enable
sbit sc  = P1^2;  //start conversion
sbit eoc = P1^3;  //end of conversion
sbit clk = P1^5;  // clock

sbit ADD_A=P3^7;  // Address pins for selecting input channels.
sbit ADD_B=P3^6;
sbit ADD_C=P3^5;

//sfr input_port=0x80;
//sfr output_port=0xA0;
char arr[10];
int pos;

void timer0() interrupt 1  // Function to generate clock of frequency 500KHZ using Timer 0 interrupt.
{
clk=~clk;
}

void delay(unsigned int count)  // Function to provide time delay in msec.
{
int i,j;
for(i=0;i<count;i++)
  for(j=0;j<1275;j++);
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

void adc_clk()
{
TMOD=0x22;  //timer0 setting for generating clock of 500KHz using interrupt enable mode.
TH0=0xFD;
IE=0x82;
TR0=1;
}

void main()
{
unsigned int value,val1;
lcd_init();
eoc=1;
ale=0;
oe=0;
sc=0;
adc_clk();
lcd_clr();
lcd_string("VALUE :");
lcd_cmd(0xC0);
while(1)
{
  ADD_C=0;  // Selecting input channel 0 using address lines
  ADD_B=0;
  ADD_A=0;
  delay(1);
  ale=1;
  delay(1);
  sc=1;
  delay(1);
  ale=0;
  delay(1);
  sc=0;
  while(eoc==1);
  while(eoc==0);
  oe=1;
  value = P2;	// P2 --> Data Port for ADC
  //output_port=input_port;
  if(value > 99 && val1 < 100 || value < 100 && val1 > 99)
  {
  lcd_cmd(0xC0);
  lcd_string("                ");
  }
  lcd_cmd(0xC0);
  store_arr(value);
  //delay(1);
  val1 = value;
  oe=0;
}
}