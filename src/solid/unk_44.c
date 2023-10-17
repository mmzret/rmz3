#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"
#include "zero.h"

static const struct Collision sCollisions[2];

static void Solid44_Init(struct Solid* p);
static void Solid44_Update(struct Solid* p);
void Solid44_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid44Routine = {
    [ENTITY_INIT] =      Solid44_Init,
    [ENTITY_UPDATE] =    Solid44_Update,
    [ENTITY_DIE] =       Solid44_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static void Solid44_Init(struct Solid* p) {
  metatile_attr_t attr;

  if ((p->s).work[0] == 0) {
    attr = GetMetatileAttr((p->s).coord.x, (p->s).coord.y);
    if (attr == 0) {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
      SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    } else {
      INIT_BODY(p, &sCollisions[0], 0, NULL);
      (p->s).coord.x += PIXEL(8);
      (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
      SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
      Solid44_Update(p);
    }
  } else {
    (p->s).flags |= FLIPABLE;
    SET_SOLID_ROUTINE(p, ENTITY_DIE);
    Solid44_Die(p);
  }
}

static void Solid44_Update(struct Solid* p) {
  // clang-format off
  if (
    (((p->body).status & BODY_STATUS_B2) && (BODY(pZero2) != BODY_CHIP_LIGHT)) || 
    (GetMetatileAttr((p->s).coord.x + PIXEL(17), (p->s).coord.y + 1) == 0) || 
    (GetMetatileAttr((p->s).coord.x - PIXEL(17), (p->s).coord.y + 1) == 0)
  ) {
    // clang-format on
    struct Solid* p2 = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
    if (p2 != NULL) {
      (p2->s).taskCol = 30;
      INIT_SOLID_ROUTINE(p2, SOLID_UNK_044);
      (p2->s).tileNum = 0;
      (p2->s).palID = 0;
      (p2->s).flags2 |= WHITE_PAINTABLE;
      (p2->s).invincibleID = (p2->s).uniqueID;
      (p2->s).work[0] = 1;
      (p2->s).work[1] = 0;
      (p2->s).coord.x = (p->s).coord.x + PIXEL(8);
      (p2->s).coord.y = (p->s).coord.y;
    }
    (p->s).coord.x -= PIXEL(8);
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    (p->s).flags |= FLIPABLE;
    SET_SOLID_ROUTINE(p, ENTITY_DIE);
    Solid44_Die(p);
  }
}

INCASM("asm/solid/unk_44.inc");

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 255,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(34), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 255,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};
