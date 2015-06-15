#ifndef Scheduler_H
#define Scheduler_H

#include "taskBlock.h"

extern Tcb *runningTcb;

void taskSwitch();

#endif // Scheduler_H
