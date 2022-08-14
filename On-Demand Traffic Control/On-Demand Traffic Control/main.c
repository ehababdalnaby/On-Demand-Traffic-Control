/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/10/2022 12:00:19 PM														*/
/*															File name: main.c																		*/
/****************************************************************************************************************************************************/

#include "./ECUAL/LED driver/LED.h"
#include "MCAL/Ext interrupt driver/Ext interrupt.h"

int main(void)
{
	ledInit(PA0);
	ledInit(PB0);
	Ext_interruptInit(INT0,ANY_LOGICAL_CHANGE);
	while (1)
	{
		ledOn(PB0);
		
	}
	return 0;
}


