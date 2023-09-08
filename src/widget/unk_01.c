#include "game.h"
#include "global.h"
#include "widget.h"

/*
  メインメニューの、"メイン", "サブ", "サブタンク", "ヘッド" などの項目名
*/

struct Widget *CreateMenuComp1(struct GameState *m, u8 kind, u8 r2) {
  struct Widget *w = (struct Widget *)AllocEntityFirst(gWidgetHeaderPtr);
  if (w != NULL) {
    (w->s).taskCol = 16;
    INIT_WIDGET_ROUTINE(w, 1);
    (w->s).tileNum = 0;
    (w->s).palID = 0;
    (w->s).unk_28 = (struct Entity *)m;
    (w->s).work[0] = kind;
    (w->s).work[1] = r2;
  }
  return w;
}

NAKED static void MenuComp1_Init(struct Widget *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	ldr r4, [r5, #0x28]\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #1\n\
	movs r2, #0\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	adds r0, #0x4c\n\
	strb r2, [r0]\n\
	adds r2, r5, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r0, _080E62E8 @ =0x00000DCC\n\
	adds r4, r4, r0\n\
	ldrb r0, [r4]\n\
	strb r0, [r5, #0x12]\n\
	ldrb r0, [r5, #0x10]\n\
	ldrb r4, [r4]\n\
	cmp r0, r4\n\
	bne _080E62F0\n\
	ldr r0, _080E62EC @ =sMenuComp1Motions\n\
	ldrb r1, [r5, #0x10]\n\
	lsls r1, r1, #2\n\
	adds r0, #2\n\
	adds r1, r1, r0\n\
	ldrh r1, [r1]\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	b _080E6300\n\
	.align 2, 0\n\
_080E62E8: .4byte 0x00000DCC\n\
_080E62EC: .4byte sMenuComp1Motions\n\
_080E62F0:\n\
	ldr r0, _080E6340 @ =sMenuComp1Motions\n\
	ldrb r1, [r5, #0x10]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldrh r1, [r1]\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
_080E6300:\n\
	ldr r1, _080E6344 @ =u8_ARRAY_08372020\n\
	ldrb r0, [r5, #0x10]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #8\n\
	str r0, [r5, #0x54]\n\
	ldr r1, _080E6348 @ =u8_ARRAY_08372027\n\
	ldrb r0, [r5, #0x10]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #8\n\
	str r0, [r5, #0x58]\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	str r0, [r5, #0x64]\n\
	str r1, [r5, #0x68]\n\
	ldr r1, _080E634C @ =gWidgetFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	adds r0, r5, #0\n\
	bl MenuComp1_Update\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E6340: .4byte sMenuComp1Motions\n\
_080E6344: .4byte u8_ARRAY_08372020\n\
_080E6348: .4byte u8_ARRAY_08372027\n\
_080E634C: .4byte gWidgetFnTable\n\
 .syntax divided\n");
}

NAKED static void MenuComp1_Update(struct Widget *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldr r5, [r4, #0x28]\n\
	ldr r0, _080E6380 @ =0x00000DCC\n\
	adds r2, r5, r0\n\
	ldrb r0, [r2, #4]\n\
	cmp r0, #0\n\
	beq _080E6388\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080E6384 @ =gWidgetFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
	b _080E63F4\n\
	.align 2, 0\n\
_080E6380: .4byte 0x00000DCC\n\
_080E6384: .4byte gWidgetFnTable\n\
_080E6388:\n\
	ldr r0, [r4, #0x64]\n\
	ldr r1, [r4, #0x68]\n\
	str r0, [r4, #0x54]\n\
	str r1, [r4, #0x58]\n\
	ldrb r0, [r4, #0x12]\n\
	ldrb r1, [r2]\n\
	cmp r0, r1\n\
	beq _080E63D0\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, r1\n\
	bne _080E63B8\n\
	ldr r0, _080E63B4 @ =sMenuComp1Motions\n\
	ldrb r1, [r4, #0x10]\n\
	lsls r1, r1, #2\n\
	adds r0, #2\n\
	adds r1, r1, r0\n\
	ldrh r1, [r1]\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _080E63C8\n\
	.align 2, 0\n\
_080E63B4: .4byte sMenuComp1Motions\n\
_080E63B8:\n\
	ldr r0, _080E63FC @ =sMenuComp1Motions\n\
	ldrb r1, [r4, #0x10]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldrh r1, [r1]\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
_080E63C8:\n\
	ldr r1, _080E6400 @ =0x00000DCC\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0]\n\
	strb r0, [r4, #0x12]\n\
_080E63D0:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	str r0, [r4, #0x64]\n\
	str r1, [r4, #0x68]\n\
	ldr r0, _080E6404 @ =gVideoRegBuffer+16\n\
	ldrh r1, [r0]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bls _080E63F4\n\
	ldr r0, [r4, #0x54]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xa\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
_080E63F4:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E63FC: .4byte sMenuComp1Motions\n\
_080E6400: .4byte 0x00000DCC\n\
_080E6404: .4byte gVideoRegBuffer+16\n\
 .syntax divided\n");
}

static void MenuComp1_Die(struct Widget *w) {
  SET_WIDGET_ROUTINE(w, ENTITY_EXIT);
  return;
}

// ------------------------------------------------------------------------------------------------------------------------------------

// clang-format off
const WidgetRoutine gMenuComp1Routine = {
    [ENTITY_INIT] =      MenuComp1_Init,
    [ENTITY_MAIN] =      MenuComp1_Update,
    [ENTITY_DIE] =       MenuComp1_Die,
    [ENTITY_DISAPPEAR] = DeleteWidget,
    [ENTITY_EXIT] =      (WidgetFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

// clang-format off
const motion_t sMenuComp1Motions[14] = {
  MOTION(SM015_MENUITEM, 0x00),
  MOTION(SM015_MENUITEM, 0x01),
  MOTION(SM015_MENUITEM, 0x02),
  MOTION(SM015_MENUITEM, 0x03),
  MOTION(SM015_MENUITEM, 0x0A),
  MOTION(SM015_MENUITEM, 0x0B),
  MOTION(SM015_MENUITEM, 0x04),
  MOTION(SM015_MENUITEM, 0x05),
  MOTION(SM015_MENUITEM, 0x06),
  MOTION(SM015_MENUITEM, 0x07),
  MOTION(SM015_MENUITEM, 0x08),
  MOTION(SM015_MENUITEM, 0x09),
  MOTION(SM015_MENUITEM, 0x0C),
  MOTION(SM015_MENUITEM, 0x0D),
};
// clang-format on

// --------------------------------------------

const u8 u8_ARRAY_08372020[7] = {
    0x18, 0x18, 0x18, 0xB0, 0xB0, 0xB0, 0x5C,
};

const u8 u8_ARRAY_08372027[7] = {
    0x38, 0x50, 0x68, 0x38, 0x50, 0x68, 0x78,
};
