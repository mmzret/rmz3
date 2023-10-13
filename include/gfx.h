#ifndef GUARD_RMZ3_GFX_H
#define GUARD_RMZ3_GFX_H

#include "anim_loader.h"
#include "constants/constants.h"
#include "gba/gba.h"
#include "gpu_regs.h"

#define COLOR 2

// Graphic.props
#define CHUNKED (1 << 0)
#define LZ77 0x0002
#define NO_PAL 0x0004
#define BPP4 0x0020
#define RLU (1 << (4 + 8))

#define PROPS1(g) (*(u8*)&g->props)
#define PROPS2(g) (*((u8*)&g->props + 1))
#define IS_RLU_COMPRESSED(g) (PROPS2(g) & (RLU >> 8))

#define BGCNT16(n) *((u16*)&gVideoRegBuffer.bgcnt[n])
#define CHAR_BASE(n) ((*((u16*)&gVideoRegBuffer.bgcnt[n]) & 0xc) << 0xc)
#define SCREEN_BASE(n) (gVideoRegBuffer.bgcnt[n].screenBaseBlock * 0x800)
#define SCREEN_BASE_16(n) ((BGCNT16(n) & 0x1F00) << 3)
#define PALETTE16(n) (*(u16*)(&gPaletteManager.buf[0]))

#if MODERN
#define STATIC_GRAPHICS ((void*)(&gStaticMotionGraphics[0]))
#define STATIC_PALETTES ((void*)(&(gStaticMotionGraphics[0].pal)))
#define BGMAP(n) ((void*)(gBgMapOffsets[n] + (void*)&gBgMapOffsets[n] + 8))
#define TILESETS(id, ofs) (&((struct ColorGraphic*)(OFFSET_TABLE(gStageTilesetOffsets, id)))[ofs])
#else
#define STATIC_GRAPHICS ((void*)(0x085d78f8))
#define STATIC_PALETTES ((void*)(0x085d7904))
#define BGMAP(n) ((void*)(*((u32*)(0x085222a0 + (n * 4))) + (0x085222a0 + (n * 4) + 8)))
#define TILESETS(id, ofs) ((struct ColorGraphic*)(*((u32*)(0x087044b0 + (id * 4))) + (0x087044b0 + (id * 4)) + (ofs * 20)))
#endif

#if MODERN
#define BG_GRAPHIC(n) ((const struct Graphic*)&((struct ColorGraphic*)&gGraphic_Capcom)[(n)])
#define BG_PALETTE(n) ((const struct Palette*)&(((struct ColorGraphic*)&gGraphic_Capcom)[(n)].pal))
#else
#define BG_GRAPHIC(n) ((const struct Graphic*)((void*)(0x08547280) + ((n) * (sizeof(struct ColorGraphic)))))
#define BG_PALETTE(n) ((const struct Palette*)((void*)(0x0854728C) + ((n) * (sizeof(struct ColorGraphic)))))
#endif

/**
 * @brief 0x080036cc の関数で src -> dst に転送が行われる (Transfer gfx data from src to dest by 0x080036cc)
 * @details
 *  Graphic構造体、Bgmapなどさまざまなグラフィックデータを転送する (gfx data is Graphic struct, Bgmap, etc...)
 */
struct GraphicTransfer {
  u32 type : 2;  // 0: struct Graphic, 1: BG map, 2: ???(0x08003a08), 3: ???
  u32 unk : 30;
  void* dst;
  void* src;
};

// 0x02001fc4
// 0x080036ccで 毎フレームごとに、 DMA3 で VRAM に転送される
struct Bg0Mask {
  u32 bytesize;  // 転送されるバイトサイズ

  /*
    ここにアドレスがセットされている場合、
    080036cc で .mask のデータが アドレス(0x6000000 + .map)に転送される
    (このアドレス自体は使わない？)
  */
  void* bg0;
  u32 map;   // 転送先のBgMap offset
  u32 mask;  // マスクデータ(u16 x 2)
};

// 0x02001f00
struct GraphicTransferManager {
  s32 len;  // .tasks のうち、有効なタスク数(.tasks length)
  struct GraphicTransfer tasks[16];
  struct Bg0Mask bg0mask;
};

