/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/10/2022 3:49:55 PM															*/
/*															File name: ATmega32Port.h																*/
/****************************************************************************************************************************************************/

#ifndef ATMEGA32PORT_H_
#define ATMEGA32PORT_H_


/**
*\defgroup MCU_port MCU ports
*\ingroup Service
*\details This contains all the definition for MCU pins, input and output pins values and pins errors.
*@{
*/
/**
*\enum EN_pinNum_t
*@details
*This enum contains the value for all pins of the MCU of the four ports (PORTA,PORTB,PORTC,PORTD)
*/
typedef enum
{
	/*PORTA pins*/
	PA0,/**<enum value for PORTA pin 0*/
	PA1,/**<enum value for PORTA pin 1*/
	PA2,/**<enum value for PORTA pin 2*/
	PA3,/**<enum value for PORTA pin 3*/
	PA4,/**<enum value for PORTA pin 4*/
	PA5,/**<enum value for PORTA pin 5*/
	PA6,/**<enum value for PORTA pin 6*/
	PA7,/**<enum value for PORTA pin 7*/
	/*PORTB pins*/
	PB0,/**<enum value for PORTB pin 0*/
	PB1,/**<enum value for PORTB pin 1*/
	PB2,/**<enum value for PORTB pin 2*/
	PB3,/**<enum value for PORTB pin 3*/
	PB4,/**<enum value for PORTB pin 4*/
	PB5,/**<enum value for PORTB pin 5*/
	PB6,/**<enum value for PORTB pin 6*/
	PB7,/**<enum value for PORTB pin 7*/
	/*PORTC pins*/
	PC0,/**<enum value for PORTC pin 0*/
	PC1,/**<enum value for PORTC pin 1*/
	PC2,/**<enum value for PORTC pin 2*/
	PC3,/**<enum value for PORTC pin 3*/
	PC4,/**<enum value for PORTC pin 4*/
	PC5,/**<enum value for PORTC pin 5*/
	PC6,/**<enum value for PORTC pin 6*/
	PC7,/**<enum value for PORTC pin 7*/
	/*PORTD pins*/
	PD0,/**<enum value for PORTD pin 0*/
	PD1,/**<enum value for PORTD pin 1*/
	PD2,/**<enum value for PORTD pin 2*/
	PD3,/**<enum value for PORTD pin 3*/
	PD4,/**<enum value for PORTD pin 4*/
	PD5,/**<enum value for PORTD pin 5*/
	PD6,/**<enum value for PORTD pin 6*/
	PD7 /**<enum value for PORTD pin 7*/
}EN_pinNum_t;

#define PORTA_OFFSET	0  /**<This macro defines the start of the PORTA pins*/
#define PORTB_OFFSET	8  /**<This macro defines the start of the PORTB pins*/
#define PORTC_OFFSET	16 /**<This macro defines the start of the PORTC pins*/
#define PORTD_OFFSET	24 /**<This macro defines the start of the PORTD pins*/

typedef enum
{
	Low,/**<enum value for Low output*/
	High/**<enum value for high output*/
}EN_pinState_t;
typedef enum
{
	Input, /**<enum value for input direction*/
	Output /**<enum value for output direction*/
}EN_pinDirection_t;
typedef enum
{
	OK,			   /**<enum value that defines that the pin parameters are ok*/
	WRONG_PIN_NUM, /**<enum value that defines that the pin number is wrong*/
	WRONG_PIN_DIR, /**<enum value that defines that the pin direction is wrong*/
	WRONG_PIN_STATE/**<enum value that defines that the pin state is wrong*/
}EN_pinErro_t;
/**@}*/


#endif /* ATMEGA32PORT_H_ */