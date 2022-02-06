#pragma once

#include <cstdint>

enum class Instructions : std::uint16_t
{
    NOP,
    CLC, SLC,
    AND, BOR, XOR, NOT,
    SHL, SHR,
    LDI, LDA, LDR, LDS,
    STA, STR, STS,
    INC, DEC,
    PSH, POP,
    SUB, RET,
    HTL
};
