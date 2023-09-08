#include "blink.h"
#include "gfx.h"
#include "global.h"
#include "overworld.h"

#define HEIGHT 14
#define WIDTH 16

static void initResistanceBase(struct Coord* _ UNUSED);
static void updateResistanceBase(struct Coord* c);
static void nop_08016378(struct Coord* _ UNUSED);
static void exitResistanceBase(struct Coord* _ UNUSED);

enum ResistanceBaseWeather {
  SUNNY,
  NIGHT,
  SNOWY,
  SUNSET,
};

void CreateSnow(struct Coord* c, u32 n);

static const StageFunc sStageRoutine[4] = {
    initResistanceBase,
    updateResistanceBase,
    nop_08016378,
    exitResistanceBase,
};

static void initResistanceBase(struct Coord* _ UNUSED) {
  gOverworld.unk_1c8.work[0] = 0;
  gOverworld.unk_1c8.work[1] = 0;

  gOverworld.work.resistanceBase.unk_000 = 0;
  gOverworld.work.resistanceBase.weather = gSystemSavedataManager.weather;
  gOverworld.work.resistanceBase.unk_002 = 0;
  if (gStageRun.id == STAGE_WEILS_LABO) {
    gOverworld.work.resistanceBase.weather = SUNSET;  // sunset
  }

  if ((gSystemSavedataManager.mods[4] & (1 << 4)) != 0) {
    LoadScreenIntoMetatileMap(5, 6, 7);
  }
  if ((gSystemSavedataManager.mods[5] & (1 << 1)) != 0) {
    LoadScreenIntoMetatileMap(6, 2, 86);
    LoadScreenIntoMetatileMap(6, 3, 87);
    LoadScreenIntoMetatileMap(7, 3, 88);
  }
};

// 0x08016154
static void updateResistanceBase(struct Coord* c) {
  if ((gOverworld.unk_1c8.tilesets[0] >> 8 == 0x11) && ((gOverworld.unk_1c8.tilesets[0] & 0xff) == 1)) {
    if ((gOverworld.work.resistanceBase.unk_000 & 1) == 0) {
      gOverworld.work.resistanceBase.unk_000 |= 1;
      LoadBlink(0x6a, 0);
    }
    GetBlinkMotionState(0x6a);

  } else if (gOverworld.work.resistanceBase.unk_000 & 1) {
    ClearBlink(0x6a);
    gOverworld.work.resistanceBase.unk_000 ^= 1;
  }

  if ((gOverworld.unk_1c8.tilesets[0] >> 8 == 0x11) && ((gOverworld.unk_1c8.tilesets[0] & 0xff) == 4)) {
    if ((gOverworld.work.resistanceBase.unk_000 & 2) == 0) {
      gOverworld.work.resistanceBase.unk_000 |= 2;
      LoadBlink(0x68, 0);
    }
    GetBlinkMotionState(0x68);

  } else if (gOverworld.work.resistanceBase.unk_000 & 2) {
    ClearBlink(0x68);
    gOverworld.work.resistanceBase.unk_000 ^= 2;
  }

  if (gOverworld.work.resistanceBase.weather == SNOWY) {
    gOverworld.work.resistanceBase.unk_002++;

    if (((c->y < PIXEL(800)) && (PIXEL(480) <= c->x)) && (c->x <= PIXEL(2160))) {
      if ((gOverworld.work.resistanceBase.unk_002 & 0xF) == 0) {
        struct Coord c;
        RNG_0202f388 = (LCG(RNG_0202f388) << 1) >> 1;
        c.x = PIXEL((RNG_0202f388 >> 16) % 960) + PIXEL(1200);
        c.y = PIXEL(160);
        CreateSnow(&c, 0x380);
      }

    } else if (c->y < PIXEL(1120)) {
      if ((gOverworld.work.resistanceBase.unk_002 & 0x3F) == 0) {
        struct Coord c;
        RNG_0202f388 = (LCG(RNG_0202f388) << 1) >> 1;
        c.x = PIXEL((RNG_0202f388 >> 16) % 240) + PIXEL(720);
        c.y = PIXEL(800);
        CreateSnow(&c, 0x140);
      }

    } else if ((gOverworld.work.resistanceBase.unk_002 & 0x1F) == 0) {
      struct Coord c;
      RNG_0202f388 = (LCG(RNG_0202f388) << 1) >> 1;
      c.x = PIXEL((RNG_0202f388 >> 16) % 480) + PIXEL(2160);
      c.y = PIXEL(1280);
      CreateSnow(&c, 0x140);
    }
  }
}

static void nop_08016378(struct Coord* _ UNUSED) { return; }

static void exitResistanceBase(struct Coord* _ UNUSED) {
  ClearBlink(0x68);
  ClearBlink(0x6a);
}

// ------------------------------------------------------------------------------------------------------------------------------------

