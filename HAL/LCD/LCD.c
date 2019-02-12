/*
 * LCD.c
 *
 *  Created on: Jan 19, 2019
 *      Author: Mahmoud Abaza
 */
//Libs and Defs
	//Service Stack Files
#include "Registers.h"
	//MCAL Files
#include "DIO.h"
#include <util/delay.h>
	//HAL Files
#include "LCD_cfg.h"
#include "LCD.h"

	//Definitions
#define ASCII_Numbers_Initiator 48

//Functions Implementation
extern void LCD_vidExecuteCommand(u8 Command)	//Function to Execute Commands of LCD
{
	//First is Initializing the Register Select (RS) by Zero to Execute a Command
	DIO_vidWritePinValue(LCD_ControlPort, RS, LOW);

    //Second is Initializing the Read/Write (RW) by Zero to Write
	DIO_vidWritePinValue(LCD_ControlPort, RW, LOW);

	//Third is Loading The Data
	DIO_vidSetPortValue(LCD_DataPort, Command);

	//After That is Initializing the Enable (E) by One to Run Command
	DIO_vidWritePinValue(LCD_ControlPort, E, HIGH);

	//Delay to Let it Execute for a Time
	_delay_ms(LCD_ExecutionTime);

    //Finally is Initializing the Enable (E) by Zero to Stop
	DIO_vidWritePinValue(LCD_ControlPort, E, LOW);
}

extern void LCD_vidWriteData(u8 Data)			//Function to Write a Specific Data from LCD
{
	//First is Initializing the Register Select (RS) by One to Display Data
	DIO_vidWritePinValue(LCD_ControlPort, RS, HIGH);

    //Second is Initializing the Read/Write (RW) by Zero to Write
	DIO_vidWritePinValue(LCD_ControlPort, RW, LOW);

	//Third is Loading The Data
	DIO_vidSetPortValue(LCD_DataPort, Data);

	//After That is Initializing the Enable (E) by One to Run Command
	DIO_vidWritePinValue(LCD_ControlPort, E, HIGH);

	//Delay to Let it Execute for a Time
	_delay_ms(LCD_ExecutionTime);

    //Finally is Initializing the Enable (E) by Zero to Stop
	DIO_vidWritePinValue(LCD_ControlPort, E, LOW);
}

extern void LCD_vidInitialization(void)		//Function to Initialize LCD
{
	DIO_vidSetPinDirection(LCD_ControlPort, RS, OUTPUT);	//Initialize The RS's Direction as 1

	DIO_vidSetPinDirection(LCD_ControlPort, RW, OUTPUT);	//Initialize The RW's Direction as 1

	DIO_vidSetPinDirection(LCD_ControlPort, E, OUTPUT);		//Initialize The E's  Direction as 1

	DIO_vidSetPortDirection(LCD_DataPort, FullyCharged);	//Charge The Whole Data Port with 1s

	_delay_ms(LCD_PowerOnDelay);	//Delay for at least 30 microseconds

	LCD_vidExecuteCommand(LCD_FunctionSet);					//The Function Set Command Setup

	_delay_ms(LCD_ExecutionTime);	//Delay for at least 30 microseconds

	LCD_vidExecuteCommand(LCD_DisplayControl);				//The Display ON/OFF Control Command Setup

	_delay_ms(LCD_ExecutionTime);	//Delay for at least 30 microseconds

	LCD_vidExecuteCommand(LCD_ClearDisplay);				//The Clear Display Command Setup

	_delay_ms(LCD_ExecutionTime);	//Delay for at least 30 microseconds

//	LCD_vidExecuteCommand(LCD_EntryMode);				//The Entry Mode Command Setup
}

void LCD_vidWriteSentence(u8 *Senten)		//Function to Write a Specific Sentence to LCD
{
	u8 i = False;	//Iterator Variable

	while(Senten[i] != False)	//Keep Going Until you find a Null Terminator
	{
		LCD_vidWriteData(Senten[i]);	//Write that Character

		i++;	//Add one to The Iterator & Continue
	}
}

extern void LCD_vidWriteNumber(u32 Number)		//Function to Write a Specific Sentence to LCD
{
	u32 Reversed = True;	//Let The Reversed Number Be = 1 to Guard The Reverse if Number is Equal to (a Number % 10 = 0)

	while (Number != False)		//Keep Reversing Till Reaching Zero
	{
		Reversed = TenTimes(Reversed) + Tenth_Remainder(Number);	//The Reverse Formula

		Number = Division_of_Ten(Number);	//Divide The Number By 10
	}

	while (Reversed != True)		//Keep Checking Till Reversed is only = 1
	{
		LCD_vidWriteData((Tenth_Remainder(Reversed)) + ASCII_Numbers_Initiator);	//Get The ASCII of The (Current Reversed % 10)

		Reversed = Division_of_Ten(Reversed);	//Shorten The Number
	}
}

extern void LCD_vidsetPosition(u8 LCD_Row, u8 LCD_Column)	//Function to Manipulate LCD Positions
{
	if(LCD_Row == False)	//If the Row Chosen = 0
	{
		LCD_vidExecuteCommand(LCD_Write in LCD_Column);	//Get to the First Row at the Desired Column
	}

	else	//If the Row Chosen = any Other than 0
	{
		LCD_vidExecuteCommand(LCD_Write in LCD_Row2 in LCD_Column);	//Get to the Second Row at the Desired Column
	}
}

extern void LCD_vidClearDisplay(void)				//Function to Clear The LCD's Display
{
	LCD_vidExecuteCommand(LCD_ClearDisplay);				//The Clear Display Command Setup
}
