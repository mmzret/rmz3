#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "physics.h"
#include "element.h"
#include "zero.h"

struct Entity* FUN_080bb830(struct Entity* e);
static const struct Collision sCollisions[];
static const Coords32 sElementCoords[2];

void Snakecord_Init(struct Enemy* p);
void Snakecord_Update(struct Enemy* p);
void Snakecord_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gSnakecordRoutine = {
    [ENTITY_INIT] =      (void*)Snakecord_Init,
    [ENTITY_UPDATE] =    (void*)Snakecord_Update,
    [ENTITY_DIE] =       (void*)Snakecord_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};

void FUN_08074f34(struct Enemy* p);
// clang-format on

u32 FUN_08073ea8(struct Entity* p, s32 dx) {
  if (dx != 0) {
    (p->coord).x += dx;
    if (dx < 0) {
      s32 val = PushoutToRight2((p->coord).x, (p->coord).y);
      if (val > 0) {
        (p->coord).x += val;
        return 2;
      }
    } else {
      s32 val = PushoutToLeft2((p->coord).x, (p->coord).y);
      if (val < 0) {
        (p->coord).x += val;
        return 1;
      }
    }
  }
  return 0;
}

u32 FUN_08073ef0(struct Entity* p, s32 dy) {
  if (dy != 0) {
    (p->coord).y += dy;
    if (dy < 0) {
      s32 val = PushoutToDown2((p->coord).x, (p->coord).y);
      if (val > 0) {
        (p->coord).y += val;
        return 2;
      }
    } else {
      s32 val = PushoutToUp2((p->coord).x, (p->coord).y);
      if (val < 0) {
        (p->coord).y += val;
        return 1;
      }
    }
  }
  return 0;
}

WIP void SnakeCord_08073f3c(struct Entity* p) {
#ifdef ALWAYS_FALSE
  {
    struct Entity* q = p;
    while (q != NULL) {
      (q->d).y += PIXEL(1) / 4;
      if (q->work[2]) {
        if (p->mode[1] == 1) {
          (q->coord).x += (q->d).x;
          (q->coord).y += (q->d).y;
        } else {
          FUN_08073ea8(q, (q->d).x);
          FUN_08073ef0(q, (q->d).y);
        }
      }
      q = q->unk_28;
    }
  }

  {
    struct Entity* cur = p;
    struct Entity* next = cur->unk_28;
    u8 i;
    for (i = 0; next != NULL; i++) {
      s32 divisor;
      s32 dx = (next->coord).x - (cur->coord).x;
      s32 dy = (next->coord).y - (cur->coord).y;
      u8 angle = (ArcTan2(dx, dy) >> 8) + 64;
      if (i == 0) cur->angle = angle + 192;
      next->angle = angle;

      if (divisor = Sqrt(dx * dx + dy * dy), divisor != 0) {
        s32 a = (dx * PIXEL(1)) / divisor;
        s32 b = (dy * PIXEL(1)) / divisor;
        dx = (divisor - PIXEL(14)) * 0xA0;
        if (dx < 0) dx += 0xFF;
        dy = (dx >> 8) * a;
        if (dy < 0) dy += 0xFF;
        dy >>= 8;
        dx = (dx >> 8) * b;
        if (dx < 0) dx += 0xFF;
        dx >>= 8;
        if (p->mode[1] == 1) {
          (cur->coord).x += dy;
          (cur->coord).y += dx;
          if (next->work[2]) {
            (next->coord).x -= dy;
            (next->coord).y -= dx;
          }
        } else {
          FUN_08073ea8(cur, dy);
          FUN_08073ef0(cur, dx);
          if (next->work[2]) {
            FUN_08073ea8(next, -dy);
            FUN_08073ef0(next, -dx);
          }
        }
      }
      cur = next;
      next = cur->unk_28;
    }
  }

  {
    struct Entity* cur = p;
    while (cur != NULL) {
      s32 dx = (cur->coord).x - (cur->unk_coord).x;
      s32 dy = (cur->coord).y - (cur->unk_coord).y;
      dx *= 0xFE;
      if (dx < 0) dx += 0xFF;
      (cur->d).x = dx >> 8;
      dy *= 0xFE;
      if (dy < 0) dy += 0xFF;
      (cur->d).y = dy >> 8;
      (cur->unk_coord).x = (cur->coord).x;
      (cur->unk_coord).y = (cur->coord).y;

      cur = cur->unk_28;
    }
  }
#else
  INCCODE("asm/wip/SnakeCord_08073f3c.inc");
#endif
}

