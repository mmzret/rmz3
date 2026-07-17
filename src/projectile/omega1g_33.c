#include "collision.h"
#include "global.h"
#include "projectile.h"

struct Projectile33x {
  OBJECT_HDR;
  u8 work[4];          // 0xB4
  Coords32 prevCoord;  // 0xB8
  u32 unk_c0;          // 0xC0
};


static const ProjectileFunc sUpdates[3];

struct Projectile* createGoldOmega1Laser(s32 a0, u8 a1, s32 a2, struct Entity* e) {
  struct Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 33);
    (p->s).work[0] = 0;
    ((struct Projectile33x*)p)->work[0] = a1;
    ((struct Projectile33x*)p)->prevCoord.x = a0;
    ((struct Projectile33x*)p)->prevCoord.y = a2;
    (p->s).unk_28 = e;
  }
  return p;
}

struct Projectile* FUN_080ac3e8(struct Coord* c, u8 a1, u16 a2) {
  struct Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 33);
    (p->s).work[0] = 1;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
    (p->s).work[1] = a1;
    ((struct Projectile33x*)p)->prevCoord.y = a2;
  }
  return p;
}

INCASM("asm/projectile/omega1g_33_a.inc");

void OmegaGoldProjectile_Update(struct Projectile* p) {
  (sUpdates[(p->s).mode[1]])(p);
}

void OmegaGoldProjectile_Die(struct Projectile* p) {
  (p->s).flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/omega1g_33_b.inc");

void OmegaGoldProjectile_Init(Projectile* p);
void OmegaGoldProjectile_Update(Projectile* p);
void OmegaGoldProjectile_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gOmegaGoldProjectileRoutine = {
    [ENTITY_INIT] =      (void*)OmegaGoldProjectile_Init,
    [ENTITY_UPDATE] =    (void*)OmegaGoldProjectile_Update,
    [ENTITY_DIE] =       (void*)OmegaGoldProjectile_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void doGoldOmega1Laser1(Projectile* p);
void doGoldOmega1Laser2(Projectile* p);
void FUN_080ac700(Projectile* p);

static const ProjectileFunc sUpdates[3] = {
    doGoldOmega1Laser1,
    doGoldOmega1Laser2,
    FUN_080ac700,
};

// --------------------------------------------

static const struct Collision sCollisions[4] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 1,
      range : {PIXEL(0), PIXEL(2), PIXEL(26), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(2), PIXEL(26), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
};

static const s32 s32_ARRAY_0836c674[32] = {
    0x00000180, -0x00000300, -0x00000220, -0x00000260, -0x00000220, -0x00000300, 0x000002C0, -0x00000260, -0x00000180, -0x00000300, -0x00000200, -0x00000280, 0x00000160, -0x000001F0, 0x00000260, -0x00000280, 0x00000200, -0x00000400, 0x00000120, -0x000002A0, 0x00000120, -0x00000340, -0x000000B0, -0x000002A0, -0x00000200, -0x00000400, 0x00000120, -0x000002A0, 0x00000120, -0x00000340, -0x000000B0, -0x000002A0,
};

static const s32* const PTR_ARRAY_0836c6f4[4] = {
    &s32_ARRAY_0836c674[0],
    &s32_ARRAY_0836c674[8],
    &s32_ARRAY_0836c674[16],
    &s32_ARRAY_0836c674[24],
};
