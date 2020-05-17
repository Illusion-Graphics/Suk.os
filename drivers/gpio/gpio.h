#ifndef __GPIO_H
#define __GPIO_H

typedef unsigned char uint8_t;

enum GPIO_Function
{
    GPIO_FUNC_INPUT  = 0b000,
    GPIO_FUNC_OUTPUT = 0b001,
    GPIO_FUNC_ALT_0  = 0b100,
    GPIO_FUNC_ALT_1  = 0b101,
    GPIO_FUNC_ALT_2  = 0b110,
    GPIO_FUNC_ALT_3  = 0b111,
    GPIO_FUNC_ALT_4  = 0b011,
    GPIO_FUNC_ALT_5  = 0b010,

    GPIO_FUNC_CLEAR  = 0b111,
};

void GPIO_SetFunction(const uint8_t aGPIOPin, const enum GPIO_Function aFunction);


enum GPIO_PullUpDown
{
    GPIO_PULLUPDOWN_OFF     = 0b00,
    GPIO_PULLUPDOWN_UP      = 0b01,
    GPIO_PULLUPDOWN_DOWN    = 0b10
};

void GPIO_SetPullUpDown(const uint8_t aGPIOPin, const enum GPIO_PullUpDown aState);

#endif //__GPIO_H