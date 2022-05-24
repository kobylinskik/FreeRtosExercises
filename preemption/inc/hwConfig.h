#ifndef __HW_CONFIG__
#define __HW_CONFIG__

#include "stm32f10x.h"
#include <stdint.h>

#define USART_BAUD_RATE 0xEA6

void setupClocks();
void setupUartPins();
void setupUsart2();
void vSetupHardware(void);

#endif