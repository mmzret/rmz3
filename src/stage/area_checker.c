#include "global.h"
#include "spawn.h"

static u32 getStage0Area(Coords32* _) { return 0; }

// 0x080190fc
static u32 getSpaceCraftArea(Coords32* c) {
  if (c->x < PIXEL(1200)) return 7;
  if ((c->x > PIXEL(3120)) && (c->x < PIXEL(3360))) return 7;
  if ((c->y < PIXEL(320)) && (c->x > PIXEL(3600))) return 7;
  return 0;
}

static u32 getVolcanoArea(struct Coord* c) {
  if (c->x > 0x2C1000) {
    return 7;
  }
  if ((u32)(c->x - 0x1D1001) <= 0xEFFE) {
    return 7;
  }
  if (c->y > 0x36000 && (u32)(c->x - 0x21C001) <= 0xEFFE) {
    return 7;
  }
  if (c->x <= 0xB3FFF) {
    return 0;
  }
  if (c->x <= 0x11F7FF) {
    return 1;
  }
  if (c->x <= 0x176FFF) {
    return 2;
  }
  if (c->x <= 0x1D0FFF) {
    return 3;
  }
  return 4;
}

static u32 getOceanArea(Coords32* c) {
  s32 x = c->x;
  if (x > 0x2B9000) return 7;
  if (x > 0x1B3000) return 2;
  if (x > 0x19C7FF) return 6;
  if (x > 0x4B000) return 1;
  return 0;
}

static u32 getRepairFactoryArea(Coords32* c) {
  s32 x = c->x;
  if (x < 0x1AB001) {
    if (x < 0xF0000) return 0;
    if (0xFEFFF < x) return 1;
  }
  return 7;
}

static u32 getOldLifeSpaceArea(Coords32* c) {
  if (c->x > 0x1c9000) return 7;
  if (c->y <= 0x13FFF && ((c->x - 0xC3001U) <= 0xEFFE)) return 7;
  if ((c->x - 0x11D001U) <= 0xEFFE) return 7;

  if (c->x >= 0x11D000) {
    if (c->y < 0x32000) return 1;
    return 2;
  }
  return 0;
}

static u32 getMissileFactoryArea(Coords32* c) {
  if (c->x > 0x195000) return 7;
  if (c->x > 0x87000) return 1;
  return 0;
}

static u32 getTwilightDesertArea(Coords32* c) {
  s32 x = c->x;
  if (x < 0x21C001) {
    if (x > 0x11D000) return 1;
    if (x < 0x10E001) return 0;
  }
  return 7;
}

static u32 getForestArea(Coords32* c) {
  if (c->x > 0x1BA7FF) return 7;
  if (c->x > 0x9D7FF) return 1;
  return 0;
}

static u32 getIceBaseArea(Coords32* c) {
  if ((c->x >= 0x205800) && (c->y <= 0x1DFFF)) return 7;
  if (c->x >= 0x16F800) return 2;
  if ((c->x >= 0x124800) && (c->y >= 0x32001)) return 1;
  if (c->x >= 0xD9800 && (c->y <= 0x32000)) return 1;
  return 0;
}

static u32 getAreaX2Area(Coords32* c) {
  if ((c->x > 0xF7000) && (c->y <= 0x1DFFF)) return 7;
  if (c->y <= 0x87000) return 1;
  return 0;
}

static u32 getEnergyFactoryArea(struct Coord* c) {
  s32 x = c->x;
  if (x > 0x2B9000) {
    return 7;
  }
  if (x > 0x223800) {
    return 1;
  }
  if (x > 0x205800) {
    return 5;
  }
  if (x > 0x16F800) {
    return 1;
  }
  if (x > 0x151800) {
    return 6;
  }
  if (x > 0xF7800) {
    return 0;
  }
  if (x > 0xD9800) {
    return 5;
  }
  return 0;
}

