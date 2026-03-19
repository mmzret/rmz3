#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

void Solid17_Init(struct Solid* p);
void Solid17_Update(struct Solid* p);
void Solid17_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid17Routine = {
    [ENTITY_INIT] =      Solid17_Init,
    [ENTITY_UPDATE] =    Solid17_Update,
    [ENTITY_DIE] =       Solid17_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

// 0x080cf098
NAKED static void onCollision(struct Body* body, struct Coord* c1, struct Coord* c2) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r3, r0, #0\n\
	ldr r0, [r3, #0xc]\n\
	ldr r4, [r0, #0x2c]\n\
	ldr r2, [r3, #0x2c]\n\
	ldr r0, [r3, #0x14]\n\
	movs r1, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080CF0CE\n\
	movs r0, #8\n\
	ldrsb r0, [r4, r0]\n\
	cmp r0, #0\n\
	bne _080CF0CE\n\
	ldr r0, _080CF0F4 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r1, [r0, #0x58]\n\
	ldr r0, [r2, #0x58]\n\
	cmp r1, r0\n\
	bgt _080CF0CE\n\
	movs r1, #1\n\
	strb r1, [r2, #0x12]\n\
	ldrb r0, [r2, #0xd]\n\
	cmp r0, #0\n\
	bne _080CF0CE\n\
	strb r1, [r2, #0xd]\n\
	strb r0, [r2, #0xe]\n\
_080CF0CE:\n\
	ldr r0, [r3, #0x14]\n\
	movs r1, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080CF0EE\n\
	ldrh r1, [r4, #8]\n\
	ldr r0, _080CF0F8 @ =0x00001106\n\
	cmp r1, r0\n\
	bne _080CF0EE\n\
	ldrb r0, [r2, #0xd]\n\
	cmp r0, #1\n\
	bne _080CF0EE\n\
	movs r1, #0\n\
	movs r0, #2\n\
	strb r0, [r2, #0xd]\n\
	strb r1, [r2, #0xe]\n\
_080CF0EE:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080CF0F4: .4byte pZero2\n\
_080CF0F8: .4byte 0x00001106\n\
 .syntax divided\n");
}

INCASM("asm/solid/unk_17.inc");

// --------------------------------------------

void nop_080cf208(struct Solid* p);

const SolidFunc sSolid17Updates1[3] = {
    nop_080cf208,
    nop_080cf208,
    nop_080cf208,
};

// --------------------------------------------

void FUN_080cf20c(struct Solid* p);
void FUN_080cf250(struct Solid* p);
void FUN_080cf378(struct Solid* p);

const SolidFunc sSolid17Updates2[3] = {
    FUN_080cf20c,
    FUN_080cf250,
    FUN_080cf378,
};

// --------------------------------------------

const struct Collision sSolid17Collisions[3] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 255,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0C00, 0x1E00, 0x2000},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0E00, 0x1E00, 0x1C00},
    },
};

// --------------------------------------------

// clang-format off
const motion_t sSolid17Motions[3][4] = {
    {
        MOTION(0x6C, 0x06),
        MOTION(0x6C, 0x04),
        MOTION(0x6C, 0x02),
        MOTION(0x6C, 0x08),
    },
    {
        MOTION(0x6C, 0x07),
        MOTION(0x6C, 0x05),
        MOTION(0x6C, 0x03),
        MOTION(0x6C, 0x09),
    },
    {
        MOTION(0x6C, 0x0C),
        MOTION(0x6C, 0x0B),
        MOTION(0x6C, 0x0A),
        MOTION(0x6C, 0x0D),
    },
};
// clang-format on

// --------------------------------------------

const struct Rect Rect_0837061c = {0x0, 0xE00, 0x1E00, 0x1C00};
const u8 u8_ARRAY_08370624[4] = {0, 0, 0, 0};

// clang-format off
const struct Rect Rect_ARRAY_08370628[6] = {
    { 0x0000, 0x0100, -0x0100, 0x0000 },
    { 0x0000, -0x0100, 0x0100, 0x0000 },
    { -0x0F00, 0x1C00, 0x0F00, 0x1C00 },
    { -0x0F00, 0x0000, -0x0F00, 0x1C00 },
    { -0x0F00, 0x0000, 0x0F00, 0x0000 },
    { 0x0F00, 0x0000, 0x0F00, 0x1C00 },
};
// clang-format on
