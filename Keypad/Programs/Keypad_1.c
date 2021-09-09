// ***** Program to detect and identify a keypressed in a 4*4 Matrix ***** //
#include <REGX52.H>
#define LED P1
sbit R1 = P0^0; 
sbit R2 = P0^1;
sbit R3 = P0^2;
sbit R4 = P0^3;
sbit C1 = P0^4;
sbit C2 = P0^5;
sbit C3 = P0^6;
sbit C4 = P0^7;

unsigned int k;
unsigned int col1_detect();
unsigned int col2_detect();
unsigned int col3_detect();
unsigned int col4_detect();

void key_function(unsigned int);
void delay(unsigned int del)
  {
   unsigned int i,j;
   for(i=0;i<=1275;i++)
     for(j=0;j<=del;j++);
  }
void main()
  {	
   while(1)
     {
     R1=0;R2=0;R3=0;R4=0;
    if(C1==0)
	    {
		 delay(5);
		 k=col1_detect();
		 key_function(k);
		}  
	else if(C2==0)
	    {
		 delay(5);
		 k=col2_detect();
		 key_function(k);
		}			  
    else if(C3==0)
	    {
		 delay(5);
		 k=col3_detect();
		 key_function(k);
		}
	else if(C4==0)
	    {
		 delay(5);
		 k=col4_detect();
		 key_function(k);
	   	}
	 }
  }
unsigned int col1_detect()
 {
   R1=0;R2=1;R3=1;R4=1;
   if(C1==0)
     {
		  //while(!C1);
  return(1);
	 }
  R1=1;R2=0;R3=1;R4=1;
   if(C1==0)
     {
	  //while(!C1);
	  return(5);
	 }
  R1=1;R2=1;R3=0;R4=1;
    if(C1==0)
     {
	  //while(!C1);
	  return(9);
	 }
  R1=1;R2=1;R3=1;R4=0;
   if(C1==0)
    {
	 //while(!C1);
	 return(13);
	}
  }
// ************************ //
unsigned int col2_detect()
	{
   R1=0;R2=1;R3=1;R4=1;
   if(C2==0)
     {
	 // while(!C2);
	  return(2);
	 }
    R1=1;R2=0;R3=1;R4=1;
    if(C2==0)
     {
	 // while(!C2);
	  return(6);
	 }   
   R1=1;R2=1;R3=0;R4=1;
   if(C2==0)
     {
	  //while(!C2);
	  return(10);
	 }
    R1=1;R2=1;R3=1;R4=0;
    if(C2==0)
     {
	 // while(!C2);
	  return(14);
	 }
	}
// ************************ //
unsigned int col3_detect()
	{
    R1=0;R2=1;R3=1;R4=1;
   if(C3==0)
     {
	 // while(!C3);
	  return(3);
	 }
    R1=1;R2=0;R3=1;R4=1;
   	if(C3==0)
     {
	 // while(!C3);
	  return(7);
	 }
    R1=1;R2=1;R3=0;R4=1;
    if(C3==0)
     {
	  //while(!C3);
	  return(11);
	 }
    R1=1;R2=1;R3=1;R4=0;
    if(C3==0)
     {
	  //while(!C3);
	  return(15);
	 }
   }
// ************************ //
unsigned int col4_detect()
	{ 
   R1=0;R2=1;R3=1;R4=1;
   if(C4==0)
     {
	 // while(!C4);
	  return(4);
	 }
    R1=1;R2=0;R3=1;R4=1;
    if(C4==0)
     {
	 // while(!C4);
	  return(8);
	 }
    R1=1;R2=1;R3=0;R4=1;
    if(C4==0)
     {
	  //while(!C4);
	  return(12);
	 }
   R1=1;R2=1;R3=1;R4=0;
   if(C4==0)
    {
	 // while(!C4);
	  return(16);
	 }
   }
  
void key_function(unsigned int key)
   {
   	switch(key)
	  {
	   case 1: LED=0x00;
	   		   break;
	   case 2: LED=0x01;
	           break;
	   case 3: LED=0x02;
	           break;
	   case 4: LED=0x03;
	           break;
	   case 5: LED=0x04;
	           break;
	   case 6: LED=0x05;
	           break;
	   case 7: LED=0x06;
	           break;
 	   case 8: LED=0x07;
	           break;
	   case 9: LED=0x08;
	           break;
	   case 10: LED=0x09;
	           break;
	   case 11: LED=0x0a;
	           break;
 	   case 12: LED=0x0b;
	           break;
  	 case 13: LED=0x0c;
	           break;
     case 14: LED=0x0d;
	           break;
	   case 15: LED=0x0e;
	           break;
	   case 16: LED=0x0f;
	           break;
	 //  default: LED = 0xff;
	 //  			break;
	  }
   } 
      