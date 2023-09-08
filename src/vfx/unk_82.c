#include "entity.h"
#include "global.h"
#include "vfx.h"

static void Ghost82_Init(struct VFX* p);
static void Ghost82_Update(struct VFX* p);
static void Ghost82_Die(struct VFX* p);

// clang-format off
const VFXRoutine gGhost82Routine = {
    [ENTITY_INIT] =      Ghost82_Init,
    [ENTITY_MAIN] =      Ghost82_Update,
    [ENTITY_DIE] =       Ghost82_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// Unused
static struct VFX* CreateGhost82_1(struct Coord* c, u8 r1) {
  struct VFX* g = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, VFX_UNK_082);
    (g->s).tileNum = 0;
    (g->s).palID = 0;
    (g->s).work[0] = r1;
    (g->s).work[1] = 0;
    (g->s).coord.x = c->x;
    (g->s).coord.y = c->y;
  }
  return g;
}

struct VFX* CreateGhost82_2(struct Coord* c, u8 r1, u16 r2, s32 y) {
  struct VFX* g = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, VFX_UNK_082);
    (g->s).tileNum = 0;
    (g->s).palID = 0;
    (g->s).work[0] = r1;
    (g->s).work[1] = 1;
    (g->s).coord.x = c->x;
    (g->s).coord.y = c->y;
    (g->props).unk28.unk_0 = r2;
    (g->props).unk28.unk_4 = y;
  }
  return g;
}

// --------------------------------------------

