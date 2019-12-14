/*
 * SPI.c
 *
 *  Created on: Jun 16, 2019
 *      Author: Mahmoud Abaza
 */
//Libs and Defs
	//Services Stack Files
#include "std_Types.h"
#include "Registers.h"
	//MCAL Files
#include "DIO.h"
#include "SPI.h"

//Function APIs Implementation
extern void SPI_vidMasterInitialization(u8 InterruptRequest , u8 OrderRequest , u8 PolarityRequest , u8 PhaseRequest , u8 FrequencyRequest)		//a Function to initialize a Master Chip
{
	//INT Request Check
	if(InterruptRequest == SPI_InterruptON)
	{
		SPI_EnableInterrupt();
	}
	else
	{
		SPI_DisableInterrupt();
	}

	//Start SPI
	SPI_Enable();

	//Order Check
	if(OrderRequest == SPI_LSBOrder)
	{
		SPI_StartFromLSB();
	}

	else
	{
		SPI_StartFromMSB();
	}

	//Define as Master for The Master Initialization
	SPI_DefineAsMaster();

	//Polarity Check
    if(PolarityRequest == SPI_RiseUpFirst)
	{
    	SPI_RisingFirst();
	}

    else
    {
    	SPI_FallingFirst();
    }

    //Phase Check
    if(PhaseRequest == SPI_SampleFirst)
    {
    	SPI_SampleThenSetup();
    }

    else
    {
    	SPI_SetupThenSample();
    }

    //Frequency Check -Specific only for Master-
    if(FrequencyRequest == Frequency_2)
    {
    	SPI_CLKFrequency_2();
    }

    else if(FrequencyRequest == Frequency_4)
    {
    	SPI_CLKFrequency_4();
    }

    else if(FrequencyRequest == Frequency_8)
    {
    	SPI_CLKFrequency_8();
    }

    else if(FrequencyRequest == Frequency_16)
    {
    	SPI_CLKFrequency_16();
    }

    else if(FrequencyRequest == Frequency_32)
    {
    	SPI_CLKFrequency_32();
    }

    else if(FrequencyRequest == Frequency_64)
    {
    	SPI_CLKFrequency_64();
    }

    else if(FrequencyRequest == Frequency_Boosted64)
    {
    	SPI_CLKFrequency_FullJuicedUp()();
    }

    else if(FrequencyRequest == Frequency_128)
    {
    	SPI_CLKFrequency_128();
    }

    else
    {
    	SPI_CLKFrequency_2();
    }
}

extern void SPI_vidSlaveInitialization(u8 InterruptRequest , u8 OrderRequest , u8 PolarityRequest , u8 PhaseRequest)  		//a Function to initialize a Slave Chip
{
	//INT Request Check
	if(InterruptRequest == SPI_InterruptON)
	{
		SPI_EnableInterrupt();
	}
	else
	{
		SPI_DisableInterrupt();
	}

	//Start SPI
	SPI_Enable();

	//Order Check
	if(OrderRequest == SPI_LSBOrder)
	{
		SPI_StartFromLSB();
	}

	else
	{
		SPI_StartFromMSB();
	}
	//Define as Slave for The Slave Initialization
	SPI_DefineAsSlave();

	//Polarity Check
    if(PolarityRequest == SPI_RiseUpFirst)
	{
    	SPI_RisingFirst();
	}

    else
    {
    	SPI_FallingFirst();
    }

    //Phase Check
    if(PhaseRequest == SPI_SampleFirst)
    {
    	SPI_SampleThenSetup();
    }

    else
    {
    	SPI_SetupThenSample();
    }

}

extern u8 SPI_u8Transceive(u8 Data)		 //a Function to Send or Receive Data
{
	SPDR = Data;

	while(SPI_DataNotTransceivedYet());

	return SPDR;
}
