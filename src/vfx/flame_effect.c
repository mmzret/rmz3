#include "entity.h"
#include "global.h"
#include "vfx.h"

struct VFX* CreateFlameEffect(struct Entity* friend, struct Coord* c, u8 r2) {
  struct VFX* g = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, 10);
    (g->s).tileNum = 0;
    (g->s).palID = 0;
    (g->s).unk_28 = friend;
    (g->props).ee.c.x = c->x;
    (g->props).ee.c.y = c->y;
    (g->s).work[2] = r2;
    *(u8*)&(g->props).ee.c.y = r2;
  }

  return g;
}

static NAKED void FlameEffect_Init(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	ldr r4, [r6, #0x28]\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080B4DDA\n\
	adds r0, r4, #0\n\
	adds r0, #0x49\n\
	ldrb r0, [r0]\n\
	adds r3, r6, #0\n\
	adds r3, #0x49\n\
	movs r1, #0xc\n\
	ands r1, r0\n\
	ldrb r2, [r3]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
_080B4DDA:\n\
	adds r1, r6, #0\n\
	adds r1, #0x25\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	adds r0, r6, #0\n\
	movs r1, #0xe\n\
	bl ForceEntityPalette\n\
	ldr r2, _080B4E10 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080B4E14 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080B4E18 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r2, r0, #0x11\n\
	movs r0, #1\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _080B4E1C\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080B4E22\n\
	.align 2, 0\n\
_080B4E10: .4byte RNG_0202f388\n\
_080B4E14: .4byte 0x000343FD\n\
_080B4E18: .4byte 0x00269EC3\n\
_080B4E1C:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080B4E22:\n\
	strb r0, [r6, #0xa]\n\
	movs r4, #1\n\
	movs r5, #1\n\
	adds r1, r5, #0\n\
	ands r1, r2\n\
	adds r0, r6, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r6, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ldr r1, _080B4E70 @ =0x00001B07\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	ldrb r0, [r6, #0xa]\n\
	orrs r4, r0\n\
	strb r4, [r6, #0xa]\n\
	ldr r1, _080B4E74 @ =gVFXFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	str r5, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	adds r0, r6, #0\n\
	bl FlameEffect_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B4E70: .4byte 0x00001B07\n\
_080B4E74: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

static NAKED void FlameEffect_Update(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	ldr r5, [r4, #0x28]\n\
	ldrb r0, [r5, #0xc]\n\
	cmp r0, #1\n\
	bls _080B4E90\n\
	ldrb r1, [r4, #0x12]\n\
	cmp r1, #0xf\n\
	bls _080B4E90\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	strb r0, [r4, #0x12]\n\
_080B4E90:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r2, r0, #1\n\
	strb r2, [r4, #0x12]\n\
	ldr r0, _080B4ED4 @ =wElement\n\
	ldr r0, [r0]\n\
	ldr r1, _080B4ED8 @ =0x00FF00FF\n\
	ands r0, r1\n\
	cmp r0, #2\n\
	bne _080B4EE6\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrb r0, [r0]\n\
	lsls r1, r0, #0x18\n\
	lsls r0, r2, #0x18\n\
	lsrs r3, r0, #0x18\n\
	lsrs r0, r1, #0x19\n\
	cmp r3, r0\n\
	bhi _080B4ECA\n\
	lsrs r0, r1, #0x1a\n\
	cmp r3, r0\n\
	bls _080B4EC2\n\
	movs r0, #1\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080B4ECA\n\
_080B4EC2:\n\
	movs r0, #3\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	bne _080B4EDC\n\
_080B4ECA:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	b _080B4F08\n\
	.align 2, 0\n\
_080B4ED4: .4byte wElement\n\
_080B4ED8: .4byte 0x00FF00FF\n\
_080B4EDC:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	b _080B4F08\n\
_080B4EE6:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080B4F04 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	b _080B4FF4\n\
	.align 2, 0\n\
_080B4F04: .4byte gVFXFnTable\n\
_080B4F08:\n\
	ldrb r3, [r5, #0xa]\n\
	movs r0, #0x40\n\
	ands r0, r3\n\
	mov ip, r3\n\
	cmp r0, #0\n\
	beq _080B4F94\n\
	adds r0, r5, #0\n\
	adds r0, #0x24\n\
	ldrb r1, [r0]\n\
	ldr r2, _080B4F4C @ =gSineTable\n\
	movs r0, #0xff\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r2\n\
	movs r6, #0\n\
	ldrsh r7, [r0, r6]\n\
	movs r0, #0x3f\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r2\n\
	movs r1, #0\n\
	ldrsh r6, [r0, r1]\n\
	movs r0, #0x30\n\
	ands r0, r3\n\
	lsrs r0, r0, #4\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080B4F50\n\
	ldr r0, [r4, #0x74]\n\
	rsbs r3, r0, #0\n\
	b _080B4F52\n\
	.align 2, 0\n\
_080B4F4C: .4byte gSineTable\n\
_080B4F50:\n\
	ldr r3, [r4, #0x74]\n\
_080B4F52:\n\
	movs r0, #0x30\n\
	mov r1, ip\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	movs r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080B4F68\n\
	ldr r0, [r4, #0x78]\n\
	rsbs r2, r0, #0\n\
	b _080B4F6A\n\
_080B4F68:\n\
	ldr r2, [r4, #0x78]\n\
_080B4F6A:\n\
	adds r0, r6, #0\n\
	muls r0, r3, r0\n\
	asrs r0, r0, #8\n\
	ldr r1, [r5, #0x54]\n\
	adds r1, r1, r0\n\
	adds r0, r7, #0\n\
	muls r0, r2, r0\n\
	asrs r0, r0, #8\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x54]\n\
	adds r0, r7, #0\n\
	muls r0, r3, r0\n\
	asrs r0, r0, #8\n\
	ldr r1, [r5, #0x58]\n\
	subs r1, r1, r0\n\
	adds r0, r6, #0\n\
	muls r0, r2, r0\n\
	asrs r0, r0, #8\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x58]\n\
	b _080B4FD2\n\
_080B4F94:\n\
	movs r0, #0x30\n\
	ands r0, r3\n\
	lsrs r0, r0, #4\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080B4FAA\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r4, #0x74]\n\
	subs r0, r0, r1\n\
	b _080B4FB0\n\
_080B4FAA:\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r4, #0x74]\n\
	adds r0, r0, r1\n\
_080B4FB0:\n\
	str r0, [r4, #0x54]\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x30\n\
	ands r1, r0\n\
	lsrs r1, r1, #4\n\
	movs r0, #2\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _080B4FCA\n\
	ldr r0, [r5, #0x58]\n\
	ldr r1, [r4, #0x78]\n\
	subs r0, r0, r1\n\
	b _080B4FD0\n\
_080B4FCA:\n\
	ldr r0, [r5, #0x58]\n\
	ldr r1, [r4, #0x78]\n\
	adds r0, r0, r1\n\
_080B4FD0:\n\
	str r0, [r4, #0x58]\n\
_080B4FD2:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _080B4FE4\n\
	ldrb r0, [r5, #0xc]\n\
	cmp r0, #2\n\
	bls _080B4FF6\n\
_080B4FE4:\n\
	ldr r1, _080B4FFC @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
_080B4FF4:\n\
	str r0, [r4, #0x14]\n\
_080B4FF6:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B4FFC: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

static void FlameEffect_Die(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// clang-format off
const VFXRoutine gFlameEffectRoutine = {
    [ENTITY_INIT] =      FlameEffect_Init,
    [ENTITY_UPDATE] =    FlameEffect_Update,
    [ENTITY_DIE] =       FlameEffect_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on
