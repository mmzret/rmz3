#include "blink.h"
#include "gfx.h"
#include "global.h"
#include "overworld.h"

static void initRepairFactory(struct Coord* _ UNUSED);
static void repairFactory_0800d6b4(struct Coord* c);
static void repairFactory_0800d8c0(struct Coord* _ UNUSED);
static void exitRepairFactory(struct Coord* _ UNUSED);

static const StageFunc sStageRoutine[4] = {
    initRepairFactory,
    repairFactory_0800d6b4,
    repairFactory_0800d8c0,
    exitRepairFactory,
};

static void initRepairFactory(struct Coord* _ UNUSED) {
  gOverworld.unk_1c8.work[0] = 0;
  gOverworld.work.repairFactory.unk_000 = 0;
  gOverworld.work.repairFactory.unk_001 = 0;
  gOverworld.work.repairFactory.unk_002 = 0;
  LoadBlink(0x2B, 0);
  LoadBlink(0x2C, 0);
}

static void repairFactory_0800d6b4(struct Coord* c) {
  if ((gOverworld.unk_1c8.tilesets[1] >> 8 == STAGE_REPAIR_FACTORY) && ((gOverworld.unk_1c8.tilesets[1] & 0xff) == 1)) {
    if ((gOverworld.work.repairFactory.unk_000 & (1 << 0)) == 0) {
      gOverworld.work.repairFactory.unk_000 |= (1 << 0);
      LoadBlink(45, 0);
    }
    UpdateBlinkMotionState(45);

  } else if (gOverworld.work.repairFactory.unk_000 & (1 << 0)) {
    gOverworld.work.repairFactory.unk_000 ^= (1 << 0);
    ClearBlink(45);
  }

  if ((gOverworld.unk_1c8.tilesets[1] >> 8 == STAGE_REPAIR_FACTORY) && ((gOverworld.unk_1c8.tilesets[1] & 0xff) == 4)) {
    if ((gOverworld.work.repairFactory.unk_000 & (1 << 1)) == 0) {
      gOverworld.work.repairFactory.unk_000 |= (1 << 1);
      LoadBlink(46, 0);
      LoadBlink(47, 0);
      LoadBlink(48, 0);
    }
    UpdateBlinkMotionState(46);
    UpdateBlinkMotionState(47);
    UpdateBlinkMotionState(48);

  } else if (gOverworld.work.repairFactory.unk_000 & (1 << 1)) {
    gOverworld.work.repairFactory.unk_000 ^= (1 << 1);
    ClearBlink(46);
    ClearBlink(47);
    ClearBlink(48);
  }

  UpdateBlinkMotionState(43);
  UpdateBlinkMotionState(44);

  if (gOverworld.unk_1c8.work[0] == 0) {
    gOverworld.unk_1c8.unk_2c004.x = -0x155;
    gOverworld.unk_1c8.unk_2c004.y = 0x155;
    gOverworld.work.repairFactory.unk_001++;
    if (gOverworld.work.repairFactory.unk_001 == 6) {
      gOverworld.work.repairFactory.unk_001 = gOverworld.unk_1c8.work[0];
    }
  } else {
    gOverworld.unk_1c8.unk_2c004.x = 0x155;
    gOverworld.unk_1c8.unk_2c004.y = -0x155;
    gOverworld.work.repairFactory.unk_001--;
    if (gOverworld.work.repairFactory.unk_001 < 0) {
      gOverworld.work.repairFactory.unk_001 = 5;
    }
  }

  gOverworld.work.repairFactory.unk_002++;
  if (gOverworld.work.repairFactory.unk_002 == 45) {
    gOverworld.work.repairFactory.unk_002 = 0;
  }

  if ((c->x - 0x10D001U < 0x5AFFF) || ((c->x < 0x1E000 && (c->y < 0x14000)))) {
    if (!isSoundPlaying(SE_UNK_10b)) {
      PlaySound(SE_UNK_10b);
    }
    SetStageNoiseVolume(SE_UNK_10b);
  } else {
    if (isSoundPlaying(SE_UNK_10b)) {
      stopSound(SE_UNK_10b);
    }
  }
}

