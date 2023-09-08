#include "entity.h"
#include "global.h"
#include "vfx.h"

/*
ボス死亡時の爆発
爆発時には、火球や漏れ出る光、誘爆のエフェクトなどがあるが、すべてのエフェクトをここで担う
エフェクトの種類は various (例: 030073ac) で分けている

various:
  0:
  1:
  2: 誘爆エフェクト？
  3: 火球
*/

void BossExplosion_Init(struct VFX *p);
void BossExplosion_Update(struct VFX *p);
void BossExplosion_Die(struct VFX *p);

// clang-format off
const VFXRoutine gBossExplosionRoutine = {
    [ENTITY_INIT] =      BossExplosion_Init,
    [ENTITY_MAIN] =      BossExplosion_Update,
    [ENTITY_DIE] =       BossExplosion_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX *CreateBossExplosion(struct Boss *boss, struct Coord *c) {
  struct VFX *p = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 1;
    INIT_VFX_ROUTINE(p, VFX_BOSS_EXPLOSION);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).unk_28 = &boss->s;
    (p->s).d = *c;
    (p->s).work[0] = 0;
    (p->s).work[1] = 0;
  }
  return p;
}

INCASM("asm/vfx/boss_explosion.inc");

// --------------------------------------------

NON_MATCH static void initFireball(struct VFX *p) {
#if MODERN
  InitScalerotMotion1(&p->s);
  (p->s).flags |= DISPLAY;
  ResetDynamicMotion(&p->s);
  (p->s).flags |= FLIPABLE;
  SetMotion(&p->s, MOTION(0xC7, 0x00));
  UpdateMotionGraphic(&p->s);
  (p->s).flags &= ~X_FLIP;
  (p->s).spr.xflip = FALSE;
  (p->s).spr.oam.xflip = FALSE;
  (p->s).spr.oam.priority = 1;
  (p->s).spr.mag.y = (p->s).spr.mag.x = 0x10;
  (p->s).angle = 0;
  SET_VFX_ROUTINE(p, ENTITY_MAIN);
  BossExplosion_Update(p);
#else
  INCCODE("asm/wip/initFireball.inc");
#endif
}

// --------------------------------------------

