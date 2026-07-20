#include "collision.h"
#include "enemy.h"
#include "global.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 buffer[4];          // 0xB4
  Coords32 c_b8;         // 0xB8
  void* enti_c0;         // 0xC0, Entity*
} Mothjiro;
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
  Mothjiro* p = AllocEntityLast(gEnemyHeaderPtr);
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

  (sUpdates1[p->mode[1]])(p);
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
  (sUpdates2[p->mode[1]])(p);
}

INCASM("asm/enemy/mothjiro_b.inc");

bool8 nop_080881d8(Mothjiro* p) { return TRUE; }

INCASM("asm/enemy/mothjiro_c.inc");

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
