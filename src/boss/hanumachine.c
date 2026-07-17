#include "boss.h"
#include "collision.h"
#include "global.h"
#include "element.h"
#include "script.h"
#include "stagerun.h"
#include "physics.h"

static const struct Collision sCollisions[];
static const Coords32 sElementCoord;

static const BossFunc sUpdates1[30];
static const BossFunc sUpdates2[30];

INCASM("asm/boss/hanumachine_a.inc");

static const BossFunc sUpdates1[30];
static const BossFunc sUpdates2[30];
u16 FUN_0805d594(struct Boss* p, s32 a, s32 b);
void Hanumachine_Die(struct Boss* p);

void Hanumachine_Update(struct Boss* p) {
  if (!((p->body).status & BODY_STATUS_DEAD)) {
    if (*(s16*)((u8*)p + 0xa4) != 0) {
      goto alive;
    }
  }
  if (gStageRun.missionStatus & 8) {
    goto alive;
  }
  SET_BOSS_ROUTINE(p, ENTITY_DIE);
  Hanumachine_Die(p);
  return;

alive:
  *(s32*)((u8*)p + 0xc8) = (p->s).coord.x;
  *(s32*)((u8*)p + 0xcc) = (p->s).coord.y;
  if ((p->s).mode[1] != 0x1d) {
    if (((p->body).status & 0x00020001) == 0x00020001) {
      if (FUN_0805d594(p, 0, 0) == 0) {
        (p->s).mode[1] = 0x1d;
        (p->s).mode[2] = 0;
      }
    }
  }
  if (((p->body).status & 1) && *(struct Entity**)((u8*)p + 0xc4) == NULL) {
    *(struct Entity**)((u8*)p + 0xc4) = (struct Entity*)ApplyElementEffect(0x1c, &p->s, &sElementCoord);
  }
  if (isKilled(*(struct Entity**)((u8*)p + 0xc4))) {
    *(struct Entity**)((u8*)p + 0xc4) = NULL;
  }
  if (sUpdates2[(p->s).mode[1]] != NULL) {
    (sUpdates2[(p->s).mode[1]])(p);
  }
  (sUpdates1[(p->s).mode[1]])(p);
}

INCASM("asm/boss/hanumachine_b.inc");

void FUN_0805bcdc(struct Boss* p) {
  s32 push = PushoutToUp1((p->s).coord.x, (p->s).coord.y + 1);
  if (push == 0) {
    (p->s).mode[1] = 0x19;
    (p->s).mode[2] = push;
  }
}

void hanu_0805bcfc(struct Boss* p) {
  u8 m = (p->s).mode[2];
  if (m == 0) {
    SetSpriteAnimation(p, MOTION(0xb5, 0));
    (p->s).mode[2]++;
    (p->s).mode[3] = m;
  }
  UpdateSpriteAnimation(p);
  if ((p->s).scriptEntity->flags & 1) {
    (p->s).mode[1] = 1;
    (p->s).mode[2] = 0;
  }
}

INCASM("asm/boss/hanumachine_c.inc");

void FUN_0805c3cc(struct Boss* p) {
  if ((p->s).mode[2] == 0) {
    SetSpriteAnimation(p, 0xB50B);
    (p->s).mode[2]++;
  }
  UpdateSpriteAnimation(p);
  if ((p->s).motion.state == 3) {
    (p->s).mode[1] = 3;
    (p->s).mode[2] = 0;
  }
}

INCASM("asm/boss/hanumachine_d.inc");

void FUN_0805d568(struct Body* body) {
  if (body->hitboxFlags & 1) {
    struct Boss* atk = (struct Boss*)((body->enemy)->parent);
    struct Boss* self = (struct Boss*)body->parent;
    u8 r = 0;
    if ((atk->s).coord.x > (self->s).coord.x) {
      r = 1;
    }
    *(u8*)((u8*)self + 0xbc) = r;
  }
}

u16 FUN_0805d594(struct Boss* p, s32 a, s32 b) {
  u16 r = FUN_080098a4((p->s).coord.x + a, (p->s).coord.y);
  if (r != 0) {
    return r;
  }
  r = FUN_080098a4((p->s).coord.x + a, (p->s).coord.y - 0x2000);
  if (r != 0) {
    return r;
  }
  return 0;
}

void Hanumachine_Init(struct Boss* p);
void Hanumachine_Update(struct Boss* p);
void Hanumachine_Die(struct Boss* p);

