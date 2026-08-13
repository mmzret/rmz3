#include "enemy/claveker.h"

#include "collision.h"
#include "element.h"
#include "enemy.h"
#include "global.h"
#include "mod.h"
#include "physics.h"
#include "story.h"
#include "zero.h"

static const struct Collision sCollisions[3];
static const Coords32 sElementCoord;

static void Claveker_Init(Claveker* p);
static void Claveker_Update(Claveker* p);
void Claveker_Die(Claveker* p);

// clang-format off
const EnemyRoutine gClavekerRoutine = {
    [ENTITY_INIT] =      (void*)Claveker_Init,
    [ENTITY_UPDATE] =    (void*)Claveker_Update,
    [ENTITY_DIE] =       (void*)Claveker_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static Claveker* Unused_CreateClaveker(Coords32* c, u8 n) {
  Claveker* p = (Claveker*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_CLAVEKER);
    p->coord = *c;
    p->work[0] = n;
  }
  return p;
}

static void Claveker_OnCollision(struct Body* body, Coords32* c, Coords32* _);

static void Claveker_Init(Claveker* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  if (FLAG(gSystemSavedata.flags, MOD_CLAVEKER) && !FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
    _INIT_BODY(p, &sCollisions[1], 14);
  } else {
    _INIT_BODY(p, &sCollisions[1], 10);
  }
  SET_BODY_INTERSECT_HANDLER(p, Claveker_OnCollision);
  (p->coord).y = FUN_0800a134((p->coord).x, (p->coord).y);
  p->initX = (p->coord).x;
  p->unk_b8 = 0;
  p->elfx = NULL;
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  if (IsFrozen(p)) {
    SetSpriteAnimation(p, MOTION(SM117_CLAVEKER, 0));
    UpdateSpriteAnimation(p);
  }
  p->unk_bb = 0;
  Claveker_Update(p);
}

static bool8 FUN_0808eb20(Claveker* p);
static bool8 FUN_0808ebb0(Claveker* p);
static bool8 FUN_0808effc(Claveker* p);
static bool8 FUN_0808f158(Claveker* p);
static bool8 FUN_0808f198(Claveker* p);
static bool8 FUN_0808f1a0(Claveker* p);

void FUN_0808eb24(Claveker* p);
void FUN_0808ebb4(Claveker* p);
void FUN_0808f000(Claveker* p);
static void FUN_0808f15c(Claveker* p);
static void FUN_0808f19c(Claveker* p);
static void FUN_0808f1a4(Claveker* p);

static bool8 FUN_0808f1e0(Claveker* p);

static void Claveker_Update(Claveker* p) {
  // clang-format off
  static bool8 (*const sUpdates1[6])(Claveker*) = {
      FUN_0808eb20,
      FUN_0808ebb0,
      FUN_0808effc,
      FUN_0808f158,
      FUN_0808f198,
      FUN_0808f1a0,
  };
  // clang-format on
  // clang-format off
  static void (*const sUpdates2[6])(Claveker*) = {
      FUN_0808eb24,
      FUN_0808ebb4,
      FUN_0808f000,
      FUN_0808f15c,
      FUN_0808f19c,
      FUN_0808f1a4,
  };
  // clang-format on

  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    Claveker_Die(p);
    return;
  }

  (sUpdates1[p->mode[1]])((void*)p);
  FUN_0808f1e0(p);

  if (IsFrozen(p)) {
    u8 m = p->mode[1];
    if (m == 2) goto skip_reset;
    if (m == 3) goto skip_reset;
    if (m == 5) goto skip_reset;
    if (m == 4) goto skip_reset;
    p->mode[1] = 0, p->mode[2] = 0;
  skip_reset:;
  }
  if (p->elfx == NULL) {
    if (IsFrozen(p)) {
      p->unk_ba = p->mode[1];
      return;
    }
  }
  if (IsFrozen(p)) {
    p->mode[1] = 0, p->mode[2] = 0;
  }
  if (p->elfx == NULL) {
    goto dispatch2;
  }
  if (isKilled(p->elfx)) {
    SetDDP(&p->body, &sCollisions[1]);
    p->elfx = NULL;
    p->mode[1] = 0, p->mode[2] = 0;
    return;
  }
  SetDDP(&p->body, &sCollisions[2]);
  return;

dispatch2:
  (sUpdates2[p->mode[1]])((void*)p);
}

