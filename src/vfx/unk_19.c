#include "entity.h"
#include "vfx.h"
#include "global.h"

static const u8 u8_ARRAY_0836e8a8[2];

static void Ghost19_Init(struct VFX *p);
static void Ghost19_Update(struct VFX *p);
static void Ghost19_Die(struct VFX *p);

// clang-format off
const VFXRoutine gGhost19Routine = {
    [ENTITY_INIT] =      Ghost19_Init,
    [ENTITY_UPDATE] =    Ghost19_Update,
    [ENTITY_DIE] =       Ghost19_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

struct VFX *CreateGhost19_1(struct Coord *c, struct Coord *d) {
  s32 x, y, dx, dy;
  struct VFX *g = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, VFX_UNK_019);
    (g->s).tileNum = 0;
    (g->s).palID = 0;

    x = c->x;
    y = c->y;
    (g->s).coord.x = x;
    (g->s).coord.y = y;

    dx = d->x;
    dy = d->y;
    (g->s).d.x = dx;
    (g->s).d.y = dy;

    (g->s).work[0] = 0;
  }
  return g;
}

void CreateGhost19_2(struct Entity *p, struct Coord *c) {
  s32 i;
  for (i = 0; i < 4; i++) {
    struct VFX *g = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
    if (g != NULL) {
      (g->s).taskCol = 1;
      INIT_VFX_ROUTINE(g, VFX_UNK_019);
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

static void Ghost19_Init(struct VFX *p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = u8_ARRAY_0836e8a8[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  if ((p->s).work[0] == 1) {
    ResetDynamicMotion(&p->s);
  }
  Ghost19_Update(p);
}

// --------------------------------------------

static void FUN_080b6fc8(struct VFX *p);
static void FUN_080b705c(struct VFX *p);

static void Ghost19_Update(struct VFX *p) {
  static VFXFunc const sUpdates[] = {
      FUN_080b6fc8,
      FUN_080b705c,
  };
  (sUpdates[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void Ghost19_Die(struct VFX *p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

// --------------------------------------------

NAKED static void FUN_080b6fc8(struct VFX *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	ldrb r0, [r5, #0xe]\n\
	cmp r0, #0\n\
	beq _080B6FD8\n\
	cmp r0, #1\n\
	beq _080B7006\n\
	b _080B7042\n\
_080B6FD8:\n\
	ldr r4, _080B7048 @ =0x0836E8AA\n\
	ldr r2, _080B704C @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080B7050 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080B7054 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #3\n\
	bl __umodsi3\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r4\n\
	ldrh r1, [r0]\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	ldrb r0, [r5, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xe]\n\
_080B7006:\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, [r5, #0x5c]\n\
	adds r2, r1, r0\n\
	str r2, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	ldr r0, [r5, #0x60]\n\
	adds r1, r1, r0\n\
	str r1, [r5, #0x58]\n\
	adds r0, #0x40\n\
	str r0, [r5, #0x60]\n\
	cmp r0, #0\n\
	ble _080B703C\n\
	adds r0, r2, #0\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080B703C\n\
	ldr r1, _080B7058 @ =gVFXFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r5, #0x14]\n\
_080B703C:\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
_080B7042:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B7048: .4byte motion_t_ARRAY_0836e8aa\n\
_080B704C: .4byte RNG_0202f388\n\
_080B7050: .4byte 0x000343FD\n\
_080B7054: .4byte 0x00269EC3\n\
_080B7058: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

NAKED static void FUN_080b705c(struct VFX *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r7, r0, #0\n\
	ldr r0, [r7, #0x28]\n\
	ldrb r0, [r0, #0xa]\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x1c\n\
	movs r1, #1\n\
	ands r5, r1\n\
	lsrs r4, r0, #0x1d\n\
	ands r4, r1\n\
	ldrb r6, [r7, #0x11]\n\
	ldrb r0, [r7, #0xe]\n\
	cmp r0, #0\n\
	beq _080B707E\n\
	cmp r0, #1\n\
	beq _080B713A\n\
	b _080B71BE\n\
_080B707E:\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #1\n\
	movs r3, #0\n\
	adds r2, r0, #0\n\
	orrs r2, r1\n\
	strb r2, [r7, #0xa]\n\
	adds r1, r5, #0\n\
	cmp r5, #0\n\
	beq _080B7096\n\
	movs r0, #0x10\n\
	orrs r2, r0\n\
	b _080B709A\n\
_080B7096:\n\
	movs r0, #0xef\n\
	ands r2, r0\n\
_080B709A:\n\
	strb r2, [r7, #0xa]\n\
	adds r0, r7, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r2, r7, #0\n\
	adds r2, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r3, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r3, r4, #0\n\
	adds r4, r2, #0\n\
	cmp r3, #0\n\
	beq _080B70C4\n\
	ldrb r0, [r7, #0xa]\n\
	movs r1, #0x20\n\
	orrs r0, r1\n\
	b _080B70CA\n\
_080B70C4:\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xdf\n\
	ands r0, r1\n\
_080B70CA:\n\
	strb r0, [r7, #0xa]\n\
	adds r1, r3, #0\n\
	adds r2, r7, #0\n\
	adds r2, #0x4d\n\
	strb r1, [r2]\n\
	lsls r1, r1, #5\n\
	ldrb r2, [r4]\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r4]\n\
	ldr r1, _080B7150 @ =0x0836E8B0\n\
	lsls r0, r6, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r7, #0\n\
	bl SetMotion\n\
	cmp r5, #0\n\
	beq _080B70F8\n\
	movs r0, #2\n\
	subs r6, r0, r6\n\
_080B70F8:\n\
	subs r1, r6, #1\n\
	lsls r1, r1, #8\n\
	ldr r6, _080B7154 @ =RNG_0202f388\n\
	ldr r0, [r6]\n\
	ldr r5, _080B7158 @ =0x000343FD\n\
	muls r0, r5, r0\n\
	ldr r3, _080B715C @ =0x00269EC3\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #1\n\
	lsrs r2, r0, #1\n\
	lsrs r0, r0, #0x11\n\
	ldr r4, _080B7160 @ =0x000001FF\n\
	ands r0, r4\n\
	adds r1, r1, r0\n\
	ldr r0, _080B7164 @ =0xFFFFFF00\n\
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
	ldr r1, _080B7168 @ =0xFFFFFD00\n\
	subs r1, r1, r0\n\
	str r1, [r7, #0x60]\n\
	movs r0, #0\n\
	strb r0, [r7, #0x12]\n\
	ldrb r0, [r7, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r7, #0xe]\n\
_080B713A:\n\
	ldrb r0, [r7, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r7, #0x12]\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080B716C\n\
	ldrb r0, [r7, #0xa]\n\
	orrs r0, r1\n\
	b _080B7172\n\
	.align 2, 0\n\
_080B7150: .4byte motion_t_ARRAY_0836e8b0\n\
_080B7154: .4byte RNG_0202f388\n\
_080B7158: .4byte 0x000343FD\n\
_080B715C: .4byte 0x00269EC3\n\
_080B7160: .4byte 0x000001FF\n\
_080B7164: .4byte 0xFFFFFF00\n\
_080B7168: .4byte 0xFFFFFD00\n\
_080B716C:\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
_080B7172:\n\
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
	beq _080B71BE\n\
	ldr r0, [r7, #0x60]\n\
	cmp r0, #0\n\
	ble _080B71BE\n\
	adds r1, r7, #0\n\
	adds r1, #0x54\n\
	movs r0, #3\n\
	bl CreateSmoke\n\
	ldr r1, _080B71C4 @ =gVFXFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r7, #0x14]\n\
_080B71BE:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B71C4: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

// ------------------------------------------------------------------------------------------------------------------------------------

static const u8 u8_ARRAY_0836e8a8[2] = {0, 1};

static const motion_t motion_t_ARRAY_0836e8aa[3] = {
    MOTION(SM005_GRAVEL, 0),
    MOTION(SM005_GRAVEL, 1),
    MOTION(SM005_GRAVEL, 2),
};

static const motion_t motion_t_ARRAY_0836e8b0[4] = {
    MOTION(0xA0, 0x11),
    MOTION(0xA0, 0x12),
    MOTION(0xA0, 0x13),
    MOTION(0xA0, 0x14),
};
