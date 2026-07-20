#ifndef __INCLUDE_VFX_BUBBLE_H__
#define __INCLUDE_VFX_BUBBLE_H__

#include "entity/entity.h"
#include "gba/gba.h"

// Bubble in the water
typedef struct {
  ENTITY_HDR;     // 0x00
  ENTITY_SPRITE;  // 0x28
  // props (16bytes, offset: 0x74..)
  s32 x_74;     // 0x74
  s32 unk_78;   // 0x78
  u8 unk_8[8];  // 0x7C
} BubbleVFX;
static_assert(sizeof(BubbleVFX) == sizeof(struct VFX));

void CreateBubble(s32 x, s32 y, u8 kind);

#endif  // __INCLUDE_VFX_BUBBLE_H__