INCASM("asm/enemy/claveker_b.inc");

static bool8 FUN_0808eb20(Claveker* p) { return TRUE; }

INCASM("asm/enemy/claveker_c.inc");

static bool8 FUN_0808ebb0(Claveker* p) { return TRUE; }

void FUN_0808ebb4(Claveker* p0) {
  register Claveker* p asm("r4");
  s32 zv;
  p = p0;
  switch (p->mode[2]) {
    case 0: {
      u32 f;
      SetMotion((struct Entity*)p, 0x7501);
      SetDDP(&p->body, (const struct Collision*)0x08369388);
      {
        struct Zero* z0 = pZero2;
        s32 zx = (z0->s).coord.x;
        s32 px = p->coord.x;
        if (zx > px) {
          p->unk_coord.x = zx + -0x3000;
          {
            s32 d = (z0->s).coord.x - px;
            if (d > 0) {
              if (d > ({ s32 lim1 = 0x2FFF; asm("" : "+r"(lim1)); lim1; })) {
                goto far0a;
              }
              goto near0;
            }
            if (px - (z0->s).coord.x > ({ s32 lim2 = 0x2FFF; asm("" : "+r"(lim2)); lim2; })) {
            far0a:
              asm("mov %0, #0" : "=r"(f));
              goto st0;
            }
            goto near0;
          }
        } else {
          p->unk_coord.x = zx + (0xC0 << 6);
          {
            s32 d2 = px - (z0->s).coord.x;
            if (d2 > 0) {
              if (d2 > ({ s32 lim3 = 0x2FFF; asm("" : "+r"(lim3)); lim3; })) {
                goto far0b;
              }
              goto near0;
            }
            if ((z0->s).coord.x - px > ({ s32 lim4 = 0x2FFF; asm("" : "+r"(lim4)); lim4; })) {
            far0b:
              f = 0;
              goto st0;
            }
          }
        near0:
          f = 1;
        st0:;
        }
      }
      p->mode[3] = f;
      {
        u32 rv = RANDOM(RNG_0202f388) % 0x14;
        u32 zw;
        s32 t0 = rv + 0x3C;
        asm("mov %0, #0" : "=r"(zw));
        p->work[2] = t0;
        p->work[3] = zw;
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if (p->mode[3] != 0) {
        goto side2;
      }
      {
        struct Zero** pz = &pZero2;
        struct Zero* z1 = *pz;
        s32 zx1 = (z1->s).coord.x;
        s32 px1 = p->coord.x;
        if (zx1 > px1) {
          s32 g = FUN_0800a134(px1 + (0xA0 << 5), p->coord.y + (0xA0 << 4));
          s32 cy = p->coord.y;
          if (g < cy) {
            p->mode[2] = 3;
            goto wander;
          }
          {
            s32 ox = p->coord.x;
            s32 r;
            p->coord.x = ox + (0xC0 << 2);
            r = PushoutToLeft1(ox + (0xB8 << 5), cy);
            if (r != 0) {
              p->work[3] = 1;
              p->coord.x += r;
              p->mode[2] = 3;
              goto wander;
            }
          }
          {
            s32 zx2 = ((*pz)->s).coord.x;
            s32 px2 = p->coord.x;
            s32 d3 = zx2 - px2;
            if (d3 > 0) {
              if (d3 <= ({ s32 lim5 = 0x2FFF; asm("" : "+r"(lim5)); lim5; })) {
                goto snapl1;
              }
              goto wander;
            }
            if (px2 - zx2 <= ({ s32 lim6 = 0x2FFF; asm("" : "+r"(lim6)); lim6; })) {
            snapl1:
              p->coord.x = (pZero2->s).coord.x + -0x3000;
              p->mode[2]++;
              goto wander;
            }
            goto wander;
          }
        } else {
          s32 g2 = FUN_0800a134(px1 + -0x1400, p->coord.y + (0xA0 << 4));
          s32 cy2 = p->coord.y;
          if (g2 < cy2) {
            p->mode[2] = 3;
            goto wander;
          }
          {
            s32 ox2 = p->coord.x;
            s32 r2;
            p->coord.x = ox2 + -0x300;
            r2 = PushoutToRight1(ox2 + -0x1700, cy2);
            if (r2 != 0) {
              p->work[3] = 1;
              p->coord.x += r2;
              p->mode[2] = 3;
              goto wander;
            }
          }
          {
            struct Zero* zt = *pz;
            s32 px3 = p->coord.x;
            s32 zx3 = (zt->s).coord.x;
            s32 d4 = px3 - zx3;
            if (d4 > 0) {
              if (d4 <= ({ s32 lim7 = 0x2FFF; asm("" : "+r"(lim7)); lim7; })) {
                goto snapr1;
              }
              goto wander;
            }
            if (zx3 - px3 <= ({ s32 lim8 = 0x2FFF; asm("" : "+r"(lim8)); lim8; })) {
            snapr1:
              p->coord.x = (pZero2->s).coord.x + (0xC0 << 6);
              p->mode[2]++;
              goto wander;
            }
            goto wander;
          }
        }
      }
    side2:
      {
        struct Zero** pz2 = &pZero2;
        struct Zero* z2 = *pz2;
        s32 zx4 = (z2->s).coord.x;
        s32 px4 = p->coord.x;
        if (zx4 > px4) {
          s32 g3 = FUN_0800a134(px4 + -0x1400, p->coord.y + (0xA0 << 4));
          s32 cy3 = p->coord.y;
          if (g3 < cy3) {
            p->mode[2] = 3;
            goto wander;
          }
          {
            s32 ox3 = p->coord.x;
            s32 r3;
            p->coord.x = ox3 + -0x300;
            r3 = PushoutToRight1(ox3 + -0x1700, cy3);
            if (r3 != 0) {
              p->work[3] = 1;
              p->coord.x += r3;
              p->mode[2] = 3;
              goto wander;
            }
          }
          {
            struct Zero* zt2 = *pz2;
            s32 px5 = p->coord.x;
            s32 zx5 = (zt2->s).coord.x;
            s32 d5 = px5 - zx5;
            if (d5 > 0) {
              if (d5 > ({ s32 lim9 = 0x2FFF; asm("" : "+r"(lim9)); lim9; })) {
                goto snapl2;
              }
              goto wander;
            }
            if (zx5 - px5 > ({ s32 lim10 = 0x2FFF; asm("" : "+r"(lim10)); lim10; })) {
            snapl2:
              p->coord.x = (pZero2->s).coord.x + -0x3000;
              p->mode[2]++;
              goto wander;
            }
            goto wander;
          }
        } else {
          s32 g4 = FUN_0800a134(px4 + (0xA0 << 5), p->coord.y + (0xA0 << 4));
          s32 cy4 = p->coord.y;
          if (g4 < cy4) {
            p->mode[2] = 3;
            goto wander;
          }
          {
            s32 ox4 = p->coord.x;
            s32 r4;
            p->coord.x = ox4 + (0xC0 << 2);
            r4 = PushoutToLeft1(ox4 + (0xB8 << 5), cy4);
            if (r4 != 0) {
              p->work[3] = 1;
              p->coord.x += r4;
              p->mode[2] = 3;
              goto wander;
            }
          }
          {
            s32 zx6 = ((*pz2)->s).coord.x;
            s32 px6 = p->coord.x;
            s32 d6 = zx6 - px6;
            if (d6 > 0) {
              if (d6 > ({ s32 lim11 = 0x2FFF; asm("" : "+r"(lim11)); lim11; })) {
                goto snapr2;
              }
              goto wander;
            }
            if (px6 - zx6 <= ({ s32 lim12 = 0x2FFF; asm("" : "+r"(lim12)); lim12; })) {
              goto wander;
            }
          snapr2:
            p->coord.x = (pZero2->s).coord.x + (0xC0 << 6);
            p->mode[2]++;
          }
        }
      }
    wander:
      {
        s32* a0 = (s32*)((u8*)p + 0xb4);
        s32* w5;
        s32 px7 = p->coord.x;
        s32 home = *a0;
        s32 d7 = px7 - home;
        w5 = a0;
        asm("" : "+r"(w5));
        if (d7 > 0) {
          if (d7 > (0xA0 << 8)) {
            goto clampit;
          }
          goto motioncheck;
        }
        if (home - px7 > (0xA0 << 8)) {
        clampit:
          {
            s32 px8 = p->coord.x;
            s32 h2 = *w5;
            if (px8 > h2) {
              p->coord.x = h2 + (0xA0 << 8);
            } else {
              p->coord.x = h2 + -0xA000;
            }
          }
          {
            struct Zero* z7 = pZero2;
            s32 px9 = p->coord.x;
            s32 d8;
            u32 nm;
            d8 = px9 - (z7->s).coord.x;
            asm volatile("" ::"r"(d8));
            if (d8 > 0) {
              if (d8 <= ({ s32 lim13 = 0x2FFF; asm("" : "+r"(lim13)); lim13; })) {
                goto settwo;
              }
              goto setthree;
            }
            if ((z7->s).coord.x - px9 > ({ s32 lim14 = 0x2FFF; asm("" : "+r"(lim14)); lim14; })) {
              goto setthree;
            }
            settwo:
            nm = 2;
            goto stnm;
            setthree:
            nm = 3;
            stnm:
            p->mode[2] = nm;
          }
        }
      }
    motioncheck:
      if (p->mode[2] == 2 && p->motion.cmdIdx == 0) {
        SetMotion((struct Entity*)p, 0xEA << 7);
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 2: {
      s8* m71 = (s8*)((u8*)p + 0x71);
      zv = *m71;
      if (zv == 0) {
        goto exitset2;
      }
      UpdateEntityAnim((struct Entity*)p);
      if (*m71 != 7) {
        break;
      }
      goto exitset;
    }
    case 3:
      SetMotion((struct Entity*)p, 0x750B);
      UpdateEntityAnim((struct Entity*)p);
      p->mode[2]++;
      break;
    case 4:
      p->mode[2]++;
      FALLTHROUGH;
    case 5: {
      s32 home2;
      UpdateEntityAnim((struct Entity*)p);
      home2 = *(s32*)((u8*)p + 0xb4);
      {
        register s32 sum5 asm("r0");
        s32 px10;
        sum5 = home2 + (0xA0 << 8);
        px10 = p->coord.x;
        if (px10 == sum5) {
          if ((pZero2->s).coord.x >= home2 + (0xD0 << 8)) {
            break;
          }
          goto exitset;
        }
        if ((pZero2->s).coord.x <= px10 + -0x3000) {
          break;
        }
      }
    exitset:
      zv = 0;
    exitset2:
      p->mode[1] = 2;
      p->mode[2] = zv;
      break;
    }
  }
}

static bool8 FUN_0808effc(Claveker* p) { return TRUE; }

INCASM("asm/enemy/claveker_e.inc");

static bool8 FUN_0808f158(Claveker* p) { return TRUE; }

static void FUN_0808f15c(Claveker* p) {
  if (p->mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[2]);
    p->mode[2]++;
  }
  if (isKilled(p->elfx)) {
    p->elfx = NULL;
    p->mode[1] = 0, p->mode[2] = 0;
  }
}

static bool8 FUN_0808f198(Claveker* p) { return TRUE; }

static void FUN_0808f19c(Claveker* p) {}

static bool8 FUN_0808f1a0(Claveker* p) { return TRUE; }

static void FUN_0808f1a4(Claveker* p) {
  if (p->mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[2]);
    p->mode[2]++;
  }
  if (isKilled(p->elfx)) {
    p->elfx = NULL;
    p->mode[1] = 0, p->mode[2] = 0;
  }
}

static bool8 FUN_0808f1e0(Claveker* p) {
  if (p->elfx == NULL && ((p->body).status & BODY_STATUS_WHITE)) {
    p->elfx = ApplyElementEffect(0, (void*)p, &sElementCoord);
    if (p->elfx != NULL) {
      if ((p->body).elemented == ELEMENT_THUNDER) {
        p->mode[1] = 3, p->mode[2] = 0;
      } else if ((p->body).elemented == ELEMENT_ICE) {
        p->mode[1] = 5, p->mode[2] = 0;
      }
    }
  }
  return TRUE;
}

static void Claveker_OnCollision(struct Body* body, Coords32* c, Coords32* _) {
  const u8 atktype = (body->enemy)->processing->atkType;
  if ((atktype == ATK_UNK3) || (atktype == ATK_UNK14) || (atktype == ATK_UNK15)) {
    Claveker* p = (Claveker*)body->parent;
    if ((p->body).status & BODY_STATUS_DEAD) {
      if ((p->coord).x < c->x) {
        p->unk_bb = 0xFF;
      } else {
        p->unk_bb = 0xFE;
      }
    }
  }
}

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(11), PIXEL(30), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(11), PIXEL(30), PIXEL(22)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(11), PIXEL(30), PIXEL(22)},
    },
};

static const Coords32 sElementCoord = {PIXEL(0), PIXEL(12)};
