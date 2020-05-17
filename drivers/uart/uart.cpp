#include <sukos/uart/uart.h>

void SukOS::UART::Write(const char* aString)
{
    uint32_t i = 0;
    char c;
    while((c = aString[i]) != '\0')
    {
        WriteChar(c);
        ++i;
    }
    WriteChar('\r');
}

void SukOS::UART::Write(const char* aString, const uint32_t aLength)
{
    for(uint32_t i = 0; i < aLength; ++i)
    {
        WriteChar(aString[i]);
    }
    WriteChar('\r');
}