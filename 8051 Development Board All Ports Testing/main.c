#include<REGX51.H>
//*************************************************** 
void delay(int del)
{
	unsigned int i,j;
	for(i=0;i<1275;i++)
	{
		for(j=0;j<=del;j++);
	}
}
/****************************************************/
int main(void)
{
	while(1)
	{
		P0 = 0x00;		P1 = 0x00;
		P2 = 0x00;		P3 = 0x00;
		delay(50);
		P0 = 0xff; 		P1 = 0xff;
		P2 = 0xff;		P3 = 0xff;
		delay(50);
	}
}
