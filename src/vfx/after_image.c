#include "global.h"
#include "motion.h"
#include "vfx.h"

/*
  ダッシュの残像
*/

static void AfterImage_Init(struct VFX *p);
static void AfterImage_Update(struct VFX *p);
static void AfterImage_Die(struct VFX *p);

// clang-format off
const VFXRoutine gDashAfterImageRoutine = {
    [ENTITY_INIT] =      AfterImage_Init,
    [ENTITY_MAIN] =      AfterImage_Update,
    [ENTITY_DIE] =       AfterImage_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX *CreateAfterImages(struct Entity *p) {
  struct VFX *s1, *s2, *s3;
  s1 = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (s1 != NULL) {
    (s1->s).taskCol = 1;
    INIT_VFX_ROUTINE(s1, VFX_AFTER_IMAGE);
    (s1->s).tileNum = 0;
    (s1->s).palID = 0;
    (s1->s).work[0] = 0;
    (s1->s).work[1] = 0;
    (s1->s).unk_28 = p;
    (s1->s).unk_2c = p;
  }
  s2 = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (s2 != NULL) {
    (s2->s).taskCol = 1;
    INIT_VFX_ROUTINE(s2, VFX_AFTER_IMAGE);
    (s2->s).tileNum = 0;
    (s2->s).palID = 0;
    (s2->s).work[0] = 1;
    (s2->s).work[1] = 0;
    (s2->s).unk_28 = &s1->s;
    (s2->s).unk_2c = p;
  }
  s3 = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (s3 != NULL) {
    (s3->s).taskCol = 1;
    INIT_VFX_ROUTINE(s3, VFX_AFTER_IMAGE);
    (s3->s).tileNum = 0;
    (s3->s).palID = 0;
    (s3->s).work[0] = 2;
    (s3->s).work[1] = 0;
    (s3->s).unk_28 = &s2->s;
    (s3->s).unk_2c = p;
  }
  return s1;
};

// --------------------------------------------

// Reg swapの問題でロジックは問題なし
NON_MATCH static void AfterImage_Init(struct VFX *p) {
#if MODERN
  s32 i;
  struct Coord *c;
  struct Entity *e1 = (p->s).unk_28;
  struct Entity *e2 = (p->s).unk_2c;
  struct Coord *c1 = &p->props.afterImage.c;
  struct Coord *c2 = &(p->s).coord;

  if (e1->mode[0] != 0) {
    InitNonAffineMotion(&p->s);
    (p->s).flags |= DISPLAY;
    (p->s).spr.c = c1;

    if (e2->kind != ENTITY_BOSS) {
      // Zero
      (p->s).taskCol = (p->s).work[0] + 17;
      ForceEntityPalette(&p->s, 12);
    } else {
      // Omega Zero
      (p->s).taskCol = (p->s).work[0] + 25;
      ForceEntityPalette(&p->s, 8);
    }

    c = &c2[0];
    for (i = 2; i >= 0; i--) {
      c->x = (e2->coord).x;
      c->y = (e2->coord).y;
      c = &c[1];
    }

    (p->s).work[2] = 3;
    SET_VFX_ROUTINE(p, ENTITY_MAIN);
    AfterImage_Update(p);
  }
#else
  INCCODE("asm/wip/AfterImage_Init.inc");
#endif
}

NAKED static void AfterImage_Update(struct VFX *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov ip, r0\n\
	ldr r4, [r0, #0x28]\n\
	ldr r5, [r0, #0x2c]\n\
	mov r3, ip\n\
	adds r3, #0x54\n\
	mov r1, ip\n\
	ldr r0, [r1, #0x54]\n\
	str r0, [r1, #0x74]\n\
	ldr r0, [r3, #4]\n\
	str r0, [r1, #0x78]\n\
	adds r1, r3, #0\n\
	movs r2, #1\n\
_080B432A:\n\
	ldr r0, [r1, #8]\n\
	str r0, [r1]\n\
	ldr r0, [r1, #0xc]\n\
	str r0, [r1, #4]\n\
	adds r1, #8\n\
	subs r2, #1\n\
	cmp r2, #0\n\
	bge _080B432A\n\
	mov r2, ip\n\
	ldrb r0, [r2, #0x10]\n\
	cmp r0, #0\n\
	bne _080B434A\n\
	ldr r0, [r4, #0x54]\n\
	str r0, [r3, #0x10]\n\
	ldr r0, [r4, #0x58]\n\
	b _080B4350\n\
_080B434A:\n\
	ldr r0, [r4, #0x74]\n\
	str r0, [r3, #0x10]\n\
	ldr r0, [r4, #0x78]\n\
_080B4350:\n\
	str r0, [r3, #0x14]\n\
	adds r0, r5, #0\n\
	adds r0, #0x48\n\
	ldrh r1, [r0]\n\
	lsls r1, r1, #0x16\n\
	mov r3, ip\n\
	adds r3, #0x48\n\
	lsrs r1, r1, #0x16\n\
	ldrh r2, [r3]\n\
	ldr r0, _080B4390 @ =0xFFFFFC00\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	ldr r0, [r5, #0x3c]\n\
	mov r1, ip\n\
	str r0, [r1, #0x3c]\n\
	adds r0, r5, #0\n\
	adds r0, #0x4e\n\
	ldrb r0, [r0]\n\
	adds r1, #0x4e\n\
	strb r0, [r1]\n\
	ldrb r0, [r5, #0xa]\n\
	lsrs r2, r0, #4\n\
	movs r0, #1\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _080B4394\n\
	mov r1, ip\n\
	ldrb r0, [r1, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080B439C\n\
	.align 2, 0\n\
_080B4390: .4byte 0xFFFFFC00\n\
_080B4394:\n\
	mov r0, ip\n\
	ldrb r1, [r0, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080B439C:\n\
	mov r1, ip\n\
	strb r0, [r1, #0xa]\n\
	movs r6, #1\n\
	adds r1, r6, #0\n\
	ands r1, r2\n\
	mov r0, ip\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	mov r3, ip\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ldrb r0, [r4, #0xc]\n\
	cmp r0, #1\n\
	bhi _080B43CE\n\
	ldrb r1, [r5, #0xa]\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080B43E6\n\
_080B43CE:\n\
	mov r2, ip\n\
	ldrb r0, [r2, #0x10]\n\
	cmp r0, #0\n\
	bne _080B43DC\n\
	movs r0, #2\n\
	strb r0, [r2, #0x11]\n\
	b _080B43E2\n\
_080B43DC:\n\
	ldrb r0, [r4, #0x11]\n\
	mov r1, ip\n\
	strb r0, [r1, #0x11]\n\
_080B43E2:\n\
	mov r2, ip\n\
	str r2, [r2, #0x28]\n\
_080B43E6:\n\
	mov r1, ip\n\
	ldrb r0, [r1, #0x11]\n\
	cmp r0, #2\n\
	bne _080B4414\n\
	ldrb r1, [r1, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	mov r2, ip\n\
	strb r0, [r2, #0xa]\n\
	ldr r1, _080B4410 @ =gVFXFnTable\n\
	ldrb r0, [r2, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r2, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r2, #0x14]\n\
	b _080B4442\n\
	.align 2, 0\n\
_080B4410: .4byte gVFXFnTable\n\
_080B4414:\n\
	cmp r0, #0\n\
	beq _080B4442\n\
	mov r1, ip\n\
	ldrb r0, [r1, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r1, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080B4442\n\
	ldr r1, _080B4448 @ =gVFXFnTable\n\
	mov r2, ip\n\
	ldrb r0, [r2, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r2, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r2, #0x14]\n\
	mov r0, ip\n\
	bl AfterImage_Die\n\
_080B4442:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B4448: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

static void AfterImage_Die(struct VFX *p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}
