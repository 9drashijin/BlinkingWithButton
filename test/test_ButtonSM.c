#include "unity.h"
#include "ButtonSM.h"
#include "LedSM.h"
#include "Message.h"
#include "mock_button.h"

void setUp(void){}
void tearDown(void){}

void test_buttonPress_when_not_in_state_PRESS(void){
  LedData ledData;
  ButtonData buttonData;
  
  ledInitData(&ledData);
  buttonInitData(&buttonData);
  
  isButtonPressed_ExpectAndReturn(false);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,RELEASE);
  
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,PRESS);
}
void test_buttonPress_when_in_state_PRESS(void){
  LedData ledData;
  ButtonData buttonData;
  
  ledInitData(&ledData);
  buttonInitData(&buttonData);
  
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,PRESS);
}

void test_buttonPress_when_for_PRESS_and_RELEASE_State(void){
  LedData ledData;
  ButtonData buttonData;
  
  ledInitData(&ledData);
  buttonInitData(&buttonData);
  
  isButtonPressed_ExpectAndReturn(false);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,RELEASE);
  
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,PRESS);
}

void test_buttonPress_when_for_PRESS_State_multiple_time(void){
  LedData ledData;
  ButtonData buttonData;
  
  ledInitData(&ledData);
  buttonInitData(&buttonData);
  
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,PRESS);
  
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,PRESS);
  
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,PRESS);
}

void test_buttonPress_when_for_RELEASE_State_multiple_time(void){
  LedData ledData;
  ButtonData buttonData;
  
  ledInitData(&ledData);
  buttonInitData(&buttonData);
  
  isButtonPressed_ExpectAndReturn(false);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,RELEASE);
  
  isButtonPressed_ExpectAndReturn(false);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,RELEASE);
  
  isButtonPressed_ExpectAndReturn(false);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,RELEASE);
}

void test_buttonPress_when_for_PRESS_and_RELEASE_State_for_multiple_time(void){
  LedData ledData;
  ButtonData buttonData;
  
  ledInitData(&ledData);
  buttonInitData(&buttonData);
  
  isButtonPressed_ExpectAndReturn(false);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,RELEASE);
  
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,PRESS);
  
  isButtonPressed_ExpectAndReturn(false);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,RELEASE);
  
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,PRESS);
  
  isButtonPressed_ExpectAndReturn(false);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,RELEASE);
  
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,PRESS);
}