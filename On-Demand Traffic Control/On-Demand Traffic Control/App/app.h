/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/10/2022 12:03:55 PM														*/
/*															File name: app.h																		*/
/****************************************************************************************************************************************************/

#ifndef APP_H_
#define APP_H_
#include "../Service/ATmega32Port.h"
#include "../Service/dataTypes.h"
/**
*@defgroup App Application layer
*\details
*\arg This layer contains all the function to control the flow of the system.
*@{
*/
/**
*@name Cars LEDS Macros
*@brief These macros represent the pins which cars leds connected to.
*
*/
///@{
#define CARS_GREEN_LED	PA0	/**<This is a cars green led pin*/
#define CARS_YELOW_LED	PA1	/**<This is a cars yellow led pin*/
#define CARS_RED_LED	PA2	/**<This is a cars red led pin*/
///@}

/**
*@name Pedestrians LEDS Macros
*@brief These macros represent the pins which pedestrians leds connected to.
*
*/
///@{
#define PEDESTRIANS_GREEN_LED	PB0	/**<This is a pedestrians green led pin*/
#define PEDESTRIANS_YELOW_LED	PB1	/**<This is a pedestrians yellow led pin*/
#define PEDESTRIANS_RED_LED		PB2	/**<This is a pedestrians red led pin*/
///@}

/**
*@brief This enum contains the values for each state of the system.
*/
typedef enum
{
	NORMAL_GREEN,				/**<This enum value is for normal green state*/
	NORMAL_YELLOW_AFTER_GREEN,	/**<This enum value is for normal yellow state after green finished*/
	NORMAL_RED,					/**<This enum value is for normal state*/
	NORMAL_YELLOW_AFTER_RED,	/**<This enum value is for normal yellow state after red finished*/
	BUTTON_PRESSED_AT_GREEN,	/**<This enum value is for the button if it pressed when the system state is green*/
	BUTTON_PRESSED_AT_RED,		/**<This enum value is for the button if it pressed when the system state is red*/
	BUTTON_PRESSED_AT_YELLOW,	/**<This enum value is for the button if it pressed when the system state is yellow*/	
}EN_TrafficStates_t;

/**
*@brief app_start this function used to initialize the MCU for the application
*\details
*\arg 1.It initialize cars and pedestrians leds as output.
*\arg 2.It initialize external interrupt 0 (#INT0) to trigger at falling edge.
*\arg 3.It initialize Timer 0 as normal mode with prescaler 1024.
*@param[in] None this function doesn't take any input parameters.
*@param[out] None this function doesn't take any output parameters.
*@retval None This function doesn't return anything.
*/
void app_start(void);

/**
*\@brief trafficLightOperation
*\details 
*\arg This function used as a main API for the system.
*\arg It is used to switch between the system states and decide which state will run.
*@param[in] None this function doesn't take any input parameters.
*@param[out] None this function doesn't take any output parameters.
*@retval None This function doesn't return anything.
*/
void trafficLightOperation(void);


/**
*@name Cars led control function
*\details These function controls the leds of the cars.
*\It is used in normal mode states.
*@param[in] None this function doesn't take any input parameters.
*@param[out] None this function doesn't take any output parameters.
*@retval None This function doesn't return anything.
*/
///@{
/**
*@brief carsGreenState
*\details This function responsible for making the cars green led on for 5 sec.
*/
void carsGreenState(void);
/**
*@brief carsYellowState
*\details This function responsible for making the cars yellow led to blink for 5 sec.
*@param[in] None this function doesn't take any input parameters.
*@param[out] None this function doesn't take any output parameters.
*@retval None This function doesn't return anything.
*/
void carsYellowState(void);
/**
*@brief carsRedState
*\details This function responsible for making the cars red led on for 5 sec.
*@param[in] None this function doesn't take any input parameters.
*@param[out] None this function doesn't take any output parameters.
*@retval None This function doesn't return anything.
*/
void carsRedState(void);
///@}

/**
*@name Pedestrians led control function
*\details These function controls the leds of the pedestrians.
*\t is used in pedestrians mode states.
*@param[in] None this function doesn't take any input parameters.
*@param[out] None this function doesn't take any output parameters.
*@retval None This function doesn't return anything.
*/
///@{
/**
*@brief pedestriansGreenState
*\details 
*\arg This function responsible for making the cars red led on and pedestrians green led on for 5 sec. 
*\arg This function responsible for making the cars red led off and pedestrians red led off for 5 sec.
*@param[in] None this function doesn't take any input parameters.
*@param[out] None this function doesn't take any output parameters.
*@retval None This function doesn't return anything.
*/	
void pedestriansGreenState(void);
/**
*@brief pedestriansYellowState
*\details
*\arg This function responsible for making the cars yellow  and pedestrians yellow led blink for 5 sec.
*@param[in] None this function doesn't take any input parameters.
*@param[out] None this function doesn't take any output parameters.
*@retval None This function doesn't return anything.
*/
void pedestriansYellowState(void);
/**
*@brief pedestriansRedState
*\details
*\arg This function responsible for making the pedestrians red led on and cars green led on for 5 sec.
*\arg This function responsible for making the cars red led off and pedestrians green led off for 5 sec.
*@param[in] None this function doesn't take any input parameters.
*@param[out] None this function doesn't take any output parameters.
*@retval None This function doesn't return anything.
*/
void pedestriansRedState(void);
///@}
/**@}*/
#endif /* APP_H_ */