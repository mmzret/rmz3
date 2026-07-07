#ifndef __INCLUDE_ENTITY_SPRITE_H__
#define __INCLUDE_ENTITY_SPRITE_H__

#include "gba/gba.h"
#include "renderer.h"

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
};  // 8 bytes

struct Coord;
struct DrawPivot;
struct MetaspriteHeader;

// Entityを表す複数のスプライトが集まったメタスプライト(モーションによっては複数のメタスプライトを持つ時もある)
struct Sprite {
  struct Sprite* p;                               // 0x00
  void (*fn)(struct Sprite*, struct DrawPivot*);  // 0x04, 関数 0x08004eb0 で呼び出し

  struct MetaspriteHeader* sprites;  // 0x08, メタスプライト(のヘッダ)の配列 (VFX* が入る時も)
  struct Coord* c;                   // 0x0C
  struct EntityOamData oam;          // 0x10
  bool8 xflip;                       // 0x18
  bool8 yflip;                       // 0x19
  u8 spriteIdx;                      // 0x1A, .sprites の idx (どのメタスプライトを表示するか)
  u8 angle;                          // 0x1B
  struct {
    u16 x;
    u16 y;
  } mag;  // size magnification (x, y)
};  // 32 bytes
static_assert(sizeof(struct Sprite) == sizeof(RenderData));

#endif  // __INCLUDE_ENTITY_SPRITE_H__