NAKED static void FUN_080c7cc0(struct VFX *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x10\n\
	adds r7, r0, #0\n\
	ldr r0, [r7, #0x28]\n\
	mov sb, r0\n\
	ldrb r6, [r7, #0xd]\n\
	cmp r6, #0\n\
	beq _080C7CDE\n\
	cmp r6, #1\n\
	beq _080C7DA0\n\
	b _080C7F52\n\
_080C7CDE:\n\
	ldrb r0, [r7, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r7, #0x13]\n\
	ldrb r1, [r7, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r1, r0\n\
	bhs _080C7D12\n\
	subs r0, r1, #1\n\
	strb r0, [r7, #0x12]\n\
	strb r6, [r7, #0x13]\n\
	mov r1, sb\n\
	adds r1, #0x8c\n\
	ldr r0, [r1]\n\
	movs r4, #1\n\
	orrs r0, r4\n\
	str r0, [r1]\n\
	adds r1, #4\n\
	ldr r0, [r1]\n\
	orrs r0, r4\n\
	str r0, [r1]\n\
	mov r0, sb\n\
	bl PaintEntityWhite\n\
	strb r4, [r7, #0x11]\n\
	b _080C7D30\n\
_080C7D12:\n\
	mov r1, sb\n\
	adds r1, #0x8c\n\
	ldr r0, [r1]\n\
	movs r2, #2\n\
	rsbs r2, r2, #0\n\
	ands r0, r2\n\
	str r0, [r1]\n\
	adds r1, #4\n\
	ldr r0, [r1]\n\
	ands r0, r2\n\
	str r0, [r1]\n\
	mov r0, sb\n\
	bl UpdateEntityPaletteID\n\
	strb r6, [r7, #0x11]\n\
_080C7D30:\n\
	ldrb r0, [r7, #0x12]\n\
	cmp r0, #1\n\
	bls _080C7D38\n\
	b _080C7F52\n\
_080C7D38:\n\
	adds r1, r7, #0\n\
	adds r1, #0x80\n\
	movs r0, #0x80\n\
	strh r0, [r1]\n\
	movs r0, #0x30\n\
	bl PlaySound\n\
	ldr r4, _080C7D8C @ =0x00001298\n\
	ldr r1, _080C7D90 @ =gStaticMotionGraphics\n\
	adds r0, r4, r1\n\
	ldr r1, _080C7D94 @ =wStaticGraphicTilenums\n\
	movs r5, #0xee\n\
	lsls r5, r5, #1\n\
	adds r1, r1, r5\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r3, _080C7D98 @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r3\n\
	ldr r0, _080C7D9C @ =wStaticMotionPalIDs\n\
	adds r0, r0, r5\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	ldrb r0, [r7, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r7, #0xd]\n\
	b _080C7F52\n\
	.align 2, 0\n\
_080C7D8C: .4byte 0x00001298\n\
_080C7D90: .4byte gStaticMotionGraphics\n\
_080C7D94: .4byte wStaticGraphicTilenums\n\
_080C7D98: .4byte gStaticMotionGraphics+12\n\
_080C7D9C: .4byte wStaticMotionPalIDs\n\
_080C7DA0:\n\
	ldrb r1, [r7, #0x12]\n\
	adds r0, r1, #1\n\
	strb r0, [r7, #0x12]\n\
	movs r0, #3\n\
	ands r0, r1\n\
	cmp r0, #1\n\
	bls _080C7DCC\n\
	mov r5, sb\n\
	adds r5, #0x8c\n\
	ldr r0, [r5]\n\
	orrs r0, r6\n\
	str r0, [r5]\n\
	mov r4, sb\n\
	adds r4, #0x90\n\
	ldr r0, [r4]\n\
	orrs r0, r6\n\
	str r0, [r4]\n\
	mov r0, sb\n\
	bl PaintEntityWhite\n\
	strb r6, [r7, #0x11]\n\
	b _080C7DEE\n\
_080C7DCC:\n\
	mov r5, sb\n\
	adds r5, #0x8c\n\
	ldr r0, [r5]\n\
	movs r1, #2\n\
	rsbs r1, r1, #0\n\
	ands r0, r1\n\
	str r0, [r5]\n\
	mov r4, sb\n\
	adds r4, #0x90\n\
	ldr r0, [r4]\n\
	ands r0, r1\n\
	str r0, [r4]\n\
	mov r0, sb\n\
	bl UpdateEntityPaletteID\n\
	movs r0, #0\n\
	strb r0, [r7, #0x11]\n\
_080C7DEE:\n\
	str r5, [sp, #8]\n\
	str r4, [sp, #0xc]\n\
	movs r1, #0x80\n\
	adds r1, r1, r7\n\
	mov sl, r1\n\
	ldrh r0, [r1]\n\
	cmp r0, #0x28\n\
	bne _080C7E12\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	mov r0, sb\n\
	mov r1, sp\n\
	movs r2, #3\n\
	movs r3, #0\n\
	bl FUN_080c7984\n\
_080C7E12:\n\
	mov r2, sl\n\
	ldrh r0, [r2]\n\
	movs r1, #0x12\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080C7E6C\n\
	ldr r3, _080C7F64 @ =RNG_0202f388\n\
	mov r8, r3\n\
	ldr r0, [r3]\n\
	ldr r5, _080C7F68 @ =0x000343FD\n\
	adds r1, r0, #0\n\
	muls r1, r5, r1\n\
	ldr r3, _080C7F6C @ =0x00269EC3\n\
	adds r1, r1, r3\n\
	lsls r1, r1, #1\n\
	lsrs r6, r1, #1\n\
	lsrs r1, r1, #0x11\n\
	movs r4, #0x7f\n\
	ands r1, r4\n\
	movs r2, #0x40\n\
	subs r1, r2, r1\n\
	lsls r1, r1, #8\n\
	ldr r0, [r7, #0x54]\n\
	adds r0, r0, r1\n\
	str r0, [sp]\n\
	adds r0, r6, #0\n\
	muls r0, r5, r0\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	mov r3, r8\n\
	str r1, [r3]\n\
	lsrs r0, r0, #0x11\n\
	ands r0, r4\n\
	subs r2, r2, r0\n\
	lsls r2, r2, #8\n\
	ldr r0, [r7, #0x58]\n\
	adds r0, r0, r2\n\
	str r0, [sp, #4]\n\
	movs r0, #1\n\
	mov r1, sp\n\
	bl CreateSmoke\n\
_080C7E6C:\n\
	mov r1, sl\n\
	ldrh r0, [r1]\n\
	movs r1, #0x12\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #9\n\
	bne _080C7ED8\n\
	ldr r2, _080C7F64 @ =RNG_0202f388\n\
	mov r8, r2\n\
	ldr r0, [r2]\n\
	ldr r3, _080C7F68 @ =0x000343FD\n\
	adds r1, r0, #0\n\
	muls r1, r3, r1\n\
	ldr r4, _080C7F6C @ =0x00269EC3\n\
	adds r1, r1, r4\n\
	lsls r1, r1, #1\n\
	lsrs r6, r1, #1\n\
	lsrs r1, r1, #0x11\n\
	movs r5, #0x1f\n\
	ands r1, r5\n\
	movs r2, #0x10\n\
	subs r1, r2, r1\n\
	lsls r1, r1, #8\n\
	ldr r0, [r7, #0x54]\n\
	adds r0, r0, r1\n\
	str r0, [sp]\n\
	adds r0, r6, #0\n\
	muls r0, r3, r0\n\
	adds r0, r0, r4\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	lsrs r0, r0, #0x11\n\
	ands r0, r5\n\
	subs r2, r2, r0\n\
	lsls r2, r2, #8\n\
	ldr r0, [r7, #0x58]\n\
	adds r0, r0, r2\n\
	str r0, [sp, #4]\n\
	muls r3, r1, r3\n\
	adds r3, r3, r4\n\
	lsls r3, r3, #1\n\
	lsrs r0, r3, #1\n\
	mov r1, r8\n\
	str r0, [r1]\n\
	lsrs r3, r3, #0x11\n\
	lsls r3, r3, #0x18\n\
	lsrs r3, r3, #0x18\n\
	adds r0, r7, #0\n\
	mov r1, sp\n\
	movs r2, #2\n\
	bl FUN_080c7984\n\
_080C7ED8:\n\
	mov r2, sl\n\
	ldrh r0, [r2]\n\
	movs r1, #0x12\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080C7EEE\n\
	movs r0, #0x35\n\
	bl PlaySound\n\
_080C7EEE:\n\
	mov r3, sl\n\
	ldrh r0, [r3]\n\
	movs r1, #6\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080C7F18\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	ldrb r3, [r7, #0x12]\n\
	lsrs r3, r3, #1\n\
	movs r0, #3\n\
	ands r3, r0\n\
	adds r0, r7, #0\n\
	mov r1, sp\n\
	movs r2, #1\n\
	bl FUN_080c7984\n\
_080C7F18:\n\
	mov r1, sl\n\
	ldrh r0, [r1]\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
	lsls r0, r0, #0x10\n\
	ldr r1, _080C7F70 @ =0xFFFF0000\n\
	cmp r0, r1\n\
	bne _080C7F52\n\
	ldr r2, [sp, #8]\n\
	ldr r0, [r2]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	ldr r3, [sp, #0xc]\n\
	ldr r0, [r3]\n\
	orrs r0, r1\n\
	str r0, [r3]\n\
	mov r0, sb\n\
	bl PaintEntityWhite\n\
	ldr r1, _080C7F74 @ =gVFXFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r7, #0x14]\n\
_080C7F52:\n\
	add sp, #0x10\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C7F64: .4byte RNG_0202f388\n\
_080C7F68: .4byte 0x000343FD\n\
_080C7F6C: .4byte 0x00269EC3\n\
_080C7F70: .4byte 0xFFFF0000\n\
_080C7F74: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

NAKED static void FUN_080c7f78(struct VFX *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r2, [r4, #0x64]\n\
	movs r5, #0xff\n\
	subs r1, r5, r2\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #4\n\
	cmp r0, #0\n\
	bge _080C7F92\n\
	adds r0, #0xff\n\
_080C7F92:\n\
	asrs r0, r0, #8\n\
	adds r3, r2, r0\n\
	str r3, [r4, #0x64]\n\
	ldr r2, [r4, #0x68]\n\
	subs r1, r5, r2\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	cmp r0, #0\n\
	bge _080C7FA8\n\
	adds r0, #0xff\n\
_080C7FA8:\n\
	asrs r0, r0, #8\n\
	adds r0, r2, r0\n\
	str r0, [r4, #0x68]\n\
	adds r0, r4, #0\n\
	adds r0, #0x50\n\
	strh r3, [r0]\n\
	ldr r0, [r4, #0x68]\n\
	adds r1, r4, #0\n\
	adds r1, #0x52\n\
	strh r0, [r1]\n\
	ldrb r0, [r4, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r4, #0x13]\n\
	subs r1, #0x2e\n\
	strb r0, [r1]\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080C7FE6\n\
	ldr r1, _080C7FEC @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
_080C7FE6:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C7FEC: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

static void FUN_080c7ff0(struct VFX *p) {
  UpdateMotionGraphic(&p->s);
  (p->s).coord.x += (p->s).d.x;
  (p->s).coord.y += (p->s).d.y;
  if ((p->s).motion.state == MOTION_END) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
  }
}

NAKED static void updateFireball(struct VFX *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldr r5, [r4, #0x28]\n\
	bl UpdateMotionGraphic\n\
	adds r2, r4, #0\n\
	adds r2, #0x50\n\
	ldrh r1, [r2]\n\
	ldr r0, _080C807C @ =0x000001FF\n\
	cmp r1, r0\n\
	bhi _080C8054\n\
	adds r0, r1, #4\n\
	strh r0, [r2]\n\
	adds r1, r4, #0\n\
	adds r1, #0x52\n\
	ldrh r0, [r1]\n\
	adds r0, #4\n\
	strh r0, [r1]\n\
_080C8054:\n\
	ldrb r0, [r5, #0xc]\n\
	cmp r0, #4\n\
	bne _080C8074\n\
	ldr r1, _080C8080 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
_080C8074:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C807C: .4byte 0x000001FF\n\
_080C8080: .4byte gVFXFnTable\n\
   .syntax divided\n");
}

// --------------------------------------------

NAKED static void FUN_080c8084(struct VFX *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	ldr r6, [r5, #0x28]\n\
	ldrb r0, [r5, #0xe]\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	bne _080C8098\n\
	strb r1, [r5, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xe]\n\
_080C8098:\n\
	ldrb r1, [r5, #0x12]\n\
	adds r0, r1, #1\n\
	strb r0, [r5, #0x12]\n\
	movs r0, #3\n\
	ands r0, r1\n\
	cmp r0, #1\n\
	bls _080C80C4\n\
	adds r1, r6, #0\n\
	adds r1, #0x8c\n\
	ldr r0, [r1]\n\
	movs r4, #1\n\
	orrs r0, r4\n\
	str r0, [r1]\n\
	adds r1, #4\n\
	ldr r0, [r1]\n\
	orrs r0, r4\n\
	str r0, [r1]\n\
	adds r0, r6, #0\n\
	bl PaintEntityWhite\n\
	strb r4, [r5, #0x11]\n\
	b _080C80E4\n\
_080C80C4:\n\
	adds r1, r6, #0\n\
	adds r1, #0x8c\n\
	ldr r0, [r1]\n\
	movs r2, #2\n\
	rsbs r2, r2, #0\n\
	ands r0, r2\n\
	str r0, [r1]\n\
	adds r1, #4\n\
	ldr r0, [r1]\n\
	ands r0, r2\n\
	str r0, [r1]\n\
	adds r0, r6, #0\n\
	bl UpdateEntityPaletteID\n\
	movs r0, #0\n\
	strb r0, [r5, #0x11]\n\
_080C80E4:\n\
	ldrb r2, [r6, #0xc]\n\
	cmp r2, #4\n\
	bne _080C8102\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _080C8108 @ =gVFXFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	str r2, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x10]\n\
	str r0, [r5, #0x14]\n\
_080C8102:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C8108: .4byte gVFXFnTable\n\
   .syntax divided\n");
}

static void FUN_080c810c(struct VFX *p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

static void FUN_080c8124(struct VFX *p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

static void deleteFireball(struct VFX *p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

// --------------------------------------------

void FUN_080c7a28(struct VFX *p);
void FUN_080c7a90(struct VFX *p);
void FUN_080c7bc4(struct VFX *p);
void initFireball(struct VFX *p);

static const VFXFunc sInitializers[4] = {
    FUN_080c7a28,
    FUN_080c7a90,
    FUN_080c7bc4,
    initFireball,
};

// --------------------------------------------

static void FUN_080c7cc0(struct VFX *p);
static void FUN_080c7f78(struct VFX *p);
static void FUN_080c7ff0(struct VFX *p);
static void updateFireball(struct VFX *p);

static const VFXFunc sUpdates[4] = {
    FUN_080c7cc0,
    FUN_080c7f78,
    FUN_080c7ff0,
    updateFireball,
};

// --------------------------------------------

static void FUN_080c8084(struct VFX *p);
static void FUN_080c810c(struct VFX *p);
static void FUN_080c8124(struct VFX *p);
static void deleteFireball(struct VFX *p);

static const VFXFunc sDeinitializers[4] = {
    FUN_080c8084,
    FUN_080c810c,
    FUN_080c8124,
    deleteFireball,
};
