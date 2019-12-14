/*
 * Switch.h
 *
 *  Created on: Mar 29, 2019
 *      Author: Mahmoud Abaza
 */

#ifndef SWITCH_H_	//if it is not defined
#define SWITCH_H_	//define it

//Definitions
#define Switch_ButtonIsPressed(PORT , PIN) Switch_u8CheckStatus(PORT , PIN) == LOW
#define Switch_CheckingTimeDelay 100

//APIs
extern void Switch_vidPullUpInitialization(u8 PORT, u8 PIN);	//a Function to Initialize The Switch as Pull-Up
extern void Switch_vidPullDownInitialization(u8 PORT, u8 PIN);	//a Function to Initialize The Switch as Pull-Down
extern u8 Switch_u8CheckStatus(u8 PORT, u8 PIN);				//a Function to Check The Switch's Status


#endif /* SWITCH_H_ */
