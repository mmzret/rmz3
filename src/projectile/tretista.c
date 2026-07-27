#include "collision.h"
#include "global.h"
#include "projectile.h"

static const ProjectileFunc* const PTR_ARRAY_0836b4e4[4];

void TretistaProjectile_Init(Projectile* p);
void TretistaProjectile_Update(Projectile* p);
void TretistaProjectile_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gTretistaProjectileRoutine = {
    [ENTITY_INIT] =      (void*)TretistaProjectile_Init,
    [ENTITY_UPDATE] =    (void*)TretistaProjectile_Update,
    [ENTITY_DIE] =       (void*)TretistaProjectile_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

Entity* createTretistaBreathGas(Entity* e, Coords32* c, u8 kind) {
  Entity* p = (Entity*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 19);
    p->work[0] = 0, p->work[1] = kind;
    (p->coord) = *c;
    p->unk_28 = (void*)e;
  }
  return p;
}

struct Projectile* tretista_080a369c(struct Entity* e, struct Coord* c, u8 a2) {
  struct Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 19);
    p->work[0] = 1;
    p->work[1] = a2;
    p->coord = *c;
    p->unk_28 = e;
  }
  return p;
}

struct Projectile* tretista_080a36f4(struct Entity* e, struct Coord* c, u8 a2) {
  struct Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 19);
    p->work[0] = 2;
    p->work[1] = a2;
    p->coord = *c;
    p->unk_28 = e;
  }
  return p;
}

struct Projectile* FUN_080a374c(struct Entity* e, struct Coord* c, u8 a2) {
  struct Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 19);
    p->work[0] = 3;
    p->work[1] = a2;
    p->coord = *c;
    p->unk_28 = e;
  }
  return p;
}

INCASM("asm/projectile/tretista_a.inc");

void TretistaProjectile_Update(Projectile* p) {
  (PTR_ARRAY_0836b4e4[p->work[0]][p->mode[1]])(p);
}

void TretistaProjectile_Die(Projectile* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/tretista_b.inc");

void FUN_080a38e8(Projectile* p);
void FUN_080a3c58(Projectile* p);
void FUN_080a44c0(Projectile* p);
void FUN_080a4d0c(Projectile* p);

static const ProjectileFunc PTR_ARRAY_0836b4d4[4] = {
    FUN_080a38e8,
    FUN_080a3c58,
    FUN_080a44c0,
    FUN_080a4d0c,
};

static const ProjectileFunc* const PTR_ARRAY_0836b4e4[4] = {
    &PTR_ARRAY_0836b4d4[0],
    &PTR_ARRAY_0836b4d4[1],
    &PTR_ARRAY_0836b4d4[2],
    &PTR_ARRAY_0836b4d4[3],
};

// --------------------------------------------

// 0x0836B4F4
static const struct Collision sCollisions[53] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), PIXEL(0), PIXEL(22), PIXEL(22)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 3,
      layer : 1,
      range : {PIXEL(8), -PIXEL(11), PIXEL(50), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 2,
      range : {PIXEL(8), -PIXEL(11), PIXEL(50), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {-PIXEL(11), PIXEL(6), PIXEL(11), PIXEL(47)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(11), PIXEL(6), PIXEL(11), PIXEL(47)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 3,
      layer : 1,
      range : {PIXEL(8), PIXEL(0), PIXEL(18), PIXEL(58)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 2,
      range : {PIXEL(8), PIXEL(0), PIXEL(18), PIXEL(58)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {-PIXEL(7), PIXEL(1), PIXEL(12), PIXEL(35)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(7), PIXEL(1), PIXEL(12), PIXEL(35)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 3,
      layer : 1,
      range : {-PIXEL(11), -PIXEL(9), PIXEL(13), PIXEL(49)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 2,
      range : {-PIXEL(11), -PIXEL(9), PIXEL(13), PIXEL(49)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(9), PIXEL(12), PIXEL(48), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(9), PIXEL(12), PIXEL(48), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 3,
      layer : 1,
      range : {PIXEL(0), PIXEL(9), PIXEL(28), PIXEL(17)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 2,
      range : {PIXEL(0), PIXEL(9), PIXEL(28), PIXEL(17)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(0), -PIXEL(9), PIXEL(60), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(9), PIXEL(60), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 3,
      layer : 1,
      range : {PIXEL(12), -PIXEL(9), PIXEL(13), PIXEL(49)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 2,
      range : {PIXEL(12), -PIXEL(9), PIXEL(13), PIXEL(49)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {-PIXEL(9), PIXEL(12), PIXEL(48), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(9), PIXEL(12), PIXEL(48), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 3,
      layer : 1,
      range : {-PIXEL(8), PIXEL(0), PIXEL(18), PIXEL(58)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 2,
      range : {-PIXEL(8), PIXEL(0), PIXEL(18), PIXEL(58)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(7), PIXEL(1), PIXEL(12), PIXEL(35)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(7), PIXEL(1), PIXEL(12), PIXEL(35)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 3,
      layer : 1,
      range : {-PIXEL(9), -PIXEL(12), PIXEL(48), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 2,
      range : {-PIXEL(9), -PIXEL(12), PIXEL(48), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(12), PIXEL(8), PIXEL(13), PIXEL(49)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(12), PIXEL(8), PIXEL(13), PIXEL(49)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 3,
      layer : 1,
      range : {PIXEL(0), -PIXEL(9), PIXEL(28), PIXEL(17)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 2,
      range : {PIXEL(0), -PIXEL(9), PIXEL(28), PIXEL(17)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(0), PIXEL(9), PIXEL(60), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), PIXEL(9), PIXEL(60), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(0), -PIXEL(9), PIXEL(28), PIXEL(17)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), PIXEL(9), PIXEL(60), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {-PIXEL(9), -PIXEL(12), PIXEL(48), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {PIXEL(12), PIXEL(8), PIXEL(13), PIXEL(49)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {-PIXEL(8), PIXEL(0), PIXEL(18), PIXEL(58)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {PIXEL(7), PIXEL(1), PIXEL(12), PIXEL(35)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(12), -PIXEL(9), PIXEL(13), PIXEL(49)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {-PIXEL(9), PIXEL(12), PIXEL(48), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(0), PIXEL(9), PIXEL(28), PIXEL(17)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), -PIXEL(9), PIXEL(60), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {-PIXEL(11), -PIXEL(9), PIXEL(13), PIXEL(49)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {PIXEL(9), PIXEL(12), PIXEL(48), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(8), PIXEL(0), PIXEL(18), PIXEL(58)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {-PIXEL(7), PIXEL(1), PIXEL(12), PIXEL(35)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(8), -PIXEL(11), PIXEL(50), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {-PIXEL(11), PIXEL(6), PIXEL(11), PIXEL(47)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {PIXEL(29), -PIXEL(38), PIXEL(22), PIXEL(54)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {-PIXEL(47), -PIXEL(34), PIXEL(90), PIXEL(26)},
    },
};

// clang-format off
static const Coords32 sCoords[10] = {
    {PIXEL(28), PIXEL(24)},
    {-PIXEL(28), -PIXEL(24)},
    {PIXEL(14), PIXEL(10)},
    {-PIXEL(14), -PIXEL(10)},
    {PIXEL(28), -PIXEL(24)},
    {-PIXEL(28), PIXEL(24)},
    {-PIXEL(14), PIXEL(10)},
    {PIXEL(14), -PIXEL(10)},
    {PIXEL(0), PIXEL(0)},
    {PIXEL(0), PIXEL(0)},
};
// clang-format on
