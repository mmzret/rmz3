#include "entity.h"
#include "global.h"
#include "renderer.h"
#include "vfx.h"
#include "zero.h"

static void Ghost84_Init(struct VFX* p);
static void Ghost84_Update(struct VFX* p);
static void Ghost84_Die(struct VFX* p);

// clang-format off
const VFXRoutine gGhost84Routine = {
    [ENTITY_INIT] =      (void*)Ghost84_Init,
    [ENTITY_UPDATE] =    (void*)Ghost84_Update,
    [ENTITY_DIE] =       (void*)Ghost84_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct Entity* CreateGhost84(struct Entity* q) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_084);
    p->work[0] = 0, p->work[1] = 0;
    p->unk_28 = q;
  }
  return p;
}

// --------------------------------------------

static void FUN_080c9d20(struct Sprite* p, struct DrawPivot* _);

static void Ghost84_Init(struct VFX* p) {
  SetTaskCallback((void*)&(p->s).spr, FUN_080c9d20);
  (p->s).spr.sprites = (void*)p;
  (p->s).flags &= ~USE_COMMON_OAM_RENDERER;
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 0, (p->s).mode[2] = 0, (p->s).mode[3] = 0;
  Ghost84_Update(p);
}

static void nop_080c9d18(struct VFX* p);
static void nop_080c9d1c(struct VFX* p);
static const VFXFunc sUpdates[2];

static void Ghost84_Update(struct VFX* p) {

  if (((p->s).unk_28)->mode[0] < 2) {
    if (((p->s).unk_28)->mode[0] != 4) {
      if (((p->s).unk_2c)->mode[0] < 2) {
        if ((((p->s).unk_2c)->mode[2] < 10) && (((p->s).unk_2c)->mode[0] != 4)) {
          if ((pZero2->s).flags & DISPLAY) {
            goto _Update;
          }
        }
      }
    }
  }
  (p->s).flags &= ~DISPLAY;
  (p->s).flags &= ~FLIPABLE;
  SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
  return;

_Update:
  (sUpdates[(p->s).mode[1]])(p);
}

static void Ghost84_Die(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080c9d18(struct VFX* p);
static void nop_080c9d1c(struct VFX* p);

static const VFXFunc sUpdates[2] = {
    nop_080c9d18,
    nop_080c9d1c,
};

// --------------------------------------------

static void nop_080c9d18(struct VFX* p) { return; }

static void nop_080c9d1c(struct VFX* p) { return; }

NAKED static void FUN_080c9d20(struct Sprite* p, struct DrawPivot* _) {
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
