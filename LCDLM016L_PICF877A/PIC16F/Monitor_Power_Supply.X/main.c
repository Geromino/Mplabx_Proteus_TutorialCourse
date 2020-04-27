#include "system_configuration.h"

void main(void) {

    //initialize system 
    PIN_MANAGER_Initialize();
    lcd_start();
    while (1) {
        System_Test();
    }
    return;
}
