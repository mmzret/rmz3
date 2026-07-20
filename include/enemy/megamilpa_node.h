#ifndef __INCLUDE_ENEMY_MEGAMILPA_NODE_H__
#define __INCLUDE_ENEMY_MEGAMILPA_NODE_H__

#include "entity/entity.h"
#include "gba/gba.h"

typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  void* parent;   // 0xB4, Megamilpa Boss Entity
  u8 nodeIdx;     // 0xB8
  u8 unk_b9[11];  // 0xB9
} MegamilpaNode;
static_assert(sizeof(MegamilpaNode) == sizeof(struct Enemy));

MegamilpaNode* CreateMegamilpaNode(u8 idx);

#endif  // __INCLUDE_ENEMY_MEGAMILPA_NODE_H__
