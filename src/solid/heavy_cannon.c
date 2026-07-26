#include "collision.h"
#include "global.h"
#include "element.h"
#include "solid.h"

static const struct Collision sCollisions[];

void initHeavyCannon(struct Solid* p);
void heavyCannonAI(struct Solid* p);
void killHeavyCannon(struct Solid* p);
void FUN_080cc284(struct Solid* p);

// clang-format off
const SolidRoutine gHeavyCannonRoutine = {
    [ENTITY_INIT] =      (void*)initHeavyCannon,
    [ENTITY_UPDATE] =    (void*)heavyCannonAI,
    [ENTITY_DIE] =       (void*)killHeavyCannon,
    [ENTITY_DISAPPEAR] = (void*)FUN_080cc284,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};



void FUN_080cbe38(struct Solid* p);
void FUN_080cc4dc(struct Solid* p);
void FUN_080cc298(struct Solid* p);
// clang-format on

static bool8 FUN_080cbdc0(Object* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    struct Entity* next;
    if (p->work[0] < 4) {
      next = (struct Entity*)p->unk_2c;
      while (next != NULL) {
        SET_SOLID_ROUTINE(next, ENTITY_DIE);
        next = (struct Entity*)next->unk_2c;
      }
    } else {
      struct Entity* prev = (struct Entity*)p->unk_28;
      next = (struct Entity*)p->unk_2c;
      if (prev != NULL) prev->unk_2c = next;
      if (next != NULL) next->unk_28 = prev;
    }
    SET_SOLID_ROUTINE(p, ENTITY_DIE);
    killHeavyCannon((struct Solid*)p);
    return TRUE;
  }
  return FALSE;
}

void FUN_080cbe38(struct Solid* p) {
  struct Entity* parent = (p->s).unk_2c;
  if (parent != NULL) {
    if ((parent->coord).y - (p->s).coord.y > 0x1000) {
      (p->s).d.y += 0x40;
      if ((p->s).d.y > 0x700) {
        (p->s).d.y = 0x700;
      }
      (p->s).coord.y += (p->s).d.y;
    } else {
      (p->s).coord.y = (parent->coord).y - 0x1000;
      (p->s).d.y = 0;
    }
  } else {
    (p->s).d.y += 0x40;
    if ((p->s).d.y > 0x700) {
      (p->s).d.y = 0x700;
    }
    (p->s).coord.y += (p->s).d.y;
    if ((p->s).coord.y > *(s32*)((u8*)p + 0xb4)) {
      (p->s).coord.y = *(s32*)((u8*)p + 0xb4);
      (p->s).d.y = 0;
    }
  }
}

void nop_080cbea4(struct Solid* p) {}

INCASM("asm/solid/heavy_cannon_a.inc");

void FUN_080cc284(struct Solid* p) {
  (p->s).flags2 &= ~ENTI_PHYSICS;
  DeleteSolid((Object*)p);
}

extern const struct Coord Coord_0836ff28;

void FUN_080cc298(struct Solid* p) {
  struct Entity** slot = (struct Entity**)((u8*)p + 0xb8);
  struct Entity* old = *slot;
  if (old == NULL && (*(u32*)((u8*)p + 0x8c) & 1)) {
    *slot = ApplyElementEffect(0, (Object*)p, &Coord_0836ff28);
    if (*slot != NULL) {
      (p->s).mode[1] = 2;
      (p->s).mode[3] = (u8)(u32)old;
    }
  }
}

INCASM("asm/solid/heavy_cannon_b.inc");

void FUN_080cc4dc(struct Solid* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[1]);
      SetSpriteAnimation(p, MOTION(0x38, 0));
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
      break;
  }
  FUN_080cbe38(p);
}

// --------------------------------------------

void FUN_080cc298(struct Solid* p);
void FUN_080cc2d4(struct Solid* p);

const SolidFunc gHeavyCannonUpdates1[3] = {
    (void*)FUN_080cc298,
    (void*)FUN_080cc298,
    (void*)FUN_080cc2d4,
};

void FUN_080cc320(struct Solid* p);
void FUN_080cc4dc(struct Solid* p);
static void FUN_080cc51c(struct Solid* p);

const SolidFunc gHeavyCannonUpdates2[3] = {
    (void*)FUN_080cc320,
    (void*)FUN_080cc4dc,
    (void*)FUN_080cc51c,
};

// --------------------------------------------

void FUN_080cbe38(struct Solid* p);

static void FUN_080cc51c(struct Solid* p) {
  if ((p->s).mode[3] == 0) {
    if ((p->s).work[0] < 4) {
      SetDDP(&p->body, &sCollisions[5]);
    } else {
      SetDDP(&p->body, &sCollisions[2]);
    }
    (p->s).mode[3]++;
  }
  FUN_080cbe38((struct Solid*)p);
}

// --------------------------------------------

// 0x0836FE8C
static const struct Collision sCollisions[6] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(5), PIXEL(26), PIXEL(16)},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(5), PIXEL(26), PIXEL(16)},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      nature : 0x04,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(25), PIXEL(22), PIXEL(8)},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(12), PIXEL(26), PIXEL(31)},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(8), PIXEL(26), PIXEL(23)},
    },
};

// 0x0836ff1c
const u8 u8_ARRAY_0836ff1c[6] = {0, 0, 0, 0, 1, 0};

// 0x0836ff22
const motion_t gHeavyCannonMotions[3] = {
    MOTION(SM056_HEAVY_CANNON, 5),
    MOTION(SM056_HEAVY_CANNON, 6),
    MOTION(SM056_HEAVY_CANNON, 7),
};

// 0x0836ff28
const Coords32 Coord_0836ff28 = {PIXEL(0), -PIXEL(8)};

// 0x0836ff30
const struct Rect Rect_ARRAY_0836ff30[2] = {
    {PIXEL(0), PIXEL(9), PIXEL(22), PIXEL(64)},
    {PIXEL(0), PIXEL(10), PIXEL(22), PIXEL(26)},
};
