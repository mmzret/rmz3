#include "collision.h"
#include "enemy.h"
#include "global.h"

struct VFX* FUN_080c2f3c(struct Coord* c, u8 mode);

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 buffer[4];          // 0xB4
  Coords32 c_b8;         // 0xB8
  void* enti_c0;         // 0xC0, Entity*
} Mothjiro;

bool8 FUN_08088ae0(Mothjiro* p);
static_assert(sizeof(Mothjiro) == sizeof(struct Enemy));

static const struct Collision sCollisions[3];

void Mothjiro_Init(Mothjiro* p);
void Mothjiro_Update(Mothjiro* p);
void Mothjiro_Die(Mothjiro* p);

// clang-format off
const EnemyRoutine gMothjiroRoutine = {
    [ENTITY_INIT] =      (void*)Mothjiro_Init,
    [ENTITY_UPDATE] =    (void*)Mothjiro_Update,
    [ENTITY_DIE] =       (void*)Mothjiro_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

Mothjiro* Unused_CreateMothjiro(Coords32* c, u8 r1) {
  Mothjiro* p = (Mothjiro*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_MOTHJIRO);
    p->coord = *c;
    p->work[0] = r1;
  }
  return p;
}

INCASM("asm/enemy/mothjiro_a.inc");

static bool8 (*const sUpdates1[7])(Mothjiro*);
static void (*const sUpdates2[7])(Mothjiro*);
bool8 mothjiro_08088a74(Mothjiro* p);

void Mothjiro_Update(Mothjiro* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    Mothjiro_Die(p);
    return;
  }

  (sUpdates1[p->mode[1]])((void*)p);
  mothjiro_08088a74(p);
  if (p->enti_c0 == NULL) {
    if (IsFrozen(p)) {
      return;
    }
    if (p->enti_c0 == NULL) {
      goto dispatch2;
    }
  }
  if (isKilled(p->enti_c0)) {
    SetDDP(&p->body, &sCollisions[1]);
    p->enti_c0 = NULL;
  }
  return;

dispatch2:
  (sUpdates2[p->mode[1]])((void*)p);
}

INCASM("asm/enemy/mothjiro_b.inc");

bool8 nop_080881d8(Mothjiro* p) { return TRUE; }

