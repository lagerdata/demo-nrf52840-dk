#define _TICKS_C_SRC

//-------------------------MODULES USED-------------------------------------
#include "system_nrf52840.h"
#include "nrf52840.h"

//-------------------------DEFINITIONS AND MACORS---------------------------



//-------------------------TYPEDEFS AND STRUCTURES--------------------------



//-------------------------PROTOTYPES OF LOCAL FUNCTIONS--------------------



//-------------------------EXPORTED VARIABLES ------------------------------



//-------------------------GLOBAL VARIABLES---------------------------------
static uint32_t g_ms_cnt;


//-------------------------EXPORTED FUNCTIONS-------------------------------
void ticks_init(void)
{
    g_ms_cnt = 0;
    SysTick_Config(SystemCoreClock / 1000);
    NVIC_EnableIRQ(SysTick_IRQn);
}

void ticks_delay(uint32_t ms)
{
    uint32_t t = g_ms_cnt;
    while((t+ms) > g_ms_cnt){};
}

uint32_t ticks_getCount(void)
{
    return g_ms_cnt;
}

void SysTick_Handler(void)
{
    g_ms_cnt++;
}


//-------------------------LOCAL FUNCTIONS----------------------------------
