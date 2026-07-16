#include "camera.h"
#include "global.h"
#include "stagerun.h"
#include "vfx.h"

// サイバーエルフが出すキラキラ

struct CyberelfParticle {
  struct Entity s;
  // props (16bytes, offset: 0x74..)
  u8 rng;    // 0x74
  u8 theta;  // 0x75
  u8 unk_2;
  u8 unk_3;
  s32 x;         // 0x78
  u8 unk_7c[8];  // 0x7C
};
static_assert(sizeof(struct CyberelfParticle) == sizeof(struct VFX));

static void ElfParticle_Init(struct VFX* p);
static void ElfParticle_Update(struct VFX* p);
static void ElfParticle_Die(struct Entity* p);

// clang-format off
const VFXRoutine gElfParticleRoutine = {
    [ENTITY_INIT] =      (void*)ElfParticle_Init,
    [ENTITY_UPDATE] =    (void*)ElfParticle_Update,
    [ENTITY_DIE] =       (void*)ElfParticle_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* FUN_080bfc94(Coords32* c, u8 r1) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_ELF_PARTICLE);
    p->coord = *c;
    p->work[0] = 0, p->work[1] = r1;
  }
  return p;
}

NAKED struct Entity* FUN_080bfce8(Coords32* c, u8 r1) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	mov sl, r0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	mov sb, r1\n\
	movs r4, #0\n\
	ldr r0, _080BFD14 @ =gVFXHeaderPtr\n\
	ldr r0, [r0]\n\
	ldrh r1, [r0, #0xa]\n\
	movs r2, #0xa\n\
	ldrsh r0, [r0, r2]\n\
	cmp r0, #4\n\
	bgt _080BFD18\n\
	subs r0, r1, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	b _080BFD1A\n\
	.align 2, 0\n\
_080BFD14: .4byte gVFXHeaderPtr\n\
_080BFD18:\n\
	movs r6, #5\n\
_080BFD1A:\n\
	movs r5, #0\n\
	cmp r5, r6\n\
	bhs _080BFD80\n\
	movs r7, #0\n\
	movs r0, #1\n\
	mov r8, r0\n\
_080BFD26:\n\
	ldr r0, _080BFD90 @ =gVFXHeaderPtr\n\
	ldr r0, [r0]\n\
	bl AllocEntityLast\n\
	adds r4, r0, #0\n\
	cmp r4, #0\n\
	beq _080BFD76\n\
	adds r0, #0x25\n\
	mov r1, r8\n\
	strb r1, [r0]\n\
	movs r0, #0x30\n\
	strb r0, [r4, #9]\n\
	ldr r2, _080BFD94 @ =0x0836D9C0\n\
	ldr r0, [r2]\n\
	ldr r0, [r0]\n\
	str r0, [r4, #0x14]\n\
	strh r7, [r4, #0x20]\n\
	adds r0, r4, #0\n\
	adds r0, #0x22\n\
	strb r7, [r0]\n\
	mov r2, sl\n\
	ldr r0, [r2]\n\
	ldr r1, [r2, #4]\n\
	str r0, [r4, #0x54]\n\
	str r1, [r4, #0x58]\n\
	mov r0, r8\n\
	strb r0, [r4, #0x10]\n\
	mov r1, sb\n\
	strb r1, [r4, #0x11]\n\
	adds r0, r4, #0\n\
	adds r0, #0x77\n\
	strb r7, [r0]\n\
	lsls r0, r5, #8\n\
	adds r1, r6, #0\n\
	bl __divsi3\n\
	subs r0, #0x40\n\
	adds r1, r4, #0\n\
	adds r1, #0x75\n\
	strb r0, [r1]\n\
_080BFD76:\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, r6\n\
	blo _080BFD26\n\
_080BFD80:\n\
	adds r0, r4, #0\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_080BFD90: .4byte gVFXHeaderPtr\n\
_080BFD94: .4byte gVFXFnTable+192\n\
 .syntax divided\n");
}

NAKED struct VFX* FUN_080bfd98(Coords32* c, u8 param2, u8 param3) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	str r0, [sp]\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	str r1, [sp, #4]\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	mov sl, r2\n\
	movs r4, #0\n\
	ldr r0, _080BFDCC @ =gVFXHeaderPtr\n\
	ldr r0, [r0]\n\
	ldrh r1, [r0, #0xa]\n\
	movs r2, #0xa\n\
	ldrsh r0, [r0, r2]\n\
	cmp r0, #2\n\
	bgt _080BFDD0\n\
	subs r0, r1, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	b _080BFDD2\n\
	.align 2, 0\n\
_080BFDCC: .4byte gVFXHeaderPtr\n\
_080BFDD0:\n\
	movs r5, #3\n\
_080BFDD2:\n\
	movs r6, #0\n\
	cmp r6, r5\n\
	bhs _080BFE96\n\
	mov sb, r6\n\
	movs r0, #1\n\
	mov r8, r0\n\
	ldr r7, _080BFE50 @ =RNG_0202f388\n\
_080BFDE0:\n\
	ldr r0, _080BFE54 @ =gVFXHeaderPtr\n\
	ldr r0, [r0]\n\
	bl AllocEntityLast\n\
	adds r4, r0, #0\n\
	cmp r4, #0\n\
	beq _080BFE8C\n\
	adds r0, #0x25\n\
	mov r1, r8\n\
	strb r1, [r0]\n\
	movs r0, #0x30\n\
	strb r0, [r4, #9]\n\
	ldr r2, _080BFE58 @ =0x0836D9C0\n\
	ldr r0, [r2]\n\
	ldr r0, [r0]\n\
	str r0, [r4, #0x14]\n\
	mov r0, sb\n\
	strh r0, [r4, #0x20]\n\
	adds r0, r4, #0\n\
	adds r0, #0x22\n\
	mov r1, sb\n\
	strb r1, [r0]\n\
	ldr r2, [sp]\n\
	ldr r0, [r2]\n\
	ldr r1, [r2, #4]\n\
	str r0, [r4, #0x54]\n\
	str r1, [r4, #0x58]\n\
	mov r0, r8\n\
	strb r0, [r4, #0x10]\n\
	mov r1, sp\n\
	ldrb r1, [r1, #4]\n\
	strb r1, [r4, #0x11]\n\
	adds r0, r4, #0\n\
	adds r0, #0x77\n\
	mov r2, r8\n\
	strb r2, [r0]\n\
	mov r0, sl\n\
	cmp r0, #0\n\
	beq _080BFE64\n\
	lsls r0, r6, #8\n\
	adds r1, r5, #0\n\
	bl __divsi3\n\
	ldr r2, [r7]\n\
	ldr r1, _080BFE5C @ =0x000343FD\n\
	muls r1, r2, r1\n\
	ldr r2, _080BFE60 @ =0x00269EC3\n\
	adds r1, r1, r2\n\
	lsls r1, r1, #1\n\
	lsrs r2, r1, #1\n\
	str r2, [r7]\n\
	lsrs r1, r1, #0x11\n\
	movs r2, #0x1f\n\
	ands r1, r2\n\
	adds r1, #0x40\n\
	b _080BFE84\n\
	.align 2, 0\n\
_080BFE50: .4byte RNG_0202f388\n\
_080BFE54: .4byte gVFXHeaderPtr\n\
_080BFE58: .4byte gVFXFnTable+192\n\
_080BFE5C: .4byte 0x000343FD\n\
_080BFE60: .4byte 0x00269EC3\n\
_080BFE64:\n\
	lsls r0, r6, #8\n\
	adds r1, r5, #0\n\
	bl __divsi3\n\
	ldr r2, [r7]\n\
	ldr r1, _080BFEA8 @ =0x000343FD\n\
	muls r1, r2, r1\n\
	ldr r2, _080BFEAC @ =0x00269EC3\n\
	adds r1, r1, r2\n\
	lsls r1, r1, #1\n\
	lsrs r2, r1, #1\n\
	str r2, [r7]\n\
	lsrs r1, r1, #0x11\n\
	movs r2, #0x1f\n\
	ands r1, r2\n\
	adds r1, #0xc0\n\
_080BFE84:\n\
	adds r0, r0, r1\n\
	adds r1, r4, #0\n\
	adds r1, #0x75\n\
	strb r0, [r1]\n\
_080BFE8C:\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, r5\n\
	blo _080BFDE0\n\
_080BFE96:\n\
	adds r0, r4, #0\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_080BFEA8: .4byte 0x000343FD\n\
_080BFEAC: .4byte 0x00269EC3\n\
 .syntax divided\n");
}

// --------------------------------------------

static void FUN_080c0160(struct CyberelfParticle* p);
static void FUN_080c019c(struct CyberelfParticle* p);

static const VFXFunc sInitializers[2] = {
    (void*)FUN_080c0160,
    (void*)FUN_080c019c,
};

NAKED static void ElfParticle_Init(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	adds r6, r0, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r6, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r0, [r6, #0xa]\n\
	movs r4, #1\n\
	movs r5, #0\n\
	orrs r0, r4\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	movs r1, #0x93\n\
	lsls r1, r1, #8\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	ldr r2, _080BFF00 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080BFF04 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080BFF08 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r2, r0, #0x11\n\
	ands r2, r4\n\
	cmp r2, #0\n\
	beq _080BFF0C\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080BFF12\n\
	.align 2, 0\n\
_080BFF00: .4byte RNG_0202f388\n\
_080BFF04: .4byte 0x000343FD\n\
_080BFF08: .4byte 0x00269EC3\n\
_080BFF0C:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080BFF12:\n\
	strb r0, [r6, #0xa]\n\
	movs r5, #1\n\
	adds r1, r2, #0\n\
	adds r4, r6, #0\n\
	adds r4, #0x4c\n\
	strb r1, [r4]\n\
	adds r3, r6, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ldr r2, _080BFF58 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080BFF5C @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080BFF60 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r2, r0, #0x11\n\
	ands r2, r5\n\
	mov sb, r4\n\
	adds r7, r3, #0\n\
	cmp r2, #0\n\
	beq _080BFF64\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #0x20\n\
	orrs r0, r1\n\
	b _080BFF6A\n\
	.align 2, 0\n\
_080BFF58: .4byte RNG_0202f388\n\
_080BFF5C: .4byte 0x000343FD\n\
_080BFF60: .4byte 0x00269EC3\n\
_080BFF64:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xdf\n\
	ands r0, r1\n\
_080BFF6A:\n\
	strb r0, [r6, #0xa]\n\
	adds r1, r2, #0\n\
	adds r3, r6, #0\n\
	adds r3, #0x4d\n\
	strb r1, [r3]\n\
	lsls r1, r1, #5\n\
	ldrb r2, [r7]\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r7]\n\
	adds r4, r6, #0\n\
	adds r4, #0x49\n\
	movs r0, #3\n\
	ldrb r1, [r6, #0x11]\n\
	ands r1, r0\n\
	lsls r1, r1, #2\n\
	ldrb r2, [r4]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r4]\n\
	ldrb r0, [r6, #0x11]\n\
	mov r8, r3\n\
	cmp r0, #1\n\
	bne _080BFFAA\n\
	adds r1, r6, #0\n\
	adds r1, #0x25\n\
	movs r0, #0x1e\n\
	strb r0, [r1]\n\
_080BFFAA:\n\
	movs r0, #0xa\n\
	strb r0, [r6, #0x12]\n\
	strb r0, [r6, #0x13]\n\
	ldr r1, _080BFFF8 @ =0x0836F12C\n\
	ldrb r0, [r6, #0x10]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	adds r0, r6, #0\n\
	bl _call_via_r1\n\
	ldr r4, _080BFFFC @ =RNG_0202f388\n\
	ldr r0, [r4]\n\
	ldr r3, _080C0000 @ =0x000343FD\n\
	muls r0, r3, r0\n\
	ldr r2, _080C0004 @ =0x00269EC3\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	lsrs r0, r0, #0x11\n\
	adds r5, r6, #0\n\
	adds r5, #0x76\n\
	strb r0, [r5]\n\
	adds r0, r1, #0\n\
	muls r0, r3, r0\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r4]\n\
	lsrs r2, r0, #0x11\n\
	movs r0, #1\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _080C0008\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080C000E\n\
	.align 2, 0\n\
_080BFFF8: .4byte sInitializers\n\
_080BFFFC: .4byte RNG_0202f388\n\
_080C0000: .4byte 0x000343FD\n\
_080C0004: .4byte 0x00269EC3\n\
_080C0008:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080C000E:\n\
	strb r0, [r6, #0xa]\n\
	movs r3, #1\n\
	adds r1, r2, #0\n\
	mov r0, sb\n\
	strb r1, [r0]\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r7]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r7]\n\
	ldr r2, _080C0048 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080C004C @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080C0050 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r2, r0, #0x11\n\
	ands r2, r3\n\
	cmp r2, #0\n\
	beq _080C0054\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #0x20\n\
	orrs r0, r1\n\
	b _080C005A\n\
	.align 2, 0\n\
_080C0048: .4byte RNG_0202f388\n\
_080C004C: .4byte 0x000343FD\n\
_080C0050: .4byte 0x00269EC3\n\
_080C0054:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xdf\n\
	ands r0, r1\n\
_080C005A:\n\
	strb r0, [r6, #0xa]\n\
	movs r3, #1\n\
	adds r1, r3, #0\n\
	ands r1, r2\n\
	mov r0, r8\n\
	strb r1, [r0]\n\
	lsls r1, r1, #5\n\
	ldrb r2, [r7]\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r7]\n\
	ldr r1, _080C0098 @ =gVFXFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	str r3, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	adds r0, r6, #0\n\
	bl ElfParticle_Update\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C0098: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

static void FUN_080c021c(struct CyberelfParticle* p);
static void nop_080c0258(void* _ UNUSED);

static const EntityFunc sUpdates[2] = {
    (void*)FUN_080c021c,
    (void*)nop_080c0258,
};

static void ElfParticle_Update(struct VFX* vfx) {
  UpdateSpriteAnimation(vfx);
  ((VFXFunc)sUpdates[(vfx->s).work[0]])(vfx);
  (vfx->s).coord.x += (vfx->s).d.x;
  (vfx->s).coord.y += (vfx->s).d.y;
  (vfx->s).d.x += (vfx->s).unk_coord.x;
  (vfx->s).d.y += (vfx->s).unk_coord.y;
  (vfx->s).flags |= DISPLAY;
  if ((u8)--(vfx->s).work[3] == 0xff) {
    (vfx->s).work[2]--;
    (vfx->s).work[3] = (vfx->s).work[2];
    if ((u8)(vfx->s).work[2] <= 7) {
      (vfx->s).flags &= ~DISPLAY;
    }
  }
  if (Camera_GetDistance(&gStageRun.vm.camera, &(vfx->s).coord) > 0x2000 || (vfx->s).work[2] == 0) {
    SET_VFX_ROUTINE(vfx, ENTITY_DIE);
    ElfParticle_Die(&vfx->s);
  }
}

static void ElfParticle_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_080c0160(struct CyberelfParticle* p) {
  (p->s).d.x = 0, (p->s).d.y = 0;
  (p->s).unk_coord.x = 0, (p->s).unk_coord.y = 4;
  p->x = (p->s).coord.x;
  p->rng = (RANDOM(RNG_0202f388) & 1) * 32;
}

static void FUN_080c019c(struct CyberelfParticle* p) {
  if (p->unk_3 != 0) {
    (p->s).work[3] = (p->s).work[2] = 6;
    (p->s).d.x = (COS(p->theta) * 3) >> 2;
    (p->s).d.y = (SIN(p->theta) * 3) >> 2;
  } else {
    (p->s).d.x = (s16)(COS(p->theta) * 1) >> 2;
    (p->s).d.y = (s16)(SIN(p->theta) * 1) >> 2;
  }
  (p->s).unk_coord.x = 0, (p->s).unk_coord.y = 1;
}

NAKED static void FUN_080c021c(struct CyberelfParticle* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r3, r0, #0\n\
	adds r3, #0x74\n\
	ldrb r1, [r3]\n\
	ldr r2, _080C0254 @ =gSineTable\n\
	lsls r1, r1, #0x1a\n\
	lsrs r1, r1, #0x17\n\
	adds r1, r1, r2\n\
	movs r4, #0\n\
	ldrsh r2, [r1, r4]\n\
	lsls r2, r2, #1\n\
	ldr r1, [r0, #0x78]\n\
	adds r1, r1, r2\n\
	str r1, [r0, #0x54]\n\
	ldrb r1, [r3]\n\
	adds r2, r1, #1\n\
	adds r0, r2, #0\n\
	cmp r2, #0\n\
	bge _080C0246\n\
	adds r0, r1, #0\n\
	adds r0, #0x40\n\
_080C0246:\n\
	asrs r0, r0, #6\n\
	lsls r0, r0, #6\n\
	subs r0, r2, r0\n\
	strb r0, [r3]\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C0254: .4byte gSineTable\n\
 .syntax divided\n");
}

static void nop_080c0258(void* _) {}
