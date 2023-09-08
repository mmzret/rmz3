#include "collision.h"
#include "global.h"
#include "projectile.h"

static const ProjectileFunc sUpdates[4];
static const struct Collision sCollisions[6];

static void Projectile6_Init(struct Projectile* p);
void Projectile6_Update(struct Projectile* p);
void Projectile6_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile6Routine = {
    [ENTITY_INIT] =      Projectile6_Init,
    [ENTITY_MAIN] =      Projectile6_Update,
    [ENTITY_DIE] =       Projectile6_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

struct Projectile* CreateProjectile6(struct Entity* e, struct Coord* c, u8 r2, u8 r3) {
  struct Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 8;
    INIT_PROJECTILE_ROUTINE(p, 6);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = r2;
    (p->s).work[1] = r3;
    (p->s).d = *c;
    (p->s).unk_28 = e;
  }
  return p;
}

static void Projectile6_Init(struct Projectile* p) {
  struct Body* body;

  InitNonAffineMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= COLLIDABLE;

  body = &p->body;
  InitBody(body, sCollisions, &(p->s).coord, 1);
  body->parent = (struct CollidableEntity*)p;
  body->fn = NULL;

  (p->s).coord.x = (((p->s).unk_28)->coord).x;
  (p->s).coord.y = (((p->s).unk_28)->coord).y;
  SET_PROJECTILE_ROUTINE(p, ENTITY_MAIN);
  (p->s).mode[1] = 1;
  (p->s).mode[2] = 0;
  (p->s).mode[3] = 0;
  Projectile6_Update(p);
}

INCASM("asm/projectile/unk_06.inc");

void FUN_0809dd60(struct Projectile* p);
void FUN_0809de04(struct Projectile* p);
void FUN_0809df14(struct Projectile* p);
void FUN_0809dfb8(struct Projectile* p);

static const ProjectileFunc sUpdates[4] = {
    FUN_0809dd60,
    FUN_0809de04,
    FUN_0809df14,
    FUN_0809dfb8,
};

static const struct Collision sCollisions[6] = {
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
      range : {0x0000, 0x0000, 0x0200, 0x0200},
    },
    {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x02,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000004,
      range : {0x2300, -0x0E00, 0x1D00, 0x0A00},
    },
    {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x02,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000004,
      range : {0x3000, -0x0F00, 0x2D00, 0x0A00},
    },
    {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x02,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000004,
      range : {0x2C00, -0x0D00, 0x2D00, 0x0A00},
    },
    {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x02,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000004,
      range : {0x4A00, -0x1200, 0x1100, 0x1300},
    },
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
      range : {0x0000, 0x0000, 0x0200, 0x0200},
    },
};
