#include "gfx.h"

#include "gba/gba.h"
#include "global.h"
#include "motion.h"

/**
 * @brief VRAM全体を 0x11111111 で埋める (Reset VRAM by filling 0x11111111)
 */
void ClearVRAM(void) {
  gGraphicTransferManager.len = 0;
  gGraphicTransferManager.bg0mask.bg0 = NULL;
  DmaFill32(3, 0x11111111, VRAM, VRAM_SIZE);
}

/**
 * @brief 0x02001f00 のタスクどおりに転送を行う
 */
NAKED void doGraphicTransferTasks(void) {
  // TODO
  INCCODE("asm/wip/doGraphicTransferTasks.inc");
}

// 0x080037c0
WIP void LoadGraphic(const struct Graphic* g, void* dst) {
#if MODERN
  u32 buf[8];

  s32 size = g->size;
  if (size != 0) {
    void* ofs = dst + g->ofs * (g->props & 0x7F8);
    u8 props1 = PROPS1(g);

    if (g->props & CHUNKED) {
      void* src = (void*)(PTR_U32(&g->src) + g->src);
      if (props1 & LZ77) {
        while (size > 0) {
          if (*(s32*)(src) < 0) {
            CpuFastCopy(VRAM + ofs + g->chunkSize, buf, 32);
            LZ77UnCompVram(src + 4, VRAM + ofs);
            CpuFastCopy(buf, VRAM + ofs + g->chunkSize, 32);
          } else {
            CpuFastCopy(src + 4, VRAM + ofs, g->chunkSize);
          }
          ofs += (((u32)g->props << 21) >> 24) << 8;  // Next row
          size -= (*(u32*)(src)) & 0x7FFFFFFF;
          src += (*(u32*)(src)) & 0x7FFFFFFF;
        }

      } else if (IS_RLU_COMPRESSED(g)) {
        while (size > 0) {
          if (*(s32*)(src) < 0) {
            RLUnCompVram(src + 4, VRAM + ofs);
          } else {
            CpuFastCopy(src + 4, VRAM + ofs, g->chunkSize);
          }
          ofs += ((g->props << 21) >> 24) << 8;  // Next row
          size -= (*(u32*)(src)) & 0x7FFFFFFF;
          src += (*(u32*)(src)) & 0x7FFFFFFF;
        }

      } else {
        while (size > 0) {
          CpuFastCopy(src, VRAM + ofs, g->chunkSize);
          ofs += ((g->props << 21) >> 24) << 8;  // Next row
          src += g->chunkSize;
          size -= g->chunkSize;
        }
      }

    } else {
      if (props1 & LZ77) {
        LZ77UnCompVram((void*)(PTR_U32(&g->src) + g->src), VRAM + ofs);
      } else if (IS_RLU_COMPRESSED(g)) {
        RLUnCompVram((void*)(PTR_U32(&g->src) + g->src), VRAM + ofs);
      } else {
        CpuFastCopy((void*)(PTR_U32(&g->src) + g->src), VRAM + ofs, size);
      }
    }
  }
#else
  INCCODE("asm/wip/LoadGraphic.inc");
#endif
}

/**
 * @brief Graphic構造体を gGraphicTransferManager(0x02001f00) に追加する
 * @note 0x08003934
 */
s32 RequestGraphicTransfer(const struct Graphic* g, void* dst) {
  u32 i;

  // Check same request
  for (i = 0; i < gGraphicTransferManager.len; i++) {
    if (((struct Graphic*)gGraphicTransferManager.tasks[i].src == g) && (gGraphicTransferManager.tasks[i].dst == dst)) {
      return 0;  // Already requested
    }
  }
  if ((u32)gGraphicTransferManager.len < 16) {
    gGraphicTransferManager.tasks[i].dst = dst;
    gGraphicTransferManager.tasks[i].type = 0;
    gGraphicTransferManager.tasks[i].src = (void*)g;
    gGraphicTransferManager.len++;
    return 0;
  }
  return -1;
}

