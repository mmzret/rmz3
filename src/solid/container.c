#include "collision.h"
#include "global.h"
#include "mapitem.h"
#include "overworld.h"
#include "solid.h"
#include "vfx.h"

static const struct Collision sCollision;
static const struct SlashedEnemy sSlashedEnemies[4];
static const struct Rect sSize;

static void Container_Init(struct Solid* p);
static void Solid35_Update(struct Solid* p);
static void Solid35_Die(struct Solid* p);

// clang-format off
const SolidRoutine gContainerRoutine = {
    [ENTITY_INIT] =      Container_Init,
    [ENTITY_MAIN] =      Solid35_Update,
    [ENTITY_DIE] =       Solid35_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

WIP static void Container_Init(struct Solid* p) {
#if MODERN
  const s32 n = SM226_CRASH_CONTAINER + (p->s).work[0];
  LOAD_STATIC_GRAPHIC(n);

  InitNonAffineMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetMotion(&p->s, MOTION(SM226_CRASH_CONTAINER, 0x00));
  (p->s).flags &= ~X_FLIP;
  (p->s).spr.xflip = FALSE;
  (p->s).spr.oam.xflip = FALSE;
  INIT_BODY(p, &sCollision, 6, NULL);
  (p->s).flags2 |= ENTITY_HAZARD;
  (p->s).size = &sSize;
  (p->s).hazardAttr = METATILE_GROUND;
  (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);

  if (FUN_080098a4((p->s).coord.x - PIXEL(12), (p->s).coord.y) != 0) {
    (p->s).coord.x += (PushoutToRight1((p->s).coord.x - PIXEL(12), (p->s).coord.y) - PIXEL(1));
  }
  if (FUN_080098a4((p->s).coord.x + PIXEL(12), (p->s).coord.y) != 0) {
    (p->s).coord.x += PushoutToLeft1((p->s).coord.x + PIXEL(12), (p->s).coord.y) + PIXEL(1);
  }
  SET_SOLID_ROUTINE(p, ENTITY_MAIN);
  Solid35_Update(p);
#else
  INCCODE("asm/wip/Container_Init.inc");
#endif
}

static void Solid35_Update(struct Solid* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_SOLID_ROUTINE(p, ENTITY_DIE);
    Solid35_Die(p);
    return;
  }
  UpdateMotionGraphic(&p->s);
}

static void FUN_080dc434(struct Solid* p);
static void FUN_080dc524(struct Solid* p);

static void Solid35_Die(struct Solid* p) {
  static const SolidFunc PTR_ARRAY_08371550[2] = {
      FUN_080dc434,
      FUN_080dc524,
  };

  if ((p->s).mode[2] == 0) {
    if ((p->body).status & BODY_STATUS_SLASHED) {
      (p->s).mode[1] = 1;
    } else {
      (p->s).mode[1] = 0;
    }
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    (p->s).flags2 &= ~ENTITY_HAZARD;
  }
  (PTR_ARRAY_08371550[(p->s).mode[1]])(p);
}

