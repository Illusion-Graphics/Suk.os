#pragma once
#include <sukos/uart/uart.h>

namespace SukOS
{
    class DMA;

    class MiniUART : public UART
    {
    public:
        MiniUART(DMA& aDMA);

        virtual void Initialize() final;
        virtual void Enable() final;
        virtual void Disable() final;
        virtual void WriteChar(const char aChar) final;

    protected:
        DMA& myDMA;
    };
}