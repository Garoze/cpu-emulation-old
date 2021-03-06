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
    void step();
    void loadToMemory(const std::vector<std::uint16_t>&);
    void debugMemory(std::size_t start, std::size_t end);

private:
    void fetch();
    void decode();
    void execute();
private:
    void NOP();
    void SHL();
    void SHR();
    void AND();
    void BOR();
    void XOR();
    void NOT();
    void LDI();
    void LDA();
    void LDR();
    void LDS();
    // void STA();
    // void STR();
    // void STS();
    // void SUB();
    void INC();
    void DEC();
    void RET();
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
