#include<lpc21xx.h>
#include"proheader1.h"


void delay_ms(u32 ms)
{
		T0PR=15000-1;
		T0PC=0;
		T0TC=0;
		T0TCR=1;
		while(T0TC<ms);
		T0TCR=0;
}
void delay_sec(u32 sec)
{
		T0PR=15000-1;
		T0PC=0;
		T0TC=0;
		T0TCR=1;
		while(T0TC<sec);
		T0TCR=0;
}
