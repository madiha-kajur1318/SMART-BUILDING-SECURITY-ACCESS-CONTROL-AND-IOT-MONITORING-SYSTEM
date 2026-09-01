#include<lpc21xx.h>
#include "proheader1.h"
#define RTC_W 0xD0
#define RTC_R 0xD1
unsigned char hours,minutes,seconds;
unsigned char date,month,year;
void rtc_init(void)
{
i2c_init();
}
void rtc_set_time(u8 hours,u8 minutes,u8 seconds)
{
    i2c_write(RTC_W,0x00,seconds);
    i2c_write(RTC_W,0x01,minutes);
    i2c_write(RTC_W,0x02,hours);
}
void rtc_set_date(u8 date,u8 month,u8 year)
{
    i2c_write(RTC_W,0x04,date);
    i2c_write(RTC_W,0x05,month);
    i2c_write(RTC_W,0x06,year);
}
void rtc_get_time(void)
{
    seconds = i2c_read(RTC_R,0x00);
    minutes = i2c_read(RTC_R,0x01);
    hours  = i2c_read(RTC_R,0x02);
}
void rtc_get_date(void)
{
    date  = i2c_read(RTC_R,0x04);
    month = i2c_read(RTC_R,0x05);
    year  = i2c_read(RTC_R,0x06);
}
void rtc_display_time(void)
{
    rtc_get_time();

    lcd_data((hours>>4)+'0');
    lcd_data((hours&0x0F)+'0');
    lcd_data(':');

    lcd_data((minutes>>4)+'0');
    lcd_data((minutes&0x0F)+'0');
    lcd_data(':');

    lcd_data((seconds>>4)+'0');
    lcd_data((seconds&0x0F)+'0');
}
void rtc_display_date(void)
{
    rtc_get_date();

    lcd_data((date>>4)+'0');
    lcd_data((date&0x0F)+'0');
    lcd_data('/');

    lcd_data((month>>4)+'0');
    lcd_data((month&0x0F)+'0');
    lcd_data('/');
		lcd_data('2');
    lcd_data('0');
    lcd_data((year>>4)+'0');
    lcd_data((year&0x0F)+'0');
}

void rtc_display_time_uart(void)
{
    rtc_get_time();

    uart0_tx((hours >> 4) + '0');
    uart0_tx((hours & 0x0F) + '0');

    uart0_tx(':');

    uart0_tx((minutes >> 4) + '0');
    uart0_tx((minutes & 0x0F) + '0');

    uart0_tx(':');

    uart0_tx((seconds >> 4) + '0');
    uart0_tx((seconds & 0x0F) + '0');

    uart0_string("\r\n");
}
