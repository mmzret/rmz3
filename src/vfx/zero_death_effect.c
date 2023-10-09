#include "entity.h"
#include "vfx.h"
#include "global.h"

/*
  ゼロ死亡時のティウンティウンエフェクト(花火)
*/

// clang-format off

static void ZeroDeathEffect_Init(struct VFX* p);
static void ZeroDeathEffect_Update(struct VFX* p);
static void ZeroDeathEffect_Die(struct VFX* p);

// xx nn nn nn
const VFXRoutine gZeroDeathEffectRoutine = {
    [ENTITY_INIT] =      ZeroDeathEffect_Init,
    [ENTITY_UPDATE] =    ZeroDeathEffect_Update,
    [ENTITY_DIE] =       ZeroDeathEffect_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

NAKED void CreateFirework(s32 x, s32 y, bool8 r2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	mov r8, r0\n\
	mov sl, r1\n\
	lsls r2, r2, #0x18\n\
	lsrs r6, r2, #0x18\n\
	movs r5, #0\n\
	mov sb, r5\n\
_080B358E:\n\
	ldr r0, _080B35C8 @ =gVFXHeaderPtr\n\
	ldr r0, [r0]\n\
	bl AllocEntityFirst\n\
	adds r3, r0, #0\n\
	cmp r3, #0\n\
	beq _080B362E\n\
	adds r0, #0x25\n\
	movs r2, #1\n\
	strb r2, [r0]\n\
	ldr r1, _080B35CC @ =gVFXFnTable\n\
	movs r0, #4\n\
	strb r0, [r3, #9]\n\
	ldr r0, [r1, #0x10]\n\
	ldr r0, [r0]\n\
	str r0, [r3, #0x14]\n\
	mov r0, sb\n\
	strh r0, [r3, #0x20]\n\
	adds r0, r3, #0\n\
	adds r0, #0x22\n\
	mov r1, sb\n\
	strb r1, [r0]\n\
	strb r1, [r3, #0x10]\n\
	cmp r5, #0\n\
	bne _080B35D0\n\
	adds r0, r6, #0\n\
	ands r0, r2\n\
	b _080B35D2\n\
	.align 2, 0\n\
_080B35C8: .4byte gVFXHeaderPtr\n\
_080B35CC: .4byte gVFXFnTable\n\
_080B35D0:\n\
	movs r0, #0\n\
_080B35D2:\n\
	adds r1, r0, #0\n\
	strb r1, [r3, #0x11]\n\
	cmp r1, #0\n\
	beq _080B35E2\n\
	mov r2, r8\n\
	str r2, [r3, #0x74]\n\
	mov r7, sl\n\
	str r7, [r3, #0x78]\n\
_080B35E2:\n\
	movs r0, #1\n\
	adds r1, r6, #0\n\
	eors r1, r0\n\
	ldr r4, _080B3644 @ =gSineTable\n\
	lsls r0, r5, #0x1d\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x17\n\
	adds r0, r0, r2\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r4\n\
	movs r7, #0\n\
	ldrsh r2, [r0, r7]\n\
	lsls r1, r1, #6\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	subs r1, r0, r1\n\
	adds r0, r2, #0\n\
	muls r0, r1, r0\n\
	cmp r0, #0\n\
	bge _080B360C\n\
	adds r0, #0xff\n\
_080B360C:\n\
	asrs r0, r0, #8\n\
	str r0, [r3, #0x5c]\n\
	lsls r0, r5, #0x1d\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r4\n\
	movs r2, #0\n\
	ldrsh r0, [r0, r2]\n\
	muls r0, r1, r0\n\
	cmp r0, #0\n\
	bge _080B3622\n\
	adds r0, #0xff\n\
_080B3622:\n\
	asrs r0, r0, #8\n\
	str r0, [r3, #0x60]\n\
	mov r7, r8\n\
	str r7, [r3, #0x54]\n\
	mov r0, sl\n\
	str r0, [r3, #0x58]\n\
_080B362E:\n\
	adds r5, #1\n\
	cmp r5, #7\n\
	ble _080B358E\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B3644: .4byte gSineTable\n\
 .syntax divided\n");
}

// --------------------------------------------

static void FUN_080b3698(struct VFX* p);

static void ZeroDeathEffect_Init(struct VFX* p) {
  static const VFXFunc sInitializers[1] = {
      FUN_080b3698,
  };
  (sInitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

void FUN_080b36e0(struct VFX* p);

static void ZeroDeathEffect_Update(struct VFX* p) {
  static const VFXFunc sUpdates[1] = {
      FUN_080b36e0,
  };
  (sUpdates[(p->s).work[0]])(p);
}

// --------------------------------------------

static void ZeroDeathEffect_Die(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_080b3698(struct VFX* p) {
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  (p->s).spr.oam.priority = 0;
  (p->s).work[3] = 0x80;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  ZeroDeathEffect_Update(p);
}

INCASM("asm/vfx/zero_death_effect.inc");
