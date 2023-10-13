#include "blink.h"
#include "game.h"
#include "gfx.h"
#include "global.h"
#include "menu.h"

static void KcMenuLoop_Init(struct GameState *g);
static void KcMenuLoop_Update(struct GameState *g);
static void KcMenuLoop_SlideOut(struct GameState *g);
static void KcMenuLoop_Exit(struct GameState *g);

// 01 02 xx xx (BYTE[0x02031978] = 2)
const MenuLoopFunc KeyConfigMenuLoops[4] = {
    KcMenuLoop_Init,
    KcMenuLoop_Update,
    KcMenuLoop_SlideOut,
    KcMenuLoop_Exit,
};

const u8 u8_ARRAY_ARRAY_08386450[3][3] = {
    {5, 6, 6},
    {6, 5, 6},
    {6, 6, 5},
};

const u8 u8_ARRAY_ARRAY_08386459[6][4] = {
    {5, 5, 5, 5}, {5, 6, 6, 6}, {6, 5, 6, 6}, {6, 6, 5, 6}, {6, 6, 6, 5}, {5, 5, 5, 5},
};

// ------------------------------------------------------------------------------------------------------------------------------------

void EachMenuLoop_KeyConfig(struct GameState *g) {
  (KeyConfigMenuLoops[g->mode[2]])(g);
  return;
}

