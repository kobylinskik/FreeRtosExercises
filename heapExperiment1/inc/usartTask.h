#ifndef __USART_TASK__
#define __USART_TASK__

#include "FreeRTOS.h"
#include "stm32f10x.h"
#include "task.h"
#include "usartDriver.h"
#include <stdbool.h>

void vUsartTaskRead(void * pvParams);
void vUsartTaskWrite(void * pvParams);

#endif