#include <lpc21xx.h>
#include "proheader1.h"
 
   #define GREEN_LED (1<<19)
   #define RED_LED   (1<<20)
   
   int i;
   
   int main()
  {
  uart0_init(9600);
  rtc_init();
  lcd_init();
  servo_init();
  keypad_init();
	
    IODIR0 |= GREEN_LED | RED_LED;
		IOSET0 = GREEN_LED | RED_LED;
  
      // Configure PIR sensor pin (P0.15) as input
      IODIR0 &= ~(1<<15);
  
  
      lcd_cmd(0x01);
      lcd_string("PIR Security");
      lcd_cmd(0xC0);
      lcd_string("System Ready");
		uart0_string("\r\nSystem Ready\r\n");
     delay_ms(200);
  
      while(1)
      {
          PIR_Sensor();     // Call PIR sensor function continuously
                
    }
  }
