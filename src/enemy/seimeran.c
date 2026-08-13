#include "collision.h"
#include "element.h"
#include "enemy.h"
#include "global.h"

static const u8 sCollisionIdxs[16];
static const struct Collision sCollisions[15];

// Entity.work[0]
#define SEIMERAN_ROOT 0
#define SEIMERAN_CLONE 1
#define SEIMERAN_SEED 2

typedef struct {
  COLLISION_OBJECT_HDR;
  struct {
    struct Entity* elfx;  // 0xB4, Element Effect
    Coords32 c_b8;        // 0xB8
    u8 unk_c0;            // 0xC0
  } props;                // props (16bytes, offset: 0xB4..)
} Seimeran;
static_assert(sizeof(Seimeran) == sizeof(struct Enemy));

void Seimeran_Init(struct Enemy* p);
void Seimeran_Update(struct Enemy* p);
void Seimeran_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gSeimeranRoutine = {
    [ENTITY_INIT] =      (void*)Seimeran_Init,
    [ENTITY_UPDATE] =    (void*)Seimeran_Update,
    [ENTITY_DIE] =       (void*)Seimeran_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// 0x0808f27c
static struct Entity* CreateClone(struct Entity* q, s32 x, s32 y, u8 idx) {
  struct Entity* p = (struct Entity*)AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_SEIMERAN);
    p->work[0] = SEIMERAN_CLONE;
    (p->unk_coord).x = x;
    (p->coord).x = x, (p->coord).y = y;
    p->work[2] = idx;
    p->unk_28 = (void*)q;
  }
  return p;
}

// 0x0808f2e4
static void FUN_0808f2e4(s32 x, s32 y, u8 idx) {
  struct Entity* p = (struct Entity*)AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_SEIMERAN);
    p->work[0] = SEIMERAN_SEED;
    (p->coord).x = x, (p->coord).y = y;
    p->work[2] = idx;
  }
}

// 0x0808f344
static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {}

// 0x0808f348
static bool8 FUN_0808f348(Seimeran* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    if ((p->work[0] != SEIMERAN_SEED) && ((p->body).status & BODY_STATUS_SLASHED) && ((p->props).unk_c0 > 9)) {
      p->mode[1] = 1;
    } else {
      p->mode[1] = 0;
    }
    Seimeran_Die((struct Enemy*)p);
    return TRUE;
  }
  return FALSE;
}

void FUN_0808f728(struct Enemy* p);
void FUN_0808f72c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[8] = {
    (void*)FUN_0808f72c,
    (void*)FUN_0808f728,
    (void*)FUN_0808f728,
    (void*)FUN_0808f728,
    (void*)FUN_0808f728,
    (void*)FUN_0808f728,
    (void*)FUN_0808f728,
    (void*)FUN_0808f728,
}; // 0x083693D4
// clang-format on

void FUN_0808f7ac(struct Enemy* p);
void FUN_0808f824(struct Enemy* p);
void FUN_0808f8e0(struct Enemy* p);
void FUN_0808f934(struct Enemy* p);
void FUN_0808fa24(struct Enemy* p);
void FUN_0808fa70(struct Enemy* p);
void FUN_0808fb10(struct Enemy* p);
void FUN_0808fc10(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[8] = {
    (void*)FUN_0808f7ac,
    (void*)FUN_0808f824,
    (void*)FUN_0808f8e0,
    (void*)FUN_0808f934,
    (void*)FUN_0808fa24,
    (void*)FUN_0808fa70,
    (void*)FUN_0808fb10,
    (void*)FUN_0808fc10,
}; // 0x083693F4
// clang-format on

// 0x0808f3a8
static bool8 FUN_0808f3a8(Seimeran* p) {
  if ((p->work[0] != SEIMERAN_SEED) && (p->props).elfx == NULL) {
    switch (p->mode[3]) {
      case 0: {
        if (IsFrozen((void*)p)) {
          (sUpdates1[p->mode[1]])((void*)p);
          (sUpdates2[p->mode[1]])((void*)p);
          p->mode[3]++;
          UpdateSpriteAnimation(p);
          return TRUE;
        }
        break;
      }
      case 1: {
        if (IsFrozen((void*)p)) return TRUE;
        p->mode[3] = 0;
        break;
      }
    }
  }
  return FALSE;
}

static const Coords32 sElementCoord;

// 0x0808f424
static void FUN_0808f424(Seimeran* p) {
  if ((p->props).elfx == NULL && (p->work[0] != SEIMERAN_SEED) && (p->mode[1] != 5) && (p->mode[1] != 6) && ((p->body).status & BODY_STATUS_WHITE)) {
    (p->props).elfx = ApplyElementEffect(0, (Object*)p, &sElementCoord);
    if ((p->props).elfx != NULL) {
      p->mode[1] = 0, p->mode[2] = 0;
    }
  }
}

// --------------------------------------------

INCASM("asm/enemy/seimeran_a.inc");

void FUN_0808f72c(struct Enemy* p) {
  struct Entity** slot = (struct Entity**)&p->buffer[0];
  if (*slot == NULL || isKilled(*slot)) {
    u8* c;
    u8* t;
    u8 v;
    *slot = NULL;
    t = (u8*)p + 0xc0;
    v = *t;
    c = t;
    asm("" : "+l"(c));
    if (v == 0xC) {
      SetDDP(&p->body, &sCollisions[11]);
    } else {
      SetDDP(&p->body, &sCollisions[sCollisionIdxs[*c]]);
    }
    if (!IsFrozen(&p->s)) {
      if (*c == 0xC) {
        (p->s).mode[1] = 2;
        (p->s).mode[2] = 0;
      } else {
        (p->s).mode[1] = 1;
        (p->s).mode[2] = 3;
      }
    }
  }
}

INCASM("asm/enemy/seimeran_b.inc");

// --------------------------------------------

void maybeKillSeimeran(struct Enemy* p);
void FUN_0808fd88(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08369414[2] = {
    maybeKillSeimeran,
    FUN_0808fd88,
};

// --------------------------------------------

// 0x0836941c
static const struct Collision sCollisions[15] = {
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
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(7), PIXEL(18), PIXEL(17)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(7), PIXEL(15), PIXEL(17)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(9), PIXEL(18), PIXEL(21)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(9), PIXEL(15), PIXEL(21)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(11), PIXEL(18), PIXEL(25)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(11), PIXEL(15), PIXEL(25)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(13), PIXEL(18), PIXEL(29)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(13), PIXEL(15), PIXEL(29)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(16), PIXEL(18), PIXEL(35)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(15), PIXEL(35)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(17), PIXEL(18), PIXEL(38)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(17), PIXEL(15), PIXEL(38)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(15), PIXEL(15)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(15), PIXEL(15)},
    },
};

// 0x08369584
static const u8 sCollisionIdxs[16] = {1, 1, 3, 3, 5, 5, 7, 7, 9, 9, 11, 11, 11, 0, 0, 0};

// 0x08369594
static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(8)};

static const u8 sInitModes[4] = {1, 5, 7, 0};

// 0x083695a0
static const motion_t sMotions[1] = {
    MOTION(SM119_SEIMERAN, 5),
};
