/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/10/2022 12:03:55 PM														*/
/*															File name: app.h																		*/
/****************************************************************************************************************************************************/

#ifndef APP_H_
#define APP_H_
#include "../Service/ATmega32Port.h"
#include "../Service/dataTypes.h"


#define CARS_GREEN_LED	PA0	
#define CARS_YELOW_LED	PA1
#define CARS_RED_LED	PA2


#define PEDESTRIANS_GREEN_LED	PB0
#define PEDESTRIANS_YELOW_LED	PB1
#define PEDESTRIANS_RED_LED		PB2	

typedef enum
{
	NORMAL_GREEN,
	NORMAL_YELLOW_AFTER_GREEN,
	NORMAL_RED,
	NORMAL_YELLOW_AFTER_RED,
	BUTTON_PRESSED_AT_GREEN,
	BUTTON_PRESSED_AT_RED,
	BUTTON_PRESSED_AT_YELLOW,	
}EN_TrafficStates_t;

void app_start(void);
void trafficLightOperation(void);


void carsGreenState(void);
void carsYellowState(void);
void carsRedState(void);

void pedestriansGreenState(void);
void pedestriansYellowState(void);
void pedestriansRedState(void);


#endif /* APP_H_ */