NAKED static void Ghost82_Init(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	movs r3, #0\n\
	adds r2, r0, #0\n\
	orrs r2, r1\n\
	movs r0, #2\n\
	orrs r2, r0\n\
	orrs r2, r3\n\
	strb r2, [r4, #0xa]\n\
	ldrb r1, [r4, #0x10]\n\
	cmp r1, #0\n\
	bne _080C96FC\n\
	movs r0, #0xef\n\
	ands r2, r0\n\
	strb r2, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	b _080C971C\n\
_080C96FC:\n\
	movs r1, #1\n\
	movs r0, #0x10\n\
	orrs r2, r0\n\
	strb r2, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r4, #0\n\
	adds r3, #0x4a\n\
	movs r2, #0x10\n\
	ldrb r1, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strb r0, [r3]\n\
_080C971C:\n\
	ldrb r0, [r4, #0x10]\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	bne _080C972A\n\
	movs r0, #0x80\n\
	rsbs r0, r0, #0\n\
	b _080C972C\n\
_080C972A:\n\
	movs r0, #0x80\n\
_080C972C:\n\
	str r0, [r4, #0x5c]\n\
	movs r2, #0\n\
	str r2, [r4, #0x60]\n\
	ldrb r0, [r4, #0x11]\n\
	cmp r0, #0\n\
	bne _080C9758\n\
	movs r0, #0xff\n\
	strb r0, [r4, #0x12]\n\
	ldr r1, _080C9754 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	strb r1, [r4, #0xd]\n\
	b _080C97B0\n\
	.align 2, 0\n\
_080C9754: .4byte gVFXFnTable\n\
_080C9758:\n\
	lsls r0, r1, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, #2\n\
	bne _080C9766\n\
	movs r0, #1\n\
	strb r0, [r4, #0x11]\n\
	b _080C976C\n\
_080C9766:\n\
	cmp r1, #1\n\
	bne _080C9774\n\
	strb r1, [r4, #0x11]\n\
_080C976C:\n\
	adds r0, r4, #0\n\
	adds r0, #0x22\n\
	strb r1, [r0]\n\
	b _080C977C\n\
_080C9774:\n\
	strb r2, [r4, #0x11]\n\
	adds r0, r4, #0\n\
	adds r0, #0x22\n\
	strb r2, [r0]\n\
_080C977C:\n\
	ldr r2, _080C97C0 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080C97C4 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080C97C8 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #7\n\
	ands r0, r1\n\
	adds r0, #0x7f\n\
	movs r2, #0\n\
	strb r0, [r4, #0x12]\n\
	ldr r1, _080C97CC @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	movs r0, #2\n\
	strb r0, [r4, #0xd]\n\
_080C97B0:\n\
	strb r2, [r4, #0xe]\n\
	strb r2, [r4, #0xf]\n\
	adds r0, r4, #0\n\
	bl Ghost82_Update\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C97C0: .4byte RNG_0202f388\n\
_080C97C4: .4byte 0x000343FD\n\
_080C97C8: .4byte 0x00269EC3\n\
_080C97CC: .4byte gVFXFnTable\n\
   .syntax divided\n");
}

// --------------------------------------------

static void FUN_080c9808(struct VFX* p);
static void FUN_080c980c(struct VFX* p);
static void FUN_080c98e8(struct VFX* p);

void Ghost82_Update(struct VFX* vfx) {
  static VFXFunc const sUpdates[] = {
      FUN_080c9808,
      FUN_080c980c,
      FUN_080c98e8,
  };
  (sUpdates[(vfx->s).mode[1]])(vfx);
}

// --------------------------------------------

static void Ghost82_Die(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_080c9808(struct VFX* p) { return; }

NAKED static void FUN_080c980c(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #8\n\
	adds r6, r0, #0\n\
	ldrb r0, [r6, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r6, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080C989C\n\
	adds r1, r6, #0\n\
	adds r1, #0x54\n\
	movs r0, #2\n\
	bl CreateSmoke\n\
	ldr r2, _080C9884 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080C9888 @ =0x000343FD\n\
	adds r4, r1, #0\n\
	muls r4, r0, r4\n\
	ldr r0, _080C988C @ =0x00269EC3\n\
	adds r4, r4, r0\n\
	lsls r4, r4, #1\n\
	lsrs r0, r4, #1\n\
	str r0, [r2]\n\
	lsrs r4, r4, #0x11\n\
	movs r0, #3\n\
	ands r4, r0\n\
	ldr r0, [r6, #0x54]\n\
	str r0, [sp]\n\
	ldr r0, [r6, #0x58]\n\
	str r0, [sp, #4]\n\
	ldrb r1, [r6, #0x10]\n\
	ldr r5, _080C9890 @ =0x00004708\n\
	mov r0, sp\n\
	adds r2, r5, #0\n\
	adds r3, r4, #0\n\
	bl CreateGhost82_2\n\
	ldrb r1, [r6, #0x10]\n\
	ldr r2, _080C9894 @ =0x00004707\n\
	mov r0, sp\n\
	adds r3, r4, #0\n\
	bl CreateGhost82_2\n\
	ldrb r1, [r6, #0x10]\n\
	mov r0, sp\n\
	adds r2, r5, #0\n\
	adds r3, r4, #0\n\
	bl CreateGhost82_2\n\
	ldr r1, _080C9898 @ =gVFXFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r6, #0x14]\n\
	b _080C98DC\n\
	.align 2, 0\n\
_080C9884: .4byte RNG_0202f388\n\
_080C9888: .4byte 0x000343FD\n\
_080C988C: .4byte 0x00269EC3\n\
_080C9890: .4byte 0x00004708\n\
_080C9894: .4byte 0x00004707\n\
_080C9898: .4byte gVFXFnTable\n\
_080C989C:\n\
	ldrb r0, [r6, #0xe]\n\
	cmp r0, #0\n\
	beq _080C98A8\n\
	cmp r0, #1\n\
	beq _080C98B6\n\
	b _080C98DC\n\
_080C98A8:\n\
	movs r0, #0x32\n\
	strb r0, [r6, #0x12]\n\
	ldr r0, _080C98E4 @ =0xFFFFFE80\n\
	str r0, [r6, #0x60]\n\
	ldrb r0, [r6, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r6, #0xe]\n\
_080C98B6:\n\
	ldr r0, [r6, #0x60]\n\
	adds r0, #0x10\n\
	str r0, [r6, #0x60]\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #3\n\
	cmp r0, r1\n\
	ble _080C98C6\n\
	str r1, [r6, #0x60]\n\
_080C98C6:\n\
	ldr r0, [r6, #0x58]\n\
	ldr r1, [r6, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r6, #0x58]\n\
	ldr r0, [r6, #0x54]\n\
	ldr r1, [r6, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r6, #0x54]\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
_080C98DC:\n\
	add sp, #8\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C98E4: .4byte 0xFFFFFE80\n\
 .syntax divided\n");
}

NAKED static void FUN_080c98e8(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	adds r7, r0, #0\n\
	ldrb r0, [r7, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r7, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _080C991E\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	beq _080C9938\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080C9938\n\
	ldr r0, [r7, #0x60]\n\
	cmp r0, #0\n\
	ble _080C9938\n\
_080C991E:\n\
	ldr r1, _080C9934 @ =gVFXFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r7, #0x14]\n\
	b _080C99FA\n\
	.align 2, 0\n\
_080C9934: .4byte gVFXFnTable\n\
_080C9938:\n\
	ldrb r0, [r7, #0xe]\n\
	mov sb, r0\n\
	cmp r0, #0\n\
	beq _080C9946\n\
	cmp r0, #1\n\
	beq _080C99B8\n\
	b _080C99FA\n\
_080C9946:\n\
	ldr r4, _080C9A08 @ =0x0836FAC0\n\
	movs r1, #0x74\n\
	adds r1, r1, r7\n\
	mov r8, r1\n\
	ldrh r0, [r1]\n\
	movs r1, #3\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0xe\n\
	adds r0, r0, r4\n\
	ldr r0, [r0]\n\
	ldr r2, [r7, #0x78]\n\
	lsls r2, r2, #3\n\
	adds r2, r2, r0\n\
	ldr r3, _080C9A0C @ =RNG_0202f388\n\
	ldr r0, [r3]\n\
	ldr r6, _080C9A10 @ =0x000343FD\n\
	adds r1, r0, #0\n\
	muls r1, r6, r1\n\
	ldr r5, _080C9A14 @ =0x00269EC3\n\
	adds r1, r1, r5\n\
	lsls r1, r1, #1\n\
	lsrs r4, r1, #1\n\
	str r4, [r3]\n\
	lsrs r1, r1, #0x11\n\
	movs r0, #0x1f\n\
	ands r1, r0\n\
	ldr r0, [r2, #4]\n\
	adds r0, r0, r1\n\
	str r0, [r7, #0x60]\n\
	adds r1, r4, #0\n\
	muls r1, r6, r1\n\
	adds r1, r1, r5\n\
	lsls r1, r1, #1\n\
	lsrs r0, r1, #1\n\
	str r0, [r3]\n\
	lsrs r1, r1, #0x11\n\
	movs r0, #0x3f\n\
	ands r1, r0\n\
	ldr r0, [r2]\n\
	subs r0, r0, r1\n\
	str r0, [r7, #0x5c]\n\
	mov r0, r8\n\
	ldrh r1, [r0]\n\
	adds r0, r7, #0\n\
	bl SetMotion\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strb r0, [r7, #0xa]\n\
	mov r1, sb\n\
	strb r1, [r7, #0x13]\n\
	ldrb r0, [r7, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r7, #0xe]\n\
_080C99B8:\n\
	ldrb r0, [r7, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r7, #0x13]\n\
	ldr r0, [r7, #0x60]\n\
	adds r0, #0x20\n\
	str r0, [r7, #0x60]\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #3\n\
	cmp r0, r1\n\
	ble _080C99CE\n\
	str r1, [r7, #0x60]\n\
_080C99CE:\n\
	ldrb r0, [r7, #0x11]\n\
	cmp r0, #0\n\
	bne _080C99E4\n\
	ldr r0, [r7, #0x28]\n\
	ldrb r0, [r0, #0xd]\n\
	cmp r0, #1\n\
	bne _080C99E4\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, _080C9A18 @ =0xFFFC4000\n\
	adds r0, r0, r1\n\
	str r0, [r7, #0x54]\n\
_080C99E4:\n\
	ldr r0, [r7, #0x58]\n\
	ldr r1, [r7, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r7, #0x58]\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r7, #0x54]\n\
	adds r0, r7, #0\n\
	bl UpdateMotionGraphic\n\
_080C99FA:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C9A08: .4byte PTR_ARRAY_0836fac0\n\
_080C9A0C: .4byte RNG_0202f388\n\
_080C9A10: .4byte 0x000343FD\n\
_080C9A14: .4byte 0x00269EC3\n\
_080C9A18: .4byte 0xFFFC4000\n\
 .syntax divided\n");
}

static const s32 s32_ARRAY_0836fa60[8] = {
    0x00000120, -0x00000200, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160,
};

static const s32 s32_ARRAY_0836fa80[8] = {
    -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200,
};

static const s32 s32_ARRAY_0836faa0[8] = {
    -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200, -0x000000B0, -0x00000160,
};

const s32* const PTR_ARRAY_0836fac0[3] = {
    s32_ARRAY_0836fa60,
    s32_ARRAY_0836fa80,
    s32_ARRAY_0836faa0,
};
