#ifndef GUARD_RMZ3_REWARD_H
#define GUARD_RMZ3_REWARD_H

#include "gba/types.h"

// Disk drop from enemy
struct DiskDrop {
  u16 stageID;
  u16 stageID2;
  u16 zakoOfs;  // 0x0202fde5 + (.zakoOfs-0x19)
  u16 type;     // entity type (e.g. Solid, Enemy, ...)
  u16 id;       // entity id (e.g. Enemy.id)
  u16 kind;     // Enemy.s.work[0] (セーメランの場合は本体だけカウントするみたいな用途で使う)
  u16 count;    // シークレットディスクを落とすのに必要な撃破数
  u16 diskNo;   // ディスク番号(not ID)
};              // 16 bytes

#endif  // GUARD_RMZ3_REWARD_H
