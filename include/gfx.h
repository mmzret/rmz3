#ifndef GUARD_RMZ3_GFX_H
#define GUARD_RMZ3_GFX_H

#include "anim_loader.h"
#include "constants/constants.h"
#include "gba/gba.h"
#include "gpu_regs.h"
#include "tileset_anims.h"

extern char gBgGraphics[];

// shit
#if MODERN
#define BGMAP(n) (SELF_REL_PTR(&gBgMapOffsets[n]) + sizeof(struct BgMapHeader))
#define BG_PALETTE(n) ((void*)&(((ColorGraphic*)&gGraphic_Capcom)[(n)].pal))
#else
#define _gBgMapOffsets 0x085222a0  // gBgMapOffsets
#define _gBgPalettes 0x0854728C    // gBgGraphics + 12
#define BGMAP(n) (SELF_REL_PTR((u32*)(_gBgMapOffsets + (n * 4))) + sizeof(struct BgMapHeader))
#define BG_PALETTE(n) ((void*)(_gBgPalettes + (n) * sizeof(ColorGraphic)))
#endif

#define BG_GRAPHIC(n) ((void*)((((u32)gBgGraphics) + ((n) * sizeof(ColorGraphic)))))

// PaletteManager.filter
#define FILTER_BLACK 0x00
#define FILTER_NONE 0x20
#define FILTER_WHITE 0x40

/**
 * @brief 0x080036cc の関数で src -> dst に転送が行われる (Transfer gfx data from src to dest by 0x080036cc)
 * @details
 *  Graphic構造体、Bgmapなどさまざまなグラフィックデータを転送する (gfx data is Graphic struct, Bgmap, etc...)
 */
struct GraphicTransfer {
  u32 type : 2;  // 0: struct Graphic, 1: BG map, 2: ???(0x08003a08), 3: ???
  u32 bytesize : 30;
  void* dst;
  void* src;
};
static_assert(sizeof(struct GraphicTransfer) == 12);

// 0x02001f00
struct GraphicTransferManager {
  s32 len;                           // 0x00, .tasks のうち、有効なタスク数(.tasks length)
  struct GraphicTransfer tasks[16];  // 0x04

  // 0xC4
  struct BG0Manager {
    u32 bytesize;  // buffer のサイズ
    void* buffer;  // BGマップのバッファ
    u32 dst;       // buffer の転送先
    u32 backdrop;  // BG0に何も描画されないときのデフォルトカラー
  } bg0;           // 0x02001fc4
};
static_assert(sizeof(struct GraphicTransferManager) == 212);

// 0x03002ac0
struct PaletteManager {
  u16 buf[512];
  u8 filter[3];  // Fadeレベル (0x0: 真っ黒, 0x20: フェードなし, 0x40: 真っ白), [0] = Red, [1] = Green, [2] = Blue
  u16 unk_404;
  u16 unk_406;
  void (*post_process)(void);  // 最終的なパレットに対して、適用される関数, このゲームでは、サイバー空間 で画面を緑っぽくする用途でのみ使われている
};  // 1036 bytes
static_assert(sizeof(struct PaletteManager) == 1036);

// 0x03002ed0
struct OamManager {
  struct OamData buf[128];
  struct OamData* p;
  u32 dispcnt;
};  // 1032 bytes
static_assert(sizeof(struct OamManager) == 1032);

struct Graphic {
  u32 src;          // 0x0: SELF_REL_PTR(&src)
  u32 size : 22;    // unit is byte.
  u32 tileId : 10;  // dst tile id in VRAM
  u16 rowsize;      // 0x8: map2d が 1のときに、1行あたりのサイズ(バイト単位), 詳しくは LoadGraphic の map2d のところを参照
  // 0xA, attributes
  u16 map2d : 1;     // bit0, VRAMにタイルデータを配置する時のレイアウト, タイルアニメーションや選択中のエルフのカテゴリ名など サイズが小さめで表示内容が頻繁に変化するグラフィックデータのために使っているっぽい, 0: linear(1D), 1: non-linear(2D)
  u16 lz77 : 1;      // bit1, LZ77 compressed?
  u16 no_pal : 1;    // bit2, Graphic構造体の後ろに、使わないがPalette構造体があることを示すフラグ (ColorGraphic[] として扱いたいときのPadding), プログラム上では使われてなくて、あくまで開発者にわかりやすくするためのものと思われる?
  u16 tilesize : 8;  // bit3..10: (g->tilesize << 3) がこのグラフィックを構成するタイル1枚あたりのバイト数 (様々な bpp を想定していた?)
  u16 prop_b11 : 1;  // bit11: ???
  u16 rlu : 1;       // bit12, RLU compressed
  u16 prop_b13 : 3;  // bit13..15: ???
};
static_assert(sizeof(struct Graphic) == 12);

// パレットの情報を持った構造体(ヘッダみたいなもの)
struct Palette {
  u32 src;     // palette data starts from `(void *)&src + src`
  u16 size;    // unit is byte
  bool8 lz77;  // lz77 compressed?
  u8 dst;      // PaletteID (0..15)
};
static_assert(sizeof(struct Palette) == 8);

typedef struct {
  struct Graphic g;
  struct Palette pal;
} ColorGraphic;
static_assert(sizeof(ColorGraphic) == 20);

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

extern const ColorGraphic gStaticMotionGraphics[STATIC_MOTION_COUNT];

extern const struct Graphic gGraphic_Capcom;
extern const struct Palette gPalette_Capcom;

extern const struct Graphic gGraphic_MiscMenu;
extern const struct Palette gPalette_MiscMenu;

extern const u32 gBgMapOffsets[134];

extern const u32 gStageTilesetOffsets[19];
extern const ColorGraphic gTilesetAnims[177];

// --------------------------------------------

void LoadGraphic(const struct Graphic* g, void* dst_vram_offset);
void LoadPalette(const struct Palette* p, u32 r1);
s32 RequestGraphicTransfer(const void* g, void* dst_vram_offset);
s32 RequestBgMapTransfer(u16* src, void* dst_vram_offset, s32 bytesize);
void EnableBG0(u32* buffer, u32 dst, u32 bytesize, u16 backdrop);
void DisableBG0(void);

#endif  // GUARD_RMZ3_GFX_H
