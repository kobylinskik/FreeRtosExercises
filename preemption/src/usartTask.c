#include "usartTask.h"

void vUsartTask1(void * pvParams) {
    while (1) {
        while (!(USART2->SR & (1 << 7))) {
        }
        USART2->DR = '*';
        vTaskDelay(100);
    }
}

void vUsartTask2(void * pvParams) {
    char * message = "This is a test message\n";
    while (1) {
        for (int i = 0; message[i] != 0; i++) {
            while (!(USART2->SR & (1 << 7))) {
            }
            USART2->DR = message[i];
        }
        vTaskDelay(100);
    }
}