// clang-format off
const BossRoutine gHanumachineRoutine = {
    [ENTITY_INIT] =      (BossFunc)Hanumachine_Init,
    [ENTITY_UPDATE] =    (BossFunc)Hanumachine_Update,
    [ENTITY_DIE] =       (BossFunc)Hanumachine_Die,
    [ENTITY_DISAPPEAR] = (BossFunc)DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void hanu_0805bcfc(struct Boss* p);
void hanu_0805bd38(struct Boss* p);
void hanu_0805bdc0(struct Boss* p);
void hanu_0805bf10(struct Boss* p);
void hanu_0805bf60(struct Boss* p);
void hanu_0805c0d0(struct Boss* p);
void hanu_0805c198(struct Boss* p);
void hanu_0805c2a4(struct Boss* p);
void hanu_0805c30c(struct Boss* p);
void FUN_0805c3cc(struct Boss* p);
void FUN_0805c404(struct Boss* p);
void hanu_0805c4a4(struct Boss* p);
void FUN_0805c580(struct Boss* p);
void hanu_0805c670(struct Boss* p);
void FUN_0805c760(struct Boss* p);
void hanu_0805c7c4(struct Boss* p);
void FUN_0805c87c(struct Boss* p);
void hanu_0805c98c(struct Boss* p);
void FUN_0805cb00(struct Boss* p);
void hanu_0805cbfc(struct Boss* p);
void hanu_0805ccc0(struct Boss* p);
void FUN_0805cdbc(struct Boss* p);
void FUN_0805ce50(struct Boss* p);
void hanu_0805cf58(struct Boss* p);
void FUN_0805cfe8(struct Boss* p);
void FUN_0805d080(struct Boss* p);
void FUN_0805d1c4(struct Boss* p);
void FUN_0805d210(struct Boss* p);
void FUN_0805d310(struct Boss* p);
void FUN_0805d3c8(struct Boss* p);

// clang-format off
static const BossFunc sUpdates1[30] = {
    hanu_0805bcfc,
    hanu_0805bd38,
    hanu_0805bdc0,
    hanu_0805bf10,
    hanu_0805bf60,
    hanu_0805c0d0,
    hanu_0805c198,
    hanu_0805c2a4,
    hanu_0805c30c,
    FUN_0805c3cc,
    FUN_0805c404,
    hanu_0805c4a4,
    FUN_0805c580,
    hanu_0805c670,
    FUN_0805c760,
    hanu_0805c7c4,
    FUN_0805c87c,
    hanu_0805c98c,
    FUN_0805cb00,
    hanu_0805cbfc,
    hanu_0805ccc0,
    FUN_0805cdbc,
    FUN_0805ce50,
    hanu_0805cf58,
    FUN_0805cfe8,
    FUN_0805d080,
    FUN_0805d1c4,
    FUN_0805d210,
    FUN_0805d310,
    FUN_0805d3c8,
};
// clang-format on

void FUN_0805bcdc(struct Boss* p);

// clang-format off
static const BossFunc sUpdates2[30] = {
    NULL,
    NULL,
    FUN_0805bcdc,
    FUN_0805bcdc,
    FUN_0805bcdc,
    NULL,
    NULL,
    FUN_0805bcdc,
    FUN_0805bcdc,
    FUN_0805bcdc,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    FUN_0805bcdc,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};
// clang-format on

// --------------------------------------------

// 0x08364e38
static const struct Collision sCollisions[22] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(13), PIXEL(19), PIXEL(31)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(13), PIXEL(19), PIXEL(31)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(2), -PIXEL(12), PIXEL(31), PIXEL(22)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      range : {PIXEL(2), -PIXEL(12), PIXEL(31), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(4), -PIXEL(14), PIXEL(23), PIXEL(34)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      range : {PIXEL(4), -PIXEL(14), PIXEL(23), PIXEL(34)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(2), -PIXEL(18), PIXEL(19), PIXEL(46)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      range : {PIXEL(2), -PIXEL(18), PIXEL(19), PIXEL(46)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(1), -PIXEL(10), PIXEL(36), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      range : {PIXEL(1), -PIXEL(10), PIXEL(36), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(42), PIXEL(42)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(42), PIXEL(42)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(2), PIXEL(22), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(2), PIXEL(22), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(18), -PIXEL(50), PIXEL(11), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 3,
      layer : 0x00000001,
      range : {-PIXEL(40), -PIXEL(41), PIXEL(11), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(11), -PIXEL(44), PIXEL(47), PIXEL(36)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(2), -PIXEL(13), PIXEL(21), PIXEL(33)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(2), -PIXEL(13), PIXEL(21), PIXEL(33)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(10), -PIXEL(16), PIXEL(8), PIXEL(65)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(26), PIXEL(33)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(22), PIXEL(26), PIXEL(33)},
    },
};

static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(14)};
