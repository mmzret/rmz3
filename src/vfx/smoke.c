#include "global.h"
#include "motion.h"
#include "vfx.h"

/*
  ショットカウンターのミサイル破壊時の煙など
*/

static const u8 sSmokeMotionIdx[8];

static void Smoke_Init(struct VFX* p);
static void Smoke_Update(struct VFX* p);
static void Smoke_Die(struct VFX* p);

// clang-format off
const VFXRoutine gSmokeRoutine = {
    [ENTITY_INIT] =      Smoke_Init,
    [ENTITY_UPDATE] =    Smoke_Update,
    [ENTITY_DIE] =       Smoke_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX* CreateSmoke(u8 kind, struct Coord* c) {
  struct VFX* g = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, 0);
    (g->s).tileNum = 0;
    (g->s).palID = 0;
    ((g->s).coord).x = c->x;
    ((g->s).coord).y = c->y;
    InitNonAffineMotion(&g->s);
    SetMotion(&g->s, MOTION(0, sSmokeMotionIdx[kind]));
  }

  return g;
}

#if MODERN == 0
NAKED static struct VFX* unused_080b2a68(u8 kind, struct Coord* c, bool8 xflip, bool8 yflip) { INCCODE("asm/unused/unused_080b2a68.inc"); }
#endif

NAKED struct VFX* FUN_080b2b40(u8 kind, struct Coord* c, u16 r2, bool8 isDirRight) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r5, r1, #0\n\
	lsls r0, r0, #0x18\n\
	lsrs r7, r0, #0x18\n\
	lsls r2, r2, #0x10\n\
	lsrs r6, r2, #0x10\n\
	lsls r3, r3, #0x10\n\
	lsrs r3, r3, #0x10\n\
	mov r8, r3\n\
	ldr r0, _080B2BB8 @ =gVFXHeaderPtr\n\
	ldr r0, [r0]\n\
	bl AllocEntityFirst\n\
	adds r4, r0, #0\n\
	cmp r4, #0\n\
	beq _080B2C1A\n\
	adds r2, r4, #0\n\
	adds r2, #0x25\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r2]\n\
	ldr r0, _080B2BBC @ =gVFXFnTable\n\
	strb r1, [r4, #9]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0]\n\
	str r0, [r4, #0x14]\n\
	movs r0, #0\n\
	strh r1, [r4, #0x20]\n\
	adds r1, r4, #0\n\
	adds r1, #0x22\n\
	strb r0, [r1]\n\
	ldr r0, [r5]\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r5, #4]\n\
	str r0, [r4, #0x58]\n\
	adds r0, r4, #0\n\
	bl InitScalerotMotion1\n\
	ldr r0, _080B2BC0 @ =sSmokeMotionIdx\n\
	adds r0, r7, r0\n\
	ldrb r1, [r0]\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	adds r0, #0x50\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	mov r1, r8\n\
	lsls r0, r1, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, #0\n\
	beq _080B2BC4\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080B2BCA\n\
	.align 2, 0\n\
_080B2BB8: .4byte gVFXHeaderPtr\n\
_080B2BBC: .4byte gVFXFnTable\n\
_080B2BC0: .4byte sSmokeMotionIdx\n\
_080B2BC4:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080B2BCA:\n\
	strb r0, [r4, #0xa]\n\
	movs r1, #1\n\
	ands r1, r2\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r3, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	mov r0, r8\n\
	lsrs r3, r0, #8\n\
	adds r5, r2, #0\n\
	cmp r3, #0\n\
	beq _080B2BFA\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #0x20\n\
	orrs r0, r1\n\
	b _080B2C00\n\
_080B2BFA:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xdf\n\
	ands r0, r1\n\
_080B2C00:\n\
	strb r0, [r4, #0xa]\n\
	movs r0, #1\n\
	ands r0, r3\n\
	adds r1, r4, #0\n\
	adds r1, #0x4d\n\
	strb r0, [r1]\n\
	lsls r0, r0, #5\n\
	ldrb r2, [r5]\n\
	movs r1, #0x21\n\
	rsbs r1, r1, #0\n\
	ands r1, r2\n\
	orrs r1, r0\n\
	strb r1, [r5]\n\
_080B2C1A:\n\
	adds r0, r4, #0\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED struct VFX* FUN_080b2c28(motion_t m, struct Coord* c, bool8 xflip, bool8 yflip) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r5, r1, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r6, r0, #0x10\n\
	lsls r2, r2, #0x18\n\
	lsrs r7, r2, #0x18\n\
	lsls r3, r3, #0x18\n\
	lsrs r3, r3, #0x18\n\
	mov r8, r3\n\
	ldr r0, _080B2C90 @ =gVFXHeaderPtr\n\
	ldr r0, [r0]\n\
	bl AllocEntityFirst\n\
	adds r4, r0, #0\n\
	cmp r4, #0\n\
	beq _080B2CEC\n\
	adds r2, r4, #0\n\
	adds r2, #0x25\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r2]\n\
	ldr r0, _080B2C94 @ =gVFXFnTable\n\
	strb r1, [r4, #9]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0]\n\
	str r0, [r4, #0x14]\n\
	movs r0, #0\n\
	strh r1, [r4, #0x20]\n\
	adds r1, r4, #0\n\
	adds r1, #0x22\n\
	strb r0, [r1]\n\
	ldr r0, [r5]\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r5, #4]\n\
	str r0, [r4, #0x58]\n\
	adds r0, r4, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	bl SetMotion\n\
	adds r2, r7, #0\n\
	cmp r2, #0\n\
	beq _080B2C98\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080B2C9E\n\
	.align 2, 0\n\
_080B2C90: .4byte gVFXHeaderPtr\n\
_080B2C94: .4byte gVFXFnTable\n\
_080B2C98:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080B2C9E:\n\
	strb r0, [r4, #0xa]\n\
	movs r1, #1\n\
	ands r1, r2\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r3, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	mov r3, r8\n\
	adds r5, r2, #0\n\
	cmp r3, #0\n\
	beq _080B2CCC\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #0x20\n\
	orrs r0, r1\n\
	b _080B2CD2\n\
_080B2CCC:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xdf\n\
	ands r0, r1\n\
_080B2CD2:\n\
	strb r0, [r4, #0xa]\n\
	movs r0, #1\n\
	ands r0, r3\n\
	adds r1, r4, #0\n\
	adds r1, #0x4d\n\
	strb r0, [r1]\n\
	lsls r0, r0, #5\n\
	ldrb r2, [r5]\n\
	movs r1, #0x21\n\
	rsbs r1, r1, #0\n\
	ands r1, r2\n\
	orrs r1, r0\n\
	strb r1, [r5]\n\
_080B2CEC:\n\
	adds r0, r4, #0\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

static void Smoke_Init(struct VFX* p) {
  (p->s).flags |= DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Smoke_Update(p);
}

static void Smoke_Update(struct VFX* p) {
  UpdateMotionGraphic(&p->s);
  if ((p->s).motion.state == MOTION_END) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
  }
}

static void Smoke_Die(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// ------------------------------------------------------------------------------------------------------------------------------------

static const u8 sSmokeMotionIdx[8] = {
    0x00, 0x01, 0x02, 0x03, 0x09, 0x16, 0x17, 0x18,
};
