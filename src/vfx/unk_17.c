#include "entity.h"
#include "global.h"
#include "story.h"
#include "vfx.h"

static void Ghost17_Init(struct VFX* p);
static void Ghost17_Update(struct VFX* p);
static void Ghost17_Die(struct VFX* p);

static const motion_t sMotions[3];

// clang-format off
const VFXRoutine gGhost17Routine = {
    [ENTITY_INIT] =      Ghost17_Init,
    [ENTITY_UPDATE] =    Ghost17_Update,
    [ENTITY_DIE] =       Ghost17_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX* CreateGhost17_1(struct Entity* p) {
  struct VFX* g = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, VFX_UNK_017);
    (g->s).tileNum = 0;
    (g->s).palID = 0;
    (g->s).work[0] = 0;
    (g->s).unk_28 = p;
  }
  return g;
}

void CreateGhost17_2(struct Entity* p, struct Coord* c) {
  s32 i;
  for (i = 0; i < 3; i++) {
    struct VFX* g = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
    if (g != NULL) {
      (g->s).taskCol = 1;
      INIT_VFX_ROUTINE(g, VFX_UNK_017);
      (g->s).tileNum = 0;
      (g->s).palID = 0;
      (g->s).work[0] = 1;
      (g->s).work[1] = i;
      (g->s).unk_28 = p;
      (g->s).coord.x = c->x;
      (g->s).coord.y = c->y;
    }
  }
}

// --------------------------------------------

static void FUN_080b6970(struct VFX* p);
static void FUN_080b6a9c(struct VFX* p);

