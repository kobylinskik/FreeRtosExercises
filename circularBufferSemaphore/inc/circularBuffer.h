#ifndef __CIRCULAR_BUFFER__
#define __CIRCULAR_BUFFER__

#include "FreeRTOS.h"
#include "usartDriver.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct {
    uint32_t * values;
    uint8_t size;
    uint8_t firstIndex;
    uint8_t lastIndex;
    uint8_t valueCount;
} CircularBuffer_t;

CircularBuffer_t * cbuf_createBuffer(uint8_t size);
void cbuf_add(CircularBuffer_t * buffer, uint32_t value);
uint32_t cbuf_get(CircularBuffer_t * buffer);
bool cbuf_isFull(CircularBuffer_t * buffer);
bool cbuf_isEmpty(CircularBuffer_t * buffer);

#endif