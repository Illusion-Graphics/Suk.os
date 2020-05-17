#include <sukos/uart/mini_uart.h>
#include <sukos/dma/dma.h>

#include "../drivers/gpio/registers.h"

namespace MiniUART_private
{
    #define AUX_ENABLE      ((volatile unsigned int*)(MMIO_BASE+0x00215004))
    #define AUX_MU_IO       ((volatile unsigned int*)(MMIO_BASE+0x00215040))
    #define AUX_MU_IER      ((volatile unsigned int*)(MMIO_BASE+0x00215044))
    #define AUX_MU_IIR      ((volatile unsigned int*)(MMIO_BASE+0x00215048))
    #define AUX_MU_LCR      ((volatile unsigned int*)(MMIO_BASE+0x0021504C))
    #define AUX_MU_MCR      ((volatile unsigned int*)(MMIO_BASE+0x00215050))
    #define AUX_MU_LSR      ((volatile unsigned int*)(MMIO_BASE+0x00215054))
    #define AUX_MU_MSR      ((volatile unsigned int*)(MMIO_BASE+0x00215058))
    #define AUX_MU_SCRATCH  ((volatile unsigned int*)(MMIO_BASE+0x0021505C))
    #define AUX_MU_CNTL     ((volatile unsigned int*)(MMIO_BASE+0x00215060))
    #define AUX_MU_STAT     ((volatile unsigned int*)(MMIO_BASE+0x00215064))
    #define AUX_MU_BAUD     ((volatile unsigned int*)(MMIO_BASE+0x00215068))
}

SukOS::MiniUART::MiniUART(DMA& aDMA)
    : UART()
    , myDMA(aDMA)
{

}

void SukOS::MiniUART::Initialize()
{
    Disable();

    myDMA.Write(REG_AUX_ENABLES, 1);
    myDMA.Write(REG_AUX_MU_LCR_REG, 3);
    myDMA.Write(REG_AUX_MU_MCR_REG, 0);
    myDMA.Write(REG_AUX_MU_IER_REG, 0);
    myDMA.Write(REG_AUX_MU_IIR_REG, 0x06);
    myDMA.Write(REG_AUX_MU_BAUD_REG, 270);

    myDMA.Flush();
}

void SukOS::MiniUART::Enable()
{
    myDMA.Write(REG_AUX_MU_CNTL_REG, 3, true);
    myEnabled = true;
}

void SukOS::MiniUART::Disable()
{
    myDMA.Write(REG_AUX_MU_CNTL_REG, 0, true);
    myEnabled = false;
}

void SukOS::MiniUART::WriteChar(const char aChar)
{
    if(!myEnabled)
    {
        return;
    }

    do
    {
        asm volatile("nop");
    } while (!(*REG_AUX_MU_LSR_REG & 0x20));
    myDMA.Write(REG_AUX_MU_IO_REG, aChar, true);
}