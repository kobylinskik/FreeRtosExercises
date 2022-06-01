#include "FreeRTOS.h"
#include "hwConfig.h"
#include "semphr.h"
#include "stm32f10x.h"
#include "task.h"
#include "tasks.h"
#include "usartDriver.h"

int main() {
    setupClocks();
    setupUartPins();
    setupUsart2();
    setupLedPin();

    ledTimer = xTimerCreate("LED timer", 2000 / portTICK_PERIOD_MS, pdFALSE, (void *)0, ledTimerCallback);

    xTaskCreate(usartTask, "usartTimer", 200, NULL, 1, NULL);
    vTaskStartScheduler();
    while (1) {
    }
}
