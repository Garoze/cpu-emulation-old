#include <vector>
#include <cstdio>

#include "include/CPU/CPU.hpp"

int main()
{
    using i = Instructions;

    CPU cpu;

    /* LDI 5
     * RET -> 5
     * INC
     * RET -> 6
     * PSH 0xABCD
     * LDS
     * RET -> ABCD
     * LDA 0x0050
     * RET -> 12
     *
    */

    const std::vector<std::uint16_t> code = {
        (int)i::LDI, 5,
        // (int)i::RET,
        // (int)i::INC,
        // (int)i::RET,
        // (int)i::PSH, 0xABCD,
        // (int)i::LDS,
        // (int)i::RET,
        // (int)i::LDA, 0x0050,
        // (int)i::RET,
        (int)i::HTL,
    };

    cpu.loadToMemory(code);
    cpu.step();
    // cpu.run();
    cpu.debugMemory(0x0050, 0x0070);

    return 0;
}
