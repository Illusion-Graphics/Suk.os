#include <sukos/dma/dma.h>

SukOS::DMA::DMA()
    : myQueueSize(0)
{

}

void SukOS::DMA::Write(volatile unsigned int* anAddress, uint32_t aData, const bool anImmediate)
{
    DMAWriteRequest newWrite;
    newWrite.myAddress = anAddress;
    newWrite.myData = aData;

    myDMAQueue[myQueueSize++] = newWrite;

    // The queue is full or immediate mode requested, flush
    if(myQueueSize == 255 || anImmediate)
    {
        Flush();
    }
}

void SukOS::DMA::Flush()
{
    for(uint8_t i = 0; i < myQueueSize; ++i)
    {
        DMAWriteRequest& request = myDMAQueue[i];
        *request.myAddress = request.myData;
    }

    myQueueSize = 0;
}