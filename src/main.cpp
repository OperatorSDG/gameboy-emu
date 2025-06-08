#include <iostream>
#include "memory/memory.hpp"
#include "DMG/cpu.hpp"

int main() {
    Memory mem;
    SM83 cpu(mem);

    mem.write(0x0100, 0x00);

    std::cout << "PC : 0x" << std::hex << cpu.getPC() << std::endl;
    cpu.step();
    std::cout << "PC : 0x" << std::hex << cpu.getPC() << std::endl;
}