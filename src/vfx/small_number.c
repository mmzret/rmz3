#include "global.h"
#include "vfx.h"

// SecretDisk Number when Zero gain on field

static void Ghost81_Init(struct VFX *vfx);
static void Ghost81_Update(struct VFX *vfx);
static void Ghost81_Die(struct VFX *vfx);

// clang-format off
const VFXRoutine gSmallNumberRoutine = {
    [ENTITY_INIT] =      Ghost81_Init,
    [ENTITY_MAIN] =      Ghost81_Update,
    [ENTITY_DIE] =       Ghost81_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

NAKED bool8 CreateSmallNumber(s32 x, s32 y, u8 value) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x10\n\
	adds r7, r0, #0\n\
	str r1, [sp, #0xc]\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	mov r8, r2\n\
	movs r0, #0\n\
	mov sb, r0\n\
	movs r6, #0\n\
	ldr r2, _080C9370 @ =0x0836DA44\n\
	mov sl, r2\n\
	mov r4, sp\n\
	movs r5, #2\n\
_080C9358:\n\
	ldr r0, _080C9374 @ =gVFXHeaderPtr\n\
	ldr r0, [r0]\n\
	bl AllocEntityFirst\n\
	adds r1, r0, #0\n\
	str r1, [r4]\n\
	cmp r1, #0\n\
	bne _080C9378\n\
	movs r0, #1\n\
	mov sb, r0\n\
	b _080C9394\n\
	.align 2, 0\n\
_080C9370: .4byte gVFXFnTable+(81*4)\n\
_080C9374: .4byte gVFXHeaderPtr\n\
_080C9378:\n\
	adds r2, r1, #0\n\
	adds r2, #0x25\n\
	movs r0, #1\n\
	strb r0, [r2]\n\
	movs r0, #0x51\n\
	strb r0, [r1, #9]\n\
	mov r2, sl\n\
	ldr r0, [r2]\n\
	ldr r0, [r0]\n\
	str r0, [r1, #0x14]\n\
	strh r6, [r1, #0x20]\n\
	adds r0, r1, #0\n\
	adds r0, #0x22\n\
	strb r6, [r0]\n\
_080C9394:\n\
	adds r4, #4\n\
	subs r5, #1\n\
	cmp r5, #0\n\
	bge _080C9358\n\
	mov r0, sb\n\
	cmp r0, #0\n\
	beq _080C93E0\n\
	movs r2, #0xfe\n\
	mov r8, r2\n\
	ldr r7, _080C93DC @ =gVFXFnTable\n\
	mov r3, sp\n\
	movs r6, #0xfd\n\
	movs r4, #3\n\
	movs r5, #2\n\
_080C93B0:\n\
	ldr r2, [r3]\n\
	cmp r2, #0\n\
	beq _080C93CE\n\
	ldrb r1, [r2, #0xa]\n\
	mov r0, r8\n\
	ands r0, r1\n\
	ands r0, r6\n\
	strb r0, [r2, #0xa]\n\
	ldrb r0, [r2, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r7\n\
	str r4, [r2, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r2, #0x14]\n\
_080C93CE:\n\
	adds r3, #4\n\
	subs r5, #1\n\
	cmp r5, #0\n\
	bge _080C93B0\n\
	movs r0, #0\n\
	b _080C941A\n\
	.align 2, 0\n\
_080C93DC: .4byte gVFXFnTable\n\
_080C93E0:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	adds r7, r7, r0\n\
	movs r5, #0\n\
	mov r6, sp\n\
_080C93EA:\n\
	ldr r4, [r6]\n\
	str r7, [r4, #0x54]\n\
	ldr r2, _080C942C @ =0xFFFFF800\n\
	adds r7, r7, r2\n\
	ldr r0, [sp, #0xc]\n\
	str r0, [r4, #0x58]\n\
	mov r0, r8\n\
	movs r1, #0xa\n\
	bl __umodsi3\n\
	strb r0, [r4, #0x12]\n\
	ldm r6!, {r0}\n\
	strb r5, [r0, #0x13]\n\
	mov r0, r8\n\
	movs r1, #0xa\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov r8, r0\n\
	adds r5, #1\n\
	cmp r5, #2\n\
	ble _080C93EA\n\
	movs r0, #1\n\
_080C941A:\n\
	add sp, #0x10\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_080C942C: .4byte 0xFFFFF800\n\
 .syntax divided\n");
}

// --------------------------------------------

static const u8 u8_ARRAY_0836fa3c[4];

static void Ghost81_Init(struct VFX *p) {
  SET_VFX_ROUTINE(p, ENTITY_MAIN);
  (p->s).mode[1] = u8_ARRAY_0836fa3c[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  Ghost81_Update(p);
}

// --------------------------------------------

static void FUN_080c94a8(struct VFX *p);
static void FUN_080c94e4(struct VFX *p);
static void FUN_080c955c(struct VFX *p);
static void FUN_080c9594(struct VFX *p);

static void Ghost81_Update(struct VFX *p) {
  static VFXFunc const sUpdates[] = {
      FUN_080c94a8,
      FUN_080c94e4,
      FUN_080c955c,
      FUN_080c9594,
  };
  (sUpdates[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void Ghost81_Die(struct VFX *p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

// --------------------------------------------

static void FUN_080c94a8(struct VFX *p) {
  switch ((p->s).mode[2]) {
    case 0: {
      (p->s).flags &= ~DISPLAY;
      (p->s).unk_coord.x = (p->s).work[3] * 4;
      (p->s).mode[2]++;
      FALLTHROUGH
    }
    case 1: {
      if ((p->s).unk_coord.x == 0) {
        (p->s).mode[1] = ENTITY_MAIN;
        (p->s).mode[2] = 0;
      }
      (p->s).unk_coord.x--;
      break;
    }
  }
}

static void FUN_080c94e4(struct VFX *p) {
  switch ((p->s).mode[2]) {
    case 0: {
      (p->s).spr.oam.priority = 0;
      (p->s).taskCol = 0;
      (p->s).flags |= DISPLAY;
      (p->s).unk_coord.y = (p->s).coord.y;
      (p->s).d.y = -0x300;
      SetMotion(&p->s, MOTION(0xD1, (p->s).work[2]));
      (p->s).mode[2]++;
      FALLTHROUGH
    }
    case 1: {
      (p->s).d.y += 0x40;
      (p->s).coord.y += (p->s).d.y;
      if ((p->s).coord.y > (p->s).unk_coord.y) {
        (p->s).coord.y = (p->s).unk_coord.y;
        (p->s).mode[1] = ENTITY_DIE;
        (p->s).mode[2] = 0;
      }
      UpdateMotionGraphic(&p->s);
      break;
    }
  }
}

static void FUN_080c955c(struct VFX *p) {
  switch ((p->s).mode[2]) {
    case 0: {
      (p->s).unk_coord.x = (2 - (p->s).work[3]) * 4 + 60;
      (p->s).mode[2]++;
      FALLTHROUGH
    }
    case 1: {
      (p->s).unk_coord.x--;
      if ((p->s).unk_coord.x == 0) {
        (p->s).mode[1] = ENTITY_DISAPPEAR;
        (p->s).mode[2] = 0;
      }
      break;
    }
  }
}

static void FUN_080c9594(struct VFX *p) {
  switch ((p->s).mode[2]) {
    case 0: {
      (p->s).unk_coord.x = 0x10;
      (p->s).mode[2]++;
      break;
    }
    case 1: {
      if ((p->s).unk_coord.x & 2) {
        (p->s).flags |= DISPLAY;
      } else {
        (p->s).flags &= ~DISPLAY;
      }
      (p->s).unk_coord.x--;
      if ((p->s).unk_coord.x == 0) {
        (p->s).flags &= ~DISPLAY;
        (p->s).flags &= ~FLIPABLE;
        SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      break;
    }
  }
}

static const u8 u8_ARRAY_0836fa3c[4] = {0, 0, 0, 0};
