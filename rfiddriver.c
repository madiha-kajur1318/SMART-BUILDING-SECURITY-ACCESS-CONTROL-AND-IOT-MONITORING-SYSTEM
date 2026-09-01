#include <lpc21xx.h>
 #include <string.h>
  #include "proheader1.h"
   
   #define GREEN_LED (1<<19)
   #define RED_LED   (1<<20)
   
   int rfid(void)
   {
  char valid_rfid[] = "4900C8FDDCA0";
  char rfid[13];
  int i;
		 
      IODIR0 |= GREEN_LED | RED_LED;
      IOSET0 = GREEN_LED | RED_LED;
uart0_init(9600);
      lcd_init();    
		 
          lcd_cmd(0x01);
          lcd_string("SCAN RFID"); 
                                  uart0_string("scan id");
          for(i = 0; i < 13; i++)
          {
              rfid[i] = '\0';
          }
                                  
                                  for(i = 0; i < 12; i++)
          {
              rfid[i] = uart0_rx();
          }
                          rfid[12]='\0';
                                  
                                  if(strcmp(rfid,valid_rfid)==0)
                                  {
              IOCLR0 = GREEN_LED;
              IOSET0 = RED_LED;
              lcd_cmd(0x01);
              lcd_string("RFID VALID");
                                                  uart0_string("\r\nrfid valid\r\n");
																		rtc_display_time_uart();
																		eeprom();
              delay_ms(2000);
                          servo_180deg();
																		lcd_string("DOOR OPEN");

        uart0_string("DOOR OPEN\r\n");

        delay_ms(2000);
																		servo_0deg();
																		IOSET0=GREEN_LED|RED_LED;
																		return 1;
          }
          else
          {
              IOCLR0 = RED_LED;
              IOSET0 = GREEN_LED;
  
              lcd_cmd(0x01);
              lcd_string("INVALID RFID");
              uart0_string("\r\nINVALID RIFD\r\n");
						rtc_display_time_uart();
						delay_ms(100);
						rtc_display_time_uart();
						
          IOSET0= GREEN_LED | RED_LED;
						return 0;
      }
  }



