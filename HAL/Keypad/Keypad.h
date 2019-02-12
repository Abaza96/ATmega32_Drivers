/*
 * Keypad.h
 *
 *  Created on: Jan 26, 2019
 *      Author: Mahmoud Abaza
 */

#ifndef KEYPAD_H_	//If it is not Defined
#define KEYPAD_H_	//Define it

//Libs and Defs
	//Services Stack Files
#include "std_Types.h"

	//MCAL Files
#include "DIO.h"

	//HAL Files
#include "Keypad_cfg.h"
#include "Keypad.h"

	//Definitions
#define EndofTheLine 32

//Function Prototypes
extern void Keypad_vidInitialization(void);		//Function to initialize The Keypad Definitions
extern u8 Keypad_u8GetButtonStatus(u8 Button);	//Function to Get whether the Keypad's Button is Active (1) or not (0)
extern void Keypad_vidDisplayNumberOnLCD(void);		//Function to Display a Number on LCD

#endif //Stop Here
