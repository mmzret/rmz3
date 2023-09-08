#include "entity.h"
#include "global.h"
#include "task.h"
#include "vfx.h"

static void Ghost84_Init(struct VFX *p);
static void Ghost84_Update(struct VFX *p);
static void Ghost84_Die(struct VFX *p);

// clang-format off
const VFXRoutine gGhost84Routine = {
    [ENTITY_INIT] =      Ghost84_Init,
    [ENTITY_MAIN] =      Ghost84_Update,
    [ENTITY_DIE] =       Ghost84_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct VFX *CreateGhost84(struct Entity *p) {
  struct VFX *g = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, VFX_UNK_084);
    (g->s).tileNum = 0;
    (g->s).palID = 0;
    (g->s).work[0] = 0;
    (g->s).work[1] = 0;
    (g->s).unk_28 = p;
  }
  return g;
}

// --------------------------------------------

static void FUN_080c9d20(struct Sprite *p, struct DrawPivot *_);

static void Ghost84_Init(struct VFX *p) {
  SetTaskCallback((struct Task *)&(p->s).spr, FUN_080c9d20);
  (p->s).spr.sprites = (struct MetaspriteHeader *)p;
  (p->s).flags &= 0xF7;
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SET_VFX_ROUTINE(p, ENTITY_MAIN);
  (p->s).mode[1] = 0;
  (p->s).mode[2] = 0;
  (p->s).mode[3] = 0;
  Ghost84_Update(p);
}

NAKED static void Ghost84_Update(struct VFX *p) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r0, [r2, #0x28]\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #1\n\
	bhi _080C9CB8\n\
	cmp r0, #4\n\
	beq _080C9CB8\n\
	ldr r0, [r2, #0x2c]\n\
	ldrb r1, [r0, #0xc]\n\
	cmp r1, #1\n\
	bhi _080C9CB8\n\
	ldrb r0, [r0, #0xe]\n\
	cmp r0, #9\n\
	bhi _080C9CB8\n\
	cmp r1, #4\n\
	beq _080C9CB8\n\
	ldr r0, _080C9CD8 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldrb r1, [r0, #0xa]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080C9CE0\n\
_080C9CB8:\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
	ldr r1, _080C9CDC @ =gVFXFnTable\n\
	ldrb r0, [r2, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r2, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r2, #0x14]\n\
	b _080C9CF0\n\
	.align 2, 0\n\
_080C9CD8: .4byte pZero2\n\
_080C9CDC: .4byte gVFXFnTable\n\
_080C9CE0:\n\
	ldr r0, _080C9CF4 @ =0x0836FB1C\n\
	ldrb r1, [r2, #0xd]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r1, [r1]\n\
	adds r0, r2, #0\n\
	bl _call_via_r1\n\
_080C9CF0:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C9CF4: .4byte sUpdates\n\
 .syntax divided\n");
}

static void Ghost84_Die(struct VFX *p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080c9d18(struct VFX *p);
static void nop_080c9d1c(struct VFX *p);

static const VFXFunc sUpdates[2] = {
    nop_080c9d18,
    nop_080c9d1c,
};

// --------------------------------------------

static void nop_080c9d18(struct VFX *p) { return; }

static void nop_080c9d1c(struct VFX *p) { return; }

NAKED static void FUN_080c9d20(struct Sprite *p, struct DrawPivot *_) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	ldr r5, [r0, #8]\n\
	movs r4, #0xa0\n\
	lsls r4, r4, #1\n\
	adds r0, r4, #0\n\
	bl Malloc\n\
	adds r7, r0, #0\n\
	cmp r7, #0\n\
	beq _080C9DB8\n\
	movs r0, #0\n\
	adds r1, r7, #0\n\
	adds r2, r4, #0\n\
	bl FillMemory\n\
	ldr r1, _080C9DC8 @ =gPaletteManager\n\
	ldr r2, _080C9DCC @ =0x0000FFFF\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, [r5, #0x78]\n\
	adds r3, r0, #1\n\
	movs r6, #0x80\n\
	adds r6, r6, r5\n\
	mov sl, r6\n\
	ldr r0, [r6]\n\
	cmp r3, r0\n\
	bge _080C9D9C\n\
	ldr r0, [r5, #0x5c]\n\
	mov r8, r0\n\
	ldr r1, [r5, #0x64]\n\
	mov ip, r1\n\
	lsls r0, r3, #1\n\
	adds r4, r0, r7\n\
	movs r2, #0xff\n\
	mov sb, r2\n\
_080C9D6E:\n\
	ldr r0, [r5, #0x78]\n\
	subs r0, r3, r0\n\
	mov r2, r8\n\
	muls r2, r0, r2\n\
	asrs r2, r2, #8\n\
	ldr r1, [r5, #0x74]\n\
	subs r2, r1, r2\n\
	mov r6, ip\n\
	muls r6, r0, r6\n\
	adds r0, r6, #0\n\
	asrs r0, r0, #8\n\
	subs r1, r1, r0\n\
	mov r0, sb\n\
	ands r1, r0\n\
	lsls r2, r2, #8\n\
	orrs r1, r2\n\
	strh r1, [r4]\n\
	adds r4, #2\n\
	adds r3, #1\n\
	mov r1, sl\n\
	ldr r0, [r1]\n\
	cmp r3, r0\n\
	blt _080C9D6E\n\
_080C9D9C:\n\
	ldr r2, _080C9DD0 @ =gIntrManager\n\
	movs r6, #0xba\n\
	lsls r6, r6, #1\n\
	adds r0, r2, r6\n\
	str r7, [r0]\n\
	movs r0, #0xbc\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	ldr r0, _080C9DD4 @ =0x04000042\n\
	str r0, [r1]\n\
	adds r6, #8\n\
	adds r1, r2, r6\n\
	ldr r0, _080C9DD8 @ =0xA2600001\n\
	str r0, [r1]\n\
_080C9DB8:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C9DC8: .4byte gPaletteManager\n\
_080C9DCC: .4byte 0x0000FFFF\n\
_080C9DD0: .4byte gIntrManager\n\
_080C9DD4: .4byte 0x04000042\n\
_080C9DD8: .4byte 0xA2600001\n\
 .syntax divided\n");
}
