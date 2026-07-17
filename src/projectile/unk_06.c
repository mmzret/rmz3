#include "projectile/unk_06.h"

#include "collision.h"
#include "global.h"
#include "motion.h"
#include "projectile.h"
#include "story.h"

// ランプロートの炎

static const ProjectileFunc sUpdates[4];
static const struct Collision sCollisions[6];

static void Projectile6_Init(Projectile* p);
static void Projectile6_Update(Projectile* p);
static void Projectile6_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile6Routine = {
    [ENTITY_INIT] =      (void*)Projectile6_Init,
    [ENTITY_UPDATE] =    (void*)Projectile6_Update,
    [ENTITY_DIE] =       (void*)Projectile6_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

Entity* CreateProjectile6(Entity* e, Coords32* c, u8 r2, u8 r3) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 6);
    p->work[0] = r2, p->work[1] = r3;
    p->d = *c;
    p->unk_28 = e;
  }
  return p;
}

// --------------------------------------------

static void Projectile6_Init(Projectile* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  INIT_BODY(p, &sCollisions[0], 1, NULL);
  p->coord.x = ((p->unk_28)->coord).x;
  p->coord.y = ((p->unk_28)->coord).y;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 1, p->mode[2] = 0, p->mode[3] = 0;
  Projectile6_Update(p);
}

void FUN_0809dd60(Projectile* p);
void FUN_0809de04(Projectile* p);
void FUN_0809df14(Projectile* p);
static void FUN_0809dfb8(Projectile* p);

// ランプロート本体が死んでる or メットールなら、こいつも消える, そうでないなら、通常の更新(本体と左右を揃える)
static void Projectile6_Update(Projectile* p) {
  // 0x0836abe8
  static const ProjectileFunc sUpdates[4] = {
      (void*)FUN_0809dd60,
      (void*)FUN_0809de04,
      (void*)FUN_0809df14,
      (void*)FUN_0809dfb8,
  };

  Entity* l = p->unk_28;
  if (l->mode[0] < ENTITY_DIE) {
    if (IS_METTAUR) {
      p->flags &= ~DISPLAY;
      EXIT_BODY(p);
    } else {
      goto _UPDATE;
    }
  }

  SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  Projectile6_Die(p);
  return;

_UPDATE:
  SET_XFLIP(p, (l->flags & X_FLIP) != 0);
  (sUpdates[p->mode[1]])(p);
}

static void Projectile6_Die(Projectile* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

void FUN_0809dd60(struct Projectile* p) {
  struct Entity* l = (p->s).unk_28;
  if (l->mode[0] >= ENTITY_DIE) {
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    Projectile6_Die(p);
    return;
  }

  SET_XFLIP(p, (l->flags >> 4) & 1);
  if ((*(u32*)p->buffer) & 1) {
    *(u32*)p->buffer = 0;
    (p->s).mode[1] = 1;
    (p->s).mode[2] = 0;
    return;
  }

  if ((p->s).mode[2] == 0) {
    (p->s).flags &= ~DISPLAY;
    SetDDP(&p->body, &sCollisions[0]);
    (p->s).mode[2]++;
  }
}

void FUN_0809de04(struct Projectile* p) {
  struct Entity* l = (p->s).unk_28;
  if (l->mode[0] >= ENTITY_DIE) {
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    Projectile6_Die(p);
    return;
  }

  SET_XFLIP(p, (l->flags >> 4) & 1);
  if ((*(u32*)p->buffer) & 2) {
    *(u32*)p->buffer = 0;
    (p->s).mode[1] = 0;
    (p->s).mode[2] = 0;
    return;
  }

  switch ((p->s).mode[2]) {
    case 0:
      (p->s).flags |= DISPLAY;
      SetSpriteAnimation(p, MOTION(SM025_LAMPLORT, 5));
      SetDDP(&p->body, &sCollisions[1]);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
      if ((p->s).motion.cmdIdx == 1) {
        SetDDP(&p->body, &sCollisions[2]);
        (p->s).mode[2]++;
      }
      if (IsSpriteAnimEnd(p)) {
        (p->s).mode[1] = 2;
        (p->s).mode[2] = 0;
      }
      break;
    case 2:
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) {
        (p->s).mode[1] = 2;
        (p->s).mode[2] = 0;
      }
      break;
  }
}

void FUN_0809df14(struct Projectile* p) {
  struct Entity* l = (p->s).unk_28;
  if (l->mode[0] >= ENTITY_DIE) {
    *(u32*)p->buffer = 0;
    (p->s).mode[1] = 3;
    (p->s).mode[2] = 0;
    return;
  }

  SET_XFLIP(p, (l->flags >> 4) & 1);
  if ((*(u32*)p->buffer) & 2) {
    *(u32*)p->buffer = 0;
    (p->s).mode[1] = 3;
    (p->s).mode[2] = 0;
    return;
  }

  switch ((p->s).mode[2]) {
    case 0:
      SetSpriteAnimation(p, MOTION(SM025_LAMPLORT, 7));
      SetDDP(&p->body, &sCollisions[3]);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
      break;
  }
}

static void FUN_0809dfb8(Projectile* p) {
  Entity* l = p->unk_28;
  if (l->mode[0] >= ENTITY_DIE) {
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    Projectile6_Die(p);
    return;
  }

  SET_XFLIP(p, (l->flags & X_FLIP) != 0);
  switch (p->mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(SM025_LAMPLORT, 9));
      SetDDP(&p->body, &sCollisions[5]);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) p->mode[1] = 0, p->mode[2] = 0;
      break;
    }
  }
}

// --------------------------------------------

// 0x0836ABF8
static const struct Collision sCollisions[6] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0000, 0x0200, 0x0200},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      atkType : 0x00,
      element : ELEMENT_FLAME,
      nature : BODY_NATURE_B7,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000004,
      range : {0x2300, -0x0E00, 0x1D00, 0x0A00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      atkType : 0x00,
      element : ELEMENT_FLAME,
      nature : BODY_NATURE_B7,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000004,
      range : {0x3000, -0x0F00, 0x2D00, 0x0A00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      atkType : 0x00,
      element : ELEMENT_FLAME,
      nature : BODY_NATURE_B7,
      comboLv : 0x00,
      remaining : 1,
      layer : 0x00000004,
      range : {0x2C00, -0x0D00, 0x2D00, 0x0A00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      atkType : 0x00,
      element : ELEMENT_FLAME,
      nature : BODY_NATURE_B7,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000004,
      range : {0x4A00, -0x1200, 0x1100, 0x1300},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0000, 0x0200, 0x0200},
    },
};
