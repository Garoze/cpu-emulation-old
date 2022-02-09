#pragma once

#include <cstdint>

enum class Instructions : std::uint16_t
{
    NOP,
    CLC, SLC,
    SHL, SHR,
    AND, BOR, XOR, NOT,
    LDI, LDA, LDR, LDS,
    STA, STR, STS,
    INC, DEC,
    PSH, POP,
    SUB, RET,
    HTL
};
