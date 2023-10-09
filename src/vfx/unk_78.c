#include "entity.h"
#include "global.h"
#include "vfx.h"

/*
  シエルのミニゲームに関係
*/

static void Ghost78_Init(struct VFX *p);
static void Ghost78_Update(struct VFX *p);
static void Ghost78_Die(struct VFX *p);

// clang-format off
const VFXRoutine gGhost78Routine = {
    [ENTITY_INIT] =      Ghost78_Init,
    [ENTITY_UPDATE] =    Ghost78_Update,
    [ENTITY_DIE] =       Ghost78_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void CreateGhost78_1(struct Entity *p, struct Coord *c, u8 r2, u8 r3) {
  struct VFX *g = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, VFX_UNK_078);
    (g->s).tileNum = 0;
    (g->s).palID = 0;
    (g->s).unk_28 = p;
    (g->s).coord = *c;
    (g->s).work[0] = r2;
    (g->s).work[1] = r3;
  }
}

void CreateGhost78_2(struct Coord *c, u8 r1, u8 r2, u8 r3) {
  struct VFX *g = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, VFX_UNK_078);
    (g->s).tileNum = 0;
    (g->s).palID = 0;
    (g->s).coord = *c;
    (g->s).work[0] = r1;
    (g->s).work[1] = r2;
    *((u8 *)&g->props.tmp.unk_7c + 1) = r3;
  }
}

// --------------------------------------------

static void FUN_080c8938(struct VFX *p);
static void FUN_080c89c8(struct VFX *p);
static void FUN_080c8acc(struct VFX *p);

