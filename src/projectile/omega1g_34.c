#include "collision.h"
#include "global.h"
#include "projectile.h"

// オメガ第一形態に関係
typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  u8 unk_b4[4];  // 0xB4
  u32 unk_b8;    // 0xB8
  u32 unk_bc;    // 0xBC
  u8 pad_c0[4];  // 0xC0
} Projectile34;
static_assert(sizeof(Projectile34) == sizeof(struct Projectile));

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

INCASM("asm/projectile/unk_34.inc");

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
