
/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/11/2022 8:25:13 PM															*/
/*															File name: Button.c																		*/
/****************************************************************************************************************************************************/

#include "../../Service/ATmega32Port.h"
#include "Button.h"

EN_pinErro_t buttonInit(EN_pinNum_t buttonPin)
{
	return DIO_pinInit(buttonPin,Input);
}
/*****************************************************************/
EN_pinErro_t buttonRead(EN_pinNum_t buttonPin,EN_pinState_t *pinState)
{
	return DIO_pinRead(buttonPin,pinState);
}