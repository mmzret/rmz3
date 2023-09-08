#ifndef GUARD_RMZ3_GPU_REGS_H
#define GUARD_RMZ3_GPU_REGS_H

#include "constants/constants.h"
#include "gba/gba.h"

struct BgOfs {
  u16 x;
  u16 y;
};

// Video register buffer on EWRAM (gVideoRegBuffer)
struct WramVideoRegister {
  /*
    ただし、 bit13..15 は無視される (0x2002190 が担う)
    WramWindowRegister.dispcnt と OR したものが 実際のDISPCNT
  */
  u16 dispcnt;
  struct BgCnt ALIGNED(4) bgcnt[4];
  u16 bgofs[4][2];
};

// Video register buffer on EWRAM (gBlendRegBuffer)
struct WramBlendRegister {
  u16 bldclt;
  u16 bldalpha;
  u16 bldy;
  u16 _;
};  // 8 bytes

// Window register buffer on EWRAM (gWindowRegBuffer)
struct WramWindowRegister {
  /*
    DISPCNTの bit13..15 (Window有効化周り)
    WramVideoRegister.dispcnt と OR したものが 実際のDISPCNT
  */
  u16 dispcnt;
  u16 _;
  u32 winH;  // (win1h << 16 | win0h)
  u32 winV;  // (win1v << 16 | win0v)
  u8 unk_0c[3];
};  // 16 bytes

// --------------------------------------------

extern struct WramVideoRegister gVideoRegBuffer;
extern struct WramBlendRegister gBlendRegBuffer;
extern struct WramWindowRegister gWindowRegBuffer;
extern u16 wMOSAIC;  // wMOSAIC

// --------------------------------------------

void ResetVideoRegister(void);
void FlashVideoRegister(void);
void LoadBgMap(u8 bg16, const u32* tbl, u8 idx, s8 x, s8 y);
void loadBgMap_08004248(s32 dst, s32* tbl, s32 idx, u8 x, s32 y);
void ResetOAM(void);
void FlashOAM(void);
void ClearBLDCLT_1(void);
void FlashBlendRegister(void);
void ResetWindow(void);
void FlashWinRegister(void);
void ClearMOSAIC(void);
void FlashMOSAIC(void);

#endif  // GUARD_RMZ3_GPU_REGS_H
