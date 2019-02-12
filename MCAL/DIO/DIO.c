#include "DIO.h"           				    //Include The DIO file to be used

extern void DIO_vidSetPinDirection(u8 PORT, u8 PIN, u8 Dir)  //Set the DDR in the AVR's DIO that Returns Void
{
    switch(PORT)    //Probabilities of PORT
    {
        case A:     //Probability #1 : if The PORT's Direction was A
            {
                if(Dir == OUTPUT) //if The Direction was Set to 1
                  {
                    SET_Bit(DDRA, PIN); //Assign that Specific PIN by DDRA
                  }   
                
                else if(Dir == INPUT) //if The Direction was Set to 0
                  {
                    CLR_Bit(DDRA, PIN); //Clear that Specific PIN by DDRA
                  }
                break;  //Get out of the Switch Statement
            }

        case B:     //Probability #2 : if The PORT's Direction was B
            {
                if(Dir == OUTPUT)
                  {
                    SET_Bit(DDRB, PIN);
                  }   
                
                else if(Dir == INPUT)
                  {
                    CLR_Bit(DDRB, PIN);
                  }
                break;
            }
            
        case C:     //Probability #3 : if The PORT's Direction was C
            {
                if(Dir == OUTPUT)
                  {
                    SET_Bit(DDRC, PIN);
                  }   
                
                else if(Dir == INPUT)
                  {
                    CLR_Bit(DDRC, PIN);
                  }
                break;
            }
            
        case D:     //Probability #4 : if The PORT's Direction was D
            {
                if(Dir == OUTPUT)
                  {
                    SET_Bit(DDRD, PIN);
                  }   
                
                else if(Dir == INPUT)
                  {
                    CLR_Bit(DDRD, PIN);
                  }
                break;
            }
    }
}

extern void DIO_vidWritePinValue(u8 PORT, u8 PIN, u8 Value)    //Write the PORT Value in the AVR's DIO that Returns Void
{
    switch(PORT)    //Probabilities of PORT
    {
        case A:  //Probability #1 : if The PORT's Direction was A
            {
                if(Value == HIGH)   //If the Value Passed as 1
                  {
                    SET_Bit(PORTA, PIN);    //Set it to 1
                  }   
                
                else if(Value == LOW) //If the Value Passed as 0
                  {
                    CLR_Bit(PORTA, PIN);    //Set it to 0
                  }
                break;  //Get out of the Switch Statement
            }

        case B:  //Probability #2 : if The PORT's Direction was DDRB
            {
                if(Value == HIGH)      //If the Value Passed as 1
                  {
                    SET_Bit(PORTB, PIN);        //Set it to 1
                  }   
                
                else if(Value == LOW)  //If the Value Passed as 0
                  {
                    CLR_Bit(PORTB, PIN);    //Set it to 0
                  }
                break;  //Get out of the Switch Statement
            }
            
        case C:  //Probability #3 : if The PORT's Direction was DDRC
            {
                if(Value == HIGH)   //If the Value Passed as 1
                  {
                    SET_Bit(PORTC, PIN);    //Set it to 1
                  }   
                
                else if(Value == LOW)    //If the Value Passed as 0
                  {
                    CLR_Bit(PORTC, PIN);    //Set it to 0
                  }
                break;  //Get out of the Switch Statement
            }
            
        case D:  //Probability #4 : if The PORT's Direction was DDRD
            {
                if(Value == HIGH)   //If the Value Passed as 1
                  {
                    SET_Bit(PORTD, PIN);    //Set it to 1
                  }   
                
                else if(Value == LOW) //If the Value Passed as 0
                  {
                    CLR_Bit(PORTD, PIN);    //Set it to 0
                  }
                break;  //Get out of the Switch Statement
            }
    }
}

u8 DIO_u8GetPinValue(u8 PORT, u8 PIN)                     //Get the PIN Value in the AVR's DIO that Returns unsigned 8-Bits
{
    switch(PORT)    //Probabilities of PORT
    {
        case A:  //Probability #1 : if The PORT's Direction was A
            {
                return GET_Bit(PINA , PIN); //Get PINA's Value
            }

        case B:  //Probability #2 : if The PORT was B
            {
                return GET_Bit(PINB , PIN); //Get PINB's Value
            }
            
        case C:  //Probability #3 : if The PORT was C
            {
                return GET_Bit(PINC , PIN); //Get PINC's Value
            }
            
        case D:  //Probability #4 : if The PORT was D
            {
                return GET_Bit(PIND , PIN); ////Get PIND's Value
            }

        default:
        	{
        		return False;
        	}
    }
}

extern void DIO_vidSetPortDirection(u8 PORT, u8 Dir)   //Assigning The Whole PORT as a Value
{
    switch(PORT)    //Probabilities of PORT
    {
        case A:  //Probability #1 : if The PORT's Direction was A
            {
                DDRA = Dir; //Set DDRA by Dir

                break; //Get out from the Switch Statement
            }

        case B:  //Probability #2 : if The PORT was B
            {
                DDRB = Dir; //Set DDRB by Dir

                break; //Get out from the Switch Statement
            }
            
        case C:  //Probability #3 : if The PORT was C
            {
                DDRC = Dir; //Set DDRC by Dir

                break; //Get out from the Switch Statement
            }
            
        case D:  //Probability #4 : if The PORT was D
            {
                DDRD = Dir; //Set DDRA by Dir

                break; //Get out from the Switch Statement
            }
            
        default:
        	{
        		//Discharge The Whole Directions
        		DDRA = Discharged;
        		DDRB = Discharged;
        		DDRC = Discharged;
        		DDRD = Discharged;

                break; //Get out from the Switch Statement
        	}
    }
}

extern void DIO_vidSetPortValue(u8 PORT, u8 Value)    //Assigning The Whole PORT as a Value
{
    switch(PORT)    //Probabilities of PORT
    {
        case A:  //Probability #1 : if The PORT's Direction was A
            {
                PORTA = Value; //Set PORTA by Value Passed

                break; //Get out from the Switch Statement
            }

        case B:  //Probability #2 : if The PORT was B
            {
                PORTB = Value; //Set PORTB by Value Passed

                break; //Get out from the Switch Statement
            }
            
        case C:  //Probability #3 : if The PORT was C
            {
                PORTC = Value; //Set PORTC by Value Passed

                break; //Get out from the Switch Statement
            }
            
        case D:  //Probability #4 : if The PORT was D
            {
                PORTD = Value; //Set PORTD by Value Passed

                break; //Get out from the Switch Statement
            }
            
        default:
        	{
        		//Discharge The Whole Directions
        		PORTA = Discharged;
        		PORTB = Discharged;
        		PORTC = Discharged;
        		PORTD = Discharged;

                break; //Get out from the Switch Statement
        	}
    }
}
