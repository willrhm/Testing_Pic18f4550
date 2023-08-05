#include "Adc.h"
#include <stdio.h>
#include <stdlib.h>

void AdcInit()
{
    /*PIN A0 AS A ANALOGIC*/
    ADCON1bits.PCFG0 = 0;
    ADCON1bits.PCFG1 = 1;
    ADCON1bits.PCFG2 = 1;
    ADCON1bits.PCFG3 = 1;
    /*REFERENCE*/
    ADCON1bits.VCFG0 = 0;   //VDD
    ADCON1bits.VCFG1 = 0;   //VSS
    /*DISABLE ADC AND SELECT CHANNEL 0*/
    ADCON0 = 0;
    /*CONFIGURATION ADC*/
    /*FOSC = 6*/
    ADCON2bits.ADCS = 1;
    /*TAD = 4*/
    ADCON2bits.ACQT = 2;
    /*RIGHT JUSTIFICATION*/
    ADCON2bits.ADFM = 1;
}

unsigned int AdcRead(unsigned char ch)
{
    if(ch > 13)return 0;
    ADCON0 = 0;
    ADCON0 = (ch<<2);
    ADCON0bits.ADON = 1;
    ADCON0bits.GO_DONE = 1;
    while(ADCON0bits.GO_DONE == 1);
    ADCON0bits.ADON = 0;
    return ADRES;
}

void AdcTest()
{
    //Here we are implementig testing functions for ADC
}
