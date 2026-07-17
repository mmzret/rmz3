#include "collision.h"
#include "global.h"
#include "projectile.h"

// Blizzack関連なのは確定
typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 buffer[16];         // 0xB4
} Projectile32;
static_assert(sizeof(Projectile32) == sizeof(Projectile));

void Projectile32_Init(Projectile32* p);
void Projectile32_Update(Projectile32* p);
void Projectile32_Die(Projectile32* p);

// clang-format off
const ProjectileRoutine gProjectile32Routine = {
    [ENTITY_INIT] =      (void*)Projectile32_Init,
    [ENTITY_UPDATE] =    (void*)Projectile32_Update,
    [ENTITY_DIE] =       (void*)Projectile32_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

Entity* FUN_080aaa80(Entity* q, u8 kind1, u8 kind2) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 32);
    p->work[0] = kind1, p->work[1] = kind2;
    p->unk_28 = (void*)q;
    (p->coord) = q->coord;
    return p;
  }
  return NULL;
}

void blizzack_080aaae0(Entity* q, u8 val) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 32);
    p->work[0] = 1, p->work[1] = val;
    p->unk_28 = q;
    (p->coord) = q->coord;
  }
}

static const ProjectileFunc sInitializers[9];
static const ProjectileFunc sUpdates[9];
static const ProjectileFunc PTR_ARRAY_0836c408[9];

INCASM("asm/projectile/blizzack_32_a.inc");

void Projectile32_Init(struct Projectile* p) {
  (sInitializers[(p->s).work[0]])(p);
}


void Projectile32_Update(struct Projectile* p) {
  (sUpdates[(p->s).work[0]])(p);
}


void Projectile32_Die(struct Projectile* p) {
  (PTR_ARRAY_0836c408[(p->s).work[0]])(p);
}


void nop_080aaecc(struct Projectile* p) {}


void nop_080aaed0(struct Projectile* p) {}


void nop_080aaed4(struct Projectile* p) {}

INCASM("asm/projectile/blizzack_32_b.inc");

void FUN_080ab178(struct Projectile* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/blizzack_32_c.inc");

void FUN_080abb2c(struct Projectile* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/blizzack_32_d.inc");

void FUN_080abdc8(struct Projectile* p) {
  *(u32*)((u8*)p + 0x8c) = 0;
  *(u32*)((u8*)p + 0x90) = 0;
  *(u8*)((u8*)p + 0x94) = 0;
  (p->s).flags &= ~COLLIDABLE;
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/blizzack_32_e.inc");

void FUN_080abea8(struct Projectile* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/blizzack_32_f.inc");

// --------------------------------------------

void nop_080aaecc(Projectile32* p);
void FUN_080aaed8(Projectile32* p);
void FUN_080ab190(Projectile32* p);
void FUN_080ab550(Projectile32* p);
void FUN_080ab784(Projectile32* p);
void FUN_080ab9f0(Projectile32* p);
void FUN_080abb44(Projectile32* p);
void FUN_080abdf8(Projectile32* p);
void FUN_080abec0(Projectile32* p);

// clang-format off
static void (*const sInitializers[9])(Projectile32*) = {
    nop_080aaecc,
    FUN_080aaed8,
    FUN_080ab190,
    FUN_080ab550,
    FUN_080ab784,
    FUN_080ab9f0,
    FUN_080abb44,
    FUN_080abdf8,
    FUN_080abec0,
};
// clang-format on

void nop_080aaed0(Projectile32* p);
void FUN_080ab004(Projectile32* p);
void FUN_080ab21c(Projectile32* p);
void FUN_080ab668(Projectile32* p);
void FUN_080ab8cc(Projectile32* p);
void FUN_080aba60(Projectile32* p);
void FUN_080abbb8(Projectile32* p);
void FUN_080abe54(Projectile32* p);
void FUN_080abf54(Projectile32* p);

// clang-format off
static void (*const sUpdates[9])(Projectile32*) = {
    nop_080aaed0,
    FUN_080ab004,
    FUN_080ab21c,
    FUN_080ab668,
    FUN_080ab8cc,
    FUN_080aba60,
    FUN_080abbb8,
    FUN_080abe54,
    FUN_080abf54,
};
// clang-format on

void nop_080aaed4(Projectile32* p);
void FUN_080ab178(Projectile32* p);
void FUN_080ab3ac(Projectile32* p);
void FUN_080ab724(Projectile32* p);
void FUN_080ab990(Projectile32* p);
void FUN_080abb2c(Projectile32* p);
void FUN_080abdc8(Projectile32* p);
void FUN_080abea8(Projectile32* p);
void FUN_080abfbc(Projectile32* p);

// clang-format off
static void (*const PTR_ARRAY_0836c408[9])(Projectile32*) = {
    nop_080aaed4,
    FUN_080ab178,
    FUN_080ab3ac,
    FUN_080ab724,
    FUN_080ab990,
    FUN_080abb2c,
    FUN_080abdc8,
    FUN_080abea8,
    FUN_080abfbc,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[14] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      unk_0a : 0x41,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(12), PIXEL(32), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 255,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      unk_0a : 0x41,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(8), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(80)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 255,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(12), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 255,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), -PIXEL(1), -PIXEL(1)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 255,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};

static const s32 s32_ARRAY_0836c57c[30] = {
    0x00001800, 0x00001800, -0x00000001, -0x00001800, 0x00000000, 0x00000000, 0x00001800, 0x00000000, 0x00000000, 0x00001800, 0x00001800, 0x00000000, -0x00000001, -0x00001800, 0x00000000, 0x00001800, -0x00001800, 0x00000000, 0x00001800, -0x00001800, 0x00000000, 0x00000000, -0x00000001, 0x00001800, 0x00000000, -0x00000001, -0x00001800, 0x00000000, -0x00000001, -0x00001800,
};
