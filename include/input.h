#ifndef GUARD_RMZ3_INPUT_H
#define GUARD_RMZ3_INPUT_H

#include "gba/gba.h"

typedef enum KEY_INPUT {
  A = 0x01,
  B = 0x02,
  SELECT = 0x04,
  START = 0x08,
  RIGHT = 0x10,
  LEFT = 0x20,
  UP = 0x40,
  DOWN = 0x80,
  R = 0x100,
  L = 0x200,
  MAX = 0xFFFF
} KEY_INPUT;

#define KEY_NEW() ({ (*(KEY_INPUT *)REG_ADDR_KEYINPUT); })

/* IOレジスタと違って、押されている時にビットが立つ */
struct KeyState {         
  enum KEY_INPUT input;   /* 現在押されている入力(以前の状態は考慮しない) */
  enum KEY_INPUT last;    /* 1フレーム前のinput */
  enum KEY_INPUT pressed; /* 今回OFFからONに変わった入力 */
  enum KEY_INPUT field3_0x6;
  
  bool16 firstRead;
  u8 field5_0xa[10];
  u8 field6_0x14;
  u8 field7_0x15;
  u8 field8_0x16;
  u8 field9_0x17;
};

#endif  // GUARD_RMZ3_INPUT_H
