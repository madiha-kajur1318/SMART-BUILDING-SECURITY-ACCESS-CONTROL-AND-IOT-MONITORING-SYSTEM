#include <LPC21xx.H>
#include "proheader1.h"

void i2c_init(void)
	{
	PINSEL0|=0x50;
	I2CONSET=(1<<6);
	I2SCLH=I2SCLL=75;
}

//////////////////write

#define SI ((I2CONSET>>3)&1)
void i2c_write(u8 sa, u8 mr, u8 data)
	{
	I2CONSET=(1<<5);
	I2CONCLR=(1<<3);
	while(SI==0);
	I2CONCLR=(1<<5);
	
	I2DAT=sa;
	I2CONCLR=(1<<3);
	while(SI==0);
	if(I2STAT==0x20)
		{
		uart0_string("Err: SA+W\r\n");
		goto exit;
	}
	
	I2DAT=mr;
	I2CONCLR=(1<<3);
	while(SI==0);
	if(I2STAT==0x30)
		{
		uart0_string("Err: Memory Addr\r\n");
		goto exit;
	}
	
	I2DAT=data;
	I2CONCLR=(1<<3);
	while(SI==0);
	if(I2STAT==0x30)
		{
		uart0_string("Err: Data\r\n");
		goto exit;
	}
	
	exit:
			I2CONSET=(1<<4);
			I2CONCLR=(1<<3);
}

//////////////////////////read///////////////////////////

u8 i2c_read(u8 sa,u8 mr)
{
	u8 temp;
	I2CONSET=(1<<5);
	I2CONCLR=(1<<3);
	while(SI==0);
	I2CONCLR=(1<<5);
	
	I2DAT=sa&0xFE;
	I2CONCLR=(1<<3);
	while(SI==0);
	if(I2STAT==0x20)
		{
		uart0_string("Err: SA+W\r\n");
		goto exit;
	}
	
	I2DAT=mr;
	I2CONCLR=(1<<3);
	while(SI==0);
	if(I2STAT==0x30)
		{
		uart0_string("Err: Memory Addr\r\n");
		goto exit;
	}
	
	I2CONSET=(1<<5);
	I2CONCLR=(1<<3);
	while(SI==0);
	I2CONCLR=(1<<5);
	
	I2DAT=sa;
	I2CONCLR=(1<<3);
	while(SI==0);
	if(I2STAT==0x48)
		{
		uart0_string("Err: SA+R\r\n");
		goto exit;
	}
	
	I2CONCLR=(1<<3);
	while(SI==0);
	temp=I2DAT;
	
	exit:
			I2CONSET=(1<<4);
			I2CONCLR=(1<<3);
		return temp;
}

//////////////////////////////////////////////////
