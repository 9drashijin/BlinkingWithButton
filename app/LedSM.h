#ifndef LedSM_H
#define LedSM_H

#include "State.h"
#include <stdint.h>

typedef struct {
  State state;
  uint32_t time;
} LedState;

#endif // LedSM_H
