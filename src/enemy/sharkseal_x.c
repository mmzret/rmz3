#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "mod.h"
#include "overworld.h"

typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  s32 x_b4;               // 0xB4
  u8 unk_b8[4];           // 0xB8
  u8 xflip_bc;            // 0xBC
  u8 unk_bd;              // 0xBD
  u8 unk_be;              // 0xBE
  u8 unk_bf;              // 0xBF
  struct Entity* unk_c0;  // 0xC0
} SharksealX;
static_assert(sizeof(SharksealX) == sizeof(struct Enemy));

static const struct Collision sCollisions[];
SharksealX* forceWaterLanding(SharksealX* p);

static void SharksealX_Init(SharksealX* p);
void SharksealX_Update(SharksealX* p);
void SharksealX_Die(SharksealX* p);

// clang-format off
const EnemyRoutine gSharksealXRoutine = {
    [ENTITY_INIT] =      (void*)SharksealX_Init,
    [ENTITY_UPDATE] =    (void*)SharksealX_Update,
    [ENTITY_DIE] =       (void*)SharksealX_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// 0x08070028
static struct Entity* Unused_CreateSharksealX(Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_SHARKSEAL_X);
    p->coord = *c, p->work[0] = kind;
  }
  return p;
}

static void SharksealX_OnCollision(struct Body* body, Coords32* c1, Coords32* _ UNUSED);

static void SharksealX_Init(SharksealX* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  if (FLAG(gSystemSavedata.flags, MOD_121) && !FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
    _INIT_BODY(p, sCollisions, 10);
  } else {
    _INIT_BODY(p, sCollisions, 6);
  }
  SET_BODY_INTERSECT_HANDLER(p, SharksealX_OnCollision);

  if (gOverworld.sea > (p->coord).y) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  p->x_b4 = (p->coord).x;
  (&p->d)->x = (&p->d)->y = 0;
  p->unk_c0 = NULL;
  p->unk_bd = 0;
  p->x_b4 = (p->coord).x;
  (p->unk_coord).y = (p->coord).y;
  (&p->d)->x = (&p->d)->y = 0;
  p->xflip_bc = FALSE;
  if (IsFrozen(p)) {
    SetSpriteAnimation(p, MOTION(SM024_SHARKSEAL_X, 0));
    UpdateSpriteAnimation(p);
  }
  p->unk_bf = 0;
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 1, p->mode[2] = 0, p->mode[3] = 0;
  SharksealX_Update(p);
}

INCASM("asm/enemy/sharkseal_x_a.inc");

bool8 FUN_080707d0(SharksealX* p) { return TRUE; }

void nop_080707d4(SharksealX* p) {}

bool8 FUN_080707d8(SharksealX* p) { return TRUE; }

INCASM("asm/enemy/sharkseal_x_b.inc");

bool8 FUN_080708dc(SharksealX* p) { return TRUE; }

void sharksealxMode2(SharksealX* p) {
  switch (p->mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(SM024_SHARKSEAL_X, 0));
      SetDDP(&p->body, &sCollisions[0]);
      (&p->d)->x = (&p->d)->y = 0;
      SET_XFLIP(p, p->xflip_bc);
      p->work[2] = 24;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      (p->d).y += PIXEL(1) / 8;
      if ((p->d).y > PIXEL(1)) (p->d).y = PIXEL(1);
      p->coord.y += (p->d).y;
      forceWaterLanding(p);
      if (p->work[2] == 0 || --p->work[2] == 0) {
        p->mode[1] = 3, p->mode[2] = 0;
      }
      break;
    }
  }
}

bool8 FUN_08070990(SharksealX* p) { return TRUE; }

INCASM("asm/enemy/sharkseal_x_c.inc");

bool8 FUN_08070c68(SharksealX* p) { return TRUE; }

INCASM("asm/enemy/sharkseal_x_d.inc");

bool8 FUN_08070f3c(SharksealX* p) { return TRUE; }

void sharksealxMode5(SharksealX* p) {
  if (p->mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[4]);
    p->mode[2]++;
  }
  if (isKilled(p->unk_c0)) {
    SetDDP(&p->body, &sCollisions[0]);
    p->unk_c0 = NULL;
    p->mode[1] = 1, p->mode[2] = 0;
  }
}

bool8 FUN_08070f8c(SharksealX* p) { return TRUE; }

void nop_08070f90(SharksealX* p) {}

bool8 FUN_08070f94(SharksealX* p) { return TRUE; }

INCASM("asm/enemy/sharkseal_x_e.inc");

bool8 FUN_080707d0(SharksealX* p);
bool8 FUN_080707d8(SharksealX* p);
bool8 FUN_080708dc(SharksealX* p);
bool8 FUN_08070990(SharksealX* p);
bool8 FUN_08070c68(SharksealX* p);
bool8 FUN_08070f3c(SharksealX* p);
bool8 FUN_08070f8c(SharksealX* p);
bool8 FUN_08070f94(SharksealX* p);

// clang-format off
static bool8 (*const sSharksealXUpdates1[8])(SharksealX*) = {
    FUN_080707d0,
    FUN_080707d8,
    FUN_080708dc,
    FUN_08070990,
    FUN_08070c68,
    FUN_08070f3c,
    FUN_08070f8c,
    FUN_08070f94,
}; // 0x08366A04
// clang-format on

void nop_080707d4(SharksealX* p);
void sharksealxMode1(SharksealX* p);
void sharksealxMode2(SharksealX* p);
void sharksealxMode3(SharksealX* p);
void sharksealxMode4(SharksealX* p);
void sharksealxMode5(SharksealX* p);
void nop_08070f90(SharksealX* p);
void sharksealxMode7(SharksealX* p);

// clang-format off
static void (*const sSharksealXUpdates2[8])(SharksealX*) = {
    nop_080707d4,
    sharksealxMode1,
    sharksealxMode2,
    sharksealxMode3,
    sharksealxMode4,
    sharksealxMode5,
    nop_08070f90,
    sharksealxMode7,
}; // 0x08366A24
// clang-format on

bool32 nop_080711d4(void* _ UNUSED) { return TRUE; }

// 0x080711d8
static void SharksealX_OnCollision(struct Body* body, Coords32* c1, Coords32* _ UNUSED) {
  const u8 atktype = (body->enemy)->processing->atkType;
  if ((atktype == ATK_UNK3) || (atktype == ATK_UNK14) || (atktype == ATK_UNK15)) {
    SharksealX* p = (SharksealX*)body->parent;
    if ((p->body).status & BODY_STATUS_DEAD) {
      if ((p->coord).x < c1->x) {
        p->unk_bf = 0xFF;
      } else {
        p->unk_bf = 0xFE;
      }
    }
  }
}

// 0x08071220
SharksealX* forceWaterLanding(SharksealX* p) {
  if (gOverworld.sea > (p->coord).y) {
    (p->coord).y = gOverworld.sea;
  }
}

// 0x08366A44
static const struct Collision sCollisions[5] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(5), PIXEL(0), PIXEL(30), PIXEL(9)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(5), PIXEL(0), PIXEL(32), PIXEL(11)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(4), PIXEL(1), PIXEL(18), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {-PIXEL(5), PIXEL(1), PIXEL(18), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(5), PIXEL(0), PIXEL(32), PIXEL(11)},
    },
};

static const Coords32 sElementCoord = {PIXEL(0), PIXEL(0)};  // 0x08366ABC
