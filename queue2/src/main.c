#include "FreeRTOS.h"
#include "hwConfig.h"
#include "queue.h"
#include "stm32f10x.h"
#include "task.h"
#include "usartDriver.h"
#include "usartTasks.h"

int main() {
    setupClocks();
    setupUartPins();
    setupUsart2();
    setupLedPin();

    inputQueue = xQueueCreate(INPUT_QUEUE_SIZE, sizeof(uint32_t));
    responseQueue = xQueueCreate(RESPONSE_QUEUE_SIZE, sizeof(uint32_t));

    xTaskCreate(vUsartInputTask, "usartInputTask", 200, NULL, 2, NULL);
    xTaskCreate(vUsartResponseTask, "usartResponseTask", 200, NULL, 2, NULL);
    vTaskStartScheduler();
    while (1) {
    }
}