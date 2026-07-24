#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "vfx.h"

// オメガ第一形態に関係
typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  u8 unk_b4[4];  // 0xB4
  u32 unk_b8;    // 0xB8
  u32 unk_bc;    // 0xBC
  u8 pad_c0[4];  // 0xC0
} Projectile34;
static_assert(sizeof(Projectile34) == sizeof(Projectile));

static const struct Collision sCollisions[5];

void Projectile34_Init(Projectile34* p);
void Projectile34_Update(Projectile34* p);
void Projectile34_Die(Projectile34* p);

// clang-format off
const ProjectileRoutine gProjectile34Routine = {
    [ENTITY_INIT] =      (void*)Projectile34_Init,
    [ENTITY_UPDATE] =    (void*)Projectile34_Update,
    [ENTITY_DIE] =       (void*)Projectile34_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* FUN_080ac818(Coords32* c, s32 val1, s32 val2, struct Entity* e) {
  Projectile34* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 34);
    p->coord = *c;
    p->work[0] = 0, p->work[1] = 0;
    p->unk_b8 = val1, p->unk_bc = val2;
    p->unk_28 = (void*)e;
  }
  return (void*)p;
}

INCASM("asm/projectile/unk_34_a.inc");

void FUN_080acb54(Projectile34* p) {
  if ((p->unk_28)->mode[0] >= ENTITY_DIE) {
    CreateSmoke(3, &p->coord);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    return;
  }
  switch (p->mode[2]) {
    case 0: {
      if (p->work[0] == 0) {
        SetSpriteAnimation(p, MOTION(SM010_OMEGA_RING, 0));
      } else {
        SetSpriteAnimation(p, MOTION(SM010_OMEGA_RING, 3));
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      FALLTHROUGH;
    }
    default: {
      if (p->unk_bc == 0 || (--p->unk_bc) == 0) {
        p->work[2] = 127;
        p->mode[1] = 1, p->mode[2] = 0;
      }
      break;
    }
  }
}

void FUN_080acbe0(Projectile34* p) {
  if ((p->unk_28)->mode[0] > 1) {
    CreateSmoke(3, &p->coord);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  } else if (--p->work[2] == 0) {
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  } else {
    s32 m = p->mode[2];
    switch (m) {
      case 0:
        if (p->work[0] == 0) {
          SetSpriteAnimation(p, MOTION(SM010_OMEGA_RING, 1));
          SetDDP(&p->body, &sCollisions[1]);
          (p->d).y = p->unk_b8;
          (p->d).x = m;
        } else {
          SetSpriteAnimation(p, MOTION(SM010_OMEGA_RING, 4));
          SetDDP(&p->body, &sCollisions[2]);
          (p->d).x = -p->unk_b8;
          (p->d).y = m;
        }
        p->work[3] = RANDOM(RNG_0202f388) & 1;
        p->mode[2]++;
        FALLTHROUGH;
      case 1:
        UpdateSpriteAnimation(p);
        if (IsSpriteAnimEnd(p)) {
          p->flags |= DISPLAY;
          p->mode[2]++;
        }
        break;
      case 2:
        (p->coord).x += (p->d).x;
        (p->coord).y += (p->d).y;
        UpdateSpriteAnimation(p);
        break;
    }
  }
}

INCASM("asm/projectile/unk_34_b.inc");

// --------------------------------------------

void FUN_080acb54(Projectile34* p);
void FUN_080acbe0(Projectile34* p);
void FUN_080accf0(Projectile34* p);
void FUN_080acea0(Projectile34* p);

static void (*const sUpdates[4])(Projectile34*) = {
    FUN_080acb54,
    FUN_080acbe0,
    FUN_080accf0,
    FUN_080acea0,
};

// --------------------------------------------

static const struct Collision sCollisions[5] = {
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
      damage : 5,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(48), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(48)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      nature : 0x80,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(2), PIXEL(26), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(2), PIXEL(26), PIXEL(20)},
    },
};

static const s32 s32_ARRAY_0836c7a0[32] = {
    0x00000180, -0x00000340, -0x00000220, -0x00000260, -0x00000220, -0x00000300, 0x000002C0, -0x00000260, -0x00000180, -0x00000340, -0x00000200, -0x00000280, 0x00000160, -0x000001F0, 0x00000260, -0x00000280, 0x00000200, -0x00000440, 0x00000120, -0x000002A0, 0x00000120, -0x00000340, -0x000000B0, -0x000002A0, -0x00000200, -0x00000440, 0x00000120, -0x000002A0, 0x00000120, -0x00000340, -0x000000B0, -0x000002A0,
};

static const s32* const PTR_ARRAY_0836c820[4] = {
    &s32_ARRAY_0836c7a0[0],
    &s32_ARRAY_0836c7a0[8],
    &s32_ARRAY_0836c7a0[16],
    &s32_ARRAY_0836c7a0[24],
};
