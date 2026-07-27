#include "collision.h"
#include "global.h"
#include "projectile.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4[16];         // 0xB4
} OmegaZXProjectile;
static_assert(sizeof(OmegaZXProjectile) == sizeof(Projectile));

void OmegaZXProjectile_Init(OmegaZXProjectile* p);
void OmegaZXProjectile_Update(OmegaZXProjectile* p);
void OmegaZXProjectile_Die(OmegaZXProjectile* p);

// clang-format off
const ProjectileRoutine gOmegaZXProjectileRoutine = {
    [ENTITY_INIT] =      (void*)OmegaZXProjectile_Init,
    [ENTITY_UPDATE] =    (void*)OmegaZXProjectile_Update,
    [ENTITY_DIE] =       (void*)OmegaZXProjectile_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};

static void (*const sUpdates[9])(OmegaZXProjectile*);
// clang-format on

Projectile* FUN_080afe84(Entity* parent, Coords32* c, u8 n) {
  Projectile* p = (Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 41);
    p->work[0] = 0, p->work[1] = n;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = parent;
  }
  return p;
}

Projectile* FUN_080afedc(Entity* parent, Coords32* c, u8 n) {
  Projectile* p = (Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 41);
    p->work[0] = n;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = parent;
  }
  return p;
}

Projectile* FUN_080aff34(Entity* parent, Coords32* c) {
  Projectile* p = (Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 41);
    p->work[0] = 4;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = parent;
  }
  return p;
}

Projectile* FUN_080aff88(Entity* parent, Coords32* c, u8 n) {
  Projectile* p = (Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 41);
    p->work[0] = 5, p->work[1] = n;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = parent;
  }
  return p;
}

OmegaZXProjectile* FUN_080affe4(struct Entity* parent, struct Coord* c, u16 a2, u8 a3) {
  OmegaZXProjectile* p = (OmegaZXProjectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 41);
    p->work[0] = 6;
    p->work[1] = a3;
    *(u16*)((u8*)p + 0xbc) = a2;
    p->coord.x = c->x;
    p->coord.y = c->y;
    p->unk_28 = parent;
  }
  return p;
}

OmegaZXProjectile* FUN_080b0048(struct Entity* parent, struct Coord* c) {
  OmegaZXProjectile* p = (OmegaZXProjectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 41);
    p->work[0] = 7;
    p->coord.x = c->x;
    p->coord.y = c->y;
    p->unk_28 = parent;
  }
  return p;
}

OmegaZXProjectile* FUN_080b009c(struct Entity* parent) {
  OmegaZXProjectile* p = (OmegaZXProjectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 41);
    p->work[0] = 8;
    p->unk_28 = parent;
  }
  return p;
}

void OmegaZXProjectile_Init(OmegaZXProjectile* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = p->work[0];
  p->mode[2] = 0;
  p->mode[3] = 0;
  p->work[2] = 0xFF;
  OmegaZXProjectile_Update(p);
}

void OmegaZXProjectile_Update(OmegaZXProjectile* p) {
  (sUpdates[p->mode[1]])((void*)p);
}

void OmegaZXProjectile_Die(OmegaZXProjectile* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/omega_zx_a.inc");

void FUN_080b0168(OmegaZXProjectile* p);
void FUN_080b0214(OmegaZXProjectile* p);
void FUN_080b02dc(OmegaZXProjectile* p);
void omega2_080b0370(OmegaZXProjectile* p);
void omega2_080b07c8(OmegaZXProjectile* p);
void FUN_080b0bb0(OmegaZXProjectile* p);
void omega2_080b0ca8(OmegaZXProjectile* p);
void FUN_080b10b8(OmegaZXProjectile* p);
void FUN_080b116c(OmegaZXProjectile* p);

// clang-format off
static void (*const sUpdates[9])(OmegaZXProjectile*) = {
    FUN_080b0168,
    FUN_080b0214,
    FUN_080b02dc,
    omega2_080b0370,
    omega2_080b07c8,
    FUN_080b0bb0,
    omega2_080b0ca8,
    FUN_080b10b8,
    FUN_080b116c,
};
// clang-format on

static const struct Collision sCollisions[26] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(30)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(10)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(6)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(4)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(2)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(1)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      nature : BODY_NATURE_B7,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(34), PIXEL(34)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 255,
      unk_0a : 0x21,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(30), PIXEL(30)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 255,
      unk_0a : 0x21,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(48), PIXEL(48)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      unk_0a : 0x21,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(48), PIXEL(48)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(35), -PIXEL(86), PIXEL(40), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      nature : BODY_NATURE_B7,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      nature : BODY_NATURE_B7,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 5,
      nature : BODY_NATURE_B7,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(50), PIXEL(27)},
    },
};
