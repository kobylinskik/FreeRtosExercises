#ifndef __USART_TASK__
#define __USART_TASK__

#include "FreeRTOS.h"
#include "queue.h"
#include "stm32f10x.h"
#include "task.h"
#include "usartDriver.h"
#include <stdbool.h>

#define MESSAGE_QUEUE_SIZE 5

QueueHandle_t messageQueue;

void vPrintMessages(void * pvParams);
void vLoop(void * pvParams);

#endif