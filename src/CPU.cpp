#include <cstdio>
#include <iostream>

#include "include/CPU/CPU.hpp"
#include "include/CPU/Flags.hpp"

CPU::CPU()
{
    registers.A = 0;
    registers.B = 0;
    flags.running = true;
    registers.PC = 0x0100;
    registers.SP = 0x00FF;

    opcode_t[Instructions::NOP] = &CPU::NOP;
    opcode_t[Instructions::PSH] = &CPU::PSH;
    opcode_t[Instructions::POP] = &CPU::POP;
    opcode_t[Instructions::HTL] = &CPU::HLT;
}

void CPU::loadToMemory(const std::vector<std::uint16_t>& v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        memory.writeWord(registers.PC + i, v.at(i));
    }
}

void CPU::DebugMemory(std::uint16_t address)
{
    memory.debugMemory(address);
}

void CPU::run()
{
    while (flags.running)
    {
        fetch();
        decode();
        execute();
    }
}

void CPU::fetch()
{
    memory.debugMemory(registers.PC);
    opcode = memory.readWord(registers.PC++);
}

void CPU::decode()
{
    instruction = (Instructions)opcode;
}

void CPU::execute()
{
    (this->*opcode_t[instruction])();
}

void CPU::NOP() {}

void CPU::PSH()
{
    auto value = memory.readWord(registers.PC++);
    memory.writeByte(registers.SP--, value);
}

void CPU::POP()
{
    registers.A = memory.readByte(--registers.SP);
}

void CPU::HLT()
{
    flags.running = false;
}