NAKED static void KcMenuLoop_Init(struct GameState *g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov r6, r8\n\
	push {r6}\n\
	adds r5, r0, #0\n\
	ldr r0, _080F5B6C @ =0x00000DF8\n\
	adds r0, r0, r5\n\
	mov r8, r0\n\
	movs r0, #0\n\
	mov r1, r8\n\
	strb r0, [r1]\n\
	ldr r0, _080F5B70 @ =gGraphic_Capcom+(22*20)\n\
	ldr r6, _080F5B74 @ =gVideoRegBuffer+6\n\
	ldrh r2, [r6]\n\
	movs r1, #0xc\n\
	ands r1, r2\n\
	lsls r1, r1, #0xc\n\
	bl LoadGraphic\n\
	ldr r0, _080F5B78 @ =gGraphic_Capcom+(22*20)+12\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r0, _080F5B7C @ =0x085222F8\n\
	ldr r0, [r0]\n\
	ldr r1, _080F5B80 @ =gBgMapOffsets+(24*4)\n\
	adds r0, r0, r1\n\
	ldr r1, _080F5B84 @ =0x00000ED8\n\
	adds r4, r5, r1\n\
	movs r2, #0xf0\n\
	lsls r2, r2, #1\n\
	adds r1, r4, #0\n\
	bl CpuFastSet\n\
	adds r0, r5, #0\n\
	adds r1, r4, #0\n\
	bl FUN_080f614c\n\
	movs r0, #0x43\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x43\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #0x43\n\
	bl ClearBlink\n\
	movs r0, #0x44\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x40\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x40\n\
	mov r1, r8\n\
	strb r0, [r1, #1]\n\
	ldrh r0, [r6]\n\
	movs r1, #0xf8\n\
	lsls r1, r1, #5\n\
	ands r1, r0\n\
	lsls r1, r1, #3\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
	adds r0, r4, #0\n\
	bl RequestBgMapTransfer\n\
	movs r0, #2\n\
	strb r0, [r5, #2]\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F5B6C: .4byte 0x00000DF8\n\
_080F5B70: .4byte gGraphic_Capcom+(22*20)\n\
_080F5B74: .4byte gVideoRegBuffer+6\n\
_080F5B78: .4byte gGraphic_Capcom+(22*20)+12\n\
_080F5B7C: .4byte gBgMapOffsets+(22*4)\n\
_080F5B80: .4byte gBgMapOffsets+(24*4)\n\
_080F5B84: .4byte 0x00000ED8\n\
 .syntax divided\n");
}

NAKED static void KcMenuLoop_Update(struct GameState *g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	mov r8, r0\n\
	ldr r0, _080F5C0C @ =0x000064AC\n\
	add r0, r8\n\
	ldr r5, [r0]\n\
	ldr r4, _080F5C10 @ =0x00000DF8\n\
	add r4, r8\n\
	ldrb r0, [r4]\n\
	subs r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #3\n\
	bls _080F5BB6\n\
	mov r0, r8\n\
	bl TrySlideMenu\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _080F5BB6\n\
	b _080F6024\n\
_080F5BB6:\n\
	ldrb r0, [r4]\n\
	mov sb, r0\n\
	movs r7, #0\n\
	ldr r6, _080F5C14 @ =gJoypad\n\
	ldrh r1, [r6, #4]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5BDA\n\
	mov r0, sb\n\
	adds r0, #5\n\
	movs r1, #6\n\
	bl __modsi3\n\
	strb r0, [r4]\n\
	movs r0, #1\n\
	bl PlaySound\n\
_080F5BDA:\n\
	ldrh r1, [r6, #4]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5BF8\n\
	ldrb r0, [r4]\n\
	adds r0, #1\n\
	movs r1, #6\n\
	bl __modsi3\n\
	strb r0, [r4]\n\
	movs r7, #5\n\
	movs r0, #1\n\
	bl PlaySound\n\
_080F5BF8:\n\
	ldrb r0, [r4]\n\
	cmp r0, #5\n\
	bls _080F5C00\n\
	b _080F5F8A\n\
_080F5C00:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080F5C18 @ =_080F5C1C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080F5C0C: .4byte 0x000064AC\n\
_080F5C10: .4byte 0x00000DF8\n\
_080F5C14: .4byte gJoypad\n\
_080F5C18: .4byte _080F5C1C\n\
_080F5C1C: @ jump table\n\
	.4byte _080F5C34 @ case 0\n\
	.4byte _080F5D04 @ case 1\n\
	.4byte _080F5D74 @ case 2\n\
	.4byte _080F5DF6 @ case 3\n\
	.4byte _080F5E98 @ case 4\n\
	.4byte _080F5F44 @ case 5\n\
_080F5C34:\n\
	ldr r0, _080F5C58 @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5C5C\n\
	adds r4, r5, #0\n\
	adds r4, #0xd8\n\
	ldrb r0, [r4]\n\
	adds r0, #1\n\
	movs r1, #3\n\
	bl __modsi3\n\
	strb r0, [r4]\n\
	movs r0, #1\n\
	bl PlaySound\n\
	b _080F5C7A\n\
	.align 2, 0\n\
_080F5C58: .4byte gJoypad\n\
_080F5C5C:\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	adds r4, r5, #0\n\
	adds r4, #0xd8\n\
	cmp r0, #0\n\
	beq _080F5C7A\n\
	ldrb r0, [r4]\n\
	adds r0, #2\n\
	movs r1, #3\n\
	bl __modsi3\n\
	strb r0, [r4]\n\
	movs r0, #1\n\
	bl PlaySound\n\
_080F5C7A:\n\
	adds r2, r5, #0\n\
	adds r2, #0xb4\n\
	ldrb r4, [r4]\n\
	cmp r4, #0\n\
	bne _080F5CB0\n\
	movs r2, #0x87\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #1\n\
	strh r0, [r1]\n\
	ldr r3, _080F5CAC @ =0x0000021E\n\
	adds r1, r5, r3\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	strh r0, [r1]\n\
	adds r0, #0x20\n\
	adds r1, r5, r0\n\
	movs r0, #2\n\
	strh r0, [r1]\n\
	adds r2, #6\n\
	adds r1, r5, r2\n\
	adds r0, #0xfe\n\
	strh r0, [r1]\n\
	b _080F5F8A\n\
	.align 2, 0\n\
_080F5CAC: .4byte 0x0000021E\n\
_080F5CB0:\n\
	cmp r4, #1\n\
	bne _080F5CE0\n\
	movs r3, #0x87\n\
	lsls r3, r3, #2\n\
	adds r0, r5, r3\n\
	strh r4, [r0]\n\
	ldr r0, _080F5CDC @ =0x0000021E\n\
	adds r1, r5, r0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	strh r0, [r1]\n\
	movs r2, #0x88\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #2\n\
	strh r0, [r1]\n\
	adds r3, #6\n\
	adds r1, r5, r3\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	strh r0, [r1]\n\
	b _080F5F8A\n\
	.align 2, 0\n\
_080F5CDC: .4byte 0x0000021E\n\
_080F5CE0:\n\
	ldrh r1, [r2, #0x1c]\n\
	movs r3, #0x87\n\
	lsls r3, r3, #2\n\
	adds r0, r5, r3\n\
	strh r1, [r0]\n\
	ldrh r1, [r2, #0x1e]\n\
	adds r3, #2\n\
	adds r0, r5, r3\n\
	strh r1, [r0]\n\
	ldrh r1, [r2, #0x20]\n\
	adds r3, #2\n\
	adds r0, r5, r3\n\
	strh r1, [r0]\n\
	ldrh r1, [r2, #0x22]\n\
	ldr r2, _080F5D00 @ =0x00000222\n\
	b _080F5F2E\n\
	.align 2, 0\n\
_080F5D00: .4byte 0x00000222\n\
_080F5D04:\n\
	adds r0, r5, #0\n\
	adds r0, #0xd8\n\
	ldrb r2, [r0]\n\
	adds r4, r5, #0\n\
	adds r4, #0xb4\n\
	cmp r2, #2\n\
	beq _080F5D14\n\
	b _080F5F38\n\
_080F5D14:\n\
	ldrh r6, [r4, #0x20]\n\
	ldr r0, _080F5D28 @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r3, #1\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5D2C\n\
	strh r3, [r4, #0x20]\n\
	b _080F5D42\n\
	.align 2, 0\n\
_080F5D28: .4byte gJoypad\n\
_080F5D2C:\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F5D40\n\
	movs r2, #0x80\n\
	lsls r2, r2, #1\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5D4A\n\
_080F5D40:\n\
	strh r2, [r4, #0x20]\n\
_080F5D42:\n\
	movs r0, #2\n\
	bl PlaySound\n\
	b _080F5D5E\n\
_080F5D4A:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5D5E\n\
	strh r2, [r4, #0x20]\n\
	movs r0, #2\n\
	bl PlaySound\n\
_080F5D5E:\n\
	ldrh r0, [r4, #0x1c]\n\
	ldrh r3, [r4, #0x20]\n\
	cmp r0, r3\n\
	bne _080F5D68\n\
	strh r6, [r4, #0x1c]\n\
_080F5D68:\n\
	ldrh r0, [r4, #0x1e]\n\
	ldrh r1, [r4, #0x20]\n\
	cmp r0, r1\n\
	bne _080F5E66\n\
	strh r6, [r4, #0x1e]\n\
	b _080F5E66\n\
_080F5D74:\n\
	adds r0, r5, #0\n\
	adds r0, #0xd8\n\
	ldrb r2, [r0]\n\
	adds r4, r5, #0\n\
	adds r4, #0xb4\n\
	cmp r2, #2\n\
	beq _080F5D84\n\
	b _080F5F38\n\
_080F5D84:\n\
	ldrh r6, [r4, #0x1c]\n\
	ldr r0, _080F5D98 @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r3, #1\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5D9C\n\
	strh r3, [r4, #0x1c]\n\
	b _080F5DB2\n\
	.align 2, 0\n\
_080F5D98: .4byte gJoypad\n\
_080F5D9C:\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F5DB0\n\
	movs r2, #0x80\n\
	lsls r2, r2, #1\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5DBA\n\
_080F5DB0:\n\
	strh r2, [r4, #0x1c]\n\
_080F5DB2:\n\
	movs r0, #2\n\
	bl PlaySound\n\
	b _080F5DCE\n\
_080F5DBA:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5DCE\n\
	strh r2, [r4, #0x1c]\n\
	movs r0, #2\n\
	bl PlaySound\n\
_080F5DCE:\n\
	ldrh r0, [r4, #0x1e]\n\
	ldrh r1, [r4, #0x1c]\n\
	cmp r0, r1\n\
	bne _080F5DD8\n\
	strh r6, [r4, #0x1e]\n\
_080F5DD8:\n\
	ldrh r2, [r4, #0x1c]\n\
	ldrh r0, [r4, #0x20]\n\
	adds r1, r2, #0\n\
	cmp r0, r1\n\
	bne _080F5DE4\n\
	strh r6, [r4, #0x20]\n\
_080F5DE4:\n\
	ldrh r0, [r4, #0x22]\n\
	cmp r0, r1\n\
	bne _080F5DEC\n\
	strh r6, [r4, #0x22]\n\
_080F5DEC:\n\
	movs r3, #0x87\n\
	lsls r3, r3, #2\n\
	adds r0, r5, r3\n\
	strh r2, [r0]\n\
	b _080F5F1A\n\
_080F5DF6:\n\
	adds r0, r5, #0\n\
	adds r0, #0xd8\n\
	ldrb r2, [r0]\n\
	adds r4, r5, #0\n\
	adds r4, #0xb4\n\
	cmp r2, #2\n\
	beq _080F5E06\n\
	b _080F5F38\n\
_080F5E06:\n\
	ldrh r6, [r4, #0x1e]\n\
	ldr r0, _080F5E1C @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r3, #1\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5E20\n\
	strh r3, [r4, #0x1e]\n\
	b _080F5E36\n\
	.align 2, 0\n\
_080F5E1C: .4byte gJoypad\n\
_080F5E20:\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F5E34\n\
	movs r2, #0x80\n\
	lsls r2, r2, #1\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5E3E\n\
_080F5E34:\n\
	strh r2, [r4, #0x1e]\n\
_080F5E36:\n\
	movs r0, #2\n\
	bl PlaySound\n\
	b _080F5E52\n\
_080F5E3E:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5E52\n\
	strh r2, [r4, #0x1e]\n\
	movs r0, #2\n\
	bl PlaySound\n\
_080F5E52:\n\
	ldrh r0, [r4, #0x1c]\n\
	ldrh r3, [r4, #0x1e]\n\
	cmp r0, r3\n\
	bne _080F5E5C\n\
	strh r6, [r4, #0x1c]\n\
_080F5E5C:\n\
	ldrh r0, [r4, #0x20]\n\
	ldrh r1, [r4, #0x1e]\n\
	cmp r0, r1\n\
	bne _080F5E66\n\
	strh r6, [r4, #0x20]\n\
_080F5E66:\n\
	ldrh r0, [r4, #0x22]\n\
	cmp r0, r1\n\
	bne _080F5E6E\n\
	strh r6, [r4, #0x22]\n\
_080F5E6E:\n\
	ldrh r1, [r4, #0x1c]\n\
	movs r2, #0x87\n\
	lsls r2, r2, #2\n\
	adds r0, r5, r2\n\
	strh r1, [r0]\n\
	ldrh r1, [r4, #0x1e]\n\
	ldr r3, _080F5E94 @ =0x0000021E\n\
	adds r0, r5, r3\n\
	strh r1, [r0]\n\
	ldrh r1, [r4, #0x20]\n\
	adds r2, #4\n\
	adds r0, r5, r2\n\
	strh r1, [r0]\n\
	ldrh r1, [r4, #0x22]\n\
	adds r3, #4\n\
	adds r0, r5, r3\n\
	strh r1, [r0]\n\
	b _080F5F8A\n\
	.align 2, 0\n\
_080F5E94: .4byte 0x0000021E\n\
_080F5E98:\n\
	adds r0, r5, #0\n\
	adds r0, #0xd8\n\
	ldrb r2, [r0]\n\
	adds r4, r5, #0\n\
	adds r4, #0xb4\n\
	cmp r2, #2\n\
	bne _080F5F38\n\
	ldrh r6, [r4, #0x22]\n\
	ldr r0, _080F5EBC @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r3, #1\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5EC0\n\
	strh r3, [r4, #0x22]\n\
	b _080F5ED6\n\
	.align 2, 0\n\
_080F5EBC: .4byte gJoypad\n\
_080F5EC0:\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F5ED4\n\
	movs r2, #0x80\n\
	lsls r2, r2, #1\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5EDE\n\
_080F5ED4:\n\
	strh r2, [r4, #0x22]\n\
_080F5ED6:\n\
	movs r0, #2\n\
	bl PlaySound\n\
	b _080F5EF2\n\
_080F5EDE:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5EF2\n\
	strh r2, [r4, #0x22]\n\
	movs r0, #2\n\
	bl PlaySound\n\
_080F5EF2:\n\
	adds r1, r4, #0\n\
	ldrh r0, [r1, #0x1c]\n\
	ldrh r2, [r1, #0x22]\n\
	cmp r0, r2\n\
	bne _080F5EFE\n\
	strh r6, [r1, #0x1c]\n\
_080F5EFE:\n\
	ldrh r0, [r1, #0x1e]\n\
	ldrh r2, [r1, #0x22]\n\
	cmp r0, r2\n\
	bne _080F5F08\n\
	strh r6, [r1, #0x1e]\n\
_080F5F08:\n\
	ldrh r0, [r1, #0x20]\n\
	cmp r0, r2\n\
	bne _080F5F10\n\
	strh r6, [r1, #0x20]\n\
_080F5F10:\n\
	ldrh r1, [r4, #0x1c]\n\
	movs r3, #0x87\n\
	lsls r3, r3, #2\n\
	adds r0, r5, r3\n\
	strh r1, [r0]\n\
_080F5F1A:\n\
	ldrh r1, [r4, #0x1e]\n\
	ldr r2, _080F5F34 @ =0x0000021E\n\
	adds r0, r5, r2\n\
	strh r1, [r0]\n\
	ldrh r1, [r4, #0x20]\n\
	adds r3, #4\n\
	adds r0, r5, r3\n\
	strh r1, [r0]\n\
	ldrh r1, [r4, #0x22]\n\
	adds r2, #4\n\
_080F5F2E:\n\
	adds r0, r5, r2\n\
	strh r1, [r0]\n\
	b _080F5F8A\n\
	.align 2, 0\n\
_080F5F34: .4byte 0x0000021E\n\
_080F5F38:\n\
	ldr r0, _080F5F40 @ =0x00000DF8\n\
	add r0, r8\n\
	strb r7, [r0]\n\
	b _080F5F8A\n\
	.align 2, 0\n\
_080F5F40: .4byte 0x00000DF8\n\
_080F5F44:\n\
	ldr r0, _080F5F68 @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5F6C\n\
	adds r4, r5, #0\n\
	adds r4, #0xd9\n\
	ldrb r0, [r4]\n\
	adds r0, #1\n\
	movs r1, #3\n\
	bl __modsi3\n\
	strb r0, [r4]\n\
	movs r0, #1\n\
	bl PlaySound\n\
	b _080F5F8A\n\
	.align 2, 0\n\
_080F5F68: .4byte gJoypad\n\
_080F5F6C:\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5F8A\n\
	adds r4, r5, #0\n\
	adds r4, #0xd9\n\
	ldrb r0, [r4]\n\
	adds r0, #2\n\
	movs r1, #3\n\
	bl __modsi3\n\
	strb r0, [r4]\n\
	movs r0, #1\n\
	bl PlaySound\n\
_080F5F8A:\n\
	ldr r1, _080F5FC8 @ =0x00000ED8\n\
	add r1, r8\n\
	mov r0, r8\n\
	bl FUN_080f614c\n\
	ldr r4, _080F5FCC @ =0x00000DF8\n\
	add r4, r8\n\
	ldrb r0, [r4]\n\
	cmp sb, r0\n\
	beq _080F5FFC\n\
	cmp r0, #5\n\
	bne _080F5FD0\n\
	ldrb r0, [r4, #1]\n\
	bl ClearBlink\n\
	movs r0, #0x42\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x42\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #0x42\n\
	bl ClearBlink\n\
	movs r0, #0x41\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x41\n\
	b _080F5FFA\n\
	.align 2, 0\n\
_080F5FC8: .4byte 0x00000ED8\n\
_080F5FCC: .4byte 0x00000DF8\n\
_080F5FD0:\n\
	mov r3, sb\n\
	cmp r3, #5\n\
	bne _080F5FFC\n\
	ldrb r0, [r4, #1]\n\
	bl ClearBlink\n\
	movs r0, #0x43\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x43\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #0x43\n\
	bl ClearBlink\n\
	movs r0, #0x40\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x40\n\
_080F5FFA:\n\
	strb r0, [r4, #1]\n\
_080F5FFC:\n\
	movs r0, #0x44\n\
	bl UpdateBlinkMotionState\n\
	ldr r0, _080F6030 @ =0x00000DF8\n\
	add r0, r8\n\
	ldrb r0, [r0, #1]\n\
	bl UpdateBlinkMotionState\n\
	ldr r0, _080F6034 @ =0x00000ED8\n\
	add r0, r8\n\
	ldr r1, _080F6038 @ =gVideoRegBuffer+6\n\
	ldrh r2, [r1]\n\
	movs r1, #0xf8\n\
	lsls r1, r1, #5\n\
	ands r1, r2\n\
	lsls r1, r1, #3\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
	bl RequestBgMapTransfer\n\
_080F6024:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F6030: .4byte 0x00000DF8\n\
_080F6034: .4byte 0x00000ED8\n\
_080F6038: .4byte gVideoRegBuffer+6\n\
 .syntax divided\n");
}

static void KcMenuLoop_SlideOut(struct GameState *g) {
  if (MENU->unk_4d == 3) {
    BGOFS(1)->x += 16;
  } else {
    BGOFS(1)->x -= 16;
  }
  BGOFS(1)->x &= 0x1FF;
  if ((BGOFS(1)->x & 0xFF) == 0) {
    MENU->unk_4c = MENU->unk_4d;
    g->mode[2] = 1;
    KcMenuLoop_Exit(g);
  }
}

static void KcMenuLoop_Exit(struct GameState *g) {
  struct KeyConfigMenuState *m;
  ClearBlink(68);

  m = &((g->sceneState).menu).kc;
  ClearBlink(m->blinkID);
}

NAKED void FUN_080f60bc(u16 *p, KEY_INPUT key, u16 r2, u8 r3) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r7, r0, #0\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	adds r6, r1, #0\n\
	lsls r2, r2, #0x10\n\
	lsrs r4, r2, #0x10\n\
	lsls r3, r3, #0x18\n\
	lsrs r5, r3, #0x18\n\
	cmp r1, #2\n\
	beq _080F60F8\n\
	cmp r1, #2\n\
	bgt _080F60DC\n\
	cmp r1, #1\n\
	beq _080F60EE\n\
	b _080F6118\n\
_080F60DC:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	cmp r6, r0\n\
	beq _080F610C\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	cmp r6, r0\n\
	beq _080F6102\n\
	b _080F6118\n\
_080F60EE:\n\
	lsls r0, r4, #1\n\
	adds r0, r0, r7\n\
	lsls r1, r5, #0xc\n\
	movs r2, #0xa1\n\
	b _080F6114\n\
_080F60F8:\n\
	lsls r0, r4, #1\n\
	adds r0, r0, r7\n\
	lsls r1, r5, #0xc\n\
	movs r2, #0xa2\n\
	b _080F6114\n\
_080F6102:\n\
	lsls r0, r4, #1\n\
	adds r0, r0, r7\n\
	lsls r1, r5, #0xc\n\
	movs r2, #0xa4\n\
	b _080F6114\n\
_080F610C:\n\
	lsls r0, r4, #1\n\
	adds r0, r0, r7\n\
	lsls r1, r5, #0xc\n\
	movs r2, #0xa5\n\
_080F6114:\n\
	orrs r1, r2\n\
	strh r1, [r0]\n\
_080F6118:\n\
	ldr r0, _080F6148 @ =0x0000013F\n\
	cmp r4, r0\n\
	bhi _080F6142\n\
	lsls r3, r4, #1\n\
	adds r3, r3, r7\n\
	lsls r2, r5, #0xc\n\
	movs r1, #0xcf\n\
	adds r0, r2, #0\n\
	orrs r0, r1\n\
	strh r0, [r3, #2]\n\
	movs r1, #0xd0\n\
	adds r0, r2, #0\n\
	orrs r0, r1\n\
	strh r0, [r3, #4]\n\
	movs r1, #0xd1\n\
	adds r0, r2, #0\n\
	orrs r0, r1\n\
	strh r0, [r3, #6]\n\
	movs r0, #0xd2\n\
	orrs r2, r0\n\
	strh r2, [r3, #8]\n\
_080F6142:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F6148: .4byte 0x0000013F\n\
 .syntax divided\n");
}

NAKED void FUN_080f614c(struct GameState *g, u16 *r1) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x14\n\
	str r0, [sp]\n\
	adds r5, r1, #0\n\
	ldr r1, _080F63C4 @ =0x000064AC\n\
	adds r0, r0, r1\n\
	ldr r6, [r0]\n\
	movs r4, #0\n\
	ldr r2, _080F63C8 @ =u8_ARRAY_ARRAY_08386459\n\
	mov sl, r2\n\
	ldr r0, _080F63CC @ =0x00000FFF\n\
	mov sb, r0\n\
	ldr r1, _080F63D0 @ =u8_ARRAY_ARRAY_08386450\n\
	mov r8, r1\n\
	movs r2, #0xd8\n\
	adds r2, r2, r6\n\
	mov ip, r2\n\
	mov r7, ip\n\
_080F6178:\n\
	lsls r3, r4, #1\n\
	adds r3, r3, r5\n\
	adds r3, #0xcc\n\
	ldrh r0, [r3]\n\
	mov r2, sb\n\
	ands r2, r0\n\
	ldrb r1, [r7]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0xc\n\
	orrs r2, r0\n\
	strh r2, [r3]\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #4\n\
	bls _080F6178\n\
	movs r4, #0\n\
	movs r0, #0xd9\n\
	adds r0, r0, r6\n\
	mov sb, r0\n\
	movs r1, #0x88\n\
	lsls r1, r1, #2\n\
	adds r1, r6, r1\n\
	str r1, [sp, #0xc]\n\
	movs r2, #0x87\n\
	lsls r2, r2, #2\n\
	adds r2, r6, r2\n\
	str r2, [sp, #4]\n\
	ldr r0, _080F63D4 @ =0x0000021E\n\
	adds r0, r6, r0\n\
	str r0, [sp, #8]\n\
	ldr r1, _080F63D8 @ =0x00000222\n\
	adds r1, r6, r1\n\
	str r1, [sp, #0x10]\n\
	ldr r2, _080F63CC @ =0x00000FFF\n\
	mov r8, r2\n\
	ldr r7, _080F63DC @ =0x08386451\n\
	mov r6, ip\n\
_080F61CA:\n\
	lsls r3, r4, #1\n\
	adds r3, r3, r5\n\
	adds r3, #0xda\n\
	ldrh r0, [r3]\n\
	mov r2, r8\n\
	ands r2, r0\n\
	ldrb r1, [r6]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	adds r0, r0, r7\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0xc\n\
	orrs r2, r0\n\
	strh r2, [r3]\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #4\n\
	bls _080F61CA\n\
	movs r4, #0\n\
	ldr r0, _080F63CC @ =0x00000FFF\n\
	mov r8, r0\n\
	ldr r7, _080F63E0 @ =0x08386452\n\
	mov r6, ip\n\
_080F61FA:\n\
	lsls r3, r4, #1\n\
	adds r3, r3, r5\n\
	adds r3, #0xe8\n\
	ldrh r0, [r3]\n\
	mov r2, r8\n\
	ands r2, r0\n\
	ldrb r1, [r6]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	adds r0, r0, r7\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0xc\n\
	orrs r2, r0\n\
	strh r2, [r3]\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #3\n\
	bls _080F61FA\n\
	movs r4, #0\n\
	ldr r1, _080F63E4 @ =0x0000030A\n\
	mov r8, r1\n\
	ldr r2, _080F63CC @ =0x00000FFF\n\
	mov ip, r2\n\
	ldr r7, _080F63D0 @ =u8_ARRAY_ARRAY_08386450\n\
	mov r6, sb\n\
_080F622E:\n\
	lsls r3, r4, #1\n\
	adds r3, r3, r5\n\
	add r3, r8\n\
	ldrh r0, [r3]\n\
	mov r2, ip\n\
	ands r2, r0\n\
	ldrb r1, [r6]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	adds r0, r0, r7\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0xc\n\
	orrs r2, r0\n\
	strh r2, [r3]\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #4\n\
	bls _080F622E\n\
	movs r4, #0\n\
	movs r0, #0xc6\n\
	lsls r0, r0, #2\n\
	mov r8, r0\n\
	ldr r1, _080F63CC @ =0x00000FFF\n\
	mov ip, r1\n\
	ldr r7, _080F63DC @ =0x08386451\n\
	mov r6, sb\n\
_080F6264:\n\
	lsls r3, r4, #1\n\
	adds r3, r3, r5\n\
	add r3, r8\n\
	ldrh r0, [r3]\n\
	mov r2, ip\n\
	ands r2, r0\n\
	ldrb r1, [r6]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	adds r0, r0, r7\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0xc\n\
	orrs r2, r0\n\
	strh r2, [r3]\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #4\n\
	bls _080F6264\n\
	movs r4, #0\n\
	ldr r2, _080F63E8 @ =0x00000326\n\
	mov r8, r2\n\
	ldr r0, _080F63CC @ =0x00000FFF\n\
	mov ip, r0\n\
	ldr r7, _080F63E0 @ =0x08386452\n\
	mov r6, sb\n\
_080F6298:\n\
	lsls r3, r4, #1\n\
	adds r3, r3, r5\n\
	add r3, r8\n\
	ldrh r0, [r3]\n\
	mov r2, ip\n\
	ands r2, r0\n\
	ldrb r1, [r6]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	adds r0, r0, r7\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0xc\n\
	orrs r2, r0\n\
	strh r2, [r3]\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #4\n\
	bls _080F6298\n\
	ldr r7, [sp, #0xc]\n\
	ldrh r1, [r7]\n\
	ldr r2, [sp]\n\
	ldr r0, _080F63EC @ =0x00000DF8\n\
	adds r4, r2, r0\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #2\n\
	add r0, sl\n\
	ldrb r3, [r0]\n\
	adds r0, r5, #0\n\
	movs r2, #0xb3\n\
	bl FUN_080f60bc\n\
	ldr r2, [sp, #4]\n\
	ldrh r1, [r2]\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #2\n\
	mov r2, sl\n\
	adds r2, #1\n\
	adds r0, r0, r2\n\
	ldrb r3, [r0]\n\
	adds r0, r5, #0\n\
	movs r2, #0xd3\n\
	bl FUN_080f60bc\n\
	ldr r0, [sp, #8]\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #2\n\
	mov r2, sl\n\
	adds r2, #2\n\
	adds r0, r0, r2\n\
	ldrb r3, [r0]\n\
	adds r0, r5, #0\n\
	movs r2, #0xf3\n\
	bl FUN_080f60bc\n\
	ldr r6, [sp, #0x10]\n\
	ldrh r1, [r6]\n\
	ldr r2, _080F63F0 @ =0x00000113\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #2\n\
	mov r3, sl\n\
	adds r3, #3\n\
	adds r0, r0, r3\n\
	ldrb r3, [r0]\n\
	adds r0, r5, #0\n\
	bl FUN_080f60bc\n\
	mov r1, sb\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	bne _080F6414\n\
	ldrh r1, [r7]\n\
	movs r2, #0xe4\n\
	lsls r2, r2, #1\n\
	adds r0, r5, #0\n\
	movs r3, #5\n\
	bl FUN_080f60bc\n\
	ldrh r1, [r6]\n\
	movs r2, #0xf3\n\
	lsls r2, r2, #1\n\
	adds r0, r5, #0\n\
	movs r3, #5\n\
	bl FUN_080f60bc\n\
	ldr r2, _080F63F4 @ =0x000003CE\n\
	adds r1, r5, r2\n\
	ldr r2, _080F63F8 @ =0x000050B9\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldrh r1, [r7]\n\
	movs r2, #0xf4\n\
	lsls r2, r2, #1\n\
	adds r0, r5, #0\n\
	movs r3, #5\n\
	bl FUN_080f60bc\n\
	ldr r0, _080F63FC @ =0x000003DE\n\
	adds r1, r5, r0\n\
	ldr r2, _080F6400 @ =0x000050C8\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r0, #0xf8\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _080F6404 @ =0x000003E2\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r0, #0xf9\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _080F6408 @ =0x000003E6\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r0, #0xfa\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _080F640C @ =0x000003EA\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r1, #0xfb\n\
	lsls r1, r1, #2\n\
	adds r0, r5, r1\n\
	subs r2, #0x2e\n\
	adds r1, r2, #0\n\
	strh r1, [r0]\n\
	ldr r2, _080F6410 @ =0x000003EE\n\
	adds r0, r5, r2\n\
	strh r1, [r0]\n\
	adds r2, #2\n\
	adds r0, r5, r2\n\
	strh r1, [r0]\n\
	b _080F6564\n\
	.align 2, 0\n\
_080F63C4: .4byte 0x000064AC\n\
_080F63C8: .4byte u8_ARRAY_ARRAY_08386459\n\
_080F63CC: .4byte 0x00000FFF\n\
_080F63D0: .4byte u8_ARRAY_ARRAY_08386450\n\
_080F63D4: .4byte 0x0000021E\n\
_080F63D8: .4byte 0x00000222\n\
_080F63DC: .4byte u8_ARRAY_ARRAY_08386450+1\n\
_080F63E0: .4byte u8_ARRAY_ARRAY_08386450+2\n\
_080F63E4: .4byte 0x0000030A\n\
_080F63E8: .4byte 0x00000326\n\
_080F63EC: .4byte 0x00000DF8\n\
_080F63F0: .4byte 0x00000113\n\
_080F63F4: .4byte 0x000003CE\n\
_080F63F8: .4byte 0x000050B9\n\
_080F63FC: .4byte 0x000003DE\n\
_080F6400: .4byte 0x000050C8\n\
_080F6404: .4byte 0x000003E2\n\
_080F6408: .4byte 0x000003E6\n\
_080F640C: .4byte 0x000003EA\n\
_080F6410: .4byte 0x000003EE\n\
_080F6414:\n\
	cmp r0, #1\n\
	bne _080F64C4\n\
	ldrh r1, [r7]\n\
	movs r2, #0xe4\n\
	lsls r2, r2, #1\n\
	adds r0, r5, #0\n\
	movs r3, #5\n\
	bl FUN_080f60bc\n\
	movs r1, #0xf3\n\
	lsls r1, r1, #2\n\
	adds r0, r5, r1\n\
	ldr r2, _080F64A8 @ =0x000050A0\n\
	adds r4, r2, #0\n\
	strh r4, [r0]\n\
	adds r1, #2\n\
	adds r0, r5, r1\n\
	strh r4, [r0]\n\
	ldrh r1, [r6]\n\
	movs r2, #0xf4\n\
	lsls r2, r2, #1\n\
	adds r0, r5, #0\n\
	movs r3, #5\n\
	bl FUN_080f60bc\n\
	ldr r2, _080F64AC @ =0x000003DE\n\
	adds r1, r5, r2\n\
	ldr r2, _080F64B0 @ =0x000050C8\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r0, #0xf8\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _080F64B4 @ =0x000003E2\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r0, #0xf9\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _080F64B8 @ =0x000003E6\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r0, #0xfa\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _080F64BC @ =0x000003EA\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r1, #0xfb\n\
	lsls r1, r1, #2\n\
	adds r0, r5, r1\n\
	strh r4, [r0]\n\
	ldr r2, _080F64C0 @ =0x000003EE\n\
	adds r0, r5, r2\n\
	strh r4, [r0]\n\
	adds r1, #4\n\
	adds r0, r5, r1\n\
	strh r4, [r0]\n\
	b _080F6564\n\
	.align 2, 0\n\
_080F64A8: .4byte 0x000050A0\n\
_080F64AC: .4byte 0x000003DE\n\
_080F64B0: .4byte 0x000050C8\n\
_080F64B4: .4byte 0x000003E2\n\
_080F64B8: .4byte 0x000003E6\n\
_080F64BC: .4byte 0x000003EA\n\
_080F64C0: .4byte 0x000003EE\n\
_080F64C4:\n\
	ldr r2, [sp, #0xc]\n\
	ldrh r1, [r2]\n\
	movs r2, #0xe4\n\
	lsls r2, r2, #1\n\
	adds r0, r5, #0\n\
	movs r3, #5\n\
	bl FUN_080f60bc\n\
	movs r1, #0xf3\n\
	lsls r1, r1, #2\n\
	adds r0, r5, r1\n\
	ldr r2, _080F6574 @ =0x000050A0\n\
	adds r1, r2, #0\n\
	strh r1, [r0]\n\
	ldr r2, _080F6578 @ =0x000003CE\n\
	adds r0, r5, r2\n\
	strh r1, [r0]\n\
	ldr r0, [sp, #0x10]\n\
	ldrh r1, [r0]\n\
	movs r2, #0xf4\n\
	lsls r2, r2, #1\n\
	adds r0, r5, #0\n\
	movs r3, #5\n\
	bl FUN_080f60bc\n\
	ldr r2, _080F657C @ =0x000003DE\n\
	adds r1, r5, r2\n\
	ldr r2, _080F6580 @ =0x000050C0\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r0, #0xf8\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _080F6584 @ =0x000003E2\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r0, #0xf9\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	subs r2, #8\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _080F6588 @ =0x000003E6\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r0, #0xfa\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _080F658C @ =0x000003EA\n\
	adds r1, r5, r0\n\
	subs r2, #7\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r0, #0xfb\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _080F6590 @ =0x000003EE\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
_080F6564:\n\
	add sp, #0x14\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F6574: .4byte 0x000050A0\n\
_080F6578: .4byte 0x000003CE\n\
_080F657C: .4byte 0x000003DE\n\
_080F6580: .4byte 0x000050C0\n\
_080F6584: .4byte 0x000003E2\n\
_080F6588: .4byte 0x000003E6\n\
_080F658C: .4byte 0x000003EA\n\
_080F6590: .4byte 0x000003EE\n\
 .syntax divided\n");
}
