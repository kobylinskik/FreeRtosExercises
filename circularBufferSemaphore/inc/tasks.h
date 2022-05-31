#ifndef __USART_TASK__
#define __USART_TASK__

#include "FreeRTOS.h"
#include "circularBuffer.h"
#include "queue.h"
#include "semphr.h"
#include "stm32f10x.h"
#include "task.h"
#include "usartDriver.h"

CircularBuffer_t * buffer;
SemaphoreHandle_t semaphore;
SemaphoreHandle_t mutex;

void taskAdd(void * params);
void taskGet(void * params);

#endif