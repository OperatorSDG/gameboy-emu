#pragma once

#include "../include/common.hpp"
#include "../memory/memory.hpp"

struct Instruction {
    u8 opcode;
};

class SM83 {
public:
    SM83(Memory& mem);
    void reset();
    void step(); 
    u16 getPC() const { return PC; }

private:
    // CPU helper
    uint8_t fetch();
    Instruction decode(u8 opcode);
    void execute(const Instruction& instr);

    // Registers
    u8 A, F, B, C, D, E, H, L;  // Acc, Flag, BC, DE & HL
    u16 PC, SP;                 // Program Counter & Stack Pointer

    Memory& memory;

    // Register pair handlers
    u16 getAF() const; void setAF(u16 val);
    u16 getBC() const; void setBC(u16 val);
    u16 getDE() const; void setDE(u16 val);
    u16 getHL() const; void setHL(u16 val);

    // Flag handlers
    bool getFlagZ() const; void setFlagZ(bool v);
    bool getFlagN() const; void setFlagN(bool v);
    bool getFlagH() const; void setFlagH(bool v);
    bool getFlagC() const; void setFlagC(bool v);
} ;