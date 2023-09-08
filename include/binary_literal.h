#ifndef GUARD_RMZ3_BINARY_LITERAL_H
#define GUARD_RMZ3_BINARY_LITERAL_H

#include "gba/types.h"

// The C language prior to C23 does not support binary notation.

// Internal Macros
#define HEX__(n) 0x##n##LU
#define B8__(x) ((x & 0x0000000FLU) ? 1 : 0) + ((x & 0x000000F0LU) ? 2 : 0) + ((x & 0x00000F00LU) ? 4 : 0) + ((x & 0x0000F000LU) ? 8 : 0) + ((x & 0x000F0000LU) ? 16 : 0) + ((x & 0x00F00000LU) ? 32 : 0) + ((x & 0x0F000000LU) ? 64 : 0) + ((x & 0xF0000000LU) ? 128 : 0)

// User-visible Macros
#define B8(d) ((u8)B8__(HEX__(d)))
#define B16(dmsb, dlsb) (((u16)B8(dmsb) << 8) + B8(dlsb))
#define B32(dmsb, db2, db3, dlsb) (((u32)B8(dmsb) << 24) + ((u32)B8(db2) << 16) + ((u32)B8(db3) << 8) + B8(dlsb))

#endif  // GUARD_RMZ3_BINARY_LITERAL_H
