/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/11/2022 8:24:25 PM															*/
/*															File name: Button.h																		*/
/****************************************************************************************************************************************************/

#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../Service/ATmega32Port.h"
#include "../../MCAL/Dio driver/DIO.h"


/**
*\defgroup ECUAL ECUAL layer
*\details This layer contains all the drivers for the external devices that connected to the MCU.
*/

/**
*\defgroup Button_driver Button driver
*\ingroup ECUAL
*\details This driver contains all the function that controls the buttons connected to the MCU.
*@{
*/
/**
*@brief initialize the button pin.
*\details
	*#buttonInit function:
	*\arg This function makes the button pin as Input.
	*@param[in] buttonPin it is the pin which the button is connected to,it may be (PA0 to PD7). 
	*@param[out] none no output arguments

	*\retval WRONG_PIN_NUM if the pinNum is wrong.
	*\retval OK if the pinNum is correct.
*/
EN_pinErro_t buttonInit(EN_pinNum_t buttonPin);
/***************************************************************************************************************/
/**
*@brief reads the  value of the button.
*@details
	*#buttonRead function:
	*\arg It reads the value of the connected pin to the button.
	*\arg It store the value in the pinState pointer.
	*@param[in] buttonPin it is the pin which the button is connected to,it may be (PA0 to PD7).
	*@param[out] pinState the function store the value of the button in that pointer.
	
	*\retval WRONG_PIN_NUM if the pinNum is wrong.
	*\retval OK if the pinNum is correct. 
*/
EN_pinErro_t buttonRead(EN_pinNum_t buttonPin,EN_pinState_t *pinState);
/**@}*/
#endif /* BUTTON_H_ */