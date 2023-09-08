#include "gpu_regs.h"

#include "gba/gba.h"
#include "gfx.h"
#include "global.h"
#include "motion.h"

void ResetVideoRegister(void) {
  gVideoRegBuffer.dispcnt &= BG_MODE_0;
  gVideoRegBuffer.dispcnt &= 0xB0FF;
  DmaFill32(3, 0, gVideoRegBuffer.bgcnt, 56);
  *(u16*)(&gVideoRegBuffer.bgcnt[0]) = 0xc008;
  *(u16*)(&gVideoRegBuffer.bgcnt[1]) = 0x4205;
  *(u16*)(&gVideoRegBuffer.bgcnt[2]) = 0x4406;
  *(u16*)(&gVideoRegBuffer.bgcnt[3]) = 0x4807;
  FlashVideoRegister();
}

void FlashVideoRegister(void) {
  vu16 dispcnt = REG_DISPCNT;
  dispcnt &= 0xF0E8;
  gVideoRegBuffer.dispcnt &= 0x0F17;
  dispcnt |= gVideoRegBuffer.dispcnt;
  REG_DISPCNT = dispcnt;
  DmaCopy32(3, gVideoRegBuffer.bgcnt, REG_ADDR_BG0CNT, 56);
}

/**
 * @brief VRAM内のBgMapにBgMapOffsets[idx]のBgMapデータをロードする
 * @param bg16 n = (bg16 / 16) = 0,1,2,3 となり BGnCNT を表す
 * @param tbl gBgMapOffsets (0x085222a0)
 * @param idx gBgMapOffsets のidx
 * @param x BgMapのX座標(タイル単位)
 * @param y BgMapのY座標(タイル単位)
 * @note 0x080041c4
 */
WIP void LoadBgMap(u8 bg16, const u32* tbl, u8 idx, s8 x, s8 y) {
#if MODERN
  s32 i;

  u32 n = (bg16 >> 4) & 0x3;
  u32 dst = VRAM + SCREEN_BASE_16(n) + ((y * 32 + x) * 2);
  struct BgMapHeader* hdr = (struct BgMapHeader*)OFFSET_TABLE(tbl, idx);
  u16* src = (u16*)&hdr[1];
  for (i = 0; i < hdr->h; i++) {
    CpuCopy16(&src[hdr->w * i], (void*)(dst + (64 * i)), hdr->w * 2);
  }
#else
  INCCODE("asm/wip/LoadBgMap.inc");
#endif
}

/**
 * @brief BgMapOffsets[n] を(x*8, y*8)にくるようにdst(BGMap)にロード
 * @note 0x08004248
 */
NAKED void loadBgMap_08004248(s32 dst, s32* tbl, s32 idx, u8 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	ldr r4, [sp, #0x1c]\n\
	lsls r2, r2, #0x18\n\
	lsls r4, r4, #0x18\n\
	asrs r4, r4, #0x13\n\
	lsls r3, r3, #0x18\n\
	asrs r3, r3, #0x18\n\
	adds r4, r4, r3\n\
	lsls r4, r4, #1\n\
	adds r7, r0, r4\n\
	lsrs r2, r2, #0x16\n\
	adds r0, r2, r1\n\
	ldr r0, [r0]\n\
	adds r1, r1, r0\n\
	adds r1, r1, r2\n\
	ldrh r0, [r1, #4]\n\
	ldrh r4, [r1, #6]\n\
	adds r5, r1, #0\n\
	adds r5, #8\n\
	cmp r4, #0\n\
	beq _0800429E\n\
	lsls r6, r0, #1\n\
	lsrs r0, r6, #1\n\
	mov r8, r0\n\
	ldr r3, _080042AC @ =0x001FFFFF\n\
	mov sb, r3\n\
_08004282:\n\
	adds r0, r5, #0\n\
	adds r1, r7, #0\n\
	mov r2, r8\n\
	mov r3, sb\n\
	ands r2, r3\n\
	bl CpuSet\n\
	subs r0, r4, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	adds r5, r5, r6\n\
	adds r7, #0x40\n\
	cmp r4, #0\n\
	bne _08004282\n\
_0800429E:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080042AC: .4byte 0x001FFFFF\n\
	 .syntax divided\n");
}

/**
 * @note 0x080042b0
 */
void ResetOAM(void) {
  gOamManager.dispcnt = 0x1040;
  gOamManager.p = gOamManager.buf;
  DmaFill32(3, 0x200, gOamManager.buf, 1024);
  FlashOAM();
}

// 0x080042F8
WIP void FlashOAM(void) {
#if MODERN
  vu16 dispcnt = REG_DISPCNT;
  dispcnt &= ~(DISPCNT_OBJ_ON);
  dispcnt |= gOamManager.dispcnt;
  REG_DISPCNT = dispcnt;

  while (PTR_U32(gOamManager.p) < PTR_U32(&gOamManager.p)) {
    *((u16*)gOamManager.p) = 0x200;
    gOamManager.p = &gOamManager.p[1];
  }
  DmaCopy32(3, gOamManager.buf, OAM, 1024);
  gOamManager.p = gOamManager.buf;
#else
  INCCODE("asm/wip/FlashOAM.inc");
#endif
}

// 0x08004370
void ClearBLDCLT_1(void) {
  gBlendRegBuffer.bldclt = 0;
  return;
}

void FlashBlendRegister(void) {
  REG_BLDALPHA = gBlendRegBuffer.bldalpha;
  REG_BLDY = gBlendRegBuffer.bldy;
  REG_BLDCNT = gBlendRegBuffer.bldclt;
}

/**
 * @note 0x0800439C
 */
void ResetWindow(void) {
  gWindowRegBuffer.dispcnt = 0;
  gWindowRegBuffer.unk_0c[2] = 0xFF;
}

/**
 * @note 0x080043AC
 */
void FlashWinRegister(void) {
  vu16 dispcnt = REG_DISPCNT;
  dispcnt &= ~(DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJWIN_ON);
  dispcnt |= gWindowRegBuffer.dispcnt;
  REG_DISPCNT = dispcnt;

  (*(vu32*)REG_ADDR_WIN0H) = gWindowRegBuffer.winH;
  (*(vu32*)REG_ADDR_WIN0V) = gWindowRegBuffer.winV;
  (*(vu32*)REG_ADDR_WININ) = *((u32*)&gWindowRegBuffer.unk_0c);
}

void ClearMOSAIC(void) {
  wMOSAIC = 0;
  return;
}

void FlashMOSAIC(void) {
  REG_MOSAIC = wMOSAIC;
  return;
}