static u32 getSnowyPlainsArea(Coords32* c) {
  const s32 x = c->x;
  if (x > 0x348000) return 7;
  if (x > 0x20d000) return 1;
  if (x > 0x1fe000) return 7;
  if (x > 0x25800) return 0;
  return 7;
}

static u32 getSubmergedLibArea(Coords32* c) {
  if (c->y > 0x3BFFF) {
    if (c->x > 0xc3000) return 1;
    return 7;
  }

  if (c->x > 0x160800) return 1;
  if (c->x > 0x142800) return 6;
  return 0;
}

static u32 getGiantElevatorArea(Coords32* c) {
  if (c->x > 0x12C000) return 7;
  if (c->x > 0xFF000) return 1;
  if (c->x > 0xD2000) return 6;
  return 0;
}

static u32 getSubArcadiaArea(Coords32* c) {
  if ((c->y < 0x1e000) && (c->x > 0x69000)) {
    return 6;
  }
  if (c->x > 0xD9800) return 7;
  if (c->x > 0x52800) return 1;
  return 0;
}

static u32 getWeilLaboArea(Coords32* c) {
  if ((c->y >= 0x32000) || (c->x > 0x1ba800)) return 7;
  if (c->x > 0x170000) return 2;

  if (c->x < 0x159001) {
    if (c->x > 0xCA7FF) return 1;
    if (c->x < 0xA5001) return 0;
  }
  return 6;
}

// 0x08019578
static u32 getBaseArea(Coords32* c) {
  s32 x = c->x;
  if (x < PIXEL(480)) {
    if (c->y < PIXEL(480)) return 0;
    return 5;
  }
  if (x > PIXEL(2640)) {
    if (c->y < PIXEL(320)) {
      if (x > PIXEL(3120)) return 0;
      return 3;
    }
    if (c->y < PIXEL(640)) return 4;
    if (c->y < PIXEL(960)) return 5;
  } else {
    if (c->y < PIXEL(1440)) {
      if (x < PIXEL(1584)) return 1;
      return 2;
    }
  }
  return 5;
}

// --------------------------------------------

// clang-format off
const AreaChecker gAreaCheckers[STAGE_COUNT] = {
  [STAGE_NONE]            = (AreaChecker)getStage0Area,
  [STAGE_SPACE_CRAFT]     = (AreaChecker)getSpaceCraftArea,
  [STAGE_VOLCANO]         = (AreaChecker)getVolcanoArea,
  [STAGE_OCEAN]           = (AreaChecker)getOceanArea,
  [STAGE_REPAIR_FACTORY]  = (AreaChecker)getRepairFactoryArea,
  [STAGE_OLD_RESIDENTIAL] = (AreaChecker)getOldLifeSpaceArea,
  [STAGE_MISSILE_FACTORY] = (AreaChecker)getMissileFactoryArea,
  [STAGE_TWILIGHT_DESERT] = (AreaChecker)getTwilightDesertArea,
  [STAGE_ANATRE_FOREST]   = (AreaChecker)getForestArea,
  [STAGE_ICE_BASE]        = (AreaChecker)getIceBaseArea,
  [STAGE_AREA_X2]         = (AreaChecker)getAreaX2Area,
  [STAGE_E_FACILITY]      = (AreaChecker)getEnergyFactoryArea,
  [STAGE_SNOWY_PLAINS]    = (AreaChecker)getSnowyPlainsArea,
  [STAGE_SUNKEN_LIBRARY]  = (AreaChecker)getSubmergedLibArea,
  [STAGE_GIANT_ELEVATOR]  = (AreaChecker)getGiantElevatorArea,
  [STAGE_SUB_ARCADIA]     = (AreaChecker)getSubArcadiaArea,
  [STAGE_WEILS_LABO]      = (AreaChecker)getWeilLaboArea,
  [STAGE_BASE]            = (AreaChecker)getBaseArea,
};
// clang-format on
