#ifndef SEGMENT //If the file is not defined
#define SEGMENT //Define it

//Assuming The Segment is Arranged in Order
    //UnDotted Numbers
#define Zero  0x3F           //Display the Zero Shape on the 7 Segment   =   0b00111111
#define One   0x06           //Display the One Shape on the 7 Segment    =   0b00000110
#define Two   0x5B           //Display the Two Shape on the 7 Segment    =   0b01011011
#define Three 0x4F           //Display the Three Shape on the 7 Segment  =   0b01001111
#define Four  0x66           //Display the Four Shape on the 7 Segment   =   0b01100110
#define Five  0x6D           //Display the Five Shape on the 7 Segment   =   0b01101101
#define Six   0x7D           //Display the Six Shape on the 7 Segment    =   0b01111101
#define Seven 0x07           //Display the Seven Shape on the 7 Segment  =   0b00000111
#define Eight 0x7F           //Display the Eight Shape on the 7 Segment  =   0b01111111
#define Nine  0x6F           //Display the Nine Shape on the 7 Segment   =   0b01101111
#define Dot   0x80           //Display the Dot on the 7 Segment          =   0b10000000
#define uSegments Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine    //Define uSegments as The Array Members Line
#define uSegmentsInv Nine, Eight, Seven, Six, Five, Four, Three, Two, One, Zero //Define uSegmentsInv as The Array Members Line reversed


    //Dotted Numbers
#define DottedZero  0Xbf     //Display the Zero Shape on the 7 Segment with a Dot  =  0b10111111
#define DottedOne   0x86     //Display the One Shape on the 7 Segment with a Dot   =  0b10000110
#define DottedTwo   0xdb     //Display the Two Shape on the 7 Segment with a Dot   =  0b11011011
#define DottedThree 0xcf     //Display the Three Shape on the 7 Segment with a Dot =  0b11001111
#define DottedFour  0xe6     //Display the Four Shape on the 7 Segment with a Dot  =  0b11100110
#define DottedFive  0xed     //Display the Five Shape on the 7 Segment with a Dot  =  0b11101101
#define DottedSix   0xfd     //Display the Six Shape on the 7 Segment with a Dot   =  0b11111101
#define DottedSeven 0x87     //Display the Seven Shape on the 7 Segment with a Dot =  0b10000111
#define DottedEight 0xff     //Display the Eight Shape on the 7 Segment with a Dot =  0b11111111
#define DottedNine  0xef     //Display the Nine Shape on the 7 Segment with a Dot  =  0b11101111
#define dSegments DottedZero, DottedOne, DottedTwo, DottedThree, DottedFour, DottedFive, DottedSix, DottedSeven, DottedEight, DottedNine                        //Define dSegments as The Array Members Line
#define dSegmentsInv DottedNine, DottedEight, DottedSeven, DottedSix, DottedFive, DottedFour, DottedThree, DottedTwo, DottedOne, DottedZero                        //Define dSegmentsInv as The Array Members Line reversed

	//Other Definitions
#define Seg_Size 10			 //Number of Counts a Segment can Reach
#define Seg_Init9 9			 //Define 9 as Init9
#define Seg_Init8 8			 //Define 8 as Init8
#define Seg_Init7 7			 //Define 7 as Init7
#define Seg_Init6 6			 //Define 6 as Init6
#define Seg_Init5 5			 //Define 5 as Init5
#define Seg_Init4 4		 	 //Define 4 as Init4
#define Seg_Init3 3			 //Define 3 as Init3
#define Seg_Init2 2			 //Define 2 as Init2
#define Seg_Init1 1			 //Define 1 as Init1
#define CountUp   1		 	 //Define a Random Number to Count up Def
#define Countdown 0		 	 //Define a Random Number to Count down Def


	//Spelling Guard
#define Up 	      CountUp
#define Down      Countdown
#define up 	 	  CountUp
#define down      Countdown
#define dwn       Countdown
#define u         CountUp
#define UP	 	  CountUp
#define DOWN 	  Countdown
#define countdown Countdown
#define countup   Countup

//Function APIs
extern void Seg_vidInitialization(u8 CountRequest);				    		     		//a Function to Initialize 7 Segment
extern void Seg_vidInitializationwithDot(u8 CountRequest);								//a Function to Initialize 7 Segment with a Dot
extern void Seg_vidRegularCount(u8 PORT , u16 Delay);									//a Function to Count on a 7 Segment
extern void Seg_vidDoubleCount(u8 PORT0 , u8 PORT1, u16 Delay);							//a Function to Count on 2 7 Segments
extern void Seg_vidCountdown_90(u8 PORT0 , u8 PORT1, u16 Delay);						//a Function to Count on 2 7 Segments from 90
extern void Seg_vidCountdown_80(u8 PORT0 , u8 PORT1, u16 Delay);						//a Function to Count on 2 7 Segments from 80
extern void Seg_vidCountdown_70(u8 PORT0 , u8 PORT1, u16 Delay);						//a Function to Count on 2 7 Segments from 70
extern void Seg_vidCountdown_60(u8 PORT0 , u8 PORT1, u16 Delay);						//a Function to Count on 2 7 Segments from 60
extern void Seg_vidCountdown_50(u8 PORT0 , u8 PORT1, u16 Delay);						//a Function to Count on 2 7 Segments from 50
extern void Seg_vidCountdown_40(u8 PORT0 , u8 PORT1, u16 Delay);						//a Function to Count on 2 7 Segments from 40
extern void Seg_vidCountdown_30(u8 PORT0 , u8 PORT1, u16 Delay);						//a Function to Count on 2 7 Segments from 30
extern void Seg_vidCountdown_20(u8 PORT0 , u8 PORT1, u16 Delay);						//a Function to Count on 2 7 Segments from 20
extern void Seg_vidCountdown_10(u8 PORT0 , u8 PORT1, u16 Delay);						//a Function to Count on 2 7 Segments from 10
extern void Seg_vidCountdown_LessThan10(u8 PORT0 , u8 PORT1, u8 Number, u16 Delay);		//a Function to Count on 2 7 Segments from >10
extern void Seg_vidCountUp_LessThan10(u8 PORT0 , u8 PORT1, u8 Number, u16 Delay);		//a Function to Count on 2 7 Segments to > 10
extern void Seg_vidCountUp_10(u8 PORT0 , u8 PORT1, u16 Delay);							//a Function to Count on 2 7 Segments to 10
extern void Seg_vidCountUp_20(u8 PORT0 , u8 PORT1, u16 Delay);							//a Function to Count on 2 7 Segments to 20
extern void Seg_vidCountUp_30(u8 PORT0 , u8 PORT1, u16 Delay);							//a Function to Count on 2 7 Segments to 30
extern void Seg_vidCountUp_40(u8 PORT0 , u8 PORT1, u16 Delay);							//a Function to Count on 2 7 Segments to 40
extern void Seg_vidCountUp_50(u8 PORT0 , u8 PORT1, u16 Delay);							//a Function to Count on 2 7 Segments to 50
extern void Seg_vidCountUp_60(u8 PORT0 , u8 PORT1, u16 Delay);							//a Function to Count on 2 7 Segments to 60
extern void Seg_vidCountUp_70(u8 PORT0 , u8 PORT1, u16 Delay);							//a Function to Count on 2 7 Segments to 70
extern void Seg_vidCountUp_80(u8 PORT0 , u8 PORT1, u16 Delay);							//a Function to Count on 2 7 Segments to 80
extern void Seg_vidCountUp_90(u8 PORT0 , u8 PORT1, u16 Delay);							//a Function to Count on 2 7 Segments to 90
#endif  //Stop Right There
