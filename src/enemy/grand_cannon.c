#include "collision.h"
#include "element.h"
#include "enemy.h"
#include "global.h"
#include "mod.h"
#include "story.h"
#include "vfx.h"

typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  struct GrandCannonProps {
    Entity* elfx;  // 0xB4, ElementEffect
    u8 unk_004;
    u8 unk_005;
    u16 unk_006;
    bool8 is_right;
    u8 unk_009;
    u8 unk_00a;
    u8 unk_00b;
    u8 unk_00c[4];
  } props;
} GrandCannon;
static_assert(sizeof(GrandCannon) == sizeof(struct Enemy));

static const struct Collision sCollisions[3];
static const struct Rect sSize;
static const motion_t sMotions[4];
static const Coords32 sElementCoord;
static const u8 sInitModes[2];

static void GrandCannon_Init(GrandCannon* p);
static void GrandCannon_Update(GrandCannon* p);
static void GrandCannon_Die(GrandCannon* p);
static void GrandCannon_Dissappear(GrandCannon* p);

// clang-format off
const EnemyRoutine gGrandCannonRoutine = {
    [ENTITY_INIT] =      (void*)GrandCannon_Init,
    [ENTITY_UPDATE] =    (void*)GrandCannon_Update,
    [ENTITY_DIE] =       (void*)GrandCannon_Die,
    [ENTITY_DISAPPEAR] = (void*)GrandCannon_Dissappear,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// グランドキャノンの砲台の方を生成
static void CreateGrandCannonBattery(GrandCannon* turret) {
  GrandCannon* p = AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    p->unk_28 = (void*)turret;
    INIT_ENEMY_ROUTINE(p, ENEMY_GRAND_CANNON);
    p->work[0] = GRAND_CANNON_BATTERY;
    p->flags2 |= WHITE_PAINTABLE;
    p->invincibleID = turret->uniqueID;
  }
}

static void GrandCannon_OnCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  if (body->hitboxFlags & BODY_STATUS_WHITE) {
    Entity* q = (body->enemy)->parent;
    GrandCannon* p = (GrandCannon*)body->parent;
    if (q->kind == ENTITY_PROJECTILE && q->id == 3) {
      SET_ENEMY_ROUTINE(p, ENTITY_DIE);
      p->mode[1] = 0;
    }
  }
}

static bool8 tryKillGrandCannon(GrandCannon* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    if ((p->body).status & BODY_STATUS_SLASHED) {
      p->mode[1] = 1;
    } else {
      p->mode[1] = 0;
    }
    GrandCannon_Die(p);
    return TRUE;
  }
  return FALSE;
}

static void nop_0806937c(GrandCannon* p);
static void grandcannon_08069380(GrandCannon* p);

static void (*const sUpdates1[4])(GrandCannon*) = {
    nop_0806937c,
    nop_0806937c,
    nop_0806937c,
    grandcannon_08069380,
};

static void grandCannon_080693b4(GrandCannon* p);
void grandcannonMoveTurret(GrandCannon* p);
void grandcannonBombShot(GrandCannon* p);
void grandcannon_08069608(GrandCannon* p);

static void (*const sUpdates2[4])(GrandCannon*) = {
    grandCannon_080693b4,
    grandcannonMoveTurret,
    grandcannonBombShot,
    grandcannon_08069608,
};

static bool8 FUN_08069098(GrandCannon* p) {
  if ((p->props).elfx == NULL) {
    switch (p->mode[3]) {
      case 0: {
        if (IsFrozen(p)) {
          (sUpdates1[p->mode[1]])((void*)p);
          (sUpdates2[p->mode[1]])((void*)p);
          p->mode[3]++;
          UpdateSpriteAnimation(p);
          return TRUE;
        }
        break;
      }
      case 1: {
        if (IsFrozen(p)) return TRUE;
        p->mode[3] = 0;
        break;
      }
    }
  }
  return FALSE;
}

static void FUN_0806910c(GrandCannon* p) {
  if ((p->props).elfx == NULL) {
    if ((p->body).status & BODY_STATUS_WHITE) {
      (p->props).elfx = ApplyElementEffect(0, (Object*)p, &sElementCoord);
      if ((p->props).elfx != NULL) {
        p->mode[1] = 3, p->mode[2] = 0;
      }
    }
  }
}

// --------------------------------------------

