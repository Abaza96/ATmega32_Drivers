/*
 * ADC.h
 *
 *  Created on: Feb 9, 2019
 *      Author: Mahmoud Abaza
 */

#ifndef ADC_H_	//If it is not Defined
#define ADC_H_	//Define it

//Definitions
	//ADC Attributes
#define ADC_MinimumVoltage 0
#define ADC_MaximumVoltage 255

	//ADMUX Register Setup Definitions
		//Reference Selection Bits
			//Activate ARef by Clearing Both REFS0 & REFS1
#define ADC_ActivateAnalogReference() 	    CLR_Bit(ADMUX , PIN7); \
											CLR_Bit(ADMUX , PIN6)

			//Activate AVcc by Setting REFS0 & Clearing REFS1
#define ADC_ActivateAnalogVoltage() 	    CLR_Bit(ADMUX , PIN7); \
											SET_Bit(ADMUX , PIN6)

			//Activate Internal 2.56V Voltage by Setting both REFS0 & REFS1
#define ADC_ActivateInternalVoltage() 	    SET_Bit(ADMUX , PIN7); \
											SET_Bit(ADMUX , PIN6)

		//ADLAR Bit
			//Set ADLAR to be Left Adjusted
#define ADC_LeftAdjustedADLAR()			    SET_Bit(ADMUX , PIN5)

			//Clear ADLAR to be Right Adjusted
#define ADC_RightAdjustedADLAR()			CLR_Bit(ADMUX , PIN5)

		//Multiplexers
			//Activate Single Ended ADC0
				//Clear All MUX Bits
#define SingleEnded_ADC0()					CLR_Bit(ADMUX , PIN4); 	\
											CLR_Bit(ADMUX , PIN3); 	\
											CLR_Bit(ADMUX , PIN2); 	\
											CLR_Bit(ADMUX , PIN1); 	\
											CLR_Bit(ADMUX , PIN0)

			//Activate Single Ended ADC1
				//Set MUX0 Bit
#define SingleEnded_ADC1()					CLR_Bit(ADMUX , PIN4); 	\
											CLR_Bit(ADMUX , PIN3); 	\
											CLR_Bit(ADMUX , PIN2); 	\
											CLR_Bit(ADMUX , PIN1); 	\
											SET_Bit(ADMUX , PIN0)

			//Activate Single Ended ADC2
				//Set MUX1 Bit
#define SingleEnded_ADC2()					CLR_Bit(ADMUX , PIN4); 	\
											CLR_Bit(ADMUX , PIN3); 	\
											CLR_Bit(ADMUX , PIN2); 	\
											SET_Bit(ADMUX , PIN1); 	\
											CLR_Bit(ADMUX , PIN0)

			//Activate Single Ended ADC3
				//Set MUX1 & MUX0 Bit
#define SingleEnded_ADC3()					CLR_Bit(ADMUX , PIN4); 	\
											CLR_Bit(ADMUX , PIN3); 	\
											CLR_Bit(ADMUX , PIN2); 	\
											SET_Bit(ADMUX , PIN1); 	\
											SET_Bit(ADMUX , PIN0)

			//Activate Single Ended ADC4
				//Set MUX2 Bit
#define SingleEnded_ADC4()					CLR_Bit(ADMUX , PIN4); 	\
											CLR_Bit(ADMUX , PIN3); 	\
											SET_Bit(ADMUX , PIN2); 	\
											CLR_Bit(ADMUX , PIN1); 	\
											CLR_Bit(ADMUX , PIN0)

			//Activate Single Ended ADC5
				//Set MUX0 & MUX2 Bit
#define SingleEnded_ADC5()					CLR_Bit(ADMUX , PIN4); 	\
											CLR_Bit(ADMUX , PIN3); 	\
											SET_Bit(ADMUX , PIN2); 	\
											CLR_Bit(ADMUX , PIN1); 	\
											SET_Bit(ADMUX , PIN0)

			//Activate Single Ended ADC6
				//Set MUX1 & MUX2 Bit
