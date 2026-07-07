#include "entity.h"
#include "global.h"
#include "renderer.h"
#include "vfx.h"

// enemy/omega_zx_x.c 関連

extern struct Zero* pZero2;

static void Ghost83_Init(struct Entity* p);
static void Ghost83_Update(struct Entity* p);
static void Ghost83_Die(struct Entity* p);

// clang-format off
const VFXRoutine gGhost83Routine = {
    [ENTITY_INIT] =      (void*)Ghost83_Init,
    [ENTITY_UPDATE] =    (void*)Ghost83_Update,
    [ENTITY_DIE] =       (void*)Ghost83_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct Entity* CreateGhost83(struct Entity* e) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_083);
    p->work[0] = 0, p->work[1] = 0;
    p->unk_28 = e;
  }
  return p;
}

// --------------------------------------------

static void TaskCB_080c9b4c(struct Sprite* p, struct DrawPivot* _);

static void Ghost83_Init(struct Entity* p) {
  SetTaskCallback((void*)&p->spr, TaskCB_080c9b4c);
  (p->spr).sprites = (void*)p;
  p->flags &= ~USE_COMMON_OAM_RENDERER;
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  Ghost83_Update(p);
}

// --------------------------------------------

static void FUN_080c9b44(void* _ UNUSED);
static void FUN_080c9b48(void* _ UNUSED);

static void Ghost83_Update(struct Entity* p) {
  static const EntityFunc sUpdates[2] = {
      (void*)FUN_080c9b44,
      (void*)FUN_080c9b48,
  };

  struct Entity* q = p->unk_28;
  if (q->mode[0] <= ENTITY_UPDATE) {
    if (q->mode[0] != ENTITY_EXIT) {
      struct Entity* r = p->unk_2c;
      if (r->mode[0] <= ENTITY_UPDATE) {
        if ((r->mode[2] < 10) && (r->mode[0] != ENTITY_EXIT)) {
          if ((pZero2->s).flags & DISPLAY) {
            goto _Update;
          }
        }
      }
    }
  }
  p->flags &= ~DISPLAY;
  p->flags &= ~FLIPABLE;
  SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
  return;

_Update:
  (sUpdates[p->mode[1]])(p);
}

// --------------------------------------------

static void Ghost83_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_080c9b44(void* _) {}
static void FUN_080c9b48(void* _) {}

// --------------------------------------------

static const u8 u8_ARRAY_0836fae8[32] = {
    2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1,
};

NAKED static void TaskCB_080c9b4c(struct Sprite* p, struct DrawPivot* _) {
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
