#ifndef __USART_DRIVER__
#define __USART_DRIVER__

#include "stm32f10x.h"
#include <stdint.h>

void usartSendMessage(char * message);
void usartSendNumber(uint32_t num);
void usartReadData(char * bufferPtr, uint8_t bufferSize);
uint8_t usartGetChar(void);
void usartSendChar(uint8_t character);

#endif