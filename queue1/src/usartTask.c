#include "usartTask.h"

#define BUFFER_SIZE 15

char * buffer;
bool transmissionComplete = false;

void vPrintMessages(void * pvParams) {
    uint32_t item;

    while (1) {
        if (xQueueReceive(messageQueue, (void *)&item, 0)) {
            usartSendNumber(item);
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
};

void vLoop(void * pvParams) {
    while (1) {
        static int num = 0;

        if (!xQueueSend(messageQueue, (void *)&num, 10)) {
            usartSendMessage("Queue full");
        }
        num++;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}