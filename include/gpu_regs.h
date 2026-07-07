#ifndef GUARD_RMZ3_GPU_REGS_H
#define GUARD_RMZ3_GPU_REGS_H

#include "constants/constants.h"
#include "gba/gba.h"

// Stage.bgIdx, LoadBgMap の引数 bg16 などで使われる値
#define USE_BGn(n) ((n << 4) | (1 << n))
#define USE_BG1 USE_BGn(1)  // 0x12
#define USE_BG2 USE_BGn(2)  // 0x24
#define USE_BG3 USE_BGn(3)  // 0x38

#define BGCNT16(n) *((u16*)&gVideoRegBuffer.bgcnt[n])
#define BGOFS(n) ((BgOfs*)gVideoRegBuffer.bgofs[(n)])
#define CHAR_BASE(n) ((void*)((BGCNT16(n) & 0xc) << 0xc))
#define SCREEN_BASE(n) ((BGCNT16(n) & 0x1F00) << 3)
#define SCREEN_ADDR(bgIdx) ((void*)(BG_VRAM + SCREEN_BASE(bgIdx)))

#define BGnHOFS(n) (*((u16*)(((u8*)gVideoRegBuffer.bgofs) + (n << 2))))
#define BGnVOFS(n) (*((u16*)(((u8*)gVideoRegBuffer.bgofs) + (n << 2) + 2)))

#define RESET_BGOFS(n) *((u32*)&gVideoRegBuffer.bgofs[(n)]) = 0

typedef struct BgOfs {
  u32 x : 16;  // ピクセル単位
  u32 y : 16;  // ピクセル単位
} BgOfs;
static_assert(sizeof(BgOfs) == 4);

// Video register buffer on EWRAM (gVideoRegBuffer)
struct WramVideoRegister {
  u16 dispcnt;                  // 0x00, ただし、 bit13..15 は無視される (gWindowRegBuffer が担う), WramWindowRegister.dispcnt と OR したものが 実際のDISPCNT
  u16 _;                        // 0x02, padding
  u16 bgcnt[4];                 // 0x04, BGnCNT
  u16 bgofs[4][2];              // 0x0C
  struct BgAffineDstData bg2p;  // 0x1C, 使われてなさそう
  struct BgAffineDstData bg3p;  // 0x2C, 使われてなさそう
};  // 60 bytes
static_assert(sizeof(struct WramVideoRegister) == 60);

// Video register buffer on EWRAM (gBlendRegBuffer)
struct WramBlendRegister {
  u16 bldclt;
  u16 bldalpha;
  u16 bldy;
  u16 _;
};  // 8 bytes
static_assert(sizeof(struct WramBlendRegister) == 8);

union WindowRegister {
  u32 word;
  u16 half[2];  // win0, win1
};
static_assert(sizeof(union WindowRegister) == 4);

// Window register buffer on EWRAM (gWindowRegBuffer)
struct WramWindowRegister {
  u16 dispcnt;                // 0x00, DISPCNTの bit13..15 (Window有効化周り), WramVideoRegister.dispcnt と OR したものが 実際のDISPCNT
  u16 _;                      // 0x02, padding
  union WindowRegister winH;  // 0x04, WINH, WIN0H + WIN1H
  union WindowRegister winV;  // 0x08, WINV, WIN0V + WIN1V
  u8 winin[4];                // 0x0C, 0x04000048 (winin.0-7), 0x04000049 (winin.8-15), 0x0400004A (winout.0-7), 0x0400004B (winout.8-15)
};  // 16 bytes
static_assert(sizeof(struct WramWindowRegister) == 16);

// --------------------------------------------

extern struct WramVideoRegister gVideoRegBuffer;
extern struct WramBlendRegister gBlendRegBuffer;
extern struct WramWindowRegister gWindowRegBuffer;
extern u16 wMOSAIC;  // wMOSAIC

// --------------------------------------------

void ResetVideoRegister(void);
void FlushVideoRegister(void);
void LoadBgMap(u8 bg16, const u32* tbl, u8 idx, s8 x8, s8 y8);
void loadBgMap_08004248(u16* dst, const u32* tbl, u8 idx, s8 x8, s8 y8);
void ResetOAM(void);
void FlushOAM(void);
void ClearBLDCLT_1(void);
void FlushBlendRegister(void);
void ResetWindow(void);
void FlushWinRegister(void);
void ClearMOSAIC(void);
void FlushMOSAIC(void);

#endif  // GUARD_RMZ3_GPU_REGS_H
