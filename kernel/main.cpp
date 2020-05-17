#include <sukos/sukos.h>

#include "drivers/gpio/gpio.h"
#include <sukos/uart/mini_uart.h>
#include <sukos/dma/dma.h>

#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif
void kernel_main(uint64_t dtb_ptr32, uint64_t x1, uint64_t x2, uint64_t x3)
{
    // Set the mini uart ports
    GPIO_SetFunction(14, GPIO_FUNC_ALT_5);
    GPIO_SetFunction(15, GPIO_FUNC_ALT_5);
    // GPIO_SetFunction(16, GPIO_FUNC_ALT_5);
    // GPIO_SetFunction(17, GPIO_FUNC_ALT_5);

    GPIO_SetPullUpDown(14, GPIO_PULLUPDOWN_OFF);
    GPIO_SetPullUpDown(15, GPIO_PULLUPDOWN_OFF);

    SukOS::DMA dma;

    SukOS::MiniUART miniUart(dma);

    miniUart.Initialize();
    miniUart.Enable();

    miniUart.Write("Suk.OS - Single Unified Kernel Operating System");
    miniUart.Write("=====                V 0.1                =====");
    // miniUart.WriteChar()

    while(1){}
}