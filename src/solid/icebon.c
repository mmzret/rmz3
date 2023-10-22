#include "collision.h"
#include "element.h"
#include "global.h"
#include "overworld_terrain.h"
#include "solid.h"

static const SolidFunc sIcebonDeathSeq[2];
const struct Collision sIcebonCollisions[3];

static void Icebon_Init(struct Solid* p);
static void Icebon_Update(struct Solid* p);
static void Icebon_Die(struct Solid* p);

// clang-format off
const SolidRoutine gIcebonRoutine = {
    [ENTITY_INIT] =      Icebon_Init,
    [ENTITY_UPDATE] =    Icebon_Update,
    [ENTITY_DIE] =       Icebon_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

void nop_080c9e90(struct Body* _ UNUSED) { return; }

NAKED void icebon_080c9e94(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	adds r6, r4, #0\n\
	adds r6, #0xb4\n\
	ldr r5, [r6]\n\
	cmp r5, #0\n\
	bne _080C9EE2\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080C9EE2\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, _080C9EE8 @ =0xFFFFF100\n\
	adds r0, r0, r1\n\
	ldr r1, _080C9EEC @ =gOverworld\n\
	ldr r2, _080C9EF0 @ =0x0002C00C\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	cmp r0, r1\n\
	ble _080C9ECE\n\
	adds r0, r4, #0\n\
	adds r0, #0x97\n\
	ldrb r1, [r0]\n\
	movs r0, #0xf0\n\
	ands r0, r1\n\
	cmp r0, #0x20\n\
	beq _080C9EE2\n\
_080C9ECE:\n\
	ldr r2, _080C9EF4 @ =0x0836FC80\n\
	movs r0, #0\n\
	adds r1, r4, #0\n\
	bl ApplyElementEffect\n\
	str r0, [r6]\n\
	cmp r0, #0\n\
	beq _080C9EE2\n\
	strb r5, [r4, #0xd]\n\
	strb r5, [r4, #0xe]\n\
_080C9EE2:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C9EE8: .4byte 0xFFFFF100\n\
_080C9EEC: .4byte gOverworld\n\
_080C9EF0: .4byte 0x0002C00C\n\
_080C9EF4: .4byte 0x0836FC80\n\
 .syntax divided\n");
}

NAKED bool8 tryKillIcebon(struct Solid* p) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	adds r3, r2, #0\n\
	adds r3, #0x8c\n\
	ldr r0, [r3]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080C9F40\n\
	ldr r1, _080C9F30 @ =gSolidFnTable\n\
	ldrb r0, [r2, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r2, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r2, #0x14]\n\
	ldr r1, [r3]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _080C9F34\n\
	movs r0, #1\n\
	strb r0, [r2, #0xd]\n\
	b _080C9F36\n\
	.align 2, 0\n\
_080C9F30: .4byte gSolidFnTable\n\
_080C9F34:\n\
	strb r1, [r2, #0xd]\n\
_080C9F36:\n\
	adds r0, r2, #0\n\
	bl Icebon_Die\n\
	movs r0, #1\n\
	b _080C9F42\n\
_080C9F40:\n\
	movs r0, #0\n\
_080C9F42:\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
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
	ldr r0, _080C9FC0 @ =0x0836FC88\n\
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
	ldr r1, _080C9FC8 @ =0x0836FC90\n\
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
	ldr r0, _080C9FCC @ =gSystemSavedataManager\n\
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
	ldr r1, _080C9FD4 @ =0x0836FC38\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0xc\n\
	b _080C9FF0\n\
	.align 2, 0\n\
_080C9FC0: .4byte 0x0836FC88\n\
_080C9FC4: .4byte gSolidFnTable\n\
_080C9FC8: .4byte 0x0836FC90\n\
_080C9FCC: .4byte gSystemSavedataManager\n\
_080C9FD0: .4byte gCurStory\n\
_080C9FD4: .4byte 0x0836FC38\n\
_080C9FD8:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #4\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _080CA024 @ =0x0836FC38\n\
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
_080CA024: .4byte 0x0836FC38\n\
_080CA028: .4byte nop_080c9e90\n\
 .syntax divided\n");
}

// --------------------------------------------

static void icebon_080ca0b8(struct Solid* p);
static void nop_080ca0b4(struct Solid* _ UNUSED);

static void icebon_080ca0e0(struct Solid* p);
void icebon_080ca104(struct Solid* p);
void icebon_080ca154(struct Solid* p);

static void Icebon_Update(struct Solid* p) {
  static const SolidFunc sUpdates1[3] = {
      icebon_080ca0b8,
      nop_080ca0b4,
      nop_080ca0b4,
  };
  static const SolidFunc sUpdates2[3] = {
      icebon_080ca0e0,
      icebon_080ca104,
      icebon_080ca154,
  };

  if (!tryKillIcebon(p)) {
    s32 delta;

    icebon_080c9e94(p);
    (sUpdates1[(p->s).mode[1]])(p);
    (sUpdates2[(p->s).mode[1]])(p);
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

static const SolidFunc sIcebonDeathSeq[2] = {
    icebonDeath0,
    icebonDeath1,
};

static void Icebon_Die(struct Solid* p) {
  (sIcebonDeathSeq[(p->s).mode[1]])(p);
  return;
}

static void nop_080ca0b4(struct Solid* _ UNUSED) { return; }

NAKED static void icebon_080ca0b8(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	adds r5, r4, #0\n\
	adds r5, #0xb4\n\
	ldr r0, [r5]\n\
	cmp r0, #0\n\
	beq _080CA0CE\n\
	bl isKilled\n\
	cmp r0, #0\n\
	beq _080CA0D8\n\
_080CA0CE:\n\
	movs r1, #0\n\
	str r1, [r5]\n\
	movs r0, #1\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_080CA0D8:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void icebon_080ca0e0(struct Solid* p) {
  if ((p->s).mode[2] == 0) {
    SetDDP(&p->body, &sIcebonCollisions[2]);
    (p->s).mode[2]++;
  }
}

INCASM("asm/solid/icebon.inc");

const struct Collision sIcebonCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1000, 0x2000, 0x2000},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x04,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x1000, 0x2000, 0x2000},
    },
};

const struct Coord Coord_0836fc80 = {0x0000, -0x1000};
const struct Coord Coord_0836fc88 = {-0x10000000, 0x20001800};

const u8 u8_ARRAY_0836fc90[2] = {1, 0};

const motion_t motion_t_ARRAY_0836fc92[4] = {
    MOTION(SM016_ICEBON, 3),
    MOTION(SM016_ICEBON, 4),
    MOTION(SM016_ICEBON, 5),
    MOTION(SM016_ICEBON, 2),
};
