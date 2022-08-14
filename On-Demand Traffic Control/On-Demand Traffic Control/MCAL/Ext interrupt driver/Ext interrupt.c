/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/13/2022 4:40:08 AM															*/
/*															File name: Ext interrupt.c																*/
/****************************************************************************************************************************************************/


#include "Ext interrupt.h"
EN_interruptError_t Ext_interruptInit(EN_interruptNum_t interruptNum,EN_interruptSenseControl_t interruptSenseControl)
{
	EN_interruptError_t interruptError = INT_OK;
	if (interruptNum == INT0)
	{
		//check if the value of the interruptSenseControl is correct
		if (interruptSenseControl >=  LOW_LEVEL &&interruptSenseControl <= RISING_EDGE)
		{
			//enable INT0
			setBit(GICR,INT0);
			//clearing interruptSenseControl old value
			MCUCR&=(~(ISC00<<0x03));
			//setting interruptSenseControl new value
			MCUCR|=interruptSenseControl<<ISC00;
			//set INT0 pin as input
			clrBit(DDRD,INT0_PIN);
		}
		else
		{
			interruptError = WRONG_SENSE_CONTROL;
		}
	}
	else if (interruptNum == INT1)
	{
		
		//check if the value of the interruptSenseControl is correct
		if (interruptSenseControl >=  LOW_LEVEL &&interruptSenseControl <= RISING_EDGE)
		{
			//enable INT1
			setBit(GICR,INT1);
			//clearing interruptSenseControl old value
			MCUCR&=(~(0x03<<ISC10));
			//setting interruptSenseControl new value
			MCUCR|=interruptSenseControl<<ISC10;
			//set INT1 pin as input
			clrBit(DDRD,INT1_PIN);
		}
		else
		{
			interruptError = WRONG_SENSE_CONTROL;
		}
	}
	else if (interruptNum == INT2)
	{
		
		//check if the value of the interruptSenseControl is correct
		if (interruptSenseControl ==  FALLING_EDGE )
		{
			//enable INT1
			setBit(GICR,INT2);
			clrBit(MCUCSR,ISC2);
			//set INT2 pin as input
			clrBit(DDRB,INT2_PIN);
		}
		else if(interruptSenseControl == RISING_EDGE)
		{
			//enable INT1
			setBit(GICR,INT2);
			setBit(MCUCSR,ISC2);
			//set INT2 pin as input
			clrBit(DDRB,INT2_PIN);
		}
		else
		{
			interruptError = WRONG_SENSE_CONTROL;
		}
	}
	else
	{
		interruptError = WRONG_INT_NUM;
	}
	if (interruptError == INT_OK)
	{
		//enable global interrupt
		sei();
	}
	return interruptError;
}


