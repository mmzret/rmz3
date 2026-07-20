#include "collision.h"
#include "enemy.h"
#include "global.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 buffer[12];         // 0xB4
  void* enti_c0;         // 0xC0, Entity*
} Petatria;
static_assert(sizeof(Petatria) == sizeof(struct Enemy));

Petatria* Unused_CreatePetatria(Coords32* c, u8 mode) {
  Petatria* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_PETATRIA);
    p->coord = *c;
    p->work[0] = mode;
  }
  return p;
}

INCASM("asm/enemy/petatria_a.inc");

static const EnemyFunc sUpdates1[10];
static const EnemyFunc sUpdates2[10];
bool8 FUN_08091188(struct Enemy* p);
void Petatria_Die(Petatria* p);

void Petatria_Update(Petatria* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    Petatria_Die(p);
    return;
  }
  (sUpdates1[p->mode[1]])((void*)p);
  FUN_08091188((void*)p);
  if (IsFrozen(p)) {
    return;
  }
  if (p->enti_c0 != NULL) {
    if (!isKilled(p->enti_c0)) {
      return;
    }
    p->enti_c0 = NULL;
  }
  (sUpdates2[p->mode[1]])((void*)p);
}

INCASM("asm/enemy/petatria_b.inc");

bool8 FUN_080902a8(Petatria* p) {
  if ((p->body).status & BODY_STATUS_B3) {
    p->mode[1] = 4, p->mode[2] = 0;
  }
  return TRUE;
}

INCASM("asm/enemy/petatria_c.inc");

bool8 FUN_080906ec(Petatria* p) {
  if ((p->body).status & BODY_STATUS_B3) {
    p->mode[1] = 5, p->mode[2] = 0;
  }
  return TRUE;
}

INCASM("asm/enemy/petatria_d.inc");

bool8 FUN_08090b20(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/petatria_e.inc");

bool8 FUN_08090c60(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/petatria_f.inc");

bool8 FUN_08090da4(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/petatria_g.inc");

bool8 FUN_08090edc(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/petatria_h.inc");

bool8 FUN_08091068(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/petatria_i.inc");

bool8 FUN_08091150(struct Enemy* p) { return TRUE; }

void FUN_08091154(Petatria* p) {
  if (p->mode[2] == 0) p->mode[2] = 1;
}

bool8 FUN_08091168(struct Enemy* p) { return TRUE; }

void FUN_0809116c(struct Enemy* p) {}

bool8 FUN_08091170(struct Enemy* p) { return TRUE; }

void FUN_08091174(Petatria* p) {
  if (p->mode[2] == 0) p->mode[2] = 1;
}

bool8 FUN_08091188(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/petatria_j.inc");

void nop_0809127c(struct Enemy* p) {}

void Petatria_Init(struct Enemy* p);
void Petatria_Update(Petatria* p);
void Petatria_Die(Petatria* p);

// clang-format off
const EnemyRoutine gPetatriaRoutine = {
    [ENTITY_INIT] =      (void*)Petatria_Init,
    [ENTITY_UPDATE] =    (void*)Petatria_Update,
    [ENTITY_DIE] =       (void*)Petatria_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// clang-format off
static const EnemyFunc sUpdates1[10] = {
    (EnemyFunc)FUN_080902a8,
    (EnemyFunc)FUN_080906ec,
    (EnemyFunc)FUN_08090b20,
    (EnemyFunc)FUN_08090c60,
    (EnemyFunc)FUN_08090da4,
    (EnemyFunc)FUN_08090edc,
    (EnemyFunc)FUN_08091068,
    (EnemyFunc)FUN_08091150,
    (EnemyFunc)FUN_08091168,
    (EnemyFunc)FUN_08091170,
};
// clang-format on

void FUN_080902c8(struct Enemy* p);
void FUN_0809070c(struct Enemy* p);
void FUN_08090b24(struct Enemy* p);
void FUN_08090c64(struct Enemy* p);
void FUN_08090da8(struct Enemy* p);
void FUN_08090ee0(struct Enemy* p);
void FUN_0809106c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[10] = {
    FUN_080902c8,
    FUN_0809070c,
    FUN_08090b24,
    FUN_08090c64,
    FUN_08090da8,
    FUN_08090ee0,
    FUN_0809106c,
    (void*)FUN_08091154,
    FUN_0809116c,
    (void*)FUN_08091174,
};
// clang-format on

// --------------------------------------------

// 0x08369608
static const struct Collision sCollisions[12] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(16), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(16), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(17), -PIXEL(25), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(17), -PIXEL(25), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(16), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 1,
      range : {PIXEL(0), -PIXEL(29), PIXEL(10), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(10), PIXEL(26), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(17), -PIXEL(25), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 1,
      range : {PIXEL(3), -PIXEL(25), PIXEL(10), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(22), -PIXEL(25), PIXEL(14), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(16), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(16), PIXEL(26), PIXEL(26)},
    },
};

static const s32 s32_ARRAY_08369728[16] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

// clang-format off
// 0x08369768
static const motion_t sMotions1[6] = {
    MOTION(SM126_PETATRIA, 0),
    MOTION(SM126_PETATRIA, 1),
    MOTION(SM126_PETATRIA, 2),
    MOTION(SM126_PETATRIA, 3),
    MOTION(SM126_PETATRIA, 4),
    MOTION(SM126_PETATRIA, 5),
};
// clang-format on

static const s32 s32_ARRAY_08369774[6] = {
    PIXEL(1), PIXEL(2), PIXEL(5), PIXEL(5), PIXEL(2), PIXEL(1),
};
static const s32 s32_ARRAY_0836978c[6] = {
    PIXEL(1), PIXEL(1), PIXEL(2), PIXEL(5), PIXEL(5), PIXEL(2),
};

// clang-format off
static const motion_t sMotions2[6] = {
    MOTION(SM126_PETATRIA, 6),
    MOTION(SM126_PETATRIA, 7),
    MOTION(SM126_PETATRIA, 8),
    MOTION(SM126_PETATRIA, 9),
    MOTION(SM126_PETATRIA, 10),
    MOTION(SM126_PETATRIA, 11),
};
// clang-format on

static const s32 s32_ARRAY_083697b0[6] = {
    -PIXEL(1), -PIXEL(2), -PIXEL(5), -PIXEL(5), -PIXEL(2), -PIXEL(1),
};
static const s32 s32_ARRAY_083697c8[6] = {
    -PIXEL(1), -PIXEL(1), -PIXEL(2), -PIXEL(5), -PIXEL(5), -PIXEL(2),
};
