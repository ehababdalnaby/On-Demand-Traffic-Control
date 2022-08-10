/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/10/2022 12:06:56 PM														*/
/*															File name: RegisterFile.h																*/
/****************************************************************************************************************************************************/

#ifndef REGISTERFILE_H_
#define REGISTERFILE_H_

/*
* if the DDRx is set to be output and we write High to the PORTx 
* this will activate the internal Pull up resistor.
*/

/*Port A Register*/                               
#define PORTA	(*((volatile uint8_t*)0x3B))  //1->high output				0->low output  
#define DDRA	(*((volatile uint8_t*)0x3A))  //1->to make it output		0->to make it input    
#define PINA	(*((volatile uint8_t*)0x39))  //this register to read a value from a pin 

/*Port B Register*/
#define PORTB	(*((volatile uint8_t*)0x38))
#define DDRB	(*((volatile uint8_t*)0x37))
#define PINB	(*((volatile uint8_t*)0x36)) 



#endif /* REGISTERFILE_H_ */