void FUN_080740e4(struct Entity* p) {
  while (p->unk_28 != NULL) {
    p = p->unk_28;
  }
  while (p != NULL) {
    if (p->work[2] < 2) {
      SET_ENEMY_ROUTINE(p, ENTITY_DIE);
      p->mode[1] = 1;
      (p->unk_2c)->unk_28 = NULL;
    }
    if (p->work[0] == 0) {
      p->mode[1] = 3, p->mode[2] = 0;
    }
    p = p->unk_2c;
  }
}

// 0x08074134
static void SnakeCord_onCollision(struct Body* body, Coords32* c1, Coords32* c2) {
  struct Entity* p = body->parent;
  if ((body->hitboxFlags & BODY_STATUS_B3) && (p->work[0] == 1) && (body->hitboxFlags & BODY_STATUS_SLASHED)) {
    FUN_080740e4(p);
  }
}

static bool8 FUN_0807415c(struct Enemy* p) {
  if ((p->s).work[0] == 0 && ((p->body).status & BODY_STATUS_DEAD)) {
    u8 i = 0;
    struct Entity* q = (p->s).unk_28;
    while (q != NULL) {
      SET_ENEMY_ROUTINE(q, ENTITY_DIE);
      q->mode[1] = 1;
      q = q->unk_28;
      i++;
    }

    if (((p->s).mode[1] < 1 || (p->s).mode[1] > 2) || (i == 2)) {
      SET_ENEMY_ROUTINE(p, ENTITY_DIE);
      if ((p->body).status & BODY_STATUS_RECOILED) {
        (p->s).mode[1] = 2;
      } else {
        (p->s).mode[1] = 0;
      }
    } else {
      SET_ENEMY_ROUTINE(p, ENTITY_DIE);
      (p->s).mode[1] = 0;
    }
    Snakecord_Die(p);
    return TRUE;
  }
  return FALSE;
}

INCASM("asm/enemy/snakecord_a.inc");

void FUN_080742ec(struct Enemy* p) {
  struct Entity** slot;
  struct Entity* e;
  const struct Coord* c;
  u8* t;
  u32 st;
  if ((p->s).work[0] != 0) {
    return;
  }
  if ((p->s).mode[1] == 1) {
    return;
  }
  t = (u8*)&p->buffer[0];
  e = *(struct Entity**)t;
  slot = (struct Entity**)t;
  asm("" : "+l"(slot));
  if (e != NULL) {
    return;
  }
  st = (p->body).status;
  if (!(st & 1)) {
    return;
  }
  st &= 0x20000;
  if (st != 0) {
    (p->s).mode[1] = 0xA;
    (p->s).mode[2] = 0;
    return;
  }
  if ((*((u8*)p + 0x97) & 0xF0) == 0x20) {
    c = &sElementCoords[1];
    asm("" : "+l"(c));
  } else {
    c = &sElementCoords[0];
    asm("" : "+l"(c));
  }
  *slot = ApplyElementEffect(0, (struct CollisionObject*)p, c);
  asm("" : "+l"(slot));
  if (*slot != NULL) {
    (p->s).mode[1] = 0;
    (p->s).mode[2] = 0;
  }
}

INCASM("asm/enemy/snakecord_b.inc");

void FUN_08074f34(struct Enemy* p) {
  register s32 m asm("r5");
  m = (p->s).mode[2];
  switch (m) {
    case 0:
      (p->s).renderPrio = 0xF;
      SetDDP(&p->body, &sCollisions[8]);
      SetMotion(&p->s, MOTION(0x28, 0x0B));
      (p->s).unk_2c = FUN_080bb830(&p->s);
      (p->s).work[2] = m;
      (p->s).mode[2]++;
      /* fallthrough */
    case 1: {
      register struct Zero* z asm("r3");
      s32 zx;
      if ((p->s).work[2] == 0) {
        (p->s).work[2] = 0x18;
        PlaySound(0x3B);
      }
      (p->s).work[2]--;
      z = pZero2;
      zx = (z->s).coord.x;
      (p->s).coord.x = zx + 0x800;
      {
        s32 t;
        u32 f = (p->s).flags & X_FLIP;
        t = zx + 0x7F0;
        if (f) {
          t = zx - 0x800;
        }
        (p->s).coord.x = t;
      }
      (p->s).coord.y = (z->s).coord.y - 0x800;
      UpdateEntityAnim(&p->s);
      break;
    }
  }
}

