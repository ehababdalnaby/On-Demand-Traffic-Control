/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/10/2022 12:03:35 PM														*/
/*															File name: app.c																		*/
/****************************************************************************************************************************************************/

#define SYSTEM_CLK 1000000
#include "../ECUAL/LED driver/LED.h"
#include "../ECUAL/Button driver/Button.h"
#include "../MCAL/Timer driver/Timer_0.h"
#include "../MCAL/Ext interrupt driver/Ext interrupt.h"
#include "app.h"

/**
*@brief system current state
*\details
*\arg This variable store the current state of the system.
*/
EN_TrafficStates_t static system_CurrentState = NORMAL_GREEN;

void app_start(void)
{
	//initialize cars leds as output
	ledInit(CARS_GREEN_LED);
	ledInit(CARS_YELOW_LED);
	ledInit(CARS_RED_LED);
	
	//initialize pedestrians leds as output
	ledInit(PEDESTRIANS_GREEN_LED);
	ledInit(PEDESTRIANS_YELOW_LED);
	ledInit(PEDESTRIANS_RED_LED);
	
	//enable #INT0 to trigger at falling edge 
	Ext_interruptInit(INT0,FALLING_EDGE);
	
	//configure Timer 0 at normal mode and prescaler 1024
	Timer0_init(NORMAL,clkI_DIVISION_BY_1024);
	
}
/*************************************************************************************************************************/
void carsGreenState(void)
{
	ledOff(CARS_RED_LED);//turn cars red led off
	ledOn(CARS_GREEN_LED);//turns card green led on
	Timer0_delay_ms(5000);//wait for 5 sec
}

void carsYellowState(void)
{
	ledOff(CARS_YELOW_LED);
	//toggle cars yellow led for 5 sec
	for(uint8_t i = 0; i < 10; i++)
	{
		ledToggle(CARS_YELOW_LED);
		Timer0_delay_ms(500);
		//check if the system state changed due to button pressed then break from the loop
		if (system_CurrentState != NORMAL_YELLOW_AFTER_GREEN && system_CurrentState != NORMAL_YELLOW_AFTER_RED)
		{
			break;
		}
	}
	ledOff(CARS_YELOW_LED);
}
void carsRedState(void)
{
	ledOff(CARS_GREEN_LED);//turn cars green led off
	ledOn(CARS_RED_LED);   //turns card red led on
	Timer0_delay_ms(5000); //wait for 5 sec
}
/*************************************************************************************************************************/
void trafficLightOperation(void)
{
	/***********************************************<Normal mode states>*****************************************/
	ledOn(PEDESTRIANS_RED_LED);//turn pedestrians red led on
	/*check if the current state is NORMAL_GREEN*/
	if (system_CurrentState == NORMAL_GREEN)
	{
		//execute cars green state
		carsGreenState();
		//after the state finished execution
		//check if i still in the same state
		//as the state might be changed due to a button pressed
		// if i still in the same state then change the current state to the next one which is in this example NORMAL_YELLOW_AFTER_GREEN
		//if the current state changed then do nothing just go to the state which assigned by the button 
		if (system_CurrentState == NORMAL_GREEN)
		{
			system_CurrentState = NORMAL_YELLOW_AFTER_GREEN;
		}
	}
	/*normal yellow after green state*/
	if (system_CurrentState == NORMAL_YELLOW_AFTER_GREEN)
	{
		carsYellowState();
		if (system_CurrentState == NORMAL_YELLOW_AFTER_GREEN)
		{
			system_CurrentState = NORMAL_RED;
		}
	}
	/*normal red state */
	if (system_CurrentState == NORMAL_RED)
	{
		carsRedState();
		if (system_CurrentState == NORMAL_RED)
		{
			system_CurrentState = NORMAL_YELLOW_AFTER_RED;
		}
	}
	/*normal yellow after red state*/
	if (system_CurrentState == NORMAL_YELLOW_AFTER_RED)
	{
		carsYellowState();
		if (system_CurrentState == NORMAL_YELLOW_AFTER_RED)
		{
			system_CurrentState = NORMAL_GREEN;
		}
	}
	/***********************************************<Pedestrians mode states>*****************************************/
	//if the button pressed at green state or one of yellow state
	if(system_CurrentState == BUTTON_PRESSED_AT_GREEN || system_CurrentState == BUTTON_PRESSED_AT_YELLOW )
	{
		ledOn(PEDESTRIANS_RED_LED);
		
		pedestriansYellowState();
		
		pedestriansGreenState();
		
		pedestriansYellowState();
		
		pedestriansRedState();
		system_CurrentState = NORMAL_GREEN;
		
	}
	//if the button pressed at red state
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
	ledOn(PEDESTRIANS_GREEN_LED);//turn pedestrians green led on
	ledOn(CARS_RED_LED);//turn cars red led on
	ledOff(CARS_GREEN_LED);//turn cars green led off
	ledOff(PEDESTRIANS_RED_LED);//turn pedestrians red led off
	Timer0_delay_ms(5000);//wait for 5 sec
}

void pedestriansYellowState(void)
{
	ledOff(CARS_YELOW_LED);
	ledOff(PEDESTRIANS_YELOW_LED);
	//blink pedestrians and cars yellow led for 5 sec
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
	ledOn(CARS_GREEN_LED);//turn cars green led on
	ledOn(PEDESTRIANS_RED_LED);//turn pedestrians red led on
	ledOff(PEDESTRIANS_GREEN_LED);//turn pedestrians green led off
	ledOff(CARS_RED_LED);//turn cars red led off
}
/*************************************************************************************************************************/
ISR(EXT_INT0)
{
	//if the button pressed at normal green state then switch to #BUTTON_PRESSED_AT_GREEN state
	if (system_CurrentState == NORMAL_GREEN)
	{
		system_CurrentState = BUTTON_PRESSED_AT_GREEN;
	}
	//if the button pressed at one of yellow states then switch to #BUTTON_PRESSED_AT_YELLOW state
	else if (system_CurrentState == NORMAL_YELLOW_AFTER_GREEN || system_CurrentState == NORMAL_YELLOW_AFTER_RED)
	{
		system_CurrentState = BUTTON_PRESSED_AT_YELLOW;
	}
	//if the button pressed at red state the switch to #BUTTON_PRESSED_AT_RED state
	else if (system_CurrentState == NORMAL_RED)
	{
		system_CurrentState = BUTTON_PRESSED_AT_RED;
	}
	else
	{
		//do nothing as at this state the button pressed at pedestrians mode.
		//this will neglect two press and long press.
	}
}
