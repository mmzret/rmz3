#include "gfx.h"

#include "gba/gba.h"
#include "global.h"
#include "motion.h"

// GraphicTransfer.type
enum TransferType {
  TT_GRAPHIC,    // struct Graphic
  TT_BG_MAP,     // BG map
  TT_VRAM_FILL,  // VRAM fill
};

/**
 * @brief VRAM全体を 0x11111111 で埋める (Reset VRAM by filling 0x11111111)
 */
void ClearVRAM(void) {
  gGraphicTransferManager.len = 0;
  gGraphicTransferManager.bg0.buffer = NULL;
  DmaFill32(3, 0x11111111, VRAM, VRAM_SIZE);
}

/**
 * @brief 0x02001f00 のタスクどおりに転送を行う
 */
void doGraphicTransferTasks(void) {
  s32 i;
  struct GraphicTransferManager* gtman = &gGraphicTransferManager;
  s32 len = gtman->len;

  if ((gtman->bg0).buffer != NULL) {
    // buffer を dst に転送した後で, backdrop で buffer をクリア
    DmaCopy32(3, (gtman->bg0).buffer, (void*)(VRAM + (gtman->bg0).dst), (gtman->bg0).bytesize);
    DmaFill32(3, (gtman->bg0).backdrop, (gtman->bg0).buffer, (gtman->bg0).bytesize);
  }

  while (len != 0) {
    struct GraphicTransfer* t = &gGraphicTransferManager.tasks[--len];
    u32 type = t->type;
    if (type != TT_GRAPHIC) {
      if (type == TT_BG_MAP) {
        // 1: BG map
        if (t->bytesize < 32) {
          CpuCopy16(t->src, VRAM + t->dst, t->bytesize);
        } else {
          CpuFastCopy(t->src, VRAM + t->dst, t->bytesize);
        }
      } else {
        // 2, 3: VRAM fill
        CpuFastFill(t->src, VRAM + t->dst, t->bytesize);
      }
    } else {
      LoadGraphic((void*)t->src, t->dst);  // 0: struct Graphic
    }
  }

  gGraphicTransferManager.len = 0;
}

// このグラフィックを構成するタイル1枚あたりのバイト数(e.g. 4bpp: TILESIZE(g) = 32, 8bpp: 64)
#define TILESIZE(g) ((u32)g->tilesize << 3)

// 0x080037c0
void LoadGraphic(const struct Graphic* g, void* dst_vram_offset) {
  if (g->size != 0) {
    dst_vram_offset += g->tileId * TILESIZE(g);

    // VRAM layout
    if (g->map2d) {
      void* src = SELF_REL_PTR(&g->src);
      s32 size = g->size;

      if (g->lz77) {
        while (size > 0) {
          // block
          //   u32 bytesize : 30;   // bit0..30
          //   u32 compressed : 1;  // bit31
          //   u8 data[.bytesize];
          if ((*(u32*)src) & (1 << 31)) {
            u32 buf[8];
            CpuFastCopy(VRAM + dst_vram_offset + g->rowsize, buf, 32);
            LZ77UnCompVram(src + 4, VRAM + dst_vram_offset);
            CpuFastCopy(buf, VRAM + dst_vram_offset + g->rowsize, 32);
          } else {
            CpuFastCopy(src + 4, VRAM + dst_vram_offset, g->rowsize);
          }
          // Next row
          dst_vram_offset += TILESIZE(g) << 5;  // BGマップは 1行32タイルなので (<< 5) で次の行に移動
          size -= (*(u32*)src) & 0x7FFFFFFF;
          src += (*(u32*)src) & 0x7FFFFFFF;
        }

      } else if (g->rlu) {
        while (size > 0) {
          // block
          //   u32 bytesize : 30;   // bit0..30
          //   u32 compressed : 1;  // bit31
          //   u8 data[.bytesize];
          if ((*(u32*)src) & (1 << 31)) {
            RLUnCompVram(src + 4, VRAM + dst_vram_offset);
          } else {
            CpuFastCopy(src + 4, VRAM + dst_vram_offset, g->rowsize);
          }
          // Next row
          dst_vram_offset += TILESIZE(g) << 5;  // BGマップは 1行32タイルなので (<< 5) で次の行に移動
          size -= (*(u32*)src) & 0x7FFFFFFF;
          src += (*(u32*)src) & 0x7FFFFFFF;
        }

      } else {
        while (size > 0) {
          CpuFastCopy((void*)src, VRAM + dst_vram_offset, g->rowsize);
          // Next row
          dst_vram_offset += TILESIZE(g) << 5;  // BGマップは 1行32タイルなので (<< 5) で次の行に移動
          src += g->rowsize;
          size -= g->rowsize;
        }
      }

    } else {
      if (g->lz77) {
        LZ77UnCompVram(SELF_REL_PTR(&g->src), VRAM + dst_vram_offset);
      } else if (g->rlu) {
        RLUnCompVram(SELF_REL_PTR(&g->src), VRAM + dst_vram_offset);
      } else {
        CpuFastCopy(SELF_REL_PTR(&g->src), VRAM + dst_vram_offset, g->size);
      }
    }
  }
}

