/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/10/2022 3:49:55 PM															*/
/*															File name: ATmega32Port.h																*/
/****************************************************************************************************************************************************/

#ifndef ATMEGA32PORT_H_
#define ATMEGA32PORT_H_

typedef enum
{
	/*PORTA pins*/
	PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7,
	/*PORTB pins*/
	PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7,
	/*PORTC pins*/
	PC0,PC1,PC2,PC3,PC4,PC5,PC6,PC7,
	/*PORTD pins*/
	PD0,PD1,PD2,PD3,PD4,PD5,PD6,PD7
}EN_pinNum_t;

#define PORTA_OFFSET	0
#define PORTB_OFFSET	8
#define PORTC_OFFSET	16
#define PORTD_OFFSET	24

typedef enum{Low,High}EN_pinState_t;
typedef enum{Input,Output}EN_pinDirection_t;
typedef enum{OK,WRONG_PIN_NUM,WRONG_PIN_DIR,WRONG_PIN_STATE}EN_pinErro_t;	



#endif /* ATMEGA32PORT_H_ */