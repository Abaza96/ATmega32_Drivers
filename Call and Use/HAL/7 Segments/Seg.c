/*
 * Seg.c
 *
 *  Created on: Jun 15, 2019
 *      Author: Mahmoud Abaza
 */
//Libs and Defs
	//Services Stack Files
#include "std_Types.h"
	//MCAL Files
#include "DIO.h"
#include <util/delay.h>
	//HAL Files
#include "Seg.h"

	//Global Variables and Constants
u8 Segment0[Seg_Size];
u8 Segment1[Seg_Size];

//Function APIs Implementation
void Seg_vidInitialization(u8 CountRequest)			//a Function to Initialize 7 Segment
{
	//Variables
	u8 i;	//Iterator
	u8 SegmentHolder[Seg_Size] = {uSegments} , InvertedHolder[Seg_Size] = {uSegmentsInv};	//a Temporary Holder for each Possibility

	//Check The Parameter Passed
	if(CountRequest == CountUp)	//if it is 1
	{
		//Initialize Segment0 as a Regular Counter
		for(i = false ; i < Seg_Size; i++)
		{
			Segment0[i] = SegmentHolder[i];
			Segment1[i] = SegmentHolder[i];
		}
	}

	else if(CountRequest == Countdown)	//if it was 0
	{
		//Initialize Segment0 as a down Counter
		for(i = false ; i < Seg_Size; i++)
		{
			Segment0[i] = InvertedHolder[i];
			Segment1[i] = InvertedHolder[i];
		}
	}

	else	//if Anything Else rather than 0 or 1
	{
		//Initialize Segment0 as a Regular Counter
		for(i = false ; i < Seg_Size; i++)
		{
			Segment0[i] = SegmentHolder[i];
			Segment1[i] = SegmentHolder[i];
		}
	}
}

void Seg_vidInitializationwithDot(u8 CountRequest)					//a Function to Initialize 7 Segment with a Dot
{
	//Variables
	u8 i;	//Iterator
	u8 SegmentHolder[Seg_Size] = {dSegments} , InvertedHolder[Seg_Size] = {dSegmentsInv};	//a Temporary Holder for each Possibility

	//Check The Parameter Passed
	if(CountRequest == CountUp)	//if it is 1
	{
		//Initialize Segment0 as a Regular Counter
		for(i = false ; i < Seg_Size; i++)
		{
			Segment0[i] = SegmentHolder[i];
			Segment1[i] = SegmentHolder[i];
		}
	}

	else if(CountRequest == Countdown)	//if it was 0
	{
		//Initialize Segment0 as a down Counter
		for(i = false ; i < Seg_Size; i++)
		{
			Segment0[i] = InvertedHolder[i];
			Segment1[i] = InvertedHolder[i];
		}
	}

	else	//if Anything Else rather than 0 or 1
	{
		//Initialize Segment0 as a Regular Counter
		for(i = false ; i < Seg_Size; i++)
		{
			Segment0[i] = SegmentHolder[i];
			Segment1[i] = SegmentHolder[i];
		}
	}
}


void Seg_vidRegularCount(u8 PORT, u16 Delay)				//a Function to Count on a 7 Segment
{
	//Variables
	u8 i;	//Iterator

	//PORT Initialization
	DIO_vidSetPortDirection(PORT , FullyCharged);

	for(i = false ; i < Seg_Size ; i++)
	{
		DIO_vidSetPortValue(PORT , Segment0[i]);

		_delay_ms(Delay);
	}
}
void Seg_vidDoubleCount(u8 PORT0 , u8 PORT1, u16 Delay)				//a Function to Count on 2 7 Segments
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	for(i = false ; i < Seg_Size ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}

