/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/12/2022 9:42:50 PM															*/
/*															File name: LED.h																		*/
/****************************************************************************************************************************************************/

#ifndef LED_H_
#define LED_H_
/**
*\defgroup LED LED driver
*\ingroup MCAL
*\details This driver contains all the function that controls the LEDs connected to the MCU.
*@{
*/
EN_pinErro_t ledInit(EN_pinNum_t ledPin);

EN_pinErro_t ledOn(EN_pinNum_t pinNum);

EN_pinErro_t ledOff(EN_pinNum_t pinNum);

EN_pinNum_t ledToggle(EN_pinNum_t pinNum);




#endif /* LED_H_ */