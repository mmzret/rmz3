#include "game.h"
#include "global.h"
#include "widget.h"

static void Widget9_Init(struct Widget *w);
static void Widget9_Update(struct Widget *w);
static void Widget9_Die(struct Widget *w);

// clang-format off
const WidgetRoutine gWidget9Routine = {
    [ENTITY_INIT] =      Widget9_Init,
    [ENTITY_MAIN] =      Widget9_Update,
    [ENTITY_DIE] =       Widget9_Die,
    [ENTITY_DISAPPEAR] = DeleteWidget,
    [ENTITY_EXIT] =      (WidgetFunc)DeleteEntity,
};
// clang-format on

struct Widget *CreateMenuComp9(struct GameState *g, bool8 r1, u8 r2) {
  struct Widget *w = (struct Widget *)AllocEntityFirst(gWidgetHeaderPtr);
  if (w != NULL) {
    (w->s).taskCol = 16;
    INIT_WIDGET_ROUTINE(w, 9);
    (w->s).tileNum = 0;
    (w->s).palID = 0;
    (w->s).unk_28 = (struct Entity *)g;
    (w->s).work[0] = r1;
    (w->s).work[1] = r2;
  }
  return w;
}

// --------------------------------------------

static void FUN_080e7a84(struct Widget *w);
static void FUN_080e7a9c(struct Widget *w);

static void Widget9_Init(struct Widget *w) {
  static const WidgetFunc sInitializers[2] = {
      FUN_080e7a84,
      FUN_080e7a9c,
  };
  SET_WIDGET_ROUTINE(w, ENTITY_MAIN);
  InitNonAffineMotion(&w->s);
  (w->s).flags |= DISPLAY;
  (w->s).flags |= FLIPABLE;
  (w->s).spr.xflip = FALSE;
  (w->s).spr.oam.xflip = FALSE;
  (w->s).flags &= ~X_FLIP;
  (sInitializers[(w->s).work[0]])(w);
  Widget9_Update(w);
}

// --------------------------------------------

static void FUN_080e7ab0(struct Widget *w);
static void FUN_080e7b9c(struct Widget *w);

static void Widget9_Update(struct Widget *w) {
  static const WidgetFunc sUpdates[2] = {
      FUN_080e7ab0,
      FUN_080e7b9c,
  };

  struct GameState *g = (struct GameState *)(w->s).unk_28;
  if ((((&((g->sceneState).menu).elf)->unk_f & 0xFC) != 0) || g->mode[3] == 0) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    SET_WIDGET_ROUTINE(w, ENTITY_DISAPPEAR);
    return;
  }

  if (g->mode[3] < 2) {
    (w->s).flags &= ~DISPLAY;
  } else {
    (w->s).flags |= DISPLAY;
    (sUpdates[(w->s).work[0]])(w);
  }
  UpdateMotionGraphic(&w->s);
}

// --------------------------------------------

static void Widget9_Die(struct Widget *w) {
  SET_WIDGET_ROUTINE(w, ENTITY_EXIT);
  return;
}

// --------------------------------------------

static void FUN_080e7a84(struct Widget *w) {
  (w->s).coord.x = PIXEL(357);
  (w->s).coord.y = (w->s).work[1] * PIXEL(16) + PIXEL(16);
}

static void FUN_080e7a9c(struct Widget *w) {
  (w->s).coord.x = PIXEL(340);
  (w->s).coord.y = (w->s).work[1] * PIXEL(16) + PIXEL(16);
}

// --------------------------------------------

