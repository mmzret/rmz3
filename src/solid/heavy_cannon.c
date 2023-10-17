#include "collision.h"
#include "global.h"
#include "solid.h"

// ------------------------------------------------------------------------------------------------------------------------------------

void initHeavyCannon(struct Solid* p);
void heavyCannonAI(struct Solid* p);
void killHeavyCannon(struct Solid* p);
void FUN_080cc284(struct Solid* p);

// clang-format off
const SolidRoutine gHeavyCannonRoutine = {
    [ENTITY_INIT] =      initHeavyCannon,
    [ENTITY_UPDATE] =    heavyCannonAI,
    [ENTITY_DIE] =       killHeavyCannon,
    [ENTITY_DISAPPEAR] = FUN_080cc284,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

NAKED struct Enemy* FUN_080cbdc0(struct Enemy* pair) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r2, r0, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080CBE30\n\
	ldrb r0, [r2, #0x10]\n\
	cmp r0, #3\n\
	bhi _080CBE00\n\
	ldr r1, [r2, #0x2c]\n\
	ldr r5, _080CBDFC @ =gSolidFnTable\n\
	cmp r1, #0\n\
	beq _080CBE12\n\
	adds r4, r5, #0\n\
	movs r3, #2\n\
_080CBDE4:\n\
	ldrb r0, [r1, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	str r3, [r1, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r1, #0x14]\n\
	ldr r1, [r1, #0x2c]\n\
	cmp r1, #0\n\
	bne _080CBDE4\n\
	b _080CBE12\n\
	.align 2, 0\n\
_080CBDFC: .4byte gSolidFnTable\n\
_080CBE00:\n\
	ldr r0, [r2, #0x28]\n\
	ldr r1, [r2, #0x2c]\n\
	cmp r0, #0\n\
	beq _080CBE0A\n\
	str r1, [r0, #0x2c]\n\
_080CBE0A:\n\
	ldr r5, _080CBE2C @ =gSolidFnTable\n\
	cmp r1, #0\n\
	beq _080CBE12\n\
	str r0, [r1, #0x28]\n\
_080CBE12:\n\
	ldrb r0, [r2, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	movs r1, #2\n\
	str r1, [r2, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r2, #0x14]\n\
	adds r0, r2, #0\n\
	bl killHeavyCannon\n\
	movs r0, #1\n\
	b _080CBE32\n\
	.align 2, 0\n\
_080CBE2C: .4byte gSolidFnTable\n\
_080CBE30:\n\
	movs r0, #0\n\
_080CBE32:\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

INCASM("asm/solid/heavy_cannon.inc");

// --------------------------------------------

void FUN_080cc298(struct Solid* p);
void FUN_080cc2d4(struct Solid* p);

const SolidFunc gHeavyCannonUpdates1[3] = {
    FUN_080cc298,
    FUN_080cc298,
    FUN_080cc2d4,
};

// --------------------------------------------

void FUN_080cc320(struct Solid* p);
void FUN_080cc4dc(struct Solid* p);
void FUN_080cc51c(struct Solid* p);

const SolidFunc gHeavyCannonUpdates2[3] = {
    FUN_080cc320,
    FUN_080cc4dc,
    FUN_080cc51c,
};

// --------------------------------------------

const struct Collision gHeavyCannonCollisions[6] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x0500, 0x1A00, 0x1000},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x0500, 0x1A00, 0x1000},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, -0x1900, 0x1600, 0x0800},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x0C00, 0x1A00, 0x1F00},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x0800, 0x1A00, 0x1700},
    },
};

const u8 u8_ARRAY_0836ff1c[6] = {0, 0, 0, 0, 1, 0};

const motion_t gHeavyCannonMotions[3] = {
    MOTION(SM056_HEAVY_CANNON, 0x05),
    MOTION(SM056_HEAVY_CANNON, 0x06),
    MOTION(SM056_HEAVY_CANNON, 0x07),
};

const struct Coord Coord_0836ff28 = {0x0, -0x800};

const struct Rect Rect_ARRAY_0836ff30[2] = {
    {0x0000, 0x0900, 0x1600, 0x4000},
    {0x0000, 0x0A00, 0x1600, 0x1A00},
};
