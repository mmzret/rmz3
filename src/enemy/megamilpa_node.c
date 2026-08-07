#include "enemy/megamilpa_node.h"

#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "vfx.h"

void CreateGhost19_2(struct Entity* p, struct Coord* c);

void MegamilpaNode_Init(struct Enemy* p);
void MegamilpaNode_Update(struct Enemy* p);
void MegamilpaNode_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gMegamilpaNodeRoutine = {
    [ENTITY_INIT] =      (EnemyFunc)MegamilpaNode_Init,
    [ENTITY_UPDATE] =    (EnemyFunc)MegamilpaNode_Update,
    [ENTITY_DIE] =       (EnemyFunc)MegamilpaNode_Die,
    [ENTITY_DISAPPEAR] = (EnemyFunc)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------


const struct Collision gMegamilpaNodeHitbox[2];
const EnemyFunc sMegamilpaNodeUpdates1[3];
const EnemyFunc sMegamilpaNodeUpdates2[3];
const u8 u8_ARRAY_08365cf0[2];
MegamilpaNode* CreateMegamilpaNode(u8 idx) {
  MegamilpaNode* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_MEGAMILPA_NODE);
    p->work[0] = 0;
    p->nodeIdx = idx;
  }
  return p;
}

// --------------------------------------------

void MegamilpaNode_Init(struct Enemy* p) {
  register struct Entity* q asm("r8");
  register u32 z asm("r5");
  struct Body* b;
  q = *(struct Entity**)((u8*)p + 0xb4);
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  {
    u8 mv = u8_ARRAY_08365cf0[(p->s).work[0]];
    z = 0;
    (p->s).mode[1] = mv;
  }
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  ResetDynamicMotion(&p->s);
  (p->s).flags |= COLLIDABLE;
  b = &p->body;
  InitBody(b, &gMegamilpaNodeHitbox[1], &(p->s).coord, 1);
  b->parent = (struct Entity*)p;
  b->fn = (BodyFunc)z;
  if (*(u8*)((u8*)p + 0xb8) == 0) {
    SetMotion(&p->s, MOTION(0xA0, 0x00));
    UpdateEntityAnim(&p->s);
  }
  (p->s).flags2 |= 0x10;
  { register struct Entity* qq asm("r1"); qq = q; (p->s).invincibleID = qq->uniqueID; }
  MegamilpaNode_Update(p);
}

void MegamilpaNode_Update(struct Enemy* p) {
  if ((*(struct Entity**)((u8*)p + 0xb4))->mode[0] > 1) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    MegamilpaNode_Die(p);
  } else {
    (sMegamilpaNodeUpdates1[(p->s).mode[1]])(p);
    (sMegamilpaNodeUpdates2[(p->s).mode[1]])(p);
  }
}

void MegamilpaNode_Die(struct Enemy* p) {
  s32 z = (p->s).mode[1];
  struct Coord* c;
  switch (z) {
    case 0: {
      u8* q = (u8*)p + 0x8c;
      *(s32*)q = z;
      asm("" : "+r"(q));
      q += 4;
      *(s32*)q = z;
      asm("" : "+r"(q));
      q += 4;
      asm("" : "+r"(q));
      *q = z;
      (p->s).flags &= ~4;
      if (((p->s).flags & 1) == 0) {
        SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
        break;
      }
      *(s32*)((u8*)p + 0x60) = z;
      (p->s).mode[1]++;
      /* fallthrough */
    }
    case 1: {
      s32 y = (p->s).coord.y;
      s32 v = *(s32*)((u8*)p + 0x60);
      (p->s).coord.y = y + v;
      v += 0x20;
      *(s32*)((u8*)p + 0x60) = v;
      if (v > 0x700) {
        *(s32*)((u8*)p + 0x60) = 0x700;
      }
      if (FUN_080098a4((p->s).coord.x, (p->s).coord.y) != 0) {
        SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
        PlaySound(0x2a);
        c = &(p->s).coord;
        CreateSmoke(1, c);
        CreateGhost19_2(&p->s, c);
      }
      break;
    }
  }
}

void nop_08065928(struct Enemy* p) {}

void MegamilpaNode_0806592c(struct Enemy* p) {
  struct Entity* q = *(struct Entity**)((u8*)p + 0xb4);
  switch ((p->s).mode[2]) {
    case 0: {
      register u8 fv asm("r0");
      register u8 t asm("r1");
      SetDDP(&p->body, &gMegamilpaNodeHitbox[1]);
      t = (p->s).flags;
      fv = 0xFE;
      fv &= t;
      (p->s).flags = fv;
      asm volatile("" ::"r"(t));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register u32* f asm("r1");
      s32 one;
      s32 v1;
      f = (u32*)((u8*)q + 0xc0);
      v1 = *f;
      one = 1;
      if ((v1 & one) != 0) {
        s32 z = 0;
        (p->s).mode[1] = one;
        (p->s).mode[2] = z;
      }
      {
        register s32 two asm("r1");
        s32 v2 = *f;
        two = 2;
        if ((v2 & two) != 0) {
          s32 z = 0;
          (p->s).mode[1] = two;
          (p->s).mode[2] = z;
        }
      }
      break;
    }
  }
}

INCASM("asm/enemy/megamilpa_node_a.inc");

void nop_08065928(struct Enemy* p);

const EnemyFunc sMegamilpaNodeUpdates1[3] = {
    nop_08065928,
    nop_08065928,
    nop_08065928,
};

// --------------------------------------------

void MegamilpaNode_0806592c(struct Enemy* p);
void MegamilpaNode_08065988(struct Enemy* p);
void MegamilpaNode_08065cbc(struct Enemy* p);

const EnemyFunc sMegamilpaNodeUpdates2[3] = {
    MegamilpaNode_0806592c,
    MegamilpaNode_08065988,
    MegamilpaNode_08065cbc,
};

const struct Collision gMegamilpaNodeHitbox[2] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(4), PIXEL(0), PIXEL(8), PIXEL(16)},
    },
};

const u8 u8_ARRAY_08365cf0[2] = {0, 0};

// clang-format off
const motion_t sMegamilpaNodeMotions[10] = {
    MOTION(DM160_MEGAMILPA, 0x00),
    MOTION(DM160_MEGAMILPA, 0x01),
    MOTION(DM160_MEGAMILPA, 0x02),
    MOTION(DM160_MEGAMILPA, 0x03),
    MOTION(DM160_MEGAMILPA, 0x04),
    MOTION(DM160_MEGAMILPA, 0x06),
    MOTION(DM160_MEGAMILPA, 0x07),
    MOTION(DM160_MEGAMILPA, 0x08),
    MOTION(DM160_MEGAMILPA, 0x09),
    MOTION(DM160_MEGAMILPA, 0x0A),
};
// clang-format on
