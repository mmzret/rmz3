#ifndef GUARD_RMZ3_OW_QUAKE_H
#define GUARD_RMZ3_OW_QUAKE_H

#include "common.h"
#include "entity.h"
#include "gba/types.h"

struct Quake {
  u32 power;
  struct Coord c;
};

// 020300f0
struct QuakeManager {
  u32 rng;
  struct Quake quakes[17];
  struct Quake unk_0d0[17];
  u16 length;  // 020300f4 の有効な配列の長さ
  u16 frame;   // 揺れ始めから経過したフレーム
  s32 power;
  u16 unk_1a4;
  u16 unk_1a6;
};  // 424 bytes

extern struct QuakeManager gQuakeManager;

void ClearQuakeManager(void);
void AppendQuake(u8 power, struct Coord* c);
void CalcQuake(struct Coord* c, struct Coord* ofs);
s32 quake_0801acdc(struct Coord* _);

#endif  // GUARD_RMZ3_OW_QUAKE_H
