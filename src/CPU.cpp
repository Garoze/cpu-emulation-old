#include <cstdio>
#include <iostream>

#include "include/CPU/CPU.hpp"
#include "include/CPU/Flags.hpp"

#define STACK_START   0x00FF
#define PROGRAM_START 0x0100

#define isValidOpcode(o) (opcode_t.count((Instructions)o) > 0)

CPU::CPU()
{
    registers.A = 0;
    registers.B = 0;
    flags.running = true;
    flags.C = flags.N = flags.V = flags.Z = 0;
    registers.SP = STACK_START;
    registers.PC = PROGRAM_START;

    opcode_t[Instructions::NOP] = &CPU::NOP;
    opcode_t[Instructions::PSH] = &CPU::PSH;
    opcode_t[Instructions::POP] = &CPU::POP;
    opcode_t[Instructions::HTL] = &CPU::HLT;
}

void CPU::loadToMemory(const std::vector<std::uint16_t>& v)
{
    auto PC = registers.PC;
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (isValidOpcode(v.at(i)))
            memory.writeByte(PC + i, v.at(i));
        else
            memory.writeWord(PC++ + i, v.at(i));
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

void CPU::step()
{
    do
    {
        printf("[ DEBUG (step) -> PC: %02lX ]\n", registers.PC);
        fetch();
        decode();
        execute();
    }
    while(std::cin.get() != 'q');
}

void CPU::fetch()
{
    opcode = memory.readByte(registers.PC++);
}

void CPU::decode()
{
    instruction = (Instructions)opcode;
}

void CPU::execute()
{
    if (isValidOpcode(instruction))
        (this->*opcode_t[instruction])();
    else
        printf("Invalid Opcode: %02hX\n", instruction);
}

void CPU::NOP() {}

void CPU::PSH()
{
    auto value = memory.readWord(registers.PC);
    printf("PUSH %04X\n", value);
    memory.writeWord(registers.SP--, value);
    registers.PC += 2;
}

void CPU::POP()
{
    auto value = memory.readWord(++registers.SP);
    printf("POP %04X\n", value);
    // printf("POP: %02X\n", value);
    // auto value = memory.readWord(++registers.SP);
    // registers.A = value;
}

void CPU::HLT()
{
    printf("HALT Instruction\n");
    flags.running = false;
}

