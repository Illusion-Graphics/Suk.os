#pragma once
#include <sukos/sukos.h>

namespace SukOS
{
    class UART
    {
    public:
        UART()
            : myEnabled(false)
        {}

        enum Baudrate
        {
            Baud_2400,
            Baud_4800,
            Baud_9600,
            Baud_14400,
            Baud_19200
        };

        virtual void Initialize() = 0;
        virtual void Enable() = 0;
        virtual void Disable() = 0;
        virtual void WriteChar(const char aChar) = 0;

        void Write(const char* aString);
        void Write(const char* aString, const uint32_t aLength);

    protected:
        bool myEnabled;
    };
}