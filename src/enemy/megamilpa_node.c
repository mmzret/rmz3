#include "enemy/megamilpa_node.h"

#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "projectile.h"

const struct Collision gMegamilpaNodeHitbox[2];

void MegamilpaNode_Init(MegamilpaNode* p);
void MegamilpaNode_Update(MegamilpaNode* p);
void MegamilpaNode_Die(MegamilpaNode* p);

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

MegamilpaNode* CreateMegamilpaNode(u8 idx) {
  MegamilpaNode* p = (MegamilpaNode*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_MEGAMILPA_NODE);
    p->work[0] = 0;
    p->nodeIdx = idx;
  }
  return p;
}

// --------------------------------------------

INCASM("asm/enemy/megamilpa_node_a.inc");

void MegamilpaNode_08065cbc(MegamilpaNode* p) {
  struct Entity* q = *(struct Entity**)((u8*)p + 0xb4);
  struct Coord c;
  u8* w;
  switch (p->mode[2]) {
    case 0: {
      SetDDP(&p->body, &gMegamilpaNodeHitbox[1]);
      *((u8*)p + 0xb9) = 0;
      {
        u8* a0 = (u8*)p + 0xb8;
        u8 d0 = *a0;
        w = a0;
        asm("" : "+r"(w));
        if (d0 == 0) {
          GotoMotion((struct Entity*)p, MOTION(DM160_MEGAMILPA, 0x0B), (*w << 2) % 10, 4);
        } else {
          GotoMotion((struct Entity*)p, MOTION(DM160_MEGAMILPA, 0x05), (*w << 2) % 10, 4);
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      p->flags &= 0xFE;
      {
        u16 tv = *w * 24;
        *(u16*)((u8*)p + 0xba) = tv;
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      u16* t = (u16*)((u8*)p + 0xba);
      u16 raw = *t;
      s32 v = *(s16*)t;
      if (v != 0) {
        raw--;
        *t = raw;
        break;
      }
      p->work[3] = v;
      p->mode[2]++;
      break;
    }
    case 2: {
      SetDDP(&p->body, &gMegamilpaNodeHitbox[0]);
      UpdateEntityAnim((struct Entity*)p);
      {
        u8* a1;
        u8 t;
        u32 fl, x, y;
        register u32 y1 asm("r4");
        u32 one;
        u8* oa;
        s32 ov, m11, m21;
        fl = p->flags;
        one = 1;
        {
          register u32 z asm("r3");
          z = 0;
          asm("" ::"r"(z));
        }
        fl |= one;
        p->flags = fl;
        a1 = (u8*)q + 0xbe;
        t = *a1;
        asm volatile("" ::"l"(t));
        w = a1;
        asm("" : "+r"(w));
        if (t != 0) {
          fl |= 0x10;
        } else {
          fl &= 0xEF;
        }
        p->flags = fl;
        y1 = 1;
        x = t & 1;
        *((u8*)p + 0x4c) = x;
        oa = (u8*)p + 0x4a;
        x <<= 4;
        ov = *oa;
        m11 = -0x11;
        m11 &= ov;
        m11 |= x;
        *oa = m11;
        y1 ^= p->work[3];
        if (y1 != 0) {
          p->flags |= 0x20;
        } else {
          p->flags &= 0xDF;
        }
        y = y1 & 1;
        *((u8*)p + 0x4d) = y;
        y <<= 5;
        ov = *oa;
        m21 = -0x21;
        m21 &= ov;
        m21 |= y;
        *oa = m21;
        p->coord.x = *(s32*)((u8*)q + 0xb4) + 0x3000;
        p->coord.x -= ((*w ^ p->work[3]) * 3) << 13;
        {
          s32 base = *(s32*)((u8*)q + 0xb8);
          p->coord.y = base - ((p->work[3] * 5) << 13);
        }
        p->d.y = (p->work[3] << 9) + -0x100;
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      s8* a71;
      s32 m1, m2, v;
      u8* b9;
      UpdateEntityAnim((struct Entity*)p);
      {
        s8* a2 = (s8*)((u8*)p + 0x71);
        m1 = *a2;
        a71 = a2;
      }
      if (m1 != 0) goto Lchk5;
      {
        u8* a3 = (u8*)p + 0xb8;
        u8 d3 = *a3 & 1;
        w = a3;
        if (d3 != 0) goto Lfire;
      }
    Lchk5:
      if (m1 != 5) goto Lcommon;
      {
        u8* a4 = (u8*)p + 0xb8;
        u8 d4 = *a4 & 1;
        w = a4;
        if (d4 != 0) goto Lcommon;
      }
    Lfire:
      m2 = *(s8*)((u8*)p + 0x72);
      if (m2 != 3) goto Lcommon;
      b9 = (u8*)p + 0xb9;
      (*b9)++;
      if (((*b9 + *w) & m2) != 0) goto Lcommon;
      v = (s8)(*a71 / 5);
      v ^= *((u8*)q + 0xbe);
      {
        s32 bx = p->coord.x + -0xC00;
        c.x = ((v * 3) << 11) + bx;
      }
      c.y = p->coord.y;
      PlaySound(0x2c);
      CreateLemon(&c, 0x200, v << 7);
    Lcommon:
      p->coord.y += p->d.y;
      if (p->work[3] != 0) {
        if (p->coord.y > *(s32*)((u8*)q + 0xb8)) {
          p->mode[2]++;
        }
      } else {
        if (p->coord.y < *(s32*)((u8*)q + 0xb8) + -0xA000) {
          p->mode[2]++;
        }
      }
      break;
    }
    case 4:
      SetDDP(&p->body, &gMegamilpaNodeHitbox[1]);
      if (p->work[3] != 0) {
        p->mode[1] = 0;
        p->mode[2] = 0;
        break;
      }
      p->flags &= 0xFE;
      p->work[2] = 8;
      p->mode[2]++;
      FALLTHROUGH;
    case 5: {
      u8 w2 = p->work[2];
      if (w2 != 0) {
        p->work[2] = w2 - 1;
        break;
      }
      p->work[3]++;
      p->mode[2] = 2;
      break;
    }
  }
  asm volatile("" ::"l"(q));
}

void nop_08065928(MegamilpaNode* p);

const EnemyFunc sMegamilpaNodeUpdates1[3] = {
    (EnemyFunc)nop_08065928,
    (EnemyFunc)nop_08065928,
    (EnemyFunc)nop_08065928,
};

// --------------------------------------------

void MegamilpaNode_0806592c(MegamilpaNode* p);
void MegamilpaNode_08065988(MegamilpaNode* p);
void MegamilpaNode_08065cbc(MegamilpaNode* p);

const EnemyFunc sMegamilpaNodeUpdates2[3] = {
    (EnemyFunc)MegamilpaNode_0806592c,
    (EnemyFunc)MegamilpaNode_08065988,
    (EnemyFunc)MegamilpaNode_08065cbc,
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
