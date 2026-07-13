#include "collision.h"
#include "global.h"
#include "projectile.h"

// コピーXの突進系の技(スライディング,ノヴァストライク)

// Entity.work[0]
#define SLIDING 0
#define NOVA_STRIKE 1

static void CopyXProjectile_Init(struct Entity* p);
static void CopyXProjectile_Update(struct Entity* p);
static void CopyXProjectile_Die(Object* p);

// clang-format off
const ProjectileRoutine gCopyXTackleProjectileRoutine = {
    [ENTITY_INIT] =      (void*)CopyXProjectile_Init,
    [ENTITY_UPDATE] =    (void*)CopyXProjectile_Update,
    [ENTITY_DIE] =       (void*)CopyXProjectile_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// 0x080A8118
void CreateCopyXSonicBoom(struct Entity* q, u8 kind, u8 unused) {
  struct Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 24);
    p->work[0] = kind, p->work[1] = unused;
    p->unk_28 = q;
    p->coord = q->coord;
  }
}

// --------------------------------------------

static void initCopyXSlidingSonicBoom(Object* p);
static void InitNovaStrikeProjectile(Object* p);

static void CopyXProjectile_Init(struct Entity* p) {
  static const EntityFunc sInitializers[] = {
      [SLIDING] = (void*)initCopyXSlidingSonicBoom,
      [NOVA_STRIKE] = (void*)InitNovaStrikeProjectile,
  };
  (sInitializers[p->work[0]])(p);
}

static void moveSlidingSonicBoom(struct Entity* p);
static void UpdateNovaStrikeProjectile(struct Entity* p);

static void CopyXProjectile_Update(struct Entity* p) {
  static const EntityFunc sUpdates[] = {
      [SLIDING] = moveSlidingSonicBoom,
      [NOVA_STRIKE] = UpdateNovaStrikeProjectile,
  };
  (sUpdates[p->work[0]])(p);
}

static void CopyXProjectile_Die(Object* p) {
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void initCopyXSlidingSonicBoom(Object* p) {
  static const struct Collision sCollisions1[2] = {
      {
        kind : DDP,
        faction : FACTION_ENEMY,
        damage : 4,
        nature : 0x04,
        remaining : 0,
        layer : 0x00000001,
        range : {PIXEL(8), -PIXEL(8), PIXEL(24), PIXEL(16)},
      },
      {
        kind : DRP,
        faction : FACTION_ENEMY,
        damage : 4,
        LAYER(0xFFFFFFFF),
        hitzone : 0,
        remaining : 0,
        range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
      },
  };

  struct Entity* q = (p->s).unk_28;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM094_COPYX_SLIDING_SPARK, 0));
  UpdateSpriteAnimation(p);
  SET_XFLIP(p, (q->flags & X_FLIP) != 0);
  INIT_BODY(p, sCollisions1, 64, NULL);
  (p->s).work[2] = 40;
  (p->s).mode[2] = 1;
  CopyXProjectile_Update((void*)p);
}

static void moveSlidingSonicBoom(struct Entity* p) {
  struct Entity* q = p->unk_28;
  UpdateSpriteAnimation(p);
  (p->coord).x = (p->flags & X_FLIP) ? ((q->coord).x + PIXEL(28)) : ((q->coord).x - PIXEL(28));
  if (((--p->work[2]) == 0xFF) || (q->mode[1] < 6) || (q->mode[1] > 8)) {
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  }
}

// 0x080a82dc
static void InitNovaStrikeProjectile(Object* p) {
  static const struct Collision sCollisions2[2] = {
      {
        kind : DDP,
        faction : FACTION_ENEMY,
        damage : 4,
        nature : 0x04,
        remaining : 0,
        layer : 0x00000001,
        range : {PIXEL(12), PIXEL(0), PIXEL(24), PIXEL(32)},
      },
      {
        kind : DRP,
        faction : FACTION_ENEMY,
        damage : 4,
        LAYER(0xFFFFFFFF),
        hitzone : 0,
        remaining : 0,
        range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
      },
  };

  struct Entity* q = (p->s).unk_28;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM094_COPYX_SLIDING_SPARK, 1));
  UpdateSpriteAnimation(p);
  SET_XFLIP(p, (q->flags & X_FLIP) != 0);
  INIT_BODY(p, sCollisions2, 64, NULL);
  (p->s).work[2] = 40;
  (p->s).mode[2] = 1;
  CopyXProjectile_Update((void*)p);
}

static void UpdateNovaStrikeProjectile(struct Entity* p) {
  struct Entity* q = p->unk_28;
  UpdateSpriteAnimation(p);
  (p->coord).x = (p->flags & X_FLIP) ? ((q->coord).x + PIXEL(24)) : ((q->coord).x - PIXEL(24));
  (p->coord).y = (q->coord).y - PIXEL(26);
  if (q->mode[1] != 15) {
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  }
}
