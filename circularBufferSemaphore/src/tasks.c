#include "tasks.h"

void taskAdd(void * params) {
    uint32_t num = ((uint32_t *)params)[0];
    uint8_t timesToPrint = ((uint32_t *)params)[1];
    while (1) {
        if (xSemaphoreGive(semaphore)) {
            while (!xSemaphoreTake(mutex, 100)) {
            }
            cbuf_add(buffer, num);
            xSemaphoreGive(mutex);
            if (!(--timesToPrint)) {
                vTaskDelete(NULL);
            }
            vTaskDelay(500 / portTICK_PERIOD_MS);
        }
    }
}

void taskGet(void * params) {
    while (1) {
        if (xSemaphoreTake(semaphore, 100)) {
            while (!xSemaphoreTake(mutex, 100)) {
            }
            uint32_t num = cbuf_get(buffer);
            usartSendNumber(num);
            usartSendMessage("\r\n");
            xSemaphoreGive(mutex);
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
    }
}