void mothjiro_080881dc(Mothjiro* p) {
  switch (p->mode[2]) {
    case 0: {
      SetMotion((struct Entity*)p, 0x6B00);
      SetDDP(&p->body, &sCollisions[1]);
      p->work[2] = RANDOM(RNG_0202f388) & 1;
      {
        u8 t = p->work[0];
        if (t == 0) {
          SET_XFLIP(p, t);
        } else {
          SET_XFLIP(p, 1);
        }
      }
      p->work[3] = 0;
      p->mode[3] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register u8 w3 asm("r5");
      u8 t2 = p->work[0];
      if (t2 == 0) {
        register u32 fl asm("r3");
        register u32 five asm("r5");
        register u32 sh asm("r0");
        register u32 nf asm("r1");
        u32 f2;
        fl = p->flags;
        asm("" : "+r"(fl));
        five = 0x10;
        if ((fl & 0x10) == 0) {
          p->coord.x += -0x180;
          if (p->unk_coord.x - p->coord.x > 0xC000) {
            p->coord.x = p->unk_coord.x + -0xC000;
            sh = ((u32)fl << 24) >> 28;
            nf = 1;
            nf &= ~sh;
            if (nf != 0) {
              f2 = five;
              asm("" : "+r"(f2));
              f2 |= fl;
            } else {
              f2 = 0xEF & fl;
            }
            p->flags = f2;
            *((u8*)p + 0x4c) = nf;
            {
              u8* oa = (u8*)p + 0x4a;
              s32 ov;
              s32 m11;
              nf <<= 4;
              ov = *oa;
              m11 = -0x11;
              m11 &= ov;
              m11 |= nf;
              *oa = m11;
            }
          }
        } else {
          p->coord.x += 0x180;
          if (p->unk_coord.x - p->coord.x < 0) {
            p->coord.x = p->unk_coord.x;
            sh = ((u32)fl << 24) >> 28;
            nf = 1;
            nf &= ~sh;
            if (nf != 0) {
              f2 = fl;
              asm("" : "+r"(f2));
              f2 |= five;
            } else {
              f2 = 0xEF & fl;
            }
            p->flags = f2;
            *((u8*)p + 0x4c) = nf;
            {
              u8* oa = (u8*)p + 0x4a;
              s32 ov;
              s32 m11;
              nf <<= 4;
              ov = *oa;
              m11 = -0x11;
              m11 &= ov;
              m11 |= nf;
              *oa = m11;
            }
          }
        }
      } else {
        register u32 fl asm("r3");
        register u32 five asm("r5");
        register u32 sh asm("r0");
        register u32 nf asm("r1");
        u32 f2;
        fl = p->flags;
        asm("" : "+r"(fl));
        five = 0x10;
        if ((fl & 0x10) == 0) {
          p->coord.x += -0x180;
          if (p->coord.x - p->unk_coord.x < 0) {
            p->coord.x = p->unk_coord.x;
            sh = ((u32)fl << 24) >> 28;
            nf = 1;
            nf &= ~sh;
            if (nf != 0) {
              f2 = five;
              asm("" : "+r"(f2));
              f2 |= fl;
            } else {
              f2 = 0xEF & fl;
            }
            p->flags = f2;
            *((u8*)p + 0x4c) = nf;
            {
              u8* oa = (u8*)p + 0x4a;
              s32 ov;
              s32 m11;
              nf <<= 4;
              ov = *oa;
              m11 = -0x11;
              m11 &= ov;
              m11 |= nf;
              *oa = m11;
            }
          }
        } else {
          p->coord.x += 0x180;
          if (p->coord.x - p->unk_coord.x > 0xC000) {
            p->coord.x = p->unk_coord.x + 0xC000;
            sh = ((u32)fl << 24) >> 28;
            nf = 1;
            nf &= ~sh;
            if (nf != 0) {
              f2 = fl;
              asm("" : "+r"(f2));
              f2 |= five;
            } else {
              f2 = 0xEF & fl;
            }
            p->flags = f2;
            *((u8*)p + 0x4c) = nf;
            {
              u8* oa = (u8*)p + 0x4a;
              s32 ov;
              s32 m11;
              nf <<= 4;
              ov = *oa;
              m11 = -0x11;
              m11 &= ov;
              m11 |= nf;
              *oa = m11;
            }
          }
        }
      }
      {
        w3 = p->work[3];
        if (w3 <= 7) {
          register u8 w2 asm("r3");
          w2 = p->work[2];
          if (w2 == 0) {
            p->coord.y += -0x500;
            if (p->unk_coord.y - p->coord.y > 0xC00) {
              p->coord.y = p->unk_coord.y + -0xC00;
              {
                u8 nw = 1;
                nw ^= w2;
                p->work[2] = nw;
              }
              p->work[3] = w3 + 1;
            }
          } else {
            p->coord.y += 0x500;
            if (p->coord.y - p->unk_coord.y > 0xC00) {
              p->coord.y = p->unk_coord.y + 0xC00;
              {
                u8 nw = 1;
                nw ^= w2;
                p->work[2] = nw;
              }
              p->work[3] = w3 + 1;
            }
          }
        } else {
          register u8 w2 asm("r3");
          w2 = p->work[2];
          if (w2 == 0) {
            p->coord.y += -0x500;
            if (p->unk_coord.y - p->coord.y > 0x1800) {
              p->coord.y = p->unk_coord.y + -0x1800;
              {
                u8 nw = 1;
                nw ^= w2;
                p->work[2] = nw;
              }
              p->work[3] = w3 + 1;
            }
          } else {
            p->coord.y += 0x500;
            if (p->coord.y - p->unk_coord.y > 0x1800) {
              p->coord.y = p->unk_coord.y + 0x1800;
              {
                u8 nw = 1;
                nw ^= w2;
                p->work[2] = nw;
              }
              p->work[3] = w3 + 1;
            }
          }
          if (p->work[3] > 10) {
            p->work[3] = 0;
          }
        }
      }
      if ((u8)(++p->mode[3]) % 0xC == 0) {
        FUN_080c2f3c(&p->coord, (p->flags >> 4) & 1);
      }
      UpdateEntityAnim((struct Entity*)p);
      if (((s32 (*)(Mothjiro*))FUN_08088ae0)(p) != 0) {
        s32 dx, dy;
        s32 q1, q2, sq1, sq2, dist;
        dx = *(s32*)((u8*)p + 0xb8) - p->coord.x;
        dy = *(s32*)((u8*)p + 0xbc) - p->coord.y;
        q1 = dx >> 2;
        sq1 = q1;
        sq1 = sq1 * q1;
        asm volatile("" ::"l"(dx));
        q2 = dy >> 2;
        sq2 = q2;
        sq2 = sq2 * q2;
        dist = (u16)Sqrt(sq1 + sq2) << 2;
        if (dist <= 0x77FF) {
          *(s32*)((u8*)p + 0xb4) = dist;
          p->mode[1] = 1;
          p->mode[2] = 0;
        }
        asm volatile("" ::"l"(dx), "l"(dy));
      }
      asm volatile("" ::"r"(w3));
      break;
    }
  }
}

