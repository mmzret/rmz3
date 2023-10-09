#include "collision.h"
#include "entity.h"
#include "vfx.h"
#include "global.h"
#include "solid.h"

static const struct Collision sCollisions[2];

static void Solid37_Init(struct Solid* p);
static void Solid37_Update(struct Solid* p);
static void Solid37_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid37Routine = {
    [ENTITY_INIT] =      Solid37_Init,
    [ENTITY_UPDATE] =    Solid37_Update,
    [ENTITY_DIE] =       Solid37_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

void CreateSolid37(struct Solid* p) {
  struct Solid* s = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (s != NULL) {
    (s->s).taskCol = 30;
    INIT_SOLID_ROUTINE(s, SOLID_UNK_037);
    (s->s).tileNum = 0;
    (s->s).palID = 0;
    (s->s).flags2 |= WHITE_PAINTABLE;
    (s->s).invincibleID = (s->s).uniqueID;
    (s->s).unk_28 = &p->s;
    (s->s).coord = (p->s).coord;
    (s->s).work[0] = 1;
    (s->s).work[1] = 0;
  }
}

void FUN_080dc81c(struct Solid* p);
void FUN_080dc900(struct Solid* p);

static void Solid37_Init(struct Solid* p) {
  if ((p->s).work[0] == 0) {
    FUN_080dc81c(p);
  } else {
    FUN_080dc900(p);
  }
}

void FUN_080dc898(struct Solid* p);
void FUN_080dca60(struct Solid* p);

static void Solid37_Update(struct Solid* p) {
  if ((p->s).work[0] == 0) {
    FUN_080dc898(p);
  } else {
    FUN_080dca60(p);
  }
}

void FUN_080dc8e8(struct Solid* p);
void FUN_080dcb80(struct Solid* p);

static void Solid37_Die(struct Solid* p) {
  if ((p->s).work[0] == 0) {
    FUN_080dc8e8(p);
  } else {
    FUN_080dcb80(p);
  }
}

INCASM("asm/solid/unk_37.inc");

static const struct Collision sCollisions[2] = {
    {
      kind : DRP,
      faction : FACTION_UNK2,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x02,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x0E00, 0x0E00},
    },
    {
      kind : DRP,
      faction : FACTION_UNK2,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x02,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x0E00, 0x0E00},
    },
};
