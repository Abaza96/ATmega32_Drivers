/*
 * Interrupt.h
 *
 *  Created on: Feb 2, 2019
 *      Author: Mahmoud Abaza
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define __INTR_ATTRS used, externally_visible
void __vector_1 (void) __attribute__((signal,__INTR_ATTRS));

void __vector_1 (void)
{
	DIO_vidWritePinValue(D, PIN0, LOW);

	_delay_ms(mSec);
}

#endif /* INTERRUPT_H_ */