/**
 * @brief BGマップを gGraphicTransferManager(0x02001f00) に追加する
 * @return 0(success), -1(fail)
 * @note 0x080039ac
 */
s32 RequestBgMapTransfer(u16* src, void* dst, s32 r2) {
  const s32 len = gGraphicTransferManager.len;
  if (len < 16) {
    gGraphicTransferManager.tasks[len].type = 1;
    gGraphicTransferManager.tasks[len].unk = r2;
    gGraphicTransferManager.tasks[len].dst = dst;
    gGraphicTransferManager.tasks[len].src = src;
    gGraphicTransferManager.len++;
    return 0;
  }
  return -1;
}

/**
 * @note バイル研究所くらいでしか使ってない
 * @details グラフィックデータ(詳細不明, type=2)を gGraphicTransferManager(0x02001f00) に追加する
 * @return 0(success), -1(fail)
 * @note 0x08003a08
 */
s32 RequestType2Transfer(void* src, void* dst, s32 r2) {
  const s32 len = gGraphicTransferManager.len;
  if (len < 16) {
    gGraphicTransferManager.tasks[len].type = 2;
    gGraphicTransferManager.tasks[len].unk = r2;
    gGraphicTransferManager.tasks[len].dst = dst;
    gGraphicTransferManager.tasks[len].src = src;
    gGraphicTransferManager.len++;
    return 0;
  }
  return -1;
}

/**
 * @fn void MaskBg0(u32* dst, u32 bg0map, u32 bytesize, u32 mask)
 * @brief 引数 mask で BG0 をマスクする マスクデータは、0x080036cc で毎フレームVRAMに転送される
 * @param bg0 BG0のバッファ、これをnullにすると転送は起きない (常に 0x02030b70?)
 * @param bg0map 0x0600_0000 + bg0map がマスクデータの転送先 (常に BG0のマップアドレスを指す)
 * @param bytesize size of mask data
 * @param mask mask data
 * @note 0x08003a64
 */
void MaskBg0(u32* bg0, u32 bg0map, u32 bytesize, u16 mask) {
  gGraphicTransferManager.bg0mask.bg0 = (void*)bg0;
  gGraphicTransferManager.bg0mask.map = bg0map;
  gGraphicTransferManager.bg0mask.bytesize = bytesize;
  gGraphicTransferManager.bg0mask.mask = ((((u32)mask) << 16) | mask);
  DmaFill32(3, gGraphicTransferManager.bg0mask.mask, bg0, bytesize);
}

// Disable BG0 Mask
void UnmaskBg0(void) {
  gGraphicTransferManager.bg0mask.bg0 = NULL;
  return;
}

// ------------------------------------------------------------------------------------------------------------------------------------

void InitPaletteManager(void) {
  DmaFill32(3, 0, &gPaletteManager, PLTT_SIZE);
  DmaCopy32(3, &gPaletteManager, PLTT, PLTT_SIZE);
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x20;
  gPaletteManager.unk_406 = 0;
  gPaletteManager.unk_408 = NULL;
}

static void gfx_08003cf0(struct PaletteManager* pal, u32* dst, u32 colorData, u32* mask);
static void gfx_08003d34(struct PaletteManager* pal, u32* dest, s32* param_3, u32* param_4);
static void flashPalette_08003d84(struct PaletteManager* pal, u32* dst, s32* param_3, u32* param_4);

