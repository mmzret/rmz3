#include "entity.h"
#include "global.h"
#include "vfx.h"

static void Ghost9_Init(struct VFX* p);
static void Ghost9_Update(struct VFX* p);
static void Ghost9_Die(struct VFX* p);

// clang-format off
const VFXRoutine gThunderEffectRoutine = {
    [ENTITY_INIT] =      Ghost9_Init,
    [ENTITY_MAIN] =      Ghost9_Update,
    [ENTITY_DIE] =       Ghost9_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX* CreateThunderEffect(struct Entity* friend, struct Coord* c, u8 r2) {
  struct VFX* g = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, 9);
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

static void Ghost9_Init(struct VFX* p) {
  InitNonAffineMotion(&p->s);
  SetMotion(&p->s, MOTION(SM026_UNK, 0x05));
  (p->s).flags |= DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_MAIN);
  Ghost9_Update(p);
}

NAKED static void Ghost9_Update(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	ldr r6, [r4, #0x28]\n\
	ldrb r0, [r6, #0xc]\n\
	cmp r0, #1\n\
	bls _080B4BA8\n\
	ldrb r1, [r4, #0x12]\n\
	cmp r1, #0xf\n\
	bls _080B4BA8\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	strb r0, [r4, #0x12]\n\
_080B4BA8:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r2, r0, #1\n\
	strb r2, [r4, #0x12]\n\
	ldr r0, _080B4BEC @ =wElement\n\
	ldr r1, [r0]\n\
	ldr r0, _080B4BF0 @ =0x00FF00FF\n\
	ands r1, r0\n\
	cmp r1, #1\n\
	bne _080B4BFE\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrb r0, [r0]\n\
	lsls r3, r0, #0x18\n\
	lsls r0, r2, #0x18\n\
	lsrs r5, r0, #0x18\n\
	lsrs r0, r3, #0x19\n\
	cmp r5, r0\n\
	bhi _080B4BE2\n\
	lsrs r0, r3, #0x1a\n\
	cmp r5, r0\n\
	bls _080B4BDA\n\
	ands r1, r2\n\
	lsls r0, r1, #0x18\n\
	cmp r0, #0\n\
	beq _080B4BE2\n\
_080B4BDA:\n\
	movs r0, #3\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	bne _080B4BF4\n\
_080B4BE2:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	b _080B4C20\n\
	.align 2, 0\n\
_080B4BEC: .4byte wElement\n\
_080B4BF0: .4byte 0x00FF00FF\n\
_080B4BF4:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	b _080B4C20\n\
_080B4BFE:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080B4C1C @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	b _080B4D24\n\
	.align 2, 0\n\
_080B4C1C: .4byte gVFXFnTable\n\
_080B4C20:\n\
	movs r0, #8\n\
	ldrsb r0, [r6, r0]\n\
	cmp r0, #2\n\
	beq _080B4C2E\n\
	ldrb r0, [r6, #9]\n\
	cmp r0, #0xd\n\
	bne _080B4C38\n\
_080B4C2E:\n\
	ldr r0, [r6, #0x54]\n\
	ldr r1, [r4, #0x74]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	b _080B4CFA\n\
_080B4C38:\n\
	ldrb r3, [r6, #0xa]\n\
	movs r0, #0x40\n\
	ands r0, r3\n\
	mov ip, r3\n\
	cmp r0, #0\n\
	beq _080B4CC4\n\
	adds r0, r6, #0\n\
	adds r0, #0x24\n\
	ldrb r1, [r0]\n\
	ldr r2, _080B4C7C @ =gSineTable\n\
	movs r0, #0xff\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r2\n\
	movs r5, #0\n\
	ldrsh r7, [r0, r5]\n\
	movs r0, #0x3f\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r2\n\
	movs r1, #0\n\
	ldrsh r5, [r0, r1]\n\
	movs r0, #0x30\n\
	ands r0, r3\n\
	lsrs r0, r0, #4\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080B4C80\n\
	ldr r0, [r4, #0x74]\n\
	rsbs r3, r0, #0\n\
	b _080B4C82\n\
	.align 2, 0\n\
_080B4C7C: .4byte gSineTable\n\
_080B4C80:\n\
	ldr r3, [r4, #0x74]\n\
_080B4C82:\n\
	movs r0, #0x30\n\
	mov r1, ip\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	movs r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080B4C98\n\
	ldr r0, [r4, #0x78]\n\
	rsbs r2, r0, #0\n\
	b _080B4C9A\n\
_080B4C98:\n\
	ldr r2, [r4, #0x78]\n\
_080B4C9A:\n\
	adds r0, r5, #0\n\
	muls r0, r3, r0\n\
	asrs r0, r0, #8\n\
	ldr r1, [r6, #0x54]\n\
	adds r1, r1, r0\n\
	adds r0, r7, #0\n\
	muls r0, r2, r0\n\
	asrs r0, r0, #8\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x54]\n\
	adds r0, r7, #0\n\
	muls r0, r3, r0\n\
	asrs r0, r0, #8\n\
	ldr r1, [r6, #0x58]\n\
	subs r1, r1, r0\n\
	adds r0, r5, #0\n\
	muls r0, r2, r0\n\
	asrs r0, r0, #8\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x58]\n\
	b _080B4D02\n\
_080B4CC4:\n\
	movs r0, #0x30\n\
	ands r0, r3\n\
	lsrs r0, r0, #4\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080B4CDA\n\
	ldr r0, [r6, #0x54]\n\
	ldr r1, [r4, #0x74]\n\
	subs r0, r0, r1\n\
	b _080B4CE0\n\
_080B4CDA:\n\
	ldr r0, [r6, #0x54]\n\
	ldr r1, [r4, #0x74]\n\
	adds r0, r0, r1\n\
_080B4CE0:\n\
	str r0, [r4, #0x54]\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #0x30\n\
	ands r1, r0\n\
	lsrs r1, r1, #4\n\
	movs r0, #2\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _080B4CFA\n\
	ldr r0, [r6, #0x58]\n\
	ldr r1, [r4, #0x78]\n\
	subs r0, r0, r1\n\
	b _080B4D00\n\
_080B4CFA:\n\
	ldr r0, [r6, #0x58]\n\
	ldr r1, [r4, #0x78]\n\
	adds r0, r0, r1\n\
_080B4D00:\n\
	str r0, [r4, #0x58]\n\
_080B4D02:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _080B4D14\n\
	ldrb r0, [r6, #0xc]\n\
	cmp r0, #2\n\
	bls _080B4D26\n\
_080B4D14:\n\
	ldr r1, _080B4D2C @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
_080B4D24:\n\
	str r0, [r4, #0x14]\n\
_080B4D26:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B4D2C: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

static void Ghost9_Die(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}
