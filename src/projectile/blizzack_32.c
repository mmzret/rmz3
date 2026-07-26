#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "gpu_regs.h"

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


static void (*const PTR_ARRAY_0836c408[9])(Projectile32*);
static void (*const sInitializers[9])(Projectile32*);
static void (*const sUpdates[9])(Projectile32*);
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

void FUN_080aab38(struct Enemy* e, struct Entity* parent) {
  Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);

  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 32);
    p->work[0] = 2;
    p->work[1] = 0;
    p->unk_28 = parent;
    SET_XFLIP(p, (e->s).d.x > 0);
    p->coord = (e->s).coord;
    p->coord.y = *(s32*)&e->buffer[4];
  }
}

void FUN_080aabd4(struct Entity* e) {
  Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 32);
    p->work[0] = 3;
    p->work[1] = 0;
    p->unk_28 = e;
    p->coord = e->coord;
  }
}

void FUN_080aac28(struct Entity* e) {
  Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 32);
    p->work[0] = 4;
    p->work[1] = 0;
    p->unk_28 = e;
    p->coord = e->coord;
  }
}

void FUN_080aac7c(struct Coord* c, bool8 xflip, struct Entity* e) {
  Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);

  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 32);
    p->work[0] = 5;
    p->work[1] = 0;
    p->coord = *c;
    SET_XFLIP(p, xflip);
    p->unk_28 = e;
  }
}

void FUN_080aad0c(struct Coord* c, bool8 xflip, struct Entity* e) {
  Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);

  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 32);
    p->work[0] = 6;
    p->work[1] = 0;
    p->coord = *c;
    SET_XFLIP(p, xflip);
    p->unk_28 = e;
    p->unk_2c = e->unk_28;
  }
}

void FUN_080aada0(struct Entity* e, u8 n) {
  Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);

  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 32);
    p->work[0] = 7;
    p->work[1] = n;
    p->coord = e->coord;
    SET_XFLIP(p, (e->flags >> 4) & 1);
    p->unk_28 = e;
  }
}

struct Projectile* FUN_080aae34(struct Entity* e) {
  Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);

  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 32);
    p->work[0] = 8;
    p->work[1] = 0;
    p->unk_28 = e;
    return p;
  }
  return NULL;
}

void Projectile32_Init(Projectile32* p) {
  (sInitializers[p->work[0]])(p);
}

void Projectile32_Update(Projectile32* p) {
  (sUpdates[p->work[0]])(p);
}

void Projectile32_Die(Projectile32* p) {
  (PTR_ARRAY_0836c408[p->work[0]])(p);
}

void nop_080aaecc(Projectile32* p) {}

void nop_080aaed0(Projectile32* p) {}

void nop_080aaed4(Projectile32* p) {}

INCASM("asm/projectile/blizzack_32_a.inc");

void FUN_080ab178(Projectile32* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/blizzack_32_b.inc");

void FUN_080ab724(Projectile32* p) {
  gVideoRegBuffer.dispcnt &= ~(DISPCNT_WIN0_ON | DISPCNT_BG2_ON);
  gWindowRegBuffer.dispcnt &= ~DISPCNT_WIN1_ON;
  gWindowRegBuffer.winin[2] |= 0xFE;
  StopSound(*(s16*)((u8*)p + 0xC0));
  p->flags &= ~DISPLAY;
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/blizzack_32_c.inc");

void FUN_080ab990(Projectile32* p) {
  gVideoRegBuffer.dispcnt &= ~(DISPCNT_WIN0_ON | DISPCNT_BG2_ON);
  gWindowRegBuffer.dispcnt &= ~DISPCNT_WIN1_ON;
  gWindowRegBuffer.winin[2] |= 0xFE;
  StopSound(*(s16*)((u8*)p + 0xC0));
  p->flags &= ~DISPLAY;
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/blizzack_32_d.inc");

void FUN_080abb2c(Projectile32* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/blizzack_32_e.inc");

void FUN_080abdc8(Projectile32* p) {
  *(u32*)((u8*)p + 0x8c) = 0;
  *(u32*)((u8*)p + 0x90) = 0;
  *(u8*)((u8*)p + 0x94) = 0;
  p->flags &= ~COLLIDABLE;
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/blizzack_32_f.inc");

void FUN_080abea8(Projectile32* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/blizzack_32_g.inc");

void FUN_080ac1a4(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  struct Projectile* self = (struct Projectile*)body->parent;
  struct Zero* z = (struct Zero*)(body->enemy)->parent;
  s32 kind = (z->s).kind;
  if (kind != ENTITY_PLAYER) {
    return;
  }
  {
    s32 v = (self->work[1] == 0) ? 0x180 : 0x280;
    if (self->flags & X_FLIP) {
      *(s32*)&z->horizontalSlide = v;
    } else {
      *(s32*)&z->horizontalSlide = -v;
    }
  }
}

INCASM("asm/projectile/blizzack_32_h.inc");

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
