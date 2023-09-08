#ifndef GUARD_RMZ3_ENTITY_ENTITY_H
#define GUARD_RMZ3_ENTITY_ENTITY_H

#include "entity/body.h"
#include "gba/gba.h"
#include "global.h"
#include "motion.h"

struct EntityOamData {
  /*0x00*/ u32 y : 8;
  /*0x01*/ u32 affineMode : 2;  // 0x1, 0x2 = 0x3
  /*    */ u32 objMode : 2;     // 0x4, 0x8 = 0xC
  /*    */ u32 mosaic : 1;      // 0x10
  /*    */ u32 bpp : 1;         // 0x20
  /*    */ u32 shape : 2;       // 0x40, 0x80

  // OBJ Attribute 1 (Affine)
  /*0x02*/ u32 x : 9;
  /*    */ u32 matrixNum : 5;  // bits 3/4 are h-flip/v-flip if not in affine mode
  /*    */ u32 size_affine : 2;

  /*0x04*/ u16 tileNum : 10;
  /*    */ u16 priority : 2;
  /*    */ u16 paletteNum : 4;

  // OBJ Attribute 1 (Non affine)
  /*0x06*/ u8 unused : 4;
  /*    */ u8 xflip : 1;
  /*    */ u8 yflip : 1;
  /*    */ u8 size : 2;
  /*    */ u8 : 8;
};

// Entityを表す複数のスプライトが集まったメタスプライト(モーションによっては複数のメタスプライトを持つ時もある)
struct Sprite {
  struct Sprite *p;
  void (*fn)(struct Sprite *, struct DrawPivot *);  // 関数 0x08004eb0 で呼び出し

  struct MetaspriteHeader *sprites;  // メタスプライト(のヘッダ)の配列 (VFX* が入る時も)
  struct Coord *c;
  struct EntityOamData oam;
  bool8 xflip;
  bool8 yflip;
  u8 spriteIdx;  // .sprites の idx (どのメタスプライトを表示するか)
  u8 angle;
  struct {
    u16 x;
    u16 y;
  } mag;  // size magnification (x, y)
};

struct __attribute__((packed, aligned(1))) EntityFlags {
  u8 display : 1;
  u8 flipable : 1;
  u8 collidable : 1;
  u8 oamprio : 1;
  u8 xflip : 1;
  u8 yflip : 1;
  u8 affine : 1;
  u8 b7 : 1;
};

struct Entity {
  struct Entity *next;
  struct Entity *prev;

  s8 kind;
  u8 id;
  u8 flags;

  /*
    bit 2: 0: (モーションテーブルとして) Staticテーブル, 1: Dynamicテーブル
    bit 3: ゼロが通り抜け不可能(例えばパンテオンはこのbitが0なのでダメージは食らうがゼロがパンテオンを通過することができる)
  */
  u8 flags2;

  // u32として1つのモードとして扱うときもある
  // 場合によっては次の処理時のmode[0]をmode[3]に格納しておくなど汎用のバッファとしても使われる
  u8 mode[4];

  u8 work[4];      // general purpose
  void *onUpdate;  // EntityFunc
  u8 *arr;
  u8 uniqueID;      // すべてのEntityを区別するためのID
  u8 invincibleID;  // 被ダメ時の無敵を表す白塗りをEntityに適用する際にEntityの区別に用いるID

  // motion_t
  motion_id_t motionID;  // upper byte for motion_t
  u8 motionStep;         // lower byte for motion_t

  u16 tileNum;
  u8 palID;  // これを変えると色が変わる
  u8 savedPalID;
  u8 angle;  // Affine spriteのときの回転度合い
  u8 taskCol;
  metatile_attr_t hazardAttr;
  struct Entity *unk_28;
  struct Entity *unk_2c;
  const struct Rect *size;
  struct Sprite spr;
  struct Coord coord;
  struct Coord d;  // 移動速度
  struct Coord unk_coord;
  struct Motion motion;
};  // 116 bytes

struct CollidableEntity {
  struct Entity s;
  struct Body body;
  u8 work[16];  // general purpose buffer
};              // 196 bytes

typedef void (*EntityFunc)(struct Entity *);

#define ENTITY(p) (((struct CollidableEntity *)p)->s)

// --------------------------------------------

#endif  // GUARD_RMZ3_ENTITY_ENTITY_H
