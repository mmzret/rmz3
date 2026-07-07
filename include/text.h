#ifndef GUARD_RMZ3_TEXT_H
#define GUARD_RMZ3_TEXT_H

#include "gba/gba.h"
#include "text_window.h"
#include "types.h"

#define STRING(n) (&gStringData[StringOfsTable[(n)]])

#define MAX_STRING_COUNT 96  // 文字数ではなく文字列の数

struct CharTile {
  struct CharTile* next;
  u16 c;  // 上位1バイトstyled, 下位1バイトは CharCode
  u16 tileID;
};
static_assert(sizeof(struct CharTile) == 8);

// 02030310 , lenが1以上の時、配列96のテキストをidx=0からlen個画面に表示する
typedef struct {
  void* tilemap;                    // 0x000, BG0's tilemap
  s16 len;                          // 0x004
  s16 unk_002;                      // 0x006, 多分、(現在のフォントの)パレットID
  str_t strings[MAX_STRING_COUNT];  // 0x008, 文字列の内容 e.g. 0x08374142, 0x0837c6da, 0x08377b60, 0x08376be6
  u8 x8[MAX_STRING_COUNT];          // 0x188, 1文字目のX (8px単位)
  u8 y8[MAX_STRING_COUNT];          // 0x1E8, 1文字目のY (8px単位)
  u16 progress[MAX_STRING_COUNT];   // 0x248, 描画をどれくらい終えたか(文字数単位)
  struct CharTile tilelist[80];     // 0x308
  struct CharTile* cur;             // 0x588, 次に描画する文字
  struct CharTile* used;            // 0x58C, 一度curとして使われたもの
  struct CharTile* freelist;        // 0x590
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

extern const u8 gFontBold[][TILE_SIZE_4BPP];

void LoadAsciiBold(void);
void ResetCharTiles(void);
void LoadKatakanaBold(void);
void FUN_080e981c(void);
void FUN_080e9840(void);
void PrintAllStrings(void);
void FUN_080e98ec(void);
void PrintString(const char_t* s, u32 x, u32 y);
s16 getStringLength(char_t* s);
void text_080e9b40(const char_t* s, u32 x, u32 y, u16 count);
void PrintRows(char_t* s, u32 x, u32 y, u16 count, u16 r4);
void PrintUnicodeString(const char_t* s, u32 x8, u32 y8);
char_t* SkipString(char_t* s, s32 skipBytesize);

#endif  // GUARD_RMZ3_TEXT_H