static void Ghost78_Init(struct VFX *p) {
  static VFXFunc const sInitializers[] = {
      FUN_080c8938,
      FUN_080c89c8,
      FUN_080c8acc,
  };
  (sInitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

static void FUN_080c8c00(struct VFX *p);
static void FUN_080c8ccc(struct VFX *p);
static void FUN_080c8d30(struct VFX *p);

static void Ghost78_Update(struct VFX *p) {
  static VFXFunc const sUpdates[] = {
      FUN_080c8c00,
      FUN_080c8ccc,
      FUN_080c8d30,
  };
  (sUpdates[(p->s).work[0]])(p);
}

// --------------------------------------------

static void FUN_080c8da0(struct VFX *p);
static void FUN_080c8db8(struct VFX *p);
static void FUN_080c8dd0(struct VFX *p);

static void Ghost78_Die(struct VFX *p) {
  static VFXFunc const sDeinitializers[] = {
      FUN_080c8da0,
      FUN_080c8db8,
      FUN_080c8dd0,
  };
  (sDeinitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

NAKED static void FUN_080c8938(struct VFX *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldr r1, _080C89C0 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080C89C4 @ =0x0000EA03\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r5, #0\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r5, [r0]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #0x3c\n\
	strb r0, [r4, #0x12]\n\
	ldr r1, [r4, #0x54]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #5\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x54]\n\
	ldr r0, [r4, #0x58]\n\
	movs r2, #0xe8\n\
	lsls r2, r2, #5\n\
	adds r0, r0, r2\n\
	str r0, [r4, #0x58]\n\
	movs r0, #0xd0\n\
	lsls r0, r0, #8\n\
	subs r0, r0, r1\n\
	movs r1, #0x3c\n\
	bl __divsi3\n\
	str r0, [r4, #0x5c]\n\
	str r5, [r4, #0x60]\n\
	movs r0, #4\n\
	rsbs r0, r0, #0\n\
	str r0, [r4, #0x68]\n\
	adds r0, r4, #0\n\
	bl Ghost78_Update\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C89C0: .4byte gVFXFnTable\n\
_080C89C4: .4byte 0x0000EA03\n\
 .syntax divided\n");
}

NAKED static void FUN_080c89c8(struct VFX *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	ldr r1, _080C8A1C @ =gVFXFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	adds r0, r5, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r0, [r5, #0xa]\n\
	movs r4, #1\n\
	movs r6, #0\n\
	orrs r0, r4\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _080C8A20 @ =0x0000E90B\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	ldr r2, _080C8A24 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080C8A28 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080C8A2C @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r2, r0, #0x11\n\
	ands r2, r4\n\
	cmp r2, #0\n\
	beq _080C8A30\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080C8A36\n\
	.align 2, 0\n\
_080C8A1C: .4byte gVFXFnTable\n\
_080C8A20: .4byte 0x0000E90B\n\
_080C8A24: .4byte RNG_0202f388\n\
_080C8A28: .4byte 0x000343FD\n\
_080C8A2C: .4byte 0x00269EC3\n\
_080C8A30:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080C8A36:\n\
	strb r0, [r5, #0xa]\n\
	movs r4, #1\n\
	adds r1, r2, #0\n\
	adds r0, r5, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r5, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ldr r2, _080C8A78 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080C8A7C @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080C8A80 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r2, r0, #0x11\n\
	ands r2, r4\n\
	cmp r2, #0\n\
	beq _080C8A84\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x20\n\
	orrs r0, r1\n\
	b _080C8A8A\n\
	.align 2, 0\n\
_080C8A78: .4byte RNG_0202f388\n\
_080C8A7C: .4byte 0x000343FD\n\
_080C8A80: .4byte 0x00269EC3\n\
_080C8A84:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xdf\n\
	ands r0, r1\n\
_080C8A8A:\n\
	strb r0, [r5, #0xa]\n\
	adds r1, r2, #0\n\
	adds r2, r5, #0\n\
	adds r2, #0x4d\n\
	movs r4, #0\n\
	strb r1, [r2]\n\
	lsls r1, r1, #5\n\
	ldrb r2, [r3]\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	adds r0, r5, #0\n\
	adds r0, #0x7d\n\
	ldrb r1, [r0]\n\
	adds r1, #5\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	adds r0, r5, #0\n\
	bl ForceEntityPalette\n\
	movs r0, #0x20\n\
	strb r0, [r5, #0x12]\n\
	str r4, [r5, #0x5c]\n\
	movs r0, #0x70\n\
	str r0, [r5, #0x60]\n\
	adds r0, r5, #0\n\
	bl Ghost78_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED static void FUN_080c8acc(struct VFX *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	ldr r1, _080C8B20 @ =gVFXFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	adds r0, r5, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r0, [r5, #0xa]\n\
	movs r4, #1\n\
	movs r6, #0\n\
	orrs r0, r4\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _080C8B24 @ =0x0000E90B\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	ldr r2, _080C8B28 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080C8B2C @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080C8B30 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r2, r0, #0x11\n\
	ands r2, r4\n\
	cmp r2, #0\n\
	beq _080C8B34\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080C8B3A\n\
	.align 2, 0\n\
_080C8B20: .4byte gVFXFnTable\n\
_080C8B24: .4byte 0x0000E90B\n\
_080C8B28: .4byte RNG_0202f388\n\
_080C8B2C: .4byte 0x000343FD\n\
_080C8B30: .4byte 0x00269EC3\n\
_080C8B34:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080C8B3A:\n\
	strb r0, [r5, #0xa]\n\
	movs r4, #1\n\
	adds r1, r2, #0\n\
	adds r0, r5, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r5, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ldr r2, _080C8B7C @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080C8B80 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080C8B84 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r2, r0, #0x11\n\
	ands r2, r4\n\
	cmp r2, #0\n\
	beq _080C8B88\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x20\n\
	orrs r0, r1\n\
	b _080C8B8E\n\
	.align 2, 0\n\
_080C8B7C: .4byte RNG_0202f388\n\
_080C8B80: .4byte 0x000343FD\n\
_080C8B84: .4byte 0x00269EC3\n\
_080C8B88:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xdf\n\
	ands r0, r1\n\
_080C8B8E:\n\
	strb r0, [r5, #0xa]\n\
	adds r1, r2, #0\n\
	adds r2, r5, #0\n\
	adds r2, #0x4d\n\
	strb r1, [r2]\n\
	lsls r1, r1, #5\n\
	ldrb r2, [r3]\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	adds r0, r5, #0\n\
	adds r0, #0x7d\n\
	ldrb r1, [r0]\n\
	adds r1, #5\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	adds r0, r5, #0\n\
	bl ForceEntityPalette\n\
	movs r0, #0x20\n\
	strb r0, [r5, #0x12]\n\
	ldrb r0, [r5, #0x11]\n\
	lsls r0, r0, #8\n\
	movs r1, #5\n\
	bl __divsi3\n\
	adds r1, r0, #0\n\
	subs r1, #0x40\n\
	strb r1, [r5, #0x13]\n\
	ldr r1, _080C8BFC @ =gSineTable\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r1\n\
	movs r2, #0\n\
	ldrsh r0, [r0, r2]\n\
	asrs r0, r0, #1\n\
	str r0, [r5, #0x5c]\n\
	ldrb r0, [r5, #0x13]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	asrs r0, r0, #1\n\
	str r0, [r5, #0x60]\n\
	movs r0, #4\n\
	str r0, [r5, #0x64]\n\
	str r0, [r5, #0x68]\n\
	adds r0, r5, #0\n\
	bl Ghost78_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C8BFC: .4byte gSineTable\n\
 .syntax divided\n");
}

// --------------------------------------------

NAKED static void FUN_080c8c00(struct VFX *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	ldr r4, [r5, #0x28]\n\
	bl UpdateMotionGraphic\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	ldr r0, [r5, #0x58]\n\
	ldr r1, [r5, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x58]\n\
	ldr r0, [r5, #0x68]\n\
	adds r1, r1, r0\n\
	str r1, [r5, #0x60]\n\
	ldrb r0, [r5, #0x12]\n\
	movs r1, #0xa\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080C8C3C\n\
	adds r0, r5, #0\n\
	adds r0, #0x54\n\
	ldrb r3, [r5, #0x11]\n\
	movs r1, #1\n\
	movs r2, #0\n\
	bl CreateGhost78_2\n\
_080C8C3C:\n\
	ldrb r0, [r5, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r5, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080C8CBA\n\
	ldr r0, _080C8CC0 @ =0x00000DCC\n\
	adds r1, r4, r0\n\
	ldrb r0, [r1, #4]\n\
	cmp r0, #3\n\
	bhi _080C8C62\n\
	ldr r0, [r1, #8]\n\
	adds r0, #0x64\n\
	str r0, [r1, #8]\n\
	ldr r2, _080C8CC4 @ =0x0001869F\n\
	cmp r0, r2\n\
	bls _080C8C62\n\
	str r2, [r1, #8]\n\
_080C8C62:\n\
	adds r4, r5, #0\n\
	adds r4, #0x54\n\
	ldrb r3, [r5, #0x11]\n\
	adds r0, r4, #0\n\
	movs r1, #2\n\
	movs r2, #0\n\
	bl CreateGhost78_2\n\
	ldrb r3, [r5, #0x11]\n\
	adds r0, r4, #0\n\
	movs r1, #2\n\
	movs r2, #1\n\
	bl CreateGhost78_2\n\
	ldrb r3, [r5, #0x11]\n\
	adds r0, r4, #0\n\
	movs r1, #2\n\
	movs r2, #2\n\
	bl CreateGhost78_2\n\
	ldrb r3, [r5, #0x11]\n\
	adds r0, r4, #0\n\
	movs r1, #2\n\
	movs r2, #3\n\
	bl CreateGhost78_2\n\
	ldrb r3, [r5, #0x11]\n\
	adds r0, r4, #0\n\
	movs r1, #2\n\
	movs r2, #4\n\
	bl CreateGhost78_2\n\
	ldr r1, _080C8CC8 @ =gVFXFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r5, #0x14]\n\
	adds r0, r5, #0\n\
	bl Ghost78_Die\n\
_080C8CBA:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C8CC0: .4byte 0x00000DCC\n\
_080C8CC4: .4byte 0x0001869F\n\
_080C8CC8: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

static void FUN_080c8ccc(struct VFX *p) {
  UpdateMotionGraphic(&p->s);
  (p->s).coord.x += (p->s).d.x;
  (p->s).coord.y += (p->s).d.y;
  if ((p->s).work[2] & 1) {
    (p->s).flags |= DISPLAY;
  } else {
    (p->s).flags &= ~DISPLAY;
  }
  (p->s).work[2]--;
  if ((p->s).work[2] == 0xFF) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    Ghost78_Die(p);
  }
}

static void FUN_080c8d30(struct VFX *p) {
  UpdateMotionGraphic(&p->s);
  (p->s).coord.x += (p->s).d.x;
  (p->s).coord.y += (p->s).d.y;
  (p->s).d.x += (p->s).unk_coord.x;
  (p->s).d.y += (p->s).unk_coord.y;
  if ((p->s).work[2] & 1) {
    (p->s).flags |= DISPLAY;
  } else {
    (p->s).flags &= ~DISPLAY;
  }
  (p->s).work[2]--;
  if ((p->s).work[2] == 0xFF) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    Ghost78_Die(p);
  }
}

// --------------------------------------------

static void FUN_080c8da0(struct VFX *p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

static void FUN_080c8db8(struct VFX *p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

static void FUN_080c8dd0(struct VFX *p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }
