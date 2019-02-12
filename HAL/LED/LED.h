/*
 * LED.h
 *
 *  Created on: Feb 10, 2019
 *      Author: Mahmoud Abaza
 */

#ifndef LED_H_	//If it is not Defined
#define LED_H_	//Proceed

//Hardware API
extern void LED_vidInitialization(u8 PORT, u8 PIN);		//Function to Initialize The Direction of The LED
extern void LED_vidPortInitialization(u8 PORT);			//Function to Initialize The Direction of The LED in a PORT
extern void LED_vidIlluminate(u8 PORT, u8 PIN);			//Function to Illuminate a Certain LED Taking Parameters for it's PORT and PIN
extern void LED_vidDarken(u8 PORT, u8 PIN);			    //Function to Darken a Certain LED Taking Parameters for it's PORT and PIN
extern void LED_vidBlink(u8 PORT , u8 PIN, u16 Delay);  //Function to Blink a Certain LED Taking Parameters for it's PORT , PIN and a Number of Delay

#endif //Stop Here
