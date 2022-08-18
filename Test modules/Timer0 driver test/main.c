/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/10/2022 12:00:19 PM														*/
/*															File name: main.c																		*/
/****************************************************************************************************************************************************/

#include "MCAL/Timer driver/Timer_0.h"
#include "MCAL/Dio driver/DIO.h"
int main(void)
{
	DIO_pinInit(PD7,Output);
	
	Timer0_init(NORMAL,clkI_DIVISION_BY_1024);
	while (1)
	{
		
		
			DIO_pinToggle(PD7);
			Timer0_delay_ms(3000);
	
	}
	return 0;
}

