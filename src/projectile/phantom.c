#include "collision.h"
#include "global.h"
#include "projectile.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4[16];         // 0xB4
} PhantomProjectile;
static_assert(sizeof(PhantomProjectile) == sizeof(struct Projectile));

static void PhantomProjectile_Init(PhantomProjectile* p);
static void PhantomProjectile_Update(PhantomProjectile* p);
void PhantomProjectile_Die(PhantomProjectile* p);

// clang-format off
const ProjectileRoutine gPhantomProjectileRoutine = {
    [ENTITY_INIT] =      (void*)PhantomProjectile_Init,
    [ENTITY_UPDATE] =    (void*)PhantomProjectile_Update,
    [ENTITY_DIE] =       (void*)PhantomProjectile_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static const struct Collision sCollisions[8] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      atkType : 0x00,
      comboLv : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(5), -PIXEL(5), PIXEL(10), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 3,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      atkType : 0x00,
      comboLv : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(24), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 5,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      atkType : 0x00,
      comboLv : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 5,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      comboLv : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(8)},
    },
};

// --------------------------------------------

static void FUN_080af114(PhantomProjectile* p);
static void FUN_080af1b4(PhantomProjectile* p);
static void FUN_080af214(PhantomProjectile* p);
static void FUN_080af250(PhantomProjectile* p);
static void FUN_080af70c(PhantomProjectile* p);
static void FUN_080af2b0(PhantomProjectile* p);

static void PhantomProjectile_Init(PhantomProjectile* p) {
  // clang-format off
  static void (*const sInitializers[6])(PhantomProjectile*) = {
    FUN_080af114,
    FUN_080af1b4,
    FUN_080af214,
    FUN_080af250,
    FUN_080af70c,
    FUN_080af2b0,
  };
  // clang-format on
  (sInitializers[p->work[0]])(p);
}

static void FUN_080af114(PhantomProjectile* p) {
  if ((p->unk_28)->mode[0] > 1) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
  } else if (*((u16*)&(p->unk_28)->mode[2]) == 0x101) {
    SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 0;
    EnableSpriteAnimation_Normal(p);
    p->renderPrio = 25;
    p->flags |= DISPLAY;
    p->flags |= FLIPABLE;
    SetSpriteAnimation(p, MOTION(SM134_NINJA_STAR, 3));
    PhantomProjectile_Update(p);
  }
}

