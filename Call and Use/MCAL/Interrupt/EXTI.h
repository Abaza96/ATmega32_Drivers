/*
 * INT_Setup.h
 *
 *  Created on: May 4, 2019
 *      Author: Mahmoud Abaza
 */

#ifndef EXTI_H_	//If it is not Defined
//Definitions
#define EXTI_H_	//Define it
#define INT0_VCTR 1
#define INT1_VCTR 2
#define INT2_VCTR 3

	//MCU Control Register Setup
		//For INT0
#define INT0_LowLevel() 	   CLR_Bit(MCUCR , PIN0); \
						       CLR_Bit(MCUCR , PIN1)

#define INT0_onLogicalChange() SET_Bit(MCUCR , PIN0); \
							   CLR_Bit(MCUCR , PIN1)

#define INT0_onFallingEdge()   CLR_Bit(MCUCR , PIN0); \
							   SET_Bit(MCUCR , PIN1)

#define INT0_onRisingEdge()	   SET_Bit(MCUCR , PIN0); \
							   SET_Bit(MCUCR , PIN1)

		//For INT1
#define INT1_LowLevel() 	   CLR_Bit(MCUCR , PIN2); \
						       CLR_Bit(MCUCR , PIN3)

#define INT1_onLogicalChange() SET_Bit(MCUCR , PIN2); \
							   CLR_Bit(MCUCR , PIN3)

#define INT1_onFallingEdge()   CLR_Bit(MCUCR , PIN2); \
							   SET_Bit(MCUCR , PIN3)

#define INT1_onRisingEdge()	   SET_Bit(MCUCR , PIN2); \
							   SET_Bit(MCUCR , PIN3)

	//General Interrupt Control Register
#define Enable_INT0()  SET_Bit(GICR , PIN6)
#define Enable_INT1()  SET_Bit(GICR , PIN7)
#define Enable_INT2()  SET_Bit(GICR , PIN5)

	//General Interrupt Flag Register
#define Enable_INT0_Flag() SET_Bit(GIFR , PIN6)
#define Enable_INT1_Flag() SET_Bit(GIFR , PIN7)
#define Enable_INT2_Flag() SET_Bit(GIFR , PIN5)

	//Global Interrupt Control
#define Enable_Global_Interrupt() SET_Bit(SREG , PIN7)


//Function APIs
extern void EXTI_vidFireOnLowLevel(u8 Vector);			//Function to Initialize External Interrupts to be fired on Low Level

extern void EXTI_vidFireOnLogicalChange(u8 Vector);		//Function to Initialize External Interrupts to be fired on Logical Changes

extern void EXTI_vidFireOnFallingEdge(u8 Vector);		//Function to Initialize External Interrupts to be fired on Falling Edge

extern void EXTI_vidFireOnRisingEdge(u8 Vector);		//Function to Initialize External Interrupts to be fired on Rising Edge

#endif // Stop Here
