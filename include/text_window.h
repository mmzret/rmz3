#ifndef GUARD_RMZ3_TEXT_WINDOW_H
#define GUARD_RMZ3_TEXT_WINDOW_H

#include "gba/gba.h"
#include "types.h"

#define TW_NORMAL 0
#define TW_OPTION 1

// gTextWindow.text.mugshot
#define NO_MUGSHOT 1

struct TextWindowText {
  /*
    bit0: ???
    bit1: セットすると会話が強制的に終わった
  */
  u16 flag;

  /*
    bit0: 文字を1つずつ書いている途中
    bit1: 三角ボタンが出てユーザー入力待ち
    bit2: ユーザーが選ぶ必要あり
  */
  u16 mode;
  u8 mugshot;
  u8 y;                // 大きくするとメッセージウィンドウの位置が下がる(後ろの黒部分は固定)
  bool8 mugshotRight;  // 顔アイコンがウィンドウの右側か
  u8 optionID;

  /*
    0x01: 選択肢付き
    0x50: 自動文字送り
  */
  u32 textType;

  /*
    1: 顔つきメッセージ
    2: 画面下メッセージ(inline)
  */
  struct {
    u8 kind;
    u8 phase;
    bool8 prompt;
    u8 _;
  } props;
  u16 len;   // .current の文字数
  u16 done;  // 処理済みの文字数
  u16 frame;
  u16 unk_16;
  char_t* start;
  char_t* current;
  char_t* next;
  char_t* optional_next;
};  // 40 bytes

// ウィンドウ付きテキスト 0x020308d0
struct TextWindow {
  u32 frame;  // 詳細不明
  tile_id_t* bg0Mask;
  struct TextWindowText text;
};

typedef void (*TextFunc)(struct TextWindowText*);

extern struct TextWindow gTextWindow;

void ClearTextWindow(void* bg0);
void UpdateTextWindow(void);
void PrintNormalMessage(TextID n);
void PrintTextWindow(TextID n, u16 kind);
void PrintOptionMessage1(TextID n);
void PrintOptionMessage2(TextID n);
void PrintResultInline(TextID t, bool16 ng);

#endif  // GUARD_RMZ3_TEXT_WINDOW_H
