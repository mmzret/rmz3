#include "global.h"
#include "vfx.h"

// マグマの間欠泉 を凍らせたときのパーティクル?

static void VFX43_Init(struct Entity* p);
static void VFX43_Update(struct Entity* p);
static void VFX43_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX43Routine = {
    [ENTITY_INIT] =      (VFXFunc)VFX43_Init,
    [ENTITY_UPDATE] =    (VFXFunc)VFX43_Update,
    [ENTITY_DIE] =       (VFXFunc)VFX43_Die,
    [ENTITY_DISAPPEAR] = (VFXFunc)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

static const u8 sInitModes[];

void CreateVFX43(s32 x, s32 y) {
  s32 i;
  for (i = 0; i < 4; i++) {
    struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_UNK_043);
      p->work[0] = 0;
      p->work[1] = i;
      p->coord.x = x;
      p->coord.y = y;
    }
  }
}

// --------------------------------------------

static void VFX43_Init(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  VFX43_Update((void*)p);
}

static void FUN_080be72c(struct Entity* p);

static void VFX43_Update(struct Entity* p) {
  static const EntityFunc sUpdates[1] = {
      FUN_080be72c,
  };  // 0x0836efbc
  (sUpdates[p->mode[1]])((void*)p);
}

static void VFX43_Die(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
  return;
}

static const motion_t sMotions[];

NAKED static void FUN_080be72c(struct Entity* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r7, r0, #0\n\
	ldrb r4, [r7, #0x11]\n\
	ldrb r0, [r7, #0xe]\n\
	cmp r0, #0\n\
	beq _080BE73E\n\
	cmp r0, #1\n\
	beq _080BE796\n\
	b _080BE80E\n\
_080BE73E:\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strb r0, [r7, #0xa]\n\
	ldr r1, _080BE7AC @ =0x0836EFC2\n\
	lsls r0, r4, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r7, #0\n\
	bl SetMotion\n\
	subs r1, r4, #1\n\
	lsls r1, r1, #8\n\
	ldr r6, _080BE7B0 @ =RNG_0202f388\n\
	ldr r0, [r6]\n\
	ldr r5, _080BE7B4 @ =0x000343FD\n\
	muls r0, r5, r0\n\
	ldr r3, _080BE7B8 @ =0x00269EC3\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #1\n\
	lsrs r2, r0, #1\n\
	lsrs r0, r0, #0x11\n\
	ldr r4, _080BE7BC @ =0x000001FF\n\
	ands r0, r4\n\
	adds r1, r1, r0\n\
	ldr r0, _080BE7C0 @ =0xFFFFFF00\n\
	adds r1, r1, r0\n\
	str r1, [r7, #0x5c]\n\
	adds r0, r2, #0\n\
	muls r0, r5, r0\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r6]\n\
	lsrs r0, r0, #0x11\n\
	ands r0, r4\n\
	ldr r1, _080BE7C4 @ =0xFFFFFE00\n\
	subs r1, r1, r0\n\
	str r1, [r7, #0x60]\n\
	movs r0, #0x20\n\
	strb r0, [r7, #0x12]\n\
	ldrb r0, [r7, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r7, #0xe]\n\
_080BE796:\n\
	ldrb r0, [r7, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r7, #0x12]\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080BE7C8\n\
	ldrb r0, [r7, #0xa]\n\
	orrs r0, r1\n\
	b _080BE7CE\n\
	.align 2, 0\n\
_080BE7AC: .4byte sMotions\n\
_080BE7B0: .4byte RNG_0202f388\n\
_080BE7B4: .4byte 0x000343FD\n\
_080BE7B8: .4byte 0x00269EC3\n\
_080BE7BC: .4byte 0x000001FF\n\
_080BE7C0: .4byte 0xFFFFFF00\n\
_080BE7C4: .4byte 0xFFFFFE00\n\
_080BE7C8:\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
_080BE7CE:\n\
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
	ldrb r0, [r7, #0x12]\n\
	cmp r0, #0\n\
	bne _080BE80E\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r7, #0xa]\n\
	ldr r1, _080BE814 @ =gVFXFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r7, #0x14]\n\
_080BE80E:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080BE814: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

static const u8 sInitModes[2] = {0, 0};

static const motion_t sMotions[4] = {
    MOTION(SM057_GEYSER, 4),
    MOTION(SM057_GEYSER, 5),
    MOTION(SM057_GEYSER, 6),
    MOTION(SM057_GEYSER, 6),
};
