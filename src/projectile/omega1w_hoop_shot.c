#include "camera.h"
#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "stagerun.h"
#include "vfx.h"

// Omega (1st white) hoop shot?
typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  u8 unk_b4[4];  // 0xB4
  s32 unk_b8;    // 0xB8
  s32 lifetime;  // 0xBC
  u32 unk_c0;    // 0xC0
} Projectile5;
static_assert(sizeof(Projectile5) == sizeof(Projectile));

static const ProjectileFunc sUpdates[2];
static const struct Collision sCollisions[];

static void Projectile5_Init(Projectile5* p);
static void Projectile5_Update(struct Entity* p);
static void Projectile5_Die(Projectile5* p);

// clang-format off
const ProjectileRoutine gProjectile5Routine = {
    [ENTITY_INIT] =      (void*)Projectile5_Init,
    [ENTITY_UPDATE] =    (void*)Projectile5_Update,
    [ENTITY_DIE] =       (void*)Projectile5_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* FUN_0809d8a0(Coords32* c, s32 unk_b8, s32 lifetime, struct Entity* q) {
  Projectile5* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 5);
    p->coord = *c;
    p->work[0] = 0;
    p->unk_b8 = unk_b8, p->lifetime = lifetime;
    p->unk_28 = q;
  }
  return (void*)p;
}

struct Entity* FUN_0809d904(Coords32* c, s32 unk_b8, s32 lifetime, struct Entity* q) {
  Projectile5* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 5);
    p->coord = *c;
    p->work[0] = 1;
    p->unk_b8 = unk_b8, p->lifetime = lifetime;
    p->unk_28 = q;
  }
  return (void*)p;
}

// --------------------------------------------

static void Projectile5_Init(Projectile5* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  INIT_BODY(p, sCollisions, 1, NULL);
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  Projectile5_Update((void*)p);
}

static void FUN_0809da14(Projectile5* p);
static void FUN_0809daa0(Projectile5* p);

static void Projectile5_Update(struct Entity* p) {
  static const EntityFunc sUpdates[2] = {
      (void*)FUN_0809da14,
      (void*)FUN_0809daa0,
  };  // 0x0836ab84
  (sUpdates[(p->mode[1])])(p);
}

static void Projectile5_Die(Projectile5* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_0809da14(Projectile5* p) {
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
      if (p->lifetime == 0 || (--p->lifetime) == 0) {
        p->work[2] = 127;
        p->mode[1] = 1, p->mode[2] = 0;
      }
      break;
    }
  }
}

static void FUN_0809daa0(Projectile5* p) {
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
          (p->d).x = 0;
        } else {
          SetSpriteAnimation(p, MOTION(SM010_OMEGA_RING, 4));
          SetDDP(&p->body, &sCollisions[2]);
          (p->d).x = -p->unk_b8;
          (p->d).y = 0;
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

// 0x0836ab8c
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
