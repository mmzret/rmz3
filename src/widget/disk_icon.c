#include "game.h"
#include "global.h"
#include "widget.h"

static void DiskIcon_Init(struct Widget *w);
static void DiskIcon_Update(struct Widget *w);
static void DiskIcon_Die(struct Widget *w);

// clang-format off
const WidgetRoutine gDiskIconRoutine = {
    [ENTITY_INIT] =      DiskIcon_Init,
    [ENTITY_MAIN] =      DiskIcon_Update,
    [ENTITY_DIE] =       DiskIcon_Die,
    [ENTITY_DISAPPEAR] = DeleteWidget,
    [ENTITY_EXIT] =      (WidgetFunc)DeleteEntity,
};
// clang-format on

void CreateDiskIcon(struct Coord *c, u8 n, u8 r2) {
  struct Widget *w = (struct Widget *)AllocEntityFirst(gWidgetHeaderPtr);
  if (w != NULL) {
    (w->s).taskCol = 16;
    INIT_WIDGET_ROUTINE(w, 10);
    (w->s).tileNum = 0;
    (w->s).palID = 0;
    (w->s).coord = *c;
    (w->s).work[0] = n;
    (w->s).work[1] = r2;
  }
}

static void DiskIcon_Init(struct Widget *w) {
  SET_WIDGET_ROUTINE(w, ENTITY_MAIN);
  InitNonAffineMotion(&w->s);
  (w->s).flags |= DISPLAY;
  (w->s).flags |= FLIPABLE;
  (w->s).coord.x += PIXEL(8);
  (w->s).coord.y += PIXEL(13);
  (w->s).spr.xflip = FALSE;
  (w->s).spr.oam.xflip = FALSE;
  (w->s).flags &= ~X_FLIP;
  (w->s).spr.oam.priority = 0;
  DiskIcon_Update(w);
}

NAKED static void DiskIcon_Update(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #0\n\
	bne _080E7DC6\n\
	ldrb r1, [r4, #0x10]\n\
	subs r0, r1, #6\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xd\n\
	bls _080E7D2E\n\
	cmp r1, #0x6d\n\
	bls _080E7D68\n\
_080E7D2E:\n\
	ldr r0, _080E7D3C @ =gSystemSavedataManager\n\
	adds r0, #0x4b\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080E7D44\n\
	ldr r1, _080E7D40 @ =0x0000B00B\n\
	b _080E7D56\n\
	.align 2, 0\n\
_080E7D3C: .4byte gSystemSavedataManager\n\
_080E7D40: .4byte 0x0000B00B\n\
_080E7D44:\n\
	cmp r0, #1\n\
	bne _080E7D50\n\
	ldr r1, _080E7D4C @ =0x0000B10B\n\
	b _080E7D56\n\
	.align 2, 0\n\
_080E7D4C: .4byte 0x0000B10B\n\
_080E7D50:\n\
	cmp r0, #2\n\
	bne _080E7DA6\n\
	ldr r1, _080E7D64 @ =0x0000B20B\n\
_080E7D56:\n\
	adds r0, r4, #0\n\
	movs r2, #5\n\
	movs r3, #2\n\
	bl GotoMotion\n\
	b _080E7DA6\n\
	.align 2, 0\n\
_080E7D64: .4byte 0x0000B20B\n\
_080E7D68:\n\
	ldr r0, _080E7D78 @ =gSystemSavedataManager\n\
	adds r0, #0x4b\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080E7D80\n\
	ldr r1, _080E7D7C @ =0x0000B00B\n\
	b _080E7D86\n\
	.align 2, 0\n\
_080E7D78: .4byte gSystemSavedataManager\n\
_080E7D7C: .4byte 0x0000B00B\n\
_080E7D80:\n\
	cmp r0, #1\n\
	bne _080E7D94\n\
	ldr r1, _080E7D90 @ =0x0000B10B\n\
_080E7D86:\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _080E7DA0\n\
	.align 2, 0\n\
_080E7D90: .4byte 0x0000B10B\n\
_080E7D94:\n\
	cmp r0, #2\n\
	bne _080E7DA0\n\
	ldr r1, _080E7E00 @ =0x0000B20B\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
_080E7DA0:\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
_080E7DA6:\n\
	ldr r0, _080E7E04 @ =gStageDiskManager\n\
	ldr r0, [r0]\n\
	ldrb r2, [r4, #0x10]\n\
	lsrs r1, r2, #2\n\
	adds r0, r0, r1\n\
	ldrb r1, [r0]\n\
	movs r0, #3\n\
	ands r0, r2\n\
	adds r0, #4\n\
	asrs r1, r0\n\
	movs r0, #1\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _080E7DC6\n\
	movs r0, #2\n\
	strb r0, [r4, #0xd]\n\
_080E7DC6:\n\
	ldrb r3, [r4, #0xd]\n\
	cmp r3, #1\n\
	bne _080E7DEA\n\
	ldr r0, _080E7E04 @ =gStageDiskManager\n\
	ldr r0, [r0]\n\
	ldrb r2, [r4, #0x10]\n\
	lsrs r1, r2, #2\n\
	adds r0, r0, r1\n\
	ldrb r1, [r0]\n\
	movs r0, #3\n\
	ands r0, r2\n\
	adds r0, #4\n\
	asrs r1, r0\n\
	ands r1, r3\n\
	cmp r1, #0\n\
	beq _080E7DEA\n\
	movs r0, #2\n\
	strb r0, [r4, #0xd]\n\
_080E7DEA:\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #2\n\
	bne _080E7E32\n\
	ldr r0, _080E7E08 @ =gSystemSavedataManager\n\
	adds r0, #0x4b\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080E7E0C\n\
	movs r1, #0xfe\n\
	lsls r1, r1, #7\n\
	b _080E7E12\n\
	.align 2, 0\n\
_080E7E00: .4byte 0x0000B20B\n\
_080E7E04: .4byte gStageDiskManager\n\
_080E7E08: .4byte gSystemSavedataManager\n\
_080E7E0C:\n\
	cmp r0, #1\n\
	bne _080E7E20\n\
	ldr r1, _080E7E1C @ =0x00007F01\n\
_080E7E12:\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _080E7E2C\n\
	.align 2, 0\n\
_080E7E1C: .4byte 0x00007F01\n\
_080E7E20:\n\
	cmp r0, #2\n\
	bne _080E7E2C\n\
	ldr r1, _080E7E40 @ =0x00007F02\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
_080E7E2C:\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
_080E7E32:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E7E40: .4byte 0x00007F02\n\
   .syntax divided\n");
}

static void DiskIcon_Die(struct Widget *w) { SET_WIDGET_ROUTINE(w, ENTITY_EXIT); }
