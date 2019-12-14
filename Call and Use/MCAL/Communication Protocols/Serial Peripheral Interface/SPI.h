/*
 * SPI.h
 *
 *  Created on: Jun 16, 2019
 *      Author: Mahmoud Abaza
 */

#ifndef SPI_H_	//If it is not Defined
#define SPI_H_	//Define it

//Definitions
#define SPI_InterruptON  1
#define SPI_InterruptOFF 0
//Case Guard for SPI_InterruptON
#define SPI_INTON SPI_InterruptON
#define SPI_ON SPI_InterruptON
#define SPI_on SPI_InterruptON
#define ON SPI_InterruptON
#define on SPI_InterruptON
//Case Guard for SPI_InterruptOFF
#define SPI_INTOFF SPI_InterruptOFF
#define SPI_OFF SPI_InterruptOFF
#define SPI_off SPI_InterruptOFF
#define OFF SPI_InterruptOFF
#define off SPI_InterruptOFF

//Polarity Definitions
#define SPI_RiseUpFirst    0
#define SPI_FalldownFirst  1
//Cases Guard
#define SPI_riseupfirst SPI_RiseUpFirst
#define SPI_RISEUPFIRST SPI_RiseUpFirst
#define RISEUPFIRST SPI_RiseUpFirst
#define riseupfirst SPI_RiseUpFirst
#define SPI_Rise SPI_RiseUpFirst
#define SPI_R    SPI_RiseUpFirst
#define SPI_RISE SPI_RiseUpFirst
#define SPI_rise SPI_RiseUpFirst
#define RISE SPI_RiseUpFirst
#define Rise SPI_RiseUpFirst
#define rise SPI_RiseUpFirst
#define r 	 SPI_RiseUpFirst
#define SPI_falldownfirst SPI_FalldownFirst
#define SPI_FALLDOWNFIRST SPI_FalldownFirst
#define FALLDOWNFIRST SPI_FalldownFirst
#define falldownfirst SPI_FalldownFirst
#define SPI_Fall SPI_FalldownFirst
#define SPI_f    SPI_FalldownFirst
#define SPI_FALL SPI_FalldownFirst
#define SPI_fall SPI_FalldownFirst
#define FALL SPI_FalldownFirst
#define fall SPI_FalldownFirst
#define f 	 SPI_FalldownFirst

//Phase Definitions
#define SPI_SampleFirst 0
#define SPI_SetupFirst  1
//Cases Guard
#define SPI_smaplefirst SPI_SampleFirst
#define SPI_SAMPLEFIRST SPI_SampleFirst
#define SampleFirst SPI_SampleFirst
#define samplefirst SPI_SampleFirst
#define SAMPLEFIRST SPI_SampleFirst
#define Sample SPI_SampleFirst
#define sample SPI_SampleFirst
#define SAMPLE SPI_SampleFirst

#define SPI_SetupFirst  SPI_SetupFirst
#define SPI_setupfirst SPI_SetupFirst
#define SPI_SETUPFIRST SPI_SetupFirst
#define SetupFirst SPI_SetupFirst
#define setupfirst SPI_SetupFirst
#define SETUPFIRST SPI_SetupFirst
#define SETUP SPI_SetupFirst
#define setup SPI_SetupFirst
#define Setup SPI_SetupFirst

//Order Request
#define SPI_MSBOrder 0
#define SPI_LSBOrder 1
//Cases Guard
#define SPI_MSBORDER SPI_MSBOrder
#define SPI_msborder SPI_MSBOrder
#define MSBORDER SPI_MSBOrder
#define msborder SPI_MSBOrder
#define MSBOrder SPI_MSBOrder
#define MSB SPI_MSBOrder
#define msb SPI_MSBOrder
#define SPI_LSBORDER SPI_LSBOrder
#define SPI_lsborder SPI_LSBOrder
#define LSBORDER SPI_LSBOrder
#define lsborder SPI_LSBOrder
#define LSBOrder SPI_LSBOrder
#define LSB SPI_LSBOrder
#define lsb SPI_LSBOrder

