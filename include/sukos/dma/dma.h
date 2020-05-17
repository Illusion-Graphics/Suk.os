#pragma once
#include <sukos/sukos.h>

namespace SukOS
{
    class DMA
    {
    public:
        DMA();

        void Write(volatile unsigned int* anAddress, uint32_t aData, const bool anImmediate = false);

        // Flush all the pending IO operation
        void Flush();

    protected:
        struct DMAWriteRequest
        {
            volatile unsigned int* myAddress;
            uint32_t myData;
        };
        DMAWriteRequest myDMAQueue[256];
        uint8_t myQueueSize;
    };
}