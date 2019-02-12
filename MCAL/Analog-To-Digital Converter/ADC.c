/*
 * ADC.c
 *
 *  Created on: Feb 9, 2019
 *      Author: Mahmoud Abaza
 */

//Libs and Defs
	//Services Stack Files
#include "std_Types.h"
#include "Macros.h"
#include "Registers.h"

	//MCAL Files
#include "DIO.h"
#include "ADC.h"

extern void ADC_vidInitialization(void)		//Function to initialize The Registers of The ADC
{
	//Activate The Analog VCC in The ADMUX by Clearing REFS1 and Setting REFS0
	ADC_ActivateAnalogVoltage();

	//Activate The Left Adjustment
	ADC_LeftAdjustedADLAR(); 	//Set ADLAR

	//Multiplexers
	SingleEnded_ADC0();

	//ADCSRA = 0b11010
	ADC_Enable();						//Start The ADC	(Set That Bit)
	ADC_StartConversion();				//Start The Conversion Process	(Set That Bit)
	ADC_DisableAutoTrigger();			//Disable The Auto Triggering	(Clear That Bit)
	ADC_RaiseInterruptFlag();			//Raise an Interrupt Flag (Set That Pin)
	ADC_DisableInterrupt();				//Don't Allow Any Interruptions (Clear That Bit)
	ADC_Prescalar_DivisionFactor128();	//Set The PreScalar's 3 Bits To Divide The Frequency By 128
}
extern u16 ADC_u16GetResult(void) 			//Function to get The Result of The Current ADC in a High State
{
	ADC_StartConversion();	//Start The ADC

	while(GET_Bit(ADCSRA , PIN4) == LOW)	//Keep in Here Until The ADIF is 1
	{
		continue;
	}

	ADC_RaiseInterruptFlag();	//Raise an Interrupt Flag (Set That Pin)

	return ADCH;	//Get The ADCH
}