WIP void flashPalette_08003b24(void) {
#if MODERN
  u32 mask[3];
  mask[0] = 0x1F001F;    // 0b00000000000111110000000000011111
  mask[1] = 0x3E003E0;   // 0b00000011111000000000001111100000
  mask[2] = 0x7C007C00;  // 0b01111100000000000111110000000000
  if (gPaletteManager.filter[0] == gPaletteManager.filter[1]) {
    if (gPaletteManager.filter[0] == 0x20) {
      DmaCopy32(3, &gPaletteManager, PLTT, PLTT_SIZE);
    } else if (gPaletteManager.filter[0] < 0x20) {
      gfx_08003cf0(&gPaletteManager, (u32*)PLTT, gPaletteManager.filter[0], mask);
    } else {
      u32 val[2];
      val[0] = 0x40 - gPaletteManager.filter[0];
      val[1] = ((gPaletteManager.filter[0] - 0x21) << 16) | (gPaletteManager.filter[0] - 0x21);
      gfx_08003d34(&gPaletteManager, (u32*)PLTT, val, mask);
    }
  } else {
    u32 val[6];
    if (gPaletteManager.filter[0] < 0x21) {
      val[0] = gPaletteManager.filter[0];
      val[3] = 0;
    } else {
      val[0] = 0x40 - gPaletteManager.filter[0];
      val[3] = ((gPaletteManager.filter[0] - 0x21) << 16) | (gPaletteManager.filter[0] - 0x21);
    }

    if (gPaletteManager.filter[1] < 0x21) {
      val[1] = gPaletteManager.filter[1];
      val[4] = 0;
    } else {
      val[1] = 0x40 - gPaletteManager.filter[1];
      val[4] = ((gPaletteManager.filter[1] - 0x21) << 16) | (gPaletteManager.filter[1] - 0x21);
    }

    if (gPaletteManager.filter[2] < 0x21) {
      val[2] = gPaletteManager.filter[2];
      val[5] = 0;
    } else {
      val[2] = 0x40 - gPaletteManager.filter[2];
      val[5] = ((gPaletteManager.filter[2] - 0x21) << 16) | (gPaletteManager.filter[2] - 0x21);
    }
    flashPalette_08003d84(&gPaletteManager, (u32*)PLTT, val, mask);
  }
  if (gPaletteManager.unk_406 != 0) {
    DmaFill16(3, 0xFFFF, PLTT + gPaletteManager.unk_404, gPaletteManager.unk_406);
    gPaletteManager.unk_406 = 0;
  }
  if (gPaletteManager.unk_408 != NULL) {
    gPaletteManager.unk_408();
  }
#else
  INCCODE("asm/wip/flashPalette_08003b24.inc");
#endif
}

/**
 * @fn void LoadPalette(struct Palette* p, u32 r1)
 * @brief Palette構造体の示すパレットを gPaletteManager.buf に転送する
 * @note 0x08003c98
 */
void LoadPalette(const struct Palette* p, u32 ofs) {
  if (p->size != 0) {
    ofs += (p->dst << 5);
    if (p->lz77) {
      LZ77UnCompWram((void*)(PTR_U32(&p->src) + p->src), (u8*)&gPaletteManager.buf + ofs);
    } else {
      DmaCopy32(3, (void*)(PTR_U32(&p->src) + p->src), (u8*)&gPaletteManager.buf + ofs, p->size);
    }
  }
}

/**
 * @note 0x08003cf0
 */
