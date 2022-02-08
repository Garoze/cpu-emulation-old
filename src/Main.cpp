#include <vector>
#include <cstdio>

#include "include/CPU/CPU.hpp"

int main()
{
    using i = Instructions;

    CPU cpu;

    const std::vector<std::uint16_t> code = {
        (int)i::PSH, 0xABCD,
        (int)i::POP,
        (int)i::HTL,
    };
    cpu.loadToMemory(code);
    cpu.step();
    // cpu.run();
    cpu.debugMemory(0x0100, 0x0120);

    return 0;
}
