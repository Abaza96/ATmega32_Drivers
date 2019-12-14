/*
 * Motors.h
 *
 *  Created on: Mar 30, 2019
 *      Author: Mahmoud Abaza
 */

#ifndef MOTORS_H_	//if it is not Defined
#define MOTORS_H_	//Define it

//Functions APIs
extern void Motor_vidInitialization(u8 PORT , u8 PIN);	    															//Function to Initialize The Motor
extern void Motor_vidConstantSpin(u8 PORT , u8 PIN);																	//Function to Spin The Motor
extern void Motor_vidVariableSpin(u8 PORT , u8 PIN, u16 Delay);															//Function to Spin The Motor with a Delay
extern void Motor_vidIdleMode(u8 PORT , u8 PIN);		  		      													//Function to Switch off The Motor
extern void Motor_vidHBridgeMode(u8 eSwitchA_PORT , u8 eSwitchA_PIN , u8 eSwitchA_State , u8 eSwitchB_PORT , u8 eSwitchB_PIN , u8 eSwitchB_State , u16 Delay);	//Function to Activate Motor with H Bridge

#endif 	//Stop Here
