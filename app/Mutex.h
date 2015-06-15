#ifndef Mutex_H
#define Mutex_H

#include <stdint.h>
#include "taskBlock.h"

//Task Control Block
typedef struct{
  Tcb *owner;
  //List *queue;
}Mutex;

void mutexInit(Mutex *mutex);
void mutexAcquire(Mutex *mutex);
void mutexRelease(Mutex *mutex);

#endif // Mutex_H
