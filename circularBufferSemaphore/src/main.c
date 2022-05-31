#include "FreeRTOS.h"
#include "hwConfig.h"
#include "semphr.h"
#include "stm32f10x.h"
#include "task.h"
#include "tasks.h"
#include "usartDriver.h"

uint32_t params[5][2];

int main() {
    setupClocks();
    setupUartPins();
    setupUsart2();

    buffer = cbuf_createBuffer(5);
    semaphore = xSemaphoreCreateCounting(5, 0);
    mutex = xSemaphoreCreateMutex();

    for (uint8_t i = 0; i < 5; i++) {
        params[i][0] = i;
        params[i][1] = 3;
    }

    xTaskCreate(taskAdd, "taskAdd0", 200, (void *)params[0], 1, NULL);
    xTaskCreate(taskAdd, "taskAdd1", 200, (void *)params[1], 1, NULL);
    xTaskCreate(taskAdd, "taskAdd2", 200, (void *)params[2], 1, NULL);
    xTaskCreate(taskAdd, "taskAdd3", 200, (void *)params[3], 1, NULL);
    xTaskCreate(taskAdd, "taskAdd4", 200, (void *)params[4], 1, NULL);
    xTaskCreate(taskGet, "getTask0", 200, NULL, 1, NULL);
    xTaskCreate(taskGet, "getTask1", 200, NULL, 1, NULL);
    vTaskStartScheduler();
    while (1) {
    }
}