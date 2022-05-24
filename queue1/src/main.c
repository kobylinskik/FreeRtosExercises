#include "FreeRTOS.h"
#include "hwConfig.h"
#include "stm32f10x.h"
#include "task.h"
#include "usartDriver.h"
#include "usartTask.h"

int main() {
    setupClocks();
    setupUartPins();
    setupUsart2();

    messageQueue = xQueueCreate(MESSAGE_QUEUE_SIZE, sizeof(uint32_t));

    xTaskCreate(vPrintMessages, "printMessages", 100, NULL, 2, NULL);
    xTaskCreate(vLoop, "loop", 100, NULL, 2, NULL);
    vTaskStartScheduler();
    while (1) {
    }
}