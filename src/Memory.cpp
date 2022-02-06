#include <assert.h>
#include <algorithm>

#include <cstdio>

#include "include/Memory/Memory.hpp"

#define isValidRange(n) (n > 0 && n < data.size())
#define checkValidRange(n) assert(n > 0 && n < data.size())

Memory::Memory()
{
    std::fill(data.begin(), data.end(), 0);
}

std::uint8_t Memory::readByte(std::uint16_t address)
{
    if (isValidRange(address))
        return data.at(address);
    else
        return 0;
}

std::uint16_t Memory::readWord(std::uint16_t address)
{
    if (isValidRange(address))
        return data.at(address);
    else
        return 0;
}

void Memory::writeByte(std::uint16_t address, std::uint8_t value)
{
    if (isValidRange(address))
        data.at(address) = value;
}

void Memory::writeWord(std::uint16_t address, std::uint8_t value)
{
    if (isValidRange(address))
        data.at(address) = value;
}

void Memory::debugMemory(uint16_t address)
{
    if (isValidRange(address))
        printf("[ DEBUG ]: Memory at 0x%04X -> 0x%04X\n", address, data[address]);
}
