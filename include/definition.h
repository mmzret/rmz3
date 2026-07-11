#ifndef GUARD_RMZ3_DEFINITION_H
#define GUARD_RMZ3_DEFINITION_H

#include "gba/types.h"
#include "types.h"

#define DISPCNT_BGMODE_MASK 0x0007

#define POW2(n) (n * n)

typedef s32 (*ShapeChecker)(s32 x, s32 y);

// bitfield
#define FLAG(gameflags, n) (gameflags[(n) >> 3] & (1 << ((n) & 7)))
#define SET_FLAG(gameflags, n) (gameflags[(n) >> 3] |= (1 << ((n) & 7)))
#define CLEAR_FLAG(gameflags, n) (gameflags[(n) >> 3] &= ~(1 << ((n) & 7)))

#define FLAG32(bitfield32, n) ((bitfield32)[(n) >> 5] & (1 << ((n) & 31)))
#define SET_FLAG32(bitfield32, n) (((bitfield32)[(n) >> 5]) |= (1 << ((n) & 31)))
#define CLEAR_FLAG32(bitfield32, n) (((bitfield32)[(n) >> 5]) &= ~(1 << ((n) & 31)))

struct Coord;

void* Malloc(u32 bytesize);
s32 FUN_08009f6c(s32 x, s32 y);
void CreateFirework(s32 x, s32 y, bool8 r2);
void ResetEntityEnvironment(void);
void clearStageDisk(void);
u32 TryDropItem(u32 table, struct Coord* c);

// --------------------------------------------

s32 FUN_0800a22c(s32 x, s32 y);
s32 FUN_0800a31c(s32 x, s32 y);

// --------------------------------------------

s32 FUN_0800a738(s32 x, s32 y);
s32 FUN_0800a73c(s32 x, s32 y);
s32 FUN_0800a740(s32 x, s32 y);
s32 FUN_0800a760(s32 x, s32 y);
s32 FUN_0800a780(s32 x, s32 y);
s32 FUN_0800a7a0(s32 x, s32 y);
s32 FUN_0800a7c0(s32 x, s32 y);
s32 FUN_0800a7e0(s32 x, s32 y);
s32 FUN_0800a800(s32 x, s32 y);
s32 FUN_0800a814(s32 x, s32 y);
s32 FUN_0800a834(s32 x, s32 y);
s32 FUN_0800a848(s32 x, s32 y);
s32 FUN_0800a868(s32 x, s32 y);
s32 FUN_0800a888(s32 x, s32 y);
s32 FUN_0800a8a8(s32 x, s32 y);
s32 FUN_0800a8bc(s32 x, s32 y);
s32 FUN_0800a8d4(s32 x, s32 y);
s32 FUN_0800a8e8(s32 x, s32 y);
s32 FUN_0800a900(s32 x, s32 y);
s32 FUN_0800a918(s32 x, s32 y);
s32 FUN_0800a930(s32 x, s32 y);
s32 FUN_0800a94c(s32 x, s32 y);
s32 FUN_0800a968(s32 x, s32 y);
s32 FUN_0800a984(s32 x, s32 y);
s32 FUN_0800a9a0(s32 x, s32 y);
s32 FUN_0800a9bc(s32 x, s32 y);
s32 FUN_0800a9d8(s32 x, s32 y);
s32 FUN_0800aa08(s32 x, s32 y);
s32 FUN_0800aa3c(s32 x, s32 y);
s32 FUN_0800aa6c(s32 x, s32 y);
s32 FUN_0800aaac(s32 x, s32 y);
s32 FUN_0800aaec(s32 x, s32 y);
s32 FUN_0800ab20(s32 x, s32 y);
s32 FUN_0800ab48(s32 x, s32 y);
s32 FUN_0800ab68(s32 x, s32 y);
s32 FUN_0800ab90(s32 x, s32 y);
s32 FUN_0800abc4(s32 x, s32 y);
s32 FUN_0800abf8(s32 x, s32 y);

#if MODERN
void* memcpy(void* buf1, const void* buf2, u32 n);
#endif

// --------------------------------------------

// sym_ewram.txt, sym_iwram.txt
extern bool8 gIsPlayDamageSE;
extern bool8 gInHitStopFrames;
extern u32 gWhitePaintFlags[256 / 32];  // 被ダメ無敵時の白塗り(ビットフィールド)
extern u32 gLifeRecoverAmount;
extern u32 gSubtankRecoverAmount;
extern u32 gECrystalGainAmount;
extern u8 gInChat;
extern bool8 gIsUsingDoor3D;
extern bool8 gInTransport;
extern u8 gMatrixCount;
extern bool8 gPause;
extern u16 gTimeElfTimer;
extern s32 s32_0202f334;
extern bool8 gIsLemonCollisionRemoved;
extern u16 INTR_CHECK;

// --------------------------------------------

extern const ShapeChecker gShapeCheckerUp[16];
extern const ShapeChecker gShapeCheckerDown[16];
extern const ShapeChecker gShapeCheckerLeft[16];
extern const ShapeChecker gShapeCheckerRight[16];

#endif  // GUARD_RMZ3_DEFINITION_H
