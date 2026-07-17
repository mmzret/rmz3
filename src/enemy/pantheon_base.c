#include "collision.h"
#include "enemy.h"
#include "global.h"

static const EnemyFunc sDeads[2];
static const struct Collision sCollisions[25];

struct Enemy* FUN_0808a0ec(struct Entity* e) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_P_BASE);
    (p->s).work[0] = 0;
    (p->s).unk_28 = e;
  }
  return p;
}

void nop_0808a140(struct Enemy* p) {}

INCASM("asm/enemy/pantheon_base_a.inc");

void PantheonBase_Die(struct Enemy* p) {
  (sDeads[(p->s).mode[1]])(p);
}

void nop_0808a3f4(struct Enemy* p) {}


void pBase_0808a3f8(struct Enemy* p) {
  struct Entity** slot = (struct Entity**)((u8*)p + 0xb4);
  if (*slot == NULL || isKilled(*slot)) {
    *slot = NULL;
    SetDDP(&p->body, &sCollisions[0]);
    if (!IsFrozen(&p->s)) {
      (p->s).mode[1] = 1;
      (p->s).mode[2] = 0;
    }
  }
}

void pBase_0808a438(struct Enemy* p) {
  struct Entity* parent = (p->s).unk_28;
  switch ((p->s).mode[2]) {
    case 0:
      SetSpriteAnimation(p, MOTION(0x6d, 0));
      UpdateSpriteAnimation(p);
      SetDDP(&p->body, &sCollisions[3]);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      (p->s).coord.x = parent->coord.x;
      (p->s).coord.y = parent->coord.y;
      break;
  }
}

INCASM("asm/enemy/pantheon_base_b.inc");

void PantheonBase_Init(struct Enemy* p);
void PantheonBase_Update(struct Enemy* p);
void PantheonBase_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gPantheonBaseRoutine = {
    [ENTITY_INIT] =      PantheonBase_Init,
    [ENTITY_UPDATE] =    PantheonBase_Update,
    [ENTITY_DIE] =       PantheonBase_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void pBase_0808a3f8(struct Enemy* p);
void nop_0808a3f4(struct Enemy* p);

static const EnemyFunc sUpdates1[2] = {
    pBase_0808a3f8,
    nop_0808a3f4,
};

void pBase_0808a438(struct Enemy* p);
void pBase_0808a47c(struct Enemy* p);

static const EnemyFunc sUpdates2[2] = {
    pBase_0808a438,
    pBase_0808a47c,
};

// --------------------------------------------

void pBase_0808a514(struct Enemy* p);
void FUN_0808a5c8(struct Enemy* p);

static const EnemyFunc sDeads[2] = {
    pBase_0808a514,
    FUN_0808a5c8,
};

// --------------------------------------------

static const struct Collision sCollisions[25] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(19), -PIXEL(53), PIXEL(24), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {-PIXEL(1), -PIXEL(13), PIXEL(35), PIXEL(35)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(21), PIXEL(12), PIXEL(39)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 1,
      range : {-PIXEL(1), -PIXEL(18), PIXEL(35), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(23), PIXEL(12), PIXEL(31)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(35), -PIXEL(53), PIXEL(24), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {-PIXEL(1), -PIXEL(13), PIXEL(35), PIXEL(35)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(21), PIXEL(12), PIXEL(39)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 1,
      range : {-PIXEL(1), -PIXEL(18), PIXEL(35), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(23), PIXEL(12), PIXEL(31)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(43), -PIXEL(56), PIXEL(24), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {-PIXEL(1), -PIXEL(13), PIXEL(35), PIXEL(35)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(21), PIXEL(12), PIXEL(39)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 1,
      range : {-PIXEL(1), -PIXEL(18), PIXEL(35), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(23), PIXEL(12), PIXEL(31)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(3), -PIXEL(56), PIXEL(24), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {-PIXEL(1), -PIXEL(13), PIXEL(35), PIXEL(35)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(21), PIXEL(12), PIXEL(39)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 1,
      range : {-PIXEL(1), -PIXEL(18), PIXEL(35), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(23), PIXEL(12), PIXEL(31)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 4,
      layer : 0x00000001,
      range : {-PIXEL(5), -PIXEL(56), PIXEL(24), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {-PIXEL(1), -PIXEL(13), PIXEL(35), PIXEL(35)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(21), PIXEL(12), PIXEL(39)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 1,
      range : {-PIXEL(1), -PIXEL(18), PIXEL(35), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(23), PIXEL(12), PIXEL(31)},
    },
};

static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(16)};
static const u8 sInitModes[1] = {1};

static const u8 sCollisionIdxs[9] = {0, 5, 10, 5, 0, 15, 20, 15, 0};

// clang-format off
static const motion_t sMotions[10] = {
    MOTION(SM109_PANTHEON_BASE, 0x03),
    MOTION(SM109_PANTHEON_BASE, 0x04),
    MOTION(SM109_PANTHEON_BASE, 0x05),
    MOTION(SM109_PANTHEON_BASE, 0x06),
    MOTION(SM109_PANTHEON_BASE, 0x07),
    MOTION(SM109_PANTHEON_BASE, 0x08),
    MOTION(SM109_PANTHEON_BASE, 0x09),
    MOTION(SM109_PANTHEON_BASE, 0x0A),
    MOTION(SM109_PANTHEON_BASE, 0x0B),
    MOTION(SM109_PANTHEON_BASE, 0x02),
};
// clang-format on
