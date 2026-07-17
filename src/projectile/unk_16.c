#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "story.h"

static void Projectile16_Init(Object* p);
static void Projectile16_Update(Object* p);
static void Projectile16_Die(Object* p);

// clang-format off
const ProjectileRoutine gProjectile16Routine = {
    [ENTITY_INIT] =      (void*)Projectile16_Init,
    [ENTITY_UPDATE] =    (void*)Projectile16_Update,
    [ENTITY_DIE] =       (void*)Projectile16_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

Entity* FUN_080a244c(Coords32* c1, Coords32* c2, bool8 isDirRight) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 16);
    p->work[0] = isDirRight;
    (p->coord).x = c1->x, (p->coord).y = c1->y;
    (p->unk_coord).x = c2->x, (p->unk_coord).y = c2->y;
  }
  return p;
}

// --------------------------------------------

static const struct Collision sCollisions[];

static void Projectile16_Init(Object* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  INIT_BODY(p, &sCollisions[0], 2, NULL);
  if (p->work[0] == 0) {
    SET_XFLIP(p, FALSE);
  } else {
    SET_XFLIP(p, TRUE);
  }
  p->work[2] = 0xFF;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  Projectile16_Update((void*)p);
}

void FUN_080a25f8(Projectile* p);
void FUN_080a2710(Projectile* p);

static void Projectile16_Update(Object* p) {
  // 0x0836b350
  static const ProjectileFunc sUpdates[2] = {
      FUN_080a25f8,
      FUN_080a2710,
  };

  if (IS_METTAUR) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  (sUpdates[p->mode[1]])((void*)p);
}

static void Projectile16_Die(Object* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

void FUN_080a25f8(struct Projectile* p) {
  // `zero` is declared up here and assigned 0 only after the division below, so
  // agbcc materializes the work[3] zero straight after __divsi3 and holds it in a
  // register across the d.y/unk_coord.x stores (a case-scoped `= 0` const-folds
  // away and is rescheduled late). Permuter-found; see git history.
  s32 zero;
  if ((p->body).status & BODY_STATUS_DEAD) {
    EXIT_BODY(p);
    CreateSmoke(2, &(p->s).coord);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  } else if ((p->body).status & BODY_STATUS_B2) {
    EXIT_BODY(p);
    CreateSmoke(2, &(p->s).coord);
    PlaySound(0x35);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  } else if (--(p->s).work[2] == 0) {
    CreateSmoke(2, &(p->s).coord);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  } else {
    switch ((p->s).mode[2]) {
      case 0: {
        s32 targetX;
        SetSpriteAnimation(p, 0x3e03);
        if (!((p->s).flags & X_FLIP)) {
          targetX = (p->s).coord.x - 0x6000;
        } else {
          targetX = (p->s).coord.x + 0x6000;
        }
        (p->s).unk_coord.x = 0x1e;
        (p->s).d.x = (targetX - (p->s).coord.x) / 0x1e;
        zero = 0;
        (p->s).d.y = -0x3c0;
        (p->s).unk_coord.x = 0x1d;
        (p->s).work[3] = zero;
        (p->s).mode[2]++;
        FALLTHROUGH;
      }
      case 1:
        (p->s).d.y += 0x40;
        (p->s).coord.x += (p->s).d.x;
        (p->s).coord.y += (p->s).d.y;
        UpdateSpriteAnimation(p);
        if (FUN_080098a4((p->s).coord.x, (p->s).coord.y) != 0) {
          (p->s).mode[1] = 1;
          (p->s).mode[2] = 0;
        }
        break;
    }
  }
}

void FUN_080a2710(struct Projectile* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      struct Coord c;
      (p->s).flags &= ~DISPLAY;
      (p->s).work[2] = 0x14;
      c.x = (p->s).coord.x;
      c.y = (p->s).coord.y - 0x800;
      CreateSmoke(1, &c);
      PlaySound(0x35);
      SetDDP(&p->body, &sCollisions[2]);
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      if ((p->s).work[2] != 0 && --(p->s).work[2] != 0) {
        break;
      }
      SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      break;
  }
}

// --------------------------------------------

// 0x0836B358
static const struct Collision sCollisions[3] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(12), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(12), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(24), PIXEL(24)},
    },
};