/**
 * @brief Graphic構造体を gGraphicTransferManager(0x02001f00) に追加する
 * @note 0x08003934
 */
s32 RequestGraphicTransfer(const void* g, void* dst_vram_offset) {
  u32 i;

  // Check same request
  for (i = 0; i < gGraphicTransferManager.len; i++) {
    if (((struct Graphic*)gGraphicTransferManager.tasks[i].src == g) && (gGraphicTransferManager.tasks[i].dst == dst_vram_offset)) {
      return 0;  // Already requested
    }
  }
  if ((u32)gGraphicTransferManager.len < 16) {
    gGraphicTransferManager.tasks[i].dst = dst_vram_offset;
    gGraphicTransferManager.tasks[i].type = TT_GRAPHIC;
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
s32 RequestBgMapTransfer(u16* src, void* dst_vram_offset, s32 bytesize) {
  const s32 len = gGraphicTransferManager.len;
  if (len < 16) {
    gGraphicTransferManager.tasks[len].type = TT_BG_MAP;
    gGraphicTransferManager.tasks[len].bytesize = bytesize;
    gGraphicTransferManager.tasks[len].dst = dst_vram_offset;
    gGraphicTransferManager.tasks[len].src = src;
    gGraphicTransferManager.len++;
    return 0;
  }
  return -1;
}

/**
 * @return 0(success), -1(fail)
 * @note 0x08003a08
 * @remark バイル研究所くらいでしか使ってない
 */
s32 RequestVRAMFill(u32 fillval, void* dst_vram_offset, s32 bytesize) {
  const s32 len = gGraphicTransferManager.len;
  if (len < 16) {
    gGraphicTransferManager.tasks[len].type = TT_VRAM_FILL;
    gGraphicTransferManager.tasks[len].bytesize = bytesize;
    gGraphicTransferManager.tasks[len].dst = dst_vram_offset;
    gGraphicTransferManager.tasks[len].src = (void*)fillval;
    gGraphicTransferManager.len++;
    return 0;
  }
  return -1;
}

// 0x08003a64
void EnableBG0(u32* buffer, u32 dst, u32 bytesize, u16 backdrop) {
  gGraphicTransferManager.bg0.buffer = (void*)buffer;
  gGraphicTransferManager.bg0.dst = dst;
  gGraphicTransferManager.bg0.bytesize = bytesize;
  gGraphicTransferManager.bg0.backdrop = ((((u32)backdrop) << 16) | backdrop);
  DmaFill32(3, gGraphicTransferManager.bg0.backdrop, buffer, bytesize);
}

// Disable BG0 (HUD layer)
void DisableBG0(void) {
  gGraphicTransferManager.bg0.buffer = NULL;
  return;
}
