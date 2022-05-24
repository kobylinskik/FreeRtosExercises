#include "usartTask.h"

#define BUFFER_SIZE 15
char * buffer;
bool transmissionComplete = false;

void vUsartTaskRead(void * pvParams) {
    while (1) {
        buffer = pvPortMalloc(BUFFER_SIZE);
        usartReadData(buffer, BUFFER_SIZE);
        transmissionComplete = true;
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
};
void vUsartTaskWrite(void * pvParams) {
    while (1) {
        if (transmissionComplete) {
            usartSendMessage(buffer);
            vPortFree(buffer);
            transmissionComplete = false;
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
};

void vUsartTask1(void * pvParams) {
    char * usartMessageHWM = "High water mark (words):\n";
    char * usartMessageBeforeMalloc = "Heap before malloc (bytes):\n";
    char * usartMessageAfterMalloc = "Heap after malloc (bytes):\n";
    char * lineBreakMessage = "\n\r";

    while (1) {
        usartSendMessage(usartMessageHWM);
        usartSendNumber(uxTaskGetStackHighWaterMark(NULL));
        usartSendMessage(lineBreakMessage);

        usartSendMessage(usartMessageBeforeMalloc);
        usartSendNumber(xPortGetFreeHeapSize());
        usartSendMessage(lineBreakMessage);

        int * ptr = pvPortMalloc(1024 * sizeof(int));

        for (int i = 0; i < 1024; i++) {
            ptr[i] = 3;
        }

        usartSendMessage(usartMessageAfterMalloc);
        usartSendNumber(xPortGetFreeHeapSize());
        usartSendMessage(lineBreakMessage);

        vPortFree(ptr);

        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}