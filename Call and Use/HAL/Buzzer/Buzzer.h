/*
 * Buzzer.h
 *
 *  Created on: Feb 10, 2019
 *      Author: Mahmoud Abaza
 */

#ifndef BUZZER_H_	//If it is Not Defined
#define BUZZER_H_	//Define it

//Hardware APIs
extern void Buzzer_vidInitialization(u8 PORT, u8 PIN);			//Function To Set The Direction of The Buzzer
extern void Buzzer_vidScream(u8 PORT, u8 PIN);					//Function To Make a Sound With The Buzzer
extern void Buzzer_vidSilence(u8 PORT, u8 PIN);					//Function To Shut The Buzzer up
extern void Buzzer_vidAlarmSound(u8 PORT, u8 PIN, u16 Delay);	//Function To Setup an Alarm Sound

#endif //Stop
