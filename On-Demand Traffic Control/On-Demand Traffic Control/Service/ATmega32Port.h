/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/10/2022 3:49:55 PM															*/
/*															File name: ATmega32Port.h																*/
/****************************************************************************************************************************************************/

#ifndef ATMEGA32PORT_H_
#define ATMEGA32PORT_H_

typedef enum
{
	PA0,
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,
	PB0,
	PB1,
	PB2,
	PB3,
	PB4,
	PB5,
	PB6,
	PB7
}EN_pinNum;

#define PORTA_OFFSET	0
#define PORTB_OFFSET	8

typedef enum{Low,High}EN_pinState;
typedef enum{Input,Output}EN_pinMode;
	



#endif /* ATMEGA32PORT_H_ */