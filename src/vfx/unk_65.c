#include "global.h"
#include "vfx.h"

static void Ghost65_Init(struct Entity* p);
static void Ghost65_Update(struct Entity* p);
static void Ghost65_Die(struct Entity* p);

// clang-format off
const VFXRoutine gGhost65Routine = {
    [ENTITY_INIT] =      (void*)Ghost65_Init,
    [ENTITY_UPDATE] =    (void*)Ghost65_Update,
    [ENTITY_DIE] =       (void*)Ghost65_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void CreateGhost65(s32 x, s32 y, u8 kind1, u8 kind2) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_065);
    p->work[0] = 0, p->work[1] = kind1, p->work[2] = kind2;
    p->coord.x = x, p->coord.y = y;
  }
}

// --------------------------------------------

static const u8 u8_ARRAY_0836f59c[2];

static void Ghost65_Init(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = u8_ARRAY_0836f59c[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  Ghost65_Update((void*)p);
}

static void FUN_080c4320(struct Entity* p);

static void Ghost65_Update(struct Entity* p) {
  static const EntityFunc sUpdates[1] = {
      FUN_080c4320,
  };
  (sUpdates[p->mode[1]])((void*)p);
}

static void Ghost65_Die(struct Entity* p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

// --------------------------------------------

static const motion_t sMotions[6];

/**
 * @note 0x
 */
NAKED static void FUN_080c4320(struct Entity* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r7, r0, #0\n\
	ldrb r0, [r7, #0xe]\n\
	cmp r0, #0\n\
	beq _080C4334\n\
	cmp r0, #1\n\
	beq _080C43BA\n\
	b _080C443C\n\
_080C4334:\n\
	ldr r0, _080C4354 @ =sMotions\n\
	ldrb r1, [r7, #0x11]\n\
	lsls r1, r1, #1\n\
	adds r1, r1, r0\n\
	ldrh r1, [r1]\n\
	adds r0, r7, #0\n\
	bl SetMotion\n\
	ldrb r2, [r7, #0x12]\n\
	cmp r2, #0\n\
	beq _080C4358\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0x10\n\
	orrs r0, r1\n\
	b _080C435E\n\
	.align 2, 0\n\
_080C4354: .4byte sMotions\n\
_080C4358:\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080C435E:\n\
	strb r0, [r7, #0xa]\n\
	movs r1, #1\n\
	ands r1, r2\n\
	adds r0, r7, #0\n\
	adds r0, #0x4c\n\
	movs r2, #0\n\
	mov r8, r2\n\
	strb r1, [r0]\n\
	adds r3, r7, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ldr r6, _080C43F4 @ =0xFFFFFE00\n\
	ldr r5, _080C43F8 @ =RNG_0202f388\n\
	ldr r0, [r5]\n\
	ldr r4, _080C43FC @ =0x000343FD\n\
	muls r0, r4, r0\n\
	ldr r3, _080C4400 @ =0x00269EC3\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #1\n\
	lsrs r2, r0, #1\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #0xff\n\
	ands r0, r1\n\
	subs r0, r6, r0\n\
	str r0, [r7, #0x60]\n\
	adds r0, r2, #0\n\
	muls r0, r4, r0\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r5]\n\
	lsls r0, r0, #5\n\
	lsrs r0, r0, #0x16\n\
	adds r0, r0, r6\n\
	str r0, [r7, #0x5c]\n\
	mov r0, r8\n\
	strb r0, [r7, #0x12]\n\
	ldrb r0, [r7, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r7, #0xe]\n\
_080C43BA:\n\
	adds r0, r7, #0\n\
	bl UpdateEntityAnim\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r7, #0x54]\n\
	ldr r0, [r7, #0x60]\n\
	adds r0, #0x40\n\
	str r0, [r7, #0x60]\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #3\n\
	cmp r0, r1\n\
	ble _080C43D8\n\
	str r1, [r7, #0x60]\n\
_080C43D8:\n\
	ldr r0, [r7, #0x58]\n\
	ldr r1, [r7, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r7, #0x58]\n\
	ldrb r0, [r7, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r7, #0x12]\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080C4404\n\
	ldrb r0, [r7, #0xa]\n\
	orrs r0, r1\n\
	b _080C440A\n\
	.align 2, 0\n\
_080C43F4: .4byte 0xFFFFFE00\n\
_080C43F8: .4byte RNG_0202f388\n\
_080C43FC: .4byte 0x000343FD\n\
_080C4400: .4byte 0x00269EC3\n\
_080C4404:\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
_080C440A:\n\
	strb r0, [r7, #0xa]\n\
	ldr r0, _080C4448 @ =gStageRun+232\n\
	adds r1, r7, #0\n\
	adds r1, #0x54\n\
	bl Camera_GetDistance\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	cmp r0, r1\n\
	bls _080C443C\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r7, #0xa]\n\
	ldr r1, _080C444C @ =gVFXFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r7, #0x14]\n\
_080C443C:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C4448: .4byte gStageRun+232\n\
_080C444C: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

static const u8 u8_ARRAY_0836f59c[2] = {0, 0};

// clang-format off
// 0x0836f59e
static const motion_t sMotions[6] = {
  MOTION(SM116_DEATHLOCK, 9),
  MOTION(SM116_DEATHLOCK, 10),
  MOTION(SM116_DEATHLOCK, 11),
  MOTION(SM116_DEATHLOCK, 12),
  MOTION(SM116_DEATHLOCK, 13),
  MOTION(SM116_DEATHLOCK, 8),
};
// clang-format on
