#include "blink.h"
#include "global.h"
#include "overworld.h"
#include "story.h"

void FUN_08014b04();

static void initGiantElevator(struct Coord* _ UNUSED);
static void gelevator_08013e88(struct Coord* _ UNUSED);
static void gelevator_08014038(struct Coord* _ UNUSED);
static void nop_080140a4(struct Coord* _ UNUSED);

static const StageFunc sStageRoutine[4] = {
    initGiantElevator,
    gelevator_08013e88,
    gelevator_08014038,
    nop_080140a4,
};

static void initGiantElevator(struct Coord* _ UNUSED) {
  gOverworld.unk_1c8.work[0] = 0;
  gOverworld.unk_1c8.work[1] = 0;
  gOverworld.work.giantElevator.unk_000[0] = 0;
  gOverworld.work.giantElevator.unk_004 = 0;
  gOverworld.work.giantElevator.unk_006 = 0;
  if (FLAG(gCurStory.s.gameflags, FLAG_49)) {
    FUN_08014b04();
  }
}

static void gelevator_08013e88(struct Coord* _ UNUSED) {
  if ((TILESET_ID(0) == STAGE_GIANT_ELEVATOR) && (TILESET_IDX(0) == 0)) {
    if ((gOverworld.work.giantElevator.unk_000[0] & (1 << 0)) == 0) {
      gOverworld.work.giantElevator.unk_000[0] |= (1 << 0);
      LoadBlink(216, 0);
    }
    GetBlinkMotionState(216);

  } else if ((gOverworld.work.giantElevator.unk_000[0] & (1 << 0))) {
    gOverworld.work.giantElevator.unk_000[0] ^= (1 << 0);
    ClearBlink(216);
  }

  if ((TILESET_ID(1) == STAGE_GIANT_ELEVATOR) && (TILESET_IDX(1) == 1)) {
    if ((gOverworld.work.giantElevator.unk_000[0] & (1 << 1)) == 0) {
      gOverworld.work.giantElevator.unk_000[0] |= (1 << 1);
      LoadBlink(215, 0);
    }
    GetBlinkMotionState(215);

  } else if ((gOverworld.work.giantElevator.unk_000[0] & (1 << 1))) {
    gOverworld.work.giantElevator.unk_000[0] ^= (1 << 1);
    ClearBlink(215);
  }

  if ((TILESET_ID(1) == STAGE_GIANT_ELEVATOR) && (TILESET_IDX(1) == 2)) {
    if ((gOverworld.work.giantElevator.unk_000[0] & (1 << 2)) == 0) {
      gOverworld.work.giantElevator.unk_000[0] |= (1 << 2);
      LoadBlink(217, 0);
      gOverworld.work.giantElevator.unk_006 = 0;
    }
    GetBlinkMotionState(217);
    if (gOverworld.unk_1c8.work[0] >= 11) {
      if (gOverworld.work.giantElevator.unk_004 != 0) {
        gOverworld.work.giantElevator.unk_004 -= 2;
      }
    } else if (gOverworld.unk_1c8.work[0] > 1) {
      if (gOverworld.work.giantElevator.unk_004 < 256) {
        gOverworld.work.giantElevator.unk_004 += 2;
      } else if (gOverworld.unk_1c8.work[0] == 2) {
        gOverworld.unk_1c8.work[0]++;
      }
    }
    gOverworld.work.giantElevator.unk_006 += gOverworld.work.giantElevator.unk_004;
    if (gOverworld.work.giantElevator.unk_006 >= 2560) {
      gOverworld.work.giantElevator.unk_006 = 0;
    }

  } else if ((gOverworld.work.giantElevator.unk_000[0] & (1 << 2))) {
    gOverworld.work.giantElevator.unk_000[0] ^= (1 << 2);
    ClearBlink(217);
  }
}

static void gelevator_08014038(struct Coord* _ UNUSED) {
  if ((TILESET_ID(1) == STAGE_GIANT_ELEVATOR) && (TILESET_IDX(1) == 2)) {
    RequestGraphicTransfer(&(TILESETS(18, 153)[gOverworld.work.giantElevator.unk_006 >> 9]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 153)[gOverworld.work.giantElevator.unk_006 >> 9]).pal, 0);
  }
}

static void nop_080140a4(struct Coord* _ UNUSED) {
  // nop
  return;
}

// ------------------------------------------------------------------------------------------------------------------------------------

INCASM("asm/stage_gfx/giant_elevator.inc");

// ./tools/dumper/bin.ts ./baserom.gba 0x08344730 0x083472e8 ./data/stage_data_2.bin
INCBIN("data/stage_data_2.bin");
