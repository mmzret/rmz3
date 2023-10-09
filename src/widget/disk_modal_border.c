#include "game.h"
#include "global.h"
#include "widget.h"

/*
セルヴォの研究所でシークレットディスクの中身を表すモーダルの四隅の枠
work[0]:
  0: 左上
  1:
  2:
  3:
*/

static void DiskModalBorder_Init(struct Widget *w);
static void DiskModalBorder_Update(struct Widget *w);
static void DiskModalBorder_Die(struct Widget *w);

// clang-format off
const WidgetRoutine gDiskModalBorderRoutine = {
    [ENTITY_INIT] =      DiskModalBorder_Init,
    [ENTITY_UPDATE] =    DiskModalBorder_Update,
    [ENTITY_DIE] =       DiskModalBorder_Die,
    [ENTITY_DISAPPEAR] = DeleteWidget,
    [ENTITY_EXIT] =      (WidgetFunc)DeleteEntity,
};
// clang-format on

struct Widget *createSecretDiskModalBorder(struct GameState *g, u8 n) {
  struct Widget *w = (struct Widget *)AllocEntityFirst(gWidgetHeaderPtr);
  if (w != NULL) {
    (w->s).taskCol = 16;
    INIT_WIDGET_ROUTINE(w, 12);
    (w->s).tileNum = 0;
    (w->s).palID = 0;
    (w->s).unk_28 = (struct Entity *)g;
    (w->s).work[0] = n;
    (w->s).work[1] = 0;
  }
  return w;
}

NAKED static void DiskModalBorder_Init(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	ldr r1, _080E82AC @ =gWidgetFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r4, #1\n\
	str r4, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	adds r0, r5, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #2\n\
	movs r6, #0\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _080E82B0 @ =0x00000E04\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	ldrb r1, [r5, #0x10]\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	adds r1, r5, #0\n\
	adds r1, #0x4c\n\
	strb r0, [r1]\n\
	ldrb r0, [r5, #0x10]\n\
	ands r4, r0\n\
	adds r3, r5, #0\n\
	adds r3, #0x4a\n\
	lsls r2, r4, #4\n\
	ldrb r1, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strb r0, [r3]\n\
	cmp r4, #0\n\
	beq _080E82B4\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080E82BA\n\
	.align 2, 0\n\
_080E82AC: .4byte gWidgetFnTable\n\
_080E82B0: .4byte 0x00000E04\n\
_080E82B4:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080E82BA:\n\
	strb r0, [r5, #0xa]\n\
	ldrb r0, [r5, #0x10]\n\
	lsrs r0, r0, #1\n\
	movs r2, #1\n\
	ands r0, r2\n\
	adds r1, r5, #0\n\
	adds r1, #0x4d\n\
	strb r0, [r1]\n\
	ldrb r1, [r5, #0x10]\n\
	lsrs r1, r1, #1\n\
	adds r4, r5, #0\n\
	adds r4, #0x4a\n\
	ands r1, r2\n\
	lsls r3, r1, #5\n\
	ldrb r2, [r4]\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r3\n\
	strb r0, [r4]\n\
	cmp r1, #0\n\
	beq _080E82EE\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x20\n\
	orrs r0, r1\n\
	b _080E82F4\n\
_080E82EE:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xdf\n\
	ands r0, r1\n\
_080E82F4:\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	bl DiskModalBorder_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED static void DiskModalBorder_Update(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldr r0, [r4, #0x28]\n\
	ldr r1, _080E8334 @ =0x00000DCC\n\
	adds r5, r0, r1\n\
	ldrb r0, [r5, #0xd]\n\
	cmp r0, #0\n\
	beq _080E833C\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080E8338 @ =gWidgetFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
	b _080E83B2\n\
	.align 2, 0\n\
_080E8334: .4byte 0x00000DCC\n\
_080E8338: .4byte gWidgetFnTable\n\
_080E833C:\n\
	ldrb r0, [r5, #0xe]\n\
	cmp r0, #0\n\
	beq _080E83AA\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #1\n\
	beq _080E837C\n\
	cmp r0, #1\n\
	bgt _080E8360\n\
	cmp r0, #0\n\
	beq _080E836A\n\
	b _080E83B2\n\
_080E8360:\n\
	cmp r0, #2\n\
	beq _080E838C\n\
	cmp r0, #3\n\
	beq _080E8398\n\
	b _080E83B2\n\
_080E836A:\n\
	ldrb r1, [r5, #0xe]\n\
	movs r0, #0x40\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #8\n\
	str r0, [r4, #0x54]\n\
	ldrb r1, [r5, #0xf]\n\
	movs r0, #0x50\n\
	subs r0, r0, r1\n\
	b _080E83A4\n\
_080E837C:\n\
	ldrb r0, [r5, #0xe]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #8\n\
	str r0, [r4, #0x54]\n\
	ldrb r1, [r5, #0xf]\n\
	movs r0, #0x50\n\
	subs r0, r0, r1\n\
	b _080E83A4\n\
_080E838C:\n\
	ldrb r0, [r5, #0xe]\n\
	movs r1, #0x40\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #8\n\
	str r1, [r4, #0x54]\n\
	b _080E83A0\n\
_080E8398:\n\
	ldrb r0, [r5, #0xe]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #8\n\
	str r0, [r4, #0x54]\n\
_080E83A0:\n\
	ldrb r0, [r5, #0xf]\n\
	adds r0, #0x50\n\
_080E83A4:\n\
	lsls r0, r0, #8\n\
	str r0, [r4, #0x58]\n\
	b _080E83B2\n\
_080E83AA:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
_080E83B2:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void DiskModalBorder_Die(struct Widget *w) { SET_WIDGET_ROUTINE(w, ENTITY_EXIT); }
