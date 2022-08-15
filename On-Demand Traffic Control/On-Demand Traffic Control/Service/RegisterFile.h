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
*@brief <h2>Output register for port A</h2>
*@details
*\arg This register controls the output of the pin.
*\arg Setting the bit in this register will make the pin high.
*\arg Clearing the bit in this register will make the pin low
*\arg If the pin is configured as output through DDRx and we write high to PORTx register this will activate internal pull up resistor (x may be A,B,C or D). 
*/                               
#define PORTA	(*((volatile uint8_t*)0x3B))  //1->high output				0->low output  
/**
*@brief <h2>Direction register for port A</h2>
*@details
*\arg This register controls the direction of the pin.
*\arg Setting the bit in this register will make the pin output.
*\arg Clearing the bit in this register will make the pin input
*/
#define DDRA	(*((volatile uint8_t*)0x3A))  //1->to make it output		0->to make it input  
/**
*@brief <h2>Input register for port A</h2>
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
*@brief <h2>Output register for port B</h2>
*@details
*\arg This register controls the output of the pin.
*\arg Setting the bit in this register will make the pin high.
*\arg Clearing the bit in this register will make the pin low
*\arg If the pin is configured as output through DDRx and we write high to PORTx register this will activate internal pull up resistor (x may be A,B,C or D).
*/
#define PORTB	(*((volatile uint8_t*)0x38))
/**
*@brief <h2>Direction register for port B</h2>
*@details
*\arg This register controls the direction of the pin.
*\arg Setting the bit in this register will make the pin output.
*\arg Clearing the bit in this register will make the pin input
*/
#define DDRB	(*((volatile uint8_t*)0x37))
/**
*@brief <h2>Input register for port A</h2>
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
*@brief <h2>Output register for port C</h2>
*@details
*\arg This register controls the direction of the pin.
*\arg Setting the bit in this register will make the pin output.
*\arg Clearing the bit in this register will make the pin input
*/
#define PORTC   (*((volatile uint8_t*)0x35))
/**
*@brief <h2>Direction register for port C</h2>
*@details
*\arg This register controls the direction of the pin.
*\arg Setting the bit in this register will make the pin output.
*\arg Clearing the bit in this register will make the pin input
*/
#define DDRC    (*((volatile uint8_t*)0x34))
/**
*@brief <h2>Input register for port C</h2>
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
*@brief <h2>Output register for port D</h2>
*@details
*\arg This register controls the direction of the pin.
*\arg Setting the bit in this register will make the pin output.
*\arg Clearing the bit in this register will make the pin input
*/
#define PORTD	(*((volatile uint8_t*)0x32))
/**
*@brief <h2>Direction register for port D</h2>
*@details
*\arg This register controls the direction of the pin.
*\arg Setting the bit in this register will make the pin output.
*\arg Clearing the bit in this register will make the pin input
*/
#define DDRD	(*((volatile uint8_t*)0x31))
/**
*@brief <h2>Input register for port D</h2>
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
 *@brief <h2>General Interrupt Control Register.</h2>
 *\image html GICR.png
 *\image latex GICR.png
 *\details
*\arg	Bit 7 - INT1: External Interrupt Request 1 Enable
*\arg	Bit 6 - INT0: External Interrupt Request 0 Enable
*\arg	Bit 5 - INT2: External Interrupt Request 2 Enable
 */
#define GICR	(*((volatile uint8_t*)0x5B))

/**
 *@brief <h2>General Interrupt Flag Register.</h2>
 *\image html GIFR.png
  *\image latex GIFR.png
 *\details
*\arg	Bit 7 - INTF1: External Interrupt Flag 1
*\arg	Bit 6 - INTF0: External Interrupt Flag 0 
*\arg	Bit 5 - INTF2: External Interrupt Flag 2 
 */
#define GIFR	(*((volatile uint8_t*)0x5A))
/**
 *@brief <h2>MCU Control Register.</h2>
 *\image html MCUCR.png
  *\image latex MCUCR.png
 *\details
*\arg	Bit 3, 2 - ISC11, ISC10: Interrupt Sense Control 1 Bit 1 and Bit 0.
|ISCx1  |ISCx0  | Description											   |
|:----: |:----: | :--------------------------------------------------------:|
|0	   |0	   | The low level of INTx generates an interrupt request.	   |
|0	   |1	   | Any logical change on INTx generates an interrupt request.|
|1	   |0	   |  The falling edge of INTx generates an interrupt request. |
|1	   |1	   | The rising edge of INTx generates an interrupt request.   |
|<b>Interrupt 0 and interrupt 1 Sense Control</b>|||

*\note x may be 0 or 1.

 */
#define MCUCR	(*((volatile uint8_t*)0x55))

