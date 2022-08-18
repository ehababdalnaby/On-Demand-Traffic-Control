/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/17/2022 8:27:24 PM																		*/
/*															File name: IncFile1.h																*/
/****************************************************************************************************************************************************/

#ifndef INCFILE1_H_
#define INCFILE1_H_
/**
*@page SYTEM_DESIGN System static architecture
@section SYSTEM_DESCRIPTION	system description
*\arg This system consist of two modes normal mode and pedestrians mode.
*\arg It controls two traffic lights one for cars and one for pedestrians.
*\arg It has button if the button pressed the system will change from normal mode to pedestrians mode.
*@subsection HW Hardware
*\arg 6 LEDs (3 for cars and 3 for pedestrians).
*\arg 1 push button.
*\arg ATmega32 MCU.
@subsection SOFT Software & IDEs
*\arg Proteus (used for system simulation).
*\arg Microchip studio (used for development and debugging).
@section SYSTEM_DESIGN system design
*@image html static_designe.png
*@image latex static_designe.png
*\arg This system consist of 4 layers (@ref MCAL "MCAL layer",@ref ECUAL "ECUAL layer",@ref App "Application layer",@ref Service "Service layer")
*@section STATE_MACHINE	State machine
*\arg This state machine describes the flow of the system
*\arg It consist of 7 main states \n
* #NORMAL_GREEN \n
* #NORMAL_YELLOW_AFTER_GREEN \n
* #NORMAL_RED \n
* #NORMAL_YELLOW_AFTER_RED \n
* #BUTTON_PRESSED_AT_GREEN \n
* #BUTTON_PRESSED_AT_YELLOW \n
* #BUTTON_PRESSED_AT_RED \n
*@image html statemachine.png width=650cm height=700cm
*@image latex statemachine.png
*/




#endif /* INCFILE1_H_ */