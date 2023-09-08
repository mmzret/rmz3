#include "global.h"
#include "overworld.h"
#include "story.h"

void FUN_08014b04();

static void initGiantElevator(struct Coord* _ UNUSED) {
  gOverworld.unk_1c8.work[0] = 0;
  gOverworld.unk_1c8.work[1] = 0;
  gOverworld.work.giantElevator.unk_000[0] = 0;
  gOverworld.work.giantElevator.unk_004 = 0;
  gOverworld.work.giantElevator.unk_006 = 0;
  if (gCurStory.s.unk_0a & (1 << 1)) {
    FUN_08014b04();
  }
}

INCASM("asm/stage_gfx/giant_elevator.inc");

// ./tools/dumper/bin.ts ./baserom.gba 0x08344720 0x083472e8 ./data/stage_data_2.bin
INCBIN("data/stage_data_2.bin");
