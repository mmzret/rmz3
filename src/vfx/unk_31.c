#include "global.h"
#include "vfx.h"

static const u8 sInitModes[2];
static const motion_t sMotions[4];

static void Ghost31_Init(struct VFX *p);
static void Ghost31_Update(struct VFX *p);
static void Ghost31_Die(struct VFX *p);

// clang-format off
const VFXRoutine gGhost31Routine = {
    [ENTITY_INIT] =      Ghost31_Init,
    [ENTITY_MAIN] =      Ghost31_Update,
    [ENTITY_DIE] =       Ghost31_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void FUN_080ba538(s32 x, s32 y) {
  struct VFX *p = (struct VFX *)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 1;
    INIT_VFX_ROUTINE(p, 31);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = 0;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
  }
}

void FUN_080ba580(s32 x, s32 y) {
  s32 i;
  for (i = 0; i < 4; i++) {
    struct VFX *p = (struct VFX *)AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      (p->s).taskCol = 1;
      INIT_VFX_ROUTINE(p, 31);
      (p->s).tileNum = 0;
      (p->s).palID = 0;
      (p->s).work[0] = 1;
      (p->s).work[1] = i;
      (p->s).coord.x = x;
      (p->s).coord.y = y;
    }
  }
}

// --------------------------------------------

static void Ghost31_Init(struct VFX *p) {
  SET_VFX_ROUTINE(p, ENTITY_MAIN);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  Ghost31_Update(p);
}

// --------------------------------------------

static void FUN_080ba658(struct VFX *p);
static void FUN_080ba6a4(struct VFX *p);

static void Ghost31_Update(struct VFX *p) {
  static const VFXFunc sUpdates[2] = {
      FUN_080ba658,
      FUN_080ba6a4,
  };
  (sUpdates[(p->s).mode[1]])(p);
}

static void Ghost31_Die(struct VFX *p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

static void FUN_080ba658(struct VFX *p) {
  switch ((p->s).mode[2]) {
    case 0: {
      SetMotion(&p->s, MOTION(SM038_UNK, 0x00));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if ((p->s).motion.state == MOTION_END) {
        SET_VFX_ROUTINE(p, ENTITY_DIE);
      }
      UpdateMotionGraphic(&p->s);
      break;
    }
  }
}

NAKED static void FUN_080ba6a4(struct VFX *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r7, r0, #0\n\
	ldrb r6, [r7, #0xe]\n\
	cmp r6, #0\n\
	beq _080BA6B4\n\
	cmp r6, #1\n\
	beq _080BA742\n\
	b _080BA7BC\n\
_080BA6B4:\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	movs r1, #0xef\n\
	ands r0, r1\n\
	strb r0, [r7, #0xa]\n\
	adds r0, r7, #0\n\
	adds r0, #0x4c\n\
	strb r6, [r0]\n\
	adds r2, r7, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xdf\n\
	ands r0, r1\n\
	strb r0, [r7, #0xa]\n\
	adds r0, r7, #0\n\
	adds r0, #0x4d\n\
	strb r6, [r0]\n\
	ldrb r1, [r2]\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldr r1, _080BA758 @ =sMotions\n\
	ldrb r0, [r7, #0x11]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r7, #0\n\
	bl SetMotion\n\
	ldrb r1, [r7, #0x11]\n\
	subs r1, #1\n\
	lsls r1, r1, #8\n\
	ldr r0, _080BA75C @ =RNG_0202f388\n\
	mov ip, r0\n\
	ldr r0, [r0]\n\
	ldr r5, _080BA760 @ =0x000343FD\n\
	muls r0, r5, r0\n\
	ldr r3, _080BA764 @ =0x00269EC3\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #1\n\
	lsrs r2, r0, #1\n\
	lsrs r0, r0, #0x11\n\
	ldr r4, _080BA768 @ =0x000001FF\n\
	ands r0, r4\n\
	adds r1, r1, r0\n\
	ldr r0, _080BA76C @ =0xFFFFFF00\n\
	adds r1, r1, r0\n\
	str r1, [r7, #0x5c]\n\
	adds r0, r2, #0\n\
	muls r0, r5, r0\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	mov r2, ip\n\
	str r1, [r2]\n\
	lsrs r0, r0, #0x11\n\
	ands r0, r4\n\
	ldr r1, _080BA770 @ =0xFFFFFE00\n\
	subs r1, r1, r0\n\
	str r1, [r7, #0x60]\n\
	strb r6, [r7, #0x12]\n\
	ldrb r0, [r7, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r7, #0xe]\n\
_080BA742:\n\
	ldrb r0, [r7, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r7, #0x12]\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080BA774\n\
	ldrb r0, [r7, #0xa]\n\
	orrs r0, r1\n\
	b _080BA77A\n\
	.align 2, 0\n\
_080BA758: .4byte sMotions\n\
_080BA75C: .4byte RNG_0202f388\n\
_080BA760: .4byte 0x000343FD\n\
_080BA764: .4byte 0x00269EC3\n\
_080BA768: .4byte 0x000001FF\n\
_080BA76C: .4byte 0xFFFFFF00\n\
_080BA770: .4byte 0xFFFFFE00\n\
_080BA774:\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
_080BA77A:\n\
	strb r0, [r7, #0xa]\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r7, #0x54]\n\
	ldr r0, [r7, #0x58]\n\
	ldr r1, [r7, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r7, #0x58]\n\
	adds r1, #0x40\n\
	str r1, [r7, #0x60]\n\
	adds r0, r7, #0\n\
	bl FUN_0801779c\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080BA7BC\n\
	ldr r0, [r7, #0x60]\n\
	cmp r0, #0\n\
	ble _080BA7BC\n\
	ldr r1, _080BA7C4 @ =gVFXFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r7, #0x14]\n\
_080BA7BC:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080BA7C4: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

static const u8 sInitModes[2] = {0, 1};

static const motion_t sMotions[4] = {
    MOTION(SM037_EAR_SHOT, 3),
    MOTION(SM037_EAR_SHOT, 4),
    MOTION(SM037_EAR_SHOT, 5),
    MOTION(SM037_EAR_SHOT, 5),
};
