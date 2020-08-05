#define _MAIN_C_SRC

//-------------------------MODULES USED-------------------------------------
#include "ledctrl.h"
//-------------------------DEFINITIONS AND MACORS---------------------------



//-------------------------TYPEDEFS AND STRUCTURES--------------------------



//-------------------------PROTOTYPES OF LOCAL FUNCTIONS--------------------



//-------------------------EXPORTED VARIABLES ------------------------------



//-------------------------GLOBAL VARIABLES---------------------------------



//-------------------------EXPORTED FUNCTIONS-------------------------------
int main(void)
{
    ledctrl_init();
    ledctrl_blinkled(5, 2);
    ledctrl_blinkled(4, 3);
    ledctrl_blinkled(3, 4);
    ledctrl_blinkled(2, 5);

    return 0;
}


//-------------------------LOCAL FUNCTIONS----------------------------------
void HardFault_Handler(void)
{
    while(1);
}
