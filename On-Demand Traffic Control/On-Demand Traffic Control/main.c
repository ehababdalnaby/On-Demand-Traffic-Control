/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/10/2022 12:00:19 PM														*/
/*															File name: main.c																		*/
/****************************************************************************************************************************************************/

#include "./ECUAL/LED driver/LED.h"
#include "MCAL/Ext interrupt driver/Ext interrupt.h"
#include "MCAL/Timer driver/Timer_0.h"
#include "App/app.h"
int main(void)
{
	ledInit(PB0);
	app_start();
	while (1)
	{
		trafficLightOperation();
	}
	return 0;
}


