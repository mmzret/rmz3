#include "game.h"
#include "global.h"
#include "widget.h"

static const u8 sSubtankCoords[4];

static void SubtankIcon_Init(struct Widget *w);
static void SubtankIcon_Update(struct Widget *w);
static void SubtankIcon_Die(struct Widget *w);

// clang-format off
const WidgetRoutine gSubtankIconRoutine = {
    [ENTITY_INIT] =      SubtankIcon_Init,
    [ENTITY_MAIN] =      SubtankIcon_Update,
    [ENTITY_DIE] =       SubtankIcon_Die,
    [ENTITY_DISAPPEAR] = DeleteWidget,
    [ENTITY_EXIT] =      (WidgetFunc)DeleteEntity,
};
// clang-format on

struct Widget *CreateSubtankIcon(struct GameState *g, u8 r1, u8 r2) {
  struct Widget *w = (struct Widget *)AllocEntityLast(gWidgetHeaderPtr);
  if (w != NULL) {
    (w->s).taskCol = 16;
    INIT_WIDGET_ROUTINE(w, 3);
    (w->s).tileNum = 0;
    (w->s).palID = 0;
    (w->s).unk_28 = (struct Entity *)g;
    (w->s).work[0] = r1;
    (w->s).work[1] = r2;
  }
  return w;
}

static void SubtankIcon_Init(struct Widget *w) {
  SET_WIDGET_ROUTINE(w, ENTITY_MAIN);
  InitNonAffineMotion(&w->s);
  (w->s).flags |= DISPLAY;
  (w->s).flags |= FLIPABLE;
  (w->s).spr.xflip = FALSE;
  (w->s).spr.oam.xflip = FALSE;
  (w->s).flags &= ~X_FLIP;
  (w->s).spr.oam.priority = 1;
  (w->s).coord.y = 0x6800;
  SubtankIcon_Update(w);
}

NAKED static void SubtankIcon_Update(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldr r6, [r4, #0x28]\n\
	ldr r1, _080E6660 @ =0x000064AC\n\
	adds r0, r6, r1\n\
	ldr r1, [r0]\n\
	ldrb r0, [r4, #0x10]\n\
	movs r5, #0x81\n\
	lsls r5, r5, #8\n\
	cmp r0, #1\n\
	bhi _080E6648\n\
	adds r5, #0xe\n\
_080E6648:\n\
	adds r0, r1, #0\n\
	adds r0, #0xbc\n\
	ldrb r1, [r4, #0x10]\n\
	adds r0, r0, r1\n\
	ldrb r1, [r0]\n\
	cmp r1, #0\n\
	beq _080E6688\n\
	cmp r1, #0x20\n\
	bne _080E6664\n\
	adds r0, r5, #0\n\
	adds r0, #0xb\n\
	b _080E666C\n\
	.align 2, 0\n\
_080E6660: .4byte 0x000064AC\n\
_080E6664:\n\
	cmp r1, #0x1f\n\
	bne _080E6672\n\
	adds r0, r5, #0\n\
	adds r0, #0xa\n\
_080E666C:\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	b _080E6688\n\
_080E6672:\n\
	ldrb r0, [r0]\n\
	subs r0, #1\n\
	movs r1, #3\n\
	bl __divsi3\n\
	adds r0, #1\n\
	lsls r1, r5, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #0x10\n\
	lsrs r5, r1, #0x10\n\
_080E6688:\n\
	adds r0, r4, #0\n\
	adds r1, r5, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r2, [r4, #0xd]\n\
	cmp r2, #1\n\
	beq _080E66D4\n\
	cmp r2, #1\n\
	bgt _080E66A6\n\
	cmp r2, #0\n\
	beq _080E66B0\n\
	b _080E673E\n\
_080E66A6:\n\
	cmp r2, #2\n\
	beq _080E66FE\n\
	cmp r2, #3\n\
	beq _080E6718\n\
	b _080E673E\n\
_080E66B0:\n\
	ldr r1, _080E6710 @ =sSubtankCoords\n\
	ldrb r0, [r4, #0x11]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #8\n\
	str r0, [r4, #0x54]\n\
	ldrb r0, [r6, #3]\n\
	cmp r0, #3\n\
	bne _080E673E\n\
	ldr r1, _080E6714 @ =0x00000E17\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	bne _080E673E\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
	strb r2, [r4, #0x12]\n\
_080E66D4:\n\
	ldrb r3, [r4, #0x12]\n\
	adds r3, #1\n\
	strb r3, [r4, #0x12]\n\
	ldr r1, _080E6710 @ =sSubtankCoords\n\
	ldrb r0, [r4, #0x11]\n\
	adds r0, r0, r1\n\
	ldrb r2, [r0]\n\
	lsls r2, r2, #8\n\
	ldrb r0, [r4, #0x12]\n\
	lsls r0, r0, #8\n\
	ldrb r1, [r4, #0x11]\n\
	muls r0, r1, r0\n\
	adds r2, r2, r0\n\
	str r2, [r4, #0x54]\n\
	lsls r3, r3, #0x18\n\
	lsrs r3, r3, #0x18\n\
	cmp r3, #7\n\
	bls _080E673E\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
_080E66FE:\n\
	ldr r1, _080E6714 @ =0x00000E17\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #4\n\
	bne _080E673E\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
	b _080E673E\n\
	.align 2, 0\n\
_080E6710: .4byte sSubtankCoords\n\
_080E6714: .4byte 0x00000E17\n\
_080E6718:\n\
	ldrb r3, [r4, #0x12]\n\
	subs r3, #1\n\
	strb r3, [r4, #0x12]\n\
	ldr r1, _080E6768 @ =sSubtankCoords\n\
	ldrb r0, [r4, #0x11]\n\
	adds r0, r0, r1\n\
	ldrb r2, [r0]\n\
	lsls r2, r2, #8\n\
	ldrb r0, [r4, #0x12]\n\
	lsls r0, r0, #8\n\
	ldrb r1, [r4, #0x11]\n\
	muls r0, r1, r0\n\
	adds r2, r2, r0\n\
	str r2, [r4, #0x54]\n\
	lsls r3, r3, #0x18\n\
	lsrs r3, r3, #0x18\n\
	cmp r3, #0\n\
	bne _080E673E\n\
	strb r3, [r4, #0xd]\n\
_080E673E:\n\
	ldr r1, _080E676C @ =0x00000DCC\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0, #4]\n\
	cmp r0, #0\n\
	beq _080E6774\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080E6770 @ =gWidgetFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
	b _080E678A\n\
	.align 2, 0\n\
_080E6768: .4byte sSubtankCoords\n\
_080E676C: .4byte 0x00000DCC\n\
_080E6770: .4byte gWidgetFnTable\n\
_080E6774:\n\
	ldr r0, _080E6790 @ =gVideoRegBuffer+16\n\
	ldrh r1, [r0]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bls _080E678A\n\
	ldr r0, [r4, #0x54]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xa\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
_080E678A:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E6790: .4byte gVideoRegBuffer+16\n\
 .syntax divided\n");
}

static void SubtankIcon_Die(struct Widget *w) {
  SET_WIDGET_ROUTINE(w, ENTITY_EXIT);
  return;
}

// --------------------------------------------

// n個目のサブタンクをどこに表示するか
static const u8 sSubtankCoords[4] = {0x44, 0x4C, 0x54, 0x5C};

// --------------------------------------------
