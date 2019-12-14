/*
 * Keypad_cfg.h
 *
 *  Created on: Jan 26, 2019
 *      Author: Mahmoud Abaza
 */

#ifndef KEYPAD_CFG_H_			//If it is not Defined
#define KEYPAD_CFG_H_			//Define it

//The Keypad's Properties
#define KeypadPort B		   //Place The Port of The Keypad in here
#define Keypad_SwitchDelay 100 //Place The Bouncing Delay in Here (Range of Delay should be from 1 microseconds : 50 microseconds)
#define Keypad_Size 16		   //Place The Number of The Keypads in Here

//Pins of Keypad
#define	Keypad_Row1    PIN0		//Place The R1 Pin in Here
#define	Keypad_Row2	   PIN1		//Place The R2 Pin in Here
#define	Keypad_Row3	   PIN2		//Place The R3 Pin in Here
#define	Keypad_Row4	   PIN3		//Place The R4 Pin in Here
#define	Keypad_Column1 PIN4		//Place The C1 Pin in Here
#define	Keypad_Column2 PIN5		//Place The C2 Pin in Here
#define	Keypad_Column3 PIN6		//Place The C3 Pin in Here
#define	Keypad_Column4 PIN7		//Place The C4 Pin in Here

#endif //Stop Here
