#include "entity.h"
#include "global.h"
#include "vfx.h"

// シエルのミニゲームに関係？

static void Ghost79_Init(struct VFX *p);
static void Ghost79_Update(struct VFX *p);
static void Ghost79_Die(struct VFX *p);

// clang-format off
const VFXRoutine gGhost79Routine = {
    [ENTITY_INIT] =      Ghost79_Init,
    [ENTITY_UPDATE] =    Ghost79_Update,
    [ENTITY_DIE] =       Ghost79_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

NAKED void CreateGhost79_1(s32 x, s32 y, struct Entity *p, void *param_4, void *param_5, void *param_6, u8 param_7) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	mov sb, r0\n\
	mov sl, r1\n\
	str r2, [sp]\n\
	ldr r0, [sp, #0x24]\n\
	ldr r1, [sp, #0x28]\n\
	ldr r2, [sp, #0x2c]\n\
	lsls r3, r3, #0x10\n\
	lsrs r5, r3, #0x10\n\
	lsls r0, r0, #0x18\n\
	lsrs r7, r0, #0x18\n\
	lsls r1, r1, #0x18\n\
	lsrs r4, r1, #0x18\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	mov r8, r2\n\
	ldr r0, _080C8EC0 @ =gVFXHeaderPtr\n\
	ldr r0, [r0]\n\
	bl AllocEntityFirst\n\
	adds r6, r0, #0\n\
	cmp r6, #0\n\
	beq _080C8EAC\n\
	adds r1, r6, #0\n\
	adds r1, #0x25\n\
	movs r2, #0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r0, _080C8EC4 @ =gVFXFnTable\n\
	movs r1, #0x4f\n\
	strb r1, [r6, #9]\n\
	adds r1, #0xed\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r0, [r0]\n\
	str r0, [r6, #0x14]\n\
	movs r1, #0\n\
	strh r2, [r6, #0x20]\n\
	adds r0, r6, #0\n\
	adds r0, #0x22\n\
	strb r1, [r0]\n\
	mov r2, sb\n\
	str r2, [r6, #0x54]\n\
	mov r0, sl\n\
	str r0, [r6, #0x58]\n\
	ldr r2, [sp]\n\
	str r2, [r6, #0x74]\n\
	adds r0, r6, #0\n\
	adds r0, #0x78\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strb r7, [r0]\n\
	adds r0, #1\n\
	strb r4, [r0]\n\
	strb r1, [r6, #0x10]\n\
	mov r0, r8\n\
	strb r0, [r6, #0x11]\n\
	movs r4, #0xe8\n\
	ldr r1, _080C8EC8 @ =wStaticGraphicTilenums\n\
	lsls r0, r4, #1\n\
	adds r1, r1, r0\n\
	strh r5, [r1]\n\
	ldr r5, _080C8ECC @ =wStaticMotionPalIDs\n\
	adds r5, r5, r0\n\
	strh r7, [r5]\n\
	lsls r4, r4, #4\n\
	movs r2, #0xe8\n\
	lsls r2, r2, #2\n\
	adds r4, r4, r2\n\
	ldr r2, _080C8ED0 @ =gStaticMotionGraphics\n\
	adds r0, r4, r2\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r0, _080C8ED4 @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r0\n\
	ldrh r1, [r5]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
_080C8EAC:\n\
	adds r0, r6, #0\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_080C8EC0: .4byte gVFXHeaderPtr\n\
_080C8EC4: .4byte gVFXFnTable\n\
_080C8EC8: .4byte wStaticGraphicTilenums\n\
_080C8ECC: .4byte wStaticMotionPalIDs\n\
_080C8ED0: .4byte gStaticMotionGraphics\n\
_080C8ED4: .4byte gStaticMotionGraphics+12\n\
 .syntax divided\n");
}

NAKED void CreateGhost79_2(struct Entity *p, u8 r1, u8 r2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r6, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r4, r1, #0x18\n\
	lsls r2, r2, #0x18\n\
	lsrs r5, r2, #0x18\n\
	ldr r0, _080C8F28 @ =gVFXHeaderPtr\n\
	ldr r0, [r0]\n\
	bl AllocEntityFirst\n\
	mov ip, r0\n\
	cmp r0, #0\n\
	beq _080C8F22\n\
	adds r0, #0x25\n\
	movs r3, #0\n\
	movs r2, #1\n\
	strb r2, [r0]\n\
	ldr r0, _080C8F2C @ =gVFXFnTable\n\
	movs r1, #0x4f\n\
	mov r7, ip\n\
	strb r1, [r7, #9]\n\
	adds r1, #0xed\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r0, [r0]\n\
	str r0, [r7, #0x14]\n\
	movs r0, #0\n\
	strh r3, [r7, #0x20]\n\
	mov r1, ip\n\
	adds r1, #0x22\n\
	strb r0, [r1]\n\
	str r6, [r7, #0x28]\n\
	mov r0, ip\n\
	adds r0, #0x7b\n\
	strb r4, [r0]\n\
	strb r2, [r7, #0x10]\n\
	strb r5, [r7, #0x11]\n\
_080C8F22:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C8F28: .4byte gVFXHeaderPtr\n\
_080C8F2C: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

static void FUN_080c8f78(struct VFX *p);
static void FUN_080c8fc8(struct VFX *p);

static void Ghost79_Init(struct VFX *p) {
  static VFXFunc const sInitializers[] = {
      FUN_080c8f78,
      FUN_080c8fc8,
  };
  (sInitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

static void FUN_080c9018(struct VFX *p);
static void FUN_080c9044(struct VFX *p);

static void Ghost79_Update(struct VFX *p) {
  static VFXFunc const sUpdates[] = {
      FUN_080c9018,
      FUN_080c9044,
  };
  (sUpdates[(p->s).work[0]])(p);
}

// --------------------------------------------

static void FUN_080c9114(struct VFX *p);
static void FUN_080c912c(struct VFX *p);

static void Ghost79_Die(struct VFX *p) {
  static VFXFunc const sDeinitializers[] = {
      FUN_080c9114,
      FUN_080c912c,
  };
  (sDeinitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

NAKED static void FUN_080c8f78(struct VFX *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldr r1, _080C8F94 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	movs r5, #0\n\
	b _080C8FA8\n\
	.align 2, 0\n\
_080C8F94: .4byte gVFXFnTable\n\
_080C8F98:\n\
	ldrb r2, [r4, #0x11]\n\
	adds r0, r4, #0\n\
	adds r1, r5, #0\n\
	bl CreateGhost79_2\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
_080C8FA8:\n\
	adds r0, r4, #0\n\
	adds r0, #0x7b\n\
	ldrb r0, [r0]\n\
	cmp r5, r0\n\
	blo _080C8F98\n\
	movs r0, #0\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #1\n\
	strb r0, [r4, #0x13]\n\
	adds r0, r4, #0\n\
	bl Ghost79_Update\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void FUN_080c8fc8(struct VFX *vfx) {
  register u8 r0 asm("r1");
  register u8 flags asm("r0");
  bool8 xflip;

  SET_VFX_ROUTINE(vfx, ENTITY_UPDATE);
  InitNonAffineMotion(&vfx->s);
  r0 = (vfx->s).flags;
  flags = r0 | FLIPABLE;
  xflip = FALSE;
  flags &= ~X_FLIP;
  (vfx->s).flags = flags;

  (vfx->s).spr.xflip = xflip;
  (vfx->s).spr.oam.xflip = xflip;
  Ghost79_Update(vfx);
}

// --------------------------------------------

static void FUN_080c9018(struct VFX *p) {
  if ((p->s).work[2] != 0) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    Ghost79_Die(p);
  }
}

NAKED static void FUN_080c9044(struct VFX *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	adds r4, r0, #0\n\
	ldr r0, [r4, #0x28]\n\
	mov r8, r0\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #1\n\
	bls _080C9078\n\
	ldr r1, _080C9074 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl Ghost79_Die\n\
	b _080C9106\n\
	.align 2, 0\n\
_080C9074: .4byte gVFXFnTable\n\
_080C9078:\n\
	mov r1, r8\n\
	ldr r0, [r1, #0x74]\n\
	ldr r1, [r0]\n\
	movs r5, #0\n\
	adds r0, r4, #0\n\
	adds r0, #0x7b\n\
	ldrb r2, [r0]\n\
	mov sb, r0\n\
	ldrb r7, [r4, #0xa]\n\
	cmp r5, r2\n\
	bhs _080C90A4\n\
	adds r6, r2, #0\n\
_080C9090:\n\
	adds r0, r1, #0\n\
	movs r1, #0xa\n\
	bl __udivsi3\n\
	adds r1, r0, #0\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, r6\n\
	blo _080C9090\n\
_080C90A4:\n\
	adds r0, r1, #0\n\
	movs r1, #0xa\n\
	bl __umodsi3\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	bne _080C90C8\n\
	mov r2, sb\n\
	ldrb r0, [r2]\n\
	cmp r0, #0\n\
	beq _080C90C8\n\
	ldrb r0, [r4, #0x11]\n\
	cmp r0, #0\n\
	bne _080C90C8\n\
	movs r0, #0xfe\n\
	ands r0, r7\n\
	strb r0, [r4, #0xa]\n\
	b _080C9106\n\
_080C90C8:\n\
	mov r2, r8\n\
	ldrb r0, [r2, #0x13]\n\
	cmp r0, #0\n\
	beq _080C90D6\n\
	movs r0, #1\n\
	orrs r0, r7\n\
	b _080C90DA\n\
_080C90D6:\n\
	movs r0, #0xfe\n\
	ands r0, r7\n\
_080C90DA:\n\
	strb r0, [r4, #0xa]\n\
	movs r2, #0xe8\n\
	lsls r2, r2, #8\n\
	adds r0, r2, #0\n\
	orrs r1, r0\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	mov r0, sb\n\
	ldrb r1, [r0]\n\
	lsls r1, r1, #0xb\n\
	mov r2, r8\n\
	ldr r0, [r2, #0x54]\n\
	subs r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r2, #0x58]\n\
	str r0, [r4, #0x58]\n\
_080C9106:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// --------------------------------------------

static void FUN_080c9114(struct VFX *p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

static void FUN_080c912c(struct VFX *p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }
