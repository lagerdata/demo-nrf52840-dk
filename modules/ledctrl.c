#define _LEDCTRL_C_SRC

//-------------------------MODULES USED-------------------------------------
#include "nrf_gpio.h"
#include "ticks.h"
#include "ledctrl.h"


//-------------------------DEFINITIONS AND MACORS---------------------------
#define MIN_NUM_BLINKS 1
#define MAX_NUM_BLINKS 9
#define MIN_BLINK_DURATION 1
#define MAX_BLINK_DURATION 4999

#define LED_PIN 13
//-------------------------TYPEDEFS AND STRUCTURES--------------------------



//-------------------------PROTOTYPES OF LOCAL FUNCTIONS--------------------



//-------------------------EXPORTED VARIABLES ------------------------------



//-------------------------GLOBAL VARIABLES---------------------------------



//-------------------------EXPORTED FUNCTIONS-------------------------------
int32_t ledctrl_init(void)
{
    nrf_gpio_cfg_output(LED_PIN);
    nrf_gpio_pin_set(LED_PIN);
    ticks_init();

    return LEDCTRL_OK;
}

int32_t ledctrl_blinkled(uint32_t num_blink, uint32_t ms_blink_duration)
{
	if(num_blink < MIN_NUM_BLINKS){
		return LEDCTRL_ERR;
	}
	if(num_blink > MAX_NUM_BLINKS){
		return LEDCTRL_ERR;
	}
	if(ms_blink_duration < MIN_BLINK_DURATION){
		return LEDCTRL_ERR;
	}
	if(ms_blink_duration > MAX_BLINK_DURATION){
		return LEDCTRL_ERR;
	}
	ms_blink_duration /=2;

	ledctrl_onoff(false);
	for(int i=0;i<(num_blink);i++){
		ledctrl_onoff(true);
        ticks_delay(ms_blink_duration);
		ledctrl_onoff(false);
        ticks_delay(ms_blink_duration);
	}

	return LEDCTRL_OK;
}


int32_t ledctrl_onoff(bool led_on)
{

	if(led_on){
        nrf_gpio_pin_clear(LED_PIN);
	}else{
        nrf_gpio_pin_set(LED_PIN);
	}

	return LEDCTRL_OK;
}



//-------------------------LOCAL FUNCTIONS----------------------------------
