#ifndef GUARD_RMZ3_DEFINITION_H
#define GUARD_RMZ3_DEFINITION_H

#include "gba/types.h"
#include "types.h"

#define BG_MODE_0 0xFFF8

#define POW2(n) (n * n)
#define OFFSET_TABLE(tbl, n) ((void *)((u32)(void *)&tbl[n] + (u32)tbl[n]))
#define PTR_U32(p) ((u32)(void *)(p))

typedef s32 (*ShapeChecker)(s32 x, s32 y);

struct Coord;

void *Malloc(u32 bytesize);
metatile_attr_t GetHazardMetatileAttr(s32 x, s32 y);
s32 FUN_08009f6c(s32 x, s32 y);
void CreateFirework(s32 x, s32 y, bool8 r2);
void resetData_08016db4(void);
void FUN_0802511c(void);
void clearStageDisk(void);
u32 TryDropItem(u32 table, struct Coord *c);

// --------------------------------------------

s32 PushoutToLeft1(s32 x, s32 y);
s32 PushoutToLeft2(s32 x, s32 y);
s32 PushoutToRight1(s32 x, s32 y);
s32 PushoutToRight2(s32 x, s32 y);

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
void *memcpy(void *buf1, const void *buf2, u32 n);
#endif

// --------------------------------------------

// sym_ewram.txt, sym_iwram.txt
extern bool8 gIsPlayDamageSE;
extern u8 wPauseFrame;
extern u32 gWhitePaintFlags[256 / 32];  // 被ダメ無敵時の白塗り(ビットフィールド)
extern u8 (*gUnlockedElfPtr)[CYBERELF_LENGTH];
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

extern const char_t gStringData[];
extern const u16 StringOfsTable[1096];

#endif  // GUARD_RMZ3_DEFINITION_H