INCASM("asm/enemy/snakecord_c.inc");

// --------------------------------------------

void FUN_080746c0(struct Enemy* p);
void FUN_08074618(struct Enemy* p);
void FUN_08074618(struct Enemy* p);
void FUN_0807472c(struct Enemy* p);
void FUN_0807461c(struct Enemy* p);
void FUN_0807465c(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_08366e30[12] = {
    FUN_080746c0,
    FUN_08074618,
    FUN_08074618,
    FUN_0807472c,
    FUN_0807472c,
    FUN_0807472c,
    FUN_0807472c,
    FUN_0807461c,
    FUN_0807461c,
    FUN_0807465c,
    FUN_08074618,
    FUN_0807472c,
};
// clang-format on

// --------------------------------------------

void snakecord_08074754(struct Enemy* p);
void FUN_080748a8(struct Enemy* p);
void FUN_0807484c(struct Enemy* p);
void FUN_08074ac0(struct Enemy* p);
void FUN_08074bac(struct Enemy* p);
void FUN_08074cb4(struct Enemy* p);
void FUN_08074d18(struct Enemy* p);
void FUN_08074d90(struct Enemy* p);
void FUN_08074e90(struct Enemy* p);
void FUN_08074f34(struct Enemy* p);
void FUN_08075154(struct Enemy* p);
void FUN_08074fcc(struct Enemy* p);

// clang-format off
const EnemyFunc PTR_ARRAY_08366e60[12] = {
    snakecord_08074754,
    FUN_080748a8,
    FUN_0807484c,
    FUN_08074ac0,
    FUN_08074bac,
    FUN_08074cb4,
    FUN_08074d18,
    FUN_08074d90,
    FUN_08074e90,
    FUN_08074f34,
    FUN_08075154,
    FUN_08074fcc,
};
// clang-format on

// --------------------------------------------

void MaybeKillSnakecord(struct Enemy* p);
void FUN_080750f8(struct Enemy* p);
void FUN_08075154(struct Enemy* p);

const EnemyFunc PTR_ARRAY_08366e90[3] = {
    MaybeKillSnakecord,
    FUN_080750f8,
    FUN_08075154,
};

// --------------------------------------------

// 0x08366e9c
static const struct Collision sCollisions[] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(4), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 2,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(4), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      hardness : HARDNESS_B3,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(2), -PIXEL(26), PIXEL(11), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 2,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(2), -PIXEL(26), PIXEL(11), PIXEL(10)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      unk_0a : 0x21,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(2), -PIXEL(8), PIXEL(11), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 2,
      hardness : 8,
      remaining : 0,
      range : {-PIXEL(2), -PIXEL(8), PIXEL(11), PIXEL(10)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      unk_0a : 0x21,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(5), -PIXEL(16), PIXEL(64), PIXEL(64)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(2), -PIXEL(11), PIXEL(11), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 2,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(2), -PIXEL(11), PIXEL(11), PIXEL(10)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(2), -PIXEL(3), PIXEL(11), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 2,
      hardness : 8,
      remaining : 0,
      range : {-PIXEL(2), -PIXEL(3), PIXEL(11), PIXEL(10)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(2), -PIXEL(26), PIXEL(11), PIXEL(10)},
    },
};

// --------------------------------------------

// 0x08366fec
static const u8 u8_ARRAY_08366fec[13] = {
    4, 4, 4, 4, 4, 4, 9, 9, 11, 11, 11, 11, 11,
};

// 0x08366FFC
static const Coords32 sElementCoords[2] = {
    {PIXEL(0), -PIXEL(24)},
    {PIXEL(0), -PIXEL(16)},
};

// 0x0836700c
static const u8 sInitModes[4] = {1, 2, 0, 0};
