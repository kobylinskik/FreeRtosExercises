#ifndef __USART_TASK__
#define __USART_TASK__

#include "FreeRTOS.h"
#include "stm32f10x.h"
#include "task.h"

void vUsartTask1(void * pvParams);
void vUsartTask2(void * pvParams);

#endif