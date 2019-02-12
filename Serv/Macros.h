#ifndef MACROS  //If it's not Defined
#define MACROS  //Define it

#define SET_Bit(Val , Bit) Val |= (1 << Bit) 	//Set a Specific Bit and restore it in the Value

#define GET_Bit(Val , Bit) ((Val >> Bit) & 1) 	//Get a Specific Bit by anding it with 1 after Shifting The Value Right with Bit

#define CLR_Bit(Val , Bit) Val &= ~(1 << Bit) 	//Clear a Specific Bit and restore it in the Value

#define TOGGLE_Bit(Val , Bit) Val ^= (1 << Bit) //Toggle a Specific Bit and restore it in the Value

#endif   //Stop Right There
