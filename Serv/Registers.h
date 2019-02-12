#ifndef DIO //If This File is not Defined
#define DIO //Define it

//The Volt Provider Definition
#define PORTA *((u8*)0x3B)  //Define PORTA as The Address of 0x3B and get it
#define PORTB *((u8*)0x38)  //Define PORTB as The Address of 0x38 and get it
#define PORTC *((u8*)0x35)  //Define PORTC as The Address of 0x35 and get it
#define PORTD *((u8*)0x32)  //Define PORTD as The Address of 0x32 and get it

//The Pin's Status Definition
#define PINA *((volatile u8*)0x39)   //Define PINA as The Address of 0x39 and get it and Store it in The Cache
#define PINB *((volatile u8*)0x36)   //Define PINB as The Address of 0x36 and get it and Store it in The Cache
#define PINC *((volatile u8*)0x33)   //Define PINC as The Address of 0x33 and get it and Store it in The Cache
#define PIND *((volatile u8*)0x30)   //Define PIND as The Address of 0x30 and get it and Store it in The Cache

//The Direction Provider Definition
#define DDRA *((u8*)0x3A)   //Define DDRA as The Address of 0x3A and get it
#define DDRB *((u8*)0x37)   //Define DDRB as The Address of 0x37 and get it
#define DDRC *((u8*)0x34)   //Define DDRC as The Address of 0x34 and get it
#define DDRD *((u8*)0x31)   //Define DDRB as The Address of 0x31 and get it

//Interruption Registers Definition
#define SREG  *((u8*)0x5f)	//Define SREG  as The Address of 0x5f and get it
#define MCUCR *((u8*)0x55)	//Define MCUCR as The Address of 0x55 and get it
#define GICR  *((u8*)0x5B)	//Define GICR  as The Address of 0x5B and get it
#endif  //Stop Right There
