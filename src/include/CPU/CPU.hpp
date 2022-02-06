#pragma once

#include <map>
#include <vector>

#include "Flags.hpp"
#include "Registers.hpp"
#include "Instructions.hpp"

#include "../Memory/Memory.hpp"

class CPU
{
public:
    CPU();

    void run();
    void loadToMemory(const std::vector<std::uint16_t>&);
public:
    void DebugMemory(std::uint16_t address);
private:
    void fetch();
    void decode();
    void execute();
private:
    void NOP();
    void PSH();
    void POP();
    void HLT();
private:
    Flags flags;
    Memory memory;
    Registers registers;
    std::uint16_t opcode;
    Instructions instruction;
    std::map<Instructions, void(CPU::*)()> opcode_t;
};
