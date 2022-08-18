/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/10/2022 12:00:19 PM														*/
/*															File name: main.c																		*/
/****************************************************************************************************************************************************/

#include "MCAL/Timer driver/Timer_0.h"
#include "MCAL/Dio driver/DIO.h"
int main(void)
{
	DIO_pinInit(PA0,Output);
	DIO_pinInit(PB3,Output);
	DIO_pinInit(PC5,Output);
	DIO_pinInit(PD7,Output);
	
	Timer0_init(NORMAL,clkI_DIVISION_BY_1024);
	while (1)
	{
		DIO_pinWrite(PA0,High);
		DIO_pinWrite(PB3,High);
		DIO_pinWrite(PC5,High);
		Timer0_delay_ms(3000);
		DIO_pinWrite(PA0,Low);
		DIO_pinWrite(PB3,Low);
		DIO_pinWrite(PC5,Low);
		
		for(uint8_t i = 0; i < 6; i++)
		{
			DIO_pinToggle(PD7);
			Timer0_delay_ms(500);
		}
		
		
		
		
	}
	return 0;
}