NAKED static void gfx_08003cf0(struct PaletteManager* pal, u32* dst, u32 colorData, u32* mask) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	movs r4, #0xff\n\
_08003CF4:\n\
	mov lr, r1\n\
	ldr r1, [r0]\n\
	ldr r5, [r3]\n\
	ands r5, r1\n\
	muls r5, r2, r5\n\
	lsrs r5, r5, #5\n\
	ldr r6, [r3]\n\
	ands r6, r5\n\
	ldr r5, [r3, #4]\n\
	ands r5, r1\n\
	muls r5, r2, r5\n\
	lsrs r5, r5, #5\n\
	ldr r7, [r3, #4]\n\
	ands r7, r5\n\
	orrs r6, r7\n\
	ldr r5, [r3, #8]\n\
	ands r5, r1\n\
	lsrs r5, r5, #5\n\
	muls r5, r2, r5\n\
	ldr r7, [r3, #8]\n\
	ands r7, r5\n\
	orrs r6, r7\n\
	mov r1, lr\n\
	str r6, [r1]\n\
	adds r0, #4\n\
	adds r1, #4\n\
	subs r4, #1\n\
	bpl _08003CF4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	mov lr, r0\n\
	bx lr\n\
	 .syntax divided\n");
}

NAKED static void gfx_08003d34(struct PaletteManager* pal, u32* dest, s32* param_3, u32* param_4) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7}\n\
	ldr r4, [r2]\n\
	movs r7, #0xff\n\
_08003D3A:\n\
	push {r0, r1, r7}\n\
	ldr r1, [r0]\n\
	ldr r5, [r2, #4]\n\
	ldr r0, [r3]\n\
	ands r0, r1\n\
	muls r0, r4, r0\n\
	lsrs r0, r0, #5\n\
	adds r0, r0, r5\n\
	ldr r6, [r3]\n\
	ands r6, r0\n\
	lsls r5, r5, #5\n\
	ldr r0, [r3, #4]\n\
	ands r0, r1\n\
	muls r0, r4, r0\n\
	lsrs r0, r0, #5\n\
	adds r0, r0, r5\n\
	ldr r7, [r3, #4]\n\
	ands r7, r0\n\
	orrs r6, r7\n\
	lsls r5, r5, #5\n\
	ldr r0, [r3, #8]\n\
	ands r0, r1\n\
	lsrs r0, r0, #5\n\
	muls r0, r4, r0\n\
	ldr r7, [r3, #8]\n\
	adds r0, r0, r5\n\
	ands r7, r0\n\
	orrs r6, r7\n\
	pop {r0, r1, r7}\n\
	str r6, [r1]\n\
	adds r0, #4\n\
	adds r1, #4\n\
	subs r7, #1\n\
	bpl _08003D3A\n\
	pop {r4, r5, r6, r7}\n\
	bx lr\n\
	.align 2, 0\n\
 .syntax divided\n");
}

/**
 * @note 0x08003d84
 */
NAKED static void flashPalette_08003d84(struct PaletteManager* pal, u32* dst, s32* param_3, u32* param_4) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7}\n\
	movs r7, #0xff\n\
_08003D88:\n\
	push {r0, r1, r7}\n\
	ldr r1, [r0]\n\
	ldr r4, [r2]\n\
	ldr r5, [r2, #0xc]\n\
	ldr r0, [r3]\n\
	ands r0, r1\n\
	muls r0, r4, r0\n\
	lsrs r0, r0, #5\n\
	adds r0, r0, r5\n\
	ldr r6, [r3]\n\
	ands r6, r0\n\
	ldr r4, [r2, #4]\n\
	ldr r5, [r2, #0x10]\n\
	ldr r0, [r3, #4]\n\
	ands r0, r1\n\
	muls r0, r4, r0\n\
	lsrs r0, r0, #5\n\
	adds r0, r0, r5\n\
	ldr r7, [r3, #4]\n\
	ands r7, r0\n\
	orrs r6, r7\n\
	ldr r4, [r2, #8]\n\
	ldr r5, [r2, #0x14]\n\
	ldr r0, [r3, #8]\n\
	ands r0, r1\n\
	lsrs r0, r0, #5\n\
	muls r0, r4, r0\n\
	ldr r7, [r3, #8]\n\
	adds r0, r0, r5\n\
	ands r7, r0\n\
	orrs r6, r7\n\
	pop {r0, r1, r7}\n\
	str r6, [r1]\n\
	adds r0, #4\n\
	adds r1, #4\n\
	subs r7, #1\n\
	bpl _08003D88\n\
	pop {r4, r5, r6, r7}\n\
	bx lr\n\
	.align 2, 0\n\
	 .syntax divided\n");
}