bool8 nop_080884a0(Mothjiro* p) { return TRUE; }

INCASM("asm/enemy/mothjiro_d.inc");

bool8 nop_080885f8(Mothjiro* p) { return TRUE; }

INCASM("asm/enemy/mothjiro_e.inc");

bool8 nop_0808889c(Mothjiro* p) { return TRUE; }

INCASM("asm/enemy/mothjiro_f.inc");

bool8 nop_08088a1c(Mothjiro* p) { return TRUE; }

void mothjiro_08088a20(Mothjiro* p) {
  if (p->mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[2]);
    p->mode[2]++;
  }
}

bool8 nop_08088a44(Mothjiro* p) { return TRUE; }

void nop_08088a48(Mothjiro* p) {}

bool8 nop_08088a4c(Mothjiro* p) { return TRUE; }

void mothjiro_08088a50(Mothjiro* p) {
  if (p->mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[2]);
    p->mode[2]++;
  }
}

INCASM("asm/enemy/mothjiro_g.inc");

Coords32* FUN_08012a64(Coords32* c);

bool8 FUN_08088ae0(Mothjiro* p) {
  Coords32* r = FUN_08012a64(&p->coord);
  if (r != NULL) {
    (p->c_b8).x = r->x;
    (p->c_b8).y = r->y;
    return TRUE;
  }
  return FALSE;
}

void Mothjiro_OnCollision(struct Body* body, Coords32* c, Coords32* _ UNUSED) {
  const u8 atktype = (body->enemy)->processing->atkType;
  if ((atktype == ATK_UNK3) || (atktype == ATK_UNK14) || (atktype == ATK_UNK15)) {
    Mothjiro* p = (Mothjiro*)body->parent;
    if ((p->body).status & BODY_STATUS_DEAD) {
      if ((p->coord).x < c->x) {
        p->work[1] = 0xFF;
      } else {
        p->work[1] = 0xFE;
      }
    }
  }
}

// --------------------------------------------

// clang-format off
static bool8 (*const sUpdates1[7])(Mothjiro*) = {
    nop_080881d8,
    nop_080884a0,
    nop_080885f8,
    nop_0808889c,
    nop_08088a1c,
    nop_08088a44,
    nop_08088a4c,
};
// clang-format on

void mothjiro_080881dc(Mothjiro* p);
void mothjiro_080884a4(Mothjiro* p);
void mothjiro_080885fc(Mothjiro* p);
void mothjiro_080888a0(Mothjiro* p);

// clang-format off
static void (*const sUpdates2[7])(Mothjiro*) = {
    (void*)mothjiro_080881dc,
    (void*)mothjiro_080884a4,
    (void*)mothjiro_080885fc,
    (void*)mothjiro_080888a0,
    (void*)mothjiro_08088a20,
    (void*)nop_08088a48,
    (void*)mothjiro_08088a50,
};
// clang-format on

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
      range : {PIXEL(0), -PIXEL(5), PIXEL(26), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(5), PIXEL(26), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(5), PIXEL(26), PIXEL(20)},
    },
};

static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(4)};
