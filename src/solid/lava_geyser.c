#include "collision.h"
#include "global.h"
#include "solid.h"

static const struct Collision sCollisions[2];
static const struct Rect sSize;

// ------------------------------------------------------------------------------------------------------------------------------------

void Solid7_Init(struct Solid* p);
void Solid7_Update(struct Solid* p);
void Solid7_Die(struct Solid* p);

// clang-format off
const SolidRoutine gLavaGeyserRoutine = {
    [ENTITY_INIT] =      Solid7_Init,
    [ENTITY_MAIN] =      Solid7_Update,
    [ENTITY_DIE] =       Solid7_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

WIP void CreateLavaGeyser(struct Solid* solid, s32 x, s32 y, s32 n) {
#if MODERN
  s32 i;
  for (i = 0; i < 6; i++) {
    struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
    if (p != NULL) {
      s32 val;

      (p->s).taskCol = 30;
      INIT_SOLID_ROUTINE(p, SOLID_LAVA_GEYSER);
      (p->s).tileNum = 0;
      (p->s).palID = 0;
      (p->s).flags2 |= ENTITY_FLAGS2_B4;
      (p->s).invincibleID = (p->s).uniqueID;
      (p->s).work[0] = 12;
      (p->s).work[1] = i;
      val = n - y;
      if (val < 0) {
        val = -val;
      }
      if (val < 0) {
        val += ((1 << 11) - 1);
      }
      (p->s).work[3] = val >> 11;
      (p->s).coord.x = x;
      (p->s).coord.y = y;
      y += PIXEL(16);
      (p->s).unk_28 = &solid->s;
    }
  }
#else
  INCCODE("asm/wip/CreateLavaGeyser.inc");
#endif
}

static void CreateSolid7_Unused(s32 x, u8 n) {
  struct Solid* p = (struct Solid*)AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_LAVA_GEYSER);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= ENTITY_FLAGS2_B4;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = n;
    (p->s).coord.x = x;
  }
}

bool8 FUN_080cc814(struct Solid* p) { return (p->s).mode[1] == ENTITY_EXIT; }

static void onCollision(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  struct CollidableEntity* enemy = (body->enemy)->parent;
  struct Solid* self = (struct Solid*)body->parent;

  if (body->hitboxFlags & BODY_STATUS_B3) {
    *(s32*)(&(self->props).raw[8]) = (enemy->s).coord.y;
  }
}

INCASM("asm/solid/unk_07.inc");

// --------------------------------------------

void nop_080cc930(struct Solid* p);
void FUN_080cc934(struct Solid* p);

// clang-format off
const SolidFunc sSolid7Updates1[6] = {
    FUN_080cc934,
    FUN_080cc934,
    FUN_080cc934,
    FUN_080cc934,
    nop_080cc930,
    nop_080cc930,
};
// clang-format on

// --------------------------------------------

void FUN_080cc968(struct Solid* p);
void FUN_080cca14(struct Solid* p);
void FUN_080ccae0(struct Solid* p);
void FUN_080ccb50(struct Solid* p);
void FUN_080ccc1c(struct Solid* p);
void FUN_080ccca4(struct Solid* p);

// clang-format off
const SolidFunc sSolid7Updates2[6] = {
    FUN_080cc968,
    FUN_080cca14,
    FUN_080ccae0,
    FUN_080ccb50,
    FUN_080ccc1c,
    FUN_080ccca4,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 254,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(0), PIXEL(57), PIXEL(32), PIXEL(111)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(57), PIXEL(32), PIXEL(111)},
    },
};

// --------------------------------------------

static const struct Rect sSize = {PIXEL(0), PIXEL(57), PIXEL(32), PIXEL(120)};