NAKED static void FUN_080e7ab0(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r3, r0, #0\n\
	ldr r0, [r3, #0x28]\n\
	ldr r2, _080E7AE0 @ =0x000064AC\n\
	adds r1, r0, r2\n\
	ldr r1, [r1]\n\
	ldr r2, _080E7AE4 @ =0x00000DFC\n\
	adds r0, r0, r2\n\
	ldrb r2, [r3, #0x11]\n\
	adds r0, r0, r2\n\
	ldrb r2, [r0]\n\
	cmp r2, #0xff\n\
	beq _080E7B8C\n\
	ldr r0, _080E7AE8 @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	adds r4, r0, r2\n\
	ldrb r5, [r4]\n\
	movs r0, #2\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	beq _080E7AF0\n\
	ldr r1, _080E7AEC @ =0x00005302\n\
	b _080E7B7E\n\
	.align 2, 0\n\
_080E7AE0: .4byte 0x000064AC\n\
_080E7AE4: .4byte 0x00000DFC\n\
_080E7AE8: .4byte gUnlockedElfPtr\n\
_080E7AEC: .4byte 0x00005302\n\
_080E7AF0:\n\
	adds r1, #0xb4\n\
	ldrb r0, [r1]\n\
	cmp r0, r2\n\
	bne _080E7B00\n\
	ldr r1, _080E7AFC @ =0x00005301\n\
	b _080E7B7E\n\
	.align 2, 0\n\
_080E7AFC: .4byte 0x00005301\n\
_080E7B00:\n\
	ldrb r0, [r1, #1]\n\
	cmp r0, r2\n\
	bne _080E7B10\n\
	ldr r1, _080E7B0C @ =0x0000530F\n\
	b _080E7B7E\n\
	.align 2, 0\n\
_080E7B0C: .4byte 0x0000530F\n\
_080E7B10:\n\
	ldr r1, _080E7B34 @ =gElfBreedInfo\n\
	lsls r0, r2, #2\n\
	adds r0, r0, r1\n\
	ldrb r2, [r0]\n\
	lsls r1, r2, #0x1d\n\
	lsrs r1, r1, #0x1d\n\
	ldr r0, [r4]\n\
	lsls r0, r0, #0x1b\n\
	lsrs r0, r0, #0x1e\n\
	subs r0, r1, r0\n\
	cmp r0, #1\n\
	beq _080E7B72\n\
	cmp r0, #1\n\
	bgt _080E7B38\n\
	cmp r0, #0\n\
	beq _080E7B3E\n\
	b _080E7B94\n\
	.align 2, 0\n\
_080E7B34: .4byte gElfBreedInfo\n\
_080E7B38:\n\
	cmp r0, #2\n\
	beq _080E7B7C\n\
	b _080E7B94\n\
_080E7B3E:\n\
	lsls r1, r2, #0x1a\n\
	lsrs r0, r1, #0x1d\n\
	cmp r0, #1\n\
	bne _080E7B50\n\
	ldr r1, _080E7B4C @ =0x00005303\n\
	b _080E7B7E\n\
	.align 2, 0\n\
_080E7B4C: .4byte 0x00005303\n\
_080E7B50:\n\
	lsrs r0, r1, #0x1d\n\
	cmp r0, #2\n\
	bne _080E7B6C\n\
	movs r0, #4\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	beq _080E7B64\n\
	movs r1, #0xa6\n\
	lsls r1, r1, #7\n\
	b _080E7B7E\n\
_080E7B64:\n\
	ldr r1, _080E7B68 @ =0x00005306\n\
	b _080E7B7E\n\
	.align 2, 0\n\
_080E7B68: .4byte 0x00005306\n\
_080E7B6C:\n\
	movs r1, #0xa6\n\
	lsls r1, r1, #7\n\
	b _080E7B7E\n\
_080E7B72:\n\
	ldr r1, _080E7B78 @ =0x00005304\n\
	b _080E7B7E\n\
	.align 2, 0\n\
_080E7B78: .4byte 0x00005304\n\
_080E7B7C:\n\
	ldr r1, _080E7B88 @ =0x00005305\n\
_080E7B7E:\n\
	adds r0, r3, #0\n\
	bl SetMotion\n\
	b _080E7B94\n\
	.align 2, 0\n\
_080E7B88: .4byte 0x00005305\n\
_080E7B8C:\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r3, #0xa]\n\
_080E7B94:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED static void FUN_080e7b9c(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r3, r0, #0\n\
	ldr r0, [r3, #0x28]\n\
	ldr r1, _080E7BCC @ =0x00000DFC\n\
	adds r0, r0, r1\n\
	ldrb r1, [r3, #0x11]\n\
	adds r0, r0, r1\n\
	ldrb r4, [r0]\n\
	cmp r4, #0xff\n\
	beq _080E7C38\n\
	ldr r1, _080E7BD0 @ =gElfBreedInfo\n\
	lsls r2, r4, #2\n\
	adds r0, r2, r1\n\
	ldrb r5, [r0]\n\
	lsls r0, r5, #0x19\n\
	adds r6, r1, #0\n\
	cmp r0, #0\n\
	bge _080E7BE0\n\
	lsrs r0, r5, #7\n\
	cmp r0, #0\n\
	beq _080E7BD8\n\
	ldr r1, _080E7BD4 @ =0x00005311\n\
	b _080E7C2A\n\
	.align 2, 0\n\
_080E7BCC: .4byte 0x00000DFC\n\
_080E7BD0: .4byte gElfBreedInfo\n\
_080E7BD4: .4byte 0x00005311\n\
_080E7BD8:\n\
	ldr r1, _080E7BDC @ =0x00005308\n\
	b _080E7C2A\n\
	.align 2, 0\n\
_080E7BDC: .4byte 0x00005308\n\
_080E7BE0:\n\
	ldr r0, _080E7C04 @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	adds r0, r0, r4\n\
	ldrb r1, [r0]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080E7C14\n\
	lsls r0, r5, #0x1a\n\
	lsrs r0, r0, #0x1d\n\
	cmp r0, #1\n\
	bne _080E7C14\n\
	lsls r0, r5, #0x18\n\
	cmp r0, #0\n\
	bge _080E7C0C\n\
	ldr r1, _080E7C08 @ =0x00005311\n\
	b _080E7C2A\n\
	.align 2, 0\n\
_080E7C04: .4byte gUnlockedElfPtr\n\
_080E7C08: .4byte 0x00005311\n\
_080E7C0C:\n\
	ldr r1, _080E7C10 @ =0x00005308\n\
	b _080E7C2A\n\
	.align 2, 0\n\
_080E7C10: .4byte 0x00005308\n\
_080E7C14:\n\
	adds r0, r2, r6\n\
	ldrb r0, [r0]\n\
	lsrs r0, r0, #7\n\
	cmp r0, #0\n\
	beq _080E7C28\n\
	ldr r1, _080E7C24 @ =0x00005310\n\
	b _080E7C2A\n\
	.align 2, 0\n\
_080E7C24: .4byte 0x00005310\n\
_080E7C28:\n\
	ldr r1, _080E7C34 @ =0x00005307\n\
_080E7C2A:\n\
	adds r0, r3, #0\n\
	bl SetMotion\n\
	b _080E7C40\n\
	.align 2, 0\n\
_080E7C34: .4byte 0x00005307\n\
_080E7C38:\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r3, #0xa]\n\
_080E7C40:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}
