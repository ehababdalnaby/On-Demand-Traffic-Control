/*************************************************************************************************************************************************//**
*@file		DIO.h
*@author	: Ehab Omara																	
*@date		: 8/10/2022 3:39:36 PM																		
***************************************************************************************************************************************************/

#ifndef DIO_H_
#define DIO_H_

#include "../../Service/ATmega32Port.h"
#include "../../Service/BitMath.h"
#include "../../Service/dataTypes.h"
#include "../../Service/RegisterFile.h"
/**
*\defgroup MCAL MCAL layer
*\details This layer contains all the driver related to the MCU.
*/
/**
*\defgroup DIO DIO driver
*\ingroup MCAL
*\details This contains all the function needed to configure and manipulate the MCU ports.
*@{
*/
/**
*@brief Set the direction of the pin.
	\details
	*#DIO_pinInit
	*\arg This function makes pin input or output.
	*\arg it makes the pinNum Output by setting the pinNum in the DDRx (x:A,B,C or D) register.
	*\arg it makes the pinNum Input by clearing the pinNum in the DDRx (x:A,B,C or D) register.
	
	*@param[in] pinNum it represent the pin number (PA0 to PD7).
	*@param[in] pinDirection it represent the pin direction it may be (Input or Output). 
	*@param[out] none no output arguments

	*@retval WRONG_PIN_NUM if the pinNum is wrong.
	*@retval WRONG_PIN_DIR if the pinDirection is wrong.
	*@retval OK if the pinNum and the pinDirection are correct.
*/
EN_pinErro_t DIO_pinInit(EN_pinNum_t pinNum,EN_pinDirection_t pinDirection);
/**

*@brief This function writes High or Low on  the pin.

*@details
	*#DIO_pinWrite  
	*\arg it writes High to the pinNum by setting the pinNum in the PORTx (x:A,B,C or D) register.
	*\arg it writes Low to the pinNum by clearing the pinNum in the PORTx (x:A,B,C or D) register.

	*@param[in] pinNum it represent the pin number (\c PA0 to \c PD7).
	*@param[in] pinState it represent the pin state it may be (High or Low). 
	*@param[out] none no output arguments

	*@retval WRONG_PIN_NUM if the pinNum is wrong.
	*@retval WRONG_PIN_STATE if the pinState is wrong.
	*@retval OK if the pinNum and the pinState are correct.
*/
EN_pinErro_t DIO_pinWrite(EN_pinNum_t pinNum,EN_pinState_t pinState);
/**
*@brief This function toggles the state of the pin.
*@details
	*#DIO_pinToggle
	*\arg if the current state of the pin is High it will make it Low.
	*\arg if the current state of the pin is Low it will make it High.

	*@param[in] pinNum it represent the pin number (PA0 to PD7).
	*@param[out] none no output arguments

	*@retval WRONG_PIN_NUM if the pinNum is wrong.
	*@retval OK if the pinNum is correct.
*/
EN_pinErro_t DIO_pinToggle(EN_pinNum_t pinNum);
/**
*@brief This function reads the state of the pin.

*@details
	*#DIO_pinRead
	*\arg It reads the bit relative to the pinNum in the register PINx (A,B,C or D).

	*@param[in] pinNum it represent the pin number (PA0 to PD7).
	*@param[out] pinState this is a pointer to store the state of the pin (High or Low). 

	*@retval WRONG_PIN_NUM if the pinNum is wrong.
	*@retval OK if the pinNum is correct.
*/
EN_pinErro_t DIO_pinRead(EN_pinNum_t pinNum,EN_pinState_t *pinState);
/**@}*/


#endif /* DIO_H_ */