// 0x03002ac0
struct PaletteManager {
  struct PlttData buf[512];
  u8 filter[3];  // 画面にかけるRGB555で指定する色のフィルター(0x20でその色のフィルターなし)
  u16 unk_404;
  u16 unk_406;
  VoidFunc unk_408;
  u32 _;
};  // 1040 bytes

// 0x03002ed0
struct OamManager {
  struct OamData buf[128];
  struct OamData* p;
  u32 dispcnt;
  u8 unk_408[8];
};

struct OamDataNoAffine {
  u32 y : 8;
  u32 affineMode : 2;  // 0x1, 0x2 = 0x3
  u32 objMode : 2;     // 0x4, 0x8 = 0xC
  u32 mosaic : 1;      // 0x10
  u32 bpp : 1;         // 0x20
  u32 shape : 2;       // 0x40, 0x80
  u32 x : 9;
  u32 unused : 3;
  u32 xflip : 1;
  u32 yflip : 1;
  u32 size : 2;

  u16 tileNum : 10;
  u16 priority : 2;
  u16 paletteNum : 4;
  u16 _;
};

// グラフィックデータ(タイルデータ)の情報を持った構造体(ヘッダみたいなもの)
struct Graphic {
  s32 src;        // tile data starts from `(u8 *)&src + src`
  u32 size : 22;  // unit is byte.
  u32 ofs : 10;
  u16 chunkSize;  // If graphic is not chunked, this value is unused.

  // bit0:     is chunked? (chunk mode)
  // bit1:     is LZ77 compressed?
  // bit5:     is 4BPP?
  // bit6:     is 8BPP?
  // bit12:    is RLU compressed?
  // props & 0x7F8 is ofsUnit (4BPP: 32, 8BPP: 64)
  u16 props;
};

// パレットの情報を持った構造体(ヘッダみたいなもの)
struct Palette {
  u32 src;     // palette data starts from `(void *)&src + src`
  u16 size;    // unit is byte
  bool8 lz77;  // lz77 compressed?
  u8 dst;
};

struct ColorGraphic {
  struct Graphic g;
  struct Palette pal;
};

// --------------------------------------------

/*
  0x02001f00
  グラフィックデータを転送するタスクデータが入っている
  毎フレーム、ここに入っているタスクが 関数 0x080036cc で実行されグラフィックデータが転送される
*/
extern struct GraphicTransferManager gGraphicTransferManager;

extern struct PaletteManager gPaletteManager;
extern struct OamManager gOamManager;

// 085d78f8 からの Graphic のpal.dstが入っている (08017aa8 参照)
extern u16 wStaticMotionPalIDs[STATIC_MOTION_COUNT + 2];

// 085d78f8 からの Graphic が配置される最初のタイル番号が入っている (08017aa8 参照)
extern u16 wStaticGraphicTilenums[STATIC_MOTION_COUNT + 2];

extern const struct ColorGraphic gStaticMotionGraphics[STATIC_MOTION_COUNT];
#define gStaticGraphic(ofs) ((const struct Graphic*)(STATIC_GRAPHICS + ofs))
#define gStaticPalette(ofs) ((const struct Palette*)(STATIC_PALETTES + ofs))

extern const struct ColorGraphic gMiscTilesetGraphics[177];

extern const struct Graphic gGraphic_Capcom;
extern const struct Palette gPalette_Capcom;

extern const u32 gBgMapOffsets[134];

extern const u32 gStageTilesetOffsets[19];

// --------------------------------------------

void doGraphicTransferTasks(void);
void LoadGraphic(const struct Graphic* g, void* dst);
void LoadPalette(const struct Palette* p, u32 r1);
s32 RequestGraphicTransfer(const struct Graphic* g, void* dst);
s32 RequestBgMapTransfer(u16* src, void* dst, s32 r2);
void MaskBg0(u32* bg0, u32 bg0map, u32 bytesize, u16 mask);
void UnmaskBg0(void);
void flashPalette_08003b24(void);

#endif  // GUARD_RMZ3_GFX_H
