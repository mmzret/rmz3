#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "mod.h"
#include "story.h"
#include "zero.h"

typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  s32 x;           // 0xB4
  bool8 xflip_b8;  // 0xB8
  u8 unk_b9;       // 0xB9
  u8 unk_ba;       // 0xBA
  u8 unk_bb;       // 0xBB
  u8 unk_bc;       // 0xBC
  u8 unk_bd;       // 0xBD
  u8 unk_be;       // 0xBE
  u8 unk_bf;       // 0xBF
  Entity* elfx;    // 0xC0, Element FX
} PantheonGuardian;
static_assert(sizeof(PantheonGuardian) == sizeof(struct Enemy));

static const struct Collision sCollisions[];
static const Coords32 Coord_08365b70;

void PantheonGuardian_OnCollision(struct Body* body, Coords32* c1, Coords32* c2);

// ------------------------------------------------------------------------------------------------------------------------------------

static void PantheonGuardian_Init(PantheonGuardian* p);
void PantheonGuardian_Update(PantheonGuardian* p);
void PantheonGuardian_Die(PantheonGuardian* p);

// clang-format off
const EnemyRoutine gPantheonGuardianRoutine = {
    [ENTITY_INIT] =      (void*)PantheonGuardian_Init,
    [ENTITY_UPDATE] =    (void*)PantheonGuardian_Update,
    [ENTITY_DIE] =       (void*)PantheonGuardian_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static void PantheonGuardian_Init(PantheonGuardian* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  if (FLAG(gSystemSavedata.flags, MOD_P_GUARDIAN_HP4) && !FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
    _INIT_BODY(p, sCollisions, 14);
  } else {
    _INIT_BODY(p, sCollisions, 10);
  }
  SET_BODY_INTERSECT_HANDLER(p, PantheonGuardian_OnCollision);
  p->x = (p->coord).x;
  (p->coord).y = FUN_08009f6c((p->coord).x, (p->coord).y);
  (p->d).x = (p->d).y = 0;
  p->elfx = NULL;
  p->xflip_b8 = 0;
  p->unk_b9 = 0;

  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  if (((pZero2->s).coord).x - (p->coord).x < 0) {
    p->mode[1] = 1, p->mode[2] = 0;
  } else {
    p->mode[1] = 2, p->mode[2] = 0;
  }
  PantheonGuardian_Update(p);
}

INCASM("asm/enemy/pantheon_guardian_a.inc");

void FUN_08063da0(PantheonGuardian* p) {
  if (*(u32*)((u8*)p + 0xbc) <= 0x2FFF) {
    p->mode[1] = 4;
    p->mode[2] = 0;
  }
  if (*(u32*)((u8*)p + 0x8c) & 1) {
    p->mode[1] = 5;
    p->mode[2] = 0;
  }
  if (*(u32*)((u8*)p + 0xc0) != 0) {
    p->mode[1] = 5;
    p->mode[2] = 0;
  }
  if (FUN_080098a4(p->coord.x, p->coord.y + 0x40) == 0) {
    p->mode[1] = 3;
    p->mode[2] = 0;
  }
  if (IsFrozen((struct Entity*)p)) {
    p->mode[1] = 0;
    p->mode[2] = 0;
  }
}

void doNothing_08063e10(PantheonGuardian* p) {
  if (IsFrozen((struct Entity*)p)) {
    p->mode[1] = 0;
    p->mode[2] = 0;
  }
}

void FUN_08063e28(PantheonGuardian* p) {
  if ((p->body).status & 1) {
    p->mode[1] = 5;
    p->mode[2] = 0;
  }
  if (*(struct Entity**)((u8*)p + 0xc0) != NULL) {
    p->mode[1] = 5;
    p->mode[2] = 0;
  }
  if (FUN_080098a4(p->coord.x, p->coord.y + 0x40) == 0) {
    p->mode[1] = 3;
    p->mode[2] = 0;
  }
  if (IsFrozen((struct Entity*)p)) {
    p->mode[1] = 0;
    p->mode[2] = 0;
  }
}

void FUN_08063e80(PantheonGuardian* p) {
  if ((p->body).status & 1) {
    p->mode[1] = 5;
    p->mode[2] = 0;
  }
  if (FUN_080098a4(p->coord.x, p->coord.y + 0x40) == 0) {
    p->mode[1] = 3;
    p->mode[2] = 0;
  }
  if (IsFrozen((struct Entity*)p)) {
    p->mode[1] = 0;
    p->mode[2] = 0;
  }
}

void FUN_08063ec8(PantheonGuardian* p) {
  if (*(struct Entity**)((u8*)p + 0xc0) != NULL) {
    p->mode[1] = 5;
    p->mode[2] = 0;
  }
  if (IsFrozen((struct Entity*)p)) {
    p->mode[1] = 0;
    p->mode[2] = 0;
  }
}

void FUN_08063ef4(PantheonGuardian* p) {
  if (FUN_080098a4(p->coord.x, p->coord.y + 0x40) == 0) {
    p->mode[1] = 3;
    p->mode[2] = 0;
  }
  if (IsFrozen((struct Entity*)p)) {
    p->mode[1] = 0;
    p->mode[2] = 0;
  }
}

void FUN_08063f28(PantheonGuardian* p) {
  if (p->mode[1] == 8) return;
  if (((p->body).status & 0x00020001) == 0x00020001) {
    p->mode[1] = 8;
    p->mode[2] = 0;
  }
}

INCASM("asm/enemy/pantheon_guardian_b.inc");

void FUN_08064444(PantheonGuardian* p) {
  if (p->mode[2] == 0) {
    SetMotion((struct Entity*)p, MOTION(0x14, 4));
    SetDDP(&p->body, &sCollisions[0]);
    p->mode[2]++;
  }
  UpdateEntityAnim((struct Entity*)p);
}

INCASM("asm/enemy/pantheon_guardian_c.inc");

void FUN_08063da0(PantheonGuardian* p);
void doNothing_08063e10(PantheonGuardian* p);
void FUN_08063e28(PantheonGuardian* p);
void FUN_08063e80(PantheonGuardian* p);
void FUN_08063ec8(PantheonGuardian* p);
void FUN_08063ef4(PantheonGuardian* p);
void FUN_08063f28(PantheonGuardian* p);

// clang-format off
static void (*const sPantheonGuardianUpdates1[9])(PantheonGuardian*) = {
    FUN_08063da0,
    FUN_08063da0,
    FUN_08063da0,
    doNothing_08063e10,
    FUN_08063e28,
    FUN_08063e80,
    FUN_08063ec8,
    FUN_08063ef4,
    FUN_08063f28,
}; // 0x08365a80
// clang-format on

void FUN_08063f50(PantheonGuardian* p);
void FUN_08063fd8(PantheonGuardian* p);
void FUN_080640dc(PantheonGuardian* p);
void FUN_080641ec(PantheonGuardian* p);
void FUN_0806429c(PantheonGuardian* p);
void FUN_08064354(PantheonGuardian* p);
void FUN_08064444(PantheonGuardian* p);
void FUN_0806447c(PantheonGuardian* p);
void FUN_080644fc(PantheonGuardian* p);

// clang-format off
static void (*const sPantheonGuardianUpdates2[9])(PantheonGuardian*) = {
    FUN_08063f50,
    FUN_08063fd8,
    FUN_080640dc,
    FUN_080641ec,
    FUN_0806429c,
    FUN_08064354,
    FUN_08064444,
    FUN_0806447c,
    FUN_080644fc,
};  // 0x08365aa4
// clang-format on

// --------------------------------------------

// 0x08365ac8
static const struct Collision sCollisions[7] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0200, -0x1000, 0x1000, 0x1000},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0200, -0x1000, 0x1000, 0x2000},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x1000, -0x1000, 0x3000, 0x1000},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0200, -0x1000, 0x1000, 0x2000},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1000, 0x1000, 0x1000},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x1000, 0x1000, 0x2000},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {-0x0200, -0x1000, 0x1000, 0x1000},
    },
};

static const Coords32 Coord_08365b70 = {0, -PIXEL(16)};
