#ifndef GUARD_RMZ3_INPUT_H
#define GUARD_RMZ3_INPUT_H

#include "gba/gba.h"
#include "types.h"

#define KEY_NEW() ({ (*(u16 *)REG_ADDR_KEYINPUT); })

// Unlike IO registers, bits stand when they are pressed.
struct KeyState {
  KEY_INPUT input;   /* 現在押されている入力(以前の状態は考慮しない) */
  KEY_INPUT last;    /* 1フレーム前のinput */
  KEY_INPUT pressed; /* 今回OFFからONに変わった入力 */
  KEY_INPUT field3_0x6;

  bool16 firstRead;
  u8 ALIGNED(2) unk_0a[10];
  u8 field6_0x14;
  u8 field7_0x15;
  u8 field8_0x16;
  u8 field9_0x17;
};

extern struct KeyState gJoypad[2];

void PollKeyInput(void);

#endif  // GUARD_RMZ3_INPUT_H
