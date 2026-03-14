#include "collision.h"
#include "global.h"
#include "solid.h"

static const struct Collision sCollisions[2];
static const s32 sSonicWaveXCoords[4];

void ChildreShip_Init(struct Solid* p);
void ChildreShip_Update(struct Solid* p);
static void ChildreShip_Die(struct Solid* p);

// clang-format off
const SolidRoutine gChildreShipRoutine = {
    [ENTITY_INIT] =      ChildreShip_Init,
    [ENTITY_UPDATE] =    ChildreShip_Update,
    [ENTITY_DIE] =       ChildreShip_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

INCASM("asm/solid/childre_ship.inc");

static void ChildreShip_Die(struct Solid* _) { return; }

NAKED void ChildreShip_CreateBubbles(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0xc\n\
	str r0, [sp, #8]\n\
	mov sl, r1\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	movs r4, #6\n\
	ldr r0, _080E0910 @ =gStageRun+232\n\
	mov r1, sp\n\
	bl CalcFromCamera\n\
	movs r1, #0x80\n\
	lsls r1, r1, #8\n\
	cmp r0, r1\n\
	bhi _080E08FE\n\
	ldr r0, _080E0914 @ =gVFXHeaderPtr\n\
	ldr r0, [r0]\n\
	movs r1, #0xa\n\
	ldrsh r0, [r0, r1]\n\
	cmp r0, #0x17\n\
	ble _080E08FE\n\
	cmp r0, #0x2f\n\
	bgt _080E08A4\n\
	movs r4, #2\n\
_080E08A4:\n\
	cmp r4, #0\n\
	beq _080E08FE\n\
	ldr r2, _080E0918 @ =RNG_0202f388\n\
	mov sb, r2\n\
	ldr r6, _080E091C @ =0x000343FD\n\
	ldr r5, _080E0920 @ =0x00269EC3\n\
	ldr r3, _080E0924 @ =0x00001FFF\n\
	mov r8, r3\n\
_080E08B4:\n\
	mov r7, sb\n\
	ldr r0, [r7]\n\
	muls r0, r6, r0\n\
	adds r0, r0, r5\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	lsrs r0, r0, #0x11\n\
	mov r2, r8\n\
	ands r0, r2\n\
	ldr r3, _080E0928 @ =0xFFFFF000\n\
	adds r0, r0, r3\n\
	ldr r7, [sp, #8]\n\
	adds r0, r7, r0\n\
	muls r1, r6, r1\n\
	adds r1, r1, r5\n\
	lsls r1, r1, #1\n\
	lsrs r2, r1, #1\n\
	lsrs r1, r1, #0x11\n\
	mov r3, r8\n\
	ands r1, r3\n\
	ldr r7, _080E0928 @ =0xFFFFF000\n\
	adds r1, r1, r7\n\
	add r1, sl\n\
	muls r2, r6, r2\n\
	adds r2, r2, r5\n\
	lsls r2, r2, #1\n\
	lsrs r3, r2, #1\n\
	mov r7, sb\n\
	str r3, [r7]\n\
	lsrs r2, r2, #0x11\n\
	movs r3, #3\n\
	ands r2, r3\n\
	bl CreateBubble\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bne _080E08B4\n\
_080E08FE:\n\
	add sp, #0xc\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E0910: .4byte gStageRun+232\n\
_080E0914: .4byte gVFXHeaderPtr\n\
_080E0918: .4byte RNG_0202f388\n\
_080E091C: .4byte 0x000343FD\n\
_080E0920: .4byte 0x00269EC3\n\
_080E0924: .4byte 0x00001FFF\n\
_080E0928: .4byte 0xFFFFF000\n\
 .syntax divided\n");
}

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(56), PIXEL(56)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(64), PIXEL(64)},
    },
};

static const s32 sSonicWaveXCoords[4] = {
    PIXEL(2984),
    PIXEL(4696),
    PIXEL(8600),
    PIXEL(9736),
};
