#include <assert.h>
#include <algorithm>

#include <cstdio>

#include "include/Memory/Memory.hpp"

#define isValidRange(n) (n > 0 && n < data.size())

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

void Memory::viewAt(std::uint16_t& address)
{
    if (isValidRange(address))
    {
        printf("0x%04X: ", address);
        for (int i = 1; i <= 10; ++i)
        {
            printf("%02X ", data[address++]);
        }
        printf("\n");
    }
}

void Memory::debugMemory(std::size_t start, std::size_t end)
{
    if (isValidRange(start + end))
    {
        std::uint16_t current = start;

        printf("[ Memory Debug ] -> 0x%04lX\n", start);
        while (current <= end)
        {
            viewAt(current);
        }
    }
}
