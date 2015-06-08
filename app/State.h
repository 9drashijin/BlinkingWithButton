#ifndef State_H
#define State_H

typedef enum {
  INITIAL,
  PRESS,         //1
  RELEASE,       //2
  LED_ON,        //3
  LED_OFF,       //4
  LED_BLINKING_ON,
  LED_BLINKING_OFF,
} State;

#endif // State_H