extern void Seg_vidCountdown_90(u8 PORT0 , u8 PORT1, u16 Delay)				//a Function to Count on 2 7 Segments from or to 90
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	//First Number to See
	DIO_vidSetPortValue(PORT0 , Nine);
	DIO_vidSetPortValue(PORT1 , Zero);

	for(i = false ; i < Seg_Size ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[1 + i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}
extern void Seg_vidCountdown_80(u8 PORT0 , u8 PORT1, u16 Delay)				//a Function to Count on 2 7 Segments from or to 80
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	//First Number to See
	DIO_vidSetPortValue(PORT0 , Eight);
	DIO_vidSetPortValue(PORT1 , Zero);

	for(i = false ; i < Seg_Init8 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[2 + i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}

extern void Seg_vidCountdown_70(u8 PORT0 , u8 PORT1, u16 Delay)			//a Function to Count on 2 7 Segments from or to 70
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	//First Number to See
	DIO_vidSetPortValue(PORT0 , Seven);
	DIO_vidSetPortValue(PORT1 , Zero);

	for(i = false ; i < Seg_Init7 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[3 + i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}
extern void Seg_vidCountdown_60(u8 PORT0 , u8 PORT1, u16 Delay)			//a Function to Count on 2 7 Segments from or to 60
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	//First Number to See
	DIO_vidSetPortValue(PORT0 , Six);
	DIO_vidSetPortValue(PORT1 , Zero);

	for(i = false ; i < Seg_Init6 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[4 + i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}

extern void Seg_vidCountdown_50(u8 PORT0 , u8 PORT1, u16 Delay)			//a Function to Count on 2 7 Segments from or to 50
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	//First Number to See
	DIO_vidSetPortValue(PORT0 , Five);
	DIO_vidSetPortValue(PORT1 , Zero);

	for(i = false ; i < Seg_Init5 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[5 + i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}

extern void Seg_vidCountdown_40(u8 PORT0 , u8 PORT1, u16 Delay)			//a Function to Count on 2 7 Segments from or to 40
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	//First Number to See
	DIO_vidSetPortValue(PORT0 , Four);
	DIO_vidSetPortValue(PORT1 , Zero);

	for(i = false ; i < Seg_Init4 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[6 + i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}
extern void Seg_vidCountdown_30(u8 PORT0 , u8 PORT1, u16 Delay)			//a Function to Count on 2 7 Segments from or to 30
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	//First Number to See
	DIO_vidSetPortValue(PORT0 , Three);
	DIO_vidSetPortValue(PORT1 , Zero);

	for(i = false ; i < Seg_Init3 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[7 + i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}

extern void Seg_vidCountdown_20(u8 PORT0 , u8 PORT1, u16 Delay)			//a Function to Count on 2 7 Segments from or to 20
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	//First Number to See
	DIO_vidSetPortValue(PORT0 , Two);
	DIO_vidSetPortValue(PORT1 , Zero);

	for(i = false ; i < Seg_Init2 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[8 + i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}

extern void Seg_vidCountdown_10(u8 PORT0 , u8 PORT1, u16 Delay) 			//a Function to Count on 2 7 Segments from or to 10
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	//First Number to See
	DIO_vidSetPortValue(PORT0 , One);
	DIO_vidSetPortValue(PORT1 , Zero);

	for(i = false ; i < Seg_Init1 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[9 + i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}

extern void Seg_vidCountdown_LessThan10(u8 PORT0 , u8 PORT1, u8 Number, u16 Delay)		//a Function to Count on 2 7 Segments from or to > 10
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	for(i = false ; i < Seg_Init1 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[9 + i]);

		//Check Number Passed
		if(Number == Seg_Init9)	//If it was 9
		{
			//Loop 9 Times
			for(j = false ; j < Seg_Size ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}

		else if(Number == Seg_Init8)	//if it was 8
		{
			//Loop 8 Times
			for(j = Seg_Init1 ; j < Seg_Size ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}

		else if(Number == Seg_Init7)	//if it was 7
		{
			//Loop 7 Times
			for(j = Seg_Init2 ; j < Seg_Size ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}

		else if(Number == Seg_Init6)	//if it was 6
		{
			//Loop 6 Times
			for(j = Seg_Init3 ; j < Seg_Size ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}

		else if(Number == Seg_Init5)	//if it was 5
		{
			//Loop 5 Times
			for(j = Seg_Init4 ; j < Seg_Size ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}

		else if(Number == Seg_Init4)	//if it was 4
		{
			//Loop 4 Times
			for(j = Seg_Init5 ; j < Seg_Size ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}

		else if(Number == Seg_Init3)	//if it was 3
		{
			//Loop 3 Times
			for(j = Seg_Init6 ; j < Seg_Size ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}

		else if(Number == Seg_Init2)	//if it was 2
		{
			//Loop 2 Times
			for(j = Seg_Init7 ; j < Seg_Size ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}

		else if(Number == Seg_Init1)	//if it was 1
		{
			//Loop Loop Once Times
			for(j = Seg_Init8 ; j < Seg_Size ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}

		else if(Number == false)	//if it was 0
		{
			//Display 0
			DIO_vidSetPortValue(PORT1 , Zero);

			_delay_ms(Delay);
		}

		else	//if it was an Unexpected Value
		{
			//Loop 9 Times
			for(j = false ; j < Seg_Size ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}
	}
}

extern void Seg_vidCountUp_LessThan10(u8 PORT0 , u8 PORT1, u8 Number, u16 Delay)		//a Function to Count on 2 7 Segments from or to > 10
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	for(i = false ; i < Seg_Init1 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[i]);

		//Check Number Passed
		if(Number == Seg_Init9)	//If it was 9
		{
			//Loop 9 Times
			for(j = false ; j < Seg_Size ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}

		else if(Number == Seg_Init8)	//if it was 8
		{
			//Loop 8 Times
			for(j = false ; j < Seg_Init9 ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}

		else if(Number == Seg_Init7)	//if it was 7
		{
			//Loop 7 Times
			for(j = false ; j < Seg_Init8 ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}

		else if(Number == Seg_Init6)	//if it was 6
		{
			//Loop 6 Times
			for(j = false ; j < Seg_Init7 ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}

		else if(Number == Seg_Init5)	//if it was 5
		{
			//Loop 5 Times
			for(j = false ; j < Seg_Init6 ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}

		else if(Number == Seg_Init4)	//if it was 4
		{
			//Loop 4 Times
			for(j = false ; j < Seg_Init5 ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}

		else if(Number == Seg_Init3)	//if it was 3
		{
			//Loop 3 Times
			for(j = false ; j < Seg_Init4 ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}

		else if(Number == Seg_Init2)	//if it was 2
		{
			//Loop 2 Times
			for(j = false ; j < Seg_Init3 ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}

		else if(Number == Seg_Init1)	//if it was 1
		{
			//Loop Loop Once Times
			for(j = false ; j < Seg_Init2 ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}

		else if(Number == false)	//if it was 0
		{
			//Display 0
			DIO_vidSetPortValue(PORT1 , Zero);

			_delay_ms(Delay);
		}

		else	//if it was an Unexpected Value
		{
			//Loop 9 Times
			for(j = false ; j < Seg_Size ; j++)
			{
				DIO_vidSetPortValue(PORT1 , Segment1[j]);

				_delay_ms(Delay);
			}
		}
	}
}

extern void Seg_vidCountUp_10(u8 PORT0 , u8 PORT1, u16 Delay)							//a Function to Count on 2 7 Segments to 10
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	//First Number to See
	DIO_vidSetPortValue(PORT0 , Zero);
	DIO_vidSetPortValue(PORT1 , Zero);

	for(i = false ; i < Seg_Init1 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}

extern void Seg_vidCountUp_20(u8 PORT0 , u8 PORT1, u16 Delay)							//a Function to Count on 2 7 Segments to 20
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	//First Number to See
	DIO_vidSetPortValue(PORT0 , Zero);
	DIO_vidSetPortValue(PORT1 , Zero);

	for(i = false ; i < Seg_Init2 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}
extern void Seg_vidCountUp_30(u8 PORT0 , u8 PORT1, u16 Delay)							//a Function to Count on 2 7 Segments to 30
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	//First Number to See
	DIO_vidSetPortValue(PORT0 , Zero);
	DIO_vidSetPortValue(PORT1 , Zero);

	for(i = false ; i < Seg_Init3 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}

extern void Seg_vidCountUp_40(u8 PORT0 , u8 PORT1, u16 Delay)							//a Function to Count on 2 7 Segments to 40
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	//First Number to See
	DIO_vidSetPortValue(PORT0 , Zero);
	DIO_vidSetPortValue(PORT1 , Zero);

	for(i = false ; i < Seg_Init4 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}

extern void Seg_vidCountUp_50(u8 PORT0 , u8 PORT1, u16 Delay)							//a Function to Count on 2 7 Segments to 50
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	//First Number to See
	DIO_vidSetPortValue(PORT0 , Zero);
	DIO_vidSetPortValue(PORT1 , Zero);

	for(i = false ; i < Seg_Init5 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}
extern void Seg_vidCountUp_60(u8 PORT0 , u8 PORT1, u16 Delay)							//a Function to Count on 2 7 Segments to 60
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	//First Number to See
	DIO_vidSetPortValue(PORT0 , Zero);
	DIO_vidSetPortValue(PORT1 , Zero);

	for(i = false ; i < Seg_Init6 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}

extern void Seg_vidCountUp_70(u8 PORT0 , u8 PORT1, u16 Delay)							//a Function to Count on 2 7 Segments to 70
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	//First Number to See
	DIO_vidSetPortValue(PORT0 , Zero);
	DIO_vidSetPortValue(PORT1 , Zero);

	for(i = false ; i < Seg_Init7 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}

extern void Seg_vidCountUp_80(u8 PORT0 , u8 PORT1, u16 Delay)							//a Function to Count on 2 7 Segments to 80
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	//First Number to See
	DIO_vidSetPortValue(PORT0 , Zero);
	DIO_vidSetPortValue(PORT1 , Zero);

	for(i = false ; i < Seg_Init8 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}

extern void Seg_vidCountUp_90(u8 PORT0 , u8 PORT1, u16 Delay)							//a Function to Count on 2 7 Segments to 90
{
	//Variables
	u8 i , j;	//Iterator

	//PORTs Initialization
	DIO_vidSetPortDirection(PORT0 , FullyCharged);
	DIO_vidSetPortDirection(PORT1 , FullyCharged);

	//First Number to See
	DIO_vidSetPortValue(PORT0 , Zero);
	DIO_vidSetPortValue(PORT1 , Zero);

	for(i = false ; i < Seg_Init9 ; i++)
	{
		DIO_vidSetPortValue(PORT0 , Segment0[i]);

		for(j = false ; j < Seg_Size ; j++)
		{
			DIO_vidSetPortValue(PORT1 , Segment1[j]);

			_delay_ms(Delay);
		}
	}
}
