#ifndef GUARD_RMZ3_MOTION_H
#define GUARD_RMZ3_MOTION_H

#include "constants/constants.h"
#include "types.h"

// Motion.state
enum MotionState {
  MOTION_STATE_0,
  MOTION_STATE_1,
  MOTION_STATE_2,
  MOTION_END,
  MOTION_NEXT,
};

struct Entity;

#define MOTION_VALUE(e) ((((u16)(e->s).motionID) << 8) | ((e->s).motion.step))

// Motionにおいて、どのメタスプライトを何フレーム表示するかを指示する
struct __attribute__((packed, aligned(2))) MotionCmd {
  u8 spriteIdx;  // どのメタスプライトを使うか
  u8 frame;
};  // 2 bytes

struct MetaspriteHeader {
  u16 ofs;            // $+ofs = Subsprite[]のアドレス
  s8 subspriteCount;  // ゼロのモーションならゼロを構成するスプライトの数(死にかけ状態だと基本的に、頭、体、腕、足の4つのスプライト、つまりこの値は 4)
  u8 step;            // lower byte of motion_t
};                    // 4 bytes

// 複数のスプライトを組み合わせて巨大な論理スプライト(メタスプライト)作る際、パーツとなる1つ1つのスプライトのこと
struct Subsprite {
  /*0x00*/ u16 tileNum : 10;  // タイル番号
  /*    */ u16 xflip : 1;
  /*    */ u16 yflip : 1;
  /*    */ u16 size : 2;   // OAMと同じ
  /*    */ u16 shape : 2;  // OAMと同じ
  /*0x02*/ s8 x;
  /*0x03*/ s8 y;
};  // 4 bytes

struct Motion {
  /*
   * モーションは action_tの上位1バイトに依存
   * cmds[.step][.cmdIdx];
   */
  const struct MotionCmd **cmds;  // 085D6EE8
  u8 step;                        // motion_t の下位1バイト
  s8 cmdIdx;

  s8 duration;
  u8 state;
};  // 8 bytes;

// e.g. 0x085ba244
struct MotionPltt {
  u8 len;
  u8 start;
  u8 end;
  u8 _;
  // u16 pltt[len*n]; n = 次の MotionPltt構造体までの長さによって変動
};  // 4 bytes;

extern const struct MotionCmd **gDynamicMotionCmdTable[DYNAMIC_MOTION_COUNT];
extern struct MotionCmd *gMotionCmd_SM000[];

extern const struct MotionCmd **gStaticMotionCmdTable[STATIC_MOTION_COUNT];
extern const struct MetaspriteHeader *gStaticMotionMetaspriteTable[STATIC_MOTION_COUNT];
extern struct MetaspriteHeader gMetasprites_SM000[];
extern struct MetaspriteHeader *gDynamicMotionMetaspriteTable[DYNAMIC_MOTION_COUNT];
extern u16 wDynamicMotionPalIDs[DYNAMIC_MOTION_COUNT + 56];
extern u16 wStaticMotionPalIDs[STATIC_MOTION_COUNT + 2];
extern const u32 gDynamicMotionGraphicOffsets[DYNAMIC_MOTION_COUNT];
extern u16 wDynamicGraphicTilenums[DYNAMIC_MOTION_COUNT + 56];

void ResetMotion(struct Motion *p, const struct MotionCmd *const *const cmds);
void setMotionStep(struct Motion *p, u8 step);
void SetMotion(struct Entity *p, motion_t m);
void GotoMotion(struct Entity *p, motion_t m, u16 r2, u16 r3);
void ResetDynamicMotion(struct Entity *p);
void UpdateMotionGraphic(struct Entity *p);
void InitMotionLocation(void);
void InitScalerotMotion1(struct Entity *p);
void UpdateMotionState(struct Motion *p);
void ForceEntityPalette(struct Entity *p, u8 palID);

#endif  // GUARD_RMZ3_MOTION_H
