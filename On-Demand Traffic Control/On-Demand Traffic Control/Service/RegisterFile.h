/****************************************************************************************************************************************************/
/*															Author	 : Ehab Omara																	*/
/*															Date	 : 8/10/2022 12:06:56 PM														*/
/*															File name: RegisterFile.h																*/
/****************************************************************************************************************************************************/

#ifndef REGISTERFILE_H_
#define REGISTERFILE_H_

#include "dataTypes.h"
/*
* if the DDRx is set to be output and we write High to the PORTx 
* this will activate the internal Pull up resistor.
*/

/**
*\defgroup Service Service layer 
*\details This layer contains all the common services that the other layers need like data types, MCU registers, bit math and MCU ports.  
*/
/**
*\defgroup registers MCU Registers
*\ingroup Service
*\details This contains all the MCU registers definition and description for each register.
*/

/**
*\defgroup IO_registers  I/O registers
*\ingroup  registers
*\details This contains all I/O registers that controls the functionality of the MCU ports.
*@note x may be (A,B,C, or D) and n from 0 to 7.
*@details
*\arg Each port pin consists of three register bits: DDxn, PORTxn, and PINxn. The DDxn bits are accessed at the DDRx
I/O address, the PORTxn bits at the PORTx I/O address, and the PINxn bits at the PINx
I/O address.
*\arg The DDxn bit in the DDRx Register selects the direction of this pin. If DDxn is written
logic one, Pxn is configured as an output pin. If DDxn is written logic zero, Pxn is configured as an input pin.
*\arg If PORTxn is written logic one when the pin is configured as an input pin, the pull-up
resistor is activated. To switch the pull-up resistor off, PORTxn has to be written logic
zero or the pin has to be configured as an output pin. The port pins are tri-stated when a
reset condition becomes active, even if no clocks are running.
*\argIf PORTxn is written logic one when the pin is configured as an output pin, the port pin is
driven high (one). If PORTxn is written logic zero when the pin is configured as an output pin, the port pin is driven low (zero).
*/


/************************************************************* Port A registers ************************************************************/
/**
*\defgroup port_a Port A registers
*\ingroup IO_registers
*@{
*/
/**
*@brief Output register for port A
*@details
*\arg This register controls the output of the pin.
*\arg Setting the bit in this register will make the pin high.
*\arg Clearing the bit in this register will make the pin low
*\arg If the pin is configured as output through DDRx and we write high to PORTx register this will activate internal pull up resistor (x may be A,B,C or D). 
*/                               
#define PORTA	(*((volatile uint8_t*)0x3B))  //1->high output				0->low output  
/**
*@brief Direction register for port A
*@details
*\arg This register controls the direction of the pin.
*\arg Setting the bit in this register will make the pin output.
*\arg Clearing the bit in this register will make the pin input
*/
#define DDRA	(*((volatile uint8_t*)0x3A))  //1->to make it output		0->to make it input  
/**
*@brief Input register for port A
*@details
*\arg This register stores the input values of port A.
*\arg If the value is 1 then the applied voltage on this pin is high.
*\arg If the value is 0 then the applied voltage on this pin is low.
*/  
#define PINA	(*((volatile uint8_t*)0x39))  //this register to read a value from a pin 
/**@}*/


