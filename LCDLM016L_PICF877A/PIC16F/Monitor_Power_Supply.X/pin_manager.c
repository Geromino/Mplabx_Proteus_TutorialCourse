/*
 * File:   pin_manager.c
 * Author: zachar.papkov
 *
 * Created on March 24, 2020, 4:02 PM
 */
#include "pin_manager.h"

void PIN_MANAGER_Initialize(void)
{
   
    /** TRISx registers*/
    
ADCON1bits.PCFG = 0b0110;

    TRISE = 0x0E;

    TRISA = 0x1B;

    TRISB = 0xE0;

    TRISC = 0x00;

    TRISD = 0x00;
    
}
