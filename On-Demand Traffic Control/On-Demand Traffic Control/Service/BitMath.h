/**************************************************************************************************************************************************//**
															Author	 : Ehab Omara																	
															Date	 : 8/10/2022 12:46:40 PM														
															File name: BitMath.h																	
****************************************************************************************************************************************************/

#ifndef BITMATH_H_
#define BITMATH_H_

/**
*\defgroup bit_math Bit math
*\ingroup Service
*\details This contains all the bit math macros that manipulates the registers values.
*@{
*/

/**
*@brief this Macro writes 1 to the bit.
*@details
	*#setBit function
	*\arg this function takes register (reg) and bit number (bitNum).
	*\arg it make the required bit in the register High(1).
	*@param[in] reg this is register that needed to be changed.
	*@param[in] bitNum this is bit number that needed to be written to 1 in the register. 
*/
#define setBit(reg,bitNum)	reg |= (1<<bitNum)
/**
*@brief this Macro clear the bit.
*@details
	*#clrBit function
	*\arg this function takes register (reg) and bit number (bitNum).
	*\arg it make the required bit in the register Low(0).
	
	*@param[in] reg this is register that needed to be changed.
	*@param[in] bitNum this is bit number that needed to be written to 0 in the register.
*/
#define clrBit(reg,bitNum)	reg &= (~(1<<bitNum))
/**
*@brief This Macro toggle the bit logic.
*@details 
	*#togBit function
	*\arg this function takes register (reg) and bit number (bitNum).
	*\arg it toggle the state of the required bit in the register.
	*\arg if the required bit is Low(0) it makes it High(1).
	*\arg if the required bit is High(1) it makes it Low(0).
	
	*@param[in] reg this is register that needed to be changed.
	*@param[in] bitNum this is bit number that needed to be changed in the register.
*/
#define toggleBit(reg,bitNum)	reg ^= (1<<bitNum)
/**
*@brief This Macro read this bit value.
*@details
	*#getBit function
	*\arg this function takes register (reg) and bit number (bitNum).
	*\arg it returns the state of the required bit in the register.
	*\arg if the required bit is Low(0) it will return 0.
	*\arg if the required bit is High(1) it will return 1.
	*@param[in] reg This is register where it reads the value from it.
	*@param[in] bitNum This is the bit number that needed to be read.
*/
#define getBit(reg,bitNum)				((reg>>bitNum)	&	0x01)
/**@}*/


#endif /* BITMATH_H_ */