#ifndef GUARD_RMZ3_MENU_H
#define GUARD_RMZ3_MENU_H

#include "gba/gba.h"
#include "types.h"

/*
  GameState.mode:
    idx=0: 01 (固定 メニューモードを表す)
    idx=1: 2 = メニュー開いてる
    idx=2: スライド中なら2
    idx=3: メインメニューなら選択しているコンポーネント メイン=1, サブ=2, ..., フット=6
*/

struct Elf;
struct Widget;
struct Zero;

struct GameState;
typedef void (*MenuLoopFunc)(struct GameState*);
typedef struct Elf* (*MenuElfFunc)(struct Zero*, u8, u8, u8);

#define MENU (&(g->sceneState).menu)
#define ELF_MENU (&((g->sceneState).menu).elf)
#define EXSKILL_MENU (&((g->sceneState).menu).exskill)

struct SquareCursorWidget;
struct ExSkillMenuState {
  struct SquareCursorWidget* cursor;  // カーソル
  u8 selected;
  bool8 inactive;  // 現在EXスキルメニュー中か
  u16 _;
};

struct KeyConfigMenuState {
  u8 y;  // キーコンフィグでカーソルが何行目か
  u8 plttAnimID;
  u16 _;
};

struct ElfMenuState {
  cyberelf_t displayed[6];  // 現在表示中のエルフのID
  u8 y;                     // サテライト1などのエルフのリストで上から何行目のエルフを選択しているか(リストの一番上からのオフセット)
  u8 mode;                  // サテライト1, サテライト2などのトップメニューでのRow
  u8 tab;                   // サテライト1なら0がナース系, 1がアニマル系, 2がハッカー系
  u8 cursor;                // サテライト1などのエルフのリストでページの上から何行目のエルフを選択しているか(ページ=6行分)
  u8 unk_a;
  u8 unk_b;
  u8 plttAnimID;
  u8 unk_d;
  u8 unk_e;
  u8 unk_f;
};

// ResultState とメモリ共有
struct MenuState {
  u8 unk_00[4];
  u16 frame;
  u16 unk_06;
  u16 unk_08;
  u8 unk_0a;
  u8 unk_0b;
  u8 unk_0c;
  u8 unk_0d;
  u8 unk_0e;
  u8 unk_0f;
  u32 rank;
  struct Widget* mc_14;  // e.g. 0203d938
  struct Widget* mc_18;  // e.g. 0203d830
  u8 unk_1c[8];

  struct ExSkillMenuState exskill;
  struct KeyConfigMenuState kc;  // 0x2c..
  struct ElfMenuState elf;
  u8 unk_40[8];
  cyberelf_t satelites[2];
  u8 unk_4a;
  u8 unk_4b;
  u8 unk_4c;
  u8 unk_4d;
  u8 unk_4e;
  u8 unk_4f;
  u8 unk_50;
  u8 unk_51;
  u8 attackMode;  // 0x52
  u8 unk_53[173];
};

bool8 TrySlideMenu(struct GameState* g);

struct BgMapHeader;
void CopyBgMap(u16* dst, struct BgMapHeader* src, u8 x, u8 y);

#endif  // GUARD_RMZ3_MENU_H
