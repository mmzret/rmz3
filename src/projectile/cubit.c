#include "collision.h"
#include "global.h"
#include "projectile.h"

struct Projectile33x {
  OBJECT_HDR;
  u8 work[4];          // 0xB4
  Coords32 prevCoord;  // 0xB8
  u32 unk_c0;          // 0xC0
};


struct Projectile* FUN_080a5f00(struct Entity* e, u8 a1) {
  struct Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 22);
    (p->s).work[0] = 0;
    (p->s).unk_28 = e;
    ((struct Projectile33x*)p)->work[2] = 0;
    ((struct Projectile33x*)p)->work[1] = a1;
  }
  return p;
}

struct Projectile* FUN_080a5f54(struct Entity* e, struct Coord* c, u8 a2, u8 a3) {
  struct Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 22);
    (p->s).work[0] = 5;
    (p->s).coord = *c;
    ((struct Projectile33x*)p)->work[0] = a2;
    ((struct Projectile33x*)p)->work[1] = a3;
    ((struct Projectile33x*)p)->work[2] = 0;
    (p->s).unk_28 = e;
  }
  return p;
}

struct Projectile* FUN_080a5fc4(struct Entity* e) {
  struct Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 22);
    (p->s).work[0] = 1;
    ((struct Projectile33x*)p)->work[2] = 0;
    (p->s).unk_28 = e;
  }
  return p;
}

struct Projectile* FUN_080a6014(struct Entity* e, struct Coord* c, u8 a2, u8 a3) {
  struct Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 22);
    (p->s).work[0] = 4;
    (p->s).coord = *c;
    ((struct Projectile33x*)p)->work[1] = a3;
    ((struct Projectile33x*)p)->work[2] = a2;
    (p->s).unk_28 = e;
  }
  return p;
}

struct Projectile* cubit_080a6078(struct Entity* e) {
  struct Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 22);
    (p->s).work[0] = 2;
    ((struct Projectile33x*)p)->work[2] = 0;
    (p->s).unk_28 = e;
  }
  return p;
}

INCASM("asm/projectile/cubit_a.inc");

static const ProjectileFunc* const sUpdates[4];

void CubitProjectile_Update(struct Projectile* p) {
  (sUpdates[(p->s).work[0]][(p->s).mode[1]])(p);
}

void CubitProjectile_Die(struct Projectile* p) {
  (p->s).flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/cubit_b.inc");

void FUN_080a7a70(struct Projectile* p) {
  (p->s).mode[1] = 1;
  (p->s).mode[2] = 0;
}

INCASM("asm/projectile/cubit_c.inc");

void CubitProjectile_Init(Projectile* p);
void CubitProjectile_Update(Projectile* p);
void CubitProjectile_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gCubitProjectileRoutine = {
    [ENTITY_INIT] =      (void*)CubitProjectile_Init,
    [ENTITY_UPDATE] =    (void*)CubitProjectile_Update,
    [ENTITY_DIE] =       (void*)CubitProjectile_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void cubit_080a63ac(Projectile* p);
void FUN_080a6718(Projectile* p);
void FUN_080a6d3c(Projectile* p);
void cubit_080a6ed4(Projectile* p);
void cubit_080a725c(Projectile* p);
void FUN_080a7478(Projectile* p);
void FUN_080a7a70(Projectile* p);
void FUN_080a7a7c(Projectile* p);

// clang-format off
static const ProjectileFunc PTR_ARRAY_ARRAY_0836bb74[4][2] = {
    {cubit_080a63ac, FUN_080a6718},
    {FUN_080a6d3c,   cubit_080a6ed4},
    {cubit_080a725c, FUN_080a7478},
    {FUN_080a7a70,   FUN_080a7a7c},
};
// clang-format on

static const ProjectileFunc* const sUpdates[4] = {
    PTR_ARRAY_ARRAY_0836bb74[0],
    PTR_ARRAY_ARRAY_0836bb74[1],
    PTR_ARRAY_ARRAY_0836bb74[2],
    PTR_ARRAY_ARRAY_0836bb74[3],
};

// --------------------------------------------

// 0x0836BBA4
static const struct Collision sCollisions[16] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 1,
      range : {PIXEL(3), PIXEL(0), PIXEL(14), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000004,
      range : {PIXEL(3), PIXEL(0), PIXEL(14), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 1,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(3), PIXEL(0), PIXEL(14), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000004,
      range : {PIXEL(3), PIXEL(0), PIXEL(14), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 4,
      layer : 0x00000004,
      range : {PIXEL(2), -PIXEL(51), PIXEL(36), PIXEL(36)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 3,
      layer : 0x00000004,
      range : {-PIXEL(11), -PIXEL(41), PIXEL(36), PIXEL(36)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 2,
      layer : 0x00000004,
      range : {PIXEL(10), -PIXEL(27), PIXEL(36), PIXEL(36)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 1,
      layer : 0x00000004,
      range : {-PIXEL(10), -PIXEL(20), PIXEL(36), PIXEL(36)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000004,
      range : {PIXEL(0), -PIXEL(8), PIXEL(36), PIXEL(36)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000004,
      range : {PIXEL(0), -PIXEL(9), PIXEL(30), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 5,
      element : 0x02,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000004,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 5,
      element : 0x02,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000004,
      range : {PIXEL(0), -PIXEL(6), PIXEL(16), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000004,
      range : {PIXEL(0), -PIXEL(5), PIXEL(12), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000004,
      range : {PIXEL(0), -PIXEL(6), PIXEL(16), PIXEL(22)},
    },
};

// clang-format off
// 0x0836bd24
static const Coords32 sCoords[30] = {
    {PIXEL(0), PIXEL(0)},
    {-PIXEL(13), -PIXEL(9)},
    {PIXEL(11), -PIXEL(17)},
    {-PIXEL(12), -PIXEL(28)},
    {PIXEL(0), -PIXEL(38)},
    {PIXEL(20), PIXEL(60)},
    {PIXEL(49), PIXEL(94)},
    {PIXEL(102), PIXEL(28)},
    {PIXEL(155), PIXEL(94)},
    {PIXEL(184), PIXEL(60)},
    {-PIXEL(16), -PIXEL(10)},
    {-PIXEL(25), -PIXEL(21)},
    {-PIXEL(22), -PIXEL(34)},
    {-PIXEL(12), -PIXEL(44)},
    {PIXEL(0), -PIXEL(48)},
    {PIXEL(12), -PIXEL(44)},
    {PIXEL(22), -PIXEL(34)},
    {PIXEL(25), -PIXEL(21)},
    {PIXEL(16), -PIXEL(10)},
    {-PIXEL(26), -PIXEL(36)},
    {PIXEL(26), -PIXEL(36)},
    {-PIXEL(16), -PIXEL(10)},
    {-PIXEL(25), -PIXEL(21)},
    {-PIXEL(22), -PIXEL(34)},
    {-PIXEL(12), -PIXEL(44)},
    {PIXEL(0), -PIXEL(48)},
    {PIXEL(12), -PIXEL(44)},
    {PIXEL(22), -PIXEL(34)},
    {PIXEL(25), -PIXEL(21)},
    {PIXEL(16), -PIXEL(10)},
};
// clang-format on

static const s32 s32_ARRAY_0836be14[9] = {
    0x7B, 0x7A, 0x79, 0x3F, 0x3E, 0x3D, 0x3, 0x2, 0x1,
};
