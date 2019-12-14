#ifndef embdt   //The File Guard (if This file is not Defined)
#define embdt  //Go ahead and Define it

//Embedded Systems Data Types
    //Unsigned Ones
typedef unsigned char u8;		     //u8 stands for unsigned 8-bits which is equal to unsigned char's No of Bits
typedef unsigned short u16;		 	 //u16 stands for unsigned 16-bits which is equal to unsigned short's No of Bits
typedef unsigned long int u32;	     //u32 stands for unsigned 32-bits which is equal to unsigned long int's No of Bits
typedef unsigned long long int u64;	 //u64 stands for unsigned 64-bits which is equal to unsigned long long int's No of Bits
	//Signed Ones
typedef char s8;	    	  //s8 stands for signed 8-bits which is equal to signed char's No of Bits
typedef short int s16;		  //s16 stands for signed 16-bits	which is equal to signed short's No of Bits
typedef long int s32;		  //s32 stands for signed 32-bits which is equal to signed long int's No of Bits
typedef long long int s64;	  //s64 stands for signed 32-bits which is equal to signed long long int's No of Bits
	//Floating Points
typedef float f32;	 //f32 stands for floating point with 32-bits which is equal to float's No of Bits
typedef double f64;  //f64 stands for floating point with 64-bits which is equal to double's No of Bits


//Definitions
	//Mathematical Equations
#define TenTimes(X) X * 10				//Definition to Get The Tenth of a Certain Number
#define Double(X) X * 2					//Definition to Get The Double of a Certain Number

#define Division_of_Ten(X) X / 10	    //Definition to Get The Tenth Division of a Certain Number
#define Quarter(X) X / 4				//Definition to Get The Quarter of a Certain Number
#define OneThird(X) X / 3				//Definition to Get The One Third of a Certain Number
#define Half(X) X / 2					//Definition to Get The Half of a Certain Number

#define Tenth_Remainder(X) X % 10		//Definition to Get The Remainder of The Tenth of a Certain Number
#define Remainder_of_Quarter(X) X % 4	//Definition to Get The Remainder of The Quarter of a Certain Number
#define Remainder_of_OneThird(X) X % 3	//Definition to Get The Remainder of The One Third of a Certain Number
#define Remainder_of_Half(X) X % 2		//Definition to Get The Remainder of The Half of a Certain Number

	//Boolean Definitions
#define True 1 		     //Define True as 1
#define true True	     //Cases Guard
#define False 0	      	 //Define False as 0
#define false False      //Cases Guard
#define notTrue -1 	  	 //Define notTrue as -1
#define NotTrue notTrue  //Cases Guard

	//Milliseconds Definitions
#define mSec 1000			//Define 1000 (1 Milliseconds)   as mSec
#define HalfmSec 500		//Define 500  (1/2 Milliseconds) as HalfmSec
#define OneThirdmSec 300	//Define 300  (1/3 Milliseconds) as OneThirdmSec
#define QuartermSec 250		//Define 250  (1/4 Milliseconds) as QuartermSec

	//Microseconds Definitions
#define uSec 1000			//Define 1000 (1 Microseconds) 	 as uSec
#define HalfuSec 500		//Define 500  (1/2 Microseconds) as HalfuSec
#define OneThirduSec 300	//Define 300  (1/3 Microseconds) as OneThirduSec
#define QuarteruSec 250		//Define 250  (1/4 Microseconds) as QuarteruSec

#endif  //Stop Right there
