#ifndef GUARD_RMZ3_MOTION_H
#define GUARD_RMZ3_MOTION_H

#include "constants/constants.h"
#include "types.h"
//
#include "animation.h"

// Entity の animation

struct Entity;

#define MOTION_VALUE(enti) ((((u16)((struct Entity*)enti)->motionID) << 8) | (((struct Entity*)enti)->motion.id))

#define IsSpriteAnimEnd(enti) ((((struct Entity*)(enti))->motion).state == ANIM_END)

struct MetaspriteHeader {
  u16 ofs;            // 0x00, $+ofs = Subsprite[]のアドレス
  s8 subspriteCount;  // 0x02, ゼロのモーションならゼロを構成するスプライトの数(死にかけ状態だと基本的に、頭、体、腕、足の4つのスプライト、つまりこの値は 4)
  u8 texture;         // 0x03, sheet/{texture}.png, 複数のテクスチャを持つ(DYNAMIC)スプライトのときに、どのテクスチャを使うか
};  // 4 bytes
static_assert(sizeof(struct MetaspriteHeader) == 4);

// 複数のスプライトを組み合わせて巨大な論理スプライト(メタスプライト)作る際、パーツとなる1つ1つのスプライトのこと
struct Subsprite {
  /*0x00*/ u16 tileNum : 10;  // タイル番号
  /*    */ u16 xflip : 1;
  /*    */ u16 yflip : 1;
  /*    */ u16 size : 2;   // OAMと同じ
  /*    */ u16 shape : 2;  // OAMと同じ
  /*0x02*/ s8 x;           // Offset
  /*0x03*/ s8 y;           // Offset
};  // 4 bytes
static_assert(sizeof(struct Subsprite) == 4);

extern const AnimCmd** gDynamicMotionCmdTable[DYNAMIC_MOTION_COUNT];
extern const AnimCmd** gStaticMotionCmdTable[STATIC_MOTION_COUNT];
extern const struct MetaspriteHeader* gStaticMotionMetaspriteTable[STATIC_MOTION_COUNT];
extern struct MetaspriteHeader* gDynamicMotionMetaspriteTable[DYNAMIC_MOTION_COUNT];

extern u16 wDynamicMotionPalIDs[DYNAMIC_MOTION_COUNT + 56];
extern u16 wStaticMotionPalIDs[STATIC_MOTION_COUNT + 2];

extern const u32 gDynamicMotionGraphicOffsets[DYNAMIC_MOTION_COUNT];
extern u16 wDynamicGraphicTilenums[DYNAMIC_MOTION_COUNT + 56];

void SetMotion(struct Entity* p, motion_t m);
// 今後は SetMotion を呼び出すところはこっちを使う (既存の箇所も後でこっちに置き換える予定)
#define SetSpriteAnimation(enti, id) (SetMotion(((struct Entity*)(enti)), id))

void ResetDynamicMotion(struct Entity* p);
static inline void SetSpriteTableDynamic(void* enti) { ResetDynamicMotion((struct Entity*)enti); }

void GotoMotion(struct Entity* p, motion_t m, u16 r2, u16 r3);
static inline void GotoSpriteAnimation(void* enti, motion_t motion, u16 cmdIdx, u16 duration) { GotoMotion((struct Entity*)enti, motion, cmdIdx, duration); }

void InitMotionLocation(void);

void InitNonAffineMotion(struct Entity* p);
static inline void EnableSpriteAnimation_Normal(void* enti) { InitNonAffineMotion((struct Entity*)enti); }

void InitScalerotMotion1(struct Entity* p);
static inline void EnableSpriteAnimation_Affine(void* enti) { InitScalerotMotion1((struct Entity*)enti); }

void ForceEntityPalette(struct Entity* p, u8 palID);

void UpdateEntityAnim(struct Entity* p);
// 今後は UpdateEntityAnim を呼び出すところはこっちを使う (既存の箇所も後でこっちに置き換える予定)
#define UpdateSpriteAnimation(enti) (UpdateEntityAnim(((struct Entity*)(enti))))

void FUN_0801779c(struct Entity* p);
static inline void _FUN_0801779c(void* enti) { FUN_0801779c((struct Entity*)enti); }

#endif  // GUARD_RMZ3_MOTION_H
