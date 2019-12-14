/*
 * Buzzer.c
 *
 *  Created on: Feb 10, 2019
 *      Author: Mahmoud Abaza
 */
//Libs and Defs
	//Services Stack Files
#include "std_Types.h"

	//MCAL Files
#include "DIO.h"
#include "util/delay.h"

	//HAL Files
#include "Buzzer.h"

//Implementations
extern void Buzzer_vidInitialization(u8 PORT, u8 PIN)	//Function To Set The Direction of The Buzzer
{
	DIO_vidSetPinDirection(PORT, PIN, OUTPUT);	//Set The Direction of The Buzzer to 1
}

extern void Buzzer_vidScream(u8 PORT, u8 PIN)	//Function To Make a Sound With The Buzzer by Passing The Buzzer's PORT and PIN as Parameters
{
	DIO_vidWritePinValue(PORT, PIN, HIGH);	//Let The Buzzer Scream
}

extern void Buzzer_vidSilence(u8 PORT, u8 PIN)	//Function To Shut The Buzzer up by Passing The Buzzer's PORT and PIN as Parameters
{
	DIO_vidWritePinValue(PORT, PIN, LOW);	//Shut The Buzzer Up
}

extern void Buzzer_vidAlarmSound(u8 PORT, u8 PIN, u16 Delay)  //Function to Blink a Certain LED Taking Parameters for it's PORT , PIN and a Number of Delay
{
	Buzzer_vidScream(PORT, PIN);	//Make Noises

	_delay_ms(Delay);	//Wait for a Delay

	Buzzer_vidSilence(PORT, PIN);	//Turn it Off

	_delay_ms(Delay);	//Wait for a Delay
}
