#include "collision.h"
#include "global.h"
#include "solid.h"
#include "vfx.h"

typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  s32 y;
  u8 unk_04[12];
} IcebonIceCube;
static_assert(sizeof(IcebonIceCube) == sizeof(struct Solid));

static const u8 sInitModes[2];
static const struct Collision sCollisions[5];
static const motion_t sMotions[4];
static const struct Rect sIcebonIceCubeSize;

static void IcebonIce_Init(IcebonIceCube* p);
static void IcebonIce_Update(IcebonIceCube* p);
static void IcebonIce_Die(IcebonIceCube* p);

// clang-format off
const SolidRoutine gIcebonIceRoutine = {
    [ENTITY_INIT] =      (void*)IcebonIce_Init,
    [ENTITY_UPDATE] =    (void*)IcebonIce_Update,
    [ENTITY_DIE] =       (void*)IcebonIce_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void icebon_080ca550(struct Entity* e, u8 n) {
  struct Entity* p = AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_ICEBON_ICE);
    p->coord.x = (e->coord).x;
    p->coord.y = (e->coord).y - PIXEL(21);
    p->work[0] = n;
    p->unk_28 = e;
  }
}

// --------------------------------------------

static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) { return; }

static void IcebonIce_Init(IcebonIceCube* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, &sCollisions[0], 8, onCollision);
  p->y = (p->coord).y;
  IcebonIce_Update(p);
}

void FUN_080ca700(IcebonIceCube* p);
static void nop_080ca6fc(IcebonIceCube* p);
void FUN_080ca76c(IcebonIceCube* p);

void FUN_080ca7d8(IcebonIceCube* p);
void FUN_080ca880(IcebonIceCube* p);
void FUN_080ca988(IcebonIceCube* p);
void FUN_080caafc(IcebonIceCube* p);
void FUN_080cab58(IcebonIceCube* p);
void FUN_080cabe8(IcebonIceCube* p);

static void IcebonIce_Update(IcebonIceCube* p) {
  // clang-format off
   static void (*const sUpdates1[6])(IcebonIceCube*) = {
      FUN_080ca700,
      nop_080ca6fc,
      nop_080ca6fc,
      FUN_080ca76c,
      nop_080ca6fc,
      nop_080ca6fc,
  };
  // clang-format on

  // clang-format off
  static void (*const sUpdates2[6])(IcebonIceCube*) = {
      FUN_080ca7d8,
      FUN_080ca880,
      FUN_080ca988,
      FUN_080caafc,
      FUN_080cab58,
      FUN_080cabe8,
  };
  // clang-format on

  if ((p->body).status & BODY_STATUS_DEAD) {
    p->flags2 &= ~ENTI_PHYSICS;
    SET_SOLID_ROUTINE(p, ENTITY_DIE);
    IcebonIce_Die(p);
    return;
  }

  (sUpdates1[p->mode[1]])(p);
  (sUpdates2[p->mode[1]])(p);
}

static void IcebonIce_Die(IcebonIceCube* p) {
  Coords32 c;

  PlaySound(SE_ICE_BREAK);
  EXIT_BODY(p);
  p->flags &= ~DISPLAY;

  c.x = (p->coord).x;
  c.y = (p->coord).y + PIXEL(16);
  FUN_080b81a0((struct Entity*)p, &c, (motion_t*)sMotions, 4);
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080ca6fc(IcebonIceCube* p) {}

void FUN_080ca700(IcebonIceCube* p) {
  struct Entity* icebon = p->unk_28;
  if (icebon->mode[0] >= ENTITY_DISAPPEAR) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  if (icebon->mode[0] >= ENTITY_DIE) {
    SET_SOLID_ROUTINE(p, ENTITY_DIE);
    p->mode[1] = 0;
  }
}

// 0x080ca700 と全く同じ
void FUN_080ca76c(IcebonIceCube* p) {
  struct Entity* icebon = p->unk_28;
  if (icebon->mode[0] >= ENTITY_DISAPPEAR) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  if (icebon->mode[0] >= ENTITY_DIE) {
    SET_SOLID_ROUTINE(p, ENTITY_DIE);
    p->mode[1] = 0;
  }
}

void FUN_080ca7d8(IcebonIceCube* p) {
  if ((p->body).hp >= 5) {
    SetSpriteAnimation(p, MOTION(SM017_ICEBON_ICE, 0));
  } else {
    SetSpriteAnimation(p, MOTION(SM017_ICEBON_ICE, 2));
  }
  UpdateSpriteAnimation(p);

  switch (p->mode[2]) {
    case 0: {
      p->y = (p->coord).y;
      (p->unk_coord).y = (p->coord).y;
      p->flags2 |= ENTI_PHYSICS;
      p->size = &sIcebonIceCubeSize;
      p->physicsAttr = MTATTR_B11 | SHAPE_BLOCK;  // 0x801
      SetDDP(&p->body, &sCollisions[1]);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 y;
      p->y -= PIXEL(1) / 2;
      y = p->y - (p->coord).y;
      if (y < 0) y += 7;
      (p->coord).y += y >> 3;
      if ((p->coord).y - (p->unk_coord).y <= -PIXEL(15)) p->mode[1] = 1, p->mode[2] = 0;
      break;
    }
  }
}

INCASM("asm/solid/icebon_ice.inc");

// --------------------------------------------

// 0x0836fce0
static const struct Collision sCollisions[5] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x0700, 0x1C00, 0x0800},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0400, 0x1C00, 0x1800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0200, 0x1400, 0x1400},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0200, 0x1400, 0x1400},
    },
};

static const struct Rect sIcebonIceCubeSize = {PIXEL(0), -PIXEL(3), PIXEL(24), PIXEL(16)};  // 0x0836FD58

static const u8 sInitModes[2] = {0, 3};  // 0x0836FD60

static const motion_t sMotions[4] = {
    MOTION(SM017_ICEBON_ICE, 6),
    MOTION(SM017_ICEBON_ICE, 7),
    MOTION(SM017_ICEBON_ICE, 8),
    MOTION(SM017_ICEBON_ICE, 6),
};  // 0x0836FD62