#define SingleEnded_ADC6()					CLR_Bit(ADMUX , PIN4); 	\
											CLR_Bit(ADMUX , PIN3); 	\
											SET_Bit(ADMUX , PIN2); 	\
											SET_Bit(ADMUX , PIN1); 	\
											CLR_Bit(ADMUX , PIN0)

			//Activate Single Ended ADC7
				//Set MUX0, MUX1 & MUX2 Bit
#define SingleEnded_ADC7()					CLR_Bit(ADMUX , PIN4); 	\
											CLR_Bit(ADMUX , PIN3); 	\
											SET_Bit(ADMUX , PIN2); 	\
											SET_Bit(ADMUX , PIN1); 	\
											SET_Bit(ADMUX , PIN0)

	//ADCSRA Register Setup Definitions
		//Activate or Deactivate The ADC
#define ADC_Enable()						SET_Bit(ADCSRA , PIN7)
#define ADC_TurnOff()						CLR_Bit(ADCSRA , PIN7)

		//Start Conversion
#define ADC_StartConversion()				SET_Bit(ADCSRA , PIN6)

		//Auto-Triggering Enable or Disable
#define ADC_EnableAutoTrigger()				SET_Bit(ADCSRA , PIN5)
#define ADC_DisableAutoTrigger()			CLR_Bit(ADCSRA , PIN5)

		//ADC Interrupting Control
#define ADC_RaiseInterruptFlag()			CLR_Bit(ADCSRA , PIN4)
#define ADC_LowerInterruptFlag()			SET_Bit(ADCSRA , PIN4)
#define ADC_EnableInterrupt()				SET_Bit(ADCSRA , PIN3)
#define ADC_DisableInterrupt()				CLR_Bit(ADCSRA , PIN3)

	//PreScalar Select Bits
		//Clear All to Divide by 2
#define ADC_Prescalar_DivisionFactor0()		CLR_Bit(ADCSRA , PIN2); \
											CLR_Bit(ADCSRA , PIN1); \
											CLR_Bit(ADCSRA , PIN0)

		//Set Bit 3 to Divide by 2
#define ADC_Prescalar_DivisionFactor2()		CLR_Bit(ADCSRA , PIN2); \
											CLR_Bit(ADCSRA , PIN1); \
											SET_Bit(ADCSRA , PIN0)

		//Set Bit 1 to Divide by 4
#define ADC_Prescalar_DivisionFactor4()		CLR_Bit(ADCSRA , PIN2); \
											SET_Bit(ADCSRA , PIN1); \
											CLR_Bit(ADCSRA , PIN0)

		//Set Bit 1 & Bit 2 to Divide by 8
#define ADC_Prescalar_DivisionFactor8()		CLR_Bit(ADCSRA , PIN2); \
											SET_Bit(ADCSRA , PIN1); \
											SET_Bit(ADCSRA , PIN0)

		//Set Bit 0 to Divide by 16
#define ADC_Prescalar_DivisionFactor16()	SET_Bit(ADCSRA , PIN2); \
											CLR_Bit(ADCSRA , PIN1); \
											CLR_Bit(ADCSRA , PIN0)

		//Set Bit 0 & Bit 2 to Divide by 32
#define ADC_Prescalar_DivisionFactor32()	SET_Bit(ADCSRA , PIN2); \
											CLR_Bit(ADCSRA , PIN1); \
											SET_Bit(ADCSRA , PIN0)

		//Set Bit 0 & Bit 1 to Divide by 64
#define ADC_Prescalar_DivisionFactor64()	SET_Bit(ADCSRA , PIN2); \
											SET_Bit(ADCSRA , PIN1); \
											CLR_Bit(ADCSRA , PIN0)

		//Set all Bits to Divide by 128
#define ADC_Prescalar_DivisionFactor128()	SET_Bit(ADCSRA , PIN2); \
											SET_Bit(ADCSRA , PIN1); \
											SET_Bit(ADCSRA , PIN0)

	//Equations
#define ADC_getVoltage(X)					(X * 5) / ADC_MaximumVoltage

//Peripheral APIs
extern void ADC_vidInitialization(void);	//Function to initialize The Registers of The ADC
extern u16 ADC_u16GetResult(void);		//Function to get The Result of The Current ADC in a High State

#endif //Stop Here
