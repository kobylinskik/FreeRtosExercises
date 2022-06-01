#include "tasks.h"

void ledTimerCallback(TimerHandle_t xTimer) {
    GPIOA->ODR &= ~(1 << 5);
}

void usartTask(void * params) {
    while (1) {
        uint8_t character = usartGetChar();
        if (character) {
            usartSendChar(character);
            GPIOA->ODR |= 1 << 5;
            xTimerStart(ledTimer, portMAX_DELAY);
        }
    }
}