#include "collision.h"
#include "element.h"
#include "global.h"
#include "overworld.h"
#include "physics.h"
#include "solid.h"

static const Coords32 Coord_0836fc80;
static const struct Rect sSize;

typedef struct {
  COLLISION_OBJECT_HDR;
  void* elfx;     // 0xB4
  u8 unk_04[12];  // 0xB8
} IcebonObject;
static_assert(sizeof(IcebonObject) == sizeof(struct Solid));

static const SolidFunc sIcebonDeathSeq[2];
const struct Collision sIcebonCollisions[3];

static void Icebon_Init(struct Solid* p);
static void Icebon_Update(struct Solid* p);
static void Icebon_Die(struct Solid* p);

// clang-format off
const SolidRoutine gIcebonRoutine = {
    [ENTITY_INIT] =      (SolidFunc)Icebon_Init,
    [ENTITY_UPDATE] =    (SolidFunc)Icebon_Update,
    [ENTITY_DIE] =       (SolidFunc)Icebon_Die,
    [ENTITY_DISAPPEAR] = (SolidFunc)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

void nop_080c9e90(struct Body* _ UNUSED) { return; }

// 0x080c9e94
static void CreateElementEffect(IcebonObject* p) {
  if ((p->elfx == NULL) && ((p->body).status & BODY_STATUS_WHITE)) {
    if ((((p->coord).y - PIXEL(15)) <= gOverworld.sea) || ((p->body).elemented != ELEMENT_FLAME)) {
      p->elfx = ApplyElementEffect(0, (Object*)p, &Coord_0836fc80);
      if (p->elfx != NULL) {
        p->mode[1] = 0, p->mode[2] = 0;
      }
    }
  }
}

static bool8 tryKillIcebon(Object* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_SOLID_ROUTINE(p, ENTITY_DIE);
    if ((p->body).status & BODY_STATUS_SLASHED) {
      p->mode[1] = 1;
    } else {
      p->mode[1] = 0;
    }
    Icebon_Die((struct Solid*)p);
    return TRUE;
  }
  return FALSE;
}

// --------------------------------------------

