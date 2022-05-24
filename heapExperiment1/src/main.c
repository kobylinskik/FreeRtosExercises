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

    /*char * buffer = pvPortMalloc(15);
    uint8_t * bufferSize;
    *bufferSize = 15;
    void ** params = pvPortMalloc(2 * sizeof(void *));
    params[0] = (void *)buffer;
    params[1] = (void *)bufferSize;*/

    xTaskCreate(vUsartTaskRead, "UsartTaskRead", 100, NULL, 2, NULL);
    xTaskCreate(vUsartTaskWrite, "UsartTaskWrite", 100, NULL, 2, NULL);
    vTaskStartScheduler();
    while (1) {
    }
}