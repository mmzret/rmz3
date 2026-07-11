#ifndef GUARD_RMZ3_TEXT_H
#define GUARD_RMZ3_TEXT_H

#include "gba/gba.h"
#include "strings.h"
#include "text_window.h"
#include "types.h"

#define CHAR_NEXT 0xFD

#define MAX_STRING_COUNT 96  // 文字数ではなく文字列の数

// Glyph は gFontTall, gFontBig の1文字
typedef u16 Glyph;  // bit0..7: 文字コード (charmap.txt), bit8: ???, bit9: 赤, bit10: gFontBig を使用する, bit11: ???, bit12..15: パレットID

// Glyph allocation entry
// Glyph は gFontTall, gFontBig の1文字のこと (gFontJIS は動的割り当てしないのでここでは扱わない)
typedef struct GlyphNode {
  struct GlyphNode* next;  // 次のグリフ, 文字列の次の文字ではなく、アロケーションリストの次を指していることに注意
  Glyph c;                 // see Glyph
  u16 tileID;              // bit0..11: タイルID, bit12..14: 不使用?, bit15: 1 ならこのNodeのグリフがまだVRAMにロードされていない (FUN_080e98ec でロードされる)
} GlyphNode;
static_assert(sizeof(GlyphNode) == 8);

// 0x02030310
// TODO: 後で FontRenderer とかに名前変えたほうがいいかも
typedef struct {
  void* tilemap;                    // 0x000, BG0's tilemap
  s16 len;                          // 0x004, 現在の文字列の数 (max: MAX_STRING_COUNT)
  s16 fontBigPalID;                 // 0x006, gFontBigPalが配置されるパレットID (2 or 10)
  str_t strings[MAX_STRING_COUNT];  // 0x008, 現在表示する文字列の配列, 多分グリフの割り当てに利用
  u8 x8[MAX_STRING_COUNT];          // 0x188, 1文字目のX (8px単位)
  u8 y8[MAX_STRING_COUNT];          // 0x1E8, 1文字目のY (8px単位)
  u16 progress[MAX_STRING_COUNT];   // 0x248, 描画をどれくらい終えたか(文字数単位)
  GlyphNode glyphBuffer[80];        // 0x308, ここから GlyphNode を割り当てる, 80個のグリフを割り当てられる
  GlyphNode* cur;                   // 0x588, 現在のフレームで使用が確定しているグリフのリスト
  GlyphNode* cache;                 // 0x58C, 前のフレームで使用していたが、現在のフレームではまだ使用が確定していないグリフ, 確定したら cur に移動する, 所謂LRUキャッシュ, 文字列という性質上、前のフレームで使用していたグリフは次のフレームでも使われる可能性が高い
  GlyphNode* freelist;              // 0x590, 未割り当てのグリフのリスト
  char_t* variable;                 // 0x594, 文字コードF9で挿入されるテキスト
  u8 startX;                        // 0x598
  u8 startY;                        // 0x599
  u8 endX;                          // 0x59A
  u8 endY;                          // 0x59B
  u32 unk_59c;                      // 0x59C
} TextPrinter;
static_assert(sizeof(TextPrinter) == 1440);

extern TextPrinter gTextPrinter;
extern char_t gTerminateCharCode;

extern const u8 gFontJIS[][TILE_SIZE_4BPP];

void LoadAsciiBold(void);
void ResetCharTiles(void);
void LoadJISKana(void);
void FUN_080e981c(void);
void FUN_080e9840(void);
void PrintAllStrings(void);
void FUN_080e98ec(void);
void PrintString(const char_t* s, u32 x, u32 y);
s16 getStringLength(char_t* s);
void text_080e9b40(const char_t* s, u32 x, u32 y, u16 count);
void PrintRows(char_t* s, u32 x, u32 y, u16 count, u16 r4);
void PrintJISString(const char_t* s, u32 x8, u32 y8);
char_t* SkipString(char_t* s, s32 skipBytesize);

#endif  // GUARD_RMZ3_TEXT_H
