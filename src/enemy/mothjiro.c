#include "collision.h"
#include "enemy.h"
#include "global.h"

static const struct Collision sCollisions[3];

void Mothjiro_Init(struct Enemy* p);
void Mothjiro_Update(struct Enemy* p);
void Mothjiro_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gMothjiroRoutine = {
    [ENTITY_INIT] =      Mothjiro_Init,
    [ENTITY_UPDATE] =    Mothjiro_Update,
    [ENTITY_DIE] =       Mothjiro_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct Enemy* CreateMothjiro(Coords32* c, u8 r1) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_MOTHJIRO);
    (p->s).coord = *c;
    (p->s).work[0] = r1;
  }
  return p;
}

INCASM("asm/enemy/mothjiro_a.inc");

static const EnemyFunc sUpdates1[7];
static const EnemyFunc sUpdates2[7];
void mothjiro_08088a74(struct Enemy* p);

void Mothjiro_Update(struct Enemy* p) {
  u32 dead = (p->body).status & BODY_STATUS_DEAD;
  struct Entity** slot;
  if (dead) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    Mothjiro_Die(p);
    return;
  }
  (sUpdates1[(p->s).mode[1]])(p);
  mothjiro_08088a74(p);
  slot = (struct Entity**)((u8*)p + 0xc0);
  if (*slot == NULL) {
    if (IsFrozen(&p->s)) {
      return;
    }
    if (*slot == NULL) {
      goto dispatch2;
    }
  }
  if (isKilled(*slot)) {
    SetDDP(&p->body, &sCollisions[1]);
    *slot = (struct Entity*)dead;
  }
  return;

dispatch2:
  (sUpdates2[(p->s).mode[1]])(p);
}

INCASM("asm/enemy/mothjiro_b.inc");

bool8 nop_080881d8(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/mothjiro_c.inc");

bool8 nop_080884a0(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/mothjiro_d.inc");

bool8 nop_080885f8(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/mothjiro_e.inc");

bool8 nop_0808889c(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/mothjiro_f.inc");

bool8 nop_08088a1c(struct Enemy* p) { return TRUE; }

void mothjiro_08088a20(struct Enemy* p) {
  if ((p->s).mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[2]);
    (p->s).mode[2]++;
  }
}

bool8 nop_08088a44(struct Enemy* p) { return TRUE; }

void nop_08088a48(struct Enemy* p) {}

bool8 nop_08088a4c(struct Enemy* p) { return TRUE; }

void mothjiro_08088a50(struct Enemy* p) {
  if ((p->s).mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[2]);
    (p->s).mode[2]++;
  }
}

INCASM("asm/enemy/mothjiro_g.inc");

struct Coord* FUN_08012a64(struct Coord* c);

bool8 FUN_08088ae0(struct Enemy* p) {
  struct Coord* r = FUN_08012a64(&(p->s).coord);
  if (r != NULL) {
    *(s32*)((u8*)p + 0xb8) = r->x;
    *(s32*)((u8*)p + 0xbc) = r->y;
    return TRUE;
  }
  return FALSE;
}

void FUN_08088b0c(struct Body* body, struct Coord* c) {
  u8 atkType = (body->enemy->processing)->atkType;
  if (atkType == 3 || atkType == 0xe || atkType == 0xf) {
    struct Enemy* self = (struct Enemy*)body->parent;
    if (*(u32*)((u8*)self + 0x8c) & 0x200) {
      if ((self->s).coord.x < c->x) {
        *(u8*)((u8*)self + 0x11) = 0xff;
      } else {
        *(u8*)((u8*)self + 0x11) = 0xfe;
      }
    }
  }
}

// --------------------------------------------


// clang-format off
static const EnemyFunc sUpdates1[7] = {
    (EnemyFunc)nop_080881d8,
    (EnemyFunc)nop_080884a0,
    (EnemyFunc)nop_080885f8,
    (EnemyFunc)nop_0808889c,
    (EnemyFunc)nop_08088a1c,
    (EnemyFunc)nop_08088a44,
    (EnemyFunc)nop_08088a4c,
};
// clang-format on

void mothjiro_080881dc(struct Enemy* p);
void mothjiro_080884a4(struct Enemy* p);
void mothjiro_080885fc(struct Enemy* p);
void mothjiro_080888a0(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[7] = {
    mothjiro_080881dc,
    mothjiro_080884a4,
    mothjiro_080885fc,
    mothjiro_080888a0,
    mothjiro_08088a20,
    nop_08088a48,
    mothjiro_08088a50,
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
