/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/12/2022 9:42:19 PM															*/
/*															File name: LED.c																		*/
/****************************************************************************************************************************************************/
#include "LED.h"



EN_pinErro_t ledInit(EN_pinNum_t ledPin)
{
	return DIO_pinInit(ledPin,Output);
}
/*********************************************************************************/
EN_pinErro_t ledOn(EN_pinNum_t ledPin)
{
	return DIO_pinWrite(ledPin,High);
}
/*********************************************************************************/
EN_pinErro_t ledOff(EN_pinNum_t ledPin)
{
	return DIO_pinWrite(ledPin,Low);
}
/*********************************************************************************/
EN_pinNum_t ledToggle(EN_pinNum_t ledPin)
{
	return DIO_pinToggle(ledPin);
}