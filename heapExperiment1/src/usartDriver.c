#include "usartDriver.h"

void usartSendMessage(char * message) {
    while (*message) {
        while (!(USART2->SR & (1 << 7))) {
        }
        USART2->DR = *message++;
    }
};

void usartSendNumber(uint32_t num) {
    uint8_t digits = 1;
    uint32_t digitsTest = 1;
    while (num > digitsTest * 10) {
        digits++;
        digitsTest *= 10;
    }

    uint8_t charToSend;
    uint32_t digit;
    while (digits--) {
        digit = num;
        num = num % digitsTest;
        digit -= num;
        digit /= digitsTest;
        digitsTest /= 10;

        charToSend = '0' + digit;

        while (!(USART2->SR & (1 << 7))) {
        }
        USART2->DR = charToSend;
    }
};

void usartReadData(char * bufferPtr, uint8_t bufferSize) {
    do {
        while (!(USART2->SR & (1 << 5))) {
        }
        *bufferPtr = USART2->DR;
    } while (*bufferPtr++ != '\r' && bufferSize--);
    *bufferPtr = 0;
};