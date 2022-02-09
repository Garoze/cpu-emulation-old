#include <cstdio>
#include <iostream>

#include "include/CPU/CPU.hpp"
#include "include/CPU/Flags.hpp"

#define STACK_START   0x0040
#define PROGRAM_START 0x0050

#define isValidOpcode(i) (opcode_t.count((Instructions)i) > 0)

CPU::CPU()
{
    registers.A = 0;
    registers.B = 0;
    flags.running = true;
    flags.C = flags.N = flags.V = flags.Z = 0;
    registers.SP = STACK_START;
    registers.PC = PROGRAM_START;

    opcode_t[Instructions::NOP] = &CPU::NOP;
    opcode_t[Instructions::SHL] = &CPU::SHL;
    opcode_t[Instructions::SHR] = &CPU::SHR;
    opcode_t[Instructions::AND] = &CPU::AND;
    opcode_t[Instructions::BOR] = &CPU::BOR;
    opcode_t[Instructions::XOR] = &CPU::XOR;
    opcode_t[Instructions::LDI] = &CPU::LDI;
    opcode_t[Instructions::LDA] = &CPU::LDA;
    opcode_t[Instructions::LDR] = &CPU::LDR;
    opcode_t[Instructions::LDS] = &CPU::LDS;
    opcode_t[Instructions::INC] = &CPU::INC;
    opcode_t[Instructions::DEC] = &CPU::DEC;
    opcode_t[Instructions::RET] = &CPU::RET;
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
        fetch();
        decode();
        execute();
        printf("[ DEBUG ] Step -> PC: %02lX Opcode: %02hX\t", registers.PC, instruction);
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

void CPU::SHL()
{
    auto value = memory.readWord(registers.PC);
    registers.A <<= value;
    registers.PC += 2;
}

void CPU::SHR()
{
    auto value = memory.readWord(registers.PC);
    registers.A >>= value;
    registers.PC += 2;
}

void CPU::AND()
{
    auto value = memory.readWord(registers.PC);
    registers.A &= value;
    registers.PC += 2;
}

void CPU::BOR()
{
    auto value = memory.readWord(registers.PC);
    registers.A |= value;
    registers.PC += 2;
}

void CPU::XOR()
{
    auto value = memory.readWord(registers.PC);
    registers.A ^= value;
    registers.PC += 2;
}

void CPU::NOT()
{
    registers.A = ~registers.A;
}

void CPU::LDI()
{
    auto value = memory.readWord(registers.PC);
    registers.A = value;
    registers.PC += 2;
}

void CPU::LDA()
{
    auto address = memory.readWord(registers.PC);
    registers.A = memory.readWord(address);
    registers.PC += 2;
}

void CPU::LDR()
{
    auto relAddress = memory.readWord(registers.PC);
    auto address = memory.readWord(relAddress);
    registers.A = memory.readWord(address);
    registers.PC += 2;
}

void CPU::LDS()
{
    auto value = memory.readWord(registers.SP);
    registers.A = value;
    registers.SP += 2;
}

void CPU::INC()
{
    registers.A++;
}

void CPU::DEC()
{
    registers.A--;
}

void CPU::RET()
{
    printf("Reg A: [ %04X ]\n", registers.A);
}

void CPU::PSH()
{
    auto value = memory.readWord(registers.PC);
    registers.SP -= 2;
    memory.writeWord(registers.SP, value);
    registers.PC += 2;
}

void CPU::POP()
{
    auto value = memory.readWord(registers.SP);
    registers.A = value;
    registers.SP += 2;
}

void CPU::HLT()
{
    flags.running = false;
}

