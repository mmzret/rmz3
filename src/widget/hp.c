#include "game.h"
#include "global.h"
#include "widget.h"

/*
  メニュー画面のHPゲージを構成するメモリ1つ
*/

static void MenuHP_Init(struct Widget *w);
static void MenuHP_Update(struct Widget *w);
static void MenuHP_Die(struct Widget *w);

// clang-format off
const WidgetRoutine gMenuHPRoutine = {
    [ENTITY_INIT] =      MenuHP_Init,
    [ENTITY_MAIN] =      MenuHP_Update,
    [ENTITY_DIE] =       MenuHP_Die,
    [ENTITY_DISAPPEAR] = DeleteWidget,
    [ENTITY_EXIT] =      (WidgetFunc)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

struct Widget *CreateMenuHPGauge(struct GameState *g, u8 x, u8 r2) {
  struct Widget *w = (struct Widget *)AllocEntityFirst(gWidgetHeaderPtr);
  if (w != NULL) {
    (w->s).taskCol = 16;
    INIT_WIDGET_ROUTINE(w, 4);
    (w->s).tileNum = 0;
    (w->s).palID = 0;
    (w->s).unk_28 = (struct Entity *)g;
    (w->s).work[0] = x;
    (w->s).work[1] = r2;
  }
  return w;
}

// --------------------------------------------

static void MenuHP_Init(struct Widget *w) {
  SET_WIDGET_ROUTINE(w, ENTITY_MAIN);
  InitNonAffineMotion(&w->s);
  (w->s).flags |= DISPLAY;
  (w->s).flags |= FLIPABLE;
  (w->s).spr.xflip = FALSE;
  (w->s).spr.oam.xflip = FALSE;
  (w->s).flags &= ~X_FLIP;
  (w->s).spr.oam.priority = 3;
  MenuHP_Update(w);
}

NAKED static void MenuHP_Update(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r5, r0, #0\n\
	ldr r0, [r5, #0x28]\n\
	mov r8, r0\n\
	ldr r0, _080E68D4 @ =0x000064AC\n\
	add r0, r8\n\
	ldr r6, [r0]\n\
	ldrb r0, [r5, #0x10]\n\
	lsls r0, r0, #0xb\n\
	movs r1, #0xb8\n\
	lsls r1, r1, #6\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	movs r0, #0x8c\n\
	lsls r0, r0, #6\n\
	str r0, [r5, #0x58]\n\
	adds r0, r6, #0\n\
	bl IsDoubleHP\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _080E68D8\n\
	adds r7, r6, #0\n\
	adds r7, #0xa4\n\
	movs r0, #0\n\
	ldrsh r4, [r7, r0]\n\
	adds r0, r6, #0\n\
	bl getMaxHP1x\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r4, r0\n\
	ble _080E68D8\n\
	adds r0, r6, #0\n\
	bl getMaxHP1x\n\
	ldrb r1, [r7]\n\
	subs r1, r1, r0\n\
	ldrb r0, [r5, #0x10]\n\
	lsls r0, r0, #2\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #0x18\n\
	lsrs r2, r1, #0x18\n\
	asrs r1, r1, #0x18\n\
	cmp r1, #4\n\
	ble _080E68BE\n\
	movs r2, #4\n\
_080E68BE:\n\
	lsls r0, r2, #0x18\n\
	cmp r0, #0\n\
	bge _080E68C6\n\
	movs r2, #0\n\
_080E68C6:\n\
	lsls r0, r2, #0x18\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x13\n\
	adds r0, r0, r1\n\
	lsrs r2, r0, #0x18\n\
	b _080E68F8\n\
	.align 2, 0\n\
_080E68D4: .4byte 0x000064AC\n\
_080E68D8:\n\
	adds r0, r6, #0\n\
	adds r0, #0xa4\n\
	ldrb r1, [r0]\n\
	ldrb r0, [r5, #0x10]\n\
	lsls r0, r0, #2\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #0x18\n\
	lsrs r2, r1, #0x18\n\
	asrs r1, r1, #0x18\n\
	cmp r1, #4\n\
	ble _080E68F0\n\
	movs r2, #4\n\
_080E68F0:\n\
	lsls r0, r2, #0x18\n\
	cmp r0, #0\n\
	bge _080E68F8\n\
	movs r2, #0\n\
_080E68F8:\n\
	lsls r1, r2, #0x18\n\
	asrs r1, r1, #8\n\
	ldr r0, _080E6938 @ =0x0E0C0000\n\
	adds r1, r1, r0\n\
	lsrs r1, r1, #0x10\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, _080E693C @ =0x00000DCC\n\
	add r0, r8\n\
	ldrb r0, [r0, #4]\n\
	cmp r0, #0\n\
	beq _080E6944\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _080E6940 @ =gWidgetFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r5, #0x14]\n\
	b _080E695A\n\
	.align 2, 0\n\
_080E6938: .4byte 0x0E0C0000\n\
_080E693C: .4byte 0x00000DCC\n\
_080E6940: .4byte gWidgetFnTable\n\
_080E6944:\n\
	ldr r0, _080E6964 @ =gVideoRegBuffer+16\n\
	ldrh r1, [r0]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bls _080E695A\n\
	ldr r0, [r5, #0x54]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xa\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
_080E695A:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E6964: .4byte gVideoRegBuffer+16\n\
 .syntax divided\n");
}

static void MenuHP_Die(struct Widget *w) {
  SET_WIDGET_ROUTINE(w, ENTITY_EXIT);
  return;
}
