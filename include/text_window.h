#ifndef GUARD_RMZ3_TEXT_WINDOW_H
#define GUARD_RMZ3_TEXT_WINDOW_H

#include "gba/gba.h"
#include "types.h"

// TextWindowText.flag
#define TEXT_FLAG_UNK0 (1 << 0)       // ???
#define TEXT_FLAG_TERMINATE (1 << 1)  // セットすると会話が強制的に終わった
#define TEXT_FLAG_UNK2 (1 << 2)       // ???
#define TEXT_FLAG_UNK3 (1 << 3)       // ???

// TextWindowText.mode
#define TWM_TYPING (1 << 0)        // 文字を1つずつ書いている途中
#define TWM_WAITING (1 << 1)       // 三角ボタンが出てユーザー入力待ち
#define TEXT_MODE_OPTION (1 << 2)  // ユーザーが選ぶ必要あり

// TextWindowText.textType
#define TW_NORMAL 0
#define TW_OPTION 1

// TextWindowText.mugshot
#define NO_MUGSHOT 1

// TextWindowText.state.u8[0], index of _UpdateTextWindow's routine table
enum TextWindowState {
  TWK_NONE,     // 0: 現在メッセージなし, _UpdateTextWindow_0_Nop
  TWK_MUGSHOT,  // 1: 顔つきメッセージ, _UpdateTextWindow_1_MugshotMessage
  TWK_INLINE,   // 2: 画面下メッセージ(inline), _UpdateTextWindow_2_InlineMessage
  TWK_UNK3,     // 3: ???, _UpdateTextWindow_3_Unk3
};

typedef struct {
  u16 flag;               // 0x00, bit0: TEXT_FLAG_UNK0,  bit1: TEXT_FLAG_TERMINATE
  u16 mode;               // 0x02, see TWM_TYPING, TWM_WAITING, TEXT_MODE_OPTION
  u8 mugshot;             // 0x04, =1 のときに 顔アイコンなしのメッセージウィンドウなのは確定
  u8 y8;                  // 0x05, 大きくするとメッセージウィンドウの位置が下がる(後ろの黒部分は固定)
  bool8 mugshotRight;     // 0x06, 顔アイコンがウィンドウの右側か
  u8 optionID;            // 0x07
  s32 textType;           // 0x08, 0x01: 選択肢付き, 0x50: 自動文字送り
  State32 state;          // 0x0C, see TextWindowState
  s16 len;                // 0x10, .current の文字数
  s16 done;               // 0x12, 処理済みの文字数
  s16 frame;              // 0x14
  s16 unk_16;             // 0x16
  char_t* start;          // 0x18
  char_t* current;        // 0x1C
  char_t* next;           // 0x20
  char_t* optional_next;  // 0x24
} TextWindowText;         // 40 bytes
static_assert(sizeof(TextWindowText) == 40);

// ウィンドウ付きテキスト 0x020308d0
struct TextWindow {
  u32 frame;            // 0x00
  void* buffer;         // 0x04, (BG0の)BGマップのバッファ
  TextWindowText text;  // 0x08
};
static_assert(sizeof(struct TextWindow) == 48);

extern struct TextWindow gTextWindow;

void ClearTextWindow(void* bgmap);
void UpdateTextWindow(void);
void PrintNormalMessage(TextID n);
void PrintTextWindow(TextID n, u16 kind);
void PrintOptionMessage1(TextID n);
void PrintOptionMessage2(TextID n);
void PrintResultInline(TextID t, bool16 ng);

#endif  // GUARD_RMZ3_TEXT_WINDOW_H
