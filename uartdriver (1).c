#include<lpc21xx.h>
#include"proheader1.h"
#include<stdio.h>

//////////////UART INTIALISATION ////////

void uart0_init(u32 baud)
{
	int pclk,result;
	if(VPBDIV==0x0)
		pclk=15000000;
	else if(VPBDIV==0x1)
		pclk=60000000;
	else if(VPBDIV==0x2)
		pclk=30000000;
	result=pclk/(16*baud);
	PINSEL0|=0x00000005;
	U0LCR=0x83;
	U0DLM=(result>>8)&0xff;
	U0DLL=(result)&0xff;
	U0LCR=0x3;
}

///////////// TX UART ////////////

#define THRE ((U0LSR>>5)&1)
void uart0_tx(u8 data)
{
	U0THR=data;
	while(THRE==0);
}

///////////// RX UART //////////////

	#define RDR (U0LSR&1)
u8 uart0_rx()
{
	while(RDR==0);
	return U0RBR;
}

///////////// STRING //////////////////

void uart0_string(char *ptr)
{
	while(*ptr)
	{
		uart0_tx(*ptr);
		ptr++;
	}
}

/////////////// BINARY ////////////////

void  binary(int num)
{
	int pos,temp;
	for(pos=7;pos>=0;pos--)
	{
		temp=(num>>pos&1);
		uart0_tx(temp+48);
	}
}

//////////// TX STRING ////////////////

 void uart0_integer(int num)
{
	char arr[10];
	sprintf(arr,"%d",num);
	uart0_string(arr);
}

void  uart0_float(float num)
{
	char arr[10];
	sprintf(arr,"%1.f",num);
	uart0_string(arr);
}

//////////////// RX INTEGER /////////////////
	
	int uart0_rx_integer()
	{
		int i,num1;
		char s[10];
		uart0_rx_string(s);
		if(s[0]=='-'||s[0]=='+')
			i=1;
		else
		i=0;
		for(i=0,num1=0;s[i];i++)
		{
		num1=num1*10+(s[i]-48);
		}
		if(s[0]=='-')
			num1=-num1;
		return num1;
	}
	
	///////////////	RX STRING ///////////////////
	
	void uart0_rx_string(char *ptr)
{
	char ch;
	int i=0;
	while(1)
	{
		ch=uart0_rx();
		uart0_tx(ch);
		if(ch=='\r'||ch=='\n')
			break;
		ptr[i++]=ch;
	}
	ptr[i]='\0';
}

///////////////////////////////////////////////
