#include "game.h"
#include "global.h"
#include "widget.h"

static const u8 u8_ARRAY_08372198[CYBERELF_LENGTH];

static void ElfIcon_Init(struct Widget *w);
static void ElfIcon_Update(struct Widget *w);
static void ElfIcon_Die(struct Widget *w);

// clang-format off
const WidgetRoutine gElfIconRoutine = {
    [ENTITY_INIT] =      ElfIcon_Init,
    [ENTITY_UPDATE] =    ElfIcon_Update,
    [ENTITY_DIE] =       ElfIcon_Die,
    [ENTITY_DISAPPEAR] = DeleteWidget,
    [ENTITY_EXIT] =      (WidgetFunc)DeleteEntity,
};
// clang-format on

struct Widget *CreateElfIcon(struct GameState *g) {
  struct Widget *w = (struct Widget *)AllocEntityFirst(gWidgetHeaderPtr);
  if (w != NULL) {
    (w->s).taskCol = 16;
    INIT_WIDGET_ROUTINE(w, 11);
    (w->s).tileNum = 0;
    (w->s).palID = 0;
    (w->s).unk_28 = (struct Entity *)g;
    (w->s).work[0] = 0;
    (w->s).work[1] = 0;
  }
  return w;
}

static void ElfIcon_Init(struct Widget *w) {
  SET_WIDGET_ROUTINE(w, ENTITY_UPDATE);
  wStaticGraphicTilenums[143] = 863;
  wStaticMotionPalIDs[143] = 11;
  InitNonAffineMotion(&w->s);
  (w->s).flags |= FLIPABLE;
  SetMotion(&w->s, MOTION(0x8F, 0x00));
  (w->s).spr.xflip = FALSE;
  (w->s).spr.oam.xflip = FALSE;
  (w->s).flags &= ~X_FLIP;
  (w->s).coord.x = PIXEL(404);
  (w->s).coord.y = PIXEL(19);
  ElfIcon_Update(w);
}

