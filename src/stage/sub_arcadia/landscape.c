#include "blink.h"
#include "global.h"
#include "overworld.h"

static void FUN_08014b28(struct Coord* _ UNUSED) {
  gOverworld.work.raw[0] = 0;
  gOverworld.work.raw[1] = 0;
}

static void subAracadia_08014b48(struct Coord* _ UNUSED) {
  if ((gOverworld.unk_1c8.tilesets[0] >> 8 == STAGE_SUB_ARCADIA) && ((gOverworld.unk_1c8.tilesets[0] & 0xFF) == 0)) {
    if ((gOverworld.work.subArcadia.unk_000 & (1 << 0)) == 0) {
      gOverworld.work.subArcadia.unk_000 |= (1 << 0);
      LoadBlink(124, 0);
      LoadBlink(125, 0);
      LoadBlink(126, 0);
      LoadBlink(130, 0);
      LoadBlink(166, 0);
    }
    GetBlinkMotionState(124);
    GetBlinkMotionState(125);
    GetBlinkMotionState(126);
    GetBlinkMotionState(130);
    GetBlinkMotionState(166);

  } else if (gOverworld.work.subArcadia.unk_000 & (1 << 0)) {
    gOverworld.work.subArcadia.unk_000 ^= (1 << 0);
    ClearBlink(124);
    ClearBlink(125);
    ClearBlink(126);
    ClearBlink(130);
    ClearBlink(166);
  }

  if ((gOverworld.unk_1c8.tilesets[1] >> 8 == STAGE_SUB_ARCADIA) && ((gOverworld.unk_1c8.tilesets[1] & 0xFF) == 1)) {
    if ((gOverworld.work.subArcadia.unk_000 & (1 << 1)) == 0) {
      gOverworld.work.subArcadia.unk_000 |= (1 << 1);
      LoadBlink(127, 0);
      LoadBlink(128, 0);
      LoadBlink(129, 0);
    }
    GetBlinkMotionState(127);
    GetBlinkMotionState(128);
    GetBlinkMotionState(129);

  } else if (gOverworld.work.subArcadia.unk_000 & (1 << 1)) {
    gOverworld.work.subArcadia.unk_000 ^= (1 << 1);
    ClearBlink(127);
    ClearBlink(128);
    ClearBlink(129);
  }

  if ((gOverworld.unk_1c8.tilesets[0] >> 8 == STAGE_SUB_ARCADIA) && ((gOverworld.unk_1c8.tilesets[0] & 0xFF) == 2)) {
    if ((gOverworld.work.subArcadia.unk_000 & (1 << 2)) == 0) {
      gOverworld.work.subArcadia.unk_000 |= (1 << 2);
      LoadBlink(161, 0);
      LoadBlink(162, 0);
      LoadBlink(163, 0);
      LoadBlink(164, 0);
      LoadBlink(165, 0);
    }
    GetBlinkMotionState(161);
    GetBlinkMotionState(162);
    GetBlinkMotionState(163);
    GetBlinkMotionState(164);
    GetBlinkMotionState(165);

  } else if (gOverworld.work.subArcadia.unk_000 & (1 << 2)) {
    gOverworld.work.subArcadia.unk_000 ^= (1 << 2);
    ClearBlink(161);
    ClearBlink(162);
    ClearBlink(163);
    ClearBlink(164);
    ClearBlink(165);
  }

  if ((gOverworld.unk_1c8.tilesets[1] >> 8 == STAGE_SUB_ARCADIA) && ((gOverworld.unk_1c8.tilesets[1] & 0xFF) == 3)) {
    if ((gOverworld.work.subArcadia.unk_000 & (1 << 3)) == 0) {
      gOverworld.work.subArcadia.unk_000 |= (1 << 3);
      LoadBlink(154, 0);
      LoadBlink(155, 0);
      LoadBlink(156, 0);
      LoadBlink(157, 0);
      LoadBlink(158, 0);
      LoadBlink(159, 0);
      LoadBlink(160, 0);
    }
    GetBlinkMotionState(154);
    GetBlinkMotionState(155);
    GetBlinkMotionState(156);
    GetBlinkMotionState(157);
    GetBlinkMotionState(158);
    GetBlinkMotionState(159);
    GetBlinkMotionState(160);

  } else if (gOverworld.work.subArcadia.unk_000 & (1 << 3)) {
    gOverworld.work.subArcadia.unk_000 ^= (1 << 3);
    ClearBlink(154);
    ClearBlink(155);
    ClearBlink(156);
    ClearBlink(157);
    ClearBlink(158);
    ClearBlink(159);
    ClearBlink(160);
  }

  if (gOverworld.work.subArcadia.unk_001 == 0) {
    if (gCurStory.s.f0 & STORY_CYBER) {
      gOverworld.work.subArcadia.unk_001 = 1;
      LoadScreenIntoMetatileMap(1, 6, 78);
    }
    if (gOverworld.work.subArcadia.unk_001 == 0) {
      return;
    }
  }

  if (!(gCurStory.s.f0 & STORY_CYBER)) {
    gOverworld.work.subArcadia.unk_001 = 1;
    LoadScreenIntoMetatileMap(1, 6, 23);
  }
}

static void nop_08014e78(struct Coord* _ UNUSED) { return; }

static void FUN_08014e7c(struct Coord* _ UNUSED) {
  ClearBlink(0x7c);
  ClearBlink(0x7d);
  ClearBlink(0x7e);
  ClearBlink(0x7f);
  ClearBlink(0x80);
  ClearBlink(0x81);
  ClearBlink(0x82);
  ClearBlink(0x9a);
  ClearBlink(0x9b);
  ClearBlink(0x9c);
  ClearBlink(0x9d);
  ClearBlink(0x9e);
  ClearBlink(0x9f);
  ClearBlink(0xa0);
  ClearBlink(0xa1);
  ClearBlink(0xa2);
  ClearBlink(0xa3);
  ClearBlink(0xa4);
  ClearBlink(0xa5);
  ClearBlink(0xa6);
}

INCASM("asm/stage_gfx/sub_arcadia.inc");
