#include "blink.h"
#include "game.h"
#include "global.h"
#include "widget.h"

static void MenuComp13_Init(struct Widget *w);
static void MenuComp13_Update(struct Widget *w);
static void MenuComp13_Die(struct Widget *w);

// clang-format off
const WidgetRoutine gMenuComp13Routine = {
    [ENTITY_INIT] =      MenuComp13_Init,
    [ENTITY_UPDATE] =    MenuComp13_Update,
    [ENTITY_DIE] =       MenuComp13_Die,
    [ENTITY_DISAPPEAR] = DeleteWidget,
    [ENTITY_EXIT] =      (WidgetFunc)DeleteEntity,
};
// clang-format on

struct Widget *FUN_080e83d0(void *r0, u8 r1, u8 r2, u16 r3, s32 x, s32 y, u8 r6) {
  struct Widget *w = (struct Widget *)AllocEntityFirst(gWidgetHeaderPtr);
  if (w != NULL) {
    (w->s).taskCol = 16;
    INIT_WIDGET_ROUTINE(w, 13);
    (w->s).tileNum = 0;
    (w->s).palID = 0;
    (w->s).unk_28 = (struct Entity *)r0;
    (w->s).work[0] = r1;
    (w->s).work[1] = r2;
    (w->s).coord.x = x;
    (w->s).coord.y = y;
    (w->props).w13.unk_4 = r3;
    (w->props).w13.unk_9 = r6;
    (w->props).w13.unk_b = 0;
  }
  return w;
}

struct Widget *FUN_080e844c(void *r0, u8 r1, u8 r2, u16 r3, s32 x, s32 y, u8 r6) {
  struct Widget *w = (struct Widget *)AllocEntityFirst(gWidgetHeaderPtr);
  if (w != NULL) {
    (w->s).taskCol = 16;
    INIT_WIDGET_ROUTINE(w, 13);
    (w->s).tileNum = 0;
    (w->s).palID = 0;
    (w->s).unk_28 = (struct Entity *)r0;
    (w->s).work[0] = r1;
    (w->s).work[1] = r2;
    (w->s).coord.x = x;
    (w->s).coord.y = y;
    (w->props).w13.unk_4 = r3;
    (w->props).w13.unk_9 = r6;
    (w->props).w13.unk_b = 1;
  }
  return w;
}