//Frequency Definitions
#define Frequency_2 2
#define Frequency_4 4
#define Frequency_8 8
#define Frequency_16 16
#define Frequency_32 32
#define Frequency_64 64
#define Frequency_Boosted64 66
#define Frequency_128 128
//Cases Guard
#define frequency_2 2
#define frequency_4 4
#define frequency_8 8
#define frequency_16 16
#define frequency_32 32
#define frequency_64 64
#define frequency_boosted64 66
#define frequency_128 128
#define FREQUENCY_2 2
#define FREQUENCY_4 4
#define FREQUENCY_8 8
#define FREQUENCY_16 16
#define FREQUENCY_32 32
#define FREQUENCY_64 64
#define FREQUENCY_BOOSTED64 66
#define FREQUENCY_128 128
//Registers Definitions
	//SPCR
#define SPI_EnableInterrupt()  SET_Bit(SPCR , PIN7)
#define SPI_DisableInterrupt() CLR_Bit(SPCR , PIN7)

#define SPI_Enable()  SET_Bit(SPCR , PIN6)
#define SPI_Disable() CLR_Bit(SPCR , PIN6)

#define SPI_StartFromLSB() SET_Bit(SPCR , PIN5)
#define SPI_StartFromMSB() CLR_Bit(SPCR , PIN5)

#define SPI_DefineAsMaster() SET_Bit(SPCR , PIN4)
#define SPI_DefineAsSlave()  CLR_Bit(SPCR , PIN4)

//Clock Polarity & Phase
#define SPI_RisingFirst()   CLR_Bit(SPCR , PIN3)
#define SPI_FallingFirst()  SET_Bit(SPCR , PIN3)

#define SPI_SampleThenSetup() CLR_Bit(SPCR , PIN2)
#define SPI_SetupThenSample() SET_Bit(SPCR , PIN2)

#define SPI_CLKFrequency_4()	CLR_Bit(SPCR , PIN1); \
								CLR_Bit(SPCR , PIN0); \
								CLR_Bit(SPSR , PIN0)

#define SPI_CLKFrequency_16()   CLR_Bit(SPCR , PIN1); \
								SET_Bit(SPCR , PIN0); \
								CLR_Bit(SPSR , PIN0)

#define SPI_CLKFrequency_64()	SET_Bit(SPCR , PIN1); \
								CLR_Bit(SPCR , PIN0); \
								CLR_Bit(SPSR , PIN0)

#define SPI_CLKFrequency_128()	SET_Bit(SPCR , PIN1); \
								SET_Bit(SPCR , PIN0); \
								CLR_Bit(SPSR , PIN0)

#define SPI_CLKFrequency_2()	CLR_Bit(SPCR , PIN1); \
								CLR_Bit(SPCR , PIN0); \
								SET_Bit(SPSR , PIN0)

#define SPI_CLKFrequency_8()	CLR_Bit(SPCR , PIN1); \
								SET_Bit(SPCR , PIN0); \
								SET_Bit(SPSR , PIN0)

#define SPI_CLKFrequency_32()	SET_Bit(SPCR , PIN1); \
								CLR_Bit(SPCR , PIN0); \
								SET_Bit(SPSR , PIN0)

#define SPI_CLKFrequency_FullJuicedUp()	SET_Bit(SPCR , PIN1); \
										SET_Bit(SPCR , PIN0); \
										SET_Bit(SPSR , PIN0)


	//SPSR
#define SPI_EnableInterruptFlag()   SET_Bit(SPSR , PIN7)
#define SPI_DisableInterruptFlag()  CLR_Bit(SPSR , PIN7)
#define SPI_DataNotTransceivedYet() GET_Bit(SPSR, PIN7) == 0
#define SPI_FlagIsNotRaised() SPI_DataNotTransceivedYet()

#define SPI_CollisionFlagOn()  SET_Bit(SPSR , PIN6)
#define SPI_CollisionFlagOff() CLR_Bit(SPSR , PIN6)



//Function APIs
extern void SPI_vidMasterInitialization(u8 InterruptRequest , u8 OrderRequest , u8 PolarityRequest , u8 PhaseRequest , u8 FrequencyRequest);		//a Function to initialize a Master Chip
extern void SPI_vidSlaveInitialization(u8 InterruptRequest , u8 OrderRequest , u8 PolarityRequest , u8 PhaseRequest);								//a Function to initialize a Slave Chip
extern u8 SPI_u8Transceive(u8 Data);																								                //a Function to Send or Receive Data

#endif /* SPI_H_ */
