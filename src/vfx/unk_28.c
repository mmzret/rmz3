#include "entity.h"
#include "global.h"
#include "story.h"
#include "vfx.h"

static void Ghost28_Init(struct VFX *p);
static void Ghost28_Update(struct VFX *p);
static void Ghost28_Die(struct VFX *p);

// clang-format off
const VFXRoutine gGhost28Routine = {
    [ENTITY_INIT] =      Ghost28_Init,
    [ENTITY_UPDATE] =    Ghost28_Update,
    [ENTITY_DIE] =       Ghost28_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX *FUN_080b9e68(struct Coord *c, u8 n) {
  struct VFX *p = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 1;
    INIT_VFX_ROUTINE(p, 28);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = n;
    (p->s).work[1] = 0;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
  }
  return p;
}

struct VFX *FUN_080b9ebc(struct Coord *c, u8 n, u16 r2, s32 y) {
  struct VFX *p = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 1;
    INIT_VFX_ROUTINE(p, 28);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = n;
    (p->s).work[1] = 1;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
    (p->props).unk28.unk_0 = r2;
    (p->props).unk28.unk_4 = y;
  }
  return p;
}

NAKED static void Ghost28_Init(struct VFX *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	movs r3, #0\n\
	adds r2, r0, #0\n\
	orrs r2, r1\n\
	movs r0, #2\n\
	orrs r2, r0\n\
	orrs r2, r3\n\
	strb r2, [r4, #0xa]\n\
	ldrb r1, [r4, #0x10]\n\
	cmp r1, #0\n\
	bne _080B9F60\n\
	movs r0, #0xef\n\
	ands r2, r0\n\
	strb r2, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	b _080B9F80\n\
_080B9F60:\n\
	movs r1, #1\n\
	movs r0, #0x10\n\
	orrs r2, r0\n\
	strb r2, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r4, #0\n\
	adds r3, #0x4a\n\
	movs r2, #0x10\n\
	ldrb r1, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strb r0, [r3]\n\
_080B9F80:\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #0\n\
	bne _080B9F8C\n\
	movs r0, #0xc0\n\
	rsbs r0, r0, #0\n\
	b _080B9F8E\n\
_080B9F8C:\n\
	movs r0, #0xc0\n\
_080B9F8E:\n\
	str r0, [r4, #0x5c]\n\
	movs r3, #0\n\
	str r3, [r4, #0x60]\n\
	ldrb r0, [r4, #0x11]\n\
	cmp r0, #0\n\
	bne _080B9FB8\n\
	movs r0, #0xff\n\
	strb r0, [r4, #0x12]\n\
	ldr r1, _080B9FB4 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	strb r1, [r4, #0xd]\n\
	b _080B9FEA\n\
	.align 2, 0\n\
_080B9FB4: .4byte gVFXFnTable\n\
_080B9FB8:\n\
	ldr r2, _080B9FFC @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080BA000 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080BA004 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #7\n\
	ands r0, r1\n\
	adds r0, #0x7f\n\
	strb r0, [r4, #0x12]\n\
	ldr r1, _080BA008 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	movs r0, #2\n\
	strb r0, [r4, #0xd]\n\
_080B9FEA:\n\
	strb r3, [r4, #0xe]\n\
	strb r3, [r4, #0xf]\n\
	adds r0, r4, #0\n\
	bl Ghost28_Update\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B9FFC: .4byte RNG_0202f388\n\
_080BA000: .4byte 0x000343FD\n\
_080BA004: .4byte 0x00269EC3\n\
_080BA008: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

static void nop_080ba078(struct VFX *p);
void FUN_080ba07c(struct VFX *p);
void FUN_080ba16c(struct VFX *p);

static void Ghost28_Update(struct VFX *p) {
  static const VFXFunc sUpdates[] = {
      nop_080ba078,
      FUN_080ba07c,
      FUN_080ba16c,
  };
  if (IS_METTAUR) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    Ghost28_Die(p);
    return;
  }
  (sUpdates[(p->s).mode[1]])(p);
}

static void Ghost28_Die(struct VFX *p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

static void nop_080ba078(struct VFX *_ UNUSED) { return; }

INCASM("asm/vfx/unk_28.inc");

static const s32 s32_ARRAY_ARRAY_0836eb4c[3][8] = {
    {0x00000120, -0x00000260, -0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0},
    {-0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260},
    {-0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260, -0x000000B0, -0x000001A0},
};

static const s32 *const PTR_ARRAY_0836ebac[3] = {
    s32_ARRAY_ARRAY_0836eb4c[0],
    s32_ARRAY_ARRAY_0836eb4c[1],
    s32_ARRAY_ARRAY_0836eb4c[2],
};
