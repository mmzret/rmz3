#include "collision.h"
#include "global.h"
#include "projectile.h"

static const ProjectileFunc sUpdates[2];
static const struct Collision sCollisions[3];

void Projectile5_Init(struct Projectile* p);
void Projectile5_Update(struct Projectile* p);
void Projectile5_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile5Routine = {
    [ENTITY_INIT] =      Projectile5_Init,
    [ENTITY_MAIN] =      Projectile5_Update,
    [ENTITY_DIE] =       Projectile5_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

struct Projectile* FUN_0809d8a0(struct Coord* c, s32 prevX, s32 prevY, struct Entity* e) {
  struct Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 8;
    INIT_PROJECTILE_ROUTINE(p, 5);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).coord = *c;
    (p->s).work[0] = 0;
    (p->prevCoord).x = prevX;
    (p->prevCoord).y = prevY;
    (p->s).unk_28 = e;
  }
  return p;
}

INCASM("asm/projectile/unk_05.inc");

void FUN_0809da14(struct Projectile* p);
void FUN_0809daa0(struct Projectile* p);

static const ProjectileFunc sUpdates[2] = {
    FUN_0809da14,
    FUN_0809daa0,
};

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      layer : 1,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {0x0000, 0x0000, 0x1000, 0x1000},
    },
    {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0000, 0x3000, 0x1000},
    },
    {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0000, 0x1000, 0x3000},
    },
};
