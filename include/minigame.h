#ifndef GUARD_RMZ3_MINIGAME_H
#define GUARD_RMZ3_MINIGAME_H

#include "gba/gba.h"

// 全種類のミニゲームで同じレイアウトなのか、unionを使うべきかは調査中
struct MinigameState {
  u8 unk_00[4];  // unk_00: s16 in CopyX
  s16 unk_04;    // zero と copy_x で s16
  s16 unk_06;    // s16 in CopyX
  s32 unk_08;    // Ciel score
  u8 unk_0c;     // u8 in ZeroMini_Update
  u8 unk_0d;
  u8 unk_0e;
  u8 unk_0f;
  u8 unk_10[4];
  s32 unk_14;  // used by Phantom
  u16 unk_18;  // ?16 in fefnir_080347f0
  u8 unk_1a;
  u8 unk_1b;
  u8 unk_1c[4];
  s32 unk_20;  // s32 in Fefnir

  // u16 unk_24, unk_26 in FUN_08034774
  s32 unk_24;  // s32 in CopyX, Leviathan
  s32 unk_28;  // Fefnir Hiscore

  // unk_2f が Fefnir だと u8 っぽくアクセスしてる(Fefnir_Update) ので、ここらへんは union?
  s32 unk_2c;  // Leviathan Hiscore
  u8 unk_30[4];
  s32 unk_34;  // Phantom score
  u8 unk_38[4];
  s32 unk_3c;  // Phantom Hiscore
  u8 unk_40[144];
  u8 unk_d0[4];
  u8 unk_d4;
  u8 unk_d5;  // Phantom minigame で u8 としてアクセス
  u8 unk_d6;  // used by Phantom
  u8 unk_d7;
  u8 unk_d8[8];
  u8 unk_e0[32];
};
static_assert(sizeof(struct MinigameState) == 256);

struct GameState;
typedef bool32 (*MinigameFunc)(struct GameState*);

void PrintMinigameNumber(s32 score, u16 x, u16 y);

#endif  // GUARD_RMZ3_MINIGAME_H