NAKED static void rbase_08016390(struct StageLayer* l, const struct Stage* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	ldrb r0, [r5, #0xe]\n\
	cmp r0, #4\n\
	bls _0801639C\n\
	b _080164D2\n\
_0801639C:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080163A8 @ =_080163AC\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080163A8: .4byte _080163AC\n\
_080163AC: @ jump table\n\
	.4byte _080163C0 @ case 0\n\
	.4byte _08016438 @ case 1\n\
	.4byte _08016452 @ case 2\n\
	.4byte _08016480 @ case 3\n\
	.4byte _080164B8 @ case 4\n\
_080163C0:\n\
	ldr r1, [r5, #0x5c]\n\
	lsrs r1, r1, #4\n\
	lsls r1, r1, #1\n\
	ldr r0, _080164A0 @ =gVideoRegBuffer+4\n\
	adds r1, r1, r0\n\
	ldrh r2, [r1]\n\
	ldr r0, _080164A4 @ =0x0000FFFC\n\
	ands r0, r2\n\
	movs r2, #3\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	ldr r0, _080164A8 @ =gOverworld\n\
	ldr r1, _080164AC @ =0x0002D025\n\
	adds r0, r0, r1\n\
	movs r4, #0\n\
	strb r4, [r0]\n\
	ldr r1, _080164B0 @ =gBlendRegBuffer\n\
	movs r0, #0xfd\n\
	lsls r0, r0, #6\n\
	strh r0, [r1]\n\
	movs r0, #0x6b\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x6c\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x6d\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x6e\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x6f\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x70\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x74\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x75\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x76\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	strh r4, [r5, #0x10]\n\
	ldrb r0, [r5, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xe]\n\
_08016438:\n\
	ldr r0, _080164A8 @ =gOverworld\n\
	ldr r1, _080164B4 @ =0x0002D024\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080164D2\n\
	movs r0, #0x72\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	ldrb r0, [r5, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xe]\n\
_08016452:\n\
	movs r0, #0x72\n\
	bl GetBlinkMotionState\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #4\n\
	bne _080164D2\n\
	ldr r0, _080164A8 @ =gOverworld\n\
	ldr r1, _080164B4 @ =0x0002D024\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #2\n\
	bne _080164D2\n\
	movs r0, #0x72\n\
	bl ClearBlink\n\
	movs r0, #0x73\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	ldrb r0, [r5, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xe]\n\
_08016480:\n\
	movs r0, #0x73\n\
	bl GetBlinkMotionState\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #3\n\
	bne _080164D2\n\
	movs r0, #0x73\n\
	bl ClearBlink\n\
	movs r0, #0x78\n\
	strh r0, [r5, #0x12]\n\
	ldrb r0, [r5, #0xe]\n\
	adds r0, #1\n\
	b _080164D0\n\
	.align 2, 0\n\
_080164A0: .4byte gVideoRegBuffer+4\n\
_080164A4: .4byte 0x0000FFFC\n\
_080164A8: .4byte gOverworld\n\
_080164AC: .4byte 0x0002D025\n\
_080164B0: .4byte gBlendRegBuffer\n\
_080164B4: .4byte 0x0002D024\n\
_080164B8:\n\
	ldrh r0, [r5, #0x12]\n\
	subs r0, #1\n\
	strh r0, [r5, #0x12]\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080164D2\n\
	ldr r0, _08016514 @ =gOverworld\n\
	ldr r1, _08016518 @ =0x0002D024\n\
	adds r0, r0, r1\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	movs r0, #1\n\
_080164D0:\n\
	strb r0, [r5, #0xe]\n\
_080164D2:\n\
	ldrh r0, [r5, #0x10]\n\
	adds r0, #1\n\
	strh r0, [r5, #0x10]\n\
	movs r0, #0x6b\n\
	bl GetBlinkMotionState\n\
	movs r0, #0x6c\n\
	bl GetBlinkMotionState\n\
	movs r0, #0x6d\n\
	bl GetBlinkMotionState\n\
	movs r0, #0x6e\n\
	bl GetBlinkMotionState\n\
	movs r0, #0x6f\n\
	bl GetBlinkMotionState\n\
	movs r0, #0x70\n\
	bl GetBlinkMotionState\n\
	movs r0, #0x74\n\
	bl GetBlinkMotionState\n\
	movs r0, #0x75\n\
	bl GetBlinkMotionState\n\
	movs r0, #0x76\n\
	bl GetBlinkMotionState\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08016514: .4byte gOverworld\n\
_08016518: .4byte 0x0002D024\n\
 .syntax divided\n");
}

NAKED static void rbase_0801651c(struct StageLayer* l, const struct Stage* _) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6}\n\
	adds r4, r0, #0\n\
	mov sb, r1\n\
	ldr r0, _0801657C @ =gStageTilesetOffsets+(18*4)\n\
	mov r8, r0\n\
	ldrh r0, [r4, #0x10]\n\
	lsrs r0, r0, #2\n\
	movs r6, #7\n\
	ands r0, r6\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	ldr r5, _08016580 @ =0x08704980\n\
	adds r1, r1, r5\n\
	mov r2, r8\n\
	ldr r0, [r2]\n\
	adds r0, r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl RequestGraphicTransfer\n\
	ldrh r0, [r4, #0x10]\n\
	lsrs r0, r0, #2\n\
	ands r0, r6\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r5\n\
	mov r2, r8\n\
	ldr r0, [r2]\n\
	adds r0, r0, r1\n\
	adds r0, #0xc\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	adds r0, r4, #0\n\
	mov r1, sb\n\
	bl DrawGeneralStageLayer\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0801657C: .4byte gStageTilesetOffsets+(18*4)\n\
_08016580: .4byte gMiscTilesetGraphics+(58*20)-0xd1534\n\
 .syntax divided\n");
}

static void rbase_08016584(struct StageLayer* l UNUSED, const struct Stage* _ UNUSED) {
  gBlendRegBuffer.bldclt = 0;
  ClearBlink(0x6b);
  ClearBlink(0x6c);
  ClearBlink(0x6d);
  ClearBlink(0x6e);
  ClearBlink(0x6f);
  ClearBlink(0x70);
  ClearBlink(0x74);
  ClearBlink(0x75);
  ClearBlink(0x76);
  ClearBlink(0x72);
  ClearBlink(0x73);
}

void setBgPrio3(struct StageLayer* l, const struct Stage* _) {
  if (l->phase == 0) {
    // Set 3 into Layer's BgPrio
    u16* bgcnt = (u16*)&gVideoRegBuffer.bgcnt[l->bgIdx >> 4];
    *bgcnt &= 0xFFFC;
    *bgcnt |= 3;

    l->phase++;
  }
}

void rbase_0801660c(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    // Set 3 into Layer's BgPrio
    u16* bgcnt = (u16*)&gVideoRegBuffer.bgcnt[l->bgIdx >> 4];
    *bgcnt &= 0xFFFC;
    *bgcnt |= 3;

    (l->prevViewportCenterPixel).y = 0;
    (l->prevViewportCenterPixel).x = 0;
    (l->scrollPower).x = 0x80;
    (l->scrollPower).y = 0x80;
    if ((l->viewportCenterPixel).x < 1440) {
      (l->scroll).x = 0x168;
      (l->scroll).y = 400;
    } else {
      (l->scroll).x = 0x4b0;
      (l->scroll).y = 0x280;
    }
    l->phase++;
  }
}

static void rbase_0801666c(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    BGCNT16(l->bgIdx >> 4) = (BGCNT16(l->bgIdx >> 4) & 0xFFFC) | 3;
    (l->prevViewportCenterPixel).y = 0;
    (l->prevViewportCenterPixel).x = 0;
    (l->scrollPower).x = 0x20;
    (l->scrollPower).y = 0x20;
    if ((l->viewportCenterPixel).x < 1440) {
      (l->scroll).x = 0x276;
      (l->scroll).y = 0x2BC;
      gOverworld.unk_1c8.disableArea[0] = 0x34000;
      gOverworld.unk_1c8.disableArea[2] = 0x3c0000;
    } else {
      (l->scroll).x = 0x834;
      (l->scroll).y = 0x460;
      gOverworld.unk_1c8.disableArea[0] = 0x0;
      gOverworld.unk_1c8.disableArea[2] = 0x9e000;
    }

    if (gOverworld.work.resistanceBase.weather == SUNNY) {
      LoadBlink(105, 0);
    } else if (gOverworld.work.resistanceBase.weather == NIGHT) {
      (l->scroll).y -= 0x140;
      LoadBlink(120, 0);
      LoadBlink(121, 0);
      LoadBlink(122, 0);
    } else if (gOverworld.work.resistanceBase.weather == SNOWY) {
      LoadBlink(201, 0);
      LoadBlink(202, 0);
    }

    l->unk_10 = 0;
    l->phase++;
  }

  if (gOverworld.work.resistanceBase.weather == SUNNY) {
    GetBlinkMotionState(105);

  } else if (gOverworld.work.resistanceBase.weather == NIGHT) {
    GetBlinkMotionState(120);
    GetBlinkMotionState(121);
    GetBlinkMotionState(122);
    GetBlinkMotionState(123);
    l->unk_10++;
    if (l->unk_10 == 3600) {
      ClearBlink(123);
      LoadBlink(123, 0);
      l->unk_10 = 0;
    }

  } else if (gOverworld.work.resistanceBase.weather == SNOWY) {
    GetBlinkMotionState(201);
    GetBlinkMotionState(202);
  }
}

static void rbase_080167dc(struct StageLayer* l, const struct Stage* _ UNUSED) {
  gOverworld.unk_1c8.disableArea[0] = 0;
  gOverworld.unk_1c8.disableArea[1] = 0;
  gOverworld.unk_1c8.disableArea[2] = 0x3c0000;
  gOverworld.unk_1c8.disableArea[3] = 0x280000;
  ClearBlink(0x69);
  ClearBlink(0x78);
  ClearBlink(0x79);
  ClearBlink(0x7a);
  ClearBlink(0x7b);
  ClearBlink(0xc9);
  ClearBlink(0xca);
}

static void setBgPrio1(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    // Set 1 into Layer's BgPrio
    u16* bgcnt = (u16*)&gVideoRegBuffer.bgcnt[l->bgIdx >> 4];
    *bgcnt &= 0xFFFC;
    *bgcnt |= 1;

    l->phase++;
  }
}

static void rbase_08016878(struct StageLayer* l, const struct Stage* _ UNUSED) {
  bool32 b = FALSE;
  if (l->phase == 0) {
    (l->work).resistanceBase.frameCounter = 2;
    l->phase++;
  }
  if ((l->viewportCenterPixel).x - 0x571U < 0xEF) {
    b = (l->viewportCenterPixel).y < 560;
    if (b != (l->work).resistanceBase.frameCounter) {
      if (b) {
        LoadScreenIntoMetatileMap(5, 2, 21);
        LoadScreenIntoMetatileMap(5, 3, 22);
        LoadScreenIntoMetatileMap(5, 4, 82);
        LoadScreenIntoMetatileMap(8, 2, 23);
        LoadScreenIntoMetatileMap(8, 3, 24);
        LoadScreenIntoMetatileMap(8, 4, 83);
      } else {
        LoadScreenIntoMetatileMap(5, 2, 17);
        LoadScreenIntoMetatileMap(5, 3, 33);
        LoadScreenIntoMetatileMap(5, 4, 49);
        LoadScreenIntoMetatileMap(8, 2, 20);
        LoadScreenIntoMetatileMap(8, 3, 36);
        LoadScreenIntoMetatileMap(8, 4, 52);
      }
      (l->work).resistanceBase.frameCounter = b;
    }
  }
}

NAKED static void rbase_08016940(struct StageLayer* l, const struct Stage* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	adds r7, r0, #0\n\
	ldrb r0, [r7, #0xe]\n\
	cmp r0, #0\n\
	beq _08016952\n\
	b _08016A5C\n\
_08016952:\n\
	ldr r0, [r7, #0x5c]\n\
	lsls r2, r0, #0x10\n\
	lsrs r0, r2, #0x10\n\
	mov sb, r0\n\
	ldr r0, _080169CC @ =gOverworld\n\
	ldr r1, _080169D0 @ =0x0002D029\n\
	adds r1, r1, r0\n\
	mov r8, r1\n\
	ldrb r0, [r1]\n\
	cmp r0, #1\n\
	beq _08016A0C\n\
	lsrs r5, r2, #0x14\n\
	lsls r5, r5, #1\n\
	ldr r0, _080169D4 @ =gVideoRegBuffer+4\n\
	adds r5, r5, r0\n\
	ldr r1, [r7, #0x60]\n\
	ldr r0, [r7, #0x64]\n\
	orrs r1, r0\n\
	ldr r2, _080169D8 @ =0x00004044\n\
	adds r0, r2, #0\n\
	orrs r1, r0\n\
	strh r1, [r5]\n\
	ldr r0, _080169DC @ =0x08522388\n\
	ldr r0, [r0]\n\
	ldr r2, _080169E0 @ =0x08522390\n\
	adds r0, r0, r2\n\
	movs r4, #0xf8\n\
	lsls r4, r4, #5\n\
	ands r1, r4\n\
	lsls r1, r1, #3\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #0x13\n\
	adds r1, r1, r2\n\
	movs r6, #0x80\n\
	lsls r6, r6, #2\n\
	adds r2, r6, #0\n\
	bl CpuFastSet\n\
	ldr r0, _080169E4 @ =0x0852238C\n\
	ldr r0, [r0]\n\
	ldr r1, _080169E8 @ =0x08522394\n\
	adds r0, r0, r1\n\
	ldrh r1, [r5]\n\
	ands r4, r1\n\
	lsls r4, r4, #3\n\
	ldr r2, _080169EC @ =0x06000800\n\
	adds r4, r4, r2\n\
	adds r1, r4, #0\n\
	adds r2, r6, #0\n\
	bl CpuFastSet\n\
	mov r1, r8\n\
	ldrb r0, [r1]\n\
	cmp r0, #2\n\
	bne _080169F0\n\
	movs r0, #0xc7\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0xc8\n\
	b _08016A00\n\
	.align 2, 0\n\
_080169CC: .4byte gOverworld\n\
_080169D0: .4byte 0x0002D029\n\
_080169D4: .4byte gVideoRegBuffer+4\n\
_080169D8: .4byte 0x00004044\n\
_080169DC: .4byte gBgMapOffsets+232\n\
_080169E0: .4byte gBgMapOffsets+240\n\
_080169E4: .4byte gBgMapOffsets+236\n\
_080169E8: .4byte gBgMapOffsets+244\n\
_080169EC: .4byte 0x06000800\n\
_080169F0:\n\
	cmp r0, #3\n\
	bne _08016A46\n\
	movs r0, #0x89\n\
	lsls r0, r0, #1\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	ldr r0, _08016A08 @ =0x00000113\n\
_08016A00:\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	b _08016A46\n\
	.align 2, 0\n\
_08016A08: .4byte 0x00000113\n\
_08016A0C:\n\
	lsrs r2, r2, #0x14\n\
	lsls r2, r2, #1\n\
	ldr r0, _08016A78 @ =gVideoRegBuffer+4\n\
	adds r2, r2, r0\n\
	ldr r1, [r7, #0x60]\n\
	ldr r0, [r7, #0x64]\n\
	orrs r1, r0\n\
	movs r0, #0x44\n\
	orrs r1, r0\n\
	strh r1, [r2]\n\
	ldr r0, _08016A7C @ =0x08522390\n\
	ldr r0, [r0]\n\
	ldr r2, _08016A80 @ =0x08522398\n\
	adds r0, r0, r2\n\
	movs r2, #0xf8\n\
	lsls r2, r2, #5\n\
	ands r1, r2\n\
	lsls r1, r1, #3\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #0x13\n\
	adds r1, r1, r2\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	bl CpuFastSet\n\
	movs r0, #0x77\n\
	movs r1, #0\n\
	bl LoadBlink\n\
_08016A46:\n\
	mov r1, sb\n\
	lsrs r0, r1, #4\n\
	lsls r0, r0, #2\n\
	ldr r1, _08016A84 @ =gVideoRegBuffer+12\n\
	adds r0, r0, r1\n\
	movs r1, #0\n\
	str r1, [r0]\n\
	str r1, [r7, #0x68]\n\
	ldrb r0, [r7, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r7, #0xe]\n\
_08016A5C:\n\
	ldr r0, _08016A88 @ =gOverworld\n\
	ldr r2, _08016A8C @ =0x0002D029\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #2\n\
	bne _08016A90\n\
	movs r0, #0xc7\n\
	bl GetBlinkMotionState\n\
	movs r0, #0xc8\n\
	bl GetBlinkMotionState\n\
	b _08016AA2\n\
	.align 2, 0\n\
_08016A78: .4byte gVideoRegBuffer+4\n\
_08016A7C: .4byte gBgMapOffsets+240\n\
_08016A80: .4byte gBgMapOffsets+248\n\
_08016A84: .4byte gVideoRegBuffer+12\n\
_08016A88: .4byte gOverworld\n\
_08016A8C: .4byte 0x0002D029\n\
_08016A90:\n\
	cmp r0, #3\n\
	bne _08016AA2\n\
	movs r0, #0x89\n\
	lsls r0, r0, #1\n\
	bl GetBlinkMotionState\n\
	ldr r0, _08016AB4 @ =0x00000113\n\
	bl GetBlinkMotionState\n\
_08016AA2:\n\
	ldr r0, [r7, #0x68]\n\
	adds r0, #1\n\
	str r0, [r7, #0x68]\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08016AB4: .4byte 0x00000113\n\
 .syntax divided\n");
}

NAKED static void rbase_08016ab8(struct StageLayer* l, const struct Stage* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	adds r6, r0, #0\n\
	ldrh r0, [r6, #0x34]\n\
	mov sl, r0\n\
	ldr r0, [r6, #0x38]\n\
	subs r0, #0xa0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	mov r8, r0\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #2\n\
	bl Malloc\n\
	mov sb, r0\n\
	cmp r0, #0\n\
	bne _08016AE4\n\
	b _08016CE6\n\
_08016AE4:\n\
	ldr r2, _08016C44 @ =gIntrManager\n\
	movs r1, #0xba\n\
	lsls r1, r1, #1\n\
	adds r0, r2, r1\n\
	mov r3, sb\n\
	str r3, [r0]\n\
	movs r5, #0xbc\n\
	lsls r5, r5, #1\n\
	adds r1, r2, r5\n\
	ldr r0, _08016C48 @ =0x0400001C\n\
	str r0, [r1]\n\
	movs r7, #0xbe\n\
	lsls r7, r7, #1\n\
	adds r1, r2, r7\n\
	ldr r0, _08016C4C @ =0xA6600001\n\
	str r0, [r1]\n\
	ldr r0, _08016C50 @ =gOverworld\n\
	ldr r1, _08016C54 @ =0x0002D029\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	bne _08016B12\n\
	b _08016C64\n\
_08016B12:\n\
	movs r4, #0x2c\n\
	mov r0, sl\n\
	muls r0, r4, r0\n\
	movs r1, #0x64\n\
	bl __divsi3\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	mov r0, r8\n\
	muls r0, r4, r0\n\
	movs r1, #0x64\n\
	bl __divsi3\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	movs r2, #0\n\
	movs r0, #0x48\n\
	subs r0, r0, r1\n\
	cmp r2, r0\n\
	bge _08016B60\n\
	lsls r2, r1, #0x10\n\
	str r2, [sp]\n\
	ldr r3, _08016C58 @ =0x0000FFFF\n\
	mov ip, r3\n\
	adds r4, r0, #0\n\
	mov r3, sb\n\
	adds r2, r4, #0\n\
_08016B48:\n\
	ldr r0, [r6, #0x68]\n\
	lsrs r0, r0, #1\n\
	adds r0, r5, r0\n\
	mov r7, ip\n\
	ands r0, r7\n\
	ldr r7, [sp]\n\
	orrs r0, r7\n\
	stm r3!, {r0}\n\
	subs r2, #1\n\
	cmp r2, #0\n\
	bne _08016B48\n\
	adds r2, r4, #0\n\
_08016B60:\n\
	movs r0, #0x68\n\
	subs r0, r0, r1\n\
	cmp r2, r0\n\
	bge _08016B92\n\
	lsls r3, r1, #0x10\n\
	str r3, [sp]\n\
	ldr r7, _08016C58 @ =0x0000FFFF\n\
	mov ip, r7\n\
	adds r4, r0, #0\n\
	lsls r0, r2, #2\n\
	mov r7, sb\n\
	adds r3, r0, r7\n\
	subs r2, r4, r2\n\
_08016B7A:\n\
	ldr r0, [r6, #0x68]\n\
	lsrs r0, r0, #2\n\
	adds r0, r5, r0\n\
	mov r7, ip\n\
	ands r0, r7\n\
	ldr r7, [sp]\n\
	orrs r0, r7\n\
	stm r3!, {r0}\n\
	subs r2, #1\n\
	cmp r2, #0\n\
	bne _08016B7A\n\
	adds r2, r4, #0\n\
_08016B92:\n\
	movs r0, #0x80\n\
	subs r0, r0, r1\n\
	cmp r2, r0\n\
	bge _08016BC4\n\
	lsls r3, r1, #0x10\n\
	str r3, [sp]\n\
	ldr r7, _08016C58 @ =0x0000FFFF\n\
	mov ip, r7\n\
	adds r4, r0, #0\n\
	lsls r0, r2, #2\n\
	mov r7, sb\n\
	adds r3, r0, r7\n\
	subs r2, r4, r2\n\
_08016BAC:\n\
	ldr r0, [r6, #0x68]\n\
	lsrs r0, r0, #3\n\
	adds r0, r5, r0\n\
	mov r7, ip\n\
	ands r0, r7\n\
	ldr r7, [sp]\n\
	orrs r0, r7\n\
	stm r3!, {r0}\n\
	subs r2, #1\n\
	cmp r2, #0\n\
	bne _08016BAC\n\
	adds r2, r4, #0\n\
_08016BC4:\n\
	movs r0, #0xa0\n\
	subs r0, r0, r1\n\
	cmp r2, r0\n\
	bge _08016BF2\n\
	lsls r4, r1, #0x10\n\
	ldr r1, _08016C58 @ =0x0000FFFF\n\
	mov ip, r1\n\
	adds r3, r0, #0\n\
	lsls r0, r2, #2\n\
	mov r7, sb\n\
	adds r1, r0, r7\n\
	subs r2, r3, r2\n\
_08016BDC:\n\
	ldr r0, [r6, #0x68]\n\
	lsrs r0, r0, #4\n\
	adds r0, r5, r0\n\
	mov r7, ip\n\
	ands r0, r7\n\
	orrs r0, r4\n\
	stm r1!, {r0}\n\
	subs r2, #1\n\
	cmp r2, #0\n\
	bne _08016BDC\n\
	adds r2, r3, #0\n\
_08016BF2:\n\
	cmp r2, #0x9f\n\
	bgt _08016CE6\n\
	mov r1, r8\n\
	adds r0, r1, r2\n\
	ldr r4, _08016C5C @ =0x0000015F\n\
	cmp r0, r4\n\
	bgt _08016C22\n\
	lsls r0, r2, #0x10\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #0x10\n\
	subs r1, r1, r0\n\
	lsls r0, r2, #2\n\
	mov r5, sb\n\
	adds r3, r0, r5\n\
	ldr r5, _08016C60 @ =0xFFFF0000\n\
_08016C10:\n\
	stm r3!, {r1}\n\
	adds r1, r1, r5\n\
	adds r2, #1\n\
	cmp r2, #0x9f\n\
	bgt _08016CE6\n\
	mov r6, r8\n\
	adds r0, r6, r2\n\
	cmp r0, r4\n\
	ble _08016C10\n\
_08016C22:\n\
	cmp r2, #0x9f\n\
	bgt _08016CE6\n\
	mov r0, r8\n\
	adds r0, #0x40\n\
	lsls r1, r0, #0x10\n\
	mov r7, sl\n\
	lsls r0, r7, #1\n\
	add r0, sl\n\
	lsrs r0, r0, #2\n\
	orrs r1, r0\n\
	lsls r0, r2, #2\n\
	add r0, sb\n\
_08016C3A:\n\
	stm r0!, {r1}\n\
	adds r2, #1\n\
	cmp r2, #0x9f\n\
	ble _08016C3A\n\
	b _08016CE6\n\
	.align 2, 0\n\
_08016C44: .4byte gIntrManager\n\
_08016C48: .4byte 0x0400001C\n\
_08016C4C: .4byte 0xA6600001\n\
_08016C50: .4byte gOverworld\n\
_08016C54: .4byte 0x0002D029\n\
_08016C58: .4byte 0x0000FFFF\n\
_08016C5C: .4byte 0x0000015F\n\
_08016C60: .4byte 0xFFFF0000\n\
_08016C64:\n\
	mov r1, r8\n\
	lsls r0, r1, #5\n\
	add r0, r8\n\
	movs r1, #0x64\n\
	bl __divsi3\n\
	adds r0, #0x28\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	movs r2, #0\n\
	movs r0, #0xa0\n\
	subs r0, r0, r1\n\
	cmp r2, r0\n\
	bge _08016C90\n\
	lsls r3, r1, #0x10\n\
	mov r1, sb\n\
	adds r2, r0, #0\n\
_08016C86:\n\
	stm r1!, {r3}\n\
	subs r2, #1\n\
	cmp r2, #0\n\
	bne _08016C86\n\
	adds r2, r0, #0\n\
_08016C90:\n\
	cmp r2, #0x9f\n\
	bgt _08016CE0\n\
	mov r3, r8\n\
	adds r0, r3, r2\n\
	ldr r4, _08016CF8 @ =0x00000167\n\
	cmp r0, r4\n\
	bgt _08016CC0\n\
	lsls r0, r2, #0x10\n\
	movs r1, #0xa8\n\
	lsls r1, r1, #0x10\n\
	subs r1, r1, r0\n\
	lsls r0, r2, #2\n\
	mov r5, sb\n\
	adds r3, r0, r5\n\
	ldr r5, _08016CFC @ =0xFFFF0000\n\
_08016CAE:\n\
	stm r3!, {r1}\n\
	adds r1, r1, r5\n\
	adds r2, #1\n\
	cmp r2, #0x9f\n\
	bgt _08016CE0\n\
	mov r6, r8\n\
	adds r0, r6, r2\n\
	cmp r0, r4\n\
	ble _08016CAE\n\
_08016CC0:\n\
	cmp r2, #0x9f\n\
	bgt _08016CE0\n\
	mov r0, r8\n\
	adds r0, #0x40\n\
	lsls r1, r0, #0x10\n\
	mov r7, sl\n\
	lsls r0, r7, #1\n\
	add r0, sl\n\
	lsrs r0, r0, #2\n\
	orrs r1, r0\n\
	lsls r0, r2, #2\n\
	add r0, sb\n\
_08016CD8:\n\
	stm r0!, {r1}\n\
	adds r2, #1\n\
	cmp r2, #0x9f\n\
	ble _08016CD8\n\
_08016CE0:\n\
	movs r0, #0x77\n\
	bl GetBlinkMotionState\n\
_08016CE6:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08016CF8: .4byte 0x00000167\n\
_08016CFC: .4byte 0xFFFF0000\n\
 .syntax divided\n");
}

static void rbase_08016d00(struct StageLayer* l, const struct Stage* _ UNUSED) {
  ClearBlink(119);
  ClearBlink(199);
  ClearBlink(200);
  ClearBlink(274);
  ClearBlink(275);
}

static void rbase_08016d2c(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    u16* bgcnt = (u16*)&gVideoRegBuffer.bgcnt[l->bgIdx >> 4];
    *bgcnt &= 0xFFFC;
    *bgcnt |= 1;

    gBlendRegBuffer.bldclt = 0x3748;
    gBlendRegBuffer.bldalpha = 0x808;
    l->phase++;
  }
}

static void rbase_08016d74(struct StageLayer* l UNUSED, const struct Stage* _ UNUSED) {
  gBlendRegBuffer.bldclt = 0;
  return;
}

static void setBgPrio2(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    u16* bgcnt = (u16*)&gVideoRegBuffer.bgcnt[l->bgIdx >> 4];
    *bgcnt &= 0xFFFC;
    *bgcnt |= 2;
    l->phase++;
  }
}

// clang-format off
static const StageLayerRoutine sLayerRoutine[11] = {
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
      [LAYER_UPDATE] = rbase_08016390,
      [LAYER_DRAW]   = rbase_0801651c,
      [LAYER_EXIT]   = rbase_08016584,
    },
    [3] = {
      [LAYER_UPDATE] = setBgPrio3,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [4] = {
      [LAYER_UPDATE] = rbase_0801660c,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [5] = {
      [LAYER_UPDATE] = rbase_0801666c,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = rbase_080167dc,
    },
    [6] = {
      [LAYER_UPDATE] = setBgPrio1,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [7] = {
      [LAYER_UPDATE] = rbase_08016878,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [8] = {
      [LAYER_UPDATE] = rbase_08016940,
      [LAYER_DRAW]   = rbase_08016ab8,
      [LAYER_EXIT]   = rbase_08016d00,
    },
    [9] = {
      [LAYER_UPDATE] = rbase_08016d2c,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = rbase_08016d74,
    },
    [10] = {
      [LAYER_UPDATE] = setBgPrio2,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
};
// clang-format on

static const struct ScreenLayout sScreenMap1 = {
  realWidth : WIDTH,
  skip : 1,
  width : 16,
  height : HEIGHT,
};

// clang-format off
static const u8 sScreenMapData1[HEIGHT][WIDTH] = {
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x06, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x0C, 0x01, 0x03, 0x01 },
  { 0x01, 0x03, 0x01, 0x01, 0x01, 0x11, 0x00, 0x00, 0x14, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x21, 0x22, 0x23, 0x24, 0x01, 0x01, 0x01, 0x09, 0x01, 0x09, 0x01 },
  { 0x01, 0x4C, 0x01, 0x01, 0x01, 0x31, 0x32, 0x33, 0x34, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x30, 0x40, 0x41, 0x42, 0x43, 0x44, 0x01, 0x01, 0x01, 0x1A, 0x1B, 0x1C, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x25, 0x26, 0x27, 0x28, 0x29, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x35, 0x36, 0x37, 0x38, 0x39, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x4A, 0x01, 0x01, 0x45, 0x46, 0x47, 0x48, 0x49, 0x20, 0x10, 0x01, 0x01, 0x50, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x2C, 0x2D, 0x01, 0x3C, 0x3D, 0x01, 0x2A, 0x2B, 0x01, 0x3E, 0x3F, 0x01, 0x2E, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x2E, 0x01, 0x2E, 0x01, 0x2E, 0x01, 0x2E, 0x01, 0x2E, 0x01, 0x2E, 0x01, 0x2E, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
};
// clang-format on

static const struct ScreenLayout sScreenMap2 = {
  realWidth : WIDTH,
  skip : 1,
  width : 16,
  height : HEIGHT,
};

// clang-format off
static const u8 sScreenMapData2[HEIGHT][WIDTH] = {
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x0B, 0x01, 0x05, 0x01 },
  { 0x01, 0x05, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x12, 0x01, 0x01, 0x01, 0x01, 0x01, 0x08, 0x01, 0x08, 0x01 },
  { 0x01, 0x4D, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x0E, 0x0F, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x4B, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x1E, 0x1F, 0x01, 0x01, 0x51, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x3A, 0x3B, 0x01, 0x4E, 0x4F, 0x01, 0x2F, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x2F, 0x01, 0x2F, 0x01, 0x2F, 0x01, 0x2F, 0x01, 0x2F, 0x01, 0x2F, 0x01, 0x2F, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
};
// clang-format on

static const struct ScreenLayout sScreenMap3 = {
  realWidth : WIDTH,
  skip : 1,
  width : 16,
  height : HEIGHT,
};
// clang-format off
static const u8 sScreenMapData3[HEIGHT][WIDTH] = {
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x0D, 0x01, 0x04, 0x01 },
  { 0x01, 0x04, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x54, 0x54, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x13, 0x01, 0x0A, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x19, 0x19, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x55, 0x55, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x1D, 0x1D, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
};
// clang-format on

// clang-format off
static const tileset_ofs_t sTilesetOffset[4+(HEIGHT * WIDTH)] = {
  4, 15, WIDTH, HEIGHT,

  0x02, 0x02, 0x02, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x42, 0x42, 0x02, 0x02, 0x02,
  0x02, 0x02, 0x02, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x42, 0x42, 0x02, 0x02, 0x02,
  0x02, 0x02, 0x02, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x42, 0x42, 0x42, 0x42, 0x42,
  0x02, 0x02, 0x02, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x42, 0x42, 0x42, 0x42, 0x42,
  0x53, 0x53, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13,
  0x53, 0x53, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13,
  0x53, 0x53, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13,
  0x53, 0x53, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x53, 0x53, 0x13, 0x13,
  0x53, 0x53, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x53, 0x53, 0x13, 0x13,
  0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53,
  0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53,
  0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53,
  0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53,
  0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53,
};
// clang-format on

// clang-format off
static const u16 u16_ARRAY_0834770c[4+(HEIGHT * WIDTH)] = {
  4, 15, WIDTH, HEIGHT,

  0xF123, 0xF100, 0xF100, 0xF100, 0xF108, 0xF108, 0xF108, 0xF108, 0xF108, 0xF100, 0xF100, 0xF119, 0xF119, 0xF123, 0xF123, 0xF100,
  0xF123, 0xE123, 0xF100, 0xF100, 0xF108, 0x2108, 0x2108, 0x2108, 0x2108, 0xF100, 0xF100, 0xF119, 0x0119, 0xF123, 0x0123, 0xF100,
  0xF123, 0x0123, 0xF100, 0xF100, 0xF108, 0x2168, 0x2168, 0x2108, 0x2108, 0xF100, 0xF100, 0xF111, 0xF111, 0xF111, 0xF111, 0xF100,
  0xF110, 0xF110, 0xF100, 0xF100, 0xF108, 0x2768, 0x2768, 0x2708, 0x2708, 0xF100, 0xF100, 0xF111, 0x0111, 0xF111, 0x0111, 0xF100,
  0xF110, 0x0110, 0xFA45, 0xFA45, 0xFA45, 0x2700, 0x1700, 0x2700, 0x2700, 0xF100, 0xF100, 0xF100, 0xF100, 0xF100, 0xF100, 0xF100,
  0xF110, 0xF100, 0xFA45, 0x0A45, 0x0A45, 0x0100, 0x1100, 0x0100, 0x0100, 0xF100, 0xF100, 0xF100, 0x0100, 0x0100, 0x0100, 0xF100,
  0xF110, 0xF100, 0xF100, 0xF100, 0x2100, 0x2100, 0x1100, 0x2100, 0x2100, 0xF100, 0xF100, 0xF100, 0xF100, 0xF100, 0xF100, 0xF100,
  0xF110, 0xF110, 0xF100, 0xF100, 0x0100, 0x0100, 0x1100, 0x0100, 0x0145, 0xF145, 0xF145, 0xF100, 0xF110, 0xF110, 0xF100, 0xF100,
  0xF110, 0x0110, 0xF100, 0xF100, 0x2100, 0x2100, 0x1100, 0x2100, 0x2145, 0x2145, 0x2145, 0xF100, 0xF110, 0x0110, 0xF100, 0xF100,
  0xF100, 0xF100, 0xF100, 0xF100, 0xF100, 0xF100, 0xF110, 0xF110, 0xF110, 0xF110, 0xF110, 0xF110, 0xF110, 0xF110, 0xF100, 0xF100,
  0xF100, 0x0100, 0x0100, 0xF100, 0x0100, 0x0100, 0xF110, 0x0110, 0x0110, 0xF110, 0x0110, 0x0110, 0xF110, 0x0110, 0xF100, 0xF100,
  0xF110, 0xF110, 0xF110, 0xF110, 0xF110, 0xF110, 0xF110, 0xF110, 0xF110, 0xF110, 0xF110, 0xF110, 0xF110, 0xF110, 0xF100, 0xF100,
  0xF110, 0x0110, 0xF110, 0x0110, 0xF110, 0x0110, 0xF110, 0x0110, 0xF110, 0x0110, 0xF110, 0x0110, 0xF110, 0x0110, 0xF100, 0xF100,
  0xF100, 0xF100, 0xF100, 0xF100, 0xF100, 0xF100, 0xF100, 0xF100, 0xF100, 0xF100, 0xF100, 0xF100, 0xF100, 0xF100, 0xF100, 0xF100,
};
// clang-format on

const struct Stage gResistanceBaseLandscape = {
  id : STAGE_BASE,
  fn : sStageRoutine,
  terrainHdr : &gStageTerrains[STAGE_BASE],
  maps : {&sScreenMap1, &sScreenMap2, &sScreenMap3},
  bgIdx : {USE_BG1, USE_BG2, USE_BG3},
  prio : {3, 2, 3},
  screenBase : {BGMAP_BLOCK(2), BGMAP_BLOCK(4), BGMAP_BLOCK(6)},
  scrollPower : {{0x100, 0x100}, {0x100, 0x100}, {0x100, 0x100}},
  scroll : {{0, 0}, {0, 0}, {0, 0}},
  tilesetOffset : sTilesetOffset,
  bgFns : sLayerRoutine,
  behavior : u16_ARRAY_0834770c,
  unk_78 : {0, 0},
};

#undef HEIGHT
#undef WIDTH
