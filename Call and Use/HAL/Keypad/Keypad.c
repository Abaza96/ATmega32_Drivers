/*
 * Keypad.c
 *
 *  Created on: Jan 26, 2019
 *      Author: Mahmoud Abaza
 */
//Libs and Defs
	//Services Stack Files
#include "std_Types.h"

	//MCAL Files
#include <util/delay.h>

	//HAL Files
#include "LCD.h"
#include "Keypad.h"

//Functions Implementation
extern void Keypad_vidInitialization(void)			//Function to initialize The Keypad Definitions
{
	//Setting The Rows' DDR
	DIO_vidSetPinDirection(KeypadPort, Keypad_Row1, INPUT);		//Set The DDR of Row 1 in The Keypad as 0
	DIO_vidSetPinDirection(KeypadPort, Keypad_Row2, INPUT);		//Set The DDR of Row 2 in The Keypad as 0
	DIO_vidSetPinDirection(KeypadPort, Keypad_Row3, INPUT);		//Set The DDR of Row 3 in The Keypad as 0
	DIO_vidSetPinDirection(KeypadPort, Keypad_Row4, INPUT);		//Set The DDR of Row 4 in The Keypad as 0

	//Setting The Rows' PORT
	DIO_vidWritePinValue(KeypadPort, Keypad_Row1, HIGH);		//Set The PORT of Row 1 in The Keypad as 1
	DIO_vidWritePinValue(KeypadPort, Keypad_Row2, HIGH);		//Set The PORT of Row 2 in The Keypad as 1
	DIO_vidWritePinValue(KeypadPort, Keypad_Row3, HIGH);		//Set The PORT of Row 3 in The Keypad as 1
	DIO_vidWritePinValue(KeypadPort, Keypad_Row4, HIGH);		//Set The PORT of Row 4 in The Keypad as 1

	//Setting The Columns' DDR
	DIO_vidSetPinDirection(KeypadPort, Keypad_Column1, OUTPUT);	//Set The DDR of Column 1 in The Keypad as 1
	DIO_vidSetPinDirection(KeypadPort, Keypad_Column2, OUTPUT);	//Set The DDR of Column 2 in The Keypad as 1
	DIO_vidSetPinDirection(KeypadPort, Keypad_Column3, OUTPUT);	//Set The DDR of Column 3 in The Keypad as 1
	DIO_vidSetPinDirection(KeypadPort, Keypad_Column4, OUTPUT);	//Set The DDR of Column 4 in The Keypad as 1
}

extern u8 Keypad_u8GetButtonStatus(u8 Button)	    //Function to Get whether the Keypad's Button is Active (1) or not (0)
{
	//Variables
	u8 Result = LOW , Column_of_Button = Remainder_of_Quarter(Button) , Row_of_Button = Quarter(Button) , Bit_of_Button = LOW;

	u8 Rows[] = {Keypad_Row1, Keypad_Row2, Keypad_Row3, Keypad_Row4}  , Columns[] = {Keypad_Column1, Keypad_Column2, Keypad_Column3, Keypad_Column4};

	//Setting The Columns' PORT
	DIO_vidWritePinValue(KeypadPort, Keypad_Column1, HIGH);		//Assigning Column 1 as 1
	DIO_vidWritePinValue(KeypadPort, Keypad_Column2, HIGH);		//Assigning Column 2 as 1
	DIO_vidWritePinValue(KeypadPort, Keypad_Column3, HIGH);		//Assigning Column 3 as 1
	DIO_vidWritePinValue(KeypadPort, Keypad_Column4, HIGH);		//Assigning Column 4 as 1

	//Activating The Button
	DIO_vidWritePinValue(KeypadPort, Columns[Column_of_Button], LOW);		//Assigning The Button's Column by 0 to Get it

	Bit_of_Button = DIO_u8GetPinValue(KeypadPort, Rows[Row_of_Button]);	    //Get The Button's Row Number's Bit Value

	if(Bit_of_Button == LOW)	//if it was a Zero Then it's an Input
	{
		_delay_ms(Keypad_SwitchDelay);	//Wait for The Bounces to End

		Bit_of_Button = DIO_u8GetPinValue(KeypadPort, Rows[Row_of_Button]);	   //Check if it was a False Press

		if(Bit_of_Button == LOW)	//if it is STILL Zero
		{
			Result = HIGH; //Then it wasn't a False Press and Assign The Result By 1
		}
	}

	return Result;
}

extern void Keypad_vidDisplayNumberOnLCD(void)		//Function to Display a Number on LCD
{
	//Variables
	u8 i;

	//Checking The Button Pressed and Displaying it
	for(i = False ; i < Keypad_Size ; i++)
	{
		if(Keypad_u8GetButtonStatus(i) == HIGH)	//If This Number is Getting a "High" Value
			{
				LCD_vidWriteNumber(i);	//Display it
			}
	}
}
