/*
 * LCD_cfg.h
 *
 *  Created on: Jan 19, 2019
 *      Author: Mahmoud Abaza
 */

#ifndef HAL_LCD_CFG_H_	//if it is not Defined
//Libs and Defs
#define HAL_LCD_CFG_H_  //Define it

//LCD Controlling Definitions
#define LCD_DataPort A					//Place the Data Port in Here (Upper-Cased or Lower-Cased)
#define LCD_ControlPort B				//Place the Control Port in Here (Upper-Cased or Lower-Cased)
#define LCD_ExecutionTime 2				//Place the given Execution time from Data sheet in here (The Unit is in Microseconds)
#define LCD_Write 0x80					//Place the DDRAM's MSB Address Number Here
#define LCD_Draw 0x40					//Place the CGRAM's MSB Address Number Here
#define RS PIN0							//Place the Register Select's Pin in Here (PIN0, PIN1, PIN2,....,PIN7 Only)
#define RW PIN1             			//Place the Read/Write's Pin in Here (PIN0, PIN1, PIN2,....,PIN7 Only)
#define E  PIN2             			//Place the Enable's Pin in Here (PIN0, PIN1, PIN2,....,PIN7 Only)

//Place The Initialization Commands Here
#define LCD_FunctionSet 0x3C	  		 	 //Place The Function Set's Command in Here (Binary Form : 0b00111100)
#define LCD_DisplayControl 0x0F		   		 //Place The Display Control's Command in Here (Binary Form : 0b00001111)
#define LCD_ClearDisplay 0x01		  		 //Place The Clear Command in Here (Binary Form : 0b00000001)
#define LCD_EntryMode 0x07		  		     //Place The Entry Mode Command in Here (Binary Form : 0b00000111)
#define LCD_PowerOnDelay 40		  			 //Place The Commands Delay Time in Here (Should be at least 30 uSec)

#endif //Stop Right There
