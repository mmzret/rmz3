#include "entity.h"
#include "global.h"
#include "vfx.h"

static void IceEffect_Init(struct VFX* p);
static void IceEffect_Update(struct VFX* p);
static void IceEffect_Die(struct VFX* p);

// clang-format off
const VFXRoutine gIceEffectRoutine = {
    [ENTITY_INIT] =      IceEffect_Init,
    [ENTITY_UPDATE] =    IceEffect_Update,
    [ENTITY_DIE] =       IceEffect_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX* CreateIceEffect(struct Entity* friend, struct Coord* c, u8 r2) {
  struct VFX* g = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, 11);
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

NAKED static void IceEffect_Init(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	bl InitNonAffineMotion\n\
	ldr r2, _080B50A8 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080B50AC @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080B50B0 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r2, r0, #0x11\n\
	movs r0, #1\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _080B50B4\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0x10\n\
	orrs r0, r1\n\
	b _080B50BA\n\
	.align 2, 0\n\
_080B50A8: .4byte RNG_0202f388\n\
_080B50AC: .4byte 0x000343FD\n\
_080B50B0: .4byte 0x00269EC3\n\
_080B50B4:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080B50BA:\n\
	strb r0, [r5, #0xa]\n\
	movs r4, #1\n\
	adds r1, r2, #0\n\
	adds r0, r5, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r5, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ldr r2, _080B50FC @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080B5100 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080B5104 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r6, r0, #0x11\n\
	ands r6, r4\n\
	adds r4, r2, #0\n\
	cmp r6, #0\n\
	beq _080B5108\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x20\n\
	orrs r0, r1\n\
	b _080B510E\n\
	.align 2, 0\n\
_080B50FC: .4byte RNG_0202f388\n\
_080B5100: .4byte 0x000343FD\n\
_080B5104: .4byte 0x00269EC3\n\
_080B5108:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xdf\n\
	ands r0, r1\n\
_080B510E:\n\
	strb r0, [r5, #0xa]\n\
	adds r1, r6, #0\n\
	adds r2, r5, #0\n\
	adds r2, #0x4d\n\
	strb r1, [r2]\n\
	lsls r1, r1, #5\n\
	ldrb r2, [r3]\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ldr r1, [r4]\n\
	ldr r0, _080B514C @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080B5150 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r4]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080B5158\n\
	ldr r1, _080B5154 @ =0x00001C01\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	b _080B5160\n\
	.align 2, 0\n\
_080B514C: .4byte 0x000343FD\n\
_080B5150: .4byte 0x00269EC3\n\
_080B5154: .4byte 0x00001C01\n\
_080B5158:\n\
	ldr r1, _080B5188 @ =0x00001C02\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
_080B5160:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _080B518C @ =gVFXFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	adds r0, r5, #0\n\
	bl IceEffect_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B5188: .4byte 0x00001C02\n\
_080B518C: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

NAKED static void IceEffect_Update(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	ldr r5, [r4, #0x28]\n\
	ldrb r0, [r5, #0xc]\n\
	cmp r0, #1\n\
	bls _080B51A8\n\
	ldrb r1, [r4, #0x12]\n\
	cmp r1, #0xf\n\
	bls _080B51A8\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	strb r0, [r4, #0x12]\n\
_080B51A8:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r1, r0, #1\n\
	strb r1, [r4, #0x12]\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrb r0, [r0]\n\
	lsls r2, r0, #0x18\n\
	lsls r0, r1, #0x18\n\
	lsrs r3, r0, #0x18\n\
	lsrs r0, r2, #0x19\n\
	cmp r3, r0\n\
	bhi _080B51D6\n\
	lsrs r0, r2, #0x1a\n\
	cmp r3, r0\n\
	bls _080B51CE\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080B51D6\n\
_080B51CE:\n\
	movs r0, #3\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _080B51DE\n\
_080B51D6:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	b _080B51E4\n\
_080B51DE:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
_080B51E4:\n\
	strb r0, [r4, #0xa]\n\
	ldrb r3, [r5, #0xa]\n\
	movs r0, #0x40\n\
	ands r0, r3\n\
	mov ip, r3\n\
	cmp r0, #0\n\
	beq _080B5274\n\
	adds r0, r5, #0\n\
	adds r0, #0x24\n\
	ldrb r1, [r0]\n\
	ldr r2, _080B522C @ =gSineTable\n\
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
	beq _080B5230\n\
	ldr r0, [r4, #0x74]\n\
	rsbs r3, r0, #0\n\
	b _080B5232\n\
	.align 2, 0\n\
_080B522C: .4byte gSineTable\n\
_080B5230:\n\
	ldr r3, [r4, #0x74]\n\
_080B5232:\n\
	movs r0, #0x30\n\
	mov r1, ip\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	movs r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080B5248\n\
	ldr r0, [r4, #0x78]\n\
	rsbs r2, r0, #0\n\
	b _080B524A\n\
_080B5248:\n\
	ldr r2, [r4, #0x78]\n\
_080B524A:\n\
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
	b _080B52B2\n\
_080B5274:\n\
	movs r0, #0x30\n\
	ands r0, r3\n\
	lsrs r0, r0, #4\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080B528A\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r4, #0x74]\n\
	subs r0, r0, r1\n\
	b _080B5290\n\
_080B528A:\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r4, #0x74]\n\
	adds r0, r0, r1\n\
_080B5290:\n\
	str r0, [r4, #0x54]\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x30\n\
	ands r1, r0\n\
	lsrs r1, r1, #4\n\
	movs r0, #2\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _080B52AA\n\
	ldr r0, [r5, #0x58]\n\
	ldr r1, [r4, #0x78]\n\
	subs r0, r0, r1\n\
	b _080B52B0\n\
_080B52AA:\n\
	ldr r0, [r5, #0x58]\n\
	ldr r1, [r4, #0x78]\n\
	adds r0, r0, r1\n\
_080B52B0:\n\
	str r0, [r4, #0x58]\n\
_080B52B2:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _080B52C4\n\
	ldrb r0, [r5, #0xc]\n\
	cmp r0, #2\n\
	bls _080B52D6\n\
_080B52C4:\n\
	ldr r1, _080B52DC @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
_080B52D6:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B52DC: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

NAKED static void IceEffect_Die(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	ldrb r0, [r6, #0xd]\n\
	cmp r0, #0\n\
	bne _080B534C\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #5\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	movs r0, #0x3f\n\
	bl isSoundPlaying\n\
	cmp r0, #0\n\
	bne _080B5304\n\
	movs r0, #0x3f\n\
	bl PlaySound\n\
_080B5304:\n\
	ldr r5, _080B5360 @ =RNG_0202f388\n\
	ldr r0, [r5]\n\
	ldr r3, _080B5364 @ =0x000343FD\n\
	muls r0, r3, r0\n\
	ldr r2, _080B5368 @ =0x00269EC3\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #1\n\
	lsrs r4, r0, #1\n\
	lsls r0, r0, #5\n\
	lsrs r0, r0, #0x16\n\
	ldr r1, _080B536C @ =0xFFFFFE00\n\
	adds r0, r0, r1\n\
	str r0, [r6, #0x5c]\n\
	adds r0, r4, #0\n\
	muls r0, r3, r0\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #1\n\
	lsrs r4, r0, #1\n\
	lsls r0, r0, #6\n\
	lsrs r0, r0, #0x17\n\
	subs r1, r1, r0\n\
	str r1, [r6, #0x60]\n\
	adds r0, r4, #0\n\
	muls r0, r3, r0\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r5]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #0x1f\n\
	ands r0, r1\n\
	adds r0, #0x20\n\
	strb r0, [r6, #0x12]\n\
	ldrb r0, [r6, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r6, #0xd]\n\
_080B534C:\n\
	ldrb r0, [r6, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r6, #0x12]\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080B5370\n\
	ldrb r0, [r6, #0xa]\n\
	orrs r0, r1\n\
	b _080B5376\n\
	.align 2, 0\n\
_080B5360: .4byte RNG_0202f388\n\
_080B5364: .4byte 0x000343FD\n\
_080B5368: .4byte 0x00269EC3\n\
_080B536C: .4byte 0xFFFFFE00\n\
_080B5370:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
_080B5376:\n\
	strb r0, [r6, #0xa]\n\
	ldr r0, [r6, #0x54]\n\
	ldr r1, [r6, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r6, #0x54]\n\
	ldr r0, [r6, #0x58]\n\
	ldr r1, [r6, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r6, #0x58]\n\
	adds r1, #0x40\n\
	str r1, [r6, #0x60]\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r6, #0x12]\n\
	cmp r0, #0\n\
	beq _080B53A6\n\
	ldr r0, [r6, #0x54]\n\
	ldr r1, [r6, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080B53B8\n\
_080B53A6:\n\
	ldr r1, _080B53C0 @ =gVFXFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #4\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x10]\n\
	str r0, [r6, #0x14]\n\
_080B53B8:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B53C0: .4byte gVFXFnTable\n\
 .syntax divided\n");
}
