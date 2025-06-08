#include "memory.hpp"

Memory::Memory() : ram(0x10000, 0) {
}

u8 Memory::read(u16 address) const {
    return ram[address];
}

void Memory::write(u16 address, u8 value) {
    ram[address] = value;
}