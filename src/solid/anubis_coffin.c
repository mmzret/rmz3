#include "collision.h"
#include "global.h"
#include "solid.h"

// ------------------------------------------------------------------------------------------------------------------------------------

void AnubisCoffin_Init(struct Solid* p);
void AnubisCoffin_Update(struct Solid* p);
void AnubisCoffin_Die(struct Solid* p);

// clang-format off
const SolidRoutine gAnubisCoffinRoutine = {
    [ENTITY_INIT] =      (void*)AnubisCoffin_Init,
    [ENTITY_UPDATE] =    (void*)AnubisCoffin_Update,
    [ENTITY_DIE] =       (void*)AnubisCoffin_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};

void FUN_080cdf34(struct Solid* p);
// clang-format on

void CreateAnubisCoffins(struct Entity* anubis, bool8 r1) {
  s32 i;
  struct Solid* another = NULL;
  for (i = 0; i < 2; i++) {
    struct Solid* p = (struct Solid*)AllocEntityLast(gSolidHeaderPtr);
    if (p != NULL) {
      INIT_SOLID_ROUTINE(p, SOLID_ANUBIS_COFFIN);
      (p->s).work[0] = 0;
      (p->s).work[2] = i;
      (p->s).work[3] = r1;
      (p->s).unk_28 = anubis;
      (p->s).unk_2c = (struct Entity*)another;
      another = p;
    }
  }
}

INCASM("asm/solid/anubis_coffin_a.inc");

void nop_080cde6c(struct Solid* p) {}

extern const u8 u8_ARRAY_08370240[4];
extern const SolidFunc sAnubisCoffinUpdates1[3];
extern const SolidFunc sAnubisCoffinUpdates2[3];
extern const struct Collision sAnubisCoffinCollisions[2];

void AnubisCoffin_Init(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = u8_ARRAY_08370240[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, sAnubisCoffinCollisions, 1, (void*)nop_080cde6c);
  *(u8*)((u8*)p + 0xbc) = 0;
  AnubisCoffin_Update(p);
}

void AnubisCoffin_Update(struct Solid* p) {
  (sAnubisCoffinUpdates1[(p->s).mode[1]])((void*)p);
  (sAnubisCoffinUpdates2[(p->s).mode[1]])((void*)p);
}


void AnubisCoffin_Die(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}


void FUN_080cdf34(struct Solid* p) {}

INCASM("asm/solid/anubis_coffin_b.inc");

// --------------------------------------------

void FUN_080cdf34(struct Solid* p);

const SolidFunc sAnubisCoffinUpdates1[3] = {
    FUN_080cdf34,
    FUN_080cdf34,
    FUN_080cdf34,
};

// --------------------------------------------

void coffin_080cdf38(struct Solid* p);
void coffin_080ce0d4(struct Solid* p);
void coffin_080ce204(struct Solid* p);

const SolidFunc sAnubisCoffinUpdates2[3] = {
    coffin_080cdf38,
    coffin_080ce0d4,
    coffin_080ce204,
};

// --------------------------------------------

const struct Collision sAnubisCoffinCollisions[2] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1800, 0x3C00},
    },
};

// --------------------------------------------

const struct Rect Rect_08370238 = {0, 0, 0x1800, 0x3C00};

const u8 u8_ARRAY_08370240[4] = {0, 0, 0, 0};
