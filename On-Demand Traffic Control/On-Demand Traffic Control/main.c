/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/10/2022 12:00:19 PM														*/
/*															File name: main.c																		*/
/****************************************************************************************************************************************************/

#include "./ECUAL/LED driver/LED.h"
#include "MCAL/Ext interrupt driver/Ext interrupt.h"
#include "MCAL/Timer driver/Timer_0.h"
int main(void)
{
	ledInit(PA0);
	ledInit(PB0);
	Ext_interruptInit(INT0,ANY_LOGICAL_CHANGE);
	Timer0_init(NORMAL,clkI_DIVISION_BY_1024);
	while (1)
	{
		ledOff(PB0);
		Timer0_delay_ms(1000);
		ledOn(PB0);
		Timer0_delay_ms(1000);
	}
	return 0;
}


