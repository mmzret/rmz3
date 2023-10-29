#ifndef GUARD_RMZ3_GLOBAL_H
#define GUARD_RMZ3_GLOBAL_H

#include "binary_literal.h"
#include "common.h"
#include "constants/constants.h"
#include "definition.h"
#include "gba/gba.h"
#include "incbin.h"
#include "syssav.h"
#include "trig.h"
#include "types.h"

// Prevent cross-jump optimization.
#define BLOCK_CROSS_JUMP asm("");

#define INCASM(file) \
  asm(".section .text\n\
  .include \"" file  \
      "\"\n\
          .align 2, 0\n    \
 .syntax divided\n");

#define INCDATA(file) \
  asm(".section .rodata\n\
  .include \"" file   \
      "\"\n\
 .syntax divided\n");

#define INCCODE(file) \
  asm(".syntax unified\n\
  .include \"" file   \
      "\"\n\
    .align 2, 0\n    \
 .syntax divided\n");

#define GLOBAL(symbol) __asm__(".section .rodata\n .global " STR(symbol) "\n" STR(symbol) ":\n");

#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))

#define SWAP(a, b, temp) \
  {                      \
    temp = a;            \
    a = b;               \
    b = temp;            \
  }

#define _(x) (x)  // For preproc
#define DISK_ID(diskno) (diskno - 1)
#define COORD(metacoord) (metacoord * 0x1000)  // 16px

// coord　を 16pxのマス目単位に
#define METACOORD(coord) ((coord) >> 12)

// gamecoord -> 1px
#define COORD_TO_PIXEL(coord) ((coord) >> 8)

// px -> gamecoord
#define PIXEL(pixel) ((pixel) << 8)
#define MAX_X (PIXEL(64 * DISPLAY_WIDTH))
#define MAX_Y (PIXEL(64 * DISPLAY_HEIGHT))

#define SCREEN_LEFT(coord_x) (((coord_x >> 8) + -120) << 8)  // Screen center -> Screen left
#define SCREEN_TOP(coord_y) (((coord_y >> 8) + -80) << 8)    // Screen center -> Screen top
#define MOTION(id, idx) ((id << 8) | idx)
#define GAMEMODE(m0, m1, m2, m3) ((m3 << 24) | (m2 << 16) | (m1 << 8) | m0)
#define SCREEN_WIDTH (240 << 8)
#define SCREEN_HEIGHT (160 << 8)

#define PLTTDATA(u16val) \
  { u16val & 0x1F, (u16val >> 5) & 0x1F, (u16val >> 10) & 0x1F, (u16val >> 15) & 0x1 }

#define DISK_COUNT 180
#define MISSION_COUNT 12
#define MINIGAME_COUNT 7
#define FREE_STAGE_COUNT 15  // フリーランできるステージの数
#define STAGE_COUNT 18       // Stage0 + ベース含む

#define LCG(s) (((s * 0x343FD + 0x269EC3) << 1) >> 1)
#define HIHALF(n) (((n) & 0xFFFF0000) >> 16)
#define LOHALF(n) ((n) & 0xFFFF)
#define HI_NIBBLE(byte) (((u8)byte) >> 4)
#define LO_NIBBLE(byte) (((u8)byte) & 0xF)

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))

static inline s32 abs(s32 n) {
  s32 val = n;
  if (n < 0) {
    val = -val;
  }
  return val;
}

extern u32 RNG_0202f388;

#endif  // GUARD_RMZ3_GLOBAL_H
