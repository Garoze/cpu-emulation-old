#pragma once

#include <cstdint>

struct Registers
{
    std::size_t PC;
    std::size_t SP;
    std::uint16_t A, B;
};
