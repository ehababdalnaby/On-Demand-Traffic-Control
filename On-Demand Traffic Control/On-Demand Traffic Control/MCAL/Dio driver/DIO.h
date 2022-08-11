/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/10/2022 3:39:36 PM															*/
/*															File name: DIO.h																		*/
/****************************************************************************************************************************************************/

#ifndef DIO_H_
#define DIO_H_

#include "../../Service/ATmega32Port.h"
#include "../../Service/BitMath.h"
#include "../../Service/dataTypes.h"
#include "../../Service/RegisterFile.h"

/*
*DIO_pinInit function
*Description:
	*1.This function makes pin input or output.
	*2.it makes the pinNum Output by setting the pinNum in the DDRx (x:A,B,C or D) register.
	*3.it makes the pinNum Input by clearing the pinNum in the DDRx (x:A,B,C or D) register.
*Input arguments:
	*1.pinNum it represent the pin number (PA0 to PD7).
	*2.pinDirection it represent the pin direction it may be (Input or Output). 
*Output arguments:
	*1.no output arguments
*Return value:
	*1.It return WRONG_PIN_NUM if the pinNum is wrong.
	*2.It return WRONG_PIN_DIR if the pinDirection is wrong.
	*3.It return OK if the pinNum and the pinDirection are correct.
*/
EN_pinErro_t DIO_pinInit(EN_pinNum_t pinNum,EN_pinDirection_t pinDirection);
/*
*DIO_pinWrite function
*Description:
	*1.This function writes High or Low to the pin.
	*2.it writes High to the pinNum by setting the pinNum in the PORTx (x:A,B,C or D) register.
	*3.it writes Low to the pinNum by clearing the pinNum in the PORTx (x:A,B,C or D) register.
*Input arguments:
	*1.pinNum it represent the pin number (PA0 to PD7).
	*2.pinState it represent the pin state it may be (High or Low). 
*Output arguments:
	*1.no output arguments
*Return value:
	*1.It return WRONG_PIN_NUM if the pinNum is wrong.
	*2.It return WRONG_PIN_STATE if the pinState is wrong.
	*3.It return OK if the pinNum and the pinState are correct.
*/
EN_pinErro_t DIO_pinWrite(EN_pinNum_t pinNum,EN_pinState_t pinState);
/*
*DIO_pinToggle function
*Description:
	*1.This function toggles the state of the pin.
*Input arguments:
	*1.pinNum it represent the pin number (PA0 to PD7).
*Output arguments:
	*1.no output arguments
*Return value:
	*1.It return WRONG_PIN_NUM if the pinNum is wrong.
	*3.It return OK if the pinNum is correct.
*/
EN_pinErro_t DIO_pinToggle(EN_pinNum_t pinNum);
/*
*DIO_pinRead function
*Description:
	*1.This function reads the state of the pin.
	*2.It reads the bit relative to the pinNum in the register PINx (A,B,C or D).
*Input arguments:
	*1.pinNum it represent the pin number (PA0 to PD7).
*Output arguments:
	*1.pinState this variable holds the state of the pin (High or Low). 
*Return value:
	*1.It return WRONG_PIN_NUM if the pinNum is wrong.
	*2.It return OK if the pinNum is correct.
*/
EN_pinErro_t DIO_pinRead(EN_pinNum_t pinNum,EN_pinState_t *pinState);



#endif /* DIO_H_ */