static void Ghost17_Init(struct VFX* p) {
  static VFXFunc const sInitializers[] = {
      FUN_080b6970,
      FUN_080b6a9c,
  };
  (sInitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

static void FUN_080b6a38(struct VFX* p);
static void FUN_080b6b8c(struct VFX* p);

static void Ghost17_Update(struct VFX* p) {
  static VFXFunc const sUpdates[] = {
      FUN_080b6a38,
      FUN_080b6b8c,
  };
  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[(p->s).work[0]])(p);
}

// --------------------------------------------

static void Ghost17_Die(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

NAKED static void FUN_080b6970(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	ldr r0, [r4, #0x28]\n\
	adds r6, r0, #0\n\
	adds r6, #0x54\n\
	ldrb r0, [r0, #0xa]\n\
	lsrs r5, r0, #4\n\
	movs r0, #1\n\
	ands r5, r0\n\
	adds r0, r4, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	movs r7, #0\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080B69B4 @ =0x00001405\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r2, r5, #0\n\
	cmp r5, #0\n\
	beq _080B69B8\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080B69BE\n\
	.align 2, 0\n\
_080B69B4: .4byte 0x00001405\n\
_080B69B8:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080B69BE:\n\
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
	strb r5, [r4, #0x11]\n\
	cmp r5, #0\n\
	beq _080B69F0\n\
	movs r0, #0x40\n\
	str r0, [r4, #0x5c]\n\
	ldr r0, [r6]\n\
	ldr r1, _080B69EC @ =0xFFFFF800\n\
	b _080B69FC\n\
	.align 2, 0\n\
_080B69EC: .4byte 0xFFFFF800\n\
_080B69F0:\n\
	movs r0, #0x40\n\
	rsbs r0, r0, #0\n\
	str r0, [r4, #0x5c]\n\
	ldr r0, [r6]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #4\n\
_080B69FC:\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r6, #4]\n\
	ldr r1, _080B6A30 @ =0xFFFFE800\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	movs r0, #0\n\
	str r0, [r4, #0x60]\n\
	movs r0, #0x18\n\
	strb r0, [r4, #0x12]\n\
	ldr r1, _080B6A34 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl Ghost17_Update\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B6A30: .4byte 0xFFFFE800\n\
_080B6A34: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

NAKED static void FUN_080b6a38(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	ldr r0, [r5, #0x58]\n\
	ldr r1, [r5, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x58]\n\
	adds r1, #0x10\n\
	str r1, [r5, #0x60]\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r5, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r5, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080B6A90\n\
	ldr r0, [r5, #0x28]\n\
	adds r4, r5, #0\n\
	adds r4, #0x54\n\
	adds r1, r4, #0\n\
	bl CreateGhost17_2\n\
	movs r0, #2\n\
	adds r1, r4, #0\n\
	bl CreateSmoke\n\
	movs r0, #0x2a\n\
	bl PlaySound\n\
	ldr r1, _080B6A98 @ =gVFXFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r5, #0x14]\n\
_080B6A90:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B6A98: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

NAKED static void FUN_080b6a9c(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r7, r0, #0\n\
	ldr r0, [r7, #0x28]\n\
	ldrb r0, [r0, #0xa]\n\
	lsrs r4, r0, #4\n\
	movs r0, #1\n\
	ands r4, r0\n\
	ldrb r5, [r7, #0x11]\n\
	adds r0, r7, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #1\n\
	movs r6, #0\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r7, #0xa]\n\
	ldr r1, _080B6AE4 @ =sMotions\n\
	lsls r0, r5, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r7, #0\n\
	bl SetMotion\n\
	adds r0, r7, #0\n\
	bl UpdateMotionGraphic\n\
	adds r2, r4, #0\n\
	cmp r4, #0\n\
	beq _080B6AE8\n\
	ldrb r0, [r7, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080B6AEE\n\
	.align 2, 0\n\
_080B6AE4: .4byte sMotions\n\
_080B6AE8:\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080B6AEE:\n\
	strb r0, [r7, #0xa]\n\
	movs r0, #1\n\
	mov ip, r0\n\
	mov r1, ip\n\
	ands r1, r2\n\
	adds r0, r7, #0\n\
	adds r0, #0x4c\n\
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
	cmp r4, #0\n\
	beq _080B6B18\n\
	movs r0, #2\n\
	subs r5, r0, r5\n\
_080B6B18:\n\
	subs r1, r5, #1\n\
	lsls r1, r1, #8\n\
	ldr r6, _080B6B70 @ =RNG_0202f388\n\
	ldr r0, [r6]\n\
	ldr r5, _080B6B74 @ =0x000343FD\n\
	muls r0, r5, r0\n\
	ldr r3, _080B6B78 @ =0x00269EC3\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #1\n\
	lsrs r2, r0, #1\n\
	lsrs r0, r0, #0x11\n\
	ldr r4, _080B6B7C @ =0x000001FF\n\
	ands r0, r4\n\
	adds r1, r1, r0\n\
	ldr r0, _080B6B80 @ =0xFFFFFF00\n\
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
	ldr r1, _080B6B84 @ =0xFFFFFE00\n\
	subs r1, r1, r0\n\
	str r1, [r7, #0x60]\n\
	ldr r1, _080B6B88 @ =gVFXFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	mov r1, ip\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r7, #0x14]\n\
	adds r0, r7, #0\n\
	bl Ghost17_Update\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B6B70: .4byte RNG_0202f388\n\
_080B6B74: .4byte 0x000343FD\n\
_080B6B78: .4byte 0x00269EC3\n\
_080B6B7C: .4byte 0x000001FF\n\
_080B6B80: .4byte 0xFFFFFF00\n\
_080B6B84: .4byte 0xFFFFFE00\n\
_080B6B88: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

NAKED static void FUN_080b6b8c(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, [r4, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	adds r1, #0x40\n\
	str r1, [r4, #0x60]\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080B6BD4\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	movs r0, #3\n\
	bl CreateSmoke\n\
	ldr r1, _080B6BDC @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
_080B6BD4:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B6BDC: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

static const motion_t sMotions[3] = {
    MOTION(SM020_PANTHEON_GUARDIAN, 0x08),
    MOTION(SM020_PANTHEON_GUARDIAN, 0x07),
    MOTION(SM020_PANTHEON_GUARDIAN, 0x09),
};
