#include "unity.h"
#include "LedSM.h"
#include "ButtonSM.h"
#include "Message.h"
#include "mock_button.h"

void setUp(void){}
void tearDown(void){}

void test_module_generator_needs_to_be_implemented(void){
  LedData ledData;
  ButtonData buttonData;
  
  ledInitData(&ledData);
  buttonInitData(&buttonData);
  
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
  
  isButtonPressed_ExpectAndReturn(false);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,RELEASE);
  
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
  
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,PRESS);
  
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_ON);
  
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_OFF);
  
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_ON);
  
	isButtonPressed_ExpectAndReturn(false);
	buttonSM(&buttonData);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_OFF);
  
	isButtonPressed_ExpectAndReturn(false);
	buttonSM(&buttonData);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_ON);
  
	isButtonPressed_ExpectAndReturn(true);
	buttonSM(&buttonData);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_ON);
  
	isButtonPressed_ExpectAndReturn(false);
	buttonSM(&buttonData);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_ON);
  
	isButtonPressed_ExpectAndReturn(true);
	buttonSM(&buttonData);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
}

void test_init_led(){
  LedData ledData;
  
  ledInitData(&ledData);
  
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
}

void test_init_led_for_msg_changing_mode(){
  LedData ledData;
  
  ledInitData(&ledData);
  msg = CHANGE_MODE;
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_ON);
}

void test_led_with_blinking_for_msg_DO_NOTHING(void){
  LedData ledData;
  
  ledInitData(&ledData);
  msg = CHANGE_MODE;
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_ON);
  
  msg = DO_NOTHING;
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_OFF);
}

void test_led_with_blinking_for_msg_CHANGE_MODE(void){
  LedData ledData;
  
  ledInitData(&ledData);
  msg = CHANGE_MODE;
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_ON);
  
  msg = CHANGE_MODE;
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_ON);
}