NAKED static void ElfIcon_Update(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r4, r0, #0\n\
	ldr r7, [r4, #0x28]\n\
	ldr r1, _080E7F6C @ =0x000064AC\n\
	adds r0, r7, r1\n\
	ldr r0, [r0]\n\
	mov r8, r0\n\
	ldr r2, _080E7F70 @ =0x00000DFC\n\
	adds r5, r7, r2\n\
	ldrb r0, [r5, #0xf]\n\
	movs r6, #0xfc\n\
	ands r6, r0\n\
	cmp r6, #0\n\
	beq _080E7F78\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080E7F74 @ =gWidgetFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
	b _080E81E0\n\
	.align 2, 0\n\
_080E7F6C: .4byte 0x000064AC\n\
_080E7F70: .4byte 0x00000DFC\n\
_080E7F74: .4byte gWidgetFnTable\n\
_080E7F78:\n\
	adds r0, r4, #0\n\
	movs r1, #0xb\n\
	bl ForceEntityPalette\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #1\n\
	bne _080E7F88\n\
	b _080E8118\n\
_080E7F88:\n\
	cmp r0, #1\n\
	bgt _080E7F92\n\
	cmp r0, #0\n\
	beq _080E7FA0\n\
	b _080E81E0\n\
_080E7F92:\n\
	cmp r0, #2\n\
	bne _080E7F98\n\
	b _080E81A4\n\
_080E7F98:\n\
	cmp r0, #3\n\
	bne _080E7F9E\n\
	b _080E81C2\n\
_080E7F9E:\n\
	b _080E81E0\n\
_080E7FA0:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldrb r0, [r7, #3]\n\
	cmp r0, #0\n\
	bne _080E8050\n\
	ldrb r0, [r5, #7]\n\
	cmp r0, #0\n\
	bne _080E7FBE\n\
	mov r2, r8\n\
	adds r2, #0xb4\n\
	ldrb r0, [r2]\n\
	cmp r0, #0xff\n\
	bne _080E7FD6\n\
_080E7FBE:\n\
	ldr r0, _080E8038 @ =0x00000DFC\n\
	adds r5, r7, r0\n\
	ldrb r0, [r5, #7]\n\
	cmp r0, #1\n\
	beq _080E7FCA\n\
	b _080E81E0\n\
_080E7FCA:\n\
	mov r2, r8\n\
	adds r2, #0xb4\n\
	ldrb r0, [r2, #1]\n\
	cmp r0, #0xff\n\
	bne _080E7FD6\n\
	b _080E81E0\n\
_080E7FD6:\n\
	adds r3, r0, #0\n\
	ldr r2, _080E803C @ =u8_ARRAY_08372198\n\
	adds r2, r3, r2\n\
	ldr r0, _080E8040 @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	adds r0, r0, r3\n\
	ldr r1, [r0]\n\
	lsls r1, r1, #0x1b\n\
	lsrs r1, r1, #0x1e\n\
	ldrb r0, [r2]\n\
	subs r0, r0, r1\n\
	strb r0, [r4, #0x10]\n\
	ldrb r1, [r4, #0x10]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r1, _080E8044 @ =gElfMugshotGraphics\n\
	adds r0, r0, r1\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	ldr r1, _080E8048 @ =0x0000035F\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl RequestGraphicTransfer\n\
	ldrb r1, [r4, #0x10]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r1, _080E804C @ =gElfMugshotGraphics+12\n\
	adds r0, r0, r1\n\
	ldrb r2, [r0, #7]\n\
	movs r1, #0xb\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	bl LoadPalette\n\
	ldrb r0, [r5, #7]\n\
	strb r0, [r4, #0x10]\n\
	movs r0, #3\n\
	strb r0, [r4, #0xd]\n\
	b _080E81E0\n\
	.align 2, 0\n\
_080E8038: .4byte 0x00000DFC\n\
_080E803C: .4byte u8_ARRAY_08372198\n\
_080E8040: .4byte gUnlockedElfPtr\n\
_080E8044: .4byte gElfMugshotGraphics\n\
_080E8048: .4byte 0x0000035F\n\
_080E804C: .4byte gElfMugshotGraphics+12\n\
_080E8050:\n\
	cmp r0, #2\n\
	bne _080E80AC\n\
	ldrb r0, [r5, #8]\n\
	strb r0, [r4, #0x10]\n\
	ldrb r1, [r5, #8]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r1, _080E80A0 @ =0x08636280\n\
	adds r0, r0, r1\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	ldr r1, _080E80A4 @ =0x0000035F\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl RequestGraphicTransfer\n\
	ldrb r1, [r5, #8]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r1, _080E80A8 @ =0x0863628C\n\
	adds r0, r0, r1\n\
	ldrb r2, [r0, #7]\n\
	movs r1, #0xb\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	bl LoadPalette\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #2\n\
	strb r0, [r4, #0xd]\n\
	b _080E81E0\n\
	.align 2, 0\n\
_080E80A0: .4byte 0x08636280\n\
_080E80A4: .4byte 0x0000035F\n\
_080E80A8: .4byte 0x0863628C\n\
_080E80AC:\n\
	cmp r0, #3\n\
	beq _080E80B2\n\
	b _080E81E0\n\
_080E80B2:\n\
	ldrb r0, [r5, #9]\n\
	adds r0, r5, r0\n\
	ldrb r3, [r0]\n\
	ldr r2, _080E8178 @ =u8_ARRAY_08372198\n\
	adds r2, r3, r2\n\
	ldr r0, _080E817C @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	adds r0, r0, r3\n\
	ldr r1, [r0]\n\
	lsls r1, r1, #0x1b\n\
	lsrs r1, r1, #0x1e\n\
	ldrb r0, [r2]\n\
	subs r0, r0, r1\n\
	strb r0, [r4, #0x10]\n\
	cmp r3, #0xff\n\
	bne _080E80D4\n\
	b _080E81E0\n\
_080E80D4:\n\
	ldrb r1, [r4, #0x10]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r1, _080E8180 @ =gElfMugshotGraphics\n\
	adds r0, r0, r1\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	ldr r1, _080E8184 @ =0x0000035F\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl RequestGraphicTransfer\n\
	ldrb r1, [r4, #0x10]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r1, _080E8188 @ =gElfMugshotGraphics+12\n\
	adds r0, r0, r1\n\
	ldrb r2, [r0, #7]\n\
	movs r1, #0xb\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	bl LoadPalette\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
_080E8118:\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #1\n\
	orrs r1, r0\n\
	strb r1, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r7, #3]\n\
	cmp r0, #3\n\
	bne _080E819E\n\
	ldr r1, _080E818C @ =0x00000DFC\n\
	adds r0, r7, r1\n\
	ldrb r1, [r0, #9]\n\
	adds r0, r0, r1\n\
	ldrb r3, [r0]\n\
	ldr r0, _080E8178 @ =u8_ARRAY_08372198\n\
	adds r0, r3, r0\n\
	ldrb r1, [r0]\n\
	ldr r0, _080E817C @ =gUnlockedElfPtr\n\
	ldr r2, [r0]\n\
	adds r2, r2, r3\n\
	ldr r0, [r2]\n\
	lsls r0, r0, #0x1b\n\
	lsrs r0, r0, #0x1e\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #0x10\n\
	lsrs r5, r1, #0x10\n\
	ldrb r1, [r2]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080E8198\n\
	mov r0, r8\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0x1a]\n\
	cmp r0, #2\n\
	bne _080E8190\n\
	adds r0, r3, #0\n\
	bl FUN_080e1cac\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080E8198\n\
	adds r0, r4, #0\n\
	movs r1, #0xc\n\
	bl ForceEntityPalette\n\
	b _080E8198\n\
	.align 2, 0\n\
_080E8178: .4byte u8_ARRAY_08372198\n\
_080E817C: .4byte gUnlockedElfPtr\n\
_080E8180: .4byte gElfMugshotGraphics\n\
_080E8184: .4byte 0x0000035F\n\
_080E8188: .4byte gElfMugshotGraphics+12\n\
_080E818C: .4byte 0x00000DFC\n\
_080E8190:\n\
	adds r0, r4, #0\n\
	movs r1, #0xc\n\
	bl ForceEntityPalette\n\
_080E8198:\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, r5\n\
	beq _080E81E0\n\
_080E819E:\n\
	movs r0, #0\n\
	strb r0, [r4, #0xd]\n\
	b _080E81E0\n\
_080E81A4:\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #1\n\
	orrs r1, r0\n\
	strb r1, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r7, #3]\n\
	cmp r0, #2\n\
	bne _080E81DE\n\
	ldrb r0, [r4, #0x10]\n\
	ldrb r5, [r5, #8]\n\
	cmp r0, r5\n\
	beq _080E81E0\n\
	b _080E81DE\n\
_080E81C2:\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #1\n\
	orrs r1, r0\n\
	strb r1, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r4, #0x10]\n\
	ldrb r5, [r5, #7]\n\
	cmp r0, r5\n\
	bne _080E81DE\n\
	ldrb r0, [r7, #3]\n\
	cmp r0, #0\n\
	beq _080E81E0\n\
_080E81DE:\n\
	strb r6, [r4, #0xd]\n\
_080E81E0:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void ElfIcon_Die(struct Widget *w) { SET_WIDGET_ROUTINE(w, ENTITY_EXIT); }

static const u8 u8_ARRAY_08372198[CYBERELF_LENGTH] = {
    2, 4, 4, 4, 4, 6, 6, 47, 47, 4, 4, 4, 4, 4, 4, 4, 4, 10, 10, 10, 10, 10, 10, 6, 6, 12, 12, 15, 17, 19, 21, 23, 24, 24, 25, 25, 26, 26, 27, 27, 30, 31, 33, 33, 33, 33, 33, 33, 34, 34, 34, 34, 35, 36, 36, 36, 36, 36, 38, 38, 38, 39, 39, 39, 39, 39, 41, 41, 41, 42, 42, 42, 42, 42,
};
