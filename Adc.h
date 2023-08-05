/* 
 * File:   Adc.h
 * Author: will
 *
 * Created on August 5, 2023, 2:04 PM
 */

#include "p18cxxx.h"
#include <stdint.h>
#include <xc.h>

#ifndef ADC_H
#define	ADC_H

void AdcInit();
unsigned int AdcRead(unsigned char ch);
void AdcTest();

#endif	/* ADC_H */

