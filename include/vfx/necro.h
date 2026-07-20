#ifndef __INCLUDE_VFX_NECRO_H__
#define __INCLUDE_VFX_NECRO_H__

#include "entity/entity.h"
#include "gba/gba.h"

/*
  雑魚敵が死んだあと、爆散始まるまでの状態
  雑魚敵が切断死した際の、切断された方の片方
*/
typedef struct {
  ENTITY_HDR;     // 0x00
  ENTITY_SPRITE;  // 0x28
  // props (16bytes, offset: 0x74..)
  motion_t* anim74;  // 0x74
  u8 unk_78;         // 0x78
  u8 unk_79;         // 0x79
  u8 unk_7a[10];     // 0x7A
} NecroVFX;
static_assert(sizeof(NecroVFX) == sizeof(struct VFX));

void FUN_080b834c(struct Entity* e, Coords32* c, Coords32* dc, s32 y, motion_t* motions, u8 frame);
void FUN_080b8454(struct Entity* e, Coords32* c, Coords32* dc, s32 y, motion_t* motions, u8 frame, u8 renderPrio);

#endif  // __INCLUDE_VFX_NECRO_H__
