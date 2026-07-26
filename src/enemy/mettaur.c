#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "zero.h"
#include "physics.h"
#include "vfx.h"

// 英語名で Metall, Mettaur の表記揺れがあるっぽい?

void MettaurSwim_Init(struct Enemy* p);
void MettaurSwim_Update(struct Enemy* p);
void MettaurSwim_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gMettaurRoutine = {
    [ENTITY_INIT] =      (void*)MettaurSwim_Init,
    [ENTITY_UPDATE] =    (void*)MettaurSwim_Update,
    [ENTITY_DIE] =       (void*)MettaurSwim_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};





void FUN_08089e60(struct Enemy* p);
void FUN_08089a00(struct Enemy* p);
void nop_08089268(struct Enemy* p);
void FUN_080892a4(struct Enemy* p);
void FUN_0808926c(struct Enemy* p);
// clang-format on

struct Entity* FUN_08088b4c(s32 x, s32 y, u8 kind) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_METTAUR);
    (p->coord).x = x, (p->coord).y = y;
    p->work[0] = kind;
  }
  return p;
}

static bool8 FUN_08088ba8(struct Entity* p) {
  s32 val = PushoutToUp1((p->coord).x, (p->coord).y + PIXEL(8));
  if (val < 0) return TRUE;
  return FALSE;
}

static const struct Collision sCollisions[8];
static const EnemyFunc sDeads[3];

INCASM("asm/enemy/mettaur_a.inc");

void CreateVFX62(struct Entity* e, struct Coord* c);

void FUN_08088d54(struct Enemy* p) {
  struct Coord c;
  c.x = (p->s).coord.x;
  c.y = (p->s).coord.y - PIXEL(20);
  CreateSmoke(2, &c);
  CreateVFX62(&p->s, &c);
}

INCASM("asm/enemy/mettaur_b.inc");

void MettaurSwim_Die(struct Enemy* p) {
  (sDeads[(p->s).mode[1]])((void*)p);
}

void FUN_08089218(struct Body* body) {
  struct Enemy* self = (struct Enemy*)body->parent;
  struct Entity* atkParent = (struct Entity*)(body->enemy)->parent;
  if (body->hitboxFlags & 8) {
    if (*(u16*)&atkParent->kind == 0x1206) {
      SET_ENEMY_ROUTINE(self, ENTITY_DIE);
      (self->s).mode[1] = 0;
    }
  }
  *(s32*)&self->buffer[0] = (pZero2->s).coord.x - (self->s).coord.x;
}

void nop_08089268(struct Enemy* p) {}


void FUN_0808926c(struct Enemy* p) {
  if (FUN_08088ba8((struct Entity*)p) == 0) {
    (p->s).mode[1] = 5;
    (p->s).mode[2] = 0;
  }
  if (((p->body).status & 0x00020001) == 0x00020001) {
    (p->s).mode[1] = 0xc;
    (p->s).mode[2] = 0;
  }
}

void FUN_080892a4(struct Enemy* p) {
  if (((p->body).status & 0x00020001) == 0x00020001) {
    (p->s).mode[1] = 0xc;
    (p->s).mode[2] = 0;
  }
}

INCASM("asm/enemy/mettaur_c.inc");

void FUN_08089a00(struct Enemy* p) {
  struct Entity* par = (p->s).unk_28;
  switch ((p->s).mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[4]);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      (p->s).coord.x = par->coord.x;
      (p->s).coord.y = par->coord.y;
      break;
  }
}

INCASM("asm/enemy/mettaur_d.inc");

void FUN_08089e60(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[0]);
      SetSpriteAnimation(p, MOTION(0xdd, 0xc));
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
      if ((p->s).motion.state == 3) {
        (p->s).mode[1] = 9;
        (p->s).mode[2] = 0;
      }
      break;
  }
}

INCASM("asm/enemy/mettaur_e.inc");

// --------------------------------------------

// 0x08368814
static const struct Collision sCollisions[8] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(6), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(16), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(8), PIXEL(16), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(24), PIXEL(16), PIXEL(6)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(24), PIXEL(16), PIXEL(6)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(6), PIXEL(16), PIXEL(16)},
    },
};

// --------------------------------------------

void FUN_0808926c(struct Enemy* p);
void FUN_080892a4(struct Enemy* p);
void nop_08089268(struct Enemy* p);

// clang-format off
static const EnemyFunc sInitializers[13] = {
    FUN_0808926c,
    FUN_0808926c,
    FUN_0808926c,
    FUN_0808926c,
    FUN_0808926c,
    FUN_080892a4,
    FUN_080892a4,
    nop_08089268,
    FUN_080892a4,
    nop_08089268,
    nop_08089268,
    nop_08089268,
    nop_08089268,
};
// clang-format on

// --------------------------------------------

void FUN_080892c4(struct Enemy* p);
void FUN_08089364(struct Enemy* p);
void FUN_080894a4(struct Enemy* p);
void FUN_0808959c(struct Enemy* p);
void FUN_08089694(struct Enemy* p);
void FUN_08089790(struct Enemy* p);
void FUN_080898bc(struct Enemy* p);
void FUN_08089a00(struct Enemy* p);
void FUN_08089a34(struct Enemy* p);
void FUN_08089b48(struct Enemy* p);
void FUN_08089c94(struct Enemy* p);
void FUN_08089e60(struct Enemy* p);
void FUN_08089f60(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates[13] = {
    FUN_080892c4,
    FUN_08089364,
    FUN_080894a4,
    FUN_0808959c,
    FUN_08089694,
    FUN_08089790,
    FUN_080898bc,
    FUN_08089a00,
    FUN_08089a34,
    FUN_08089b48,
    FUN_08089c94,
    FUN_08089e60,
    FUN_08089f60,
};
// clang-format on

// --------------------------------------------

void FUN_08089eb0(struct Enemy* p);
void FUN_08089f60(struct Enemy* p);
static void FUN_0808a068(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    (void*)FUN_08089eb0,
    (void*)FUN_08089f60,
    (void*)FUN_0808a068,
};

static void FUN_0808a068(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      Coords32 c;
      (p->s).flags &= ~DISPLAY;
      EXIT_BODY(p);
      c.x = (p->s).coord.x, c.y = (p->s).coord.y - PIXEL(8);
      CreateSmoke(1, &c);
      if ((p->s).work[0] == 2) {
        PlaySound(SE_UNK_31);
      } else {
        PlaySound(SE_ZAKO_EXPLODE);
      }
      (p->s).mode[2]++;
      break;
    }
    case 1: {
      SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
      break;
    }
  }
}

// --------------------------------------------

// 0x08368948
static const u8 sInitModes[6] = {0, 6, 9, 0, 7, 0};

// 0x0836894e
static const motion_t sMotions[4] = {
    MOTION(SM221_METTAUR, 0),
    MOTION(SM000_BATTLE_EFFECT, 6),
    MOTION(SM000_BATTLE_EFFECT, 9),
    MOTION(SM221_METTAUR, 0),
};
