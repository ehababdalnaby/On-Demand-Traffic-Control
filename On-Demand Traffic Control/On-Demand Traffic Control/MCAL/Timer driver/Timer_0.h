/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/14/2022 12:55:53 PM														*/
/*															File name: Timer_0.h																	*/
/****************************************************************************************************************************************************/

#ifndef TIMER_0_H_
#define TIMER_0_H_
#include "../../Service/BitMath.h"
#include "../../Service/ATmega32Port.h"
#include "../../Service/dataTypes.h"
#include "../../Service/RegisterFile.h"
/**
*\defgroup Timers_driver	Timers driver
*\ingroup MCAL
*\details
*This contains the drivers for Atmega32 Timers
*/
/******************************************************************************************************/
/**
*\defgroup Timer0_driver	Timer0 driver
*\ingroup Timers_driver
*@{
*/
/******************************************************************************************************/
/**
*@brief System clock Macro
*\details
*\arg This Macro is the system clock that the user used.
*\arg It should provided in hertz like this \code #define SYSTEM_CLK	1000000UL \endcode.
*\arg Default value is 1 MHz.
*/
#ifndef SYSTEM_CLK
/* prevent compiler error by supplying a default */
# warning "SYSTEM_CLK not defined for Timer_0.h, default value is 1MHz"
#define SYSTEM_CLK	1000000UL
#endif
/******************************************************************************************************/
/**
*@brief Number of Ticks.
*\details
*\arg This Macro is the Number of Ticks for Timer 0.
*\arg It the number of ticks for one over flow.
*\arg It can be calculated by 2^num of bits, Timer 0 is 8 bit timer\n so number of ticks for Timer 0 are 2^8 = 256.
*/
#define TIMER0_NUM_OF_TICKS	256
/******************************************************************************************************/
/**
*@name Bit 2:0 - CS02:0: Clock Select
*\details
*\arg The three Clock Select bits select the clock source to be used by the Timer/Counter and located in #TCCR0.
|CS02  |CS01  |CS00  | Description												|
|:---: |:---: |:---: | :--------------------------------------------------------|
|0	   |0	  |0	 |No clock source\n (Timer/Counter stopped).				|
|0	   |0	  |1	 |clkI/O/(No prescaling).									|
|0	   |1	  |0	 |clkI/O/8 (From prescaler).								|
|0	   |1	  |1	 |clkI/O/64 (From prescaler).								|
|1	   |0	  |0	 |clkI/O/256 (From prescaler).								|
|1	   |0	  |1	 |clkI/O/1024 (From prescaler).								|
|1	   |1	  |0	 |External clock source on T0 pin.\n Clock on falling edge.	|
|1	   |1	  |1	 | External clock source on T0 pin.\n Clock on rising edge.	|
|<b>Clock Select Bit Description</b>||||
\note If external pin modes are used for the Timer/Counter0, transitions on the T0 pin will\n
clock the counter even if the pin is configured as an output. This feature allows software\n
control of the counting.
*/
///@{
#define CS00	0
#define CS01	1
#define CS02	2
///@}
/******************************************************************************************************/
/**
*@brief<h3> Clear Timer 0 clock source</h3>
*\details
*\arg This macro used to clear Timer 0 clock source.
*\arg Anding the register #TCCR0 by the #CLR_TIMER0_CLK_SRC (0b1111 1000) will result clearing the three bits\n
	#CS00, #CS01 and #CS02.
*/
#define CLR_TIMER0_CLK_SRC 0xF8
/******************************************************************************************************/
/**
*@name Bit 6, 3 - WGM01:0: Waveform Generation Mode
*\details
*\arg These bits control the counting sequence of the counter and located in #TCCR0.
*\arg the source for the maximum (TOP) counter value,\n and what type of Waveform Generation to be used.
| Mode  |WGM01\n (CTC0)  |WGM00\n (PWM0) |Timer/Counter\n Mode of Operation  |TOP	|Update of\n OCR0   | TOV0 Flag\n Set-on|
|:----: |:--------------:|:-------------:|:---------------------------------:|:-----:|:-----------------:| :----------------:|
| 0	   |0				|0				|Normal								|0xFF	|Immediate			| MAX				|
| 1	   |0				|1				|PWM, Phase Correct					|0xFF	|TOP   				| BOTTOM			|
| 2	   |1				|0				|CTC								|#OCR0	|Immediate			|	MAX				|
| 3	   |1				|1				|Fast PWM							|0xFF	|BOTTOM				| MAX				|
|<b>Waveform Generation Mode Bit Description</b>|||||||
*/
///@{
#define WGM00	3
#define WGM01	6
///@}
/******************************************************************************************************/
/**
*@brief<h3> Clear Timer 0 Mode</h3>
*\details
*\arg This macro used to clear Timer 0 mode.
*\arg Anding the register #TCCR0 by the #CLR_TIMER0_MODE (0b1011 0111) will result clearing the two bits\n
	#WGM00 and #WGM01.
*/
#define CLR_TIMER0_MODE 0xB7
/******************************************************************************************************/
/**
*@name Timer/Counter0 Interrupts Enable
*\details
*\arg These bits enable and disable the interrupts of the counter and located in #TIMSK.
*/
///@{
#define	TOIE0	0/**< Bit 0 - TOIE0: Timer/Counter0 Overflow Interrupt Enable*/
#define OCIE0	1/**<Bit 1 - OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable*/
/**
*@brief <h3>Timer 0 interrupts choice</h3>
*\details
*\arg This enum contains the values for Timer0 interrupts.
*/
typedef enum 
{
	TIMER0_OVER_FLOW_INT,	/**<Timer/Counter0 Overflow Interrupt*/
	TIMER0_OUT_CMP_MATCH_INT/**<Timer/Counter0 Output Compare Match Interrupt*/
}TIMER0_interrupt_t;
///@}
/******************************************************************************************************/
/**
*@name Timer/Counter0 Interrupts Flags
*\details
*\arg These bits are flags for interrupts of the Timer 0 and located in #TIFR.
*/
///@{
#define	TOV0	0/**< Bit 0 - TOV0: Timer/Counter0 Overflow Flag*/
#define OCF0	1/**<Bit 1 - OCF0: Output Compare Flag */
///@}
/******************************************************************************************************/
/**
*@brief <h3>Timer 0 Modes</h3>
*\details
*\arg This enum contains the exact value for each mode that needed to be written in #TCCR0 register.
*\arg There is no need to check for each mode, just  (orring) | the #TCCR0 register with enum value will do the job.

*<h4>example</h4>
	*\arg \code TCCR0 |= FAST_PWM;  //this will make the timer work in fast PWM mode.\endcode

*<h4>enum representation in #TCCR0 register:</h4> 		
		|FOC0|WGM00|COM01|COM00|WGM01|CS02|CS01|CS00|
		|:--:|:---:|:---:|:---:|:---:|:--:|:--:|:--:|
		|x	 |0	   |x	 |x	   |0	 |x	  |x   |x	|
		|<b>Normal mode</b>||||||||

		|FOC0|WGM00|COM01|COM00|WGM01|CS02|CS01|CS00|
		|:--:|:---:|:---:|:---:|:---:|:--:|:--:|:--:|
		|x	 |0	   |x	 |x	   |1	 |x	  |x   |x	|
		|<b>PWM phase correct mode</b>||||||||

		|FOC0|WGM00|COM01|COM00|WGM01|CS02|CS01|CS00|
		|:--:|:---:|:---:|:---:|:---:|:--:|:--:|:--:|
		|x	 |1	   |x	 |x	   |0	 |x	  |x   |x	|
		|<b>clear timer on compare mode</b>||||||||

		|FOC0|WGM00|COM01|COM00|WGM01|CS02|CS01|CS00|
		|:--:|:---:|:---:|:---:|:---:|:--:|:--:|:--:|
		|x	 |1	   |x	 |x	   |1	 |x	  |x   |x	|
		|<b>fast PWM mode</b>||||||||

*/
typedef enum
{
	NORMAL = 0,				/**<enum value for Timer 0 Normal mode*/	
	PWM_PHASE_CORRECR=8,	/**<enum value for Timer 0 PWM phase correct mode*/
	CTC=64,					/**<enum value for Timer 0 clear timer on compare mode*/
	FAST_PWM=72				/**<enum value for Timer 0 fast PWM mode*/
}EN_Timer0_Mode_t;
/******************************************************************************************************/
/**
*@brief <h3>Timer 0 clock source</h3>
*\details
*\arg This enum contains the values for Timer0 clock source that needed to be written in #TCCR0 register.
*\arg There is no need to check for each source, just  (orring) | the #TCCR0 register with enum value shifted left by #CS00 will do the job.
*\arg After setting the clock source the timer will start automatically.
*<h4>example</h4>
*\arg \code TCCR0 |= clkI_No_DIVISON<<CS00;  //this will make the timer clock sorce as the system clock (No prescaling)\endcode
*/
typedef enum
{
	NO_CLOCK_SOURCE,			/**<No clock source\n (Timer/Counter stopped).				*/
	clkI_No_DIVISON,			/**<clkI/O/(No prescaling).									*/
	clkI_DIVISION_BY_8,			/**<clkI/O/8 (From prescaler).								*/
	clkI_DIVISION_BY_64, 		/**<clkI/O/64 (From prescaler).								*/
	clkI_DIVISION_BY_256,		/**<clkI/O/256 (From prescaler).							*/
	clkI_DIVISION_BY_1024,		/**<clkI/O/1024 (From prescaler).							*/
	EXTERNAL_CLOCK_FALLING_EDGE,/**<External clock source on T0 pin.\n Clock on falling edge.*/
	EXTERNAL_CLOCK_RISING_EDGE	/**< External clock source on T0 pin.\n Clock on rising edge.*/
}EN_Timer0_clkSource_t;
/******************************************************************************************************/
/**
*@brief <h3>Timer 0 errors</h3>
*@details
*\arg This enum contains the values for Timer 0 errors.
*/
typedef enum
{
	TIMER0_OK,		 /**<enum value shows that timer 0 parameters are correct*/
	TIMER0_WRONG_MODE,		 /**<enum value shows that timer 0 mode is wrong*/
	TIMER0_WRONG_CLK_SOURCE, /**<enum value shows that timer 0 clock source is wrong*/
	TIMER0_WRONG_INT/**<enum value shows that timer 0 interrupt number is wrong*/
}En_Timer0_Error_t;
/******************************************************************************************************/
/**
*@brief <h3>Timer0 interrupt enable</h3>
*@details
*\arg This function enables Timer 0 interrupt.

*@param[in] TIMER0_interrupt Timer 0 interrupt number.
*@param[out] void No output arguments.

*@retval TIMER0_OK	If timer 0 parameters are correct.
*@retval TIMER0_WRONG_INT	If timer 0 interrupt number is wrong.
*/
En_Timer0_Error_t Timer0_interruptEnable(TIMER0_interrupt_t Timer0_interrupt);
/******************************************************************************************************/
/**
*@brief <h3>Timer0 interrupt disable</h3>
*@details
*\arg This function disables Timer 0 interrupt.

*@param[in] TIMER0_interrupt Timer 0 interrupt number.
*@param[out] void No output arguments.

*@retval TIMER0_OK	If timer 0 parameters are correct.
*@retval TIMER0_WRONG_INT	If timer 0 interrupt number is wrong.
*/
En_Timer0_Error_t Timer0_interruptDiable(TIMER0_interrupt_t Timer0_interrupt);
/******************************************************************************************************/
/**
*@brief <h3>Timer0 init</h3>
*@details
*\arg This function initialize Timer 0.
*\arg It configures Timer 0 mode.
*\arg It configures Timer 0 clock source.

*@param[in]	Timer0_mode The mode for Timer 0 it can be selected from #EN_Timer0_Mode_t.
*@param[in] Timer0_clkSource The clock source for Timer 0 it can be selected from #EN_Timer0_clkSource_t.

*@retval TIMER0_OK 		  If timer 0 parameters are correct
*@retval WRONG_MODE		  If timer 0 mode is wrong
*@retval WRONG_CLK_SOURCE If timer 0 clock source is wrong

*/
En_Timer0_Error_t Timer0_init(EN_Timer0_Mode_t Timer0_mode,EN_Timer0_clkSource_t Timer0_clkSource);
/******************************************************************************************************/
/**
*@brief <h3>Timer0 start</h3>
*@details
*\arg This function starts Timer 0.
*@param[in] void No input arguments.
*@param[out] void No output arguments.
*@retval void	This function doesn't return anything.
*/
void Timer0_start(void);
/******************************************************************************************************/
/**
*@brief <h3>Timer0 stop</h3>
*@details
*\arg This function stops Timer 0.
*@param[in] void No input arguments.
*@param[out] void No output arguments.
*@retval void	This function doesn't return anything.
*/
void Timer0_stop(void);
/******************************************************************************************************/
/**
*@brief <h3>Timer0 reset</h3>
*@details
*\arg This function resets Timer 0 without stopping it.
*@param[in] void No input arguments.
*@param[out] void No output arguments.
*@retval void	This function doesn't return anything.
*/
void Timer0_reset(void);
/******************************************************************************************************/
/**
*@brief <h3>Timer 0 delay</h3>
*@details
*\arg This function generates a delay in mile seconds using Timer 0.
*@param[in] delay_ms Delay time in mile seconds.
*@param[out] void No output arguments.
*@retval void	This function doesn't return anything.
*/
void Timer0_delay_ms(uint32_t delay_ms);
/**@}*/
#endif /* TIMER_0_H_ */