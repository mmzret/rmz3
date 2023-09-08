#include "menu.h"

#include "cyberelf.h"
#include "entity.h"
#include "game.h"
#include "gfx.h"
#include "global.h"
#include "sprite.h"
#include "weapon.h"
#include "zero.h"

static void menu_080f394c(struct GameState *g);
static void menu_080f39a8(struct GameState *m);

void MainLoop_Menu(struct GameState *m) {
  (gMenuLoops[m->mode[1]])(m);
  menu_080f39a8(m);
}

// 01 00 xx xx
NAKED void MenuLoop_InitMenu(struct GameState *m) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov r6, r8\n\
	push {r6}\n\
	adds r4, r0, #0\n\
	ldr r1, _080F3690 @ =0x000064AC\n\
	adds r0, r4, r1\n\
	ldr r3, [r0]\n\
	movs r2, #0\n\
	mov r8, r2\n\
	movs r6, #0\n\
	strh r6, [r4, #4]\n\
	adds r2, r3, #0\n\
	adds r2, #0xb4\n\
	ldrb r1, [r2, #0xc]\n\
	ldr r5, _080F3694 @ =0x00000E12\n\
	adds r0, r4, r5\n\
	strb r1, [r0]\n\
	ldrb r1, [r2, #0xd]\n\
	adds r5, #1\n\
	adds r0, r4, r5\n\
	strb r1, [r0]\n\
	ldrb r1, [r2, #0xe]\n\
	adds r5, #3\n\
	adds r0, r4, r5\n\
	strb r1, [r0]\n\
	adds r3, #0xd9\n\
	ldrb r1, [r3]\n\
	ldr r3, _080F3698 @ =0x00000E1E\n\
	adds r0, r4, r3\n\
	strb r1, [r0]\n\
	ldrb r1, [r2]\n\
	subs r5, #2\n\
	adds r0, r4, r5\n\
	strb r1, [r0]\n\
	ldrb r1, [r2, #1]\n\
	ldr r2, _080F369C @ =0x00000E15\n\
	adds r0, r4, r2\n\
	strb r1, [r0]\n\
	subs r3, #2\n\
	adds r1, r4, r3\n\
	movs r0, #0xff\n\
	strb r0, [r1]\n\
	ldr r0, _080F36A0 @ =0x00000E18\n\
	adds r5, r4, r0\n\
	mov r1, r8\n\
	strb r1, [r5]\n\
	adds r0, r4, #0\n\
	bl menu_080f394c\n\
	ldr r2, _080F36A4 @ =gVideoRegBuffer\n\
	ldrh r1, [r2]\n\
	ldr r0, _080F36A8 @ =0x0000FFF8\n\
	ands r0, r1\n\
	ldr r1, _080F36AC @ =0x0000F0FF\n\
	ands r0, r1\n\
	movs r3, #0x98\n\
	lsls r3, r3, #5\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _080F36B0 @ =0x00004206\n\
	adds r0, r1, #0\n\
	strh r0, [r2, #6]\n\
	str r6, [r2, #0x10]\n\
	ldr r1, _080F36B4 @ =gEachMenuLoops\n\
	ldrb r0, [r5]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	adds r0, r4, #0\n\
	bl _call_via_r1\n\
	movs r0, #1\n\
	strb r0, [r4, #2]\n\
	strb r0, [r4, #1]\n\
	adds r0, r4, #0\n\
	bl MenuLoop_OpenMenu\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F3690: .4byte 0x000064AC\n\
_080F3694: .4byte 0x00000E12\n\
_080F3698: .4byte 0x00000E1E\n\
_080F369C: .4byte 0x00000E15\n\
_080F36A0: .4byte 0x00000E18\n\
_080F36A4: .4byte gVideoRegBuffer\n\
_080F36A8: .4byte 0x0000FFF8\n\
_080F36AC: .4byte 0x0000F0FF\n\
_080F36B0: .4byte 0x00004206\n\
_080F36B4: .4byte gEachMenuLoops\n\
 .syntax divided\n");
}

// 01 01 xx xx
NAKED void MenuLoop_OpenMenu(struct GameState *m) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrh r0, [r4, #4]\n\
	adds r0, #1\n\
	adds r1, r0, #0\n\
	strh r0, [r4, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0xf\n\
	ble _080F36FC\n\
	ldr r1, _080F36F0 @ =gPaletteManager\n\
	ldr r2, _080F36F4 @ =0x00000402\n\
	adds r0, r1, r2\n\
	movs r2, #0x20\n\
	strb r2, [r0]\n\
	ldr r3, _080F36F8 @ =0x00000401\n\
	adds r0, r1, r3\n\
	strb r2, [r0]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #3\n\
	adds r1, r1, r0\n\
	strb r2, [r1]\n\
	movs r0, #2\n\
	strb r0, [r4, #1]\n\
	adds r0, r4, #0\n\
	bl MenuLoop_Update\n\
	b _080F3716\n\
	.align 2, 0\n\
_080F36F0: .4byte gPaletteManager\n\
_080F36F4: .4byte 0x00000402\n\
_080F36F8: .4byte 0x00000401\n\
_080F36FC:\n\
	ldr r2, _080F3724 @ =gPaletteManager\n\
	ldr r3, _080F3728 @ =0x00000402\n\
	adds r0, r2, r3\n\
	strb r1, [r0]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	subs r3, #1\n\
	adds r1, r2, r3\n\
	strb r0, [r1]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r2, r2, r1\n\
	strb r0, [r2]\n\
_080F3716:\n\
	adds r0, r4, #0\n\
	bl menu_080f39a8\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F3724: .4byte gPaletteManager\n\
_080F3728: .4byte 0x00000402\n\
 .syntax divided\n");
}

// 01 02 xx xx
NAKED void MenuLoop_Update(struct GameState *m) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	ldr r0, _080F376C @ =0x00000E1D\n\
	adds r4, r5, r0\n\
	movs r0, #0\n\
	strb r0, [r4]\n\
	ldr r1, _080F3770 @ =gEachMenuLoops\n\
	ldr r2, _080F3774 @ =0x00000E18\n\
	adds r0, r5, r2\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	adds r0, r5, #0\n\
	bl _call_via_r1\n\
	ldrb r0, [r4]\n\
	cmp r0, #0\n\
	bne _080F3764\n\
	ldr r0, _080F3778 @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F3764\n\
	movs r0, #3\n\
	strb r0, [r5, #1]\n\
	strb r0, [r5, #2]\n\
_080F3764:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F376C: .4byte 0x00000E1D\n\
_080F3770: .4byte gEachMenuLoops\n\
_080F3774: .4byte 0x00000E18\n\
_080F3778: .4byte gJoypad\n\
 .syntax divided\n");
}

// 01 03 xx xx
NAKED void MenuLoop_BlackOut(struct GameState *m) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r2, r0, #0\n\
	ldrh r0, [r2, #4]\n\
	subs r0, #1\n\
	movs r3, #0\n\
	adds r1, r0, #0\n\
	strh r0, [r2, #4]\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080F37BC\n\
	ldr r0, _080F37B4 @ =gPaletteManager\n\
	ldr r4, _080F37B8 @ =0x00000402\n\
	adds r1, r0, r4\n\
	strb r3, [r1]\n\
	subs r4, #1\n\
	adds r1, r0, r4\n\
	strb r3, [r1]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r0, r0, r1\n\
	strb r3, [r0]\n\
	movs r0, #4\n\
	strb r0, [r2, #1]\n\
	adds r0, r2, #0\n\
	bl MenuLoop_ExitMenu\n\
	b _080F37D6\n\
	.align 2, 0\n\
_080F37B4: .4byte gPaletteManager\n\
_080F37B8: .4byte 0x00000402\n\
_080F37BC:\n\
	ldr r2, _080F37DC @ =gPaletteManager\n\
	ldr r3, _080F37E0 @ =0x00000402\n\
	adds r0, r2, r3\n\
	strb r1, [r0]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	ldr r4, _080F37E4 @ =0x00000401\n\
	adds r1, r2, r4\n\
	strb r0, [r1]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r2, r2, r1\n\
	strb r0, [r2]\n\
_080F37D6:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F37DC: .4byte gPaletteManager\n\
_080F37E0: .4byte 0x00000402\n\
_080F37E4: .4byte 0x00000401\n\
 .syntax divided\n");
}

// 01 04 xx xx
NAKED void MenuLoop_ExitMenu(struct GameState *m) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r6, r0, #0\n\
	ldr r1, _080F3864 @ =0x000064AC\n\
	adds r0, r6, r1\n\
	ldr r7, [r0]\n\
	adds r0, r6, #0\n\
	bl menu_080f39fc\n\
	adds r0, r6, #0\n\
	bl menu_080f3ab0\n\
	ldr r2, _080F3868 @ =0x00000E1E\n\
	adds r0, r6, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #2\n\
	beq _080F3822\n\
	adds r0, r7, #0\n\
	adds r0, #0xd9\n\
	ldrb r0, [r0]\n\
	cmp r0, #2\n\
	bne _080F3822\n\
	adds r1, r7, #0\n\
	adds r1, #0xda\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_080F3822:\n\
	ldr r3, _080F386C @ =0x00000E16\n\
	adds r0, r6, r3\n\
	adds r1, r7, #0\n\
	adds r1, #0xb4\n\
	ldrb r0, [r0]\n\
	adds r4, r1, #0\n\
	ldrb r1, [r4, #0xe]\n\
	cmp r0, r1\n\
	beq _080F383A\n\
	ldrb r0, [r4, #0xe]\n\
	bl setWramElement\n\
_080F383A:\n\
	movs r5, #0\n\
	ldr r2, _080F3870 @ =0x00000E1C\n\
	adds r2, r2, r6\n\
	mov r8, r2\n\
	movs r3, #0xa4\n\
	adds r3, r3, r7\n\
	mov sb, r3\n\
	ldr r0, _080F3874 @ =0x00000E18\n\
	adds r0, r0, r6\n\
	mov sl, r0\n\
_080F384E:\n\
	cmp r5, #0\n\
	bne _080F387C\n\
	ldr r1, _080F3878 @ =0x00000E14\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0]\n\
	ldrb r2, [r4]\n\
	cmp r0, r2\n\
	beq _080F3892\n\
	ldrb r1, [r4]\n\
	b _080F388A\n\
	.align 2, 0\n\
_080F3864: .4byte 0x000064AC\n\
_080F3868: .4byte 0x00000E1E\n\
_080F386C: .4byte 0x00000E16\n\
_080F3870: .4byte 0x00000E1C\n\
_080F3874: .4byte 0x00000E18\n\
_080F3878: .4byte 0x00000E14\n\
_080F387C:\n\
	ldr r3, _080F392C @ =0x00000E15\n\
	adds r0, r6, r3\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r4, #1]\n\
	cmp r0, r1\n\
	beq _080F3892\n\
	ldrb r1, [r4, #1]\n\
_080F388A:\n\
	adds r0, r7, #0\n\
	adds r2, r5, #0\n\
	bl CreateSateliteElf\n\
_080F3892:\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, #1\n\
	bls _080F384E\n\
	mov r2, r8\n\
	ldrb r0, [r2]\n\
	cmp r0, #0xff\n\
	beq _080F38D2\n\
	ldr r4, _080F3930 @ =gExitMenuScripts\n\
	ldr r1, _080F3934 @ =gElfBreedInfo\n\
	adds r2, r0, #0\n\
	lsls r0, r2, #2\n\
	adds r0, r0, r1\n\
	ldrb r3, [r0, #1]\n\
	lsls r3, r3, #2\n\
	adds r3, r3, r4\n\
	ldrb r1, [r0, #2]\n\
	ldr r0, _080F3938 @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	adds r0, r0, r2\n\
	ldr r2, [r0]\n\
	lsls r2, r2, #0x1d\n\
	lsrs r2, r2, #0x1f\n\
	ldr r4, [r3]\n\
	adds r0, r7, #0\n\
	movs r3, #0\n\
	bl _call_via_r4\n\
	ldr r1, _080F393C @ =gPause\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
_080F38D2:\n\
	adds r0, r7, #0\n\
	bl GetMaxHP\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov r3, sb\n\
	movs r2, #0\n\
	ldrsh r1, [r3, r2]\n\
	cmp r0, r1\n\
	bge _080F38F4\n\
	adds r0, r7, #0\n\
	bl GetMaxHP\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov r3, sb\n\
	strh r0, [r3]\n\
_080F38F4:\n\
	ldr r1, _080F3940 @ =gEachMenuLoops\n\
	mov r2, sl\n\
	ldrb r0, [r2]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	adds r0, r6, #0\n\
	bl _call_via_r1\n\
	ldr r0, _080F3944 @ =FUN_080f3d44\n\
	bl KillAllWeapons\n\
	ldr r0, _080F3948 @ =close_menu_080f3d64\n\
	bl close_menu_080e1540\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #3\n\
	adds r0, r6, #0\n\
	bl SetGameMode\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F392C: .4byte 0x00000E15\n\
_080F3930: .4byte gExitMenuScripts\n\
_080F3934: .4byte gElfBreedInfo\n\
_080F3938: .4byte gUnlockedElfPtr\n\
_080F393C: .4byte gPause\n\
_080F3940: .4byte gEachMenuLoops\n\
_080F3944: .4byte FUN_080f3d44\n\
_080F3948: .4byte close_menu_080f3d64\n\
 .syntax divided\n");
}

static void menu_080f394c(struct GameState *g) {
  struct Coord *c = &g->unk_0dc4;
  c->x = PIXEL(120);
  c->y = PIXEL(80);
  ResetPivot(&g->unk_0db8, c, 0, 0);
  ResetTaskManager(&g->taskManager2);
  SetTaskPivot(&g->taskManager2, &g->unk_0db8);
  InitWidgetHeader(&g->entityHeaders[ENTITY_WIDGET], gWidgets, 64);
}

static void menu_080f39a8(struct GameState *g) {
  g->unk_0dc4.x = PIXEL(((struct BgOfs *)gVideoRegBuffer.bgofs[1])->x & 0x1FF) + PIXEL(120);
  ClearTaskBuffer(&g->taskManager2);
  UpdateEntities(gWidgetHeaderPtr);
  DrawEntity(gWidgetHeaderPtr, &g->taskManager2);
  RunAllTasks(&g->taskManager2);
}

NAKED void menu_080f39fc(struct GameState *m) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r1, r0, #0\n\
	ldr r2, _080F3A2C @ =0x000064AC\n\
	adds r0, r1, r2\n\
	ldr r2, [r0]\n\
	ldr r3, _080F3A30 @ =0x00000E12\n\
	adds r0, r1, r3\n\
	adds r6, r2, #0\n\
	adds r6, #0xb4\n\
	ldrb r7, [r6, #0xc]\n\
	ldrb r0, [r0]\n\
	mov ip, r0\n\
	adds r4, r7, #0\n\
	cmp ip, r4\n\
	bne _080F3A3A\n\
	adds r1, r2, #0\n\
	adds r1, #0xe4\n\
	ldrb r0, [r1]\n\
	cmp r0, r4\n\
	bne _080F3A34\n\
	ldrb r1, [r6, #0xd]\n\
	adds r0, r2, #0\n\
	adds r0, #0xe5\n\
	b _080F3AA6\n\
	.align 2, 0\n\
_080F3A2C: .4byte 0x000064AC\n\
_080F3A30: .4byte 0x00000E12\n\
_080F3A34:\n\
	ldrb r0, [r6, #0xd]\n\
	strb r0, [r1]\n\
	b _080F3AA8\n\
_080F3A3A:\n\
	ldr r3, _080F3A5C @ =0x00000E13\n\
	adds r0, r1, r3\n\
	ldrb r5, [r6, #0xd]\n\
	ldrb r3, [r0]\n\
	adds r1, r5, #0\n\
	cmp r3, r1\n\
	bne _080F3A64\n\
	adds r1, r2, #0\n\
	adds r1, #0xe5\n\
	ldrb r0, [r1]\n\
	cmp r0, r3\n\
	bne _080F3A60\n\
	adds r0, r2, #0\n\
	adds r0, #0xe4\n\
	strb r7, [r0]\n\
	b _080F3AA8\n\
	.align 2, 0\n\
_080F3A5C: .4byte 0x00000E13\n\
_080F3A60:\n\
	strb r7, [r1]\n\
	b _080F3AA8\n\
_080F3A64:\n\
	cmp ip, r1\n\
	bne _080F3A82\n\
	cmp r3, r4\n\
	beq _080F3AA8\n\
	adds r3, r2, #0\n\
	adds r3, #0xe4\n\
	ldrb r0, [r3]\n\
	cmp r0, r1\n\
	bne _080F3A7E\n\
	adds r0, r2, #0\n\
	adds r0, #0xe5\n\
	strb r7, [r0]\n\
	b _080F3AA8\n\
_080F3A7E:\n\
	strb r7, [r3]\n\
	b _080F3AA8\n\
_080F3A82:\n\
	cmp r3, r4\n\
	bne _080F3A9C\n\
	adds r1, r2, #0\n\
	adds r1, #0xe4\n\
	ldrb r0, [r1]\n\
	cmp r0, r3\n\
	bne _080F3A98\n\
	adds r0, r2, #0\n\
	adds r0, #0xe5\n\
	strb r5, [r0]\n\
	b _080F3AA8\n\
_080F3A98:\n\
	strb r5, [r1]\n\
	b _080F3AA8\n\
_080F3A9C:\n\
	adds r0, r2, #0\n\
	adds r0, #0xe4\n\
	strb r7, [r0]\n\
	ldrb r1, [r6, #0xd]\n\
	adds r0, #1\n\
_080F3AA6:\n\
	strb r1, [r0]\n\
_080F3AA8:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED void menu_080f3ab0(struct GameState *m) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	mov r8, r0\n\
	ldr r0, _080F3B40 @ =0x000064AC\n\
	add r0, r8\n\
	ldr r4, [r0]\n\
	adds r5, r4, #0\n\
	adds r5, #0xb4\n\
	movs r0, #0x92\n\
	lsls r0, r0, #1\n\
	adds r3, r4, r0\n\
	ldrb r0, [r3]\n\
	lsls r1, r0, #0x1b\n\
	lsrs r1, r1, #0x1f\n\
	str r1, [sp]\n\
	lsls r0, r0, #0x1a\n\
	lsrs r0, r0, #0x1f\n\
	mov sb, r0\n\
	adds r6, r4, #0\n\
	adds r6, #0xdc\n\
	ldrb r1, [r6]\n\
	str r1, [sp, #4]\n\
	adds r0, r4, #0\n\
	adds r0, #0xdd\n\
	ldrb r0, [r0]\n\
	mov sl, r0\n\
	ldr r7, _080F3B44 @ =0x00000E12\n\
	add r7, r8\n\
	ldrb r0, [r7]\n\
	ldrb r2, [r5, #0xc]\n\
	cmp r0, r2\n\
	beq _080F3B5E\n\
	ldrb r1, [r5, #0xd]\n\
	cmp r0, r1\n\
	beq _080F3B1C\n\
	movs r2, #0x9b\n\
	lsls r2, r2, #1\n\
	adds r2, r2, r4\n\
	mov ip, r2\n\
	ldrb r0, [r2]\n\
	movs r1, #0x80\n\
	orrs r1, r0\n\
	strb r1, [r2]\n\
	ldr r2, _080F3B48 @ =u8_ARRAY_083862fc\n\
	ldrb r0, [r7]\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	orrs r1, r0\n\
	mov r0, ip\n\
	strb r1, [r0]\n\
_080F3B1C:\n\
	ldr r0, _080F3B4C @ =0x00000E13\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	ldrb r5, [r5, #0xc]\n\
	cmp r0, r5\n\
	bne _080F3B50\n\
	mov r1, sb\n\
	lsls r2, r1, #4\n\
	ldrb r1, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strb r0, [r3]\n\
	mov r2, sl\n\
	strb r2, [r6]\n\
	b _080F3B5E\n\
	.align 2, 0\n\
_080F3B40: .4byte 0x000064AC\n\
_080F3B44: .4byte 0x00000E12\n\
_080F3B48: .4byte u8_ARRAY_083862fc\n\
_080F3B4C: .4byte 0x00000E13\n\
_080F3B50:\n\
	ldrb r0, [r3]\n\
	movs r1, #0x11\n\
	rsbs r1, r1, #0\n\
	ands r1, r0\n\
	strb r1, [r3]\n\
	movs r0, #0\n\
	strb r0, [r6]\n\
_080F3B5E:\n\
	ldr r5, _080F3BC4 @ =0x00000E13\n\
	add r5, r8\n\
	adds r3, r4, #0\n\
	adds r3, #0xb4\n\
	ldrb r0, [r5]\n\
	ldrb r1, [r3, #0xd]\n\
	cmp r0, r1\n\
	beq _080F3BE8\n\
	ldrb r2, [r3, #0xc]\n\
	cmp r0, r2\n\
	beq _080F3B94\n\
	movs r0, #0x9b\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r4\n\
	mov ip, r0\n\
	ldrb r0, [r0]\n\
	movs r1, #0x80\n\
	orrs r1, r0\n\
	mov r2, ip\n\
	strb r1, [r2]\n\
	ldr r2, _080F3BC8 @ =u8_ARRAY_083862fc\n\
	ldrb r0, [r5]\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	orrs r1, r0\n\
	mov r0, ip\n\
	strb r1, [r0]\n\
_080F3B94:\n\
	ldr r0, _080F3BCC @ =0x00000E12\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	ldrb r3, [r3, #0xd]\n\
	cmp r0, r3\n\
	bne _080F3BD0\n\
	movs r1, #0x92\n\
	lsls r1, r1, #1\n\
	adds r2, r4, r1\n\
	ldr r0, [sp]\n\
	lsls r3, r0, #5\n\
	ldrb r1, [r2]\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	orrs r0, r3\n\
	strb r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xdd\n\
	mov r1, sp\n\
	ldrb r1, [r1, #4]\n\
	strb r1, [r0]\n\
	b _080F3BE8\n\
	.align 2, 0\n\
_080F3BC4: .4byte 0x00000E13\n\
_080F3BC8: .4byte u8_ARRAY_083862fc\n\
_080F3BCC: .4byte 0x00000E12\n\
_080F3BD0:\n\
	movs r0, #0x92\n\
	lsls r0, r0, #1\n\
	adds r2, r4, r0\n\
	ldrb r1, [r2]\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	adds r1, r4, #0\n\
	adds r1, #0xdd\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_080F3BE8:\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

/**
 * @return TRUE: B,L,Rのいずれかが押されてメニューが遷移, FALSE: 何もなし
 */
NAKED bool8 TrySlideMenu(struct GameState *g) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r3, r0, #0\n\
	ldr r0, _080F3C14 @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	cmp r2, #0\n\
	beq _080F3C18\n\
	movs r0, #3\n\
	strb r0, [r3, #1]\n\
	strb r0, [r3, #2]\n\
	b _080F3C7C\n\
	.align 2, 0\n\
_080F3C14: .4byte gJoypad\n\
_080F3C18:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	ands r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	cmp r4, #0\n\
	beq _080F3C44\n\
	ldr r1, _080F3C3C @ =0x00000E18\n\
	adds r0, r3, r1\n\
	ldrb r0, [r0]\n\
	adds r0, #3\n\
	movs r1, #3\n\
	ands r0, r1\n\
	ldr r4, _080F3C40 @ =0x00000E19\n\
	adds r1, r3, r4\n\
	strb r0, [r1]\n\
	strb r2, [r3, #2]\n\
	b _080F3C66\n\
	.align 2, 0\n\
_080F3C3C: .4byte 0x00000E18\n\
_080F3C40: .4byte 0x00000E19\n\
_080F3C44:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F3C52\n\
	movs r0, #0\n\
	b _080F3C7E\n\
_080F3C52:\n\
	ldr r1, _080F3C84 @ =0x00000E18\n\
	adds r0, r3, r1\n\
	ldrb r0, [r0]\n\
	adds r0, #1\n\
	movs r1, #3\n\
	ands r0, r1\n\
	ldr r2, _080F3C88 @ =0x00000E19\n\
	adds r1, r3, r2\n\
	strb r0, [r1]\n\
	strb r4, [r3, #2]\n\
_080F3C66:\n\
	ldr r2, _080F3C8C @ =gEachMenuLoops\n\
	ldrb r0, [r1]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	ldr r1, [r0]\n\
	adds r0, r3, #0\n\
	bl _call_via_r1\n\
	movs r0, #0x33\n\
	bl PlaySound\n\
_080F3C7C:\n\
	movs r0, #1\n\
_080F3C7E:\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_080F3C84: .4byte 0x00000E18\n\
_080F3C88: .4byte 0x00000E19\n\
_080F3C8C: .4byte gEachMenuLoops\n\
 .syntax divided\n");
}

/**
 * @brief dstが BGMap の (0, 0) としたときに (xタイル ,yタイル) を左上として転送する
 * @param dst BGMap (0, 0) point
 * @param x Start X Tile
 * @param y Start Y Tile
 */
NAKED void CopyBgMap(u16 *dst, struct BgMapHeader *src, u8 x, u8 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov ip, r0\n\
	adds r4, r1, #0\n\
	lsls r2, r2, #0x18\n\
	lsls r3, r3, #0x18\n\
	ldrb r6, [r4, #4]\n\
	ldrb r7, [r4, #6]\n\
	adds r4, #8\n\
	lsrs r3, r3, #0x12\n\
	add r3, ip\n\
	lsrs r2, r2, #0x17\n\
	adds r3, r3, r2\n\
	mov ip, r3\n\
	movs r1, #0\n\
	cmp r1, r7\n\
	bhs _080F3CDA\n\
_080F3CB0:\n\
	lsls r0, r1, #6\n\
	mov r2, ip\n\
	adds r3, r2, r0\n\
	movs r2, #0\n\
	adds r5, r1, #1\n\
	cmp r2, r6\n\
	bhs _080F3CD2\n\
_080F3CBE:\n\
	lsls r0, r2, #1\n\
	adds r0, r0, r3\n\
	ldrh r1, [r4]\n\
	strh r1, [r0]\n\
	adds r4, #2\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, r6\n\
	blo _080F3CBE\n\
_080F3CD2:\n\
	lsls r0, r5, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, r7\n\
	blo _080F3CB0\n\
_080F3CDA:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED void PrintNumber(u16 n, u8 x, u8 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	lsls r1, r1, #0x18\n\
	lsrs r7, r1, #0x18\n\
	lsls r2, r2, #0x18\n\
	lsrs r6, r2, #0x18\n\
	movs r5, #0\n\
	ldr r0, _080F3D30 @ =StringOfsTable\n\
	mov r8, r0\n\
_080F3CF8:\n\
	adds r0, r4, #0\n\
	movs r1, #0xa\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0xf\n\
	adds r0, #0x3c\n\
	add r0, r8\n\
	ldrh r0, [r0]\n\
	ldr r1, _080F3D34 @ =gStringData\n\
	adds r0, r0, r1\n\
	subs r1, r7, r5\n\
	adds r2, r6, #0\n\
	bl PrintString\n\
	adds r0, r4, #0\n\
	movs r1, #0xa\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	cmp r4, #0\n\
	beq _080F3D38\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	b _080F3CF8\n\
	.align 2, 0\n\
_080F3D30: .4byte StringOfsTable\n\
_080F3D34: .4byte gStringData\n\
_080F3D38:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

void FUN_080f3d44(struct Weapon *w) {
  if (PTR_ARRAY_08386300[(w->s).id] != NULL) {
    (PTR_ARRAY_08386300[(w->s).id])(w);
  }
}

void close_menu_080f3d64(struct Elf *p) {
  if (PTR_ARRAY_08386344[(p->s).id] != NULL) {
    (PTR_ARRAY_08386344[(p->s).id])(p);
  }
}

// ------------------------------------------------------------------------------------------------------------------------------------

// idx is BYTE[0x02031978]
const MenuLoopFunc gEachMenuLoops[4] = {
    EachMenuLoop_MainMenu,
    EachMenuLoop_ExSkill,
    EachMenuLoop_KeyConfig,
    EachMenuLoop_Elf,
};

// 01 xx nn nn
const MenuLoopFunc gMenuLoops[5] = {
    MenuLoop_InitMenu, MenuLoop_OpenMenu, MenuLoop_Update, MenuLoop_BlackOut, MenuLoop_ExitMenu,
};

struct Elf *FUN_080e20a4(struct Zero *z, u8 breed, u8 availability, u8 _);
struct Elf *CreateElf5(struct Zero *z, u8 breed, u8 availability, u8 _);
struct Elf *CreateElf6(struct Zero *z, u8 breed, u8 availability, u8 _);
struct Elf *CreateElf7(struct Zero *z, u8 breed, u8 availability, u8 _);
struct Elf *elf_080e4bf4(struct Zero *z, u8 breed, u8 availability, u8 _);

// clang-format off
const MenuElfFunc gExitMenuScripts[13] = {
    CreateElf0,
    FUN_080e20a4,
    CreateNurseBElf, 
    CreateNurseBElf, 
    CreateNurseEElf, 
    CreateElf5, 
    CreateElf6, 
    CreateElf7, 
    CreateFollowerElf, 
    CreateSeaotterElf, 
    elf_080e4bf4, 
    elf_080e4bf4, 
    CreateBirdElf,
};
// clang-format on

const u8 u8_ARRAY_083862fc[4] = {
    1,
    2,
    4,
    8,
};

// clang-format off
const WeaponFunc PTR_ARRAY_08386300[WEAPON_MOVE_COUNT] = {
    [WEAPON_MOVE_Z_BUSTER]     =      MenuExit_Buster, 
    [WEAPON_MOVE_Z_SABER]      =      NULL, 
    [WEAPON_MOVE_SHIELD_GUARD] =      MenuExit_ShieldGuard, 
    [WEAPON_MOVE_RECOIL_ROD]   =      NULL, 
    [WEAPON_MOVE_SHIELD_FLY]   =      MenuExit_ShieldFly, 
    [WEAPON_MOVE_SABER_WAVE] =        NULL, 
    [WEAPON_MOVE_06] =                NULL, 
    [WEAPON_MOVE_REFLECT_LASER] =     MenuExit_ReflectLaser, 
    [WEAPON_MOVE_SOUL_LANCHER] =      MenuExit_SoulLauncher, 
    [WEAPON_MOVE_BURST_SHOT] =        MenuExit_BurstShot, 
    [WEAPON_MOVE_BLIZZARD_ARROW] =    MenuExit_BlizzardArrow, 
    [WEAPON_MOVE_ZANEIDAN] =          MenuExit_ThrowBlade, 
    [WEAPON_MOVE_SHIELD_SWEEP] =      MenuExit_ShieldSweep, 
    [WEAPON_MOVE_13] =                MenuExit_Weapon13, 
    [WEAPON_MOVE_RAKUSAIGA] =         MenuExit_SaberSmash, 
    [WEAPON_MOVE_SHIELD_SWEEP_ELEC] = MenuExit_ShieldSweepElec, 
    [WEAPON_MOVE_16] =                NULL,
};
// clang-format on

// --------------------------------------------

void FUN_080e2510(struct Elf *p);
void FUN_080e2b78(struct Elf *p);
void FUN_080e4054(struct Elf *p);
void FUN_080e453c(struct Elf *p);
void FUN_080e4b88(struct Elf *p);
void FUN_080e58bc(struct Elf *p);

// clang-format off
const ElfFunc PTR_ARRAY_08386344[13] = {
    NULL, 
    NULL, 
    FUN_080e2510, 
    NULL, 
    FUN_080e2b78, 
    NULL, 
    NULL, 
    NULL, 
    FUN_080e4054, 
    FUN_080e453c, 
    FUN_080e4b88, 
    NULL, 
    FUN_080e58bc,
};
// clang-format on
