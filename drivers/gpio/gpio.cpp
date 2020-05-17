#include "gpio.h"
#include "registers.h"

void GPIO_SetFunction(const uint8_t aGPIOPin, const enum GPIO_Function aFunction)
{
    volatile unsigned int* functionRegisterList[] = {REG_GPFSEL0, REG_GPFSEL1, REG_GPFSEL2, REG_GPFSEL3, REG_GPFSEL4, REG_GPFSEL5};
    volatile unsigned int* functionRegister = functionRegisterList[aGPIOPin / 10u];
    uint8_t GPIOShift = (aGPIOPin % 10) * 3;

    *functionRegister &= ~(GPIO_FUNC_CLEAR << GPIOShift);
    *functionRegister |= (aFunction << GPIOShift);
}

void SleepCycle(const unsigned int aCycle)
{
    for(uint8_t i = 0; i < aCycle; ++i)
    {
        __asm("nop");
    }
}

void GPIO_SetPullUpDown(const uint8_t aGPIOPin, const enum GPIO_PullUpDown aState)
{
    const uint8_t minHoldState = 150;

    uint8_t registerIdx = aGPIOPin / 32u;

    // Write GPPUD
    *REG_GPPUD = aState;
    
    // Wait 150 cycles to set-up the control signal
    SleepCycle(minHoldState);

    // Write clock signal to GPPUDCLK0/1
    if (registerIdx == 0)
    {
        *REG_GPPUDCLK0 = (1 << aGPIOPin);
    }
    else if (registerIdx == 1)
    {
        *REG_GPPUDCLK1 = (1 << (aGPIOPin - 32));
    }

    // Wait 150 cycles, hold time for the control signal
    SleepCycle(minHoldState);

    // Write to GPPUD
    *REG_GPPUD = 0;

    // Write to GPPUDCLK0/1 to remove the clock
    *REG_GPPUDCLK0 = 0;
    *REG_GPPUDCLK1 = 0;
}