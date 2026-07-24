#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "vfx.h"

// オメガ第一形態に関係 (same layout as omega1w_laser.c's Projectile4)
typedef struct {
  COLLISION_OBJECT_HDR;
  u8 idx_b4;     // 0xB4
  s32 unk_b8;    // 0xB8
  s32 timer_bc;  // 0xBC
  u32 unk_c0;    // 0xC0
} Projectile33;
static_assert(sizeof(Projectile33) == sizeof(Projectile));

INCASM("asm/projectile/omega1g_33_a.inc");

void doGoldOmega1Laser1(Projectile33* p) {
  if ((p->unk_28)->mode[0] > 1) {
    CreateSmoke(3, &p->coord);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  } else {
    switch (p->mode[2]) {
      case 0:
        SetSpriteAnimation(p, MOTION(SM010_OMEGA_RING, 6));
        p->mode[2]++;
        FALLTHROUGH;
      case 1:
        (p->coord).x = (p->unk_28)->coord.x;
        (p->coord).y = (p->unk_28)->coord.y - 0x6600;
        UpdateSpriteAnimation(p);
        break;
    }
    if (p->timer_bc == 0 || (--p->timer_bc) == 0) {
      p->mode[1] = 1, p->mode[2] = 0;
    }
  }
}

INCASM("asm/projectile/omega1g_33_b.inc");

void OmegaGoldProjectile_Init(Projectile* p);
void OmegaGoldProjectile_Update(Projectile* p);
void OmegaGoldProjectile_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gOmegaGoldProjectileRoutine = {
    [ENTITY_INIT] =      (void*)OmegaGoldProjectile_Init,
    [ENTITY_UPDATE] =    (void*)OmegaGoldProjectile_Update,
    [ENTITY_DIE] =       (void*)OmegaGoldProjectile_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void doGoldOmega1Laser1(Projectile33* p);
void doGoldOmega1Laser2(Projectile* p);
void FUN_080ac700(Projectile* p);

static const ProjectileFunc sUpdates[3] = {
    (ProjectileFunc)doGoldOmega1Laser1,
    doGoldOmega1Laser2,
    FUN_080ac700,
};

// --------------------------------------------

static const struct Collision sCollisions[4] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 1,
      range : {PIXEL(0), PIXEL(2), PIXEL(26), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(2), PIXEL(26), PIXEL(20)},
    },
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
      damage : 4,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
};

static const s32 s32_ARRAY_0836c674[32] = {
    0x00000180, -0x00000300, -0x00000220, -0x00000260, -0x00000220, -0x00000300, 0x000002C0, -0x00000260, -0x00000180, -0x00000300, -0x00000200, -0x00000280, 0x00000160, -0x000001F0, 0x00000260, -0x00000280, 0x00000200, -0x00000400, 0x00000120, -0x000002A0, 0x00000120, -0x00000340, -0x000000B0, -0x000002A0, -0x00000200, -0x00000400, 0x00000120, -0x000002A0, 0x00000120, -0x00000340, -0x000000B0, -0x000002A0,
};

static const s32* const PTR_ARRAY_0836c6f4[4] = {
    &s32_ARRAY_0836c674[0],
    &s32_ARRAY_0836c674[8],
    &s32_ARRAY_0836c674[16],
    &s32_ARRAY_0836c674[24],
};
