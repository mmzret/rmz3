#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "physics.h"
#include "vfx.h"

void Enemy72_Update(struct Enemy* p);
#include "script.h"


static const struct Collision sCollisions[3];
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

void Enemy72_Init(struct Enemy* p) {
  s32 z4;
  register s32 z6 asm("r6");
  InitNonAffineMotion(&p->s);
  {
    register u8 fl asm("r1");
    register u8 fv asm("r0");
    fl = (p->s).flags;
    fv = 1;
    z4 = 0;
    asm volatile("" : "+l"(z4));
    z6 = 0;
    fv |= fl;
    fl = 2;
    fv |= fl;
    (p->s).flags = fv;
  }
  ResetDynamicMotion(&p->s);
  asm volatile("" ::"l"(z4));
  if ((p->s).work[1] == 0) {
    register s32 dx asm("r0");
    register s32 z2 asm("r2");
    if ((p->s).work[0] == 0) {
      register u8* a asm("r0");
      register u8* b asm("r2");
      register u8 ov asm("r1");
      register s32 m asm("r0");
      {
        register u8 fl2 asm("r1");
        register u8 g asm("r0");
        fl2 = (p->s).flags;
        asm("" : "+r"(fl2));
        g = 0xEF;
        g &= fl2;
        (p->s).flags = g;
      }
      a = (u8*)p + 0x4c;
      *a = z6;
      b = (u8*)p + 0x4a;
      ov = *b;
      m = 0x11;
      m = -m;
      m &= ov;
      *b = m;
      dx = 0x80;
    } else {
      register s32 one asm("r2");
      register u8* a2 asm("r0");
      register u8* b2 asm("r3");
      register s32 k10 asm("r2");
      register u8 ov2 asm("r1");
      register s32 m2 asm("r0");
      one = 1;
      {
        register u8 g2 asm("r0");
        register u8 h2 asm("r1");
        g2 = (p->s).flags;
        h2 = 0x10;
        g2 |= h2;
        (p->s).flags = g2;
      }
      a2 = (u8*)p + 0x4c;
      *a2 = one;
      b2 = (u8*)p + 0x4a;
      k10 = 0x10;
      ov2 = *b2;
      m2 = 0x11;
      m2 = -m2;
      m2 &= ov2;
      m2 |= k10;
      *b2 = m2;
      dx = -0x80;
    }
    (p->s).d.x = dx;
    {
      register u8 fl3 asm("r1");
      register u8 g3 asm("r0");
      fl3 = (p->s).flags2;
      g3 = 0x10;
      z2 = 0;
      g3 |= fl3;
      (p->s).flags2 = g3;
    }
    (p->s).invincibleID = ((p->s).unk_28)->uniqueID;
    SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
    (p->s).mode[1] = z2;
    (p->s).mode[2] = z2;
    (p->s).mode[3] = z2;
  } else {
    register s32 one2 asm("r1");
    (p->s).work[2] = 0xFF;
    {
      register u8 g4 asm("r0");
      register u8 h4 asm("r1");
      g4 = (p->s).flags;
      h4 = 4;
      g4 |= h4;
      (p->s).flags = g4;
    }
    {
      struct Body* body = &p->body;
      InitBody(body, &sCollisions[1], &(p->s).coord, 0x10);
      body->parent = (struct Entity*)p;
      body->fn = (void*)z6;
    }
    {
      u32 tbl = (u32)gEnemyFnTable;
      EntityFunc** rt = (EntityFunc**)(tbl + (((p->s).id) << 2));
      one2 = 1;
      *(u32*)((p->s).mode) = one2;
      (p->s).onUpdate = (void*)((*rt)[1]);
    }
    (p->s).mode[1] = one2;
    (p->s).mode[2] = z6;
    (p->s).mode[3] = z6;
  }
  Enemy72_Update(p);
}

void Enemy72_Update(struct Enemy* p) {
  (sUpdates[(p->s).mode[1]])(p);
}

void Enemy72_Die(struct Enemy* p) {
  (p->s).flags &= ~DISPLAY;
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

void FUN_0809c5bc(struct Enemy* p) {
  s32 m = (p->s).mode[2];
  switch (m) {
    case 0: {
      struct Entity* q;
      SetMotion(&p->s, *(u16*)((u8*)p + 0xb4));
      (p->s).work[2] = 0x1e;
      if ((p->s).d.x > 0) {
        q = (p->s).unk_28;
        (p->s).unk_coord.x = (q->coord).x + 0xC00;
      } else {
        q = (p->s).unk_28;
        (p->s).unk_coord.x = (q->coord).x - 0xC00;
      }
      (p->s).d.y = 0x80;
      (p->s).unk_coord.y = (q->coord).y + 0x600;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      (p->s).coord.x += (((p->s).unk_coord.x - (p->s).coord.x) << 4) >> 8;
      (p->s).coord.y += (((p->s).unk_coord.y - (p->s).coord.y) << 4) >> 8;
      UpdateEntityAnim(&p->s);
      break;
    case 2:
      if ((((p->s).unk_28)->scriptEntity)->flags & 0x80) {
        SET_ENEMY_ROUTINE(p, ENTITY_DIE);
      }
      break;
  }
}

void FUN_0809c664(struct Enemy* p) {
  if ((p->s).unk_28->mode[0] > 1) {
    CreateSmoke(2, &(p->s).coord);
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
  } else if ((p->body).status & 0x200) {
    struct Coord c;
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
        SetMotion(&p->s, 0xA304);
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
        UpdateEntityAnim(&p->s);
        break;
    }
  }
}

void Enemy72_Init(struct Enemy* p);
void Enemy72_Update(struct Enemy* p);
void Enemy72_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gEnemy72Routine = {
    [ENTITY_INIT] =      Enemy72_Init,
    [ENTITY_UPDATE] =    Enemy72_Update,
    [ENTITY_DIE] =       Enemy72_Die,
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
