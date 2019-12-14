/*
 * Switch.c
 *
 *  Created on: Mar 29, 2019
 *      Author: Mahmoud Abaza
 */
//Libs and Defs
//Services Stack Files
#include "std_Types.h"

//MCAL Files
#include "DIO.h"
#include "util/delay.h"

//HAL Files
#include "Switch.h"

//Functions Implementation
extern void Switch_vidPullUpInitialization(u8 PORT, u8 PIN)		//a Function to Initialize The Switch
{
	//Check PIN Value
	if(PIN == Discharged)	//if it was Connected to a Full PORT
	{
		DIO_vidSetPortDirection(PORT , Discharged);			//Initialize The Direction of The Pin
		DIO_vidSetPortValue(PORT , FullyCharged);			//Give The Pin Number 5V VCC
	}

	else	//If it was connected to One PIN Only
	{
		DIO_vidSetPinDirection(PORT , PIN , INPUT);			//Initialize The Direction of The Pin
		DIO_vidWritePinValue(PORT , PIN , HIGH);			//Give The Pin Number 5V VCC
	}
}

extern void Switch_vidPullDownInitialization(u8 PORT, u8 PIN)		//a Function to Initialize The Switch
{
	//Check PIN Value
	if(PIN == Discharged)	//if it was Connected to a Full PORT
	{
		DIO_vidSetPortDirection(PORT , Discharged);			//Initialize The Direction of The Pin
	}

	else	//If it was connected to One PIN Only
	{
		DIO_vidSetPinDirection(PORT , PIN , INPUT);			//Initialize The Direction of The Pin
	}
}

extern u8 Switch_u8CheckStatus(u8 PORT, u8 PIN) 				//a Function to Check The Switch's Status
{
	u8 Status = DIO_u8GetPinValue(PORT , PIN);		//Get The Status of The Passed Pin and Port

	//Check if it is a False Press
	if(Status == LOW)
	{
		_delay_ms(Switch_CheckingTimeDelay);	//Give it Some Time to Check

		Status = DIO_u8GetPinValue(PORT , PIN);	//Check Closely if it was 0

		if(Status == LOW)	//If it is still 0
		{
			return Status;	//Return it to the Main
		}
	}
	return True;	//Return 1 if it was a false Press
}
