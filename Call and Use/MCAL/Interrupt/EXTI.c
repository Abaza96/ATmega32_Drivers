/*
 * EXTI.c
 *
 *  Created on: May 4, 2019
 *      Author: Mahmoud Abaza
 */
//Libs and Defs
	//Services Stack Files
#include "std_Types.h"
#include "Registers.h"
#include "Macros.h"

	//MCAL Files
#include "DIO.h"
#include "EXTI.h"

//Function APIs Implementation
extern void EXTI_vidFireOnLowLevel(u8 Vector)			//Function to Initialize External Interrupts to be fired on Low Level
{
	if(Vector == INT0_VCTR)
	{
		INT0_LowLevel();
		Enable_INT0();
		Enable_INT0_Flag();
		Enable_Global_Interrupt();
	}

	else if(Vector == INT1_VCTR)
	{
		INT1_LowLevel();
		Enable_INT1();
		Enable_INT1_Flag();
		Enable_Global_Interrupt();
	}

	else if(Vector == INT2_VCTR)
	{
		Enable_INT2();
		Enable_INT2_Flag();
		Enable_Global_Interrupt();
	}
}

extern void EXTI_vidFireOnLogicalChange(u8 Vector)		//Function to Initialize External Interrupts to be fired on Logical Changes
{
	if(Vector == INT0_VCTR)
	{
		INT0_onLogicalChange();
		Enable_INT0();
		Enable_INT0_Flag();
		Enable_Global_Interrupt();
	}

	else if(Vector == INT1_VCTR)
	{
		INT1_onLogicalChange();
		Enable_INT1();
		Enable_INT1_Flag();
		Enable_Global_Interrupt();
	}

	else if(Vector == INT2_VCTR)
	{
		Enable_INT2();
		Enable_INT2_Flag();
		Enable_Global_Interrupt();
	}

}
extern void EXTI_vidFireOnFallingEdge(u8 Vector)		//Function to Initialize External Interrupts to be fired on Falling Edge
{
	if(Vector == INT0_VCTR)
	{
		INT0_onFallingEdge();
		Enable_INT0();
		Enable_INT0_Flag();
		Enable_Global_Interrupt();
	}

	else if(Vector == INT1_VCTR)
	{
		INT1_onFallingEdge();
		Enable_INT1();
		Enable_INT1_Flag();
		Enable_Global_Interrupt();
	}

	else if(Vector == INT2_VCTR)
	{
		Enable_INT2();
		Enable_INT2_Flag();
		Enable_Global_Interrupt();
	}
}

extern void EXTI_vidFireOnRisingEdge(u8 Vector)			//Function to Initialize External Interrupts to be fired on Rising Edge
{
	if(Vector == INT0_VCTR)
	{
		INT0_onRisingEdge();
		Enable_INT0();
		Enable_INT0_Flag();
		Enable_Global_Interrupt();
	}

	else if(Vector == INT1_VCTR)
	{
		INT1_onRisingEdge();
		Enable_INT1();
		Enable_INT1_Flag();
		Enable_Global_Interrupt();
	}

	else if(Vector == INT2_VCTR)
	{
		Enable_INT2();
		Enable_INT2_Flag();
		Enable_Global_Interrupt();
	}
}
