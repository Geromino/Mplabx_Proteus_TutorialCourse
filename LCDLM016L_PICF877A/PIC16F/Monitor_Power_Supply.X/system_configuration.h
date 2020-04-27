/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef SYSTEM_CONFIGURATION_H_
#define SYSTEM_CONFIGURATION_H_

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "addtional_string.h"
#include "pin_manager.h"
#include "lcd.h"
#include "config.h"

// TODO Insert appropriate #include <>

#define LEVEL_ACCURECTY_FLOAT_TO_STRING  (2)
#define FLOAT_CASTING_STRING_BUFFER_SIZE (5)
#define LCD_START_POSITION               (0x0)

 
#ifndef   TEST_TOGGLE_LCD
  #define TEST_TOGGLE_LCD   0           
#endif

#ifndef   A2D_TEST
  #define A2D_TEST      1          
#endif






// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation
void System_Test(void);
void A2D_Test_TO_LCD(void);
void Toggle_Test(uint16_t delay);
#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

