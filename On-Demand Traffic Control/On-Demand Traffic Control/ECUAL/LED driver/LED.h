/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/12/2022 9:42:50 PM															*/
/*															File name: LED.h																		*/
/****************************************************************************************************************************************************/

#ifndef LED_H_
#define LED_H_

#include "../../Service/ATmega32Port.h"
#include "../../MCAL/Dio driver/DIO.h"

/**
*\defgroup LED LED driver
*\ingroup ECUAL
*\details This driver contains all the function that controls the LEDs connected to the MCU.
*@{
*/

/**
*@brief initialize the led pin.
*\details
	*#ledInit function:
	*\arg This function initialize the led pin as output.
	
	*@param[in] ledPin it is the pin which the led is connected to,it may be (PA0 to PD7).
	*@param[out] none no output arguments

	*\retval WRONG_PIN_NUM if the pinNum is wrong.
	*\retval OK if the pinNum is correct.
*/
EN_pinErro_t ledInit(EN_pinNum_t ledPin);
/*********************************************************************************/
/**
*@brief turn the led on.
*\details
	*#ledOn function:
	*\arg This function turns the led on by writing high to the pin.
	
	*@param[in] ledPin it is the pin which the led is connected to,it may be (PA0 to PD7).
	*@param[out] none no output arguments

	*\retval WRONG_PIN_NUM if the pinNum is wrong.
	*\retval OK if the pinNum is correct.
*/
EN_pinErro_t ledOn(EN_pinNum_t ledPin);
/*********************************************************************************/
/**
*@brief turn the led off.
*\details
	*#ledOff function:
	*\arg This function turns the led off by writing low to the pin.
	
	*@param[in] ledPin it is the pin which the led is connected to,it may be (PA0 to PD7).
	*@param[out] none no output arguments

	*\retval WRONG_PIN_NUM if the pinNum is wrong.
	*\retval OK if the pinNum is correct.
*/
EN_pinErro_t ledOff(EN_pinNum_t ledPin);
/*********************************************************************************/
/**
*@brief toggle the led state.
*\details
	*#ledToggle function:
	*\arg This function toggle the led state.
	*\arg It makes the led on if the led was off.
	*\arg It makes the led off if the led was on.
	
	*@param[in] ledPin it is the pin which the led is connected to,it may be (PA0 to PD7).
	*@param[out] none no output arguments

	*\retval WRONG_PIN_NUM if the pinNum is wrong.
	*\retval OK if the pinNum is correct.
*/
EN_pinNum_t ledToggle(EN_pinNum_t ledPin);
/**@}*/



#endif /* LED_H_ */