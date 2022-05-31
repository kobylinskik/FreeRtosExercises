#include "circularBuffer.h"

CircularBuffer_t * cbuf_createBuffer(uint8_t size) {
    CircularBuffer_t * buffer = pvPortMalloc(sizeof(CircularBuffer_t));
    buffer->values = pvPortMalloc(size * sizeof(uint32_t));
    buffer->firstIndex = 0;
    buffer->lastIndex = 0;
    buffer->valueCount = 0;
    buffer->size = size;
    return buffer;
}

void cbuf_add(CircularBuffer_t * buffer, uint32_t value) {
    if (cbuf_isFull(buffer)) {
        usartSendMessage("Buffer full\n");
        return;
    }
    if (!cbuf_isEmpty(buffer)) {
        buffer->lastIndex = (buffer->lastIndex + 1) % buffer->size;
    }
    buffer->values[buffer->lastIndex] = value;
    buffer->valueCount++;
}

uint32_t cbuf_get(CircularBuffer_t * buffer) {
    if (cbuf_isEmpty(buffer)) {
        usartSendMessage("Buffer empty\n");
        return 0;
    }
    uint32_t retVal = buffer->values[buffer->firstIndex];
    if (buffer->firstIndex != buffer->lastIndex) {
        buffer->firstIndex = (buffer->firstIndex + 1) % buffer->size;
    }
    buffer->valueCount--;
    return retVal;
}

bool cbuf_isFull(CircularBuffer_t * buffer) {
    return buffer->firstIndex == (buffer->lastIndex + 1) % buffer->size;
}

bool cbuf_isEmpty(CircularBuffer_t * buffer) {
    return !buffer->valueCount && buffer->firstIndex == buffer->lastIndex;
}
