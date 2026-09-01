#include<lpc21xx.h>
#include"proheader1.h"

////////// LCD DATA ////////
void lcd_data(u8 data)
{
	u32 TEMP;
	IOCLR1=0XFE<<16;
	TEMP=(data&0x0f)<<16;
	IOSET1=TEMP;
	IOSET1=1<<17;
	IOCLR1=1<<18;
	IOSET1=1<<19;
	delay_ms(2);
	IOCLR1=1<<19;
	
	IOCLR1=0XFE<<16;
	IOSET1=(data&0xf0)<<20;
	IOSET1=1<<17;
	IOCLR1=1<<18;
	IOSET1=1<<19;
	delay_ms(2);
	IOCLR1=1<<19;
}

///////////////// LCD CMD //////////////

	void lcd_cmd(u32 cmd)
{
	u32 TEMP;
	IOCLR1=0XFE<<16;
	TEMP=(cmd&0x0f)<<16;
	IOSET1=TEMP;
	IOCLR1=1<<17;
	IOCLR1=1<<18;
	IOSET1=1<<19;
	delay_ms(2);
	IOCLR1=1<<19;
	
	IOCLR1=0XFE<<16;
	IOSET1=(cmd&0xf0)<<20;
	IOCLR1=1<<17;
	IOCLR1=1<<18;
	IOSET1=1<<19;
	delay_ms(2);
	IOCLR1=1<<19;
}

///////////////// LCD INTIALISATION ///////////////

void lcd_init(void)
{
	IODIR1=0xFE<<16;
	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x0e);
	lcd_cmd(0x01);
}

///////////////// LCD STRING //////////////////

void lcd_string(char *ptr)
{
	while(*ptr)
	{
		lcd_data(*ptr);
		ptr++;
	}
}

////////////////////////////////////////////////
