#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"

enum ElevatorSkin {
  ELEVATOR_DEFAULT,
  ELEVATOR_WOOD,
  ELEVATOR_MMX,
};

#define level work[1]

static const struct Collision sCollisions[2];
static const struct Rect Rect_08370728;

static void BaseElevator_Init(struct Solid* p);
void BaseElevator_Update(struct Solid* p);
static void BaseElevator_Die(struct Solid* p);
static void BaseElevator_Disappear(struct Solid* p);

// clang-format off
const SolidRoutine gBaseElevatorRoutine = {
    [ENTITY_INIT] =      BaseElevator_Init,
    [ENTITY_MAIN] =      BaseElevator_Update,
    [ENTITY_DIE] =       BaseElevator_Die,
    [ENTITY_DISAPPEAR] = BaseElevator_Disappear,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

struct Solid* CreateResistanceBaseElevator(u8 lv) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_BASE_ELEVATOR);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= ENTITY_FLAGS2_B4;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = 0;
    (p->s).level = lv;
    p->props.rbe.skin = gSystemSavedataManager.elevator;
  }
  return p;
}

void CreateResistanceBaseElevator2(struct Solid* e, u8 r1, u8 lv) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_BASE_ELEVATOR);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= ENTITY_FLAGS2_B4;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).unk_28 = &e->s;
    (p->s).work[0] = r1;
    (p->s).level = lv;
  }
}

// --------------------------------------------

static void rBase_080cfd4c(struct Solid* p);
void FUN_080cff48(struct Solid* p);
void FUN_080d0008(struct Solid* p);
void FUN_080d0024(struct Solid* p);

static void BaseElevator_Init(struct Solid* p) {
  if ((p->s).work[0] != 0) {
    FUN_080cff48(p);
    return;
  }
  rBase_080cfd4c(p);
}

void BaseElevator_Update(struct Solid* p) {
  if ((p->s).work[0] != 0) {
    FUN_080d0024(p);
  } else {
    FUN_080d0008(p);
  }
}

static void BaseElevator_Die(struct Solid* p) {
  if ((p->s).work[0] == 0) {
    if (p->props.rbe.se != MUS_NONE) {
      stopSound(p->props.rbe.se);
      p->props.rbe.se = MUS_NONE;
    }
  }
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

static void BaseElevator_Disappear(struct Solid* p) {
  if ((p->s).work[0] == 0) {
    if (p->props.rbe.se != MUS_NONE) {
      stopSound(p->props.rbe.se);
      p->props.rbe.se = MUS_NONE;
    }
  }
  DeleteSolid(p);
}

WIP static void rBase_080cfd4c(struct Solid* p) {
#if MODERN
  if (p->props.rbe.skin == ELEVATOR_DEFAULT) {
    LOAD_STATIC_GRAPHIC(115);
  }
  if (p->props.rbe.skin == ELEVATOR_WOOD) {
    LOAD_STATIC_GRAPHIC(137);
  }
  if (p->props.rbe.skin == ELEVATOR_MMX) {
    LOAD_STATIC_GRAPHIC(138);
  }

  InitNonAffineMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  (p->s).flags &= ~X_FLIP;
  (p->s).spr.xflip = FALSE;
  (p->s).spr.oam.xflip = FALSE;
  (p->s).flags2 |= ENTITY_HAZARD;
  (p->s).size = &Rect_08370728;
  (p->s).hazardAttr = 0x2001;
  INIT_BODY(p, sCollisions, 0, NULL);
  p->props.rbe.c.x = 0x65000;
  p->props.rbe.c.y = 0x26000;
  (p->s).coord.x = p->props.rbe.c.x;
  (p->s).coord.y = p->props.rbe.c.y + (p->s).level * PIXEL(160);

  p->props.rbe.se = MUS_NONE;
  CreateResistanceBaseElevator2(p, 1, 0);
  gOverworld.unk_1c8.disableArea[0] = 0;
  gOverworld.unk_1c8.disableArea[1] = 0;
  gOverworld.unk_1c8.disableArea[2] = 0x3c0000;
  gOverworld.unk_1c8.disableArea[3] = 0x280000;
  p->props.rbe.unk_c0 = 0;
  p->props.rbe.unk_c1 = 5;
  SET_SOLID_ROUTINE(p, ENTITY_MAIN);
  BaseElevator_Update(p);
#else
  INCCODE("asm/wip/rBase_080cfd4c.inc");
#endif
}

INCASM("asm/solid/base_elevator.inc");

// ------------------------------------------------------------------------------------------------------------------------------------

static const struct Collision sCollisions[2] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 255,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0800, 0x1000, 0x1200},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 255,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x0000, 0x0000},
    },
};

// --------------------------------------------

// clang-format off
const motion_t sBaseElevatorMotions[6] = {
    MOTION(0x73, 0x06),
    MOTION(0x73, 0x05),
    MOTION(0x73, 0x04),
    MOTION(0x73, 0x03),
    MOTION(0x73, 0x02),
    MOTION(0x73, 0x01),
};
// clang-format on

// --------------------------------------------

static const struct Rect Rect_08370728 = {0x0, 0x800, 0x4000, 0x1000};
const struct Rect Rect_08370730 = {0x0, 0xB800, 0x4000, 0x1000};

#undef level
