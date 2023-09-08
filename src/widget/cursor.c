#include "game.h"
#include "global.h"
#include "widget.h"

static void MenuCursor_Init(struct Widget *w);
static void MenuCursor_Update(struct Widget *w);
static void MenuCursor_Die(struct Widget *w);

// clang-format off
const WidgetRoutine gMenuCursorRoutine = {
    [ENTITY_INIT] =      MenuCursor_Init,
    [ENTITY_MAIN] =      MenuCursor_Update,
    [ENTITY_DIE] =       MenuCursor_Die,
    [ENTITY_DISAPPEAR] = DeleteWidget,
    [ENTITY_EXIT] =      (WidgetFunc)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

struct Widget *createMenuCursor(struct GameState *g, u8 kind) {
  struct Widget *w = (struct Widget *)AllocEntityFirst(gWidgetHeaderPtr);
  if (w != NULL) {
    (w->s).taskCol = 16;
    INIT_WIDGET_ROUTINE(w, 8);
    (w->s).tileNum = 0;
    (w->s).palID = 0;
    (w->s).unk_28 = (struct Entity *)g;
    (w->s).work[0] = kind;
    (w->s).work[1] = 0;
  }
  return w;
}

// --------------------------------------------

static void FUN_080e76b4(struct Widget *w);
static void FUN_080e76dc(struct Widget *w);
static void FUN_080e7704(struct Widget *w);
static void FUN_080e7720(struct Widget *w);
static void FUN_080e7748(struct Widget *w);
static void FUN_080e7770(struct Widget *w);

static void MenuCursor_Init(struct Widget *w) {
  // clang-format off
  static const WidgetFunc sInitializers[6] = {
      FUN_080e76b4,
      FUN_080e76dc,
      FUN_080e7704,
      FUN_080e7720,
      FUN_080e7748,
      FUN_080e7770,
  };
  // clang-format on
  SET_WIDGET_ROUTINE(w, ENTITY_MAIN);
  InitNonAffineMotion(&w->s);
  (w->s).flags |= DISPLAY;
  (w->s).flags |= FLIPABLE;
  (w->s).spr.xflip = FALSE;
  (w->s).spr.oam.xflip = FALSE;
  (w->s).flags &= ~X_FLIP;
  (sInitializers[(w->s).work[0]])(w);
  MenuCursor_Update(w);
}

// --------------------------------------------

static void FUN_080e778c(struct Widget *w);
static void FUN_080e77c0(struct Widget *w);
static void FUN_080e77f4(struct Widget *w);
static void FUN_080e786c(struct Widget *w);
static void FUN_080e789c(struct Widget *w);
static void FUN_080e78cc(struct Widget *w);

// clang-format off
static const WidgetFunc sUpdates[6] = {
    FUN_080e778c,
    FUN_080e77c0,
    FUN_080e77f4,
    FUN_080e786c,
    FUN_080e789c,
    FUN_080e78cc,
};
// clang-format on

NAKED static void MenuCursor_Update(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldr r2, [r4, #0x28]\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #2\n\
	bls _080E762C\n\
	cmp r0, #5\n\
	bne _080E7648\n\
_080E762C:\n\
	ldr r1, _080E7644 @ =0x00000DFC\n\
	adds r0, r2, r1\n\
	ldrb r1, [r0, #0xf]\n\
	movs r0, #0xfc\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080E7652\n\
	ldrb r0, [r2, #3]\n\
	cmp r0, #0\n\
	bne _080E767C\n\
	b _080E7652\n\
	.align 2, 0\n\
_080E7644: .4byte 0x00000DFC\n\
_080E7648:\n\
	ldr r1, _080E7674 @ =0x00000DCC\n\
	adds r0, r2, r1\n\
	ldrb r0, [r0, #0xd]\n\
	cmp r0, #0\n\
	beq _080E767C\n\
_080E7652:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080E7678 @ =gWidgetFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
	b _080E7692\n\
	.align 2, 0\n\
_080E7674: .4byte 0x00000DCC\n\
_080E7678: .4byte gWidgetFnTable\n\
_080E767C:\n\
	ldr r0, _080E7698 @ =0x08372134\n\
	ldrb r1, [r4, #0x10]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r1, [r1]\n\
	adds r0, r4, #0\n\
	bl _call_via_r1\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
_080E7692:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E7698: .4byte sUpdates\n\
 .syntax divided\n");
}

// --------------------------------------------

static void MenuCursor_Die(struct Widget *w) { SET_WIDGET_ROUTINE(w, ENTITY_EXIT); }

// --------------------------------------------

static void FUN_080e76b4(struct Widget *w) {
  InitNonAffineMotion(&w->s);
  SetMotion(&w->s, MOTION(0x53, 0x0A));
  (w->s).coord.x = PIXEL(356);
  (w->s).coord.y = PIXEL(6);
}

static void FUN_080e76dc(struct Widget *w) {
  InitNonAffineMotion(&w->s);
  SetMotion(&w->s, MOTION(0x53, 0x0C));
  (w->s).coord.x = PIXEL(356);
  (w->s).coord.y = PIXEL(122);
}

static void FUN_080e7704(struct Widget *w) {
  InitNonAffineMotion(&w->s);
  SetMotion(&w->s, MOTION(0x53, 0x0E));
}

static void FUN_080e7720(struct Widget *w) {
  InitNonAffineMotion(&w->s);
  SetMotion(&w->s, MOTION(0x53, 0x0A));
  (w->s).coord.x = PIXEL(114);
  (w->s).coord.y = PIXEL(14);
}

static void FUN_080e7748(struct Widget *w) {
  InitNonAffineMotion(&w->s);
  SetMotion(&w->s, MOTION(0x53, 0x0C));
  (w->s).coord.x = PIXEL(114);
  (w->s).coord.y = PIXEL(128);
}

static void FUN_080e7770(struct Widget *w) {
  InitNonAffineMotion(&w->s);
  SetMotion(&w->s, MOTION(0x53, 0x0E));
}

// --------------------------------------------

static void FUN_080e778c(struct Widget *w) {
  struct GameState *g = (struct GameState *)(w->s).unk_28;
  if ((g->mode[3] == 3) && ((&((g->sceneState).menu).elf)->unk_f & (1 << 0))) {
    (w->s).flags |= DISPLAY;
  } else {
    (w->s).flags &= ~DISPLAY;
  }
}

static void FUN_080e77c0(struct Widget *w) {
  struct GameState *g = (struct GameState *)(w->s).unk_28;
  if ((g->mode[3] == 3) && ((&((g->sceneState).menu).elf)->unk_f & (1 << 1))) {
    (w->s).flags |= DISPLAY;
  } else {
    (w->s).flags &= ~DISPLAY;
  }
}

static void FUN_080e77f4(struct Widget *w) {
  struct GameState *g = (struct GameState *)(w->s).unk_28;
  if (g->mode[3] == 2) {
    (w->s).flags |= DISPLAY;
    (w->s).coord.x = PIXEL(10);
    (w->s).coord.y = PIXEL(9);
    (w->s).coord.x = ((&((g->sceneState).menu).elf)->tab * PIXEL(16)) + PIXEL(10);
  } else if (g->mode[3] == 3) {
    (w->s).flags |= DISPLAY;
    (w->s).coord.x = PIXEL(8);
    (w->s).coord.y = PIXEL(23);
    (w->s).coord.y = ((&((g->sceneState).menu).elf)->cursor * PIXEL(16)) + PIXEL(23);
  } else {
    (w->s).flags &= ~DISPLAY;
  }
  (w->s).coord.x += PIXEL(256);
}

static void FUN_080e786c(struct Widget *w) {
  struct GameState *g = (struct GameState *)(w->s).unk_28;
  if ((g->mode[2] == 0) && (&(g->sceneState).menu)->unk_0b != 0) {
    (w->s).flags |= DISPLAY;
  } else {
    (w->s).flags &= ~DISPLAY;
  }
}

static void FUN_080e789c(struct Widget *w) {
  struct GameState *g = (struct GameState *)(w->s).unk_28;
  if ((g->mode[2] == 0) && (&(g->sceneState).menu)->unk_0b != 30) {
    (w->s).flags |= DISPLAY;
  } else {
    (w->s).flags &= ~DISPLAY;
  }
}

NAKED static void FUN_080e78cc(struct Widget *w) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r1, [r2, #0x28]\n\
	ldr r3, _080E78FC @ =0x00000E17\n\
	adds r0, r1, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #2\n\
	beq _080E7904\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
	ldr r1, _080E7900 @ =gWidgetFnTable\n\
	ldrb r0, [r2, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r2, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r2, #0x14]\n\
	b _080E792E\n\
	.align 2, 0\n\
_080E78FC: .4byte 0x00000E17\n\
_080E7900: .4byte gWidgetFnTable\n\
_080E7904:\n\
	ldr r3, _080E7914 @ =0x00000DFC\n\
	adds r0, r1, r3\n\
	ldrb r0, [r0, #0xe]\n\
	cmp r0, #0\n\
	beq _080E7918\n\
	movs r0, #0xb9\n\
	lsls r0, r0, #8\n\
	b _080E791C\n\
	.align 2, 0\n\
_080E7914: .4byte 0x00000DFC\n\
_080E7918:\n\
	movs r0, #0x91\n\
	lsls r0, r0, #8\n\
_080E791C:\n\
	str r0, [r2, #0x54]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #7\n\
	str r0, [r2, #0x58]\n\
	ldr r0, [r2, #0x54]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #9\n\
	adds r0, r0, r1\n\
	str r0, [r2, #0x54]\n\
_080E792E:\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}