NAKED static void repairFactory_0800d8c0(struct Coord* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	ldr r7, _0800D99C @ =gStageTilesetOffsets+(18*4)\n\
	ldr r5, _0800D9A0 @ =gOverworld\n\
	ldr r0, _0800D9A4 @ =0x0002D029\n\
	adds r6, r5, r0\n\
	movs r0, #0\n\
	ldrsb r0, [r6, r0]\n\
	lsls r0, r0, #1\n\
	movs r1, #3\n\
	bl __divsi3\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	ldr r4, _0800D9A8 @ =0x0870478C\n\
	adds r1, r1, r4\n\
	ldr r0, [r7]\n\
	adds r0, r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	mov r8, r1\n\
	bl RequestGraphicTransfer\n\
	movs r0, #0\n\
	ldrsb r0, [r6, r0]\n\
	lsls r0, r0, #1\n\
	movs r1, #3\n\
	bl __divsi3\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
	ldr r0, [r7]\n\
	adds r0, r0, r1\n\
	adds r0, #0xc\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r0, _0800D9AC @ =0x0002D02A\n\
	adds r6, r5, r0\n\
	ldrb r0, [r6]\n\
	movs r1, #9\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r4, #0x50\n\
	adds r1, r1, r4\n\
	ldr r0, [r7]\n\
	adds r0, r0, r1\n\
	mov r1, r8\n\
	bl RequestGraphicTransfer\n\
	ldrb r0, [r6]\n\
	movs r1, #9\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
	ldr r0, [r7]\n\
	adds r0, r0, r1\n\
	adds r0, #0xc\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r1, _0800D9B0 @ =0x000007D6\n\
	adds r5, r5, r1\n\
	ldrh r5, [r5]\n\
	lsrs r0, r5, #8\n\
	cmp r0, #4\n\
	bne _0800D990\n\
	movs r0, #0xff\n\
	ands r0, r5\n\
	cmp r0, #4\n\
	bne _0800D990\n\
	ldr r0, _0800D9B4 @ =gMission\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x14]\n\
	movs r1, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0800D990\n\
	ldr r0, [r7]\n\
	ldr r1, _0800D9B8 @ =0x08704C28\n\
	adds r0, r0, r1\n\
	mov r1, r8\n\
	bl RequestGraphicTransfer\n\
	ldr r0, [r7]\n\
	ldr r1, _0800D9BC @ =0x08704C34\n\
	adds r0, r0, r1\n\
	movs r1, #0\n\
	bl LoadPalette\n\
_0800D990:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800D99C: .4byte gStageTilesetOffsets+(18*4)\n\
_0800D9A0: .4byte gOverworld\n\
_0800D9A4: .4byte 0x0002D029\n\
_0800D9A8: .4byte 0x0870478C\n\
_0800D9AC: .4byte 0x0002D02A\n\
_0800D9B0: .4byte 0x000007D6\n\
_0800D9B4: .4byte gMission\n\
_0800D9B8: .4byte 0x08704C28\n\
_0800D9BC: .4byte 0x08704C34\n\
 .syntax divided\n");
}

static void exitRepairFactory(struct Coord* _ UNUSED) {
  ClearBlink(43);
  ClearBlink(44);
  ClearBlink(45);
  ClearBlink(46);
  ClearBlink(47);
  ClearBlink(48);
  if (isSoundPlaying(SE_UNK_10b)) {
    stopSound(SE_UNK_10b);
  }
}

void rfactory_0800da04(struct StageLayer* l, const struct Stage* stage);
void rfactory_0800da80(struct StageLayer* l, const struct Stage* stage);

// clang-format off
static const StageLayerRoutine sLayerRoutine[4] = {
    [0] = {
      [LAYER_UPDATE] = NULL,
      [LAYER_DRAW]   = NULL,
      [LAYER_EXIT]   = NULL,
    },
    [1] = {
      [LAYER_UPDATE] = NULL,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [2] = {
      [LAYER_UPDATE] = rfactory_0800da04,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [3] = {
      [LAYER_UPDATE] = rfactory_0800da80,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
};
// clang-format on

#include "../../../data/stage/repair_factory/layer.h"
//
#include "../../../data/stage/repair_factory/landscape.h"

INCASM("asm/stage_gfx/repair_factory.inc");
