#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"

void CreateLavaGeyserPlatform(struct Solid* s);

static const struct Collision sCollisions[];
static const struct Rect sSize;

typedef struct {
  ENTITY_HDR;        // 0x00
  ENTITY_SPRITE;     // 0x28
  struct Body body;  // 0x74
  // props (16bytes, offset: 0xB4..)
  u8 unk_b4[4];  // 0xB4
  s32 unk_b8_y;  // 0xB8
  s32 unk_bc_y;  // 0xBC
  s32 unk_c0_x;  // 0xC0
} LavaGeyser;
static_assert(sizeof(LavaGeyser) == sizeof(struct Solid));

// ------------------------------------------------------------------------------------------------------------------------------------

static void Solid7_Init(LavaGeyser* p);
static void Solid7_Update(LavaGeyser* p);
static void Solid7_Die(void* _);

// clang-format off
const SolidRoutine gLavaGeyserRoutine = {
    [ENTITY_INIT] =      (void*)Solid7_Init,
    [ENTITY_UPDATE] =    (void*)Solid7_Update,
    [ENTITY_DIE] =       (void*)Solid7_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void CreateLavaGeyser(struct Entity* e, s32 x, s32 y, s32 n) {
  s32 i;
  for (i = 0; i < 6; i++) {
    struct Entity* p = AllocEntityLast(gSolidHeaderPtr);
    if (p != NULL) {
      register s32 r0 asm("r0");
      register s32 r1 asm("r1");

      INIT_SOLID_ROUTINE(p, SOLID_LAVA_GEYSER);
      (p->work)[0] = 12;
      (p->work)[1] = i;

      r0 = abs(n - y);
      r1 = r0;
      if (r0 < 0) {  // never reached?
        r1 = r0 + ((1 << 11) - 1);
      }
      r0 = r1 >> 11;
      (p->work)[3] = r0;

      (p->coord).x = x;
      (p->coord).y = y;
      y += PIXEL(16);
      p->unk_28 = (void*)e;
    }
  }
}

static void CreateSolid7_Unused(s32 x, u8 n) {
  struct Entity* p = AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_LAVA_GEYSER);
    (p->work)[0] = n;
    (p->coord).x = x;
  }
}

bool8 FUN_080cc814(struct Entity* p) { return (p->mode)[1] == ENTITY_EXIT; }

// 0x080cc828
static void LavaGeyser_OnCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  struct Entity* q = (struct Entity*)(body->enemy)->parent;
  LavaGeyser* p = (LavaGeyser*)body->parent;

  if (body->hitboxFlags & BODY_STATUS_B3) {
    p->unk_bc_y = (q->coord).y;
  }
}

static void Solid7_Init(LavaGeyser* p) {
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  if (p->work[0] == 12) {
    p->mode[1] = 5;
  } else {
    p->mode[1] = 0;
    INIT_BODY(p, &sCollisions[0], 1, LavaGeyser_OnCollision);
    (p->coord).y = FUN_08009f6c((p->coord).x, (p->coord).y) - PIXEL(14);
    p->unk_b8_y = (p->coord).y;
    p->unk_c0_x = (p->coord).x;
    p->flags2 |= ENTI_PHYSICS;
    p->size = &sSize;
    p->physicsAttr = MTATTR_B11 | MTATTR_SPIKE | SHAPE_BLOCK;
    CreateLavaGeyserPlatform((void*)p);
  }
  Solid7_Update(p);
}

void nop_080cc930(LavaGeyser* _);
void FUN_080cc934(LavaGeyser* p);

void FUN_080cc968(LavaGeyser* p);
void FUN_080cca14(LavaGeyser* p);
void FUN_080ccae0(LavaGeyser* p);
void FUN_080ccb50(LavaGeyser* p);
void FUN_080ccc1c(LavaGeyser* p);
void FUN_080ccca4(LavaGeyser* p);

static void Solid7_Update(LavaGeyser* p) {
  // clang-format off
  static void (*const sUpdates1[6])(LavaGeyser*) = {
    FUN_080cc934,
    FUN_080cc934,
    FUN_080cc934,
    FUN_080cc934,
    nop_080cc930,
    nop_080cc930,
  };  // 0x0836FF7C
  // clang-format on
  // clang-format off
  static void (*const sUpdates2[6])(LavaGeyser*) = {
    FUN_080cc968,
    FUN_080cca14,
    FUN_080ccae0,
    FUN_080ccb50,
    FUN_080ccc1c,
    FUN_080ccca4,
  };  // 0x0836FF94
  // clang-format on
  sUpdates1[p->mode[1]](p);
  sUpdates2[p->mode[1]](p);
}

static void Solid7_Die(void* _) {}

// --------------------------------------------

void nop_080cc930(LavaGeyser* _) {}

void FUN_080cc934(LavaGeyser* p) {
  if (((p->body).status & BODY_STATUS_B3) && ((p->body).elemented == ELEMENT_ICE)) {
    PlaySound(SE_ICE_40);
    p->mode[1] = 4, p->mode[2] = 0;
  }
}

void FUN_080cc968(LavaGeyser* p) {
  switch (p->mode[2]) {
    case 0: {
      (p->unk_coord).x = (p->coord).x;
      SetDDP(&p->body, sCollisions);
      SetSpriteAnimation(p, MOTION(SM057_GEYSER, 0));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 val = (gOverworld.work.volcano.unk_004 - (67 * (p->work[0] % 4)) + 1) % 268;
      if (val > 236) {
        (p->coord).x = (p->unk_c0_x - PIXEL(2));
        (p->coord).x += (RANDOM(RNG_0202f388) & 0x3FF);
      }
      if (val == 0) p->mode[1] = 1, p->mode[2] = 0;
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

INCASM("asm/solid/lava_geyser.inc");

// --------------------------------------------

// 0x0836ffac
static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 254,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(57), PIXEL(32), PIXEL(111)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      hardness : 8,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(57), PIXEL(32), PIXEL(111)},
    },
};

// --------------------------------------------

// 0x0836FFDC
static const struct Rect sSize = {PIXEL(0), PIXEL(57), PIXEL(32), PIXEL(120)};
