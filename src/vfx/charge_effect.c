#include "global.h"
#include "vfx.h"

/*
  ゼロの武器チャージエフェクト(メイン、サブ両方)
*/

static const motion_t sMotions[2];

static void ChargeEffect_Init(struct VFX* p);
static void ChargeEffect_Update(struct VFX* p);
static void ChargeEffect_Die(struct VFX* p);

// clang-format off
const VFXRoutine gChargeEffectRoutine = {
    [ENTITY_INIT] =      ChargeEffect_Init,
    [ENTITY_UPDATE] =    ChargeEffect_Update,
    [ENTITY_DIE] =       ChargeEffect_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX* CreateChargeEffect(struct Zero* z, struct VFX* v, u8 r2) {
  struct VFX* g = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, VFX_CHARGE_EFFECT);
    (g->s).tileNum = 0;
    (g->s).palID = 0;
    (g->s).unk_28 = &z->s;
    (g->s).unk_2c = &v->s;
    (g->s).work[0] = r2;
    (g->s).work[1] = 0;
  }

  return g;
}

// ------------------------------------------------------------------------------------------------------------------------------------

NON_MATCH static void ChargeEffect_Init(struct VFX* p) {
#if MODERN
  InitNonAffineMotion(&p->s);
  (p->s).flags |= FLIPABLE;
  (p->s).flags &= ~X_FLIP;
  (p->s).spr.xflip = FALSE;
  (p->s).spr.oam.xflip = FALSE;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  ChargeEffect_Update(p);
#else
  INCCODE("asm/wip/ChargeEffect_Init.inc");
#endif
}

// --------------------------------------------