/**
 *@brief <h2>MCU Control and Status Register.</h2>
 *\image html MCUCSR.png
  *\image latex MCUCSR.png
 *\details
*\arg	Bit 6 - ISC2: Interrupt Sense Control 2
ISC2   | Description
:----: | :-------------:
0	   | The falling edge on INT2 activates the interrupt request.
1	   | The rising edge on INT2 activates the interrupt request.
 */
#define MCUCSR	(*((volatile uint8_t*)0x54))
/**@}*/
 /************************************************************* Timers registers ************************************************************/
/**
*\defgroup Timers_registers Timers Registers
*\ingroup registers
*/

/**
*\defgroup Timer0_registers Timer0 Registers
*\ingroup Timers_registers
*\details
*\arg This contains all the registers to control Timer0.
*@{
*/

/**
*@brief <h2>Timer/Counter Control Register.</h2>
*\image html TCCR0.png
*\image latex TCCR0.png
*\details
*<h3>Bit 7 - FOC0: Force Output Compare</h3>
*\arg When writing a logical one to the FOC0 bit, an immediate compare match is forced on the Waveform Generation unit.
*<h3> Bit 6, 3 - WGM01:0: Waveform Generation Mode</h3>
*\arg These bits control the counting sequence of the counter, the source for the maximum (TOP) counter value,\n and what type of Waveform Generation to be used.
*| Mode  |WGM01\n (CTC0)  |WGM00\n (PWM0) |Timer/Counter\n Mode of Operation  |TOP	|Update of\n OCR0   | TOV0 Flag\n Set-on|
*|:----: |:--------------:|:-------------:|:---------------------------------:|:-----:|:-----------------:| :----------------:|
*|0	   |0				|0				|Normal								|0xFF	|Immediate			| MAX				|
*|1	   |0				|1				|PWM, Phase Correct					|0xFF	|TOP   				| BOTTOM			|
*|2	   |1				|0				|CTC								|#OCR0	|Immediate			|	MAX				|
*|3	   |1				|1				|Fast PWM							|0xFF	|BOTTOM				| MAX				|
*|<b>Waveform Generation Mode Bit Description</b>|||||||

*<h3>Bit 5:4 - COM01:0: Compare Match Output Mode</h3>
*\arg These bits control the Output Compare pin (OC0) behavior. 
*\arg If one or both of the COM01:0 bits are set, the OC0 output overrides the normal port functionality of the I/O
pin it is connected to.
*\note The Data Direction Register (DDR) bit corresponding to the OC0 pin must be set in order to enable the output driver.
*\arg When OC0 is connected to the pin, the function of the COM01:0 bits depends on the WGM01:0 bit setting.

*|COM01  |COM00  | Description							 |
*|:----: |:----: | :--------------------------------------|
*|0		|0		|Normal port operation,\n OC0 disconnected.|
*|0		|1		|Toggle OC0 on compare match.			 |
*|1		|0		|Clear OC0 on compare match.			 |
*|1		|1		|Set OC0 on compare match.				 |
*|<b>Compare Output Mode, non-PWM Mode</b>|||
\n
*|COM01  |COM00  | Description														|
*|:----: |:----: | :-----------------------------------------------------------------|
*|0		|0		|Normal port operation,\n OC0 disconnected.							|
*|0		|1		|Reserved.															|
*|1		|0		|Clear OC0 on compare match,\n set OC0 at BOTTOM,(non-inverting mode).|
*|1		|1		|Set OC0 on compare match,\n clear OC0 at BOTTOM,(inverting mode)		|
*|<b>Compare Output Mode, Fast PWM Mode</b>|||
*\note A special case occurs when OCR0 equals TOP and COM01 is set. In this case,\n 
	the compare match is ignored, but the set or clear is done at BOTTOM.

*|COM01  |COM00  | Description																				|
*|:----: |:----: | :-----------------------------------------------------------------------------------------|
*|0		|0		|Normal port operation,\n OC0 disconnected.													|
*|0		|1		|Reserved.																					|
*|1		|0		|Clear OC0 on compare match when up-counting.\n Set OC0 on compare match when downcounting.	|
*|1		|1		|Set OC0 on compare match when up-counting.\n Clear OC0 on compare match when downcounting.	|
*|<b>Compare Output Mode, Fast PWM Mode</b>|||

*\note A special case occurs when OCR0 equals TOP and COM01 is set. In this case,\n 
	the compare match is ignored, but the set or clear is done at TOP.


*<h3> Bit 2:0 - CS02:0: Clock Select</h3>
*\arg The three Clock Select bits select the clock source to be used by the Timer/Counter.

*|CS02  |CS01  |CS00  | Description												|
*|:---: |:---: |:---: | :--------------------------------------------------------|
*|0	   |0	  |0	 |No clock source (Timer/Counter stopped).					|
*|0	   |0	  |1	 |clkI/O/(No prescaling).									|
*|0	   |1	  |0	 |clkI/O/8 (From prescaler).								|
*|0	   |1	  |1	 |clkI/O/64 (From prescaler).								|
*|1	   |0	  |0	 |clkI/O/256 (From prescaler).								|
*|1	   |0	  |1	 |clkI/O/1024 (From prescaler).								|
*|1	   |1	  |0	 |External clock source on T0 pin.\n Clock on falling edge.	|
*|1	   |1	  |1	 | External clock source on T0 pin.\n Clock on rising edge.	|
*|<b>Clock Select Bit Description</b>||||

*\note If external pin modes are used for the Timer/Counter0, transitions on the T0 pin will\n
	clock the counter even if the pin is configured as an output. This feature allows software\n
	control of the counting.

*/
#define TCCR0	(*((volatile uint8_t*)0x53))
/**
*@brief <h2>Timer/Counter Register</h2>
*\image html TCNT0.png
*\image latex TCNT0.png
 *@details
	*- The Timer/Counter Register gives direct access, both for read and write operations,\n 
		to the Timer/Counter unit 8-bit counter. 
	*- Writing to the TCNT0 Register blocks (removes) the compare match on the following timer clock.
	*- Modifying the counter (TCNT0) while the counter is running, introduces a risk of missing a compare match\n
	   between TCNT0 and the OCR0 Register.
*/
#define TCNT0	(*((volatile uint8_t*)0x52))
/**
*@brief <h2>Output Compare Register</h2>
*\image html OCR0.png
*\image latex OCR0.png
*@details
	*- The Output Compare Register contains an 8-bit value that is continuously compared\n
	with the counter value (TCNT0). 
	*- A match can be used to generate an output compare interrupt, or to generate a waveform\n
	 output on the OC0 pin.
*/
#define OCR0	(*((volatile uint8_t*)0x5C))
/**@}*/


