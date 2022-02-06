#include <vector>
#include <cstdio>

#include "include/CPU/CPU.hpp"

int main()
{
    using i = Instructions;

    CPU cpu;

    const std::vector<std::uint16_t> code = {
        (int)i::PSH, 5,
        (int)i::POP,
        (int)i::HTL,
    };
    cpu.loadToMemory(code);
    cpu.run();
    cpu.debugMemory(0x0100, 0x0120);

    return 0;
}
