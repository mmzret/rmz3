#include "entity.h"
#include "global.h"
#include "task.h"
#include "vfx.h"

static void Ghost83_Init(struct VFX *p);
static void Ghost83_Update(struct VFX *p);
static void Ghost83_Die(struct VFX *p);

// clang-format off
const VFXRoutine gGhost83Routine = {
    [ENTITY_INIT] =      Ghost83_Init,
    [ENTITY_UPDATE] =    Ghost83_Update,
    [ENTITY_DIE] =       Ghost83_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct VFX *CreateGhost83(struct Entity *p) {
  struct VFX *g = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, VFX_UNK_083);
    (g->s).tileNum = 0;
    (g->s).palID = 0;
    (g->s).work[0] = 0;
    (g->s).work[1] = 0;
    (g->s).unk_28 = p;
  }
  return g;
}

// --------------------------------------------

static void FUN_080c9b4c(struct Sprite *p, struct DrawPivot *_);

static void Ghost83_Init(struct VFX *p) {
  SetTaskCallback((struct Task *)&(p->s).spr, FUN_080c9b4c);
  (p->s).spr.sprites = (struct MetaspriteHeader *)p;
  (p->s).flags &= 0xF7;
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 0;
  (p->s).mode[2] = 0;
  (p->s).mode[3] = 0;
  Ghost83_Update(p);
}

// --------------------------------------------

NAKED static void Ghost83_Update(struct VFX *p) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r0, [r2, #0x28]\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #1\n\
	bhi _080C9AE4\n\
	cmp r0, #4\n\
	beq _080C9AE4\n\
	ldr r0, [r2, #0x2c]\n\
	ldrb r1, [r0, #0xc]\n\
	cmp r1, #1\n\
	bhi _080C9AE4\n\
	ldrb r0, [r0, #0xe]\n\
	cmp r0, #9\n\
	bhi _080C9AE4\n\
	cmp r1, #4\n\
	beq _080C9AE4\n\
	ldr r0, _080C9B04 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldrb r1, [r0, #0xa]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080C9B0C\n\
_080C9AE4:\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
	ldr r1, _080C9B08 @ =gVFXFnTable\n\
	ldrb r0, [r2, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r2, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r2, #0x14]\n\
	b _080C9B1C\n\
	.align 2, 0\n\
_080C9B04: .4byte pZero2\n\
_080C9B08: .4byte gVFXFnTable\n\
_080C9B0C:\n\
	ldr r0, _080C9B20 @ =0x0836FAE0\n\
	ldrb r1, [r2, #0xd]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r1, [r1]\n\
	adds r0, r2, #0\n\
	bl _call_via_r1\n\
_080C9B1C:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C9B20: .4byte sUpdates\n\
 .syntax divided\n");
}

// --------------------------------------------

static void Ghost83_Die(struct VFX *p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_080c9b44(struct VFX *p);
static void FUN_080c9b48(struct VFX *p);

static const VFXFunc sUpdates[2] = {
    FUN_080c9b44,
    FUN_080c9b48,
};

static void FUN_080c9b44(struct VFX *p) { return; }

static void FUN_080c9b48(struct VFX *p) { return; }

// --------------------------------------------

static const u8 u8_ARRAY_0836fae8[32] = {
    2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1,
};

NAKED static void FUN_080c9b4c(struct Sprite *p, struct DrawPivot *_) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #4\n\
	ldr r5, [r0, #8]\n\
	movs r4, #0xa0\n\
	lsls r4, r4, #1\n\
	adds r0, r4, #0\n\
	bl Malloc\n\
	adds r6, r0, #0\n\
	cmp r6, #0\n\
	beq _080C9BD0\n\
	movs r0, #0\n\
	adds r1, r6, #0\n\
	adds r2, r4, #0\n\
	bl FillMemory\n\
	ldr r1, _080C9BD8 @ =gPaletteManager\n\
	ldr r2, _080C9BDC @ =0x0000FFFF\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r2, [r5, #0x78]\n\
	ldr r1, [r5, #0x7c]\n\
	adds r3, r2, r1\n\
	adds r0, r2, #0\n\
	adds r0, #0x20\n\
	subs r0, r0, r1\n\
	cmp r3, r0\n\
	bge _080C9BB2\n\
	ldr r0, _080C9BE0 @ =0x0836FAE8\n\
	mov ip, r0\n\
	movs r7, #0xff\n\
	lsls r0, r3, #1\n\
	adds r4, r0, r6\n\
_080C9B8E:\n\
	subs r0, r3, r2\n\
	str r0, [sp]\n\
	ldr r1, [r5, #0x74]\n\
	ldr r0, [sp]\n\
	add r0, ip\n\
	ldrb r0, [r0]\n\
	adds r0, r0, r1\n\
	ands r0, r7\n\
	strh r0, [r4]\n\
	adds r4, #2\n\
	adds r3, #1\n\
	ldr r2, [r5, #0x78]\n\
	adds r0, r2, #0\n\
	adds r0, #0x20\n\
	ldr r1, [r5, #0x7c]\n\
	subs r0, r0, r1\n\
	cmp r3, r0\n\
	blt _080C9B8E\n\
_080C9BB2:\n\
	ldr r2, _080C9BE4 @ =gIntrManager\n\
	movs r1, #0xba\n\
	lsls r1, r1, #1\n\
	adds r0, r2, r1\n\
	str r6, [r0]\n\
	movs r0, #0xbc\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	ldr r0, _080C9BE8 @ =0x04000042\n\
	str r0, [r1]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	ldr r0, _080C9BEC @ =0xA2600001\n\
	str r0, [r1]\n\
_080C9BD0:\n\
	add sp, #4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C9BD8: .4byte gPaletteManager\n\
_080C9BDC: .4byte 0x0000FFFF\n\
_080C9BE0: .4byte u8_ARRAY_0836fae8\n\
_080C9BE4: .4byte gIntrManager\n\
_080C9BE8: .4byte 0x04000042\n\
_080C9BEC: .4byte 0xA2600001\n\
 .syntax divided\n");
}
