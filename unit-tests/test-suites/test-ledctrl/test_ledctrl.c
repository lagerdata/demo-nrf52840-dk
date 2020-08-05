#define _TEST_EXAMPLE_C_SRC

//-------------------------MODULES USED-------------------------------------
#include "nrf_delay.h"
#include "nrf_systick.h"
#include "unity.h"
#include "ledctrl.h"
#include "test_ledctrl.h"

//-------------------------DEFINITIONS AND MACORS---------------------------



//-------------------------TYPEDEFS AND STRUCTURES--------------------------



//-------------------------PROTOTYPES OF LOCAL FUNCTIONS--------------------



//-------------------------EXPORTED VARIABLES ------------------------------



//-------------------------GLOBAL VARIABLES---------------------------------



//-------------------------EXPORTED FUNCTIONS-------------------------------
void test_check_min_number_blinks(void)
{
	uint32_t num_blink = 0;
	uint32_t s_blink_duration = 2;
	int32_t ret = ledctrl_blinkled(num_blink, s_blink_duration);
	TEST_ASSERT_EQUAL_INT(LEDCTRL_ERR, ret);
	num_blink = 1;
	ret = ledctrl_blinkled(num_blink, s_blink_duration);
	TEST_ASSERT_EQUAL_INT(LEDCTRL_OK, ret);
	num_blink = 2;
	ret = ledctrl_blinkled(num_blink, s_blink_duration);
	TEST_ASSERT_EQUAL_INT(LEDCTRL_OK, ret);
}

void test_check_max_number_blinks(void)
{
	uint32_t num_blink = 10;
	uint32_t s_blink_duration = 2;
	int32_t ret = ledctrl_blinkled(num_blink, s_blink_duration);
	TEST_ASSERT_EQUAL_INT(LEDCTRL_ERR, ret);
	num_blink = 9;
	ret = ledctrl_blinkled(num_blink, s_blink_duration);
	TEST_ASSERT_EQUAL_INT(LEDCTRL_OK, ret);
	num_blink = 8;
	ret = ledctrl_blinkled(num_blink, s_blink_duration);
	TEST_ASSERT_EQUAL_INT(LEDCTRL_OK, ret);
}

void test_check_min_blink_duration(void)
{
	uint32_t num_blink = 2;
	uint32_t s_blink_duration = 0;
	int32_t ret = ledctrl_blinkled(num_blink, s_blink_duration);
	TEST_ASSERT_EQUAL_INT(LEDCTRL_ERR, ret);
	s_blink_duration = 1;
	ret = ledctrl_blinkled(num_blink, s_blink_duration);
	TEST_ASSERT_EQUAL_INT(LEDCTRL_ERR, ret);
	s_blink_duration = 2;
	ret = ledctrl_blinkled(num_blink, s_blink_duration);
	TEST_ASSERT_EQUAL_INT(LEDCTRL_OK, ret);
}

void test_check_max_blink_duration(void)
{
	uint32_t num_blink = 2;
	uint32_t s_blink_duration = 5000;
	int32_t ret = ledctrl_blinkled(num_blink, s_blink_duration);
	TEST_ASSERT_EQUAL_INT(LEDCTRL_ERR, ret);
	s_blink_duration = 4999;
	ret = ledctrl_blinkled(num_blink, s_blink_duration);
	TEST_ASSERT_EQUAL_INT(LEDCTRL_OK, ret);
	s_blink_duration = 4998;
	ret = ledctrl_blinkled(num_blink, s_blink_duration);
	TEST_ASSERT_EQUAL_INT(LEDCTRL_OK, ret);
}

void test_total_blink_length(void)
{

	uint32_t blink_duration = 500;
	for(int i=1;i<5;i++){
        uint32_t t = nrf_systick_val_get();
		int32_t ret = ledctrl_blinkled(i, blink_duration);
		TEST_ASSERT_EQUAL_INT(LEDCTRL_OK, ret);
		TEST_ASSERT_GREATER_THAN_UINT32(i*blink_duration - 50, nrf_systick_val_get() - t);
        TEST_ASSERT_LESS_THAN_UINT32(i*blink_duration + 50, nrf_systick_val_get() - t);
	}

}
//-------------------------LOCAL FUNCTIONS----------------------------------
