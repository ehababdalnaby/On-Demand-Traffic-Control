/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/14/2022 12:55:03 PM														*/
/*															File name: Timer_0.c																	*/
/****************************************************************************************************************************************************/
#include "Timer_0.h"
#include <math.h>
#include "../Interrupt/Interrupt.h"
/**
*\var EN_Timer0_clkSource_t Timer0_globalClkSource
*@brief Global static variable for Timer 0 clock source 
*\details
*\arg This variable stores the value of the clock source for Timer 0.
*/
static EN_Timer0_clkSource_t Timer0_globalClkSource = clkI_No_DIVISON;
/*******************************************************************************************************************/
/**
*@var uint32_t Timer0_globalNumOfOverFlows
*@brief Global static variable for Timer 0 over flows number
*\details
*\arg This variable stores the number of over flows of the clock source for Timer 0.
*\arg This variable declared as volatile to prevent the compiler from deleting it as\n
it will be used by #ISR.
*/
static uint32_t volatile Timer0_globalNumOfOverFlows = 0;
/*******************************************************************************************************************/
/**
*@var float64_t volatile Timer0_globalOverFlowTime
*@brief Global static variable for Timer 0 over flow time
*\details
*\arg This variable stores the time for one over flow.
*/
static float64_t volatile Timer0_globalOverFlowTime = 0;
/**
*@var float64_t volatile Timer0_globalTickTime
*@brief Global static variable for Timer 0 tick time
*\details
*\arg This variable stores the time for one tick.
*/
static float64_t volatile Timer0_globalTickTime = 0;
/*******************************************************************************************************************/
En_Timer0_Error_t Timer0_init(EN_Timer0_Mode_t Timer0_mode,EN_Timer0_clkSource_t Timer0_clkSource)
{
	En_Timer0_Error_t Timer0_error = TIMER0_OK;
	//selecting Timer 0 mode
	if (Timer0_mode == NORMAL || Timer0_mode == PWM_PHASE_CORRECR || Timer0_mode == CTC || Timer0_mode == FAST_PWM)
	{

		//clear the old mode value
		TCCR0 &= CLR_TIMER0_MODE;
		//set the new mode value
		TCCR0 |= Timer0_mode;
	}
	else
	{
		Timer0_error = TIMER0_WRONG_MODE;
	}
	//selecting Timer 0 clock source
	if (Timer0_clkSource >= NO_CLOCK_SOURCE && Timer0_clkSource <= EXTERNAL_CLOCK_RISING_EDGE)
	{
		Timer0_globalClkSource = Timer0_clkSource;
		
		
		uint16_t Timer0_localClkPrescaler[] = {0,1,8,64,256,1024};
		//calculate Timer 0 tick time
		Timer0_globalTickTime = (float64_t)Timer0_localClkPrescaler[Timer0_clkSource]/SYSTEM_CLK;
		//calculate Timer 0 over flow time
		Timer0_globalOverFlowTime = Timer0_globalTickTime * TIMER0_NUM_OF_TICKS;
	} 
	else
	{
		Timer0_error = TIMER0_WRONG_CLK_SOURCE;
	}
	return Timer0_error;
}
/*******************************************************************************************************************/
void Timer0_start(void)
{
	//clear the old clock source value
	TCCR0 &= CLR_TIMER0_CLK_SRC;
	//set the new clock source value
	TCCR0 |= Timer0_globalClkSource << CS00;
}
/*******************************************************************************************************************/
void Timer0_stop(void)
{
	//clear the value of Timer 0 clock source 
	//this is done by clearing the three bits #CS00, #CS01 and #CS02
	TCCR0 &= CLR_TIMER0_CLK_SRC;
}
/*******************************************************************************************************************/
void Timer0_reset(void)
{
	TCNT0 = 0x00;
	Timer0_globalNumOfOverFlows = 0;
}
/*******************************************************************************************************************/
En_Timer0_Error_t Timer0_interruptDiable(TIMER0_interrupt_t Timer0_interrupt)
{
	En_Timer0_Error_t Timer0_error = TIMER0_OK;
	if (Timer0_interrupt == TIMER0_OVER_FLOW_INT || Timer0_interrupt == TIMER0_OUT_CMP_MATCH_INT)
	{
		clrBit(TIMSK,Timer0_interrupt);
	}
	else
	{
		Timer0_error = TIMER0_WRONG_INT;
	}
	return Timer0_error;
}
/*******************************************************************************************************************/
En_Timer0_Error_t Timer0_interruptEnable(TIMER0_interrupt_t Timer0_interrupt)
{
	En_Timer0_Error_t Timer0_error = TIMER0_OK;
	if (Timer0_interrupt == TIMER0_OVER_FLOW_INT || Timer0_interrupt == TIMER0_OUT_CMP_MATCH_INT)
	{
		sei();
		setBit(TIMSK,Timer0_interrupt);
	}
	else
	{
		Timer0_error = TIMER0_WRONG_INT;
	}
	return Timer0_error;
}
/*******************************************************************************************************************/
void Timer0_delay_ms(uint32_t delay_ms)
{
	//reset Timer 0
	Timer0_reset();
	//convert delay time from mile seconds to seconds
	float64_t neededTimeInsecond = (float64_t)delay_ms/1000;
	//calculate number of over flows needed to reach the desired time
	uint32_t numberOfoverFlows = ceil(neededTimeInsecond/Timer0_globalOverFlowTime);
	//calculate the initial value for #TCNT0 register
	TCNT0 = TIMER0_NUM_OF_TICKS -(neededTimeInsecond/Timer0_globalTickTime)/numberOfoverFlows;
	//enable Timer 0 over flow interrupt
	Timer0_interruptEnable(TIMER0_OVER_FLOW_INT);
	//start Timer 0 to count
	Timer0_start();
	//wait until reaching needed number over flows
	while(Timer0_globalNumOfOverFlows < numberOfoverFlows);
	//stop Timer 0 after reaching the desired time.
	Timer0_stop();
}

ISR(TIM0_OVF)
{
	Timer0_globalNumOfOverFlows++;
}