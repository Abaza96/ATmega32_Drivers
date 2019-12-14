//The AVR Microcontroller DIO Driver

#ifndef DIO_H_  //If the file is not defined
#define DIO_H_  //Define it

//Libs and Defs

	//The PORTs Names : Probability #1
#define A 0
#define B 1
#define C 2
#define D 3

	//The PORTs Names : Probability #2
#define a A
#define b B
#define c C
#define d D

	//States Definitions
#define HIGH   1
#define LOW    0
#define OUTPUT 1
#define INPUT  0

    //PORT Charge States
#define FullyCharged     0xff
#define SemiChargedRight 0x0f
#define SemiChargedLeft  0xf0
#define Discharged       0x00

#include "Registers.h"     //Include The Registers file to be used
#include "std_Types.h"     //Include The Standard Types file to be used
#include "Macros.h"    	 //Include The Macros file to be used

//User-Defined Data Types
typedef enum pins
{
	PIN0	,	//Pin0 as 0
	PIN1	,	//Pin1 as 1
	PIN2	,	//Pin2 as 2
	PIN3	,	//Pin3 as 3
	PIN4	,	//Pin4 as 4
	PIN5	,	//Pin5 as 5
	PIN6	,	//Pin6 as 6
	PIN7		//Pin7 as 7
}Pins;

//External Prototypes and Variables
extern void DIO_vidSetPinDirection(u8 PORT, u8 PIN, u8 Dir);  //Set the DDR in the AVR's DIO that Returns Void

extern void DIO_vidWritePinValue(u8 PORT, u8 PIN, u8 Value);  //Write the PORT Value in the AVR's DIO that Returns Void

extern void DIO_vidTogglePinValue(u8 PORT, u8 Value);   //Assigning The Whole PORT as a Value

extern u8 DIO_u8GetPinValue(u8 PORT, u8 PIN);  //Get the PIN Value in the AVR's DIO that Returns unsigned 8-Bits

extern void DIO_vidSetPortDirection(u8 PORT, u8 Dir);   //Assigning The Whole PORT as a Direction

extern void DIO_vidSetPortValue(u8 PORT, u8 Value);   //Assigning The Whole PORT as a Value

extern void DIO_vidTogglePortValue(u8 PORT);   //Assigning The Whole PORT as a Value

#endif  //Stop Right There