NAKED static void Icebon_Init(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	ldrb r1, [r6, #0xb]\n\
	movs r0, #8\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xb]\n\
	ldr r0, _080C9FC0 @ =sSize\n\
	str r0, [r6, #0x30]\n\
	movs r2, #1\n\
	strh r2, [r6, #0x26]\n\
	ldr r1, _080C9FC4 @ =gSolidFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	str r2, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	ldr r1, _080C9FC8 @ =u8_ARRAY_0836fc90\n\
	ldrb r0, [r6, #0x10]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	strb r0, [r6, #0xd]\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	movs r1, #1\n\
	movs r4, #0\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	bl InitNonAffineMotion\n\
	ldr r0, _080C9FCC @ =gSystemSavedata\n\
	ldrb r1, [r0, #0x13]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080C9FD8\n\
	ldr r0, _080C9FD0 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, #0\n\
	bne _080C9FD8\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _080C9FD4 @ =sIcebonCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0xc\n\
	b _080C9FF0\n\
	.align 2, 0\n\
_080C9FC0: .4byte sSize\n\
_080C9FC4: .4byte gSolidFnTable\n\
_080C9FC8: .4byte u8_ARRAY_0836fc90\n\
_080C9FCC: .4byte gSystemSavedata\n\
_080C9FD0: .4byte gCurStory\n\
_080C9FD4: .4byte sIcebonCollisions\n\
_080C9FD8:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #4\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _080CA024 @ =sIcebonCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #8\n\
_080C9FF0:\n\
	bl InitBody\n\
	str r6, [r4, #0x2c]\n\
	str r5, [r4, #0x24]\n\
	ldr r0, _080CA028 @ =nop_080c9e90\n\
	str r0, [r4, #0x24]\n\
	adds r0, r6, #0\n\
	adds r0, #0xb4\n\
	movs r4, #0\n\
	str r4, [r0]\n\
	ldr r0, [r6, #0x54]\n\
	ldr r1, [r6, #0x58]\n\
	bl FUN_0800a05c\n\
	str r0, [r6, #0x58]\n\
	movs r0, #0x40\n\
	strb r0, [r6, #0x12]\n\
	strb r4, [r6, #0x13]\n\
	str r4, [r6, #0x60]\n\
	adds r0, r6, #0\n\
	bl Icebon_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080CA024: .4byte sIcebonCollisions\n\
_080CA028: .4byte nop_080c9e90\n\
 .syntax divided\n");
}

// --------------------------------------------

static void icebon_080ca0b8(IcebonObject* p);
static void nop_080ca0b4(void* _ UNUSED);

static void icebon_080ca0e0(Object* p);
static void icebon_080ca104(Object* p);
void icebon_080ca154(struct Solid* p);

static void Icebon_Update(struct Solid* p) {
  static const SolidFunc sUpdates1[3] = {
      (SolidFunc)icebon_080ca0b8,
      (SolidFunc)nop_080ca0b4,
      (SolidFunc)nop_080ca0b4,
  };
  static const SolidFunc sUpdates2[3] = {
      (SolidFunc)icebon_080ca0e0,
      (SolidFunc)icebon_080ca104,
      (SolidFunc)icebon_080ca154,
  };

  if (!tryKillIcebon((Object*)p)) {
    s32 delta;

    CreateElementEffect((void*)p);
    (sUpdates1[(p->s).mode[1]])((void*)p);
    (sUpdates2[(p->s).mode[1]])((void*)p);
    (p->s).d.y += PIXEL(1) / 4;
    if ((p->s).d.y > PIXEL(7)) {
      (p->s).d.y = PIXEL(7);
    }
    (p->s).coord.y += (p->s).d.y;

    delta = PushoutToUp2((p->s).coord.x, (p->s).coord.y);
    if (delta < 0) {
      (p->s).d.y = 0;
      (p->s).coord.y = (p->s).coord.y + delta;
    }
  }
}

// --------------------------------------------

void icebonDeath0(struct Solid* p);
void icebonDeath1(struct Solid* p);

static void Icebon_Die(struct Solid* p) {
  static const SolidFunc sIcebonDeathSeq[2] = {
      (SolidFunc)icebonDeath0,
      (SolidFunc)icebonDeath1,
  };
  (sIcebonDeathSeq[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void nop_080ca0b4(void* _ UNUSED) { return; }

static void icebon_080ca0b8(IcebonObject* p) {
  if ((p->elfx == NULL) || isKilled(p->elfx)) {
    p->elfx = NULL;
    p->mode[1] = 1, p->mode[2] = 0;
  }
}

static void icebon_080ca0e0(Object* p) {
  if (p->mode[2] == 0) {
    SetDDP(&p->body, &sIcebonCollisions[2]);
    p->mode[2]++;
  }
}

static void icebon_080ca104(Object* p) {
  switch (p->mode[2]) {
    case 0: {
      SetDDP(&p->body, &sIcebonCollisions[1]);
      SetSpriteAnimation(p, MOTION(SM016_ICEBON, 0));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if (--p->work[2] == 0) {
        p->mode[1] = 2, p->mode[2] = 0;
      }
      break;
    }
  }
}

INCASM("asm/solid/icebon.inc");

// 0x0836fc38
const struct Collision sIcebonCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(16), PIXEL(32), PIXEL(32)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x04,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(32), PIXEL(32)},
    },
};

static const Coords32 Coord_0836fc80 = {PIXEL(0), -PIXEL(16)};

// 0x0836fc88
static const struct Rect sSize = {PIXEL(0), -PIXEL(16), PIXEL(24), PIXEL(32)};

const u8 u8_ARRAY_0836fc90[2] = {1, 0};

// 0x0836FC92
static const motion_t motion_t_ARRAY_0836fc92[4] = {
    MOTION(SM016_ICEBON, 3),
    MOTION(SM016_ICEBON, 4),
    MOTION(SM016_ICEBON, 5),
    MOTION(SM016_ICEBON, 2),
};
