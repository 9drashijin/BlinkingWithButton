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
}
