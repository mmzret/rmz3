#ifndef GUARD_RMZ3_GAME_H
#define GUARD_RMZ3_GAME_H

#include "gba/gba.h"

typedef enum MainScript {
  NEUTRAL = 0 /* その他 */,
  MENU = 1 /* メニュー画面 */,
  SD_ANALYSIS = 2 /* シークレットディスクの解析 */,
  MINIGAME = 3 /* ミニゲーム中 */
} MainScript;

struct GameState {      /* Game全体のステート 0x02030b60 */
  enum MainScript proc; /* 083860a0 のidx */
  u8 mode;              /* 0x08386170, 0x083862b4, 0x08386a78. */
  u8 sub_mode2;         /* Used as index in 0x08386a8c. */
  u8 sub_mode3;
  u16 frames;
  u8 field5_0x6;
  u8 field6_0x7;
  void *field7_0x8;
};

#endif  // GUARD_RMZ3_GAME_H
