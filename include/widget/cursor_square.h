#ifndef __INCLUDE_WIDGET_UNK_02_H__
#define __INCLUDE_WIDGET_UNK_02_H__

#include "entity/entity.h"
#include "types.h"

struct GameState;

struct SquareCursorWidget {
  ENTITY_HDR;     // 0x00
  ENTITY_SPRITE;  // 0x28
  // props (16bytes, offset: 0x74..)
  u16 px;         // 0x74
  u16 py;         // 0x76
  bool8 dead;     // 0x78, EXスキルメニューが終了したりして、すでにカーソルが不要になったときに立つフラグ
  u8 pad_79[11];  // 0x79
};
static_assert(sizeof(struct SquareCursorWidget) == (sizeof(struct Entity) + 16));

struct Entity* CreateSquareCursor(struct GameState* g, bool8 big, u8 r2);

#endif  // __INCLUDE_WIDGET_UNK_02_H__
