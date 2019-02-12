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


#endif  //Stop Right There