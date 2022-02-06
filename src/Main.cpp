#include <vector>
#include <cstdio>

#include "include/CPU/CPU.hpp"

using i = Instructions;

int main()
{
    CPU cpu;

    const std::vector<std::uint16_t> code = {
        (int)i::NOP,
        (int)i::PSH, 5,
        (int)i::POP,
        (int)i::HTL,
    };
    cpu.loadToMemory(code);
    cpu.run();
    cpu.debugRegisterA();

    return 0;
}
