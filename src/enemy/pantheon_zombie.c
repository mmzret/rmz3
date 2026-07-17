#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "element.h"

static const EnemyFunc sUpdates1[8];
static const EnemyFunc sUpdates2[8];
static const EnemyFunc sDeads[3];
static const struct Collision sCollisions[8];
static const u8 sInitModes[4];
static const Coords32 sElementCoord;

INCASM("asm/enemy/pantheon_zombie_a.inc");

void FUN_0807fd84(struct Body* body) {
  struct Enemy* self = (struct Enemy*)body->parent;
  if ((body->hitboxFlags & 0x800) && (self->s).mode[1] != 4) {
    (self->s).mode[1] = 4;
    (self->s).mode[2] = 0;
  }
}

void PantheonZombie_Die(struct Enemy* p);

bool8 FUN_0807fda8(struct Enemy* p) {
  if ((p->body).status & 0x200) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    if ((p->body).status & 0x20000) {
      (p->s).mode[1] = 2;
    } else {
      (p->s).mode[1] = 0;
    }
    PantheonZombie_Die(p);
    return TRUE;
  }
  return FALSE;
}

void FUN_0807fdf8(struct Enemy* p) {
  if (*(struct VFX**)&p->buffer[0] == NULL && ((p->body).status & 1)) {
    struct VFX* e = ApplyElementEffect(0, &p->s, &sElementCoord);
    *(struct VFX**)&p->buffer[0] = e;
    if (e != NULL) {
      (p->s).mode[1] = 0;
      (p->s).mode[2] = 0;
    }
  }
}

void PantheonZombie_Update(struct Enemy* p);
extern const u8 sInitModes[4];

void PantheonZombie_Init(struct Enemy* p) {
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  INIT_BODY(p, sCollisions, 20, (void*)FUN_0807fd84);
  *(u32*)&p->buffer[0] = 0;
  p->buffer[4] = 0;
  PantheonZombie_Update(p);
}

void PantheonZombie_Update(struct Enemy* p) {
  if (*(u32*)((u8*)(p->s).unk_28 + 0xc0) & 0x100) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    (p->s).mode[1] = 1;
    PantheonZombie_Die(p);
  } else {
    if (FUN_0807fda8(p)) return;
    FUN_0807fdf8(p);
    (sUpdates1[(p->s).mode[1]])(p);
    (sUpdates2[(p->s).mode[1]])(p);
  }
}

void PantheonZombie_Die(struct Enemy* p) {
  (sDeads[(p->s).mode[1]])(p);
}

void nop_0807ff3c(struct Enemy* p) {}


void FUN_0807ff40(struct Enemy* p) {
  u32 status = (p->body).status;
  if (status & BODY_STATUS_WHITE) {
    if (status & BODY_STATUS_RECOILED) {
      (p->s).mode[1] = 7;
    } else {
      (p->s).mode[1] = 6;
    }
    (p->s).mode[2] = 0;
  }
}

void FUN_0807ff6c(struct Enemy* p) {
  u32 status = (p->body).status;
  if (status & BODY_STATUS_WHITE) {
    if (status & BODY_STATUS_RECOILED) {
      (p->s).mode[1] = 7;
      (p->s).mode[2] = 0;
    }
  }
}

void FUN_0807ff94(struct Enemy* p) {
  if (!((p->body).status & BODY_STATUS_BINDING)) {
    (p->s).mode[1] = 5;
    (p->s).mode[2] = 0;
  }
}

void FUN_0807ffb0(struct Enemy* p) {
  struct Entity** slot = (struct Entity**)((u8*)p + 0xb4);
  if (*slot == NULL || isKilled(*slot)) {
    *slot = NULL;
    (p->s).mode[1] = 1;
    (p->s).mode[2] = 0;
  }
}

INCASM("asm/enemy/pantheon_zombie_b.inc");

void FUN_08080610(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[1]);
      (p->s).work[2] = 0x10;
      SetSpriteAnimation(p, MOTION(0x4c, 2));
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      if (--(p->s).work[2] == 0) {
        (p->s).mode[1] = 1;
        (p->s).mode[2] = 0;
      }
      if (p->buffer[4] != 0) {
        (p->s).coord.y += 0x20;
      }
      UpdateSpriteAnimation(p);
      break;
  }
}

INCASM("asm/enemy/pantheon_zombie_c.inc");

void PantheonZombie_Init(struct Enemy* p);
void PantheonZombie_Update(struct Enemy* p);
void PantheonZombie_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gPantheonZombieRoutine = {
    [ENTITY_INIT] =      PantheonZombie_Init,
    [ENTITY_UPDATE] =    PantheonZombie_Update,
    [ENTITY_DIE] =       PantheonZombie_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_0807ffb0(struct Enemy* p);
void FUN_0807ff40(struct Enemy* p);
void nop_0807ff3c(struct Enemy* p);
void FUN_0807ff6c(struct Enemy* p);
void FUN_0807ff94(struct Enemy* p);
void FUN_0807ff6c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[8] = {
    FUN_0807ffb0,
    FUN_0807ff40,
    nop_0807ff3c,
    FUN_0807ff6c,
    FUN_0807ff94,
    FUN_0807ff6c,
    nop_0807ff3c,
    nop_0807ff3c,
};
// clang-format on

void FUN_0807ffd8(struct Enemy* p);
void FUN_08080054(struct Enemy* p);
void FUN_0808027c(struct Enemy* p);
void FUN_08080324(struct Enemy* p);
void FUN_080803dc(struct Enemy* p);
void FUN_080804a8(struct Enemy* p);
void FUN_08080610(struct Enemy* p);
void FUN_08080734(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[8] = {
    FUN_0807ffd8,
    FUN_08080054,
    FUN_0808027c,
    FUN_08080324,
    FUN_080803dc,
    FUN_080804a8,
    FUN_08080610,
    FUN_08080734,
};
// clang-format on

void FUN_08080674(struct Enemy* p);
void FUN_080806e0(struct Enemy* p);
void FUN_08080734(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    FUN_08080674,
    FUN_080806e0,
    FUN_08080734,
};

// --------------------------------------------

static const struct Collision sCollisions[8] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(4), -PIXEL(16), PIXEL(14), PIXEL(32)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(4), -PIXEL(16), PIXEL(14), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      unk_0a : 0x21,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(2), -PIXEL(16), PIXEL(22), PIXEL(32)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(2), -PIXEL(16), PIXEL(22), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      unk_0a : 0x21,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(2), -PIXEL(16), PIXEL(64), PIXEL(64)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(2), -PIXEL(16), PIXEL(22), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(4), -PIXEL(16), PIXEL(14), PIXEL(32)},
    },
};

static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(16)};
static const u8 sInitModes[4] = {2, 0, 0, 0};
