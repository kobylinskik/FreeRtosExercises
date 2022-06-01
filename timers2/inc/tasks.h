#ifndef __USART_TASK__
#define __USART_TASK__

#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#include "stm32f10x.h"
#include "task.h"
#include "timers.h"
#include "usartDriver.h"

TimerHandle_t ledTimer;

void ledTimerCallback(TimerHandle_t timer);
void usartTask(void * params);

#endif