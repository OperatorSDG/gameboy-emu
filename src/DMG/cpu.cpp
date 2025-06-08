#include <iostream>
#include "cpu.hpp"

// Constructor
SM83::SM83(Memory& mem) : memory(mem) {
    reset();
}

void SM83::reset() {
    A = 0x01, F = 0xB0;
    B = 0x00, C = 0x13;
    D = 0x00, E = 0xD8;
    H = 0x01, L = 0x4D;
    SP = 0xFFFE;
    PC = 0x0100;
}

void SM83::step() {
    u8 opcode =fetch();
    Instruction instr = decode(opcode);
    execute(instr);
}


u8 SM83::fetch() {
    return memory.read(PC++);
}

Instruction SM83::decode(u8 opcode) {
    Instruction instr;
    instr.opcode = opcode;

    return instr;
}

void SM83::execute(const Instruction& instr) {
    switch (instr.opcode)
    {
    case 0x00: // NOP
        /* code */
        break;
    
    default:
        std::cout << "Unknown opcode: 0x" << std::hex << (int)instr.opcode << std::endl;
        break;
    }
}

// Register pair hendler
u16 SM83::getAF() const { return (A << 8) | F; }
void SM83::setAF(u16 val) { A = val >> 8; F = val & 0xF0; }
u16 SM83::getBC() const { return (B << 8) | C; }
void SM83::setBC(u16 val) { B = val >> 8; C = val & 0xFF; }
u16 SM83::getDE() const { return (D << 8) | E; }
void SM83::setDE(u16 val) { D = val >> 8; E = val & 0xFF; }
u16 SM83::getHL() const { return (H << 8) | L; }
void SM83::setHL(u16 val) { H = val >> 8; L = val & 0xFF; }

// Flag handler
bool SM83::getFlagZ() const { return F & 0x80; }
void SM83::setFlagZ(bool v) { F = v ? (F | 0x80) : (F & ~0x80); }
bool SM83::getFlagN() const { return F & 0x40; }
void SM83::setFlagN(bool v) { F = v ? (F | 0x40) : (F & ~0x40); }
bool SM83::getFlagH() const { return F & 0x20; }
void SM83::setFlagH(bool v) { F = v ? (F | 0x20) : (F & ~0x20); }
bool SM83::getFlagC() const { return F & 0x10; }
void SM83::setFlagC(bool v) { F = v ? (F | 0x10) : (F & ~0x10); }