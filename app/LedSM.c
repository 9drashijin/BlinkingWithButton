#include "LedSM.h"
#include <stdio.h>

void buttonSM(LedState *data){
  switch(data->state){
  
    default:
    printf("Error: unknown state encountered in LedSM: %d\n",data->state);
    break;
  }
}