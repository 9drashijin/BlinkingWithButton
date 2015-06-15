#include "LedSM.h"
#include "Message.h"
#include "timer.h"
#include <stdio.h>

void ledInitData(LedData *data){
  data->state = LED_OFF;
}

void ledSM(LedData *data){
  switch(data->state){
  case LED_OFF:
    if(msg == CHANGE_MODE){
      data->state = LED_BLINKING_ON;
      msg = DO_NOTHING;
    }
    break;
    
  case LED_ON:
  if(msg == CHANGE_MODE){
      data->state = LED_OFF;
      msg = DO_NOTHING;
    }
    break;
    
  case LED_BLINKING_ON:
    //if(data->time <= delay()){
      data->state = LED_BLINKING_OFF;
    //}
    if(msg == CHANGE_MODE){
      data->state = LED_ON;
      msg = DO_NOTHING;
    }
    break;
    
  case LED_BLINKING_OFF:
    //if(data->time <= delay()){
      data->state = LED_ON;
    //}
    if(msg == CHANGE_MODE){
      data->state = LED_ON;
      msg = DO_NOTHING;
    }
    break;
    
  default:
    printf("Error: unknown state encountered in LedSM: %d\n",data->state);
    break;
  }
}