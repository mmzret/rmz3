#include "collision.h"
#include "global.h"
#include "projectile.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4;             // 0xB4
  u8 unk_b5;             // 0xB5
  u8 unk_b6;             // 0xB6
  u8 unk_b7;             // 0xB7
  u8 unk_b8[4];          // 0xB8
  u32 unk_bc;            // 0xBC
  u8 unk_c0[4];          // 0xC0
} HellbatProjectile;
static_assert(sizeof(HellbatProjectile) == sizeof(Projectile));

// Entity.work[0]
enum {
  HELLBAT_PROJ_BAT = 0,
  HELLBAT_PROJ_ECHO_WAVE,
  HELLBAT_PROJ_UNK2,
  HELLBAT_PROJ_UNK3,
  HELLBAT_PROJ_UNK4,
};

static const struct Collision sCollisions[9];

static void Projectile15_Init(HellbatProjectile* p);
static void Projectile15_Update(HellbatProjectile* p);
static void Projectile15_Die(HellbatProjectile* p);

// clang-format off
const ProjectileRoutine gHellbatProjectileRoutine = {
    [ENTITY_INIT] =      (void*)Projectile15_Init,
    [ENTITY_UPDATE] =    (void*)Projectile15_Update,
    [ENTITY_DIE] =       (void*)Projectile15_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

typedef void (*HellbatProjectileFunc)(HellbatProjectile*);

HellbatProjectile* createBat(Entity* hellbat, Coords32* c, u8 a2, u8 a3) {
  HellbatProjectile* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 15);
    p->work[0] = 0;
    p->unk_b5 = a2;
    p->unk_b6 = a3;
    p->coord = *c;
    p->unk_28 = hellbat;
  }
  return p;
}

HellbatProjectile* createEchoWave(Entity* hellbat, Coords32* c, u8 a2) {
  HellbatProjectile* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 15);
    p->work[0] = 1;
    p->unk_b5 = a2;
    p->coord = *c;
    p->unk_28 = hellbat;
  }
  return p;
}

HellbatProjectile* FUN_080a14dc(Entity* hellbat, Coords32* c, u8 a2) {
  HellbatProjectile* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 15);
    p->work[0] = 2;
    p->unk_b5 = a2;
    p->coord = *c;
    p->unk_28 = hellbat;
  }
  return p;
}

HellbatProjectile* FUN_080a1538(Entity* hellbat, Coords32* c, u8 a2) {
  HellbatProjectile* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 15);
    p->work[0] = 3;
    p->unk_b5 = a2;
    p->coord = *c;
    p->unk_28 = hellbat;
  }
  return p;
}

HellbatProjectile* FUN_080a1594(Entity* hellbat, Coords32* c, u8 a2) {
  HellbatProjectile* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 15);
    p->work[0] = 4;
    p->unk_b5 = a2;
    p->coord = *c;
    p->unk_28 = hellbat;
  }
  return p;
}

static void Projectile15_Init(HellbatProjectile* p) {
  p->work[2] = 0xFF;
  if (p->work[0] == HELLBAT_PROJ_BAT) {
    EnableSpriteAnimation_Normal(p);
    _INIT_BODY(p, &sCollisions[0], 4);
  } else if (p->work[0] == HELLBAT_PROJ_ECHO_WAVE) {
    EnableSpriteAnimation_Normal(p);
    p->work[2] = 0;
    p->unk_bc = 0;
    EnableSpriteAnimation_Normal(p);
    p->angle = 0, (p->spr).mag.x = 0x100, (p->spr).mag.y = 0x100;
    _INIT_BODY(p, &sCollisions[5], 1);
  } else if (p->work[0] == HELLBAT_PROJ_UNK2) {
    EnableSpriteAnimation_Normal(p);
    _INIT_BODY(p, &sCollisions[2], 1);
  } else if (p->work[0] == HELLBAT_PROJ_UNK3) {
    EnableSpriteAnimation_Affine(p);
    p->angle = 0, (p->spr).mag.x = 0x100, (p->spr).mag.y = 0x100;
    _INIT_BODY(p, &sCollisions[3], 1);
  } else if (p->work[0] == HELLBAT_PROJ_UNK4) {
    EnableSpriteAnimation_Normal(p);
    _INIT_BODY(p, &sCollisions[3], 1);
  }

  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteTableDynamic(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 1, p->mode[2] = 0, p->mode[3] = 0;
  Projectile15_Update(p);
}

static const HellbatProjectileFunc* const sUpdates[5];

static void Projectile15_Update(HellbatProjectile* p) { (sUpdates[p->work[0]][p->mode[1]])(p); }

static void Projectile15_Die(HellbatProjectile* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

static void FUN_080a176c(HellbatProjectile* p) {
  p->mode[1] = 1;
  p->mode[2] = 0;
}

INCASM("asm/projectile/hellbat_b.inc");

static void FUN_080a1a10(HellbatProjectile* p) {
  p->mode[1] = 1;
  p->mode[2] = 0;
}

INCASM("asm/projectile/hellbat_c.inc");

static void FUN_080a1f10(HellbatProjectile* p) {
  p->mode[1] = 1;
  p->mode[2] = 0;
}

INCASM("asm/projectile/hellbat_d.inc");

static void FUN_080a2020(HellbatProjectile* p) {
  p->mode[1] = 1;
  p->mode[2] = 0;
}

INCASM("asm/projectile/hellbat_e.inc");

static void FUN_080a22ec(HellbatProjectile* p) {
  p->mode[1] = 1;
  p->mode[2] = 0;
}

INCASM("asm/projectile/hellbat_f.inc");

static void FUN_080a176c(HellbatProjectile* p);
void FUN_080a1778(HellbatProjectile* p);

static const HellbatProjectileFunc sUpdates1[2] = {
    FUN_080a176c,
    FUN_080a1778,
};

static void FUN_080a1a10(HellbatProjectile* p);
void FUN_080a1a1c(HellbatProjectile* p);

static const HellbatProjectileFunc sUpdates2[2] = {
    FUN_080a1a10,
    FUN_080a1a1c,
};

static void FUN_080a1f10(HellbatProjectile* p);
void FUN_080a1f1c(HellbatProjectile* p);

static const HellbatProjectileFunc sUpdates3[2] = {
    FUN_080a1f10,
    FUN_080a1f1c,
};

static void FUN_080a2020(HellbatProjectile* p);
void FUN_080a202c(HellbatProjectile* p);

static const HellbatProjectileFunc sUpdates4[2] = {
    FUN_080a2020,
    FUN_080a202c,
};

static void FUN_080a22ec(HellbatProjectile* p);
void FUN_080a22f8(HellbatProjectile* p);

static const HellbatProjectileFunc sUpdates5[2] = {
    FUN_080a22ec,
    FUN_080a22f8,
};

// clang-format off
static const HellbatProjectileFunc* const sUpdates[5] = {
    sUpdates1,
    sUpdates2,
    sUpdates3,
    sUpdates4,
    sUpdates5,
};
// clang-format on

static const struct Collision sCollisions[9] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 1,
      range : {PIXEL(0), -PIXEL(2), PIXEL(20), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(2), PIXEL(20), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      element : ELEMENT_THUNDER,
      remaining : 0,
      layer : 0x00000002,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 5,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(11), PIXEL(30)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 5,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(10)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(10)},
    },
};  // 0x0836B264
