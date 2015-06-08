#include "ButtonSM.h"
#include <stdio.h>

void buttonSM(ButtonData *data){
  switch(data->state){
  
    default:
    printf("Error: unknown state encountered in buttomSM: %d\n",data->state);
    break;
  }
}
