#ifndef __USART_TASK__
#define __USART_TASK__

#include "FreeRTOS.h"
#include "queue.h"
#include "stm32f10x.h"
#include "stringUtils.h"
#include "task.h"
#include "usartDriver.h"

#define INPUT_QUEUE_SIZE 5
#define RESPONSE_QUEUE_SIZE 5
#define USART_BUFFER_SIZE 40

QueueHandle_t inputQueue;
QueueHandle_t responseQueue;

void vUsartInputTask(void * pvParams);
void vUsartResponseTask(void * pvParams);
void vLedTask(void * pvParams);
void vToggleLed(void);

#endif