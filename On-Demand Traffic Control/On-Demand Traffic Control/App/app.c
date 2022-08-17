/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/10/2022 12:03:35 PM														*/
/*															File name: app.c																		*/
/****************************************************************************************************************************************************/
#include "../ECUAL/LED driver/LED.h"
#include "../ECUAL/Button driver/Button.h"
#include "../MCAL/Timer driver/Timer_0.h"
#include "../MCAL/Ext interrupt driver/Ext interrupt.h"
#include "app.h"


EN_TrafficStates_t system_CurrentState = NORMAL_GREEN;

void app_start(void)
{
	ledInit(CARS_GREEN_LED);
	ledInit(CARS_YELOW_LED);
	ledInit(CARS_RED_LED);

	
	
	ledInit(PEDESTRIANS_GREEN_LED);
	ledInit(PEDESTRIANS_YELOW_LED);
	ledInit(PEDESTRIANS_RED_LED);
	
	Ext_interruptInit(INT0,FALLING_EDGE);
	Timer0_init(NORMAL,clkI_DIVISION_BY_1024);
	
}
/*************************************************************************************************************************/
void carsGreenState(void)
{
	ledOff(CARS_RED_LED);
	ledOn(CARS_GREEN_LED);
	Timer0_delay_ms(5000);
}
void carsYellowState(void)
{
	ledOff(CARS_YELOW_LED);
	for(uint8_t i = 0; i < 10; i++)
	{
		ledToggle(CARS_YELOW_LED);
		Timer0_delay_ms(500);
		if (system_CurrentState != NORMAL_YELLOW_AFTER_GREEN && system_CurrentState != NORMAL_YELLOW_AFTER_RED)
		{
			break;
		}
	}
	ledOff(CARS_YELOW_LED);
}
void carsRedState(void)
{
	ledOff(CARS_GREEN_LED);
	ledOn(CARS_RED_LED);
	Timer0_delay_ms(5000);
}
/*************************************************************************************************************************/
void trafficLightOperation(void)
{
	ledOn(PEDESTRIANS_RED_LED);
	if (system_CurrentState == NORMAL_GREEN)
	{
		carsGreenState();
		if (system_CurrentState == NORMAL_GREEN)
		{
			system_CurrentState = NORMAL_YELLOW_AFTER_GREEN;
		}
	}
	if (system_CurrentState == NORMAL_YELLOW_AFTER_GREEN)
	{
		carsYellowState();
		if (system_CurrentState == NORMAL_YELLOW_AFTER_GREEN)
		{
			system_CurrentState = NORMAL_RED;
		}
	}
	if (system_CurrentState == NORMAL_RED)
	{
		carsRedState();
		if (system_CurrentState == NORMAL_RED)
		{
			system_CurrentState = NORMAL_YELLOW_AFTER_RED;
		}
	}
	if (system_CurrentState == NORMAL_YELLOW_AFTER_RED)
	{
		carsYellowState();
		if (system_CurrentState == NORMAL_YELLOW_AFTER_RED)
		{
			system_CurrentState = NORMAL_GREEN;
		}
	}
	if(system_CurrentState == BUTTON_PRESSED_AT_GREEN || system_CurrentState == BUTTON_PRESSED_AT_YELLOW )
	{
		ledOn(PEDESTRIANS_RED_LED);
		
		pedestriansYellowState();
		
		pedestriansGreenState();
		
		pedestriansYellowState();
		
		pedestriansRedState();
		system_CurrentState = NORMAL_GREEN;
		
	}
	if (system_CurrentState == BUTTON_PRESSED_AT_RED)
	{
		pedestriansGreenState();
		
		pedestriansYellowState();
		
		pedestriansRedState();
		system_CurrentState = NORMAL_GREEN;
	}
}



/*************************************************************************************************************************/
void pedestriansGreenState(void)
{
	ledOn(PEDESTRIANS_GREEN_LED);
	ledOn(CARS_RED_LED);
	ledOff(CARS_GREEN_LED);
	ledOff(PEDESTRIANS_RED_LED);
	Timer0_delay_ms(5000);
}

void pedestriansYellowState(void)
{
	ledOff(CARS_YELOW_LED);
	ledOff(PEDESTRIANS_YELOW_LED);
	for(uint8_t i = 0; i < 10; i++)
	{
		ledToggle(CARS_YELOW_LED);
		ledToggle(PEDESTRIANS_YELOW_LED);
		Timer0_delay_ms(500);
	}
	ledOff(CARS_YELOW_LED);
	ledOff(PEDESTRIANS_YELOW_LED);
}

void pedestriansRedState(void)
{
	ledOn(CARS_GREEN_LED);
	ledOn(PEDESTRIANS_RED_LED);
	ledOff(PEDESTRIANS_GREEN_LED);
	ledOff(CARS_RED_LED);
}
/*************************************************************************************************************************/
ISR(EXT_INT0)
{
	if (system_CurrentState == NORMAL_GREEN)
	{
		system_CurrentState = BUTTON_PRESSED_AT_GREEN;
	}
	else if (system_CurrentState == NORMAL_YELLOW_AFTER_GREEN || system_CurrentState == NORMAL_YELLOW_AFTER_RED)
	{
		system_CurrentState = BUTTON_PRESSED_AT_YELLOW;
	}
	else if (system_CurrentState == NORMAL_RED)
	{
		system_CurrentState = BUTTON_PRESSED_AT_RED;
	}
}
