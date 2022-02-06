#pragma once

#include <cstdint>

struct Flags
{
    bool running;
    std::uint8_t N : 1;
    std::uint8_t Z : 1;
    std::uint8_t C : 1;
    std::uint8_t V : 1;
};