NAKED static void MenuComp13_Init(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x10\n\
	adds r6, r0, #0\n\
	ldr r0, [r6, #0x28]\n\
	str r0, [sp, #0xc]\n\
	ldr r1, _080E8550 @ =gWidgetFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #0xa6\n\
	bne _080E8512\n\
	ldr r0, _080E8554 @ =gSystemSavedataManager\n\
	ldrb r1, [r0, #0xc]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080E8512\n\
	adds r1, r6, #0\n\
	adds r1, #0x78\n\
	movs r0, #0xbd\n\
	lsls r0, r0, #8\n\
	strh r0, [r1]\n\
	ldr r0, [r6, #0x58]\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #3\n\
	adds r0, r0, r1\n\
	str r0, [r6, #0x58]\n\
_080E8512:\n\
	ldrb r0, [r6, #0x10]\n\
	adds r7, r6, #0\n\
	adds r7, #0x78\n\
	movs r2, #0x7d\n\
	adds r2, r2, r6\n\
	mov sl, r2\n\
	cmp r0, #0xa7\n\
	bne _080E8538\n\
	ldr r0, _080E8554 @ =gSystemSavedataManager\n\
	ldrb r1, [r0, #9]\n\
	movs r2, #2\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080E8538\n\
	ldr r0, _080E8558 @ =0x0000BB03\n\
	strh r0, [r7]\n\
	mov r3, sl\n\
	strb r2, [r3]\n\
_080E8538:\n\
	ldrh r1, [r7]\n\
	ldr r0, _080E855C @ =0x0000B00A\n\
	cmp r1, r0\n\
	bne _080E856C\n\
	ldr r0, _080E8554 @ =gSystemSavedataManager\n\
	adds r0, #0x4b\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	bne _080E8564\n\
	ldr r0, _080E8560 @ =0x0000B10A\n\
	b _080E856A\n\
	.align 2, 0\n\
_080E8550: .4byte gWidgetFnTable\n\
_080E8554: .4byte gSystemSavedataManager\n\
_080E8558: .4byte 0x0000BB03\n\
_080E855C: .4byte 0x0000B00A\n\
_080E8560: .4byte 0x0000B10A\n\
_080E8564:\n\
	cmp r0, #2\n\
	bne _080E856C\n\
	ldr r0, _080E8584 @ =0x0000B20A\n\
_080E856A:\n\
	strh r0, [r7]\n\
_080E856C:\n\
	ldrh r1, [r7]\n\
	ldr r0, _080E8588 @ =0x0000AA04\n\
	cmp r1, r0\n\
	bne _080E859C\n\
	ldr r0, _080E858C @ =gSystemSavedataManager\n\
	adds r0, #0x4a\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	bne _080E8594\n\
	ldr r0, _080E8590 @ =0x0000AB04\n\
	b _080E859A\n\
	.align 2, 0\n\
_080E8584: .4byte 0x0000B20A\n\
_080E8588: .4byte 0x0000AA04\n\
_080E858C: .4byte gSystemSavedataManager\n\
_080E8590: .4byte 0x0000AB04\n\
_080E8594:\n\
	cmp r0, #2\n\
	bne _080E859C\n\
	ldr r0, _080E863C @ =0x0000AC04\n\
_080E859A:\n\
	strh r0, [r7]\n\
_080E859C:\n\
	ldrb r0, [r6, #0x10]\n\
	subs r0, #0x14\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x49\n\
	bhi _080E865C\n\
	ldr r0, _080E8640 @ =wDynamicGraphicTilenums\n\
	movs r2, #0x8f\n\
	lsls r2, r2, #1\n\
	adds r0, r0, r2\n\
	ldrh r0, [r0]\n\
	adds r1, r6, #0\n\
	adds r1, #0x7a\n\
	strh r0, [r1]\n\
	ldr r0, _080E8644 @ =wDynamicMotionPalIDs\n\
	adds r0, r0, r2\n\
	ldrh r0, [r0]\n\
	adds r1, #4\n\
	strb r0, [r1]\n\
	ldr r0, _080E8648 @ =wStaticGraphicTilenums\n\
	adds r0, r0, r2\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #2\n\
	strh r1, [r0]\n\
	ldr r0, _080E864C @ =wStaticMotionPalIDs\n\
	adds r0, r0, r2\n\
	movs r4, #6\n\
	strh r4, [r0]\n\
	ldrh r2, [r7]\n\
	lsrs r2, r2, #8\n\
	subs r2, #0x8f\n\
	strh r2, [r7]\n\
	ldr r3, _080E8650 @ =gUnlockedElfPtr\n\
	ldrb r0, [r6, #0x10]\n\
	ldr r3, [r3]\n\
	adds r0, r0, r3\n\
	subs r0, #0x14\n\
	ldr r0, [r0]\n\
	lsls r0, r0, #0x1b\n\
	lsrs r0, r0, #0x1e\n\
	subs r2, r2, r0\n\
	strh r2, [r7]\n\
	ldrh r2, [r7]\n\
	lsls r0, r2, #2\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #2\n\
	ldr r2, _080E8654 @ =gElfMugshotGraphics\n\
	adds r0, r0, r2\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r3, #0x80\n\
	lsls r3, r3, #9\n\
	adds r1, r1, r3\n\
	bl RequestGraphicTransfer\n\
	ldrh r1, [r7]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r1, _080E8658 @ =gElfMugshotGraphics+12\n\
	adds r0, r0, r1\n\
	ldrb r1, [r0, #7]\n\
	subs r4, r4, r1\n\
	lsls r4, r4, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r4, r4, r2\n\
	adds r1, r4, #0\n\
	bl LoadPalette\n\
	movs r0, #0x8f\n\
	lsls r0, r0, #8\n\
	strh r0, [r7]\n\
	movs r3, #0x7f\n\
	adds r3, r3, r6\n\
	mov sb, r3\n\
	b _080E8794\n\
	.align 2, 0\n\
_080E863C: .4byte 0x0000AC04\n\
_080E8640: .4byte wDynamicGraphicTilenums\n\
_080E8644: .4byte wDynamicMotionPalIDs\n\
_080E8648: .4byte wStaticGraphicTilenums\n\
_080E864C: .4byte wStaticMotionPalIDs\n\
_080E8650: .4byte gUnlockedElfPtr\n\
_080E8654: .4byte gElfMugshotGraphics\n\
_080E8658: .4byte gElfMugshotGraphics+12\n\
_080E865C:\n\
	ldrb r0, [r6, #0x11]\n\
	cmp r0, #0\n\
	beq _080E86A8\n\
	ldr r2, _080E86A0 @ =wDynamicGraphicTilenums\n\
	ldrh r0, [r7]\n\
	lsrs r0, r0, #8\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrh r0, [r0]\n\
	adds r1, r6, #0\n\
	adds r1, #0x7a\n\
	strh r0, [r1]\n\
	ldr r3, _080E86A4 @ =wDynamicMotionPalIDs\n\
	ldrh r0, [r7]\n\
	lsrs r0, r0, #8\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r3\n\
	ldrh r0, [r0]\n\
	adds r1, #4\n\
	strb r0, [r1]\n\
	ldrh r0, [r7]\n\
	lsrs r0, r0, #8\n\
	lsls r0, r0, #1\n\
	adds r2, r0, r2\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #2\n\
	strh r1, [r2]\n\
	adds r0, r0, r3\n\
	movs r1, #6\n\
	strh r1, [r0]\n\
	movs r0, #0x7f\n\
	adds r0, r0, r6\n\
	mov sb, r0\n\
	b _080E8794\n\
	.align 2, 0\n\
_080E86A0: .4byte wDynamicGraphicTilenums\n\
_080E86A4: .4byte wDynamicMotionPalIDs\n\
_080E86A8:\n\
	ldr r3, _080E8730 @ =wStaticGraphicTilenums\n\
	ldrh r0, [r7]\n\
	lsrs r0, r0, #8\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r3\n\
	ldrh r0, [r0]\n\
	adds r1, r6, #0\n\
	adds r1, #0x7a\n\
	strh r0, [r1]\n\
	ldr r1, _080E8734 @ =wStaticMotionPalIDs\n\
	mov r8, r1\n\
	ldrh r0, [r7]\n\
	lsrs r0, r0, #8\n\
	lsls r0, r0, #1\n\
	add r0, r8\n\
	ldrh r0, [r0]\n\
	adds r1, r6, #0\n\
	adds r1, #0x7e\n\
	strb r0, [r1]\n\
	adds r1, #1\n\
	ldrb r0, [r1]\n\
	mov sb, r1\n\
	cmp r0, #0\n\
	beq _080E8740\n\
	ldrh r0, [r7]\n\
	lsrs r0, r0, #8\n\
	lsls r0, r0, #1\n\
	adds r2, r0, r3\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #2\n\
	strh r1, [r2]\n\
	add r0, r8\n\
	movs r1, #7\n\
	strh r1, [r0]\n\
	ldrh r4, [r7]\n\
	lsrs r4, r4, #8\n\
	lsls r5, r4, #2\n\
	adds r5, r5, r4\n\
	lsls r5, r5, #2\n\
	ldr r2, _080E8738 @ =gStaticMotionGraphics\n\
	adds r0, r5, r2\n\
	lsls r4, r4, #1\n\
	adds r1, r4, r3\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r3, #0x80\n\
	lsls r3, r3, #9\n\
	adds r1, r1, r3\n\
	bl LoadGraphic\n\
	ldr r0, _080E873C @ =gStaticMotionGraphics+12\n\
	adds r5, r5, r0\n\
	add r4, r8\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	b _080E8794\n\
	.align 2, 0\n\
_080E8730: .4byte wStaticGraphicTilenums\n\
_080E8734: .4byte wStaticMotionPalIDs\n\
_080E8738: .4byte gStaticMotionGraphics\n\
_080E873C: .4byte gStaticMotionGraphics+12\n\
_080E8740:\n\
	ldrh r0, [r7]\n\
	lsrs r0, r0, #8\n\
	lsls r0, r0, #1\n\
	adds r2, r0, r3\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #2\n\
	strh r1, [r2]\n\
	add r0, r8\n\
	movs r1, #6\n\
	strh r1, [r0]\n\
	ldrh r4, [r7]\n\
	lsrs r4, r4, #8\n\
	lsls r5, r4, #2\n\
	adds r5, r5, r4\n\
	lsls r5, r5, #2\n\
	ldr r1, _080E87B0 @ =gStaticMotionGraphics\n\
	adds r0, r5, r1\n\
	lsls r4, r4, #1\n\
	adds r1, r4, r3\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r3, _080E87B4 @ =gStaticMotionGraphics+12\n\
	adds r5, r5, r3\n\
	add r4, r8\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
_080E8794:\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #0x13\n\
	bhi _080E87C8\n\
	adds r0, r6, #0\n\
	bl InitScalerotMotion1\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #5\n\
	bhi _080E87B8\n\
	adds r0, r6, #0\n\
	adds r0, #0x50\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #1\n\
	b _080E87C0\n\
	.align 2, 0\n\
_080E87B0: .4byte gStaticMotionGraphics\n\
_080E87B4: .4byte gStaticMotionGraphics+12\n\
_080E87B8:\n\
	adds r0, r6, #0\n\
	adds r0, #0x50\n\
	movs r1, #0xf4\n\
	lsls r1, r1, #1\n\
_080E87C0:\n\
	strh r1, [r0]\n\
	adds r0, #2\n\
	strh r1, [r0]\n\
	b _080E87CE\n\
_080E87C8:\n\
	adds r0, r6, #0\n\
	bl InitNonAffineMotion\n\
_080E87CE:\n\
	ldrb r0, [r6, #0x11]\n\
	cmp r0, #0\n\
	beq _080E87DA\n\
	adds r0, r6, #0\n\
	bl ResetDynamicMotion\n\
_080E87DA:\n\
	ldrh r1, [r7]\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #2\n\
	movs r4, #0\n\
	orrs r0, r1\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	mov r2, sl\n\
	ldrb r1, [r2]\n\
	adds r1, #6\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	adds r0, r6, #0\n\
	bl ForceEntityPalette\n\
	adds r0, r6, #0\n\
	adds r0, #0x4c\n\
	strb r4, [r0]\n\
	adds r2, r6, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	adds r0, #0x4d\n\
	strb r4, [r0]\n\
	ldrb r1, [r2]\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xdf\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	adds r0, #0x7c\n\
	strb r4, [r0]\n\
	adds r0, #4\n\
	strb r4, [r0]\n\
	mov r3, sb\n\
	ldrb r2, [r3]\n\
	adds r4, r0, #0\n\
	cmp r2, #0\n\
	bne _080E8864\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #0x77\n\
	bne _080E8864\n\
	adds r1, r0, #0\n\
	ldr r3, _080E88A8 @ =0x00006401\n\
	ldr r0, [r6, #0x54]\n\
	str r0, [sp]\n\
	ldr r0, [r6, #0x58]\n\
	str r0, [sp, #4]\n\
	str r2, [sp, #8]\n\
	ldr r0, [sp, #0xc]\n\
	movs r2, #0\n\
	bl FUN_080e844c\n\
_080E8864:\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #0x74\n\
	bne _080E886E\n\
	movs r0, #0x14\n\
	strb r0, [r4]\n\
_080E886E:\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #0x73\n\
	bne _080E8878\n\
	movs r0, #0xf\n\
	strb r0, [r4]\n\
_080E8878:\n\
	ldrb r0, [r4]\n\
	cmp r0, #0\n\
	beq _080E8892\n\
	mov r2, sl\n\
	ldrb r1, [r2]\n\
	adds r1, #6\n\
	lsls r1, r1, #5\n\
	movs r3, #0x80\n\
	lsls r3, r3, #2\n\
	adds r2, r3, #0\n\
	orrs r1, r2\n\
	bl LoadBlink\n\
_080E8892:\n\
	adds r0, r6, #0\n\
	bl MenuComp13_Update\n\
	add sp, #0x10\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E88A8: .4byte 0x00006401\n\
 .syntax divided\n");
}

NAKED static void MenuComp13_Update(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldr r5, [r4, #0x28]\n\
	ldr r1, _080E88F8 @ =0x00000DCC\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0, #0xd]\n\
	cmp r0, #0\n\
	beq _080E88C0\n\
	bl _080E9504\n\
_080E88C0:\n\
	adds r1, r4, #0\n\
	adds r1, #0x80\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	beq _080E88CE\n\
	bl UpdateBlinkMotionState\n\
_080E88CE:\n\
	ldrb r0, [r5, #2]\n\
	cmp r0, #2\n\
	bne _080E88DE\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #1\n\
	bhi _080E88DE\n\
	movs r0, #3\n\
	strb r0, [r4, #0xd]\n\
_080E88DE:\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #0xb0\n\
	beq _080E88E6\n\
	b _080E8A70\n\
_080E88E6:\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0xc\n\
	bls _080E88EE\n\
	b _080E8A70\n\
_080E88EE:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080E88FC @ =_080E8900\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080E88F8: .4byte 0x00000DCC\n\
_080E88FC: .4byte _080E8900\n\
_080E8900: @ jump table\n\
	.4byte _080E8934 @ case 0\n\
	.4byte _080E893E @ case 1\n\
	.4byte _080E895E @ case 2\n\
	.4byte _080E8970 @ case 3\n\
	.4byte _080E898E @ case 4\n\
	.4byte _080E89A8 @ case 5\n\
	.4byte _080E89C2 @ case 6\n\
	.4byte _080E89D2 @ case 7\n\
	.4byte _080E89F0 @ case 8\n\
	.4byte _080E8A0C @ case 9\n\
	.4byte _080E8A30 @ case 10\n\
	.4byte _080E8A46 @ case 11\n\
	.4byte _080E8A70 @ case 12\n\
_080E8934:\n\
	movs r0, #0x20\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080E893E:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	beq _080E894E\n\
	b _080E8A70\n\
_080E894E:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #1\n\
	b _080E8A62\n\
_080E895E:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	beq _080E896A\n\
	b _080E8A70\n\
_080E896A:\n\
	movs r0, #0x10\n\
	strb r0, [r4, #0x12]\n\
	b _080E8A6A\n\
_080E8970:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080E8A70\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0x16\n\
	b _080E8A62\n\
_080E898E:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080E8A70\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0x17\n\
	b _080E8A62\n\
_080E89A8:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080E8A70\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0x18\n\
	b _080E8A62\n\
_080E89C2:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080E8A70\n\
	movs r0, #8\n\
	strb r0, [r4, #0x12]\n\
	b _080E8A6A\n\
_080E89D2:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080E8A70\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0x10\n\
	b _080E8A62\n\
_080E89F0:\n\
	adds r0, r4, #0\n\
	adds r0, #0x71\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #3\n\
	ble _080E8A70\n\
	ldr r0, [r4, #0x58]\n\
	ldr r2, _080E8A08 @ =0xFFFFE900\n\
	adds r0, r0, r2\n\
	str r0, [r4, #0x58]\n\
	b _080E8A6A\n\
	.align 2, 0\n\
_080E8A08: .4byte 0xFFFFE900\n\
_080E8A0C:\n\
	ldr r0, [r4, #0x54]\n\
	subs r0, #0x60\n\
	str r0, [r4, #0x54]\n\
	adds r0, r4, #0\n\
	adds r0, #0x71\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #4\n\
	ble _080E8A70\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, _080E8A2C @ =0xFFFFF400\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	b _080E8A6A\n\
	.align 2, 0\n\
_080E8A2C: .4byte 0xFFFFF400\n\
_080E8A30:\n\
	ldr r0, [r4, #0x54]\n\
	subs r0, #0x60\n\
	str r0, [r4, #0x54]\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080E8A70\n\
	movs r0, #0x10\n\
	strb r0, [r4, #0x12]\n\
	b _080E8A6A\n\
_080E8A46:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080E8A70\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0xa\n\
_080E8A62:\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
_080E8A6A:\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080E8A70:\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #0xb1\n\
	beq _080E8A78\n\
	b _080E8F70\n\
_080E8A78:\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0x70\n\
	bls _080E8A80\n\
	b _080E8F70\n\
_080E8A80:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080E8A8C @ =_080E8A90\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080E8A8C: .4byte _080E8A90\n\
_080E8A90: @ jump table\n\
	.4byte _080E8C54 @ case 0\n\
	.4byte _080E8C66 @ case 1\n\
	.4byte _080E8C88 @ case 2\n\
	.4byte _080E8CA4 @ case 3\n\
	.4byte _080E8CD2 @ case 4\n\
	.4byte _080E8CF0 @ case 5\n\
	.4byte _080E8D0E @ case 6\n\
	.4byte _080E8D20 @ case 7\n\
	.4byte _080E8D6C @ case 8\n\
	.4byte _080E8DA6 @ case 9\n\
	.4byte _080E8DE0 @ case 10\n\
	.4byte _080E8E18 @ case 11\n\
	.4byte _080E8F70 @ case 12\n\
	.4byte _080E8F70 @ case 13\n\
	.4byte _080E8F70 @ case 14\n\
	.4byte _080E8F70 @ case 15\n\
	.4byte _080E8F70 @ case 16\n\
	.4byte _080E8F70 @ case 17\n\
	.4byte _080E8F70 @ case 18\n\
	.4byte _080E8F70 @ case 19\n\
	.4byte _080E8F70 @ case 20\n\
	.4byte _080E8F70 @ case 21\n\
	.4byte _080E8F70 @ case 22\n\
	.4byte _080E8F70 @ case 23\n\
	.4byte _080E8F70 @ case 24\n\
	.4byte _080E8F70 @ case 25\n\
	.4byte _080E8F70 @ case 26\n\
	.4byte _080E8F70 @ case 27\n\
	.4byte _080E8F70 @ case 28\n\
	.4byte _080E8F70 @ case 29\n\
	.4byte _080E8F70 @ case 30\n\
	.4byte _080E8F70 @ case 31\n\
	.4byte _080E8F70 @ case 32\n\
	.4byte _080E8F70 @ case 33\n\
	.4byte _080E8F70 @ case 34\n\
	.4byte _080E8F70 @ case 35\n\
	.4byte _080E8F70 @ case 36\n\
	.4byte _080E8F70 @ case 37\n\
	.4byte _080E8F70 @ case 38\n\
	.4byte _080E8F70 @ case 39\n\
	.4byte _080E8F70 @ case 40\n\
	.4byte _080E8F70 @ case 41\n\
	.4byte _080E8F70 @ case 42\n\
	.4byte _080E8F70 @ case 43\n\
	.4byte _080E8F70 @ case 44\n\
	.4byte _080E8F70 @ case 45\n\
	.4byte _080E8F70 @ case 46\n\
	.4byte _080E8F70 @ case 47\n\
	.4byte _080E8F70 @ case 48\n\
	.4byte _080E8F70 @ case 49\n\
	.4byte _080E8F70 @ case 50\n\
	.4byte _080E8F70 @ case 51\n\
	.4byte _080E8F70 @ case 52\n\
	.4byte _080E8F70 @ case 53\n\
	.4byte _080E8F70 @ case 54\n\
	.4byte _080E8F70 @ case 55\n\
	.4byte _080E8F70 @ case 56\n\
	.4byte _080E8F70 @ case 57\n\
	.4byte _080E8F70 @ case 58\n\
	.4byte _080E8F70 @ case 59\n\
	.4byte _080E8F70 @ case 60\n\
	.4byte _080E8F70 @ case 61\n\
	.4byte _080E8F70 @ case 62\n\
	.4byte _080E8F70 @ case 63\n\
	.4byte _080E8F70 @ case 64\n\
	.4byte _080E8F70 @ case 65\n\
	.4byte _080E8F70 @ case 66\n\
	.4byte _080E8F70 @ case 67\n\
	.4byte _080E8F70 @ case 68\n\
	.4byte _080E8F70 @ case 69\n\
	.4byte _080E8F70 @ case 70\n\
	.4byte _080E8F70 @ case 71\n\
	.4byte _080E8F70 @ case 72\n\
	.4byte _080E8F70 @ case 73\n\
	.4byte _080E8F70 @ case 74\n\
	.4byte _080E8F70 @ case 75\n\
	.4byte _080E8F70 @ case 76\n\
	.4byte _080E8F70 @ case 77\n\
	.4byte _080E8F70 @ case 78\n\
	.4byte _080E8F70 @ case 79\n\
	.4byte _080E8F70 @ case 80\n\
	.4byte _080E8F70 @ case 81\n\
	.4byte _080E8F70 @ case 82\n\
	.4byte _080E8F70 @ case 83\n\
	.4byte _080E8F70 @ case 84\n\
	.4byte _080E8F70 @ case 85\n\
	.4byte _080E8F70 @ case 86\n\
	.4byte _080E8F70 @ case 87\n\
	.4byte _080E8F70 @ case 88\n\
	.4byte _080E8F70 @ case 89\n\
	.4byte _080E8F70 @ case 90\n\
	.4byte _080E8F70 @ case 91\n\
	.4byte _080E8F70 @ case 92\n\
	.4byte _080E8F70 @ case 93\n\
	.4byte _080E8F70 @ case 94\n\
	.4byte _080E8F70 @ case 95\n\
	.4byte _080E8F70 @ case 96\n\
	.4byte _080E8F70 @ case 97\n\
	.4byte _080E8F70 @ case 98\n\
	.4byte _080E8F70 @ case 99\n\
	.4byte _080E8E4E @ case 100\n\
	.4byte _080E8E58 @ case 101\n\
	.4byte _080E8E7A @ case 102\n\
	.4byte _080E8E96 @ case 103\n\
	.4byte _080E8EBC @ case 104\n\
	.4byte _080E8EE6 @ case 105\n\
	.4byte _080E8EBC @ case 106\n\
	.4byte _080E8EE6 @ case 107\n\
	.4byte _080E8EBC @ case 108\n\
	.4byte _080E8EE6 @ case 109\n\
	.4byte _080E8EBC @ case 110\n\
	.4byte _080E8F10 @ case 111\n\
	.4byte _080E8F4E @ case 112\n\
_080E8C54:\n\
	ldr r0, [r4, #0x54]\n\
	str r0, [r4, #0x74]\n\
	ldr r0, [r4, #0x58]\n\
	str r0, [r4, #0x68]\n\
	movs r0, #0x20\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080E8C66:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	beq _080E8C76\n\
	b _080E8F70\n\
_080E8C76:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0xc\n\
	orrs r1, r0\n\
	b _080E8F64\n\
_080E8C88:\n\
	adds r0, r4, #0\n\
	adds r0, #0x71\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bgt _080E8C98\n\
	b _080E8F70\n\
_080E8C98:\n\
	ldr r0, _080E8CA0 @ =0xFFFFFC00\n\
	str r0, [r4, #0x5c]\n\
	b _080E8F6A\n\
	.align 2, 0\n\
_080E8CA0: .4byte 0xFFFFFC00\n\
_080E8CA4:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	adds r1, #0x38\n\
	str r1, [r4, #0x5c]\n\
	cmp r1, #0x80\n\
	bgt _080E8CB6\n\
	b _080E8F70\n\
_080E8CB6:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0xd\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r0, #4\n\
	strb r0, [r4, #0x12]\n\
	b _080E8F6A\n\
_080E8CD2:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	beq _080E8CDE\n\
	b _080E8F70\n\
_080E8CDE:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0xe\n\
	orrs r1, r0\n\
	b _080E8F64\n\
_080E8CF0:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	beq _080E8CFC\n\
	b _080E8F70\n\
_080E8CFC:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0xf\n\
	orrs r1, r0\n\
	b _080E8F64\n\
_080E8D0E:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	beq _080E8D1A\n\
	b _080E8F70\n\
_080E8D1A:\n\
	movs r0, #0x10\n\
	strb r0, [r4, #0x12]\n\
	b _080E8F6A\n\
_080E8D20:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	beq _080E8D30\n\
	b _080E8F70\n\
_080E8D30:\n\
	adds r1, r4, #0\n\
	adds r1, #0x4c\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r0, [r2]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldrb r0, [r4, #0xa]\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0x11\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r0, _080E8D68 @ =0xFFFFFC00\n\
	str r0, [r4, #0x60]\n\
	b _080E8F6A\n\
	.align 2, 0\n\
_080E8D68: .4byte 0xFFFFFC00\n\
_080E8D6C:\n\
	adds r0, r4, #0\n\
	adds r0, #0x71\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bgt _080E8D7C\n\
	b _080E8F70\n\
_080E8D7C:\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, [r4, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	adds r1, #0x40\n\
	str r1, [r4, #0x60]\n\
	ldr r0, [r4, #0x54]\n\
	adds r0, #0xc0\n\
	str r0, [r4, #0x54]\n\
	cmp r1, #0\n\
	bgt _080E8D94\n\
	b _080E8F70\n\
_080E8D94:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0x12\n\
	orrs r1, r0\n\
	b _080E8F64\n\
_080E8DA6:\n\
	ldr r1, [r4, #0x58]\n\
	ldr r0, [r4, #0x60]\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x58]\n\
	adds r0, #0x40\n\
	str r0, [r4, #0x60]\n\
	ldr r0, [r4, #0x54]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #1\n\
	adds r0, r0, r2\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r4, #0x68]\n\
	cmp r1, r0\n\
	bgt _080E8DC4\n\
	b _080E8F70\n\
_080E8DC4:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0x13\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r0, [r4, #0x68]\n\
	str r0, [r4, #0x58]\n\
	b _080E8F6A\n\
_080E8DE0:\n\
	adds r0, r4, #0\n\
	adds r0, #0x71\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bgt _080E8DF0\n\
	b _080E8F70\n\
_080E8DF0:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #3\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r0, #0xc0\n\
	rsbs r0, r0, #0\n\
	str r0, [r4, #0x5c]\n\
	ldr r0, _080E8E14 @ =0xFFFFFD00\n\
	str r0, [r4, #0x60]\n\
	b _080E8F6A\n\
	.align 2, 0\n\
_080E8E14: .4byte 0xFFFFFD00\n\
_080E8E18:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	ldr r0, [r4, #0x60]\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x58]\n\
	adds r0, #0x40\n\
	str r0, [r4, #0x60]\n\
	ldr r0, [r4, #0x68]\n\
	cmp r1, r0\n\
	bgt _080E8E34\n\
	b _080E8F70\n\
_080E8E34:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r0, [r4, #0x68]\n\
	str r0, [r4, #0x58]\n\
	movs r0, #0x64\n\
	b _080E8F6E\n\
_080E8E4E:\n\
	movs r0, #8\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080E8E58:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	beq _080E8E68\n\
	b _080E8F70\n\
_080E8E68:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0x16\n\
	orrs r1, r0\n\
	b _080E8F64\n\
_080E8E7A:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080E8F70\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0x17\n\
	orrs r1, r0\n\
	b _080E8F64\n\
_080E8E96:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080E8F70\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0x18\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r0, #0x10\n\
	strb r0, [r4, #0x12]\n\
	b _080E8F6A\n\
_080E8EBC:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080E8F70\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0x19\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r0, #0x10\n\
	strb r0, [r4, #0x12]\n\
	b _080E8F6A\n\
_080E8EE6:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080E8F70\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0x18\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r0, #0x10\n\
	strb r0, [r4, #0x12]\n\
	b _080E8F6A\n\
_080E8F10:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080E8F70\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0x1a\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r1, r4, #0\n\
	adds r1, #0x4c\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	subs r0, #0x11\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	b _080E8F6A\n\
_080E8F4E:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080E8F70\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
_080E8F64:\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
_080E8F6A:\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
_080E8F6E:\n\
	strb r0, [r4, #0xe]\n\
_080E8F70:\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #0xb2\n\
	beq _080E8F78\n\
	b _080E917C\n\
_080E8F78:\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0xe\n\
	bls _080E8F80\n\
	b _080E917C\n\
_080E8F80:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080E8F8C @ =_080E8F90\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080E8F8C: .4byte _080E8F90\n\
_080E8F90: @ jump table\n\
	.4byte _080E8FCC @ case 0\n\
	.4byte _080E8FD6 @ case 1\n\
	.4byte _080E9000 @ case 2\n\
	.4byte _080E902E @ case 3\n\
	.4byte _080E905A @ case 4\n\
	.4byte _080E9080 @ case 5\n\
	.4byte _080E909A @ case 6\n\
	.4byte _080E90B4 @ case 7\n\
	.4byte _080E90CE @ case 8\n\
	.4byte _080E90E8 @ case 9\n\
	.4byte _080E90FA @ case 10\n\
	.4byte _080E9124 @ case 11\n\
	.4byte _080E9142 @ case 12\n\
	.4byte _080E9152 @ case 13\n\
	.4byte _080E917C @ case 14\n\
_080E8FCC:\n\
	movs r0, #0x18\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080E8FD6:\n\
	ldr r0, [r4, #0x54]\n\
	subs r0, #0x80\n\
	str r0, [r4, #0x54]\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	beq _080E8FEC\n\
	b _080E917C\n\
_080E8FEC:\n\
	movs r0, #0x10\n\
	strb r0, [r4, #0x12]\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #1\n\
	b _080E916E\n\
_080E9000:\n\
	ldr r0, [r4, #0x54]\n\
	subs r0, #0x40\n\
	str r0, [r4, #0x54]\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	beq _080E9016\n\
	b _080E917C\n\
_080E9016:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r0, #0x20\n\
	strb r0, [r4, #0x12]\n\
	b _080E9176\n\
_080E902E:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	beq _080E903E\n\
	b _080E917C\n\
_080E903E:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r0, #0x3c\n\
	strb r0, [r4, #0x12]\n\
	b _080E9176\n\
_080E905A:\n\
	ldr r0, [r4, #0x58]\n\
	subs r0, #0x20\n\
	str r0, [r4, #0x58]\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	beq _080E9070\n\
	b _080E917C\n\
_080E9070:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #5\n\
	b _080E916E\n\
_080E9080:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080E917C\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #9\n\
	b _080E916E\n\
_080E909A:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080E917C\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0xa\n\
	b _080E916E\n\
_080E90B4:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080E917C\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0xb\n\
	b _080E916E\n\
_080E90CE:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080E917C\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0xc\n\
	b _080E916E\n\
_080E90E8:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080E917C\n\
	movs r0, #8\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #0xd\n\
	b _080E917A\n\
_080E90FA:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080E917C\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0xe\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r0, #8\n\
	strb r0, [r4, #0x12]\n\
	b _080E9176\n\
_080E9124:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080E917C\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0xf\n\
	b _080E916E\n\
_080E9142:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080E917C\n\
	movs r0, #8\n\
	strb r0, [r4, #0x12]\n\
	b _080E9176\n\
_080E9152:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080E917C\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0x14\n\
_080E916E:\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
_080E9176:\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
_080E917A:\n\
	strb r0, [r4, #0xe]\n\
_080E917C:\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #0xb3\n\
	beq _080E9184\n\
	b _080E947E\n\
_080E9184:\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0xf\n\
	bls _080E918C\n\
	b _080E947E\n\
_080E918C:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080E9198 @ =_080E919C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080E9198: .4byte _080E919C\n\
_080E919C: @ jump table\n\
	.4byte _080E91DC @ case 0\n\
	.4byte _080E91EE @ case 1\n\
	.4byte _080E9216 @ case 2\n\
	.4byte _080E923E @ case 3\n\
	.4byte _080E928C @ case 4\n\
	.4byte _080E92C0 @ case 5\n\
	.4byte _080E92F2 @ case 6\n\
	.4byte _080E9328 @ case 7\n\
	.4byte _080E9350 @ case 8\n\
	.4byte _080E938C @ case 9\n\
	.4byte _080E93B2 @ case 10\n\
	.4byte _080E93CA @ case 11\n\
	.4byte _080E9404 @ case 12\n\
	.4byte _080E942A @ case 13\n\
	.4byte _080E9442 @ case 14\n\
	.4byte _080E947E @ case 15\n\
_080E91DC:\n\
	ldr r0, [r4, #0x54]\n\
	str r0, [r4, #0x74]\n\
	ldr r0, [r4, #0x58]\n\
	str r0, [r4, #0x68]\n\
	movs r0, #0x18\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080E91EE:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	beq _080E91FE\n\
	b _080E947E\n\
_080E91FE:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _080E9478\n\
_080E9216:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	beq _080E9222\n\
	b _080E947E\n\
_080E9222:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #2\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r0, #0\n\
	strb r0, [r4, #0x12]\n\
	b _080E9478\n\
_080E923E:\n\
	ldrb r0, [r4, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r4, #0x12]\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080E9256\n\
	ldrb r1, [r4, #0x12]\n\
	lsls r1, r1, #7\n\
	ldr r0, [r4, #0x54]\n\
	adds r0, r0, r1\n\
	b _080E925E\n\
_080E9256:\n\
	ldrb r1, [r4, #0x12]\n\
	lsls r1, r1, #7\n\
	ldr r0, [r4, #0x54]\n\
	subs r0, r0, r1\n\
_080E925E:\n\
	str r0, [r4, #0x54]\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0x78\n\
	bhi _080E9268\n\
	b _080E947E\n\
_080E9268:\n\
	ldr r0, _080E9288 @ =0xFFFFFC00\n\
	str r0, [r4, #0x5c]\n\
	movs r0, #0x28\n\
	str r0, [r4, #0x64]\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0xc\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _080E9478\n\
	.align 2, 0\n\
_080E9288: .4byte 0xFFFFFC00\n\
_080E928C:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r4, #0x64]\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x5c]\n\
	ldr r0, _080E92BC @ =0xFFFFFF00\n\
	cmp r1, r0\n\
	bgt _080E92A2\n\
	b _080E947E\n\
_080E92A2:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0xd\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _080E9478\n\
	.align 2, 0\n\
_080E92BC: .4byte 0xFFFFFF00\n\
_080E92C0:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r2, [r4, #0x5c]\n\
	adds r0, r0, r2\n\
	str r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x64]\n\
	adds r2, r2, r1\n\
	str r2, [r4, #0x5c]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	cmn r2, r0\n\
	bgt _080E92DA\n\
	b _080E947E\n\
_080E92DA:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r0, #8\n\
	strb r0, [r4, #0x12]\n\
	b _080E9478\n\
_080E92F2:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r4, #0x64]\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x5c]\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	beq _080E9310\n\
	b _080E947E\n\
_080E9310:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #3\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _080E9478\n\
_080E9328:\n\
	adds r0, r4, #0\n\
	adds r0, #0x71\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bgt _080E9338\n\
	b _080E947E\n\
_080E9338:\n\
	ldr r0, _080E934C @ =0xFFFFFC40\n\
	str r0, [r4, #0x60]\n\
	ldr r0, [r4, #0x74]\n\
	ldr r1, [r4, #0x54]\n\
	subs r0, r0, r1\n\
	movs r1, #0x1e\n\
	bl __divsi3\n\
	str r0, [r4, #0x5c]\n\
	b _080E9478\n\
	.align 2, 0\n\
_080E934C: .4byte 0xFFFFFC40\n\
_080E9350:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	ldr r0, [r4, #0x60]\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x58]\n\
	adds r0, #0x40\n\
	str r0, [r4, #0x60]\n\
	ldr r0, [r4, #0x68]\n\
	cmp r1, r0\n\
	bgt _080E936C\n\
	b _080E947E\n\
_080E936C:\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r0, [r4, #0x68]\n\
	str r0, [r4, #0x58]\n\
	movs r0, #0x20\n\
	strb r0, [r4, #0x12]\n\
	b _080E9478\n\
_080E938C:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080E947E\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0x16\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _080E9478\n\
_080E93B2:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080E947E\n\
	movs r0, #8\n\
	strb r0, [r4, #0x12]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	b _080E9478\n\
_080E93CA:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080E947E\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0x17\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, _080E9400 @ =0xFFFFE400\n\
	adds r0, r0, r1\n\
	b _080E9476\n\
	.align 2, 0\n\
_080E9400: .4byte 0xFFFFE400\n\
_080E9404:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080E947E\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0x18\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r0, #8\n\
	strb r0, [r4, #0x12]\n\
	b _080E9478\n\
_080E942A:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080E947E\n\
	movs r0, #8\n\
	strb r0, [r4, #0x12]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	b _080E9478\n\
_080E9442:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080E947E\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	movs r0, #0x19\n\
	orrs r1, r0\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r0, [r4, #0x58]\n\
	movs r2, #0xe0\n\
	lsls r2, r2, #5\n\
	adds r0, r0, r2\n\
_080E9476:\n\
	str r0, [r4, #0x58]\n\
_080E9478:\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080E947E:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #1\n\
	beq _080E94D4\n\
	cmp r0, #1\n\
	bgt _080E9494\n\
	cmp r0, #0\n\
	beq _080E94A2\n\
	b _080E949C\n\
_080E9494:\n\
	cmp r0, #2\n\
	beq _080E94E6\n\
	cmp r0, #3\n\
	beq _080E9504\n\
_080E949C:\n\
	adds r2, r4, #0\n\
	adds r2, #0x7c\n\
	b _080E9524\n\
_080E94A2:\n\
	adds r2, r4, #0\n\
	adds r2, #0x45\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r1, r4, #0\n\
	adds r1, #0x7c\n\
	ldrb r0, [r1]\n\
	adds r0, #2\n\
	strb r0, [r1]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	adds r2, r1, #0\n\
	cmp r0, #0xf\n\
	bls _080E9524\n\
	movs r0, #0x10\n\
	strb r0, [r2]\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
	b _080E9524\n\
_080E94D4:\n\
	adds r2, r4, #0\n\
	adds r2, #0x45\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	adds r2, #0x37\n\
	b _080E9524\n\
_080E94E6:\n\
	adds r2, r4, #0\n\
	adds r2, #0x45\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r1, r4, #0\n\
	adds r1, #0x7c\n\
	movs r0, #8\n\
	strb r0, [r1]\n\
	adds r2, r1, #0\n\
	b _080E9524\n\
_080E9504:\n\
	ldr r1, _080E9520 @ =gWidgetFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl MenuComp13_Die\n\
	b _080E9538\n\
	.align 2, 0\n\
_080E9520: .4byte gWidgetFnTable\n\
_080E9524:\n\
	ldr r3, _080E9540 @ =gBlendRegBuffer\n\
	ldrb r0, [r2]\n\
	movs r1, #0x1f\n\
	ands r1, r0\n\
	ldrb r2, [r2]\n\
	movs r0, #0x10\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #8\n\
	orrs r1, r0\n\
	strh r1, [r3, #2]\n\
_080E9538:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E9540: .4byte gBlendRegBuffer\n\
 .syntax divided\n");
}

static void MenuComp13_Die(struct Widget *w) {
  if ((w->s).work[1] != 0) {
    const motion_t m = (w->props).w13.unk_4;
    wDynamicGraphicTilenums[m >> 8] = (w->props).w13.tileNum;
    wDynamicMotionPalIDs[m >> 8] = (w->props).w13.palID;
  } else {
    const motion_t m = (w->props).w13.unk_4;
    wStaticGraphicTilenums[m >> 8] = (w->props).w13.tileNum;
    wStaticMotionPalIDs[m >> 8] = (w->props).w13.palID;
  }

  if ((w->props).w13.unk_c != 0) {
    ClearBlink((w->props).w13.unk_c);
  }

  (w->s).flags &= ~DISPLAY;
  SET_WIDGET_ROUTINE(w, ENTITY_EXIT);
}
