#include "collision.h"
#include "global.h"
#include "physics.h"
#include "projectile.h"
#include "story.h"
#include "vfx.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 buffer[16];         // 0xB4
} ClavekerYellowBalls;
static_assert(sizeof(ClavekerYellowBalls) == sizeof(Projectile));

static const struct Collision sCollisions[2];

static void ClavekerYellowBalls_Init(ClavekerYellowBalls* p);
static void ClavekerYellowBalls_Update(ClavekerYellowBalls* p);
static void ClavekerYellowBalls_Die(ClavekerYellowBalls* p);

// clang-format off
const ProjectileRoutine gClavekerYellowBallsRoutine = {
    [ENTITY_INIT] =      (void*)ClavekerYellowBalls_Init,
    [ENTITY_UPDATE] =    (void*)ClavekerYellowBalls_Update,
    [ENTITY_DIE] =       (void*)ClavekerYellowBalls_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

ClavekerYellowBalls* FUN_080aed8c(Entity* q, Coords32* c1, Coords32* c2, u8 n) {
  ClavekerYellowBalls* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 39);
    p->work[0] = n, p->work[1] = 0;
    (p->coord).x = c1->x, (p->coord).y = c1->y;
    (p->unk_coord).x = c2->x, (p->unk_coord).y = c2->y;
    p->unk_28 = q;
  }
  return p;
}

static void ClavekerYellowBalls_Init(ClavekerYellowBalls* p) {
  if (p->work[1] == 0) {
    EnableSpriteAnimation_Normal(p);
    p->flags |= DISPLAY;
    p->flags |= FLIPABLE;
    INIT_BODY(p, &sCollisions[0], 2, NULL);
    SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  }
  p->work[2] = 0xFF;
  ClavekerYellowBalls_Update(p);
}

static void FUN_080aeefc(ClavekerYellowBalls* p);

static void ClavekerYellowBalls_Update(ClavekerYellowBalls* p) {
  static void (*const sUpdates[1])(ClavekerYellowBalls*) = {
      FUN_080aeefc,
  };

  if (IS_METTAUR) {
    p->flags &= ~DISPLAY;
    EXIT_BODY(p);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    ClavekerYellowBalls_Die(p);
    return;
  }
  (sUpdates[p->mode[1]])(p);
}

static void ClavekerYellowBalls_Die(ClavekerYellowBalls* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

static void FUN_080aeefc(ClavekerYellowBalls* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    EXIT_BODY(p);
    CreateSmoke(2, &p->coord);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    if ((p->unk_28)->mode[0] <= 1) {
      (*(u8*)((u8*)p->unk_28 + 0xb9))++;
    }
    if (*(u8*)((u8*)p->unk_28 + 0xb9) > 7) {
      CreateSmoke(1, &p->coord);
      TryDropItem(6, &p->coord);
    }
  } else if ((p->body).status & BODY_STATUS_B2) {
    EXIT_BODY(p);
    CreateSmoke(2, &p->coord);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  } else if (--p->work[2] == 0) {
    CreateSmoke(3, &p->coord);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  } else {
    switch (p->mode[2]) {
      case 0: {
        SetSpriteAnimation(p, MOTION(SM117_CLAVEKER, 10));
        (p->d).y = 0;
        (p->d).x = (RANDOM(RNG_0202f388) % 0x1E0) - 0xF0;
        p->work[2] = 120;
        p->mode[2]++;
        FALLTHROUGH;
      }
      case 1: {
        (p->d).y += PIXEL(1) / 4;
        if ((p->d).y > PIXEL(7)) (p->d).y = PIXEL(7);
        (p->coord).x += (p->d).x;
        (p->coord).y += (p->d).y;
        {
          s32 push = PushoutToUp1((p->coord).x, (p->coord).y);
          if (push != 0 && push >= -PIXEL(7)) {
            s32 pushH;
            if ((p->d).x > 0) {
              pushH = PushoutToLeft1((p->coord).x, (p->coord).y);
            } else {
              pushH = PushoutToRight1((p->coord).x, (p->coord).y);
            }
            if (pushH == 0) {
              (p->d).y = -((p->d).y >> 1);
            } else if (pushH == -1) {
              (p->d).y = -((p->d).y >> 1);
            } else if (abs(pushH) > PIXEL(1) && abs(pushH) <= PIXEL(7) && abs(pushH) <= abs(push)) {
              (p->d).x = -(p->d).x;
            } else {
              (p->d).y = -((p->d).y >> 1);
            }
            p->mode[2]++;
          }
        }
        UpdateSpriteAnimation(p);
        break;
      }
      case 2: {
        (p->d).y += PIXEL(1) / 4;
        if ((p->d).y > PIXEL(7)) (p->d).y = PIXEL(7);
        (p->coord).x += (p->d).x;
        (p->coord).y += (p->d).y;
        UpdateSpriteAnimation(p);
        break;
      }
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
