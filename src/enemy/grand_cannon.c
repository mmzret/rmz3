#include "collision.h"
#include "element.h"
#include "enemy.h"
#include "global.h"
#include "story.h"
#include "vfx.h"

static const struct Collision sCollisions[3];
static const struct Rect sSize;
static const motion_t sMotions[4];
static const struct Coord sElementCoord;
static const u8 sInitModes[2];

static const EnemyFunc sUpdates1[4];
static const EnemyFunc sUpdates2[4];
static const EnemyFunc sDeads[3];

static void GrandCannon_Init(struct Enemy* p);
static void GrandCannon_Update(struct Enemy* p);
static void GrandCannon_Die(struct Enemy* p);
static void GrandCannon_Dissappear(struct Enemy* p);

// clang-format off
const EnemyRoutine gGrandCannonRoutine = {
    [ENTITY_INIT] =      GrandCannon_Init,
    [ENTITY_UPDATE] =    GrandCannon_Update,
    [ENTITY_DIE] =       GrandCannon_Die,
    [ENTITY_DISAPPEAR] = GrandCannon_Dissappear,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// グランドキャノンの砲台の方を生成
WIP void CreateGrandCannonBattery(struct Enemy* p) {
#if MODERN
  struct Enemy* battery = (struct Enemy*)AllocEntityLast(gZakoHeaderPtr);
  if (battery != NULL) {
    (battery->s).unk_28 = &p->s;
    (battery->s).taskCol = 24;
    INIT_ZAKO_ROUTINE(battery, 6);
    (battery->s).tileNum = 0;
    (battery->s).palID = 0;
    (battery->s).flags2 |= WHITE_PAINTABLE;
    (battery->s).invincibleID = (battery->s).uniqueID;
    (battery->s).work[0] = GRAND_CANNON_BATTERY;
    (battery->s).invincibleID = (p->s).uniqueID;
  }
#else
  INCCODE("asm/wip/CreateGrandCannonBattery.inc");
#endif
}

static void onCollision(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  if (body->hitboxFlags & BODY_STATUS_WHITE) {
    struct CollidableEntity* e = body->enemy->parent;
    struct Enemy* parent = (struct Enemy*)body->parent;
    if (*((u16*)&(e->s).kind) == 0x304) {
      SET_ZAKO_ROUTINE(parent, ENTITY_DIE);
      (parent->s).mode[1] = 0;
    }
  }
}

static bool8 tryKillGrandCannon(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ZAKO_ROUTINE(p, ENTITY_DIE);
    if ((p->body).status & BODY_STATUS_SLASHED) {
      (p->s).mode[1] = 1;
    } else {
      (p->s).mode[1] = 0;
    }
    GrandCannon_Die(p);
    return TRUE;
  }
  return FALSE;
}

static void nop_0806937c(struct Enemy* p);
static void grandcannon_08069380(struct Enemy* p);

static const EnemyFunc sUpdates1[4] = {
    nop_0806937c,
    nop_0806937c,
    nop_0806937c,
    grandcannon_08069380,
};

// --------------------------------------------

static void grandCannon_080693b4(struct Enemy* p);
void grandcannonMoveTurret(struct Enemy* p);
void grandcannonBombShot(struct Enemy* p);
void grandcannon_08069608(struct Enemy* p);

static const EnemyFunc sUpdates2[4] = {
    grandCannon_080693b4,
    grandcannonMoveTurret,
    grandcannonBombShot,
    grandcannon_08069608,
};

static bool8 FUN_08069098(struct Enemy* p) {
  if ((p->props.gyroCannon).elementEffect == NULL) {
    switch ((p->s).mode[3]) {
      case 0: {
        if (isFrozen(p)) {
          (sUpdates1[(p->s).mode[1]])(p);
          (sUpdates2[(p->s).mode[1]])(p);
          (p->s).mode[3]++;
          UpdateMotionGraphic(&p->s);
          return TRUE;
        }
        break;
      }
      case 1: {
        if (isFrozen(p)) {
          return TRUE;
        }
        (p->s).mode[3] = 0;
        break;
      }
    }
  }
  return FALSE;
}

static void FUN_0806910c(struct Enemy* p) {
  if ((p->props.gyroCannon).elementEffect == NULL) {
    if ((p->body).status & BODY_STATUS_WHITE) {
      (p->props).gyroCannon.elementEffect = ApplyElementEffect(0, &p->s, &sElementCoord);
      if ((p->props).gyroCannon.elementEffect != NULL) {
        (p->s).mode[1] = 3;
        (p->s).mode[2] = 0;
      }
    }
  }
}

