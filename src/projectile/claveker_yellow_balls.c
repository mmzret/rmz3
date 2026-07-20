#include "collision.h"
#include "global.h"
#include "vfx.h"
#include "physics.h"
#include "projectile.h"
#include "story.h"

static const struct Collision sCollisions[2];

static void ClavekerYellowBalls_Init(struct Projectile* p);
static void ClavekerYellowBalls_Update(struct Projectile* p);
static void ClavekerYellowBalls_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gClavekerYellowBallsRoutine = {
    [ENTITY_INIT] =      ClavekerYellowBalls_Init,
    [ENTITY_UPDATE] =    ClavekerYellowBalls_Update,
    [ENTITY_DIE] =       ClavekerYellowBalls_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

struct Projectile* FUN_080aed8c(struct Entity* boss, Coords32* c1, Coords32* c2, u8 n) {
  struct Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 39);
    (p->s).work[0] = n;
    (p->s).work[1] = 0;
    (p->s).coord.x = c1->x;
    (p->s).coord.y = c1->y;
    (p->s).unk_coord.x = c2->x;
    (p->s).unk_coord.y = c2->y;
    (p->s).unk_28 = boss;
  }
  return p;
}

static void ClavekerYellowBalls_Init(struct Projectile* p) {
  if ((p->s).work[1] == 0) {
    EnableSpriteAnimation_Normal(p);
    (p->s).flags |= DISPLAY;
    (p->s).flags |= FLIPABLE;
    INIT_BODY(p, &sCollisions[0], 2, NULL);
    SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
    (p->s).mode[1] = 0;
    (p->s).mode[2] = 0;
    (p->s).mode[3] = 0;
  }
  (p->s).work[2] = 0xFF;
  ClavekerYellowBalls_Update(p);
}

static void FUN_080aeefc(struct Projectile* p);

static void ClavekerYellowBalls_Update(struct Projectile* p) {
  static const ProjectileFunc sUpdates[1] = {
      FUN_080aeefc,
  };

  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    EXIT_BODY(p);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    ClavekerYellowBalls_Die(p);
    return;
  }
  (sUpdates[(p->s).mode[1]])(p);
}

static void ClavekerYellowBalls_Die(struct Projectile* p) {
  (p->s).flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

static void FUN_080aeefc(struct Projectile* p) {
  if ((p->body).status & 0x200) {
    EXIT_BODY(p);
    CreateSmoke(2, &(p->s).coord);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    if (((p->s).unk_28)->mode[0] <= 1) {
      (*(u8*)((u8*)(p->s).unk_28 + 0xb9))++;
    }
    if (*(u8*)((u8*)(p->s).unk_28 + 0xb9) > 7) {
      CreateSmoke(1, &(p->s).coord);
      TryDropItem(6, &(p->s).coord);
    }
  } else if ((p->body).status & BODY_STATUS_B2) {
    EXIT_BODY(p);
    CreateSmoke(2, &(p->s).coord);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  } else if (--(p->s).work[2] == 0) {
    CreateSmoke(3, &(p->s).coord);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  } else {
    switch ((p->s).mode[2]) {
      case 0:
        SetSpriteAnimation(&p->s, MOTION(0x75, 0xa));
        (p->s).d.y = 0;
        RNG_0202f388 = LCG(RNG_0202f388);
        (p->s).d.x = ((RNG_0202f388 >> 16) % 0x1e0) - 0xf0;
        (p->s).work[2] = 0x78;
        (p->s).mode[2]++;
        // fallthrough
      case 1:
        (p->s).d.y += 0x40;
        if ((p->s).d.y > 0x700) {
          (p->s).d.y = 0x700;
        }
        (p->s).coord.x += (p->s).d.x;
        (p->s).coord.y += (p->s).d.y;
        {
          s32 push = PushoutToUp1((p->s).coord.x, (p->s).coord.y);
          if (push != 0 && push >= -0x700) {
            s32 pushH;
            if ((p->s).d.x > 0) {
              pushH = PushoutToLeft1((p->s).coord.x, (p->s).coord.y);
            } else {
              pushH = PushoutToRight1((p->s).coord.x, (p->s).coord.y);
            }
            if (pushH == 0) {
              (p->s).d.y = -((p->s).d.y >> 1);
            } else if (pushH == -1) {
              (p->s).d.y = -((p->s).d.y >> 1);
            } else if (abs(pushH) > 0x100 && abs(pushH) <= 0x700 && abs(pushH) <= abs(push)) {
              (p->s).d.x = -(p->s).d.x;
            } else {
              (p->s).d.y = -((p->s).d.y >> 1);
            }
            (p->s).mode[2]++;
          }
        }
        UpdateSpriteAnimation(p);
        break;
      case 2:
        (p->s).d.y += 0x40;
        if ((p->s).d.y > 0x700) {
          (p->s).d.y = 0x700;
        }
        (p->s).coord.x += (p->s).d.x;
        (p->s).coord.y += (p->s).d.y;
        UpdateSpriteAnimation(p);
        break;
    }
  }
}

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      atkType : 0x00,
      nature : BODY_NATURE_B7,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
};
