#ifndef __INCLUDE_VFX_AFTER_IMAGE_H__
#define __INCLUDE_VFX_AFTER_IMAGE_H__

#include "entity/entity.h"
#include "gba/gba.h"

struct AfterImage {
  ENTITY_HDR;     // 0x00
  ENTITY_SPRITE;  // 0x28
  // props (16bytes, offset: 0x74..)
  Coords32 c_74;  // 0x74
  u8 unk_7c[8];   // 0x7C
};  // 132 bytes
static_assert(sizeof(struct AfterImage) == sizeof(struct VFX));

struct Entity* CreateAfterImages(struct Entity* p);

#endif  // __INCLUDE_VFX_AFTER_IMAGE_H__