// --------------------------------------------

WIP static void GrandCannon_Init(struct Enemy* p) {
#if MODERN
  SET_ZAKO_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);

  if ((p->s).work[0] == GRAND_CANNON_TURRET) {
    (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
    (p->s).flags |= COLLIDABLE;
    if (!(gSystemSavedataManager.mods[13] & (1 << 1)) || FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
      InitBody(&p->body, sCollisions, &(p->s).coord, 8);
    } else {
      InitBody(&p->body, sCollisions, &(p->s).coord, 12);
    }
    (&p->body)->parent = (struct CollidableEntity*)p;
    (&p->body)->fn = NULL;
    (&p->body)->fn = onCollision;
    CreateGrandCannonBattery(p);
    (p->props).gyroCannon.elementEffect = NULL;
  } else {
    (p->props).gyroCannon.unk_004 = 0;
  }

  GrandCannon_Update(p);
#else
  INCCODE("asm/wip/GrandCannon_Init.inc");
#endif
}

WIP static void GrandCannon_Update(struct Enemy* p) {
#if MODERN
  if ((p->s).work[0] == GRAND_CANNON_BATTERY) {
    struct Entity* turret = (p->s).unk_28;
    if (!IS_METTAUR) {
      if (turret->mode[0] != ENTITY_EXIT) {
        if (turret->mode[0] > ENTITY_UPDATE) {
          SET_ZAKO_ROUTINE(p, ENTITY_DIE);
          (p->s).mode[1] = 2;
          GrandCannon_Die(p);
          return;
        }
        goto _UPDATE;
      }
    }

    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_ZAKO_ROUTINE(p, ENTITY_DISAPPEAR);
  } else {
    if (tryKillGrandCannon(p)) {
      return;
    }
    FUN_0806910c(p);
    if (FUN_08069098(p)) {
      return;
    }
  _UPDATE:
    (sUpdates1[(p->s).mode[1]])(p);
    (sUpdates2[(p->s).mode[1]])(p);
  }
#else
  INCCODE("asm/wip/GrandCannon_Update.inc");
#endif
}

void explodeGrandCannon(struct Enemy* p);
void slashGrandCannon(struct Enemy* p);
void FUN_080697bc(struct Enemy* p);

static void GrandCannon_Die(struct Enemy* p) {
  static const EnemyFunc sDeads[3] = {
      explodeGrandCannon,
      slashGrandCannon,
      FUN_080697bc,
  };
  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_ZAKO_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sDeads[(p->s).mode[1]])(p);
}

static void GrandCannon_Dissappear(struct Enemy* p) {
  (p->s).flags2 &= ~ENTITY_HAZARD;
  DeleteEnemy(p);
}

// --------------------------------------------

static void nop_0806937c(struct Enemy* p) { return; }

static void grandcannon_08069380(struct Enemy* p) {
  struct VFX* effect = (p->props).gyroCannon.elementEffect;
  if (effect == NULL || isKilled(&effect->s)) {
    (p->props).gyroCannon.elementEffect = NULL;
    SetDDP(&p->body, sCollisions);
    (p->s).mode[1] = 0;
    (p->s).mode[2] = 0;
  }
}

// --------------------------------------------

static void grandCannon_080693b4(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      SetDDP(&p->body, &sCollisions[1]);
      (p->s).flags2 |= ENTITY_HAZARD;
      (p->s).size = &sSize;
      (p->s).hazardAttr = 0x1001;
      SetMotion(&p->s, MOTION(SM007_GRAND_CANNON, 0x0));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&p->s);
    }
  }
}

INCASM("asm/enemy/grand_cannon.inc");

// --------------------------------------------

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

static const struct Coord sElementCoord = {PIXEL(0), 0xFFFFF000};

static const u8 sInitModes[2] = {0, 1};

static const struct Rect sSize = {0x0, 0x0, 0x1800, 0x2600};

static const motion_t sMotions[4] = {
    MOTION(SM007_GRAND_CANNON, 0x05),
    MOTION(SM007_GRAND_CANNON, 0x06),
    MOTION(SM007_GRAND_CANNON, 0x07),
    MOTION(SM007_GRAND_CANNON, 0x02),
};
