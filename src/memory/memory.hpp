#pragma once

#include "../include/common.hpp"
#include <vector>

class Memory {
public:
    Memory();
    u8 read(u16 address) const;
    void write(u16 address, u8 value);
private:
    std::vector<u8> ram;
};