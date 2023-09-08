#include "blink.h"
#include "game.h"
#include "gfx.h"
#include "global.h"
#include "widget.h"

// サテライト1、サテライト2、フュージョン、Eクリスタル、リスト

static const motion_t sElfMenuItemMotions[5];

static void ElfMenuItem_Init(struct Widget *w);
static void ElfMenuItem_Update(struct Widget *w);
static void ElfMenuItem_Die(struct Widget *w);

// clang-format off
const WidgetRoutine gElfMenuItemRoutine = {
    [ENTITY_INIT] =      ElfMenuItem_Init,
    [ENTITY_MAIN] =      ElfMenuItem_Update,
    [ENTITY_DIE] =       ElfMenuItem_Die,
    [ENTITY_DISAPPEAR] = DeleteWidget,
    [ENTITY_EXIT] =      (WidgetFunc)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

struct Widget *CreateElfMenuItem(struct GameState *g, u8 row, u8 r2) {
  struct Widget *w = (struct Widget *)AllocEntityFirst(gWidgetHeaderPtr);
  if (w != NULL) {
    (w->s).taskCol = 16;
    INIT_WIDGET_ROUTINE(w, 7);
    (w->s).tileNum = 0;
    (w->s).palID = 0;
    (w->s).unk_28 = (struct Entity *)g;
    (w->s).work[0] = row;
    (w->s).work[1] = r2;
  }
  return w;
}

// --------------------------------------------

NAKED static void ElfMenuItem_Init(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldr r0, [r4, #0x28]\n\
	ldr r1, _080E7318 @ =0x000064AC\n\
	adds r0, r0, r1\n\
	ldr r3, [r0]\n\
	ldr r1, _080E731C @ =gWidgetFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	movs r2, #0\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r2, [r0]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r0, _080E7320 @ =0x00012100\n\
	str r0, [r4, #0x54]\n\
	adds r3, #0xb4\n\
	ldrb r0, [r3, #0x1a]\n\
	cmp r0, #1\n\
	bne _080E7324\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #6\n\
	b _080E7332\n\
	.align 2, 0\n\
_080E7318: .4byte 0x000064AC\n\
_080E731C: .4byte gWidgetFnTable\n\
_080E7320: .4byte 0x00012100\n\
_080E7324:\n\
	ldrb r1, [r4, #0x10]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0xa\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	adds r0, r0, r1\n\
_080E7332:\n\
	str r0, [r4, #0x58]\n\
	ldr r1, _080E736C @ =0xFFFFFF00\n\
	str r1, [r4, #0x5c]\n\
	movs r0, #0x80\n\
	rsbs r0, r0, #0\n\
	str r0, [r4, #0x60]\n\
	ldr r0, [r4, #0x54]\n\
	str r0, [r4, #0x74]\n\
	lsls r1, r1, #3\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x78]\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	str r0, [r4, #0x64]\n\
	str r1, [r4, #0x68]\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #0\n\
	bne _080E7360\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #2\n\
	movs r0, #0x5b\n\
	bl LoadBlink\n\
_080E7360:\n\
	adds r0, r4, #0\n\
	bl ElfMenuItem_Update\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E736C: .4byte 0xFFFFFF00\n\
 .syntax divided\n");
}

NAKED static void ElfMenuItem_Update(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r4, r0, #0\n\
	ldr r7, [r4, #0x28]\n\
	ldr r1, _080E73BC @ =0x000064AC\n\
	adds r0, r7, r1\n\
	ldr r0, [r0]\n\
	mov r8, r0\n\
	ldr r0, _080E73C0 @ =0x00000DFC\n\
	adds r5, r7, r0\n\
	ldrb r0, [r5, #0xf]\n\
	movs r6, #0xfc\n\
	ands r6, r0\n\
	cmp r6, #0\n\
	beq _080E73C8\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #0\n\
	bne _080E739C\n\
	movs r0, #0x5b\n\
	bl ClearBlink\n\
_080E739C:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080E73C4 @ =gWidgetFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
	b _080E7540\n\
	.align 2, 0\n\
_080E73BC: .4byte 0x000064AC\n\
_080E73C0: .4byte 0x00000DFC\n\
_080E73C4: .4byte gWidgetFnTable\n\
_080E73C8:\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #0\n\
	bne _080E73D4\n\
	movs r0, #0x5b\n\
	bl GetBlinkMotionState\n\
_080E73D4:\n\
	ldr r0, [r4, #0x64]\n\
	ldr r1, [r4, #0x68]\n\
	str r0, [r4, #0x54]\n\
	str r1, [r4, #0x58]\n\
	ldrb r0, [r4, #0x10]\n\
	ldrb r1, [r5, #7]\n\
	cmp r0, r1\n\
	bne _080E7438\n\
	adds r0, r4, #0\n\
	adds r0, #0x22\n\
	strb r6, [r0]\n\
	ldrb r0, [r5, #0xb]\n\
	cmp r0, #0x10\n\
	bne _080E73F8\n\
	adds r0, r4, #0\n\
	bl InitNonAffineMotion\n\
	b _080E740C\n\
_080E73F8:\n\
	adds r0, r4, #0\n\
	bl InitScalerotMotion1\n\
	adds r0, r4, #0\n\
	adds r0, #0x50\n\
	movs r1, #0x80\n\
	lsls r1, r1, #1\n\
	strh r1, [r0]\n\
	adds r0, #2\n\
	strh r1, [r0]\n\
_080E740C:\n\
	ldr r1, _080E7434 @ =sElfMenuItemMotions\n\
	ldrb r0, [r4, #0x10]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r0, [r4, #0x78]\n\
	ldr r1, [r4, #0x54]\n\
	cmp r0, r1\n\
	beq _080E746C\n\
	ldr r0, [r4, #0x5c]\n\
	adds r0, r1, r0\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, [r4, #0x60]\n\
	adds r0, r0, r1\n\
	b _080E746A\n\
	.align 2, 0\n\
_080E7434: .4byte sElfMenuItemMotions\n\
_080E7438:\n\
	adds r1, r4, #0\n\
	adds r1, #0x22\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	bl InitNonAffineMotion\n\
	ldr r1, _080E7498 @ =sElfMenuItemMotions\n\
	ldrb r0, [r4, #0x10]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r0, [r4, #0x74]\n\
	ldr r1, [r4, #0x54]\n\
	cmp r0, r1\n\
	beq _080E746C\n\
	ldr r0, [r4, #0x5c]\n\
	subs r0, r1, r0\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, [r4, #0x60]\n\
	subs r0, r0, r1\n\
_080E746A:\n\
	str r0, [r4, #0x58]\n\
_080E746C:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	str r0, [r4, #0x64]\n\
	str r1, [r4, #0x68]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r0, _080E749C @ =0x00000DFC\n\
	adds r3, r7, r0\n\
	ldrb r1, [r3, #0xb]\n\
	cmp r1, #0x10\n\
	bne _080E74A0\n\
	adds r2, r4, #0\n\
	adds r2, #0x45\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	b _080E753A\n\
	.align 2, 0\n\
_080E7498: .4byte sElfMenuItemMotions\n\
_080E749C: .4byte 0x00000DFC\n\
_080E74A0:\n\
	movs r0, #0x10\n\
	subs r0, r0, r1\n\
	lsls r6, r0, #0x18\n\
	lsrs r5, r6, #0x18\n\
	adds r2, r4, #0\n\
	adds r2, #0x45\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldrb r0, [r4, #0x10]\n\
	ldrb r1, [r3, #7]\n\
	cmp r0, r1\n\
	beq _080E74EA\n\
	adds r2, r0, #0\n\
	ldrb r1, [r3, #7]\n\
	subs r0, r2, r1\n\
	cmp r0, #0\n\
	bge _080E74CE\n\
	subs r0, r1, r2\n\
_080E74CE:\n\
	subs r0, #1\n\
	lsls r0, r0, #1\n\
	subs r0, r5, r0\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	ble _080E753A\n\
	lsls r1, r0, #0xa\n\
	ldr r0, [r4, #0x54]\n\
	subs r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	b _080E753A\n\
_080E74EA:\n\
	ldr r0, [r4, #0x74]\n\
	ldr r1, [r4, #0x64]\n\
	cmp r0, r1\n\
	beq _080E7500\n\
	ldr r0, [r4, #0x5c]\n\
	subs r0, r1, r0\n\
	str r0, [r4, #0x64]\n\
	ldr r0, [r4, #0x68]\n\
	ldr r1, [r4, #0x60]\n\
	subs r0, r0, r1\n\
	str r0, [r4, #0x68]\n\
_080E7500:\n\
	lsls r0, r5, #4\n\
	movs r1, #0x80\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	adds r1, r4, #0\n\
	adds r1, #0x50\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	strh r0, [r1]\n\
	mov r0, r8\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0x1a]\n\
	cmp r0, #1\n\
	bne _080E7522\n\
	lsrs r1, r6, #0x19\n\
	lsls r1, r1, #8\n\
	b _080E7534\n\
_080E7522:\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #2\n\
	bne _080E752E\n\
	lsrs r1, r6, #0x19\n\
	lsls r1, r1, #8\n\
	b _080E7534\n\
_080E752E:\n\
	cmp r0, #2\n\
	bls _080E753A\n\
	lsls r1, r5, #8\n\
_080E7534:\n\
	ldr r0, [r4, #0x58]\n\
	subs r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
_080E753A:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
_080E7540:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void ElfMenuItem_Die(struct Widget *w) {
  SET_WIDGET_ROUTINE(w, ENTITY_EXIT);
  return;
}

// ------------------------------------------------------------------------------------------------------------------------------------

// clang-format off
static const motion_t sElfMenuItemMotions[5] = {
  MOTION(0x52, 0x00),
  MOTION(0x52, 0x01),
  MOTION(0x52, 0x02),
  MOTION(0x52, 0x03),
  MOTION(0x52, 0x04),
};
// clang-format on
