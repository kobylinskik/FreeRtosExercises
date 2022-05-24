#include "usartTasks.h"

void vUsartInputTask(void * pvParams) {
    char usartInputBuffer[USART_BUFFER_SIZE];
    uint32_t responseAddr;

    while (1) {

        usartReadData(usartInputBuffer, USART_BUFFER_SIZE);
        usartSendMessage(usartInputBuffer);
        usartSendMessage("\n\r");

        uint32_t blinkDelay = parseInt(usartInputBuffer);
        char * bufferPtr = usartInputBuffer;
        while (*bufferPtr++ != ' ') {
        }
        uint32_t blinkCount = parseInt(bufferPtr) * 2 + 1;

        if (!xQueueSend(inputQueue, (void *)&blinkDelay, 0)) {
            usartSendMessage("Queue full\n\r");
        }
        if (!xQueueSend(inputQueue, (void *)&blinkCount, 0)) {
            usartSendMessage("Queue full\n\r");
        }

        while (!xQueueReceive(responseQueue, &responseAddr, 100)) {
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
        char * response = (char *)responseAddr;
        usartSendMessage(response);
    }
}

void vUsartResponseTask(void * pvParams) {
    uint32_t blinkDelay = 0;
    uint32_t blinkCount = 0;
    char * responseText = "Blinked!\n\r";
    char * response = pvPortMalloc(11 * sizeof(char));
    for (char * responsePtr = response; *responseText != 0; responsePtr++) {
        *responsePtr = *responseText++;
    }

    while (1) {
        if (blinkDelay != 0 || xQueueReceive(inputQueue, &blinkDelay, 10)) {
            if (xQueueReceive(inputQueue, &blinkCount, 10)) {
                while (--blinkCount) {
                    vToggleLed();
                    vTaskDelay(blinkDelay / portTICK_PERIOD_MS);
                }
                blinkDelay = 0;
                if (!xQueueSend(responseQueue, &response, 0)) {
                    usartSendMessage("Queue full\n\r");
                }
            }
        }

        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void vLedTask(void * pvParams) {
    while (1) {
        vToggleLed();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void vToggleLed(void) {
    if (GPIOA->ODR & (1 << 5)) {
        GPIOA->BSRR |= 1 << 21;
    } else {
        GPIOA->BSRR |= 1 << 5;
    }
}