static void FUN_080dc434(struct Solid* p) {
  u8 diskNo;
  struct Coord c;

  c.x = (p->s).coord.x - PIXEL(4);
  c.y = (p->s).coord.y - PIXEL(15);
  CreateSlashedEnemy(&c, &sSlashedEnemies[0], 0, 0);
  c.x = (p->s).coord.x + PIXEL(8);
  c.y = (p->s).coord.y - PIXEL(15);
  CreateSlashedEnemy(&c, &sSlashedEnemies[1], 0, 0);
  c.x = (p->s).coord.x - PIXEL(4);
  c.y = (p->s).coord.y + PIXEL(1);
  CreateSlashedEnemy(&c, &sSlashedEnemies[2], 0, 0);
  c.x = (p->s).coord.x;
  c.y = (p->s).coord.y - PIXEL(12);
  CreateSmoke(1, &c);
  if ((p->s).coord.y > SEA) {
    PlaySound(SE_UNK_31);
  } else {
    PlaySound(SE_ZAKO_EXPLODE);
  }

  diskNo = (p->s).work[1];
  if (diskNo < 180) {
    CreateMapDisk(diskNo, &(p->s).coord, 1);
  } else if (diskNo == 254) {
    TryDropItem(4, &(p->s).coord);
  }
  (p->s).flags &= ~DISPLAY;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

static void FUN_080dc524(struct Solid* p) {
  u8 diskNo;
  struct Coord c;

  if ((p->s).mode[2] == 0) {
    SetMotion(&p->s, MOTION(SM226_CRASH_CONTAINER, 2));
    (p->s).work[2] = 32;
    CreateSlashedEnemy(&(p->s).coord, &sSlashedEnemies[3], 0, 0);
    (p->s).mode[2]++;
  }

  UpdateMotionGraphic(&p->s);
  (p->s).work[2]--;
  if ((p->s).work[2] == 0xFF) {
    c.x = (p->s).coord.x + PIXEL(11);
    c.y = (p->s).coord.y - PIXEL(9);
    CreateSlashedEnemy(&c, &sSlashedEnemies[0], 0, 0);
    c.x = (p->s).coord.x + PIXEL(23);
    c.y = (p->s).coord.y - PIXEL(9);
    CreateSlashedEnemy(&c, &sSlashedEnemies[1], 0, 0);
    c.x = (p->s).coord.x - PIXEL(4);
    c.y = (p->s).coord.y + PIXEL(1);
    CreateSlashedEnemy(&c, &sSlashedEnemies[2], 0, 0);
    c.x = (p->s).coord.x + PIXEL(10);
    c.y = (p->s).coord.y - PIXEL(8);
    CreateSmoke(1, &c);
    if ((p->s).coord.y > SEA) {
      PlaySound(SE_UNK_31);
    } else {
      PlaySound(SE_ZAKO_EXPLODE);
    }

    diskNo = (p->s).work[1];
    if (diskNo < 180) {
      CreateMapDisk(diskNo, &(p->s).coord, 1);
    } else if (diskNo == 254) {
      TryDropItem(4, &(p->s).coord);
    }
    (p->s).flags &= ~DISPLAY;
    SET_SOLID_ROUTINE(p, ENTITY_EXIT);
  }
}

static const struct Collision sCollision = {
  kind : DRP,
  faction : FACTION_ENEMY,
  special : 0,
  damage : 0,
  unk_04 : 0xFF,
  element : 0xFF,
  nature : 0xFF,
  comboLv : 0xFF,
  hitzone : 0x01,
  hardness : 0x08,
  unk_0a : 0x00,
  remaining : 0,
  unk_0c : 0x00000000,
  range : {PIXEL(0), -PIXEL(10), PIXEL(24), PIXEL(24)},
};

static const struct SlashedEnemy sSlashedEnemies[4] = {
    {
      m : MOTION(SM226_CRASH_CONTAINER, 3),
      unk_02 : {0xFF, 0x51},
      c : {0, 0},
      d : {0x180, 0xFB00},
      unk_0c : {0xFF, 0x1FF},
      unk_10 : {0x00, 0x40},
      unk_14 : {0x400, 0x400},
    },
    {
      m : MOTION(SM226_CRASH_CONTAINER, 4),
      unk_02 : {0xFF, 0x51},
      c : {0, 0},
      d : {0xFE80, 0xFB00},
      unk_0c : {0xFF, 0x1FF},
      unk_10 : {0x00, 0x40},
      unk_14 : {0x400, 0x400},
    },
    {
      m : MOTION(SM226_CRASH_CONTAINER, 5),
      unk_02 : {0xFF, 0x51},
      c : {0, 0},
      d : {0x80, 0xFA00},
      unk_0c : {0xFF, 0x1FF},
      unk_10 : {0x00, 0x40},
      unk_14 : {0x400, 0x400},
    },
    {
      m : MOTION(SM226_CRASH_CONTAINER, 1),
      unk_02 : {0x20, 0x60},
      c : {0, 0},
      d : {0x100, 0x80},
      unk_0c : {0, 0},
      unk_10 : {-8, -4},
      unk_14 : {0, 0},
    },
};

static const struct Rect sSize = {PIXEL(0), -PIXEL(10), PIXEL(24), PIXEL(24)};
