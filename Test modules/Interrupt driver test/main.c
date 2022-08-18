/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/10/2022 12:00:19 PM														*/
/*															File name: main.c																		*/
/****************************************************************************************************************************************************/


#include "MCAL/Timer driver/Timer_0.h"
#include "MCAL/Ext interrupt driver/Ext interrupt.h"
#include "MCAL/Dio driver/DIO.h"
int main(void)
{
	DIO_pinInit(PD7,Output);
	DIO_pinInit(PC5,Output);
	
	Timer0_init(NORMAL,clkI_DIVISION_BY_1024);
	Ext_interruptInit(INT1,FALLING_EDGE);
	while (1)
	{
		DIO_pinToggle(PC5);
		Timer0_delay_ms(500);	
	}
	return 0;
}

ISR(EXT_INT1)
{
	DIO_pinToggle(PD7);
}

