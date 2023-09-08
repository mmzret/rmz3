#ifndef GUARD_RMZ3_TEXT_H
#define GUARD_RMZ3_TEXT_H

#include "gba/gba.h"
#include "text_window.h"
#include "types.h"

#define STRING(n) (&gStringData[StringOfsTable[n]])

// gTextWindow.text.flag
#define TEXT_FLAG_TERMINATE (1 << 1)  // セットすると会話が強制的に終わった

// gTextWindow.text.mode
#define TEXT_MODE_OPTION (1 << 2)

// gTextWindow.props.kind
#define MUGSHOT 1

#define MAX_STRING_COUNT 96  // 文字数ではなく文字列の数

struct CharTile {
  struct CharTile* next;
  u16 c;  // 上位1バイトstyled, 下位1バイトは CharCode
  u16 tileID;
};

// 02030314 , lenが1以上の時、配列96のテキストをidx=0からlen個画面に表示する
struct TextPrinter {
  tile_id_t* bg0;  // BG0's tilemap
  s16 len;
  s16 unk_002;
  str_t strings[MAX_STRING_COUNT];  // 文字列の内容 e.g. 0x08374142, 0x0837c6da, 0x08377b60, 0x08376be6
  u8 x[MAX_STRING_COUNT];           // 1文字目のX
  u8 y[MAX_STRING_COUNT];           // 1文字目のY
  s16 progress[MAX_STRING_COUNT];   // 描画をどれくらい終えたか(文字数単位)
  struct CharTile tilelist[80];
  struct CharTile* cur;   // 次に描画する文字
  struct CharTile* used;  // 一度curとして使われたもの
  struct CharTile* freelist;
  char_t* inserted;  // 文字コードF9で挿入されるテキスト
  u8 startX;
  u8 startY;
  u8 endX;
  u8 endY;
  u32 unk_598;
};  // 1436 bytes

extern struct TextPrinter gTextPrinter;
extern char_t gTerminateCharCode;

extern const u8 gFontBold[][TILE_SIZE_4BPP];
extern const struct PlttData gFontPalette[96];

extern const u16* const gTextOffsetTable[20];
extern const char_t* const gTextTable[20];

void text_080e9730(void);
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
void PrintUnicodeString(u8* s, u32 x, u32 y);
char_t* SkipString(char_t* s, s32 skipBytesize);

#endif  // GUARD_RMZ3_TEXT_H