/**
*\defgroup general_timer_registers General Timers registers
*\ingroup Timers_registers
*@{
*/

/**
*@brief <h2>Timer/Counter Interrupt Flag Register</h2>
*\image html TIFR.png
*\image latex TIFR.png
*\details
*<h3>Bit 1 - OCF0: Output Compare Flag 0</h3>
	*- The OCF0 bit is set (one) when a compare match occurs between the Timer/Counter0
	and the data in OCR0 - Output Compare Register0.
	*- OCF0 is cleared by hardware when executing the corresponding interrupt handling vector.
	*- Alternatively, OCF0 is cleared by writing a logic one to the flag.
	*- When the I-bit in SREG, OCIE0 (Timer/Counter0 Compare Match Interrupt Enable), and OCF0 are set (one),\n
	the Timer/Counter0 Compare Match Interrupt is executed.
*<h3> Bit 0 - TOV0: Timer/Counter0 Overflow Flag</h3>
	*- The bit TOV0 is set (one) when an overflow occurs in Timer/Counter0.
	*- TOV0 is cleared by hardware when executing the corresponding interrupt handling vector.
	*- Alternatively, TOV0 is cleared by writing a logic one to the flag. When the SREG I-bit,\n
	TOIE0 (Timer/Counter0 Overflow Interrupt Enable), and TOV0 are set (one),\n
	the Timer/Counter0 Overflow interrupt is executed.
	*- In phase correct PWM mode, this bit is set when Timer/Counter0 changes counting direction at \$00.
*/
#define TIFR	(*((volatile uint8_t*)0x58))
/**
*@brief <h2>Timer/Counter Interrupt Mask Register</h2>
*\image html TIMSK.png
*\image latex TIMSK.png
*\details
*<h3>Bit 1 - OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable</h3>
	*- When the OCIE0 bit is written to one, and the I-bit in the Status Register is set (one),\n 
	the Timer/Counter0 Compare Match interrupt is enabled. 
	*- The corresponding interrupt is executed if a compare match in Timer/Counter0 occurs,\n
	 i.e., when the OCF0 bit is set in the Timer/Counter Interrupt Flag Register - TIFR.
*<h3>Bit 0 - TOIE0: Timer/Counter0 Overflow Interrupt Enable</h3>
	*- When the TOIE0 bit is written to one, and the I-bit in the Status Register is set (one),\n 
	the Timer/Counter0 Overflow interrupt is enabled. 
	*- The corresponding interrupt is executed if an overflow in Timer/Counter0 occurs,\n 
	i.e., when the TOV0 bit is set in the Timer/Counter Interrupt Flag Register - TIFR.
*/
#define TIMSK	(*((volatile uint8_t*)0x59))
/**@}*/



#endif /* REGISTERFILE_H_ */