/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/13/2022 1:08:16 AM															*/
/*															File name: Interrupt.h																	*/
/****************************************************************************************************************************************************/

#ifndef INTERRUPT_H_
#define INTERRUPT_H_
/**
*\defgroup interrupts Interrupts driver
*\ingroup MCAL
*/

/**
*\defgroup avr_interrupts ATMEGA32 interrupts definitions
*\ingroup interrupts
*@brief Interrupts request handlers
*\details 
	*<h1>This section contains:</h1>
	*\arg Macros for Interrupts request handlers in ATmega32.
	*\arg Macros for enabling and disabling global interrupt.
	*\arg ISR Macro which defines interrupt service routine function.
*@{ 
*/

/** 
	*\details
	*\arg Disables all interrupts by clearing the global interrupt mask.
	*\arg This function actually compiles into a single line of assembly, so there is no function
	call overhead.
	*\arg However, the macro also implies a <strong><i>memory barrier</i></strong>
	which can cause additional loss of optimization.

*/
# define sei()  __asm__ __volatile__ ("sei" ::: "memory")

/** 
    *\details
    *\arg Disables all interrupts by clearing the global interrupt mask. 
	*\arg This function actually compiles into a single line of assembly, so there is no function
    call overhead.  
	*\arg However, the macro also implies a <strong><i>memory barrier</i></strong>
    which can cause additional loss of optimization.

*/
# define cli()  __asm__ __volatile__ ("cli" ::: "memory")

#define EXT_INT0		__vector_1 /**<This Macro defines IRQ0 Handler						*/
#define EXT_INT1		__vector_2 /**<This Macro defines IRQ1 Handler						*/
#define EXT_INT2		__vector_3 /**<This Macro defines IRQ2 Handler						*/
#define TIM2_COMP		__vector_4 /**<This Macro defines Timer2 Compare Handler			*/
#define TIM2_OVF		__vector_5 /**<This Macro defines Timer2 Overflow Handler			*/
#define TIM1_CAPT		__vector_6 /**<This Macro defines Timer1 Capture Handler			*/
#define TIM1_COMPA		__vector_7 /**<This Macro defines Timer1 CompareA Handler			*/
#define TIM1_COMPB		__vector_8 /**<This Macro defines Timer1 CompareB Handler			*/
#define TIM1_OVF		__vector_9 /**<This Macro defines Timer1 Overflow Handler			*/
#define TIM0_COMP		__vector_10/**<This Macro defines Timer0 Compare Handler			*/
#define TIM0_OVF		__vector_11/**<This Macro defines Timer0 Overflow Handler			*/
#define SPI_STC			__vector_12/**<This Macro defines SPI Transfer Complete Handler		*/
#define USART_RXC		__vector_13/**<This Macro defines USART RX Complete Handler			*/
#define USART_UDRE		__vector_14/**<This Macro defines UDR Empty Handler					*/
#define USART_TXC		__vector_15/**<This Macro defines USART TX Complete Handler			*/
#define ADC				__vector_16/**<This Macro defines ADC Conversion Complete Handler	*/
#define EE_RDY			__vector_17/**<This Macro defines EEPROM Ready Handler				*/
#define ANA_COMP		__vector_18/**<This Macro defines Analog Comparator Handler			*/
#define TWI				__vector_19/**<This Macro defines Two-wire Serial Interface Handler */
#define SPM_RDY			__vector_20/**<This Macro defines Store Program Memory Ready Handler*/
/** 
*@brief interrupt service routine Macro.
*@details
    *\arg Introduces an interrupt handler function (interrupt service
    routine) that runs with global interrupts initially disabled
    by default with no attributes specified.

    *\pre \c vector must be one of the interrupt vector names that are
    valid for the particular MCU type.
*/
#define ISR(INT_VECT)	void INT_VECT(void)__attribute__((signal,used));\
						void INT_VECT(void)
/**@}*/

#endif /* INTERRUPT_H_ */