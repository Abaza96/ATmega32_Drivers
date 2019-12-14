#ifndef DIO //If This File is not Defined
#define DIO //Define it

/*
 * The Structure of The Comments is:
 * Define {RegisterName} 
 * as The Address of {The Address of The Register from the Datasheet} 
 * and {The Condition of the Register}
 */

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
#define SREG  *((volatile u8*)0x5f)	//Define SREG  as The Address of 0x5f and get it
#define MCUCR *((volatile u8*)0x55)	//Define MCUCR as The Address of 0x55 and get it
#define GIFR  *((volatile u8*)0x5A)	//Define GIFR  as The Address of 0x5A and get it
#define GICR  *((volatile u8*)0x5B)	//Define GICR  as The Address of 0x5B and get it

//ADCs Registers Definition
#define ADMUX  *((volatile u8*)0x27)  	//Define ADMUX  as The Address of 0x27 and Get it
#define ADCSRA *((volatile u8*)0x26)  	//Define ADCSRA as The Address of 0x26 and Get it
#define ADC    *((volatile u16*)0x24)  	//Define ADC    as The Address of 0x24 and Get it to access the Whole u8
#define ADCH   *((volatile u8*)0x25)  	//Define ADCH   as The Address of 0x25 and Get it
#define ADCL   *((volatile u8*)0x24)  	//Define ADCL   as The Address of 0x24 and Get it

//First Timer Registers Definitions
#define TCNT0 *((volatile u8*)0x52)		//Define TCNT0 as The Address of 0x52 and Get it
#define TCCR0 *((volatile u8*)0x53)		//Define TCCR0 as The Address of 0x53 and Get it
#define TIMSK *((volatile u8*)0x59)		//Define TIMSK as The Address of 0x59 and Get it
#define OCR0  *((volatile u8*)0x5C)		//Define OCR0  as The Address of 0x5C and Get it

//Second Timer Registers Definitions
#define TCNT1  *((volatile u16*)0x4C)	    //Define TCNT1  as The Address of 0x4C and Get it
#define TCNT1L *((volatile u8*)0x4C)		//Define TCNT1L as The Address of 0x4C and Get it
#define TCNT1H *((volatile u8*)0x4D)		//Define TCNT1H as The Address of 0x4D and Get it
#define TCCR1  *((volatile u8*)0x4E)		//Define TCCR1  as The Address of 0x4E and Get it
#define TCCR1A *((volatile u8*)0x4F)		//Define TCNT1A as The Address of 0x4F and Get it
#define TCCR1B *((volatile u8*)0x4E)		//Define TCNT1B as The Address of 0x4E and Get it
#define ICR1   *((volatile u16*)0x46)		//Define ICR1  as The Address of 0x46 and Get it
#define ICR1L  *((volatile u8*)0x46)		//Define ICR1L as The Address of 0x46 and Get it
#define ICR1H  *((volatile u8*)0x47)		//Define ICR1H as The Address of 0x47 and Get it
#define OCR1A  *((volatile u16*)0x4A)		//Define OCR1A  as The Address of 0x4A and Get it
#define OCR1AL *((volatile u8*)0x4A)		//Define OCR1AL as The Address of 0x4A and Get it
#define OCR1AH *((volatile u8*)0x4B)		//Define OCR1AH as The Address of 0x4B and Get it
#define OCR1B  *((volatile u16*)0x48)		//Define OCR1B  as The Address of 0x48 and Get it
#define OCR1BL *((volatile u8*)0x48)		//Define OCR1BL as The Address of 0x48 and Get it
#define OCR1BH *((volatile u8*)0x49)		//Define OCR1BH as The Address of 0x49 and Get it
#define TIFR  *((volatile u8*)0x58)		    //Define TIFR as The Address of 0x58 and Get it

//USART Registers Definitions
#define UBRRL *((volatile u8*)0x29)		//Define UBRRL as The Address of 0x29 and Get it
#define UCSRB *((volatile u8*)0x2A)		//Define UCSRB as The Address of 0x2A and Get it
#define UCSRA *((volatile u8*)0x2B)		//Define UCSRA as The Address of 0x2B and Get it
#define UDR   *((volatile u8*)0x2C)		//Define UDR   as The Address of 0x2C and Get it
#define UCSRC *((volatile u8*)0x40)		//Define UCSRC as The Address of 0x40 and Get it

//Two Wire Serial Interfacing Registers Definitions
#define TWDR  *((volatile u8*)0x20)		//Define TWDR as The Address of 0x20 and Get it
#define TWSR  *((volatile u8*)0x21)		//Define TWSR as The Address of 0x21 and Get it
#define TWAR  *((volatile u8*)0x22)		//Define TWAR as The Address of 0x22 and Get it
#define TWBR  *((volatile u8*)0x23)		//Define TWBR as The Address of 0x23 and Get it
#define TWCR  *((volatile u8*)0x56)		//Define TWCR as The Address of 0x56 and Get it

//SPI Registers Definitions
#define SPCR  *((volatile u8*)0x2D)		//Define SPCR as The Address of 0x2D and Get it
#define SPSR  *((volatile u8*)0x2E)		//Define SPSR as The Address of 0x2E and Get it
#define SPDR  *((volatile u8*)0x2F)		//Define SPDR as The Address of 0x2F and Get it



#endif  //Stop Right There
