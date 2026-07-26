#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "vfx.h"
#include "physics.h"
#include "physics.h"
#include "physics.h"

void FUN_0809c664(struct Enemy* p);

void Enemy72_Die(struct Enemy* p);

void Enemy72_Update(struct Enemy* p);

static const EnemyFunc sUpdates[2];

struct Enemy* FUN_0809c3b4(struct Entity* e, struct Coord* c, u16 a2, u8 a3) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_72);
    (p->s).coord = *c;
    (p->s).work[0] = a3;
    (p->s).work[1] = 0;
    *(u16*)&p->buffer[0] = a2;
    (p->s).unk_28 = e;
  }
  return p;
}

struct Enemy* FUN_0809c430(struct Entity* e, struct Coord* c) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_72);
    (p->s).coord = *c;
    (p->s).work[0] = 0;
    (p->s).work[1] = 1;
    (p->s).unk_28 = e;
  }
  return p;
}

INCASM("asm/enemy/unk_72_a.inc");

void Enemy72_Update(struct Enemy* p) {
  (sUpdates[(p->s).mode[1]])((void*)p);
}

void Enemy72_Die(struct Enemy* p) {
  (p->s).flags &= ~DISPLAY;
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/enemy/unk_72_b.inc");

static const struct Collision sCollisions[3];

// 0x0809c664
void FUN_0809c664(struct Enemy* p) {
  if ((p->s).unk_28->mode[0] > 1) {
    CreateSmoke(2, &(p->s).coord);
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
  } else if ((p->body).status & 0x200) {
    Coords32 c;
    c = (p->s).coord;
    c.x -= 0x800;
    CreateSmoke(2, &c);
    c.x += 0x800;
    c.y -= 0x400;
    CreateSmoke(2, &c);
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
  } else if (--(p->s).work[2] == 0) {
    CreateSmoke(2, &(p->s).coord);
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
  } else {
    switch ((p->s).mode[2]) {
      case 0: {
        u8 f;
        SetSpriteAnimation(p, MOTION(SM163_GRAFFITI_ZERO1, 4));
        f = (p->s).unk_28->flags & X_FLIP;
        if (f == 0) {
          (p->s).d.x = 0xC0;
          SET_XFLIP(p, 0);
        } else {
          (p->s).d.x = -0xC0;
          SET_XFLIP(p, 1);
        }
        (p->s).d.y = -0x400;
        (p->s).work[3] = 0x28;
        (p->s).mode[2]++;
        FALLTHROUGH;
      }
      case 1:
        if ((p->s).work[3] != 0 && --(p->s).work[3] == 0) {
          SetDDP(&p->body, &sCollisions[1]);
        }
        (p->s).d.y += 0x40;
        if ((p->s).d.y > 0x700) {
          (p->s).d.y = 0x700;
        }
        (p->s).coord.x += (p->s).d.x;
        (p->s).coord.y += (p->s).d.y;
        {
          s32 push = PushoutToUp1((p->s).coord.x, (p->s).coord.y);
          if (push != 0) {
            (p->s).coord.y += push;
            (p->s).d.y = -0x300;
          }
        }
        if ((p->s).d.x > 0) {
          s32 push = PushoutToLeft1((p->s).coord.x + 0x800, (p->s).coord.y);
          if (push != 0) {
            (p->s).d.x = -(p->s).d.x;
            SET_XFLIP(p, !(((p->s).flags >> 4) & 1));
            (p->s).coord.x += push;
          }
        } else {
          s32 push = PushoutToRight1((p->s).coord.x - 0x800, (p->s).coord.y);
          if (push != 0) {
            (p->s).d.x = -(p->s).d.x;
            SET_XFLIP(p, !(((p->s).flags >> 4) & 1));
            (p->s).coord.x += push;
          }
        }
        UpdateSpriteAnimation(p);
        break;
    }
  }
}

void Enemy72_Init(struct Enemy* p);
void Enemy72_Update(struct Enemy* p);
void Enemy72_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gEnemy72Routine = {
    [ENTITY_INIT] =      (void*)Enemy72_Init,
    [ENTITY_UPDATE] =    (void*)Enemy72_Update,
    [ENTITY_DIE] =       (void*)Enemy72_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_0809c5bc(struct Enemy* p);
void FUN_0809c664(struct Enemy* p);

static const EnemyFunc sUpdates[2] = {
    FUN_0809c5bc,
    FUN_0809c664,
};

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(1), -PIXEL(4), PIXEL(26), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 1,
      range : {PIXEL(1), -PIXEL(4), PIXEL(26), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(1), -PIXEL(4), PIXEL(26), PIXEL(14)},
    },
};