static void GrandCannon_Init(GrandCannon* p) {
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);

  if (p->work[0] == GRAND_CANNON_TURRET) {
    p->coord.y = FUN_08009f6c(p->coord.x, p->coord.y);
    if (FLAG(gSystemSavedata.flags, MOD_105) && !FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
      _INIT_BODY(p, sCollisions, 12);
    } else {
      _INIT_BODY(p, sCollisions, 8);
    }
    SET_BODY_INTERSECT_HANDLER(p, GrandCannon_OnCollision);
    CreateGrandCannonBattery(p);
    (p->props).elfx = NULL;
  } else {
    (p->props).unk_004 = 0;
  }

  GrandCannon_Update(p);
}

NON_MATCH static void GrandCannon_Update(GrandCannon* p) {
#if MODERN
  if (p->work[0] == GRAND_CANNON_BATTERY) {
    struct Entity* turret = p->unk_28;
    if (!IS_METTAUR) {
      if (turret->mode[0] != ENTITY_EXIT) {
        if (turret->mode[0] > ENTITY_UPDATE) {
          SET_ENEMY_ROUTINE(p, ENTITY_DIE);
          p->mode[1] = 2;
          GrandCannon_Die(p);
          return;
        }
        goto _UPDATE;
      }
    }

    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
  } else {
    if (tryKillGrandCannon(p)) {
      return;
    }
    FUN_0806910c(p);
    if (FUN_08069098(p)) {
      return;
    }
  _UPDATE:
    (sUpdates1[p->mode[1]])((void*)p);
    (sUpdates2[p->mode[1]])((void*)p);
  }
#else
  INCCODE("asm/wip/GrandCannon_Update.inc");
#endif
}

void explodeGrandCannon(GrandCannon* p);
void slashGrandCannon(GrandCannon* p);
void FUN_080697bc(GrandCannon* p);

static void GrandCannon_Die(GrandCannon* p) {
  static void (*const sDeads[3])(GrandCannon*) = {
      explodeGrandCannon,
      slashGrandCannon,
      FUN_080697bc,
  };
  if (FLAG(gCurStory.s.gameflags, METTAUR_ENABLED)) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sDeads[p->mode[1]])((void*)p);
}

static void GrandCannon_Dissappear(GrandCannon* p) {
  p->flags2 &= ~ENTI_PHYSICS;
  DeleteEnemy((Entity*)p);
}

// --------------------------------------------

static void nop_0806937c(GrandCannon* p) { return; }

static void grandcannon_08069380(GrandCannon* p) {
  struct Entity* elfx = (p->props).elfx;
  if (elfx == NULL || IsDead(elfx)) {
    (p->props).elfx = NULL;
    SetDDP(&p->body, sCollisions);
    p->mode[1] = 0, p->mode[2] = 0;
  }
}

static void grandCannon_080693b4(GrandCannon* p) {
  switch (p->mode[2]) {
    case 0: {
      SetDDP(&p->body, &sCollisions[1]);
      p->flags2 |= ENTI_PHYSICS;
      p->size = &sSize;
      p->physicsAttr = MTATTR_SLIP | SHAPE_BLOCK;
      SetSpriteAnimation(p, MOTION(SM007_GRAND_CANNON, 0));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

INCASM("asm/enemy/grand_cannon_a.inc");

void grandcannon_08069608(GrandCannon* p) {
  if (p->mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[2]);
    p->mode[2]++;
  }
}

INCASM("asm/enemy/grand_cannon_b.inc");

// --------------------------------------------

// 0x08366260
static const struct Collision sCollisions[3] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0400, 0x0000, 0x0800, 0x1000},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x0900, 0x1C00, 0x1600},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x04,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x0800, 0x1C00, 0x1800},
    },
};

// 0x083662a8
static const Coords32 sElementCoord = {PIXEL(0), 0xFFFFF000};

// 0x083662b0
static const u8 sInitModes[2] = {0, 1};

// 0x083662b4
static const struct Rect sSize = {PIXEL(0), PIXEL(0), PIXEL(24), PIXEL(38)};

// 0x083662bc
static const motion_t sMotions[4] = {
    MOTION(SM007_GRAND_CANNON, 5),
    MOTION(SM007_GRAND_CANNON, 6),
    MOTION(SM007_GRAND_CANNON, 7),
    MOTION(SM007_GRAND_CANNON, 2),
};
