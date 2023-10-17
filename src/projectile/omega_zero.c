#include "collision.h"
#include "global.h"
#include "projectile.h"

static const struct Collision gOmegaZeroProjectileCollisions_0836c9c0[41];

static void OmegaZeroProjectile_Init(struct Projectile *p);
static void OmegaZeroProjectile_Update(struct Projectile *p);
static void OmegaZeroProjectile_Die(struct Projectile *p);

// clang-format off
const ProjectileRoutine gOmegaZeroProjectileRoutine = {
    [ENTITY_INIT] =      OmegaZeroProjectile_Init,
    [ENTITY_UPDATE] =    OmegaZeroProjectile_Update,
    [ENTITY_DIE] =       OmegaZeroProjectile_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

NAKED static void OmegaZeroProjectile_Init(struct Projectile *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldr r1, _080AE53C @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	ldr r1, _080AE540 @ =0x0836D264\n\
	ldrb r0, [r4, #0x10]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	strb r0, [r4, #0xd]\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r5, r4, #0\n\
	adds r5, #0x74\n\
	ldr r1, _080AE544 @ =0x0836C9C0\n\
	adds r2, r4, #0\n\
	adds r2, #0x54\n\
	adds r0, r5, #0\n\
	movs r3, #1\n\
	bl InitBody\n\
	str r4, [r5, #0x2c]\n\
	ldr r0, _080AE548 @ =nop_080ae4d8\n\
	str r0, [r5, #0x24]\n\
	adds r0, r4, #0\n\
	bl OmegaZeroProjectile_Update\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080AE53C: .4byte gProjectileFnTable\n\
_080AE540: .4byte 0x0836D264\n\
_080AE544: .4byte 0x0836C9C0\n\
_080AE548: .4byte nop_080ae4d8\n\
 .syntax divided\n");
}

// --------------------------------------------

static void nop_080ae5b4(struct Projectile *_);
static void OmegaZeroSaber_Update(struct Projectile *p);
static void Messenkou_Update(struct Projectile *p);
static void ArcBlade_Update(struct Projectile *p);
static void Rekkoha_Update(struct Projectile *p);
static void DoubleChargeWave1_Update(struct Projectile *p);
static void DoubleChargeWave2_Update(struct Projectile *p);
static void DoubleChargeWave3_Update(struct Projectile *p);

static void OmegaZeroProjectile_Update(struct Projectile *p) {
  // clang-format off
  static const ProjectileFunc sUpdates1[7] = {
      nop_080ae5b4,
      nop_080ae5b4,
      nop_080ae5b4,
      nop_080ae5b4,
      nop_080ae5b4,
      nop_080ae5b4,
      nop_080ae5b4,
  };
  // clang-format on
  // clang-format off
  static const ProjectileFunc sUpdates2[7] = {
      OmegaZeroSaber_Update, // All Saber Attack
      Messenkou_Update,
      ArcBlade_Update,
      Rekkoha_Update,
      DoubleChargeWave1_Update, // 1st shot
      DoubleChargeWave2_Update, // 2nd shot
      DoubleChargeWave3_Update, // O-Saber wave
  };
  // clang-format on
  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void OmegaZeroProjectile_Die(struct Projectile *p) {
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~(COLLIDABLE);
  (p->s).flags &= ~(DISPLAY);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080ae5b4(struct Projectile *_) { return; }

// 01 00 xx --
NAKED static void OmegaZeroSaber_Update(struct Projectile *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldr r5, [r4, #0x28]\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	beq _080AE5CA\n\
	cmp r0, #1\n\
	beq _080AE630\n\
	b _080AE690\n\
_080AE5CA:\n\
	adds r0, r4, #0\n\
	bl ResetDynamicMotion\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	strh r0, [r4, #0x20]\n\
	adds r1, r4, #0\n\
	adds r1, #0x22\n\
	movs r0, #5\n\
	strb r0, [r1]\n\
	ldr r1, _080AE604 @ =0x0836D26C\n\
	ldrb r0, [r4, #0x11]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r5, #0xa]\n\
	lsrs r2, r0, #4\n\
	movs r0, #1\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _080AE608\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080AE60E\n\
	.align 2, 0\n\
_080AE604: .4byte 0x0836D26C\n\
_080AE608:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080AE60E:\n\
	strb r0, [r4, #0xa]\n\
	adds r1, r2, #0\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r4, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080AE630:\n\
	ldr r0, [r5, #0x54]\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r5, #0x58]\n\
	str r0, [r4, #0x58]\n\
	ldrb r0, [r4, #0x11]\n\
	cmp r0, #9\n\
	bls _080AE64C\n\
	adds r0, r4, #0\n\
	bl FUN_0801779c\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	b _080AE652\n\
_080AE64C:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
_080AE652:\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _080AE6D4 @ =0x0836D28C\n\
	ldrb r2, [r4, #0x11]\n\
	lsls r2, r2, #2\n\
	adds r2, r2, r1\n\
	adds r1, r4, #0\n\
	adds r1, #0x71\n\
	ldrb r1, [r1]\n\
	lsls r1, r1, #0x18\n\
	asrs r1, r1, #0x18\n\
	ldr r2, [r2]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	bl SetDDP\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080AE690\n\
	ldr r1, _080AE6D8 @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
_080AE690:\n\
	ldrb r0, [r5, #0xc]\n\
	cmp r0, #1\n\
	bls _080AE6CC\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080AE6D8 @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
_080AE6CC:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080AE6D4: .4byte 0x0836D28C\n\
_080AE6D8: .4byte gProjectileFnTable\n\
 .syntax divided\n");
}

// 01 01 xx --
NAKED static void Messenkou_Update(struct Projectile *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	beq _080AE6EC\n\
	cmp r0, #1\n\
	beq _080AE760\n\
	b _080AE7CE\n\
_080AE6EC:\n\
	adds r0, r4, #0\n\
	bl InitRotatableMotion\n\
	ldrb r0, [r4, #0x12]\n\
	lsls r0, r0, #5\n\
	movs r1, #0x80\n\
	rsbs r1, r1, #0\n\
	adds r5, r1, #0\n\
	subs r0, r5, r0\n\
	adds r1, r4, #0\n\
	adds r1, #0x24\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _080AE7D4 @ =0x0836CA08\n\
	bl SetDDP\n\
	ldr r2, _080AE7D8 @ =gSineTable\n\
	ldrb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x1d\n\
	movs r3, #0x80\n\
	lsls r3, r3, #0x17\n\
	adds r0, r0, r3\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r2\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #7\n\
	cmp r0, #0\n\
	bge _080AE72E\n\
	adds r0, #0xff\n\
_080AE72E:\n\
	asrs r0, r0, #8\n\
	str r0, [r4, #0x5c]\n\
	ldrb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x1d\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r2\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #7\n\
	cmp r0, #0\n\
	bge _080AE74A\n\
	adds r0, #0xff\n\
_080AE74A:\n\
	asrs r0, r0, #8\n\
	rsbs r0, r0, #0\n\
	str r0, [r4, #0x60]\n\
	ldr r1, _080AE7DC @ =0x00008001\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	strb r5, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080AE760:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, [r4, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _080AE786\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080AE7CE\n\
_080AE786:\n\
	ldr r0, _080AE7E0 @ =gStageRun+232\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	bl CalcFromCamera\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	cmp r0, r1\n\
	bls _080AE7CE\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080AE7E4 @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
_080AE7CE:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080AE7D4: .4byte 0x0836CA08\n\
_080AE7D8: .4byte gSineTable\n\
_080AE7DC: .4byte 0x00008001\n\
_080AE7E0: .4byte gStageRun+232\n\
_080AE7E4: .4byte gProjectileFnTable\n\
 .syntax divided\n");
}

// 01 02 xx --
NAKED static void ArcBlade_Update(struct Projectile *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	beq _080AE7F8\n\
	cmp r0, #1\n\
	beq _080AE87C\n\
	b _080AE8EA\n\
_080AE7F8:\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _080AE8F0 @ =0x0836C9C0\n\
	bl SetDDP\n\
	adds r0, r4, #0\n\
	bl InitRotatableMotion\n\
	movs r5, #0x80\n\
	ldrb r0, [r4, #0x12]\n\
	lsls r0, r0, #7\n\
	movs r1, #6\n\
	bl __divsi3\n\
	subs r0, r5, r0\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	ldrb r0, [r4, #0x13]\n\
	cmp r0, #0\n\
	beq _080AE828\n\
	movs r0, #0x80\n\
	subs r0, r0, r5\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
_080AE828:\n\
	adds r1, r5, #0\n\
	adds r1, #0x80\n\
	adds r0, r4, #0\n\
	adds r0, #0x24\n\
	strb r1, [r0]\n\
	ldr r2, _080AE8F4 @ =gSineTable\n\
	adds r0, r5, #0\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r2\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #7\n\
	cmp r0, #0\n\
	bge _080AE84E\n\
	adds r0, #0xff\n\
_080AE84E:\n\
	asrs r0, r0, #8\n\
	str r0, [r4, #0x5c]\n\
	lsls r0, r5, #1\n\
	adds r0, r0, r2\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #7\n\
	cmp r0, #0\n\
	bge _080AE866\n\
	adds r0, #0xff\n\
_080AE866:\n\
	asrs r0, r0, #8\n\
	str r0, [r4, #0x60]\n\
	ldr r1, _080AE8F8 @ =0x00008009\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r0, #0x80\n\
	strb r0, [r4, #0x13]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080AE87C:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, [r4, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _080AE8A2\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080AE8EA\n\
_080AE8A2:\n\
	ldr r0, _080AE8FC @ =gStageRun+232\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	bl CalcFromCamera\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	cmp r0, r1\n\
	bls _080AE8EA\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080AE900 @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
_080AE8EA:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080AE8F0: .4byte 0x0836C9C0\n\
_080AE8F4: .4byte gSineTable\n\
_080AE8F8: .4byte 0x00008009\n\
_080AE8FC: .4byte gStageRun+232\n\
_080AE900: .4byte gProjectileFnTable\n\
 .syntax divided\n");
}

// 01 03 xx --
NAKED static void Rekkoha_Update(struct Projectile *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldr r5, [r4, #0x28]\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #1\n\
	beq _080AE940\n\
	cmp r0, #1\n\
	bgt _080AE91A\n\
	cmp r0, #0\n\
	beq _080AE924\n\
	b _080AEA3E\n\
_080AE91A:\n\
	cmp r0, #2\n\
	beq _080AE9D4\n\
	cmp r0, #3\n\
	beq _080AE9FA\n\
	b _080AEA3E\n\
_080AE924:\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _080AE98C @ =0x0836CA80\n\
	bl SetDDP\n\
	movs r0, #0x4c\n\
	strb r0, [r4, #0x13]\n\
	ldr r1, _080AE990 @ =0x00008002\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080AE940:\n\
	ldr r2, [r5, #0x54]\n\
	str r2, [r4, #0x54]\n\
	ldr r1, _080AE994 @ =gSineTable\n\
	ldrb r0, [r4, #0x12]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r1\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #3\n\
	adds r2, r2, r0\n\
	str r2, [r4, #0x54]\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x71\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	ble _080AE9A2\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _080AE998 @ =0x0836CA20\n\
	bl SetDDP\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080AE99C\n\
	ldrb r0, [r4, #0x12]\n\
	adds r0, #4\n\
	b _080AE9A0\n\
	.align 2, 0\n\
_080AE98C: .4byte 0x0836CA80\n\
_080AE990: .4byte 0x00008002\n\
_080AE994: .4byte gSineTable\n\
_080AE998: .4byte 0x0836CA20\n\
_080AE99C:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #4\n\
_080AE9A0:\n\
	strb r0, [r4, #0x12]\n\
_080AE9A2:\n\
	ldrb r0, [r4, #0x13]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x13]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _080AE9B4\n\
	ldrb r0, [r5, #0xc]\n\
	cmp r0, #1\n\
	bls _080AE9BA\n\
_080AE9B4:\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080AE9BA:\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0x80\n\
	bls _080AE9CA\n\
	adds r1, r4, #0\n\
	adds r1, #0x25\n\
	movs r0, #0x17\n\
	strb r0, [r1]\n\
	b _080AEA3E\n\
_080AE9CA:\n\
	adds r1, r4, #0\n\
	adds r1, #0x25\n\
	movs r0, #0x19\n\
	strb r0, [r1]\n\
	b _080AEA3E\n\
_080AE9D4:\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	movs r1, #0\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	strb r1, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080AEA44 @ =0x00008003\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080AE9FA:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r3, [r0]\n\
	cmp r3, #3\n\
	bne _080AEA3E\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080AEA48 @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	str r3, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
_080AEA3E:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080AEA44: .4byte 0x00008003\n\
_080AEA48: .4byte gProjectileFnTable\n\
 .syntax divided\n");
}

// 01 04 xx --
NAKED static void DoubleChargeWave1_Update(struct Projectile *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	beq _080AEA5C\n\
	cmp r0, #1\n\
	beq _080AEABC\n\
	b _080AEB30\n\
_080AEA5C:\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _080AEA74 @ =0x0836CA38\n\
	bl SetDDP\n\
	ldrb r2, [r4, #0x12]\n\
	cmp r2, #0\n\
	beq _080AEA78\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	orrs r0, r1\n\
	b _080AEA7E\n\
	.align 2, 0\n\
_080AEA74: .4byte 0x0836CA38\n\
_080AEA78:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080AEA7E:\n\
	strb r0, [r4, #0xa]\n\
	movs r1, #1\n\
	ands r1, r2\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r4, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ldrb r1, [r4, #0x12]\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #8\n\
	ldr r1, _080AEB38 @ =0xFFFFFB80\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x5c]\n\
	movs r0, #0x80\n\
	strb r0, [r4, #0x12]\n\
	ldr r1, _080AEB3C @ =0x00008007\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080AEABC:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x71\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	ble _080AEAD8\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
_080AEAD8:\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _080AEAE8\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080AEB30\n\
_080AEAE8:\n\
	ldr r0, _080AEB40 @ =gStageRun+232\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	bl CalcFromCamera\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	cmp r0, r1\n\
	bls _080AEB30\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080AEB44 @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
_080AEB30:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080AEB38: .4byte 0xFFFFFB80\n\
_080AEB3C: .4byte 0x00008007\n\
_080AEB40: .4byte gStageRun+232\n\
_080AEB44: .4byte gProjectileFnTable\n\
 .syntax divided\n");
}

// 01 05 xx --
NAKED static void DoubleChargeWave2_Update(struct Projectile *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	beq _080AEB58\n\
	cmp r0, #1\n\
	beq _080AEBC0\n\
	b _080AEC6E\n\
_080AEB58:\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _080AEB70 @ =0x0836CA50\n\
	bl SetDDP\n\
	ldrb r2, [r4, #0x12]\n\
	cmp r2, #0\n\
	beq _080AEB74\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	orrs r0, r1\n\
	b _080AEB7A\n\
	.align 2, 0\n\
_080AEB70: .4byte 0x0836CA50\n\
_080AEB74:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080AEB7A:\n\
	strb r0, [r4, #0xa]\n\
	movs r1, #1\n\
	ands r1, r2\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	movs r3, #0\n\
	strb r1, [r0]\n\
	movs r0, #0x4a\n\
	adds r0, r0, r4\n\
	mov ip, r0\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r0]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	mov r1, ip\n\
	strb r0, [r1]\n\
	ldrb r1, [r4, #0x12]\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #8\n\
	ldr r1, _080AEC74 @ =0xFFFFFB80\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x5c]\n\
	movs r0, #0x80\n\
	str r0, [r4, #0x64]\n\
	strb r3, [r4, #0x13]\n\
	ldr r1, _080AEC78 @ =0x00008008\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080AEBC0:\n\
	ldrb r0, [r4, #0x13]\n\
	adds r0, #1\n\
	movs r5, #0\n\
	strb r0, [r4, #0x13]\n\
	ldrb r0, [r4, #0x13]\n\
	movs r6, #3\n\
	ands r0, r6\n\
	cmp r0, #0\n\
	bne _080AEC00\n\
	ldrb r1, [r4, #0x12]\n\
	lsls r1, r1, #0xd\n\
	ldr r0, _080AEC7C @ =0xFFFFF000\n\
	adds r1, r1, r0\n\
	ldr r0, [r4, #0x54]\n\
	subs r0, r0, r1\n\
	ldr r3, _080AEC80 @ =RNG_0202f388\n\
	ldr r2, [r3]\n\
	ldr r1, _080AEC84 @ =0x000343FD\n\
	muls r2, r1, r2\n\
	ldr r1, _080AEC88 @ =0x00269EC3\n\
	adds r2, r2, r1\n\
	lsls r2, r2, #1\n\
	lsrs r1, r2, #1\n\
	str r1, [r3]\n\
	lsls r2, r2, #3\n\
	lsrs r2, r2, #0x14\n\
	ldr r1, _080AEC8C @ =0xFFFFF800\n\
	adds r2, r2, r1\n\
	ldr r1, [r4, #0x58]\n\
	adds r1, r1, r2\n\
	bl FUN_080c3bf4\n\
_080AEC00:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x71\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #3\n\
	ble _080AEC1C\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
_080AEC1C:\n\
	ldr r0, [r4, #0x64]\n\
	cmp r0, #0\n\
	beq _080AEC2A\n\
	subs r0, #1\n\
	str r0, [r4, #0x64]\n\
	cmp r0, #0\n\
	bne _080AEC6E\n\
_080AEC2A:\n\
	ldr r0, _080AEC90 @ =gStageRun+232\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	bl CalcFromCamera\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	cmp r0, r1\n\
	bls _080AEC6E\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	str r5, [r0]\n\
	adds r0, #4\n\
	str r5, [r0]\n\
	adds r0, #4\n\
	strb r5, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080AEC94 @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	str r6, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
_080AEC6E:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080AEC74: .4byte 0xFFFFFB80\n\
_080AEC78: .4byte 0x00008008\n\
_080AEC7C: .4byte 0xFFFFF000\n\
_080AEC80: .4byte RNG_0202f388\n\
_080AEC84: .4byte 0x000343FD\n\
_080AEC88: .4byte 0x00269EC3\n\
_080AEC8C: .4byte 0xFFFFF800\n\
_080AEC90: .4byte gStageRun+232\n\
_080AEC94: .4byte gProjectileFnTable\n\
 .syntax divided\n");
}

// 01 06 xx --
NAKED static void DoubleChargeWave3_Update(struct Projectile *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	beq _080AECA8\n\
	cmp r0, #1\n\
	beq _080AED10\n\
	b _080AED74\n\
_080AECA8:\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _080AECC0 @ =0x0836CA68\n\
	bl SetDDP\n\
	ldrb r2, [r4, #0x12]\n\
	cmp r2, #0\n\
	beq _080AECC4\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	orrs r0, r1\n\
	b _080AECCA\n\
	.align 2, 0\n\
_080AECC0: .4byte 0x0836CA68\n\
_080AECC4:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080AECCA:\n\
	strb r0, [r4, #0xa]\n\
	movs r1, #1\n\
	ands r1, r2\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	movs r3, #0\n\
	strb r1, [r0]\n\
	movs r0, #0x4a\n\
	adds r0, r0, r4\n\
	mov ip, r0\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r0]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	mov r1, ip\n\
	strb r0, [r1]\n\
	ldrb r1, [r4, #0x12]\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #8\n\
	ldr r1, _080AED7C @ =0xFFFFFB80\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x5c]\n\
	movs r0, #0x80\n\
	str r0, [r4, #0x64]\n\
	strb r3, [r4, #0x13]\n\
	ldr r1, _080AED80 @ =0x00008005\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080AED10:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r4, #0x64]\n\
	cmp r0, #0\n\
	beq _080AED2C\n\
	subs r0, #1\n\
	str r0, [r4, #0x64]\n\
	cmp r0, #0\n\
	bne _080AED74\n\
_080AED2C:\n\
	ldr r0, _080AED84 @ =gStageRun+232\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	bl CalcFromCamera\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	cmp r0, r1\n\
	bls _080AED74\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080AED88 @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
_080AED74:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080AED7C: .4byte 0xFFFFFB80\n\
_080AED80: .4byte 0x00008005\n\
_080AED84: .4byte gStageRun+232\n\
_080AED88: .4byte gProjectileFnTable\n\
 .syntax divided\n");
}

static const struct Collision gOmegaZeroProjectileCollisions_0836c9c0[41] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {-0x0400, 0x0000, 0x0800, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0200, -0x0600, 0x0800, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0200, 0x0600, 0x0800, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x0F00, 0x0F00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 5,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x0E00, -0x4C00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0600, 0x0000, 0x1900, 0x1A00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0600, 0x0000, 0x1900, 0x1A00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0300, -0x0100, 0x0A00, 0x1F00},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 2,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000020,
      range : {-0x2000, -0x1200, 0x2600, 0x1A00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 2,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x0800, -0x2200, 0x3A00, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 2,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {0x0D00, -0x2100, 0x1000, 0x0A00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000020,
      range : {-0x2000, -0x1200, 0x2600, 0x1A00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x0800, -0x2200, 0x3A00, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {0x0D00, -0x2100, 0x1000, 0x0A00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x02,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000020,
      range : {-0x0F00, -0x2200, 0x3800, 0x0E00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x02,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000020,
      range : {-0x2700, -0x1200, 0x1A00, 0x1600},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x02,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x1600, 0x0000, 0x2F00, 0x0E00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x02,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000020,
      range : {-0x0E00, 0x0100, 0x1E00, 0x0E00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x02,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000020,
      range : {-0x0F00, -0x2200, 0x3800, 0x0E00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x02,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000020,
      range : {-0x2700, -0x1200, 0x1A00, 0x1600},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x02,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x1600, 0x0000, 0x2F00, 0x0E00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x02,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x0E00, 0x0100, 0x1E00, 0x0E00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x04,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000020,
      range : {-0x0F00, -0x2200, 0x3800, 0x0E00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x04,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000020,
      range : {-0x2700, -0x1200, 0x1A00, 0x1600},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x04,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x1600, 0x0000, 0x2F00, 0x0E00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x04,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x0E00, 0x0100, 0x1E00, 0x0E00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x03,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {0x0600, -0x0200, 0x0800, 0x1000},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x03,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {0x1300, -0x1100, 0x0900, 0x1200},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x03,
      hitzone : 0x00,
      remaining : 4,
      layer : 0x00000020,
      range : {0x1400, -0x1C00, 0x0E00, 0x2400},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x03,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000020,
      range : {0x0000, -0x3100, 0x2200, 0x0C00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x03,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000020,
      range : {-0x1E00, -0x3100, 0x1C00, 0x0C00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x03,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000020,
      range : {-0x2A00, -0x1900, 0x1700, 0x2200},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x03,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x2100, -0x0300, 0x1D00, 0x0A00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x05,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {0x0600, -0x0200, 0x0800, 0x1000},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x05,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {0x1300, -0x1100, 0x0900, 0x1200},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x05,
      hitzone : 0x00,
      remaining : 4,
      layer : 0x00000020,
      range : {0x1400, -0x1C00, 0x0E00, 0x2400},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x05,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000020,
      range : {0x0000, -0x3100, 0x2200, 0x0C00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x05,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000020,
      range : {-0x1E00, -0x3100, 0x1C00, 0x0C00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x05,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000020,
      range : {-0x2A00, -0x1900, 0x1700, 0x2200},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x05,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x2100, -0x0300, 0x1D00, 0x0A00},
    },
};

// clang-format off
static const struct Collision *const PTR_ARRAY_0836cd98[8] = {
  [0] = &(gOmegaZeroProjectileCollisions_0836c9c0[9]),
  [1] = &(gOmegaZeroProjectileCollisions_0836c9c0[9]),
  [2] = &(gOmegaZeroProjectileCollisions_0836c9c0[10]),
  [3] = &(gOmegaZeroProjectileCollisions_0836c9c0[11]),
  [4] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
  [5] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
  [6] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
  [7] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
};

static const struct Collision *const PTR_ARRAY_0836cdb8[8] = {
  [0] = &(gOmegaZeroProjectileCollisions_0836c9c0[12]),
  [1] = &(gOmegaZeroProjectileCollisions_0836c9c0[12]),
  [2] = &(gOmegaZeroProjectileCollisions_0836c9c0[13]),
  [3] = &(gOmegaZeroProjectileCollisions_0836c9c0[14]),
  [4] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
  [5] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
  [6] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
  [7] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
};

const struct Collision *const PTR_ARRAY_0836cdd8[7] = {
  [0] = &(gOmegaZeroProjectileCollisions_0836c9c0[15]),
  [1] = &(gOmegaZeroProjectileCollisions_0836c9c0[15]),
  [2] = &(gOmegaZeroProjectileCollisions_0836c9c0[17]),
  [3] = &(gOmegaZeroProjectileCollisions_0836c9c0[18]),
  [4] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
  [5] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
  [6] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
};

const struct Collision *const PTR_ARRAY_0836cdf4[7] = {
  [0] = &(gOmegaZeroProjectileCollisions_0836c9c0[19]),
  [1] = &(gOmegaZeroProjectileCollisions_0836c9c0[19]),
  [2] = &(gOmegaZeroProjectileCollisions_0836c9c0[21]),
  [3] = &(gOmegaZeroProjectileCollisions_0836c9c0[22]),
  [4] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
  [5] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
  [6] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
};

const struct Collision *const PTR_ARRAY_0836ce10[7] = {
  [0] = &(gOmegaZeroProjectileCollisions_0836c9c0[23]),
  [1] = &(gOmegaZeroProjectileCollisions_0836c9c0[23]),
  [2] = &(gOmegaZeroProjectileCollisions_0836c9c0[25]),
  [3] = &(gOmegaZeroProjectileCollisions_0836c9c0[26]),
  [4] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
  [5] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
  [6] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
};

const struct Collision *const PTR_ARRAY_0836ce2c[11] = {
  [0] =  &(gOmegaZeroProjectileCollisions_0836c9c0[27]),
  [1] =  &(gOmegaZeroProjectileCollisions_0836c9c0[28]),
  [2] =  &(gOmegaZeroProjectileCollisions_0836c9c0[28]),
  [3] =  &(gOmegaZeroProjectileCollisions_0836c9c0[28]),
  [4] =  &(gOmegaZeroProjectileCollisions_0836c9c0[29]),
  [5] =  &(gOmegaZeroProjectileCollisions_0836c9c0[29]),
  [6] =  &(gOmegaZeroProjectileCollisions_0836c9c0[31]),
  [7] =  &(gOmegaZeroProjectileCollisions_0836c9c0[33]),
  [8] =  &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
  [9] =  &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
  [10] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
};

const struct Collision *const PTR_ARRAY_0836ce58[11] = {
  [0] =  &(gOmegaZeroProjectileCollisions_0836c9c0[34]),
  [1] =  &(gOmegaZeroProjectileCollisions_0836c9c0[35]),
  [2] =  &(gOmegaZeroProjectileCollisions_0836c9c0[35]),
  [3] =  &(gOmegaZeroProjectileCollisions_0836c9c0[35]),
  [4] =  &(gOmegaZeroProjectileCollisions_0836c9c0[36]),
  [5] =  &(gOmegaZeroProjectileCollisions_0836c9c0[36]),
  [6] =  &(gOmegaZeroProjectileCollisions_0836c9c0[38]),
  [7] =  &(gOmegaZeroProjectileCollisions_0836c9c0[40]),
  [8] =  &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
  [9] =  &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
  [10] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
};
// clang-format on

const struct Collision gOmegaZeroProjectileCollisions_0836ce84[5] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x07,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000020,
      range : {-0x1B00, -0x0600, 0x1C00, 0x1000},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x07,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {0x0100, -0x0E00, 0x1C00, 0x0D00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x04,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000020,
      range : {-0x1800, -0x1000, 0x1D00, 0x3900},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x04,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x1100, -0x2900, 0x2000, 0x1500},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x04,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x0D00, -0x2B00, 0x1A00, 0x1100},
    },
};

const struct Collision *const PTR_ARRAY_0836cefc[2] = {
    [0] = &(gOmegaZeroProjectileCollisions_0836ce84[1]),
    [1] = &(gOmegaZeroProjectileCollisions_0836ce84[0]),
};

const struct Collision *const PTR_ARRAY_0836cf04[4] = {
    [0] = &(gOmegaZeroProjectileCollisions_0836ce84[2]),
    [1] = &(gOmegaZeroProjectileCollisions_0836ce84[2]),
    [2] = &(gOmegaZeroProjectileCollisions_0836ce84[3]),
    [3] = &(gOmegaZeroProjectileCollisions_0836ce84[4]),
};

const struct Collision *const PTR_ARRAY_0836cf14[2] = {
    [0] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
    [1] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
};

const struct Collision gOmegaZeroProjectileCollisions_0836cf1c[12] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x03,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {0x0F00, -0x0C00, 0x0E00, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x03,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000020,
      range : {-0x0F00, -0x0D00, 0x3A00, 0x2400},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x03,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x1A00, -0x3000, 0x2100, 0x2200},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x03,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x1000, -0x3200, 0x0D00, 0x1C00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x03,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {0x0F00, -0x0C00, 0x0E00, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x03,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000020,
      range : {-0x0F00, -0x0D00, 0x3A00, 0x2400},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x03,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x1A00, -0x3000, 0x2100, 0x2200},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x03,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x1000, -0x3200, 0x0D00, 0x1C00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x06,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {0x0F00, -0x0C00, 0x0E00, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x06,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000020,
      range : {-0x0F00, -0x0D00, 0x3A00, 0x2400},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x06,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {-0x1A00, -0x3000, 0x2100, 0x2200},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x06,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x1000, -0x3200, 0x0D00, 0x1C00},
    },
};

// clang-format off

static const struct Collision *const PTR_ARRAY_0836d03c[8] = {
    [0] =  &(gOmegaZeroProjectileCollisions_0836cf1c[0]),
    [1] =  &(gOmegaZeroProjectileCollisions_0836cf1c[1]),
    [2] =  &(gOmegaZeroProjectileCollisions_0836cf1c[1]),
    [3] =  &(gOmegaZeroProjectileCollisions_0836cf1c[2]),
    [4] =  &(gOmegaZeroProjectileCollisions_0836cf1c[3]),
    [5] =  &(gOmegaZeroProjectileCollisions_0836cf1c[3]),
    [6] =  &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
    [7] =  &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
};

static const struct Collision *const PTR_ARRAY_0836d05c[8] = {
    [0] =  &(gOmegaZeroProjectileCollisions_0836cf1c[4]),
    [1] =  &(gOmegaZeroProjectileCollisions_0836cf1c[5]),
    [2] =  &(gOmegaZeroProjectileCollisions_0836cf1c[5]),
    [3] =  &(gOmegaZeroProjectileCollisions_0836cf1c[6]),
    [4] =  &(gOmegaZeroProjectileCollisions_0836cf1c[7]),
    [5] =  &(gOmegaZeroProjectileCollisions_0836cf1c[7]),
    [6] =  &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
    [7] =  &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
};

static const struct Collision *const PTR_ARRAY_0836d07c[8] = {
    [0] =  &(gOmegaZeroProjectileCollisions_0836cf1c[8]),
    [1] =  &(gOmegaZeroProjectileCollisions_0836cf1c[9]),
    [2] =  &(gOmegaZeroProjectileCollisions_0836cf1c[9]),
    [3] =  &(gOmegaZeroProjectileCollisions_0836cf1c[10]),
    [4] =  &(gOmegaZeroProjectileCollisions_0836cf1c[11]),
    [5] =  &(gOmegaZeroProjectileCollisions_0836cf1c[11]),
    [6] =  &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
    [7] =  &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
};

// clang-format on

static const struct Collision gOmegaZeroProjectileCollisions_0836d09c[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 5,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x04,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {0x1200, -0x1800, 0x0800, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 5,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x04,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000020,
      range : {-0x0900, -0x1900, 0x3200, 0x1800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 5,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x04,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000020,
      range : {-0x1E00, -0x0E00, 0x1600, 0x2400},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 5,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x04,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x3700, -0x1E00, 0x1E00, 0x3C00},
    },
};

// clang-format off
static const struct Collision *const PTR_ARRAY_0836d0fc[10] = {
    [0] =  &(gOmegaZeroProjectileCollisions_0836d09c[0]),
    [1] =  &(gOmegaZeroProjectileCollisions_0836d09c[0]),
    [2] =  &(gOmegaZeroProjectileCollisions_0836d09c[1]),
    [3] =  &(gOmegaZeroProjectileCollisions_0836d09c[2]),
    [4] =  &(gOmegaZeroProjectileCollisions_0836d09c[2]),
    [5] =  &(gOmegaZeroProjectileCollisions_0836d09c[2]),
    [6] =  &(gOmegaZeroProjectileCollisions_0836d09c[2]),
    [7] =  &(gOmegaZeroProjectileCollisions_0836d09c[2]),
    [8] =  &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
    [9] =  &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
};
// clang-format on

static const struct Collision gOmegaZeroProjectileCollisions_0836d124[11] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {0x0300, -0x1A00, 0x2400, 0x2C00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x0500, -0x2600, 0x2A00, 0x1D00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x1A00, -0x1F00, 0x1F00, 0x2800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x1C00, -0x0D00, 0x1E00, 0x2C00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x1400, 0x0A00, 0x2800, 0x1F00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {0x0000, 0x0C00, 0x2A00, 0x1D00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {0x1300, 0x0300, 0x1F00, 0x2800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {0x1600, -0x0E00, 0x1E00, 0x2C00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {0x0D00, -0x2300, 0x2800, 0x1F00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x1900, -0x1300, 0x2000, 0x3200},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {-0x1700, -0x0700, 0x1C00, 0x1800},
    },
};

// clang-format off
static const struct Collision *const PTR_ARRAY_0836d22c[12] = {
    [0] =  &(gOmegaZeroProjectileCollisions_0836d124[0]),
    [1] =  &(gOmegaZeroProjectileCollisions_0836d124[1]),
    [2] =  &(gOmegaZeroProjectileCollisions_0836d124[2]),
    [3] =  &(gOmegaZeroProjectileCollisions_0836d124[3]),
    [4] =  &(gOmegaZeroProjectileCollisions_0836d124[4]),
    [5] =  &(gOmegaZeroProjectileCollisions_0836d124[5]),
    [6] =  &(gOmegaZeroProjectileCollisions_0836d124[6]),
    [7] =  &(gOmegaZeroProjectileCollisions_0836d124[7]),
    [8] =  &(gOmegaZeroProjectileCollisions_0836d124[8]),
    [9] =  &(gOmegaZeroProjectileCollisions_0836d124[1]),
    [10] = &(gOmegaZeroProjectileCollisions_0836d124[9]),
    [11] = &(gOmegaZeroProjectileCollisions_0836d124[10]),
};
// clang-format on

static const struct Collision *const PTR_ARRAY_0836d25c[2] = {
    [0] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
    [1] = &(gOmegaZeroProjectileCollisions_0836c9c0[8]),
};

// (p->s).work[0] -> (p->s).mode[1]
const u8 gOmegaZeroProjectileInitModes[8] = {
    0, 1, 2, 3, 4, 5, 6, 0,
};

// clang-format off
const motion_t gOmegaZeroSaberMotions[16] = {
    MOTION(0x58, 0x00),
    MOTION(0x59, 0x00),
    MOTION(0x5A, 0x00),
    MOTION(0x5B, 0x00),
    MOTION(0x5C, 0x00),
    MOTION(0x5C, 0x01),
    MOTION(0x5C, 0x02),
    MOTION(0x40, 0x00),
    MOTION(0x63, 0x00),
    MOTION(0x62, 0x01),
    MOTION(0x58, 0x00),
    MOTION(0x59, 0x00),
    MOTION(0x5B, 0x00),
    MOTION(0x59, 0x00),
    MOTION(0x5A, 0x00),
    MOTION(0x5B, 0x00),
};
// clang-format on

// clang-format off
const struct Collision *const *const PTR_ARRAY_0836d28c[16] = {
    PTR_ARRAY_0836cd98,
    PTR_ARRAY_0836cdd8,
    PTR_ARRAY_0836ce2c,
    PTR_ARRAY_0836d03c,
    PTR_ARRAY_0836cefc,
    PTR_ARRAY_0836cf04,
    PTR_ARRAY_0836cf14,
    PTR_ARRAY_0836d0fc,
    PTR_ARRAY_0836d22c,
    PTR_ARRAY_0836d25c,
    PTR_ARRAY_0836cdb8,
    PTR_ARRAY_0836cdf4,
    PTR_ARRAY_0836d05c,
    PTR_ARRAY_0836ce10,
    PTR_ARRAY_0836ce58,
    PTR_ARRAY_0836d07c,
};
// clang-format on
