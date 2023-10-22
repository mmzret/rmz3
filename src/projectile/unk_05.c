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
    [ENTITY_UPDATE] =    Projectile5_Update,
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
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0000, 0x1000, 0x1000},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B7,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x3000, 0x1000},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B7,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1000, 0x3000},
    },
};
