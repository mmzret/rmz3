#include "blink.h"
#include "global.h"
#include "overworld.h"

static void initWeilLabo(struct Coord* _ UNUSED);
static void FUN_08015010(struct Coord* _ UNUSED);
static void nop_08015244(struct Coord* _ UNUSED);
static void exitWeilLabo(struct Coord* _ UNUSED);

static void initWeilLabo(struct Coord* _ UNUSED) {
  gOverworld.work.weilLabo.unk_000 = 0;
  gOverworld.unk_1c8.work[2] = 0;
  gOverworld.unk_1c8.work[3] = 0;
  gOverworld.unk_1c8.work[0] = 0;
  gOverworld.unk_1c8.work[1] = 0;
  gOverworld.work.weilLabo.unk_00c = 0;
  gOverworld.work.weilLabo.unk_010.x = 0x1dd000;
  gOverworld.work.weilLabo.unk_010.y = 0x55000;
  gOverworld.work.weilLabo.unk_018 = 0;
  gOverworld.work.weilLabo.unk_01c = 0;
  gOverworld.work.weilLabo.unk_020 = 0;
  gOverworld.work.weilLabo.unk_024.x = 0x1dd000;
  gOverworld.work.weilLabo.unk_024.y = 0x55000;
  gOverworld.work.weilLabo.unk_02c.x = 0x1dd000;
  gOverworld.work.weilLabo.unk_02c.y = 0x55000;
  gOverworld.work.weilLabo.unk_008 = 0;
}

static void FUN_08015010(struct Coord* _ UNUSED) {
  if ((gOverworld.unk_1c8.tilesets[0] >> 8 == STAGE_WEILS_LABO) && ((gOverworld.unk_1c8.tilesets[0] & 0xFF) == 0) && (gOverworld.unk_1c8.work[0] == 0)) {
    if ((gOverworld.work.weilLabo.unk_000 & (1 << 0)) == 0) {
      gOverworld.work.weilLabo.unk_000 |= (1 << 0);
      LoadBlink(259, 0);
      LoadBlink(260, 0);
      LoadBlink(261, 0);
      LoadBlink(262, 0);
    }
    GetBlinkMotionState(259);
    GetBlinkMotionState(260);
    GetBlinkMotionState(261);
    GetBlinkMotionState(262);
  } else if (gOverworld.work.weilLabo.unk_000 & (1 << 0)) {
    gOverworld.work.weilLabo.unk_000 ^= (1 << 0);
    ClearBlink(259);
    ClearBlink(260);
    ClearBlink(261);
    ClearBlink(262);
  }

  if ((gOverworld.unk_1c8.tilesets[1] >> 8 == STAGE_WEILS_LABO) && ((gOverworld.unk_1c8.tilesets[1] & 0xFF) == 1)) {
    if ((gOverworld.work.weilLabo.unk_000 & (1 << 1)) == 0) {
      gOverworld.work.weilLabo.unk_000 |= (1 << 1);
      LoadBlink(263, 0);
      LoadBlink(264, 0);
      LoadBlink(265, 0);
      LoadBlink(266, 0);
    }
    GetBlinkMotionState(263);
    GetBlinkMotionState(264);
    GetBlinkMotionState(265);
    GetBlinkMotionState(266);
  } else if (gOverworld.work.weilLabo.unk_000 & (1 << 1)) {
    gOverworld.work.weilLabo.unk_000 ^= (1 << 1);
    ClearBlink(263);
    ClearBlink(264);
    ClearBlink(265);
    ClearBlink(266);
  }

  if ((gOverworld.unk_1c8.tilesets[1] >> 8 == STAGE_WEILS_LABO) && ((gOverworld.unk_1c8.tilesets[1] & 0xFF) == 3) && (gOverworld.unk_1c8.work[0] == 0)) {
    if ((gOverworld.work.weilLabo.unk_000 & (1 << 2)) == 0) {
      gOverworld.work.weilLabo.unk_000 |= (1 << 2);
      LoadBlink(267, 0);
      LoadBlink(268, 0);
    }
    GetBlinkMotionState(267);
    GetBlinkMotionState(268);
  } else if (gOverworld.work.weilLabo.unk_000 & (1 << 2)) {
    gOverworld.work.weilLabo.unk_000 ^= (1 << 2);
    ClearBlink(267);
    ClearBlink(268);
  }

  gOverworld.work.weilLabo.unk_008++;
}

static void nop_08015244(struct Coord* _ UNUSED) { return; }

static void exitWeilLabo(struct Coord* _ UNUSED) {
  ClearBlink(0x103);
  ClearBlink(0x104);
  ClearBlink(0x105);
  ClearBlink(0x106);
  ClearBlink(0x107);
  ClearBlink(0x108);
  ClearBlink(0x109);
  ClearBlink(0x10a);
  ClearBlink(0x10b);
  ClearBlink(0x10c);
  ClearBlink(0x10d);
  ClearBlink(0x10e);
}

INCASM("asm/stage_gfx/weil_labo.inc");
