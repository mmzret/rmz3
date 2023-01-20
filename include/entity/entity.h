#ifndef GUARD_RMZ3_ENTITY_ENTITY_H
#define GUARD_RMZ3_ENTITY_ENTITY_H

#include "gba/gba.h"
#include "global.h"
#include "motion.h"
#include "object.h"

struct Entity {
  struct Entity *next;
  struct Entity *prev;

  u8 field2_0x8;
  u8 id;
  u8 flags;
  u8 flags2;

  // u32として1つのモードとして扱うときもある
  u8 fnIdx;
  u8 mode;
  u8 phase;
  u8 step;  // 場合によっては次の処理時のmodeを格納しておくバッファとしても使われる

  // entity の種類によって使われ方はさまざま
  u8 various;
  u8 floor;
  u8 frames;
  u8 frames2;

  void *fn;
  u8 *arr;
  u8 unk_28;
  u8 unk_29;
  u8 actionID;
  u8 motionFrames;
};

struct BaseGeneralEntity {
  struct Entity s;
  u8 unk_32[2];
  u8 palID;  // これを変えると色が変わる
  u8 savedPalID;
  u8 unk_36[2];
  u16 blockingAttr;
  struct Entity *unk_40;
  struct Entity *unk_44;
  struct Rect *size;
  void *spr;
  struct Coord coord;
  struct Coord d;  // 移動速度
  struct Coord unk_coord;
  struct Motion motion;
};  // 116 bytes

#endif  // GUARD_RMZ3_ENTITY_ENTITY_H
