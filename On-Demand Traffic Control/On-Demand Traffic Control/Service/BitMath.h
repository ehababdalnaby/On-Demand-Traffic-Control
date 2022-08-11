/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/10/2022 12:46:40 PM														*/
/*															File name: BitMath.h																	*/
/****************************************************************************************************************************************************/

#ifndef BITMATH_H_
#define BITMATH_H_

/*
*setBit function
*1.this function takes register (reg) and bit number (bitNum).
*2.it make the required bit in the register High(1).
*/
#define setBit(reg,bitNum)	reg |= (1<<bitNum)
/*
*clrBit function
*1.this function takes register (reg) and bit number (bitNum).
*2.it make the required bit in the register Low(0).
*/
#define clrBit(reg,bitNum)	reg &= (~(1<<bitNum))
/*
*togBit function
*1.this function takes register (reg) and bit number (bitNum).
*2.it toggle the state of the required bit in the register.
*3.if the required bit is Low(0) it makes it High(1).
*4.if the required bit is High(1) it makes it Low(0).
*/
#define toggleBit(reg,bitNum)	reg ^= (1<<bitNum)
/*
*getBit function
*1.this function takes register (reg) and bit number (bitNum).
*2.it returns the state of the required bit in the register.
*3.if the required bit is Low(0) it will return 0.
*4.if the required bit is High(1) it will return 1.
*/
#define getBit(reg,bitNum)				((reg>>bitNum)	&	0x01)



#endif /* BITMATH_H_ */