static void FUN_080af1b4(PhantomProjectile* p) {
  INIT_BODY(p, &sCollisions[0], 0, NULL);
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0;
  EnableSpriteAnimation_Rotatable(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  PhantomProjectile_Update(p);
}

static void FUN_080af214(PhantomProjectile* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0;
  EnableSpriteAnimation_Rotatable(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  PhantomProjectile_Update(p);
}

static void FUN_080af250(PhantomProjectile* p) {
  INIT_BODY(p, &sCollisions[4], 0, NULL);
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0;
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  PhantomProjectile_Update(p);
}

static void FUN_080af2b0(PhantomProjectile* p) {
  INIT_BODY(p, &sCollisions[6], 0, NULL);
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->flags &= ~DISPLAY;
  p->flags |= FLIPABLE;
  PhantomProjectile_Update(p);
}

// --------------------------------------------

static void FUN_080af32c(PhantomProjectile* p);
static void FUN_080af61c(PhantomProjectile* p);
void FUN_080af8b0(PhantomProjectile* p);
void FUN_080af9b0(PhantomProjectile* p);
void FUN_080af748(PhantomProjectile* p);
void FUN_080afb1c(PhantomProjectile* p);

static void PhantomProjectile_Update(PhantomProjectile* p) {
  // clang-format off
  static void (*const sUpdates[6])(PhantomProjectile*) = {
    FUN_080af32c,
    FUN_080af61c,
    FUN_080af8b0,
    FUN_080af9b0,
    FUN_080af748,
    FUN_080afb1c,
  };
  // clang-format on
  (sUpdates[p->work[0]])(p);
  UpdateSpriteAnimation(p);
}

void FUN_080af368(PhantomProjectile* p);
void FUN_080af3ec(PhantomProjectile* p);
void FUN_080af46c(PhantomProjectile* p);

static void FUN_080af32c(PhantomProjectile* p) {
  static void (*const PTR_ARRAY_0836d418[3])(PhantomProjectile*) = {
      FUN_080af368,
      FUN_080af3ec,
      FUN_080af46c,
  };

  if ((p->unk_28)->mode[0] >= 2) {
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    return;
  }
  (PTR_ARRAY_0836d418[p->mode[1]])(p);
}

static void (*const PTR_ARRAY_0836d430[2])(PhantomProjectile*);
static void (*const PTR_ARRAY_0836d438[2])(PhantomProjectile*);
static void (*const PTR_ARRAY_0836d440[3])(PhantomProjectile*);
static void (*const PTR_ARRAY_0836d44c[2])(PhantomProjectile*);

INCASM("asm/projectile/phantom_a.inc");

bool8 FUN_080afdf0(struct Entity* e, struct Coord* a, struct Coord* b, struct Coord* c);

void FUN_080af5cc(PhantomProjectile* p) {
  if (FUN_080afdf0(p->unk_28, &p->coord, &p->d, &p->unk_coord)) {
    p->mode[2] = 2;
  }
}

bool8 FUN_080afe38(struct Entity* e, struct Coord* a, struct Coord* b, struct Coord* c);

void FUN_080af5f4(PhantomProjectile* p) {
  if (FUN_080afe38(p->unk_28, &p->coord, &p->d, &p->unk_coord)) {
    p->mode[2] = 1;
  }
}

static void FUN_080af61c(PhantomProjectile* p) { (PTR_ARRAY_0836d430[p->mode[1]])((void*)p); }

void FUN_080af65c(PhantomProjectile* p);

void FUN_080af634(PhantomProjectile* p) {
  SetSpriteAnimation(p, MOTION(0x86, 5));
  p->angle = p->work[2] + 0x20;
  p->mode[1] = 1;
  FUN_080af65c(p);
}

INCASM("asm/projectile/phantom_b.inc");

static void FUN_080af70c(PhantomProjectile* p) {
  *(u32*)((u8*)p + 0x8c) = 0;
  *(u32*)((u8*)p + 0x90) = 0;
  *(u8*)((u8*)p + 0x94) = 0;
  p->flags &= ~COLLIDABLE;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0;
  PhantomProjectile_Update(p);
}

void FUN_080af748(PhantomProjectile* p) { (PTR_ARRAY_0836d438[p->mode[1]])(p); }

INCASM("asm/projectile/phantom_c.inc");

void FUN_080af8b0(PhantomProjectile* p) { (PTR_ARRAY_0836d440[p->mode[1]])(p); }

void FUN_080af8e8(PhantomProjectile* p);

void FUN_080af8c8(PhantomProjectile* p) {
  SetSpriteAnimation(p, MOTION(0x86, 5));
  p->mode[1] = 1;
  FUN_080af8e8(p);
}

INCASM("asm/projectile/phantom_d.inc");

void nop_080af9ac(PhantomProjectile* p) {}

void FUN_080af9b0(PhantomProjectile* p) { (PTR_ARRAY_0836d44c[p->mode[1]])(p); }

void FUN_080af9f4(PhantomProjectile* p);

void FUN_080af9c8(PhantomProjectile* p) {
  SetSpriteAnimation(p, MOTION(0x86, 2));
  p->angle = p->work[2] + 0x20;
  p->mode[1] = 1;
  p->work[3] = 0;
  FUN_080af9f4(p);
}

INCASM("asm/projectile/phantom_e.inc");

void FUN_080af518(PhantomProjectile* p);
void FUN_080af5cc(PhantomProjectile* p);
void FUN_080af5f4(PhantomProjectile* p);

static const ProjectileFunc PTR_ARRAY_0836d424[3] = {
    (void*)FUN_080af518,
    (void*)FUN_080af5cc,
    (void*)FUN_080af5f4,
};

void FUN_080af634(PhantomProjectile* p);
void FUN_080af65c(PhantomProjectile* p);

static void (*const PTR_ARRAY_0836d430[2])(PhantomProjectile*) = {
    (void*)FUN_080af634,
    (void*)FUN_080af65c,
};

void FUN_080af760(PhantomProjectile* p);
void FUN_080af7b0(PhantomProjectile* p);

static void (*const PTR_ARRAY_0836d438[2])(PhantomProjectile*) = {
    FUN_080af760,
    FUN_080af7b0,
};

void FUN_080af8c8(PhantomProjectile* p);
void FUN_080af8e8(PhantomProjectile* p);
void nop_080af9ac(PhantomProjectile* p);

static void (*const PTR_ARRAY_0836d440[3])(PhantomProjectile*) = {
    FUN_080af8c8,
    FUN_080af8e8,
    nop_080af9ac,
};

void FUN_080af9c8(PhantomProjectile* p);
void FUN_080af9f4(PhantomProjectile* p);

static void (*const PTR_ARRAY_0836d44c[2])(PhantomProjectile*) = {
    FUN_080af9c8,
    FUN_080af9f4,
};
