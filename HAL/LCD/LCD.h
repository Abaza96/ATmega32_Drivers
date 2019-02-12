/*
 * LCD.h
 *
 *  Created on: Jan 19, 2019
 *      Author: Mahmoud Abaza
 */

#ifndef HAL_LCD_H_	//If it is not Defined
#define HAL_LCD_H_	//Define it

//Libs and Defs
	//Service Stack Files
#include "std_Types.h"

	//HAL Files
#include "LCD_cfg.h"

	//Definitions
#define in +		//Define in as + for the Readability

#define LCD_Row1  0x00		 	//Define Row 1 for more Readability
#define LCD_Row2  0x40   		//Define Row 2 for more Readability

	//User-Defined Data Types
typedef enum LCD_Cols
{
	LCD_Column1  = 0x00,	 	//Define Column 01 for Readability
	LCD_Column2  ,			 	//Define Column 02 for Readability
	LCD_Column3  ,			 	//Define Column 03 for Readability
	LCD_Column4  ,	 			//Define Column 04 for Readability
	LCD_Column5  ,	 			//Define Column 05 for Readability
	LCD_Column6  ,	 			//Define Column 06 for Readability
	LCD_Column7  ,	 			//Define Column 07 for Readability
	LCD_Column8  ,	 			//Define Column 08 for Readability
	LCD_Column9  ,	 			//Define Column 09 for Readability
	LCD_Column10 ,	   			//Define Column 10 for Readability
	LCD_Column11 ,				//Define Column 11 for Readability
	LCD_Column12 ,				//Define Column 12 for Readability
	LCD_Column13 ,				//Define Column 13 for Readability
	LCD_Column14 ,				//Define Column 14 for Readability
	LCD_Column15 ,   			//Define Column 15 for Readability
	LCD_Column16 				//Define Column 16 for Readability
}Column;


//External Prototypes
extern void LCD_vidInitialization(void);			//Function to Initialize LCD
extern void LCD_vidExecuteCommand(u8 Command);		//Function to Execute Commands of LCD
extern void LCD_vidWriteData(u8 Data);				//Function to Write a Specific Data to LCD
extern void LCD_vidWriteSentence(u8 *Senten);		//Function to Write a Specific Sentence to LCD
extern void LCD_vidWriteNumber(u32 Number);			//Function to Write a Specific Sentence to LCD
extern void LCD_vidsetPosition(u8 Row, u8 Column);	//Function to Manipulate LCD Positions
extern void LCD_vidClearDisplay(void);				//Function to Clear The LCD's Display

#endif //Stop Here
