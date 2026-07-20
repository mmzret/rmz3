#include "collision.h"
#include "global.h"
#include "projectile.h"

typedef struct {
  COLLISION_OBJECT_HDR;
  u8 unk_b4[8];  // 0xB4
  u8 unk_bc;     // 0xBC
  u32 unk_c0;    // 0xC0
} Projectile14;
static_assert(sizeof(Projectile14) == sizeof(struct Projectile));

void Projectile14_Init(struct Projectile* p);
void Projectile14_Update(struct Projectile* p);
void Projectile14_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile14Routine = {
    [ENTITY_INIT] =      (void*)Projectile14_Init,
    [ENTITY_UPDATE] =    (void*)Projectile14_Update,
    [ENTITY_DIE] =       (void*)Projectile14_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080a0888(s32 x, s32 y, u8 kind, bool8 xflip) {
  struct Entity* p = AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 14);
    p->work[0] = 4;
    (p->coord).x = x, (p->coord).y = y;
    p->work[2] = kind, p->work[3] = xflip;
  }
}

void FUN_080a08e0(struct Entity* q, s32 x, s32 y, bool8 xflip) {
  struct Entity* p = AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 14);
    p->work[0] = 0;
    (p->coord).x = x, (p->coord).y = y;
    p->work[2] = xflip;
    p->unk_28 = q;
  }
}

void deathtanz_080a0934(struct Entity* q, s32 x, s32 y, bool8 xflip, bool8 r4) {
  Projectile14* p = AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 14);
    p->work[0] = 1;
    (p->coord).x = x, (p->coord).y = y;
    p->work[2] = xflip;
    p->unk_28 = q, p->unk_bc = r4;
  }
}

void deathtanz_080a09a0(struct Entity* q, s32 x, s32 y, bool8 xflip) {
  struct Entity* p = AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 14);
    p->work[0] = 2;
    (p->coord).x = x, (p->coord).y = y;
    p->work[2] = xflip;
    p->unk_28 = q;
  }
}

void deathtanz_080a09f4(struct Entity* q, s32 x, s32 y, u8 kind, bool8 xflip) {
  struct Entity* p = AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 14);
    p->work[0] = 3;
    (p->coord).x = x, (p->coord).y = y;
    p->work[2] = kind, p->work[3] = xflip;
    p->unk_28 = q;
  }
}

// 0x080a0a5c
static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {}

INCASM("asm/projectile/unk_14.inc");

void nop_080a0b6c(struct Projectile* p);

// clang-format off
// 0x0836b0f4
static const ProjectileFunc sUpdates1[5] = {
    (void*)nop_080a0b6c,
    (void*)nop_080a0b6c,
    (void*)nop_080a0b6c,
    (void*)nop_080a0b6c,
    (void*)nop_080a0b6c,
};
// clang-format on

void FUN_080a0b70(struct Projectile* p);
void FUN_080a0dc0(struct Projectile* p);
void FUN_080a0fa8(struct Projectile* p);
void FUN_080a1280(struct Projectile* p);
void FUN_080a133c(struct Projectile* p);

// clang-format off
// 0x0836b108
static const ProjectileFunc sUpdates2[5] = {
    (void*)FUN_080a0b70,
    (void*)FUN_080a0dc0,
    (void*)FUN_080a0fa8,
    (void*)FUN_080a1280,
    (void*)FUN_080a133c,
};
// clang-format on

// --------------------------------------------

// 0x0836b11c
static const struct Collision sCollisions[10] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(40), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(50), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(26), PIXEL(50)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(4), PIXEL(2), PIXEL(40), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(20), PIXEL(19), PIXEL(8), PIXEL(51)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(60)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(57), -PIXEL(24), PIXEL(36), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(35), -PIXEL(11), PIXEL(37), PIXEL(13)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(57), -PIXEL(39), PIXEL(36), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(35), -PIXEL(53), PIXEL(37), PIXEL(13)},
    },
};

// 0x0836b20c
static const u8 u8_ARRAY_0836b20c[5] = {0, 1, 2, 3, 4};

// 0x0836b211
static const u8 u8_ARRAY_0836b211[2] = {6, 8};
