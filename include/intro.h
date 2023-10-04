#ifndef GUARD_RMZ3_INTRO_H
#define GUARD_RMZ3_INTRO_H

#include "global.h"
#include "system.h"

struct Intro {
  u8 unk_00[4];
  u8 mode[4];
  s16 titleFrame;  // タイトル画面用のフレームカウンタ
  u16 frame;
  u32 rng;
  u16 saveOK;  // ストーリーのセーブデータが正常
  s16 unk_12;
  u8 unk_14[544];
  u8 unk_234;
  u8 unk_235;
  u8 unk_236;
  u8 unk_237;
  u8 cursor;  // Selected on Titlescreen (0: NewGame, 1: Continue, 2: Minigame)
  u8 pad_239[3];
  u16 unk_23c;
  u16 unk_23e;
  u16 unk_240;
  u8 unk_242;
  u8 unk_243;
  u8 unk_244[4];
  u16 demoKeyIdx;      // 例: 08385714 のidx (080ebe84)
  u8 demoKeyFrame;     // 現在の DemoKeyIdx で経過したフレーム
  u8 demoKeyFrameEnd;  // .demoKeyFrame がこの値と等しくなったら次のidxへ
  KEY_INPUT unk_24c;
  u16 unk_24e;
  u16 unk_250;
  u8 unk_252;
  u8 unk_253;
};  // 596 bytes

typedef void (*IntroLoopFunc)(struct Intro*);

extern const IntroLoopFunc gIntroLoops[7];
extern struct Intro gIntro;

extern const struct Graphic gGraphic_Inti;
extern const struct Palette gPalette_Inti;
extern const struct Graphic gGraphic_085472a8;
extern const struct Palette gPalette_085472a8;
extern const struct Graphic gGraphic_TitleZero;
extern const struct Palette gPalette_TitleZero;
extern const struct Graphic gGraphic_TitleCiel;
extern const struct Palette gPalette_TitleCiel;

extern const struct Graphic gGraphic_OpeningAnim1;
extern const struct Palette gPalette_OpeningAnim1;
extern const struct Graphic gGraphic_OpeningAnim2;
extern const struct Palette gPalette_OpeningAnim2;

void Process_Intro(struct Process* p);
void Process_Game(struct Process* p);

void SetIntroMode(struct Intro* intro, u32 mode);

#endif  // GUARD_RMZ3_INTRO_H
