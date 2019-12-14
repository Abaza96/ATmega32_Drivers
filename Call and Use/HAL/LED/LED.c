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
	//Check The PIN Value
	if(PIN == FullyCharged)	//if The PIN is All Juiced Up
	{
		DIO_vidSetPortDirection(PORT , FullyCharged);	//Set The Direction of 8 LEDs to 1
	}
	else	//If it was anything else
	{
		DIO_vidSetPinDirection(PORT, PIN, OUTPUT);	//Set The Direction of The LED to 1
	}
}

extern void LED_vidIlluminate(u8 PORT, u8 PIN)	//Function to Illuminate a Certain LED Taking Parameters for it's PORT and PIN
{
	//Check The PIN Value
	if(PIN == FullyCharged)	//if The PIN is All Juiced Up
	{
		DIO_vidSetPortValue(PORT , FullyCharged);	//Light Up The Whole LEDs
	}
	else	//If it was anything else
	{
		DIO_vidWritePinValue(PORT, PIN, HIGH);	//Light Up The Pin Passed
	}
}

extern void LED_vidDarken(u8 PORT, u8 PIN)		//Function to Darken a Certain LED Taking Parameters for it's PORT and PIN
{
	//Check The PIN Value
	if(PIN == Discharged)	//if The PIN is All Juiced Up
	{
		DIO_vidSetPortValue(PORT , Discharged);	//Light off The Whole LEDs
	}
	else	//If it was anything else
	{
		DIO_vidWritePinValue(PORT, PIN, LOW);	//Light Off The Pin Passed
	}
}

extern void LED_vidBlink(u8 PORT, u8 PIN, u16 Delay)  //Function to Blink a Certain LED Taking Parameters for it's PORT , PIN and a Number of Delay
{
	LED_vidIlluminate(PORT, PIN);	//Light it Up

	_delay_ms(Delay);	//Wait for a Delay

	LED_vidDarken(PORT, PIN);	//Turn it Off

	_delay_ms(Delay);	//Wait for a Delay
}

extern void LED_vidToggle(u8 PORT, u8 PIN)			    //Function to Toggle a Certain LED Taking Parameters for it's PORT and PIN
{
	//Variables
	u8 i; //iterator
	//Check The PIN Value
	if(PIN == FullyCharged)	//if The PIN is All Juiced Up
	{
		for(i = PIN0 ; i <= PIN7 ; i++)
		{
			DIO_vidTogglePinValue(PORT , i);	//Change to The Opposite Bit
		}
	}

	else	//If it was anything else
	{
		DIO_vidTogglePinValue(PORT , PIN);	//Change to The Opposite Bit
	}

}
