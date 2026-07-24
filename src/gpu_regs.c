#include "gpu_regs.h"

#include "gba/gba.h"
#include "gfx.h"
#include "global.h"
#include "motion.h"

IWRAM_DATA ALIGNED(16) struct OamManager gOamManager = {};

void ResetVideoRegister(void) {
  gVideoRegBuffer.dispcnt &= ~DISPCNT_BGMODE_MASK;
  gVideoRegBuffer.dispcnt &= ~(DISPCNT_BG_ALL_ON | DISPCNT_WIN1_ON);
  DmaFill32(3, 0, gVideoRegBuffer.bgcnt, sizeof(struct WramVideoRegister) - 4);
  BGCNT16(0) = BGCNT_PRIORITY(0) | BGCNT_CHARBASE(2) | BGCNT_SCREENBASE(0) | BGCNT_TXT512x512;
  BGCNT16(1) = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(2) | BGCNT_TXT512x256;
  BGCNT16(2) = BGCNT_PRIORITY(2) | BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(4) | BGCNT_TXT512x256;
  BGCNT16(3) = BGCNT_PRIORITY(3) | BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(8) | BGCNT_TXT512x256;
  FlushVideoRegister();
}

void FlushVideoRegister(void) {
  vu16 dispcnt = REG_DISPCNT;
  dispcnt &= 0xF0E8;
  gVideoRegBuffer.dispcnt &= 0x0F17;
  dispcnt |= gVideoRegBuffer.dispcnt;
  REG_DISPCNT = dispcnt;

  DmaCopy32(3, gVideoRegBuffer.bgcnt, REG_ADDR_BG0CNT, sizeof(struct WramVideoRegister) - 4);
}

// SELF_REL_PTR(&tbl[idx]); tbl = gBgMapOffsets
static inline void* GetHdr(const u32* tbl, u8 idx) {
  tbl = (const u32*)((const char*)tbl + tbl[idx]);
  return (void*)&tbl[idx];
}

/**
 * @brief VRAM内のBgMapにBgMapOffsets[idx]のBgMapデータをロードする
 * @param bg16 n = (bg16 / 16) = 0,1,2,3 となり BGnCNT を表す
 * @param tbl gBgMapOffsets (0x085222a0)
 * @param idx gBgMapOffsets のidx
 * @param x8 BgMapのX座標(タイル単位)
 * @param y8 BgMapのY座標(タイル単位)
 * @note 0x080041c4
 */
void LoadBgMap(u8 bg16, const u32* tbl, u8 idx, s8 x8, s8 y8) {
  u16* dst = SCREEN_ADDR(bg16 >> 4);
  dst += (y8 * 32) + x8;

  {
    struct BgMapHeader* hdr = GetHdr(tbl, idx);
    u32 w8 = hdr->w;
    u16 h8 = hdr->h;
    u16* src = (u16*)&hdr[1];

    while (h8 > 0) {
      CpuCopy16(src, dst, w8 << 1);
      h8--;
      src += w8, dst += 32;
    }
  }
}

/**
 * @brief BgMapOffsets[n] を(x*8, y*8)にくるようにdst(BGMap)にロード
 * @note 0x08004248
 */
void loadBgMap_08004248(u16* _dst, const u32* tbl, u8 idx, s8 x8, s8 y8) {
  u16* dst = &_dst[(y8 * 32) + x8];
  struct BgMapHeader* hdr = GetHdr(tbl, idx);
  u32 w8 = hdr->w;
  u16 h8 = hdr->h;
  u16* src = (u16*)(hdr + 1);

  while (h8 > 0) {
    CpuCopy16(src, dst, w8 << 1);
    h8--;
    src += w8, dst += 32;
  }
}

/**
 * @note 0x080042b0
 */
void ResetOAM(void) {
  gOamManager.dispcnt = DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON;
  gOamManager.p = gOamManager.buf;
  DmaFill32(3, 0x200, gOamManager.buf, OAM_SIZE);
  FlushOAM();
}

// 0x080042F8
void FlushOAM(void) {
  vu16 dispcnt = REG_DISPCNT;
  struct OamData** ep = &gOamManager.p;
  struct OamData* p = *ep;
  struct OamData* buf;

  dispcnt &= ~(DISPCNT_OBJ_ON);
  dispcnt |= gOamManager.dispcnt;
  REG_DISPCNT = dispcnt;

  buf = (struct OamData*)ep - 128;
  while (PTR_U32(p) < PTR_U32(ep)) {
    *((u16*)p) = 0x200;
    p++;
  }
  DmaCopy32(3, buf, OAM, OAM_SIZE);
  *(struct OamData**)(buf + 128) = buf;
}

// 0x08004370
void ClearBLDCLT_1(void) { gBlendRegBuffer.bldclt = 0; }

void FlushBlendRegister(void) {
  REG_BLDALPHA = gBlendRegBuffer.bldalpha;
  REG_BLDY = gBlendRegBuffer.bldy;
  REG_BLDCNT = gBlendRegBuffer.bldclt;
}

/**
 * @note 0x0800439C
 */
void ResetWindow(void) {
  gWindowRegBuffer.dispcnt = 0;
  gWindowRegBuffer.winin[2] = 0xFF;
}

/**
 * @note 0x080043AC
 */
void FlushWinRegister(void) {
  vu16 dispcnt = REG_DISPCNT;
  dispcnt &= ~(DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJWIN_ON);
  dispcnt |= gWindowRegBuffer.dispcnt;
  REG_DISPCNT = dispcnt;

  (*(vu32*)REG_ADDR_WIN0H) = gWindowRegBuffer.winH.word;
  (*(vu32*)REG_ADDR_WIN0V) = gWindowRegBuffer.winV.word;
  (*(vu32*)REG_ADDR_WININ) = *((u32*)&gWindowRegBuffer.winin);
}

void ClearMOSAIC(void) { wMOSAIC = 0; }

void FlushMOSAIC(void) { REG_MOSAIC = wMOSAIC; }
