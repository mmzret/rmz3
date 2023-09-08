#include "global.h"
#include "stage.h"

static u32 getStage0Area(struct Coord* _) { return 0; }

static u32 getSpaceCraftArea(struct Coord* c) {
  s32 x = c->x;
  if ((x < 0x4B000) || ((x - 0xC3001U) < 0xEFFF)) {
    return 7;
  }
  if ((c->y < 0x14000) && (x > 0xE1000)) {
    return 7;
  }
  return 0;
}

NAKED static u32 getVolcanoArea(struct Coord* c) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r3, r0, #0\n\
	ldr r2, [r3]\n\
	ldr r0, _0801916C @ =0x002C1000\n\
	cmp r2, r0\n\
	bgt _08019168\n\
	ldr r1, _08019170 @ =0xFFE2EFFF\n\
	adds r0, r2, r1\n\
	ldr r4, _08019174 @ =0x0000EFFE\n\
	cmp r0, r4\n\
	bls _08019168\n\
	ldr r1, [r3, #4]\n\
	movs r0, #0xd8\n\
	lsls r0, r0, #0xa\n\
	cmp r1, r0\n\
	ble _0801917C\n\
	ldr r1, _08019178 @ =0xFFDE3FFF\n\
	adds r0, r2, r1\n\
	cmp r0, r4\n\
	bhi _0801917C\n\
_08019168:\n\
	movs r0, #7\n\
	b _080191BE\n\
	.align 2, 0\n\
_0801916C: .4byte 0x002C1000\n\
_08019170: .4byte 0xFFE2EFFF\n\
_08019174: .4byte 0x0000EFFE\n\
_08019178: .4byte 0xFFDE3FFF\n\
_0801917C:\n\
	ldr r1, [r3]\n\
	ldr r0, _08019188 @ =0x000B3FFF\n\
	cmp r1, r0\n\
	bgt _0801918C\n\
	movs r0, #0\n\
	b _080191BE\n\
	.align 2, 0\n\
_08019188: .4byte 0x000B3FFF\n\
_0801918C:\n\
	ldr r0, _08019198 @ =0x0011F7FF\n\
	cmp r1, r0\n\
	bgt _0801919C\n\
	movs r0, #1\n\
	b _080191BE\n\
	.align 2, 0\n\
_08019198: .4byte 0x0011F7FF\n\
_0801919C:\n\
	ldr r0, _080191A8 @ =0x00176FFF\n\
	cmp r1, r0\n\
	bgt _080191AC\n\
	movs r0, #2\n\
	b _080191BE\n\
	.align 2, 0\n\
_080191A8: .4byte 0x00176FFF\n\
_080191AC:\n\
	ldr r0, _080191B8 @ =0x001D0FFF\n\
	cmp r1, r0\n\
	ble _080191BC\n\
	movs r0, #4\n\
	b _080191BE\n\
	.align 2, 0\n\
_080191B8: .4byte 0x001D0FFF\n\
_080191BC:\n\
	movs r0, #3\n\
_080191BE:\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

static u32 getOceanArea(struct Coord* c) {
  s32 x = c->x;
  if (x > 0x2B9000) return 7;
  if (x > 0x1B3000) return 2;
  if (x > 0x19C7FF) return 6;
  if (x > 0x4B000) return 1;
  return 0;
}

static u32 getRepairFactoryArea(struct Coord* c) {
  s32 x = c->x;
  if (x < 0x1AB001) {
    if (x < 0xF0000) {
      return 0;
    }
    if (0xFEFFF < x) {
      return 1;
    }
  }
  return 7;
}

static u32 getOldLifeSpaceArea(struct Coord* c) {
  if (c->x > 0x1c9000) return 7;
  if (c->y <= 0x13FFF && ((c->x - 0xC3001U) <= 0xEFFE)) return 7;
  if ((c->x - 0x11D001U) <= 0xEFFE) return 7;

  if (c->x >= 0x11D000) {
    if (c->y < 0x32000) return 1;
    return 2;
  }
  return 0;
}

static u32 getMissileFactoryArea(struct Coord* c) {
  if (c->x > 0x195000) return 7;
  if (c->x > 0x87000) return 1;
  return 0;
}

static u32 getTwilightDesertArea(struct Coord* c) {
  s32 x = c->x;
  if (x < 0x21C001) {
    if (x > 0x11D000) {
      return 1;
    }
    if (x < 0x10E001) {
      return 0;
    }
  }
  return 7;
}

static u32 getForestArea(struct Coord* c) {
  if (c->x > 0x1BA7FF) return 7;
  if (c->x > 0x9D7FF) return 1;
  return 0;
}

static u32 getIceBaseArea(struct Coord* c) {
  if ((c->x >= 0x205800) && (c->y <= 0x1DFFF)) {
    return 7;
  }
  if (c->x >= 0x16F800) {
    return 2;
  }

  if ((c->x >= 0x124800) && (c->y >= 0x32001)) {
    return 1;
  }
  if (c->x >= 0xD9800 && (c->y <= 0x32000)) {
    return 1;
  }
  return 0;
}

static u32 getAreaX2Area(struct Coord* c) {
  if ((c->x > 0xF7000) && (c->y <= 0x1DFFF)) return 7;
  if (c->y <= 0x87000) return 1;
  return 0;
}

NAKED static u32 getEnergyFactoryArea(struct Coord* c) {
  asm(".syntax unified\n\
	push {lr}\n\
	ldr r1, [r0]\n\
	ldr r0, _080193D4 @ =0x002B9000\n\
	cmp r1, r0\n\
	ble _080193D8\n\
	movs r0, #7\n\
	b _08019426\n\
	.align 2, 0\n\
_080193D4: .4byte 0x002B9000\n\
_080193D8:\n\
	ldr r0, _080193F0 @ =0x00223800\n\
	cmp r1, r0\n\
	bgt _080193EA\n\
	ldr r0, _080193F4 @ =0x00205800\n\
	cmp r1, r0\n\
	bgt _08019424\n\
	ldr r0, _080193F8 @ =0x0016F800\n\
	cmp r1, r0\n\
	ble _080193FC\n\
_080193EA:\n\
	movs r0, #1\n\
	b _08019426\n\
	.align 2, 0\n\
_080193F0: .4byte 0x00223800\n\
_080193F4: .4byte 0x00205800\n\
_080193F8: .4byte 0x0016F800\n\
_080193FC:\n\
	ldr r0, _08019408 @ =0x00151800\n\
	cmp r1, r0\n\
	ble _0801940C\n\
	movs r0, #6\n\
	b _08019426\n\
	.align 2, 0\n\
_08019408: .4byte 0x00151800\n\
_0801940C:\n\
	ldr r0, _0801941C @ =0x000F7800\n\
	cmp r1, r0\n\
	bgt _08019418\n\
	ldr r0, _08019420 @ =0x000D9800\n\
	cmp r1, r0\n\
	bgt _08019424\n\
_08019418:\n\
	movs r0, #0\n\
	b _08019426\n\
	.align 2, 0\n\
_0801941C: .4byte 0x000F7800\n\
_08019420: .4byte 0x000D9800\n\
_08019424:\n\
	movs r0, #5\n\
_08019426:\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
 .syntax divided\n");
}

static u32 getSnowyPlainsArea(struct Coord* c) {
  const s32 x = c->x;
  if (x > 0x348000) return 7;
  if (x > 0x20d000) return 1;
  if (x > 0x1fe000) return 7;
  if (x > 0x25800) return 0;
  return 7;
}

static u32 getSubmergedLibArea(struct Coord* c) {
  if (c->y > 0x3BFFF) {
    if (c->x > 0xc3000) return 1;
    return 7;
  }

  if (c->x > 0x160800) return 1;
  if (c->x > 0x142800) return 6;
  return 0;
}

static u32 getGiantElevatorArea(struct Coord* c) {
  if (c->x > 0x12C000) return 7;
  if (c->x > 0xFF000) return 1;
  if (c->x > 0xD2000) return 6;
  return 0;
}

static u32 getSubArcadiaArea(struct Coord* c) {
  if ((c->y < 0x1e000) && (c->x > 0x69000)) {
    return 6;
  }
  if (c->x > 0xD9800) return 7;
  if (c->x > 0x52800) return 1;
  return 0;
}

static u32 getWeilLaboArea(struct Coord* c) {
  if ((c->y >= 0x32000) || (c->x > 0x1ba800)) return 7;
  if (c->x > 0x170000) return 2;

  if (c->x < 0x159001) {
    if (c->x > 0xCA7FF) return 1;
    if (c->x < 0xA5001) return 0;
  }
  return 6;
}

static u32 getBaseArea(struct Coord* c) {
  s32 x = c->x;
  if (x < 0x1E000) {
    if (c->y < 0x1E000) return 0;
    return 5;
  }

  if (x > 0xA5000) {
    if (c->y < 0x14000) {
      if (x > 0xC3000) return 0;
      return 3;
    }
    if (c->y < 0x28000) {
      return 4;
    }
    if (c->y < 0x3C000) {
      return 5;
    }
  } else {
    if (c->y < 0x5A000) {
      if (x < 0x63000) return 1;
      return 2;
    }
  }

  return 5;
}

// --------------------------------------------

// clang-format off
const AreaChecker gAreaCheckers[STAGE_COUNT] = {
  [STAGE_NONE]            = getStage0Area,
  [STAGE_SPACE_CRAFT]     = getSpaceCraftArea,
  [STAGE_VOLCANO]         = getVolcanoArea,
  [STAGE_OCEAN]           = getOceanArea,
  [STAGE_REPAIR_FACTORY]  = getRepairFactoryArea,
  [STAGE_OLD_RESIDENTIAL] = getOldLifeSpaceArea,
  [STAGE_MISSILE_FACTORY] = getMissileFactoryArea,
  [STAGE_TWILIGHT_DESERT] = getTwilightDesertArea,
  [STAGE_ANATRE_FOREST]   = getForestArea,
  [STAGE_ICE_BASE]        = getIceBaseArea,
  [STAGE_AREA_X2]         = getAreaX2Area,
  [STAGE_E_FACILITY]      = getEnergyFactoryArea,
  [STAGE_SNOWY_PLAINS]    = getSnowyPlainsArea,
  [STAGE_SUNKEN_LIBRARY]  = getSubmergedLibArea,
  [STAGE_GIANT_ELEVATOR]  = getGiantElevatorArea,
  [STAGE_SUB_ARCADIA]     = getSubArcadiaArea,
  [STAGE_WEILS_LABO]      = getWeilLaboArea,
  [STAGE_BASE]            = getBaseArea,
};
// clang-format on
