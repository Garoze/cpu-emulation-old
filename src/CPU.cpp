#include <cstdio>
#include <iostream>

#include "include/CPU/CPU.hpp"
#include "include/CPU/Flags.hpp"

#define STACK_START   0x00FF
#define PROGRAM_START 0x0100

CPU::CPU()
{
    registers.A = 0;
    registers.B = 0;
    flags.running = true;
    registers.SP = STACK_START;
    registers.PC = PROGRAM_START;

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

void CPU::debugMemory(std::size_t start, std::size_t end)
{
    memory.debugMemory(start, end);
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
    // opcode = memory.readWord(registers.PC++);
    opcode = memory.readByte(registers.PC++);
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
    registers.A = memory.readWord(++registers.SP);
}

void CPU::HLT()
{
    flags.running = false;
}

