#include "boss/anubis.h"
#include "collision.h"
#include "element.h"
#include "enemy.h"
#include "global.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  void* elfx;            // 0xB4, Element FX
  u8 unk_b8;             // 0xB8
  u8 unk_b9[11];         // 0xB9
} PantheonZombie;
static_assert(sizeof(PantheonZombie) == sizeof(struct Enemy));

static const EnemyFunc sUpdates1[8];
static const EnemyFunc sUpdates2[8];
static const EnemyFunc sDeads[3];
static const struct Collision sCollisions[8];
static const u8 sInitModes[4];
static const Coords32 sElementCoord;

void PantheonZombie_Init(PantheonZombie* p);
void PantheonZombie_Update(PantheonZombie* p);
void PantheonZombie_Die(PantheonZombie* p);

// clang-format off
const EnemyRoutine gPantheonZombieRoutine = {
    [ENTITY_INIT] =      (void*)PantheonZombie_Init,
    [ENTITY_UPDATE] =    (void*)PantheonZombie_Update,
    [ENTITY_DIE] =       (void*)PantheonZombie_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void createPantheonZombie(Anubis* anubis, s32 x, s32 y) {
  PantheonZombie* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    anubis->pzombieCount++;
    INIT_ENEMY_ROUTINE(p, ENEMY_P_ZOMBIE);
    p->work[0] = 0;
    p->unk_28 = (void*)anubis;
    (p->coord).x = x, (p->coord).y = y;
  }
}

void PantheonZombie_OnCollision(struct Body* body, Coords32* c1, Coords32* c2) {
  PantheonZombie* p = (PantheonZombie*)body->parent;
  if ((body->hitboxFlags & BODY_STATUS_BINDING) && p->mode[1] != 4) {
    p->mode[1] = 4, p->mode[2] = 0;
  }
}

bool8 FUN_0807fda8(PantheonZombie* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    if ((p->body).status & BODY_STATUS_RECOILED) {
      p->mode[1] = 2;
    } else {
      p->mode[1] = 0;
    }
    PantheonZombie_Die(p);
    return TRUE;
  }
  return FALSE;
}

void FUN_0807fdf8(PantheonZombie* p) {
  if (p->elfx == NULL && ((p->body).status & BODY_STATUS_WHITE)) {
    p->elfx = ApplyElementEffect(0, (void*)p, &sElementCoord);
    if (p->elfx != NULL) {
      p->mode[1] = 0, p->mode[2] = 0;
    }
  }
}

void PantheonZombie_Init(PantheonZombie* p) {
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, sCollisions, 20, PantheonZombie_OnCollision);
  p->elfx = NULL;
  p->unk_b8 = 0;
  PantheonZombie_Update(p);
}

void PantheonZombie_Update(PantheonZombie* p) {
  Anubis* anubis = (Anubis*)p->unk_28;
  if (anubis->unk_c0 & 0x100) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    p->mode[1] = 1;
    PantheonZombie_Die(p);
  } else {
    if (FUN_0807fda8((void*)p)) return;
    FUN_0807fdf8((void*)p);
    (sUpdates1[p->mode[1]])((void*)p);
    (sUpdates2[p->mode[1]])((void*)p);
  }
}

void PantheonZombie_Die(PantheonZombie* p) { (sDeads[p->mode[1]])((void*)p); }

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

void FUN_0807ffb0(PantheonZombie* p) {
  if (p->elfx == NULL || isKilled(p->elfx)) {
    p->elfx = NULL;
    p->mode[1] = 1, p->mode[2] = 0;
  }
}

INCASM("asm/enemy/pantheon_zombie_b.inc");

void FUN_08080610(PantheonZombie* p) {
  switch (p->mode[2]) {
    case 0: {
      SetDDP(&p->body, &sCollisions[1]);
      p->work[2] = 16;
      SetSpriteAnimation(p, MOTION(SM076_PANTHEON_ZOMBIE, 2));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if (--p->work[2] == 0) {
        p->mode[1] = 1, p->mode[2] = 0;
      }
      if (p->unk_b8) p->coord.y += PIXEL(1) / 8;
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

INCASM("asm/enemy/pantheon_zombie_c.inc");

void FUN_0807ffb0(PantheonZombie* p);
void FUN_0807ff40(struct Enemy* p);
void nop_0807ff3c(struct Enemy* p);
void FUN_0807ff6c(struct Enemy* p);
void FUN_0807ff94(struct Enemy* p);
void FUN_0807ff6c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[8] = {
    (void*)FUN_0807ffb0,
    (void*)FUN_0807ff40,
    (void*)nop_0807ff3c,
    (void*)FUN_0807ff6c,
    (void*)FUN_0807ff94,
    (void*)FUN_0807ff6c,
    (void*)nop_0807ff3c,
    (void*)nop_0807ff3c,
};
// clang-format on

void FUN_0807ffd8(struct Enemy* p);
void FUN_08080054(struct Enemy* p);
void FUN_0808027c(struct Enemy* p);
void FUN_08080324(struct Enemy* p);
void FUN_080803dc(struct Enemy* p);
void FUN_080804a8(struct Enemy* p);
void FUN_08080610(PantheonZombie* p);
void FUN_08080734(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[8] = {
    (void*)FUN_0807ffd8,
    (void*)FUN_08080054,
    (void*)FUN_0808027c,
    (void*)FUN_08080324,
    (void*)FUN_080803dc,
    (void*)FUN_080804a8,
    (void*)FUN_08080610,
    (void*)FUN_08080734,
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
