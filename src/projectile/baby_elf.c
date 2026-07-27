#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "vfx.h"

static const struct Collision sCollisions[5];
static const ProjectileFunc sUpdates1[7];
static const ProjectileFunc sUpdates2[7];
static const u8 u8_0836b0c8[6];

// Baby Elf's projectile

void Projectile13_Init(Projectile* p);
void Projectile13_Update(Projectile* p);
void Projectile13_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile13Routine = {
    [ENTITY_INIT] =      (void*)Projectile13_Init,
    [ENTITY_UPDATE] =    (void*)Projectile13_Update,
    [ENTITY_DIE] =       (void*)Projectile13_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_0809f8ac(Entity* q) {
  s32 i;
  for (i = 0; i < 4; i++) {
    Entity* p = (Entity*)AllocEntityFirst(gProjectileHeaderPtr);
    if (p != NULL) {
      INIT_PROJECTILE_ROUTINE(p, 13);
      p->work[0] = 5, p->work[2] = i;
      p->unk_28 = q;
    }
  }
}

void FUN_0809f8fc(s32 x, s32 y, u8 sineidx) {
  Entity* p = (Entity*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 13);
    p->work[0] = 0;
    (p->coord).x = x, (p->coord).y = y;
    (p->d).x = COS(sineidx) << 1;
    (p->d).y = -(SIN(sineidx) << 1);
  }
}

void FUN_0809f970(s32 x, s32 y, u8 work2) {
  Entity* p = (Entity*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 13);
    p->work[0] = 1, p->work[2] = work2;
    (p->unk_coord).x = x, (p->unk_coord).y = y;
    (p->coord).x = x - PIXEL(4) + (RANDOM(RNG_0202f388) & 0x7FF);
    (p->coord).y = y;
  }
}

void babyelf_0809f9f0(struct Entity* parent, s32 x, s32 y, u8 n) {
  struct Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);

  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 13);
    p->work[0] = 2;
    p->coord.x = x;
    p->coord.y = y;
    p->work[2] = n;
    p->unk_28 = parent;
  }
}

void FUN_0809fa44(struct Entity* parent, s32 x, s32 y, u8 n) {
  struct Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);

  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 13);
    p->work[0] = 3;
    p->work[2] = n;
    p->unk_coord.x = x;
    p->unk_coord.y = y;
    p->coord.x = x;
    p->coord.y = y;
    p->unk_28 = parent;
  }
}

void FUN_0809fa9c(struct Entity* parent, s32 x, s32 y, u8 n) {
  struct Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);

  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 13);
    p->work[0] = 4;
    p->work[2] = n;
    p->coord.x = x;
    p->coord.y = y;
    p->unk_28 = parent;
  }
}

void nop_0809faf0(struct Projectile* p) {}

void Projectile13_Init(Projectile* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = u8_0836b0c8[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, sCollisions, 1, (void*)nop_0809faf0);
  Projectile13_Update(p);
}

void Projectile13_Update(Projectile* p) {
  (sUpdates1[p->mode[1]])((void*)p);
  (sUpdates2[p->mode[1]])((void*)p);
}

void Projectile13_Die(Projectile* p) {
  EXIT_BODY(p);
  CreateSmoke(3, &p->coord);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

void nop_0809fbd8(Projectile* p) {}

INCASM("asm/projectile/baby_elf_a.inc");

// --------------------------------------------

void nop_0809fbd8(Projectile* p);

// clang-format off
static const ProjectileFunc sUpdates1[7] = {
    nop_0809fbd8,
    nop_0809fbd8,
    nop_0809fbd8,
    nop_0809fbd8,
    nop_0809fbd8,
    nop_0809fbd8,
    nop_0809fbd8,
};
// clang-format on

// --------------------------------------------

void FUN_0809fbdc(Projectile* p);
void FUN_0809fcfc(Projectile* p);
void FUN_0809ff74(Projectile* p);
void FUN_080a025c(Projectile* p);
void FUN_080a03ac(Projectile* p);
void FUN_080a04d4(Projectile* p);
void FUN_080a06c0(Projectile* p);

// clang-format off
static const ProjectileFunc sUpdates2[7] = {
    FUN_0809fbdc,
    FUN_0809fcfc,
    FUN_0809ff74,
    FUN_080a025c,
    FUN_080a03ac,
    FUN_080a04d4,
    FUN_080a06c0,
};
// clang-format on

// --------------------------------------------

// 0x0836B050
static const struct Collision sCollisions[5] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(10)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(10)},
    },
};

static const u8 u8_0836b0c8[6] = {0, 1, 2, 3, 4, 5};

// 0x0836B0CE
static const s16 sUnkDeltaX[4] = {PIXEL(48), PIXEL(32), -PIXEL(32), -PIXEL(48)};

static const s16 s16_ARRAY_0836b0d6[4] = {
    0x30,
    0x90,
    0xC0,
    0x60,
};
