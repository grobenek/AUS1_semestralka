#pragma once

#include <chrono>

namespace structures
{
    using byte = unsigned char;
    using DurationType = std::chrono::nanoseconds;

    template<typename D>
    const char* duration_name()
    {
        if (std::is_same<D, std::chrono::nanoseconds>::value)
        {
            return "nanoseconds";
        }
        else if (std::is_same<D, std::chrono::microseconds>::value)
        {
            return "microseconds";
        }
        else if (std::is_same<D, std::chrono::milliseconds>::value)
        {
            return "milliseconds";
        }
        else if (std::is_same<D, std::chrono::seconds>::value)
        {
            return "seconds";
        }
        else if (std::is_same<D, std::chrono::minutes>::value)
        {
            return "minutes";
        }
        else if (std::is_same<D, std::chrono::hours>::value)
        {
            return "hours";
        }
        else
        {
            return "<unknown duration type>";
        }
    }
}