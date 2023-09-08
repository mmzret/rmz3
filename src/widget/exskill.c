#include "game.h"
#include "global.h"
#include "widget.h"

static const motion_t sExIconMotions[12];

static void ExIcon_Init(struct Widget *w);
static void ExIcon_Update(struct Widget *w);
static void ExIcon_Die(struct Widget *w);

// clang-format off
const WidgetRoutine gExIconRoutine = {
    [ENTITY_INIT] =      ExIcon_Init,
    [ENTITY_MAIN] =      ExIcon_Update,
    [ENTITY_DIE] =       ExIcon_Die,
    [ENTITY_DISAPPEAR] = DeleteWidget,
    [ENTITY_EXIT] =      (WidgetFunc)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

struct Widget *CreateExSkillIcon(struct GameState *g, u8 kind) {
  struct Widget *w = (struct Widget *)AllocEntityFirst(gWidgetHeaderPtr);
  if (w != NULL) {
    (w->s).taskCol = 16;
    INIT_WIDGET_ROUTINE(w, 6);
    (w->s).tileNum = 0;
    (w->s).palID = 0;
    (w->s).unk_28 = (struct Entity *)g;
    (w->s).work[0] = kind;
    (w->s).work[1] = 0;
  }
  return w;
}

NON_MATCH static void ExIcon_Init(struct Widget *w) {
#if MODERN
  SET_WIDGET_ROUTINE(w, ENTITY_MAIN);
  (w->s).flags |= DISPLAY;
  (w->s).flags |= FLIPABLE;
  (w->s).spr.xflip = FALSE;
  (w->s).spr.oam.xflip = FALSE;
  (w->s).flags &= ~X_FLIP;
  (w->s).coord.x = (u32)((w->s).work[0] & 3) * PIXEL(24) + PIXEL(16) + PIXEL(256);
  (w->s).coord.y = (u32)((w->s).work[0] >> 2) * PIXEL(24) + PIXEL(28);
  ExIcon_Update(w);
#else
  INCCODE("asm/wip/ExIcon_Init.inc");
#endif
}

NAKED static void ExIcon_Update(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldr r0, [r4, #0x28]\n\
	ldr r2, _080E71E8 @ =0x000064AC\n\
	adds r1, r0, r2\n\
	ldr r1, [r1]\n\
	movs r2, #0xdf\n\
	lsls r2, r2, #4\n\
	adds r0, r0, r2\n\
	ldrb r3, [r0, #5]\n\
	cmp r3, #0\n\
	beq _080E71F0\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080E71EC @ =gWidgetFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
	b _080E724A\n\
	.align 2, 0\n\
_080E71E8: .4byte 0x000064AC\n\
_080E71EC: .4byte gWidgetFnTable\n\
_080E71F0:\n\
	adds r0, r1, #0\n\
	adds r0, #0xb4\n\
	ldrh r1, [r0, #0x12]\n\
	ldrb r2, [r4, #0x10]\n\
	movs r5, #1\n\
	adds r0, r5, #0\n\
	lsls r0, r2\n\
	ands r1, r0\n\
	asrs r1, r2\n\
	cmp r1, #0\n\
	beq _080E7228\n\
	adds r0, r4, #0\n\
	adds r0, #0x22\n\
	strb r3, [r0]\n\
	adds r0, r4, #0\n\
	bl InitNonAffineMotion\n\
	ldr r0, _080E7224 @ =sExIconMotions\n\
	ldrb r1, [r4, #0x10]\n\
	lsls r1, r1, #1\n\
	adds r1, r1, r0\n\
	ldrh r1, [r1]\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _080E7244\n\
	.align 2, 0\n\
_080E7224: .4byte sExIconMotions\n\
_080E7228:\n\
	adds r0, r4, #0\n\
	adds r0, #0x22\n\
	strb r5, [r0]\n\
	adds r0, r4, #0\n\
	bl InitNonAffineMotion\n\
	ldr r0, _080E7250 @ =sExIconMotions\n\
	ldrb r1, [r4, #0x10]\n\
	lsls r1, r1, #1\n\
	adds r1, r1, r0\n\
	ldrh r1, [r1]\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
_080E7244:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
_080E724A:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E7250: .4byte sExIconMotions\n\
   .syntax divided\n");
}

static void ExIcon_Die(struct Widget *w) {
  SET_WIDGET_ROUTINE(w, ENTITY_EXIT);
  return;
}

// ------------------------------------------------------------------------------------------------------------------------------------

// clang-format off
static const motion_t sExIconMotions[12] = {
    MOTION(0x45, 0x05),
    MOTION(0x45, 0x04),
    MOTION(0x45, 0x06),
    MOTION(0x45, 0x07),
    MOTION(0x45, 0x03),
    MOTION(0x45, 0x00),
    MOTION(0x45, 0x01),
    MOTION(0x45, 0x02),
    MOTION(0x45, 0x08),
    MOTION(0x45, 0x09),
    MOTION(0x45, 0x0B),
    MOTION(0x45, 0x0A),
};
// clang-format on