NAKED static void ChargeEffect_Update(struct VFX* vfx) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r4, r0, #0\n\
	ldr r6, [r4, #0x28]\n\
	adds r0, r6, #0\n\
	adds r0, #0xa4\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	cmp r0, #0\n\
	beq _080B33D8\n\
	ldrb r0, [r6, #0xc]\n\
	cmp r0, #2\n\
	bls _080B33F8\n\
_080B33D8:\n\
	ldr r1, _080B33F4 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl ChargeEffect_Die\n\
	b _080B3556\n\
	.align 2, 0\n\
_080B33F4: .4byte gVFXFnTable\n\
_080B33F8:\n\
	ldrb r1, [r4, #0x10]\n\
	adds r0, r6, #0\n\
	bl GetWeaponCharge\n\
	adds r1, r4, #0\n\
	adds r1, #0x78\n\
	movs r7, #0\n\
	strb r0, [r1]\n\
	ldrb r0, [r6, #0xd]\n\
	mov r8, r1\n\
	cmp r0, #9\n\
	bls _080B341A\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	b _080B3556\n\
_080B341A:\n\
	ldrb r0, [r4, #0xa]\n\
	movs r3, #1\n\
	adds r1, r0, #0\n\
	orrs r1, r3\n\
	orrs r1, r7\n\
	strb r1, [r4, #0xa]\n\
	mov r0, r8\n\
	ldrb r2, [r0]\n\
	cmp r2, #0\n\
	beq _080B34DE\n\
	ldrb r5, [r4, #0xd]\n\
	cmp r5, #0\n\
	bne _080B3450\n\
	orrs r1, r3\n\
	strb r1, [r4, #0xa]\n\
	ldr r1, _080B3470 @ =0x0836DAB8\n\
	ldrb r0, [r4, #0x10]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	str r5, [r4, #0x74]\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
_080B3450:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080B347C\n\
	ldr r1, _080B3474 @ =0x0836DABC\n\
	ldr r3, _080B3478 @ =0x00000147\n\
	adds r2, r6, r3\n\
	ldrb r0, [r2]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	ldr r0, [r6, #0x54]\n\
	subs r0, r0, r1\n\
	b _080B3490\n\
	.align 2, 0\n\
_080B3470: .4byte sMotions\n\
_080B3474: .4byte sChargeEffectXOffsets\n\
_080B3478: .4byte 0x00000147\n\
_080B347C:\n\
	ldr r1, _080B34B8 @ =0x0836DABC\n\
	ldr r0, _080B34BC @ =0x00000147\n\
	adds r2, r6, r0\n\
	ldrb r0, [r2]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	ldr r0, [r6, #0x54]\n\
	adds r0, r0, r1\n\
_080B3490:\n\
	str r0, [r4, #0x54]\n\
	ldr r1, _080B34C0 @ =0x0836DAC8\n\
	ldrb r0, [r2]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	ldr r0, [r6, #0x58]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	mov r3, r8\n\
	ldrb r0, [r3]\n\
	cmp r0, #2\n\
	bne _080B34C4\n\
	adds r0, r4, #0\n\
	movs r1, #0xf\n\
	bl ForceEntityPalette\n\
	b _080B34CC\n\
	.align 2, 0\n\
_080B34B8: .4byte sChargeEffectXOffsets\n\
_080B34BC: .4byte 0x00000147\n\
_080B34C0: .4byte sChargeEffectYOffsets\n\
_080B34C4:\n\
	adds r0, r4, #0\n\
	movs r1, #0xe\n\
	bl ForceEntityPalette\n\
_080B34CC:\n\
	ldr r0, [r4, #0x74]\n\
	cmp r0, #0\n\
	beq _080B34D6\n\
	subs r0, #1\n\
	str r0, [r4, #0x74]\n\
_080B34D6:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	b _080B34E6\n\
_080B34DE:\n\
	movs r0, #0xfe\n\
	ands r1, r0\n\
	strb r1, [r4, #0xa]\n\
	strb r2, [r4, #0xd]\n\
_080B34E6:\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #1\n\
	bne _080B3556\n\
	ldr r5, [r4, #0x2c]\n\
	adds r3, r5, #0\n\
	adds r3, #0x78\n\
	ldrb r0, [r3]\n\
	mov r7, r8\n\
	ldrb r2, [r7]\n\
	cmn r0, r2\n\
	beq _080B3556\n\
	adds r1, r0, #0\n\
	adds r0, r2, #0\n\
	cmp r1, r0\n\
	bne _080B3512\n\
	ldr r1, [r4, #0x74]\n\
	ldr r0, [r5, #0x74]\n\
	cmp r1, r0\n\
	blt _080B3518\n\
	str r1, [r5, #0x74]\n\
	ldrb r2, [r7]\n\
	b _080B3526\n\
_080B3512:\n\
	cmp r1, r0\n\
	bls _080B351E\n\
	ldr r0, [r5, #0x74]\n\
_080B3518:\n\
	str r0, [r4, #0x74]\n\
	ldrb r2, [r3]\n\
	b _080B3526\n\
_080B351E:\n\
	ldr r0, [r4, #0x74]\n\
	str r0, [r5, #0x74]\n\
	mov r0, r8\n\
	ldrb r2, [r0]\n\
_080B3526:\n\
	ldr r1, _080B354C @ =0x00000216\n\
	adds r0, r6, r1\n\
	ldrh r1, [r0]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080B3556\n\
	ldr r0, [r4, #0x74]\n\
	cmp r0, #0\n\
	bne _080B3556\n\
	movs r0, #0x18\n\
	str r0, [r4, #0x74]\n\
	str r0, [r5, #0x74]\n\
	cmp r2, #2\n\
	bne _080B3550\n\
	bl PlaySound\n\
	b _080B3556\n\
	.align 2, 0\n\
_080B354C: .4byte 0x00000216\n\
_080B3550:\n\
	movs r0, #0x17\n\
	bl PlaySound\n\
_080B3556:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// --------------------------------------------

static void ChargeEffect_Die(struct VFX* vfx) { SET_VFX_ROUTINE(vfx, ENTITY_EXIT); }

// --------------------------------------------

static const motion_t sMotions[2] = {
    MOTION(SM000_BATTLE_EFFECT, 8),
    MOTION(SM000_BATTLE_EFFECT, 18),
};

const s16 sChargeEffectXOffsets[6] = {
    -PIXEL(2), -PIXEL(8), PIXEL(0), -PIXEL(8), -PIXEL(2), -PIXEL(2),
};

const s16 sChargeEffectYOffsets[6] = {
    -PIXEL(20), -PIXEL(12), -PIXEL(20), -PIXEL(12), -PIXEL(20), -PIXEL(20),
};
