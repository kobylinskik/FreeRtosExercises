#include "stringUtils.h"

uint32_t stringLength(char * str) {
    uint32_t result = 0;
    while (*(str++)) {
        result++;
    }
    return result;
}

uint32_t parseInt(char * str) {
    uint32_t result = 0;
    while (*str != ' ' && *str != '\r' && *str != 0) {
        result *= 10;
        result += (*str - '0');
        str++;
    }
    return result;
}