#include "proheader1.h"

void eeprom(void)
{
    rtc_get_time();
    rtc_get_date();

    i2c_write(0xA0,0x01,hours);
		delay_ms(10);
    i2c_write(0xA0,0x02,minutes);
		delay_ms(10);
    i2c_write(0xA0,0x03,seconds);
		delay_ms(10);

    if(hours < 0x12)
		{
        i2c_write(0xA0,0x04,'A');
				delay_ms(10);
				}
    else
		{
        i2c_write(0xA0,0x04,'P');
        delay_ms(10);
		}		
    i2c_write(0xA0,0x05,date);
		delay_ms(10);
    i2c_write(0xA0,0x06,month);
		delay_ms(10);
    i2c_write(0xA0,0x07,year);
		delay_ms(10);
}
