#include "FreeRTOS.h"
#include "hwConfig.h"
#include "stm32f10x.h"
#include "task.h"
#include "usartTask.h"

int main() {
    setupClocks();
    setupUartPins();
    setupUsart2();
    xTaskCreate(vUsartTask1, "UsartTask1", 100, NULL, 2, NULL);
    xTaskCreate(vUsartTask2, "UsartTask2", 100, NULL, 1, NULL);
    vTaskStartScheduler();
    while (1) {
    }
}