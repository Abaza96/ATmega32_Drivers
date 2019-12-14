/*
 * Motors.c
 *
 *  Created on: Mar 30, 2019
 *      Author: Mahmoud Abaza
 */
//Libs and Defs
	//Services Stack Files
#include "std_Types.h"

	//MCAL Files
#include "DIO.h"
#include <util/delay.h>


extern void Motor_vidInitialization(u8 PORT , u8 PIN)	    //Function to Initialize The Motor
{
	//Check The Pin Value
	if(PIN == FullyCharged)	//if The PIN was All Juiced Up
	{
		DIO_vidSetPortDirection(PORT , FullyCharged);	//Run The Motor from the Whole Port
	}

	else	//If it was Only from PIN0 to PIN7
	{
		DIO_vidSetPinDirection(PORT , PIN , OUTPUT);	//Run The Motor From this PIN in That PORT
	}

}

extern void Motor_vidConstantSpin(u8 PORT , u8 PIN)					//Function to Spin The Motor
{
	//Check The Pin Value
	if(PIN == FullyCharged)	//if The PIN was All Juiced Up
	{
		DIO_vidSetPortValue(PORT , FullyCharged); //Run The Motor from the Whole Port
	}

	else	//If it was Only from PIN0 to PIN7
	{
		DIO_vidWritePinValue(PORT , PIN , HIGH);	//Run The Motor From this PIN in That PORT
	}
}

extern void Motor_vidVariableSpin(u8 PORT , u8 PIN, u16 Delay)	//Function to Spin The Motor with a Delay
{
	//Check The Pin Value
	if(PIN == FullyCharged) 	//if The PIN was All Juiced Up
	{
		DIO_vidSetPortValue(PORT , FullyCharged); //Run The Motor from the Whole Port

		_delay_ms(Delay);	//Wait For a Given Time

		DIO_vidSetPortValue(PORT , Discharged);	//Stop The Motor

		_delay_ms(Delay);	//Wait for a Given Time
	}

	else 	//If it was Only from PIN0 to PIN7
	{
		DIO_vidWritePinValue(PORT , PIN , HIGH);	//Run The Motor From this PIN in That PORT

		_delay_ms(Delay);

		DIO_vidWritePinValue(PORT , PIN , LOW);

		_delay_ms(Delay);
	}
}

extern void Motor_vidIdleMode(u8 PORT , u8 PIN)		    //Function to Switch off The Motor
{
	//Check The Pin Value
	if(PIN == Discharged) 	//if The PIN was All Juiced Up
	{
		DIO_vidSetPortValue(PORT , Discharged);	//Stop The Motor
	}

	else 	//If it was Only from PIN0 to PIN7
	{
		DIO_vidWritePinValue(PORT , PIN , LOW);	//Stop That Pin's Charge
	}
}

extern void Motor_vidHBridgeMode(u8 eSwitchA_PORT , u8 eSwitchA_PIN , u8 eSwitchA_State , u8 eSwitchB_PORT , u8 eSwitchB_PIN , u8 eSwitchB_State , u16 Delay)	//Function to Activate Motor with H Bridge
{
	if(eSwitchA_State && !eSwitchB_State)
	{
		Motor_vidVariableSpin(eSwitchA_PORT , eSwitchA_PIN , Delay);
	}

	else if(eSwitchB_State && !eSwitchA_State)
	{
		Motor_vidVariableSpin(eSwitchB_PORT , eSwitchB_PIN , Delay);
	}

	else
	{
		Motor_vidIdleMode(A , Discharged);
	}
}