/************************************************************* Port B registers ************************************************************/
/**
*\defgroup port_b Port B registers
*\ingroup IO_registers
*@{
*/
/**
*@brief Output register for port B
*@details
*\arg This register controls the output of the pin.
*\arg Setting the bit in this register will make the pin high.
*\arg Clearing the bit in this register will make the pin low
*\arg If the pin is configured as output through DDRx and we write high to PORTx register this will activate internal pull up resistor (x may be A,B,C or D).
*/
#define PORTB	(*((volatile uint8_t*)0x38))
/**
*@brief Direction register for port B
*@details
*\arg This register controls the direction of the pin.
*\arg Setting the bit in this register will make the pin output.
*\arg Clearing the bit in this register will make the pin input
*/
#define DDRB	(*((volatile uint8_t*)0x37))
/**
*@brief Input register for port A
*@details
*\arg This register stores the input values of port B.
*\arg If the value is 1 then the applied voltage on this pin is high.
*\arg If the value is 0 then the applied voltage on this pin is low.
*/
#define PINB	(*((volatile uint8_t*)0x36))
/**@}*/
/************************************************************* Port C registers ************************************************************/
/**
*\defgroup port_c Port C registers
*\ingroup IO_registers
*@{
*/
/**
*@brief Direction register for port C
*@details
*\arg This register controls the direction of the pin.
*\arg Setting the bit in this register will make the pin output.
*\arg Clearing the bit in this register will make the pin input
*/
#define PORTC   (*((volatile uint8_t*)0x35))
/**
*@brief Direction register for port C
*@details
*\arg This register controls the direction of the pin.
*\arg Setting the bit in this register will make the pin output.
*\arg Clearing the bit in this register will make the pin input
*/
#define DDRC    (*((volatile uint8_t*)0x34))
/**
*@brief Input register for port C
*@details
*\arg This register stores the input values of port C.
*\arg If the value is 1 then the applied voltage on this pin is high.
*\arg If the value is 0 then the applied voltage on this pin is low.
*/
#define PINC    (*((volatile uint8_t*)0x33))
/**@}*/
/************************************************************* Port D registers ************************************************************/
/**
*\defgroup port_d Port D registers
*\ingroup IO_registers
*@{
*/
/**
*@brief Direction register for port D
*@details
*\arg This register controls the direction of the pin.
*\arg Setting the bit in this register will make the pin output.
*\arg Clearing the bit in this register will make the pin input
*/
#define PORTD	(*((volatile uint8_t*)0x32))
/**
*@brief Direction register for port D
*@details
*\arg This register controls the direction of the pin.
*\arg Setting the bit in this register will make the pin output.
*\arg Clearing the bit in this register will make the pin input
*/
#define DDRD	(*((volatile uint8_t*)0x31))
/**
*@brief Input register for port D
*@details
*\arg This register stores the input values of port D.
*\arg If the value is 1 then the applied voltage on this pin is high.
*\arg If the value is 0 then the applied voltage on this pin is low.
*/
#define PIND	(*((volatile uint8_t*)0x30))
/**@}*/
 /************************************************************* Interrupts registers ************************************************************/
 /**
 *\defgroup int_registers  Interrupt registers
 *\ingroup registers
 *@{
 */
 /**
 *@brief General Interrupt Control Register.
 *\image html GICR.png
 *\image latex GICR.png
 *\details
*\arg	Bit 7 - INT1: External Interrupt Request 1 Enable
*\arg	Bit 6 - INT0: External Interrupt Request 0 Enable
*\arg	Bit 5 - INT2: External Interrupt Request 2 Enable
 */
#define GICR	(*((volatile uint8_t*)0x5B))

/**
 *@brief General Interrupt Flag Register.
 *\image html GIFR.png
  *\image latex GIFR.png
 *\details
*\arg	Bit 7 - INTF1: External Interrupt Flag 1
*\arg	Bit 6 - INTF0: External Interrupt Flag 0 
*\arg	Bit 5 - INTF2: External Interrupt Flag 2 
 */
#define GIFR	(*((volatile uint8_t*)0x5A))
/**
 *@brief MCU Control Register.
 *\image html MCUCR.png
  *\image latex MCUCR.png
 *\details
*\arg	Bit 3, 2 - ISC11, ISC10: Interrupt Sense Control 1 Bit 1 and Bit 0.
*\arg Interrupt 0 and interrupt 1 Sense Control.
ISCx1  |ISCx0  | Description											   |
:----: |:----: | :--------------------------------------------------------:|
0	   |0	   | The low level of INTx generates an interrupt request.	   |
0	   |1	   | Any logical change on INTx generates an interrupt request.|
1	   |0	   |  The falling edge of INTx generates an interrupt request. |
1	   |1	   | The rising edge of INTx generates an interrupt request.   |
*\note x may be 0 or 1.

 */
#define MCUCR	(*((volatile uint8_t*)0x55))

/**
 *@brief MCU Control and Status Register.
 *\image html MCUCSR.png
  *\image latex MCUCSR.png
 *\details
*\arg	Bit 6 - ISC2: Interrupt Sense Control 2
*\arg 
ISC2   | Description
:----: | :-------------:
0	   | The falling edge on INT2 activates the interrupt request.
1	   | The rising edge on INT2 activates the interrupt request.
 */
#define MCUCSR	(*((volatile uint8_t*)0x54))
/**@}*/



#endif /* REGISTERFILE_H_ */