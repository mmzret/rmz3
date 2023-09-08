#include "collision.h"
#include "global.h"
#include "projectile.h"

INCASM("asm/projectile/projectile.inc");

void Projectile7_Init(struct Projectile* p);
void Projectile7_Update(struct Projectile* p);
void Projectile7_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile7Routine = {
    [ENTITY_INIT] =      Projectile7_Init,
    [ENTITY_MAIN] =      Projectile7_Update,
    [ENTITY_DIE] =       Projectile7_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

static const struct Collision sCollision[2] = {
    {
      kind : DDP,
      layer : 2,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0000, 0x2000, 0x2000},
    },
    {
      kind : DRP,
      layer : 2,
      special : 0,
      damage : 3,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x2000, 0x2000},
    },
};
