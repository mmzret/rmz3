#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "overworld.h"

void CarrybeeG_Init(struct Enemy* p);
void CarrybeeG_Update(struct Enemy* p);
void CarrybeeG_Die(struct Enemy* p);
void CarrybeeG_Disappear(struct Enemy* p);

// clang-format off
const EnemyRoutine gCarrybeeGRoutine = {
    [ENTITY_INIT] =      CarrybeeG_Init,
    [ENTITY_UPDATE] =    CarrybeeG_Update,
    [ENTITY_DIE] =       CarrybeeG_Die,
    [ENTITY_DISAPPEAR] = CarrybeeG_Disappear,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

struct Enemy* FUN_0808a854(Coords32* c) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_CARRYBEE_G);
    (p->s).coord = *c;
    (p->s).work[0] = 0;
  }
  return p;
}

struct Enemy* FUN_0808a8b0(struct Entity* e) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_CARRYBEE_G);
    (p->s).work[0] = 1;
    (p->s).unk_28 = e;
  }
  return p;
}

static const EnemyFunc sUpdates1[5];
static const EnemyFunc sUpdates2[5];

INCASM("asm/enemy/carrybee_g_a.inc");

extern const EnemyFunc sUpdates1[5];
extern const EnemyFunc sUpdates2[5];
void CarrybeeG_Die(struct Enemy* p);

void CarrybeeG_Update(struct Enemy* p) {
  struct Entity* par;
  u8* t;
  if (((p->body).status & BODY_STATUS_DEAD) && (p->s).work[0] == 0) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    CarrybeeG_Die(p);
    return;
  }
  (sUpdates1[(p->s).mode[1]])(p);
  if ((p->s).work[0] != 0) {
    if (IsFrozen(&p->s)) {
      par = (p->s).unk_28;
      if (par->mode[0] > 2) {
        (p->body).status = 0;
        (p->body).prevStatus = 0;
        (p->body).invincibleTime = 0;
        (p->s).flags &= ~COLLIDABLE;
        (p->s).flags &= ~DISPLAY;
        SET_ENEMY_ROUTINE(p, ENTITY_DIE);
        (p->s).work[1] = 1;
        return;
      } else if (par->mode[0] > 1) {
        s32 blink;
        (p->s).coord = par->coord;
        blink = (p->s).work[2] + 1;
        (p->s).work[2] = blink;
        blink &= 0xff;
        if (blink & 1) {
          (p->s).flags |= DISPLAY;
        } else {
          (p->s).flags &= ~DISPLAY;
        }
        (p->body).status = 0;
        (p->body).prevStatus = 0;
        (p->body).invincibleTime = 0;
        (p->s).flags &= ~COLLIDABLE;
        UpdateSpriteAnimation(p);
      }
    }
  }
  if (IsFrozen(&p->s)) {
    return;
  }
  if ((p->s).work[0] != 0) {
    goto dispatch2;
  }
  {
    struct Entity** s = (struct Entity**)((u8*)p + 0xbc);
    if (*s != NULL) {
      if ((*s)->mode[0] > 1) {
        *s = NULL;
      }
      t = (u8*)((u8*)p + 0xc0);
      if (*t == 0 || --*t == 0) {
        *(u8*)((u8*)*s + 0x25) = 0x18;
      }
    }
  }
  if ((p->s).unk_2c != NULL) {
    if (((p->s).unk_2c)->mode[0] > 1) {
      (p->s).unk_2c = NULL;
    }
    t = (u8*)((u8*)p + 0xc1);
    if (*t == 0 || --*t == 0) {
      *(u8*)((u8*)(p->s).unk_2c + 0x25) = 0x18;
    }
  }
  if ((p->s).unk_28 != NULL) {
    if (((p->s).unk_28)->mode[0] > 1) {
      (p->s).unk_28 = NULL;
    }
    t = (u8*)((u8*)p + 0xc2);
    if (*t == 0 || --*t == 0) {
      *(u8*)((u8*)(p->s).unk_28 + 0x25) = 0x18;
    }
  }
dispatch2:
  (sUpdates2[(p->s).mode[1]])(p);
}

INCASM("asm/enemy/carrybee_g_b.inc");

void CarrybeeG_Disappear(struct Enemy* p) {
  if ((p->s).work[0] == 0 && *(u8*)((u8*)p + 0xc3) == 1) {
    gOverworld.work.raw[4]--;
  }
  DeleteEnemy(&p->s);
}

bool8 FUN_0808af78(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/carrybee_g_c.inc");

bool8 FUN_0808b008(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/carrybee_g_d.inc");

bool8 FUN_0808b108(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/carrybee_g_e.inc");

bool8 FUN_0808b2b0(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/carrybee_g_f.inc");

bool8 FUN_0808b418(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/carrybee_g_g.inc");

void nop_0808b534(struct Enemy* p) {}

bool8 FUN_0808af78(struct Enemy* p);
bool8 FUN_0808b008(struct Enemy* p);
bool8 FUN_0808b108(struct Enemy* p);
bool8 FUN_0808b2b0(struct Enemy* p);
bool8 FUN_0808b418(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[5] = {
    (EnemyFunc)FUN_0808af78,
    (EnemyFunc)FUN_0808b008,
    (EnemyFunc)FUN_0808b108,
    (EnemyFunc)FUN_0808b2b0,
    (EnemyFunc)FUN_0808b418,
};
// clang-format on

void FUN_0808af7c(struct Enemy* p);
void carrybeeg_0808b00c(struct Enemy* p);
void FUN_0808b10c(struct Enemy* p);
void FUN_0808b2b4(struct Enemy* p);
void FUN_0808b41c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[5] = {
    FUN_0808af7c,
    carrybeeg_0808b00c,
    FUN_0808b10c,
    FUN_0808b2b4,
    FUN_0808b41c,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[9] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(7), PIXEL(22), PIXEL(19)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 7,
      layer : 0x00000001,
      range : {PIXEL(30), -PIXEL(4), PIXEL(69), PIXEL(39)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 6,
      range : {PIXEL(30), -PIXEL(4), PIXEL(69), PIXEL(39)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 5,
      layer : 0x00000001,
      range : {-PIXEL(36), -PIXEL(7), PIXEL(62), PIXEL(22)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 4,
      range : {-PIXEL(36), -PIXEL(7), PIXEL(62), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {-PIXEL(18), PIXEL(10), PIXEL(26), PIXEL(11)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 2,
      range : {-PIXEL(18), PIXEL(10), PIXEL(26), PIXEL(11)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(6), PIXEL(23), PIXEL(57), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(6), PIXEL(23), PIXEL(57), PIXEL(16)},
    },
};
