/*
 * LED.c
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
#include "LED.h"

//Implementations
extern void LED_vidInitialization(u8 PORT, u8 PIN)	//Function to Initialize The Direction of The LED
{
	DIO_vidSetPinDirection(PORT, PIN, OUTPUT);	//Set The Direction of The LED to 1
}

extern void LED_vidPortInitialization(u8 PORT)		//Function to Initialize The Direction of The LED in a PORT
{
	DIO_vidSetPortDirection(PORT, FullyCharged); //Initialize The Whole PORT as an Output
}

extern void LED_vidIlluminate(u8 PORT, u8 PIN)	//Function to Illuminate a Certain LED Taking Parameters for it's PORT and PIN
{
	DIO_vidWritePinValue(PORT, PIN, HIGH);	//Light Up The Pin Passed
}

extern void LED_vidDarken(u8 PORT, u8 PIN)		//Function to Darken a Certain LED Taking Parameters for it's PORT and PIN
{
	DIO_vidWritePinValue(PORT, PIN, LOW);	//Light off The Pin Passed
}

extern void LED_vidBlink(u8 PORT, u8 PIN, u16 Delay)  //Function to Blink a Certain LED Taking Parameters for it's PORT , PIN and a Number of Delay
{
	LED_vidIlluminate(PORT, PIN);	//Light it Up

	_delay_ms(Delay);	//Wait for a Delay

	LED_vidDarken(PORT, PIN);	//Turn it Off

	_delay_ms(Delay);	//Wait for a Delay
}
