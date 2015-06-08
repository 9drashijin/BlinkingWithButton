#include "ButtonSM.h"
#include "Message.h"
#include "button.h"
#include <stdio.h>

void buttonInitData(ButtonData *data){
  data->state = RELEASE;
}

void buttonSM(ButtonData *data){
  switch(data->state){
  case RELEASE:
    if(isButtonPressed() == true){ //mock button
        msg = CHANGE_MODE; // Pass the message to LED
        data->state = PRESS;
      }
      break;
  
  case PRESS:
    if(isButtonPressed() == false){ //mock button
        msg = DO_NOTHING; // Pass the message to LED
        data->state = RELEASE;
      }
    break;
  
  default:
    printf("Error: unknown state encountered in buttomSM: %d\n",data->state);
    break;
  }
}
