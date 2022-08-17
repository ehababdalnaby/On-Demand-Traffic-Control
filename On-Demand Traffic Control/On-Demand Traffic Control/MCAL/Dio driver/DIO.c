/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/10/2022 3:39:46 PM															*/
/*															File name: DIO.c																		*/
/****************************************************************************************************************************************************/

#include "DIO.h"
#include "../Interrupt/Interrupt.h"



EN_pinErro_t DIO_pinInit(EN_pinNum_t pinNum,EN_pinDirection_t pinDirection)
{
	EN_pinErro_t error = OK;
	//check if the pin is located in port A
	if (pinNum <= PA7)
	{
		if (pinDirection == Output)
		{
			setBit(DDRA,pinNum);
		}
		else if (pinDirection == Input)
		{
			clrBit(DDRA,pinNum);
		}
		else
		{
			error = WRONG_PIN_DIR;
		}
	}
	//check if the pin is located in port B
	else if (pinNum <= PB7)
	{
		pinNum-=PORTB_OFFSET;
		if (pinDirection == Output)
		{
			setBit(DDRB,pinNum);
		}
		else if (pinDirection == Input)
		{
			clrBit(DDRB,pinNum);
		}
		else
		{
			error = WRONG_PIN_DIR;
		}
	}
	//check if the pin is located in port C
	else if (pinNum <= PC7)
	{
		pinNum-=PORTC_OFFSET;
		if (pinDirection == Output)
		{
			setBit(DDRC,pinNum);
		}
		else if (pinDirection == Input)
		{
			clrBit(DDRC,pinNum);
		}
		else
		{
			error = WRONG_PIN_DIR;
		}
	}
	//check if the pin is located in port D
	else if (pinNum <= PD7)
	{
		pinNum-=PORTD_OFFSET;
		if (pinDirection == Output)
		{
			setBit(DDRD,pinNum);
		}
		else if (pinDirection == Input)
		{
			clrBit(DDRD,pinNum);
		}
		else
		{
			error = WRONG_PIN_DIR;
		}
	}
	//if the pinNum is wrong
	else
	{
		error = WRONG_PIN_NUM;
	}
	return error;
}
/********************************************************************************************************************************************************/
EN_pinErro_t DIO_pinWrite(EN_pinNum_t pinNum,EN_pinState_t pinState)
{
	EN_pinErro_t error = OK;
	//check if the pin is located in port A
	if (pinNum <= PA7)
	{
		if (pinState == High)
		{
			setBit(PORTA,pinNum);
		}
		else if (pinState == Low)
		{
			clrBit(PORTA,pinNum);
		}
		else
		{
			error = WRONG_PIN_STATE;
		}
	}
	//check if the pin is located in port B
	else if (pinNum <= PB7)
	{
		pinNum-=PORTB_OFFSET;
		if (pinState == High)
		{
			setBit(PORTB,pinNum);
		}
		else if (pinState == Low)
		{
			clrBit(PORTB,pinNum);
		}
		else
		{
			error = WRONG_PIN_STATE;
		}
	}
	//check if the pin is located in port C
	else if (pinNum <= PC7)
	{
		if (pinState == High)
		{
			setBit(PORTC,pinNum);
		}
		else if (pinState == Low)
		{
			clrBit(PORTC,pinNum);
		}
		else
		{
			error = WRONG_PIN_STATE;
		}
	}
	//check if the pin is located in port D
	else if (pinNum <= PD7)
	{
		if (pinState == High)
		{
			setBit(PORTD,pinNum);
		}
		else if (pinState == Low)
		{
			clrBit(PORTD,pinNum);
		}
		else
		{
			error = WRONG_PIN_STATE;
		}
	}
	//if the pinNum is wrong
	else
	{
		error = WRONG_PIN_NUM;
	}
	return error;
}
/********************************************************************************************************************************************************/
EN_pinErro_t DIO_pinRead(EN_pinNum_t pinNum,EN_pinState_t *pinState)
{
	EN_pinErro_t error = OK;
	//check if the pin is located in port A
	if (pinNum <= PA7)
	{
		*pinState = getBit(PINA,pinNum);
	}
	//check if the pin is located in port B
	else if (pinNum <= PB7)
	{
		pinNum-=PORTB_OFFSET;
		*pinState = getBit(PINB,pinNum);
	}
	//check if the pin is located in port C
	else if (pinNum <= PC7)
	{
		*pinState = getBit(PINC,pinNum);
	}
	//check if the pin is located in port D
	else if (pinNum <= PD7)
	{
		*pinState = getBit(PIND,pinNum);
	}
	//if the pinNum is wrong
	else
	{
		error = WRONG_PIN_NUM;
	}
	return error;
}
/********************************************************************************************************************************************************/
EN_pinErro_t DIO_pinToggle(EN_pinNum_t pinNum)
{
	EN_pinErro_t error = OK;
	//check if the pin is located in port A
	if (pinNum <= PA7)
	{
		toggleBit(PORTA,pinNum);
	}
	//check if the pin is located in port B
	else if (pinNum <= PB7)
	{
		pinNum-=PORTB_OFFSET;
		toggleBit(PORTB,pinNum);
	}
	//check if the pin is located in port C
	else if (pinNum <= PC7)
	{
		toggleBit(PORTC,pinNum);
	}
	//check if the pin is located in port D
	else if (pinNum <= PD7)
	{
		toggleBit(PORTD,pinNum);
	}
	//if the pinNum is wrong
	else
	{
		error = WRONG_PIN_NUM;
	}
	return error;
}
/********************************************************************************************************************************************************/
