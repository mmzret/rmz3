#include "blink.h"
#include "game.h"
#include "gfx.h"
#include "global.h"
#include "menu.h"

static void ExMenuLoop_Init(struct GameState* g);
static void ExMenuLoop_Update(struct GameState* g);
static void ExMenuLoop_SlideOut(struct GameState* g);
static void ExMenuLoop_Exit(struct GameState* g);

// 01 02 xx xx (BYTE[0x02031978] = 1)
static const MenuLoopFunc ExSkillMenuLoops[4] = {
    ExMenuLoop_Init,
    ExMenuLoop_Update,
    ExMenuLoop_SlideOut,
    ExMenuLoop_Exit,
};

// ------------------------------------------------------------------------------------------------------------------------------------

void EachMenuLoop_ExSkill(struct GameState* g) {
  (ExSkillMenuLoops[g->mode[2]])(g);
  return;
}

NAKED static void ExMenuLoop_Init(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r6, r0, #0\n\
	ldr r1, _080F7AF4 @ =0x000064AC\n\
	adds r0, r6, r1\n\
	ldr r7, [r0]\n\
	movs r2, #0xdf\n\
	lsls r2, r2, #4\n\
	adds r4, r6, r2\n\
	movs r0, #0\n\
	strb r0, [r4, #4]\n\
	strb r0, [r4, #5]\n\
	ldr r0, _080F7AF8 @ =gGraphic_ExSkillMenu\n\
	ldr r5, _080F7AFC @ =gVideoRegBuffer+6\n\
	ldrh r2, [r5]\n\
	movs r1, #0xc\n\
	ands r1, r2\n\
	lsls r1, r1, #0xc\n\
	bl LoadGraphic\n\
	ldr r0, _080F7B00 @ =gGraphic_ExSkillMenu+12\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r0, _080F7B04 @ =0x085222F4\n\
	ldr r0, [r0]\n\
	ldr r1, _080F7B08 @ =0x085222FC\n\
	adds r0, r0, r1\n\
	ldr r2, _080F7B0C @ =0x000016D8\n\
	adds r1, r6, r2\n\
	movs r2, #0xf0\n\
	lsls r2, r2, #1\n\
	bl CpuFastSet\n\
	ldr r1, _080F7B10 @ =0x00000ED8\n\
	adds r0, r6, r1\n\
	ldrh r2, [r5]\n\
	movs r1, #0xf8\n\
	lsls r1, r1, #5\n\
	ands r1, r2\n\
	lsls r1, r1, #3\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
	bl RequestBgMapTransfer\n\
	movs r0, #0x3e\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x3f\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	adds r0, r6, #0\n\
	movs r1, #1\n\
	movs r2, #0\n\
	bl CreateMenuComp2\n\
	str r0, [r4]\n\
	adds r0, #0x74\n\
	movs r1, #0x8e\n\
	lsls r1, r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, [r4]\n\
	adds r0, #0x76\n\
	movs r1, #0x28\n\
	strh r1, [r0]\n\
	ldr r4, _080F7B14 @ =0x00000564\n\
	ldr r2, _080F7B18 @ =gStaticMotionGraphics\n\
	adds r0, r4, r2\n\
	ldr r1, _080F7B1C @ =wStaticGraphicTilenums\n\
	adds r1, #0x8a\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r0, _080F7B20 @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r0\n\
	ldr r0, _080F7B24 @ =wStaticMotionPalIDs\n\
	adds r0, #0x8a\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	movs r4, #0\n\
_080F7AC4:\n\
	adds r0, r7, #0\n\
	adds r0, #0xb4\n\
	ldrh r1, [r0, #0x14]\n\
	movs r0, #1\n\
	lsls r0, r4\n\
	ands r1, r0\n\
	asrs r1, r4\n\
	cmp r1, #0\n\
	beq _080F7ADE\n\
	adds r0, r6, #0\n\
	adds r1, r4, #0\n\
	bl CreateExSkillIcon\n\
_080F7ADE:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #0xb\n\
	bls _080F7AC4\n\
	movs r0, #2\n\
	strb r0, [r6, #2]\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F7AF4: .4byte 0x000064AC\n\
_080F7AF8: .4byte gGraphic_ExSkillMenu\n\
_080F7AFC: .4byte gVideoRegBuffer+6\n\
_080F7B00: .4byte gGraphic_ExSkillMenu+12\n\
_080F7B04: .4byte gBgMapOffsets+(21*4)\n\
_080F7B08: .4byte gBgMapOffsets+(23*4)\n\
_080F7B0C: .4byte 0x000016D8\n\
_080F7B10: .4byte 0x00000ED8\n\
_080F7B14: .4byte 0x00000564\n\
_080F7B18: .4byte gStaticMotionGraphics\n\
_080F7B1C: .4byte wStaticGraphicTilenums\n\
_080F7B20: .4byte gStaticMotionGraphics+12\n\
_080F7B24: .4byte wStaticMotionPalIDs\n\
 .syntax divided\n");
}

NAKED static void ExMenuLoop_Update(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r6, r0, #0\n\
	ldr r1, _080F7C14 @ =0x000064AC\n\
	adds r0, r6, r1\n\
	ldr r0, [r0]\n\
	mov r8, r0\n\
	adds r0, r6, #0\n\
	bl TrySlideMenu\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _080F7B46\n\
	b _080F7CD2\n\
_080F7B46:\n\
	movs r0, #0x3e\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #0x3f\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #0xdf\n\
	lsls r0, r0, #4\n\
	adds r4, r6, r0\n\
	ldrb r7, [r4, #4]\n\
	ldr r5, _080F7C18 @ =gJoypad\n\
	ldrh r1, [r5, #6]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F7B72\n\
	adds r0, r7, #0\n\
	adds r0, #8\n\
	movs r1, #0xc\n\
	bl __modsi3\n\
	strb r0, [r4, #4]\n\
_080F7B72:\n\
	ldrh r5, [r5, #6]\n\
	movs r0, #0x80\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	beq _080F7B88\n\
	ldrb r0, [r4, #4]\n\
	adds r0, #4\n\
	movs r1, #0xc\n\
	bl __modsi3\n\
	strb r0, [r4, #4]\n\
_080F7B88:\n\
	movs r0, #0x20\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	beq _080F7BA4\n\
	ldrb r1, [r4, #4]\n\
	lsrs r0, r1, #2\n\
	lsls r3, r0, #2\n\
	adds r2, r1, #3\n\
	adds r0, r2, #0\n\
	asrs r0, r0, #2\n\
	lsls r0, r0, #2\n\
	subs r0, r2, r0\n\
	adds r0, r3, r0\n\
	strb r0, [r4, #4]\n\
_080F7BA4:\n\
	ldr r0, _080F7C18 @ =gJoypad\n\
	ldrh r1, [r0, #6]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F7BCA\n\
	movs r1, #0xdf\n\
	lsls r1, r1, #4\n\
	adds r4, r6, r1\n\
	ldrb r1, [r4, #4]\n\
	lsrs r0, r1, #2\n\
	lsls r3, r0, #2\n\
	adds r2, r1, #1\n\
	adds r0, r2, #0\n\
	asrs r0, r0, #2\n\
	lsls r0, r0, #2\n\
	subs r0, r2, r0\n\
	adds r0, r3, r0\n\
	strb r0, [r4, #4]\n\
_080F7BCA:\n\
	movs r0, #0xdf\n\
	lsls r0, r0, #4\n\
	adds r5, r6, r0\n\
	ldrb r1, [r5, #4]\n\
	cmp r7, r1\n\
	beq _080F7BDC\n\
	movs r0, #1\n\
	bl PlaySound\n\
_080F7BDC:\n\
	ldr r0, _080F7C18 @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r2, #1\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	mov r4, r8\n\
	adds r4, #0xb4\n\
	cmp r0, #0\n\
	beq _080F7C2E\n\
	ldrh r0, [r4, #0x14]\n\
	ldrb r3, [r5, #4]\n\
	lsls r2, r3\n\
	ands r0, r2\n\
	asrs r0, r3\n\
	cmp r0, #0\n\
	beq _080F7C28\n\
	ldrh r1, [r4, #0x12]\n\
	adds r0, r1, #0\n\
	ands r0, r2\n\
	asrs r0, r3\n\
	cmp r0, #0\n\
	beq _080F7C1C\n\
	eors r1, r2\n\
	strh r1, [r4, #0x12]\n\
	movs r0, #3\n\
	bl PlaySound\n\
	b _080F7C2E\n\
	.align 2, 0\n\
_080F7C14: .4byte 0x000064AC\n\
_080F7C18: .4byte gJoypad\n\
_080F7C1C:\n\
	orrs r1, r2\n\
	strh r1, [r4, #0x12]\n\
	movs r0, #2\n\
	bl PlaySound\n\
	b _080F7C2E\n\
_080F7C28:\n\
	movs r0, #4\n\
	bl PlaySound\n\
_080F7C2E:\n\
	movs r0, #0xdf\n\
	lsls r0, r0, #4\n\
	adds r6, r6, r0\n\
	ldr r2, [r6]\n\
	ldrb r1, [r6, #4]\n\
	movs r0, #3\n\
	ands r1, r0\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #3\n\
	movs r1, #0x8e\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	adds r2, #0x74\n\
	strh r0, [r2]\n\
	ldr r2, [r6]\n\
	ldrb r1, [r6, #4]\n\
	lsrs r1, r1, #2\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #3\n\
	adds r0, #0x28\n\
	adds r2, #0x76\n\
	strh r0, [r2]\n\
	ldrh r1, [r4, #0x14]\n\
	ldrb r2, [r6, #4]\n\
	movs r0, #1\n\
	lsls r0, r2\n\
	ands r1, r0\n\
	asrs r1, r2\n\
	cmp r1, #0\n\
	beq _080F7CAC\n\
	ldr r5, _080F7CA0 @ =StringOfsTable\n\
	movs r1, #0xe1\n\
	lsls r1, r1, #1\n\
	adds r0, r2, r1\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r5\n\
	ldrh r0, [r0]\n\
	ldr r4, _080F7CA4 @ =gStringData\n\
	adds r0, r0, r4\n\
	movs r1, #2\n\
	movs r2, #0xe\n\
	bl PrintString\n\
	ldrb r0, [r6, #4]\n\
	ldr r1, _080F7CA8 @ =0x000001CF\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r5\n\
	ldrh r0, [r0]\n\
	adds r0, r0, r4\n\
	movs r1, #0x11\n\
	movs r2, #1\n\
	bl PrintString\n\
	b _080F7CD2\n\
	.align 2, 0\n\
_080F7CA0: .4byte StringOfsTable\n\
_080F7CA4: .4byte gStringData\n\
_080F7CA8: .4byte 0x000001CF\n\
_080F7CAC:\n\
	ldr r4, _080F7CDC @ =StringOfsTable\n\
	movs r1, #0xe7\n\
	lsls r1, r1, #2\n\
	adds r0, r4, r1\n\
	ldrh r0, [r0]\n\
	ldr r5, _080F7CE0 @ =gStringData\n\
	adds r0, r0, r5\n\
	movs r1, #2\n\
	movs r2, #0xe\n\
	bl PrintString\n\
	ldr r0, _080F7CE4 @ =0x000003B6\n\
	adds r4, r4, r0\n\
	ldrh r0, [r4]\n\
	adds r0, r0, r5\n\
	movs r1, #0x11\n\
	movs r2, #1\n\
	bl PrintString\n\
_080F7CD2:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F7CDC: .4byte StringOfsTable\n\
_080F7CE0: .4byte gStringData\n\
_080F7CE4: .4byte 0x000003B6\n\
 .syntax divided\n");
}

NAKED static void ExMenuLoop_SlideOut(struct GameState* g) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r1, _080F7D00 @ =0x00000E19\n\
	adds r0, r2, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #2\n\
	bne _080F7D08\n\
	ldr r1, _080F7D04 @ =gVideoRegBuffer+16\n\
	ldrh r0, [r1]\n\
	adds r0, #0x10\n\
	b _080F7D0E\n\
	.align 2, 0\n\
_080F7D00: .4byte 0x00000E19\n\
_080F7D04: .4byte gVideoRegBuffer+16\n\
_080F7D08:\n\
	ldr r1, _080F7D3C @ =gVideoRegBuffer+16\n\
	ldrh r0, [r1]\n\
	subs r0, #0x10\n\
_080F7D0E:\n\
	strh r0, [r1]\n\
	adds r3, r1, #0\n\
	ldrh r0, [r3]\n\
	ldr r1, _080F7D40 @ =0x000001FF\n\
	ands r1, r0\n\
	strh r1, [r3]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F7D38\n\
	ldr r3, _080F7D44 @ =0x00000E19\n\
	adds r0, r2, r3\n\
	ldrb r1, [r0]\n\
	subs r3, #1\n\
	adds r0, r2, r3\n\
	strb r1, [r0]\n\
	movs r0, #1\n\
	strb r0, [r2, #2]\n\
	adds r0, r2, #0\n\
	bl ExMenuLoop_Exit\n\
_080F7D38:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F7D3C: .4byte gVideoRegBuffer+16\n\
_080F7D40: .4byte 0x000001FF\n\
_080F7D44: .4byte 0x00000E19\n\
 .syntax divided\n");
}

static void ExMenuLoop_Exit(struct GameState* g) {
  struct ExSkillMenuState* m = &((g->sceneState).menu).exskill;
  m->inactive = TRUE;
  ClearBlink(0x3E);
  ClearBlink(0x3F);
  (m->w)->props.exskill.unk_004[0] = 1;
}
