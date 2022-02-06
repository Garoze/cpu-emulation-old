#pragma once

#include <array>
#include <cstdint>

#define MEMORY_SIZE 4096

class Memory
{
public:
    Memory();

    std::uint8_t  readByte(std::uint16_t address);
    std::uint16_t readWord(std::uint16_t address);

    void writeByte(std::uint16_t address, std::uint8_t value);
    void writeWord(std::uint16_t address, std::uint8_t value);

    void debugMemory(uint16_t address);

    std::uint16_t& operator[](std::size_t i)
    {
        return data[i];
    }
private:
    std::array<std::uint16_t, MEMORY_SIZE> data;
};
