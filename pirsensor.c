#include<lpc21xx.h>
#include"proheader1.h"

#define GREEN_LED (1<<19)
#define RED_LED (1<<20)

#define BUZZER  (1<<21)

#define Pir_sens ((IOPIN0 >> 15 ) & 1)

void PIR_Sensor(void)
{
	IODIR0 |= GREEN_LED | RED_LED | BUZZER;
  if(Pir_sens == 0) // NO Motion
	{
	   uart0_string("Motion Status : CLEAR \r\n");
		 uart0_string("Security : NORMAL \r\n");
		 
		 IOCLR0 = GREEN_LED;
		 IOSET0 = RED_LED;
		 
		 IOCLR0 = BUZZER;
		 
		 lcd_cmd(0x01);
		 lcd_cmd(0x80);
		 lcd_string("Field :SAFE");
		 lcd_cmd(0xC0);
		 lcd_string("No Motion");
	}
	else
	{
	   uart0_string("Motion Status : DETECTED\r\n");
		 uart0_string("Security : ALERT\r\n");
		 
		 IOCLR0 = RED_LED;
		 IOSET0 = GREEN_LED;
		 
		 IOSET0 = BUZZER;
		 
		 lcd_cmd(0x01);
		 lcd_cmd(0x80);
		 lcd_string("Motion Found");
		 lcd_cmd(0xC0);
		 lcd_string("Check Field");
		if(rfid()==0)
                {
               key();
                }
	}
	
	uart0_string("-----------------------------------\r\n");
	
	delay_ms(100);
}
