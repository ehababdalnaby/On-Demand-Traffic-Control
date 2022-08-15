/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/13/2022 4:39:49 AM															*/
/*															File name: Ext interrupt.h																*/
/****************************************************************************************************************************************************/

#ifndef EXT_INTERRUPT_H_
#define EXT_INTERRUPT_H_

#include "../../Service/ATmega32Port.h"
#include "../../Service/RegisterFile.h"
#include "../Interrupt/Interrupt.h"
#include "../../Service/BitMath.h"

/**
*\defgroup EXT_interrupts ATMEGA32 external interrupts driver
*\ingroup interrupts
*@brief External interrupts driver.
*@{ 
*/


/** @name External interrupts pins
 *  @details
 *	\arg These are the pins which connected to each interrupt.
 *	\arg It should be configured as #Input.
 */
///@{
#define INT0_PIN (PD2 - PORTD_OFFSET) /**<This Pin connected to INT0 interrupt*/
#define INT1_PIN (PD3 - PORTD_OFFSET) /**<This Pin connected to INT1 interrupt*/
#define INT2_PIN (PB2 - PORTB_OFFSET) /**<This Pin connected to INT2 interrupt*/
///@}

/** @name INT0 sense control
 *  @details
 *	\arg These two bits #ISC00 and #ISC01 which located in #MCUCR register control the #INT0 sense control.
 *	ISC01  |ISC00  | Description											   |
 *	:----: |:----: | :--------------------------------------------------------:|
 *	0	   |0	   | The low level of INT0 generates an interrupt request.	   |
 *	0	   |1	   | Any logical change on INT0 generates an interrupt request.|
 *	1	   |0	   |  The falling edge of INT0 generates an interrupt request. |
 *	1	   |1	   | The rising edge of INT0 generates an interrupt request.   | 
 *	
 */
///@{
#define ISC00 0	/**<Interrupt Sense Control 0 Bit 0*/
#define ISC01 1 /**<Interrupt Sense Control 0 Bit 1*/
///@}
/********************************************************************************************************************************/

/** @name INT1 sense control
 *  @details
 *	\arg These two bits #ISC10 and #ISC11 which located in #MCUCR register control the #INT1 sense control.
 *	ISC11  |ISC10  | Description											   |
 *	:----: |:----: | :--------------------------------------------------------:|
 *	0	   |0	   | The low level of INT1 generates an interrupt request.	   |
 *	0	   |1	   | Any logical change on INT1 generates an interrupt request.|
 *	1	   |0	   |  The falling edge of INT1 generates an interrupt request. |
 *	1	   |1	   | The rising edge of INT1 generates an interrupt request.   | 
 *	
 */
///@{
#define ISC10 2	/**<Interrupt Sense Control 1 Bit 0*/
#define ISC11 3	/**<Interrupt Sense Control 1 Bit 1*/
///@}

/********************************************************************************************************************************/

/** @name INT2 sense control
 *  @details
 *	\arg This bit #ISC2 which located in #MCUCSR register control the #INT2 sense control.
 *	ISC2   | Description
 *	:----: | :-------------:
 *	0	   | The falling edge on INT2 activates the interrupt request.
 *	1	   | The rising edge on INT2 activates the interrupt request.
 */
///@{
#define ISC2 6	/**<Interrupt Sense Control 2 Bit 6*/
///@}
/********************************************************************************************************************************/

/**
*@brief External interrupt number.
*@details
*\arg This enum contains the bit number for each interrupt in #GICR register. 
*\arg Setting these bits will enables the interrupts.
*\arg Clearing these bits will disables the interrupts.
*/
typedef enum
{
	INT2 = 5,/**<enum value for external interrupt 2*/
	INT0,	 /**<enum value for external interrupt 0*/
	INT1	 /**<enum value for external interrupt 1*/
}EN_interruptNum_t;
/********************************************************************************************************************************/
/**
*@brief External interrupt sense control.
*@details
*\arg This enum contains the values for interrupt sense control.
*\arg each value represent the exact value that should be written in the #MCUCR register this for #INT0 and #INT1 and #MCUCSR register for INT2.
*\note
*\arg #INT2 has just rising and falling edge sense control. 
*/
typedef enum
{
	LOW_LEVEL,			/**<The low level generates an interrupt request.*/
	ANY_LOGICAL_CHANGE,	/**<Any logical change generates an interrupt request.*/
	FALLING_EDGE,		/**<The falling edge generates an interrupt request*/
	RISING_EDGE			/**<The rising edge generates an interrupt request*/
}EN_interruptSenseControl_t;
/********************************************************************************************************************************/
/**
*@brief External interrupt errors.
*@details
*\arg This enum contains the values for interrupt errors.
*/
typedef enum
{
	INT_OK,				/**<enum value shows that INTx parameters is right.*/
	WRONG_INT_NUM,		/**<enum value shows that INTx number is wrong.*/
	WRONG_SENSE_CONTROL	/**<enum value shows that INTx sense control is wrong.*/	
}EN_interruptError_t;
/********************************************************************************************************************************/
/**
*@brief External interrupt init.
*@details 
	*\arg This function configures INTx sense control.
	*\arg This function enables INTx.
	*@param[in] interruptNum This is the interrupt number that needed to be enabled.
	*@param[in] interruptSenseControl	This is the value of the interrupt sense control which the interrupt will activated at it.
	
	*@retval INT_OK If interruptNum and interruptSenseControl are corrects.
	*@retval WRONG_INT_NUM If interruptNum is wrong.
	*@retval WRONG_SENSE_CONTROL If interruptSenseControl is wrong. 
*/
EN_interruptError_t Ext_interruptInit(EN_interruptNum_t interruptNum,EN_interruptSenseControl_t interruptSenseControl);
/**@}*/
#endif /* EXT_INTERRUPT_H_ */