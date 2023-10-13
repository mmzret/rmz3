#include "entity.h"
#include "game.h"
#include "gfx.h"
#include "global.h"
#include "menu.h"

// 08547280 のidx
const u8 u8_ARRAY_08386378[16] = {
    24, 25, 26, 27, 28, 29, 30, 31, 32, 31, 30, 29, 28, 27, 26, 25,
};

const u8 u8_ARRAY_08386388[16] = {
    24, 24, 24, 24, 24, 24, 24, 24, 25, 25, 25, 25, 25, 25, 25, 25,
};

// MainMenuのカーソル位置
const u8 u8_ARRAY_ARRAY_08386398[7][4] = {
    {
        0,  // Up
        3,  // Right
        1,  // Down
        0   // Left
    },
    {0, 4, 2, 1},
    {1, 5, 6, 2},
    {3, 3, 4, 0},
    {3, 4, 5, 1},
    {4, 5, 6, 2},
    {2, 5, 6, 2},
};

// MainMenuのカーソル位置
const u8 u8_ARRAY_ARRAY_083863b4[7][4] = {
    {-1, -1, -1, -1}, {-1, -1, -1, -1}, {5, -1, 5, 1}, {0, 4, -1, -1}, {3, 5, 5, -1}, {1, 6, 6, -1}, {-1, -1, -1, -1},
};

const u8 u8_ARRAY_083863d0[24] = {
    0x78, 0x01, 0x20, 0x07, 0x28, 0x04, 0x30, 0x03, 0x38, 0x04, 0x40, 0x04, 0x48, 0x04, 0x50, 0x03, 0x58, 0x06, 0x60, 0x03, 0x68, 0x02, 0x70, 0x01,
};

const u8 u8_ARRAY_083863e8[40] = {
    0xE0, 0x03, 0x00, 0x04, 0x08, 0x04, 0x10, 0x07, 0x18, 0x05, 0x80, 0x05, 0x88, 0x05, 0x90, 0x06, 0x98, 0x03, 0xA0, 0x05, 0xA8, 0x04, 0xB0, 0x06, 0xB8, 0x08, 0xC0, 0x08, 0xC8, 0x05, 0xD0, 0x06, 0xD8, 0x08, 0xF0, 0x03, 0xE8, 0x05, 0xF8, 0x06,
};

// --------------------------------------------

static void MainMenuLoop_Init(struct GameState* p);
static void MainMenuLoop_Update(struct GameState* p);
static void MainMenuLoop_SlideOut(struct GameState* p);
static void MainMenuLoop_Exit(struct GameState* p);

// 01 02 xx xx (BYTE[0x02031978] = 0)
const MenuLoopFunc gMainManuLoops[4] = {
    MainMenuLoop_Init,
    MainMenuLoop_Update,
    MainMenuLoop_SlideOut,
    MainMenuLoop_Exit,
};

// --------------------------------------------

static void MainMenuFocusLoop_NoFocus(struct GameState* g);
static void MainMenuFocusLoop_MainWeapon(struct GameState* g);
static void MainMenuFocusLoop_SubWeapon(struct GameState* g);
static void MainMenuFocusLoop_Subtank(struct GameState* g);
static void MainMenuFocusLoop_Head(struct GameState* g);
static void MainMenuFocusLoop_Body(struct GameState* g);
static void MainMenuFocusLoop_Foot(struct GameState* g);
static void MainMenuFocusLoop_Escape(struct GameState* g);

// メインメニューで選択されているもの
// clang-format off
const MenuLoopFunc gMainMenuFocusLoops[8] = {
    MainMenuFocusLoop_NoFocus,
    MainMenuFocusLoop_MainWeapon,
    MainMenuFocusLoop_SubWeapon,
    MainMenuFocusLoop_Subtank,
    MainMenuFocusLoop_Head,
    MainMenuFocusLoop_Body,
    MainMenuFocusLoop_Foot,
    MainMenuFocusLoop_Escape,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

// 01 02 xx xx
void EachMenuLoop_MainMenu(struct GameState* g) {
  (gMainManuLoops[g->mode[2]])(g);
  return;
}

// 01 02 00 xx
NAKED static void MainMenuLoop_Init(struct GameState* m) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0xc\n\
	adds r7, r0, #0\n\
	ldr r1, _080F4084 @ =0x000064AC\n\
	adds r0, r7, r1\n\
	ldr r0, [r0]\n\
	str r0, [sp]\n\
	bl GetMaxHP\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldr r4, [sp]\n\
	adds r4, #0xa4\n\
	movs r2, #0\n\
	ldrsh r1, [r4, r2]\n\
	cmp r0, r1\n\
	bge _080F3DD2\n\
	ldr r0, [sp]\n\
	bl GetMaxHP\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	strh r0, [r4]\n\
_080F3DD2:\n\
	ldr r3, _080F4088 @ =0x00000DCC\n\
	adds r2, r7, r3\n\
	movs r3, #0\n\
	strb r3, [r2]\n\
	strb r3, [r2, #2]\n\
	movs r0, #0xff\n\
	strb r0, [r2, #3]\n\
	strb r3, [r2, #4]\n\
	strb r3, [r2, #5]\n\
	strb r3, [r2, #0xe]\n\
	ldr r0, [sp]\n\
	adds r0, #0xb4\n\
	ldrb r1, [r0, #0x10]\n\
	strb r1, [r2, #0x10]\n\
	ldrb r1, [r0, #0x1a]\n\
	str r0, [sp, #4]\n\
	cmp r1, #2\n\
	bne _080F3DFA\n\
	movs r0, #7\n\
	strb r0, [r2, #0x10]\n\
_080F3DFA:\n\
	ldr r4, [sp, #4]\n\
	ldrb r0, [r4, #0x1a]\n\
	cmp r0, #1\n\
	bne _080F3E06\n\
	movs r0, #6\n\
	strb r0, [r2, #0x10]\n\
_080F3E06:\n\
	strb r3, [r2, #0x11]\n\
	ldr r0, _080F408C @ =gGraphic_Capcom+(20*20)\n\
	ldr r5, _080F4090 @ =gVideoRegBuffer+6\n\
	ldrh r2, [r5]\n\
	movs r4, #0xc\n\
	adds r1, r4, #0\n\
	ands r1, r2\n\
	lsls r1, r1, #0xc\n\
	bl LoadGraphic\n\
	ldr r0, _080F4094 @ =gGraphic_Capcom+(20*20)+12\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r0, _080F4098 @ =gGraphics_CodeName\n\
	ldrh r1, [r5]\n\
	ands r4, r1\n\
	lsls r4, r4, #0xc\n\
	adds r1, r4, #0\n\
	bl LoadGraphic\n\
	ldr r0, _080F409C @ =gGraphics_CodeName+12\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r0, _080F40A0 @ =0x085222F0\n\
	ldr r0, [r0]\n\
	ldr r5, _080F40A4 @ =0x085222F8\n\
	adds r0, r0, r5\n\
	ldr r1, _080F40A8 @ =0x00000ED8\n\
	adds r4, r7, r1\n\
	movs r2, #0xf0\n\
	lsls r2, r2, #1\n\
	adds r1, r4, #0\n\
	bl CpuFastSet\n\
	mov r8, r4\n\
	ldr r0, _080F40AC @ =gMission\n\
	ldr r3, [r0]\n\
	ldrb r6, [r3]\n\
	movs r2, #0xa4\n\
	lsls r2, r2, #1\n\
	adds r0, r6, r2\n\
	movs r4, #0x80\n\
	lsls r4, r4, #7\n\
	adds r2, r4, #0\n\
	orrs r0, r2\n\
	mov r5, r8\n\
	strh r0, [r5, #0x18]\n\
	movs r0, #0xf3\n\
	lsls r0, r0, #4\n\
	adds r1, r7, r0\n\
	movs r4, #0xb4\n\
	lsls r4, r4, #1\n\
	adds r0, r6, r4\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	ldrb r1, [r3, #1]\n\
	movs r0, #6\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	movs r5, #0xf7\n\
	lsls r5, r5, #4\n\
	adds r1, r7, r5\n\
	subs r4, #0x28\n\
	adds r0, r6, r4\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	adds r5, #0x40\n\
	adds r1, r7, r5\n\
	adds r4, #0x20\n\
	adds r0, r6, r4\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	ldr r5, [r3, #0xc]\n\
	ldr r1, _080F40B0 @ =0x0020F580\n\
	adds r0, r5, #0\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	ldr r0, _080F40B4 @ =0x00000F76\n\
	adds r1, r7, r0\n\
	movs r2, #0xba\n\
	lsls r2, r2, #1\n\
	mov sl, r2\n\
	mov r3, sl\n\
	adds r0, r6, r3\n\
	movs r4, #0xc0\n\
	lsls r4, r4, #7\n\
	mov sb, r4\n\
	mov r2, sb\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	ldr r1, _080F40B8 @ =0x00034BC0\n\
	adds r0, r5, #0\n\
	bl __udivsi3\n\
	movs r1, #0xa\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	ldr r3, _080F40BC @ =0x00000F78\n\
	adds r1, r7, r3\n\
	mov r4, sl\n\
	adds r0, r6, r4\n\
	mov r2, sb\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	movs r1, #0xe1\n\
	lsls r1, r1, #4\n\
	adds r0, r5, #0\n\
	bl __udivsi3\n\
	movs r1, #0x3c\n\
	bl __umodsi3\n\
	adds r4, r0, #0\n\
	movs r1, #0xa\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	ldr r3, _080F40C0 @ =0x00000F7C\n\
	adds r1, r7, r3\n\
	mov r2, sl\n\
	adds r0, r6, r2\n\
	mov r3, sb\n\
	orrs r0, r3\n\
	strh r0, [r1]\n\
	adds r0, r4, #0\n\
	movs r1, #0xa\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	ldr r4, _080F40C4 @ =0x00000F7E\n\
	adds r1, r7, r4\n\
	mov r2, sl\n\
	adds r0, r6, r2\n\
	mov r3, sb\n\
	orrs r0, r3\n\
	strh r0, [r1]\n\
	adds r0, r5, #0\n\
	movs r1, #0x3c\n\
	bl __udivsi3\n\
	movs r1, #0x3c\n\
	bl __umodsi3\n\
	adds r4, r0, #0\n\
	movs r1, #0xa\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	ldr r5, _080F40C8 @ =0x00000F82\n\
	adds r1, r7, r5\n\
	mov r2, sl\n\
	adds r0, r6, r2\n\
	mov r3, sb\n\
	orrs r0, r3\n\
	strh r0, [r1]\n\
	adds r0, r4, #0\n\
	movs r1, #0xa\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	ldr r4, _080F40CC @ =0x00000F84\n\
	adds r1, r7, r4\n\
	mov r5, sl\n\
	adds r0, r6, r5\n\
	mov r2, sb\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	ldr r3, [sp, #4]\n\
	ldrh r1, [r3, #6]\n\
	ldr r0, _080F40D0 @ =0x000003E7\n\
	cmp r1, r0\n\
	bls _080F3F98\n\
	adds r0, r1, #0\n\
	movs r1, #0xfa\n\
	lsls r1, r1, #2\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	movs r1, #0xa\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	adds r4, #6\n\
	adds r1, r7, r4\n\
	adds r0, r6, r5\n\
	mov r5, sb\n\
	orrs r0, r5\n\
	strh r0, [r1]\n\
_080F3F98:\n\
	ldr r1, [sp, #4]\n\
	ldrh r0, [r1, #6]\n\
	cmp r0, #0x63\n\
	bls _080F3FC2\n\
	movs r1, #0x64\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	movs r1, #0xa\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	ldr r2, _080F40D4 @ =0x00000F8C\n\
	adds r1, r7, r2\n\
	mov r3, sl\n\
	adds r0, r6, r3\n\
	mov r4, sb\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
_080F3FC2:\n\
	ldr r5, [sp, #4]\n\
	ldrh r0, [r5, #6]\n\
	cmp r0, #9\n\
	bls _080F3FEC\n\
	movs r1, #0xa\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	movs r1, #0xa\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	ldr r0, _080F40D8 @ =0x00000F8E\n\
	adds r1, r7, r0\n\
	mov r2, sl\n\
	adds r0, r6, r2\n\
	mov r3, sb\n\
	orrs r0, r3\n\
	strh r0, [r1]\n\
_080F3FEC:\n\
	ldr r4, [sp, #4]\n\
	ldrh r0, [r4, #6]\n\
	movs r1, #0xa\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	movs r5, #0xf9\n\
	lsls r5, r5, #4\n\
	adds r1, r7, r5\n\
	mov r2, sl\n\
	adds r0, r6, r2\n\
	mov r3, sb\n\
	orrs r0, r3\n\
	strh r0, [r1]\n\
	ldr r0, [sp]\n\
	bl getMaxHP1x\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x14\n\
	bne _080F40E0\n\
	movs r6, #0\n\
	ldr r4, [sp]\n\
	adds r4, #0xbc\n\
	str r4, [sp, #8]\n\
	movs r5, #0x80\n\
	lsls r5, r5, #6\n\
	adds r4, r5, #0\n\
_080F4026:\n\
	lsls r0, r6, #6\n\
	mov r1, r8\n\
	adds r3, r0, r1\n\
	movs r2, #0x89\n\
	lsls r2, r2, #1\n\
	adds r1, r3, r2\n\
	lsls r2, r6, #5\n\
	ldr r5, _080F40DC @ =0x00000109\n\
	adds r0, r2, r5\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	movs r0, #0x8a\n\
	lsls r0, r0, #1\n\
	adds r1, r3, r0\n\
	adds r5, #1\n\
	adds r0, r2, r5\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	movs r0, #0x8b\n\
	lsls r0, r0, #1\n\
	adds r1, r3, r0\n\
	adds r5, #1\n\
	adds r0, r2, r5\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	movs r0, #0x8c\n\
	lsls r0, r0, #1\n\
	adds r1, r3, r0\n\
	subs r5, #4\n\
	adds r0, r2, r5\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	movs r0, #0x8d\n\
	lsls r0, r0, #1\n\
	adds r1, r3, r0\n\
	movs r3, #0x84\n\
	lsls r3, r3, #1\n\
	adds r0, r2, r3\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, #1\n\
	bls _080F4026\n\
	b _080F4254\n\
	.align 2, 0\n\
_080F4084: .4byte 0x000064AC\n\
_080F4088: .4byte 0x00000DCC\n\
_080F408C: .4byte gGraphic_Capcom+(20*20)\n\
_080F4090: .4byte gVideoRegBuffer+6\n\
_080F4094: .4byte gGraphic_Capcom+(20*20)+12\n\
_080F4098: .4byte gGraphics_CodeName\n\
_080F409C: .4byte gGraphics_CodeName+12\n\
_080F40A0: .4byte gBgMapOffsets+(20*4)\n\
_080F40A4: .4byte gBgMapOffsets+(22*4)\n\
_080F40A8: .4byte 0x00000ED8\n\
_080F40AC: .4byte gMission\n\
_080F40B0: .4byte 0x0020F580\n\
_080F40B4: .4byte 0x00000F76\n\
_080F40B8: .4byte 0x00034BC0\n\
_080F40BC: .4byte 0x00000F78\n\
_080F40C0: .4byte 0x00000F7C\n\
_080F40C4: .4byte 0x00000F7E\n\
_080F40C8: .4byte 0x00000F82\n\
_080F40CC: .4byte 0x00000F84\n\
_080F40D0: .4byte 0x000003E7\n\
_080F40D4: .4byte 0x00000F8C\n\
_080F40D8: .4byte 0x00000F8E\n\
_080F40DC: .4byte 0x00000109\n\
_080F40E0:\n\
	ldr r0, [sp]\n\
	bl getMaxHP1x\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x18\n\
	bne _080F415C\n\
	movs r6, #0\n\
	ldr r4, [sp]\n\
	adds r4, #0xbc\n\
	str r4, [sp, #8]\n\
	movs r5, #0x80\n\
	lsls r5, r5, #6\n\
	adds r4, r5, #0\n\
_080F40FC:\n\
	lsls r0, r6, #6\n\
	mov r1, r8\n\
	adds r3, r0, r1\n\
	movs r2, #0x89\n\
	lsls r2, r2, #1\n\
	adds r1, r3, r2\n\
	lsls r2, r6, #5\n\
	ldr r5, _080F4158 @ =0x00000109\n\
	adds r0, r2, r5\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	movs r0, #0x8a\n\
	lsls r0, r0, #1\n\
	adds r1, r3, r0\n\
	adds r5, #3\n\
	adds r0, r2, r5\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	movs r0, #0x8b\n\
	lsls r0, r0, #1\n\
	adds r1, r3, r0\n\
	adds r5, #1\n\
	adds r0, r2, r5\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	movs r0, #0x8c\n\
	lsls r0, r0, #1\n\
	adds r1, r3, r0\n\
	adds r5, #1\n\
	adds r0, r2, r5\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	movs r0, #0x8d\n\
	lsls r0, r0, #1\n\
	adds r1, r3, r0\n\
	movs r3, #0x84\n\
	lsls r3, r3, #1\n\
	adds r0, r2, r3\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, #1\n\
	bls _080F40FC\n\
	b _080F4254\n\
	.align 2, 0\n\
_080F4158: .4byte 0x00000109\n\
_080F415C:\n\
	ldr r0, [sp]\n\
	bl getMaxHP1x\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x1c\n\
	bne _080F41DC\n\
	movs r6, #0\n\
	ldr r4, [sp]\n\
	adds r4, #0xbc\n\
	str r4, [sp, #8]\n\
	movs r5, #0x80\n\
	lsls r5, r5, #6\n\
	adds r4, r5, #0\n\
_080F4178:\n\
	lsls r0, r6, #6\n\
	mov r1, r8\n\
	adds r3, r0, r1\n\
	movs r2, #0x89\n\
	lsls r2, r2, #1\n\
	adds r1, r3, r2\n\
	lsls r2, r6, #5\n\
	ldr r5, _080F41D4 @ =0x00000109\n\
	adds r0, r2, r5\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	movs r0, #0x8a\n\
	lsls r0, r0, #1\n\
	adds r1, r3, r0\n\
	adds r5, #3\n\
	adds r0, r2, r5\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	movs r0, #0x8b\n\
	lsls r0, r0, #1\n\
	adds r1, r3, r0\n\
	adds r5, #3\n\
	adds r0, r2, r5\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	movs r0, #0x8c\n\
	lsls r0, r0, #1\n\
	adds r1, r3, r0\n\
	adds r5, #1\n\
	adds r0, r2, r5\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	movs r0, #0x8d\n\
	lsls r0, r0, #1\n\
	adds r1, r3, r0\n\
	ldr r3, _080F41D8 @ =0x00000111\n\
	adds r0, r2, r3\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, #1\n\
	bls _080F4178\n\
	b _080F4254\n\
	.align 2, 0\n\
_080F41D4: .4byte 0x00000109\n\
_080F41D8: .4byte 0x00000111\n\
_080F41DC:\n\
	ldr r0, [sp]\n\
	bl getMaxHP1x\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldr r4, [sp]\n\
	adds r4, #0xbc\n\
	str r4, [sp, #8]\n\
	cmp r0, #0x20\n\
	bne _080F4254\n\
	movs r6, #0\n\
	movs r5, #0x89\n\
	lsls r5, r5, #1\n\
	mov sb, r5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #6\n\
	adds r4, r0, #0\n\
_080F41FE:\n\
	lsls r0, r6, #6\n\
	mov r1, r8\n\
	adds r2, r0, r1\n\
	mov r3, sb\n\
	adds r1, r2, r3\n\
	lsls r3, r6, #5\n\
	ldr r5, _080F429C @ =0x00000109\n\
	adds r0, r3, r5\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	movs r0, #0x8a\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	adds r5, #3\n\
	adds r0, r3, r5\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	movs r0, #0x8b\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	adds r5, #3\n\
	adds r0, r3, r5\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	movs r0, #0x8c\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	mov r5, sb\n\
	adds r0, r3, r5\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	movs r0, #0x8d\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	ldr r2, _080F42A0 @ =0x00000113\n\
	adds r0, r3, r2\n\
	orrs r0, r4\n\
	strh r0, [r1]\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, #1\n\
	bls _080F41FE\n\
_080F4254:\n\
	ldr r3, _080F42A4 @ =0x00000ED8\n\
	adds r3, r3, r7\n\
	mov r8, r3\n\
	ldr r0, _080F42A8 @ =gMission\n\
	ldr r2, [r0]\n\
	ldrb r1, [r2, #4]\n\
	mov ip, r0\n\
	cmp r1, #0\n\
	bne _080F42B4\n\
	movs r6, #0\n\
	movs r4, #0x8f\n\
	lsls r4, r4, #1\n\
	mov sb, r4\n\
	ldr r5, _080F42AC @ =u8_ARRAY_083863e8\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #2\n\
	adds r4, r0, #0\n\
	ldr r1, _080F42B0 @ =0xFFFFF000\n\
	adds r3, r1, #0\n\
_080F427A:\n\
	lsls r1, r6, #1\n\
	add r1, r8\n\
	add r1, sb\n\
	ldrb r0, [r2, #2]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r5\n\
	ldrb r0, [r0]\n\
	adds r0, r0, r4\n\
	adds r0, r0, r6\n\
	orrs r0, r3\n\
	strh r0, [r1]\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, #7\n\
	bls _080F427A\n\
	b _080F4378\n\
	.align 2, 0\n\
_080F429C: .4byte 0x00000109\n\
_080F42A0: .4byte 0x00000113\n\
_080F42A4: .4byte 0x00000ED8\n\
_080F42A8: .4byte gMission\n\
_080F42AC: .4byte u8_ARRAY_083863e8\n\
_080F42B0: .4byte 0xFFFFF000\n\
_080F42B4:\n\
	movs r6, #0\n\
	ldr r3, _080F444C @ =u8_ARRAY_083863d0\n\
	mov sl, r3\n\
	movs r4, #0x8f\n\
	lsls r4, r4, #1\n\
	mov sb, r4\n\
	mov r5, sl\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #2\n\
	adds r4, r0, #0\n\
	ldr r1, _080F4450 @ =0xFFFFF000\n\
	adds r3, r1, #0\n\
_080F42CC:\n\
	lsls r1, r6, #1\n\
	add r1, r8\n\
	add r1, sb\n\
	ldrb r0, [r2, #4]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r5\n\
	ldrb r0, [r0]\n\
	adds r0, r0, r4\n\
	adds r0, r0, r6\n\
	orrs r0, r3\n\
	strh r0, [r1]\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, #7\n\
	bls _080F42CC\n\
	mov r3, ip\n\
	ldr r2, [r3]\n\
	ldrb r0, [r2, #4]\n\
	lsls r0, r0, #1\n\
	mov r1, sl\n\
	adds r1, #1\n\
	adds r0, r0, r1\n\
	ldrb r3, [r0]\n\
	ldrb r0, [r2, #2]\n\
	lsls r0, r0, #1\n\
	ldr r5, _080F4454 @ =u8_ARRAY_083863e8\n\
	adds r5, #1\n\
	adds r0, r0, r5\n\
	ldrb r4, [r0]\n\
	adds r1, r3, r4\n\
	cmp r1, #9\n\
	ble _080F431A\n\
	subs r1, #9\n\
	lsls r0, r3, #0x18\n\
	asrs r0, r0, #0x18\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
_080F431A:\n\
	ldr r1, _080F4458 @ =0x00000DCC\n\
	adds r0, r7, r1\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r5\n\
	ldrb r0, [r0]\n\
	cmp r0, #8\n\
	bne _080F4330\n\
	adds r0, r3, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
_080F4330:\n\
	movs r6, #0\n\
	cmp r6, r4\n\
	bhs _080F4378\n\
	ldr r4, _080F4454 @ =u8_ARRAY_083863e8\n\
	mov sl, r4\n\
	adds r4, r2, #0\n\
	mov sb, r5\n\
	movs r5, #0xaf\n\
	lsls r5, r5, #1\n\
	mov ip, r5\n\
_080F4344:\n\
	adds r2, r3, r6\n\
	lsls r2, r2, #1\n\
	add r2, r8\n\
	add r2, ip\n\
	ldrb r0, [r4, #2]\n\
	lsls r0, r0, #1\n\
	add r0, sl\n\
	ldrb r0, [r0]\n\
	movs r5, #0xc0\n\
	lsls r5, r5, #2\n\
	adds r1, r5, #0\n\
	adds r0, r0, r1\n\
	adds r0, r0, r6\n\
	ldr r5, _080F4450 @ =0xFFFFF000\n\
	adds r1, r5, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	ldrb r0, [r4, #2]\n\
	lsls r0, r0, #1\n\
	add r0, sb\n\
	ldrb r0, [r0]\n\
	cmp r6, r0\n\
	blo _080F4344\n\
_080F4378:\n\
	movs r0, #4\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	ldr r0, _080F4458 @ =0x00000DCC\n\
	adds r4, r7, r0\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #0\n\
	beq _080F43A2\n\
	adds r0, #0xab\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	ldrb r0, [r4, #0x10]\n\
	adds r0, #0xab\n\
	bl UpdateBlinkMotionState\n\
	ldrb r0, [r4, #0x10]\n\
	adds r0, #0xab\n\
	bl ClearBlink\n\
_080F43A2:\n\
	movs r4, #0x8c\n\
	lsls r4, r4, #1\n\
	ldr r1, _080F445C @ =gStaticMotionGraphics\n\
	mov r8, r1\n\
	adds r0, r4, r1\n\
	ldr r6, _080F4460 @ =wStaticGraphicTilenums\n\
	ldrh r1, [r6, #0x1c]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r3, _080F4464 @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r3\n\
	ldr r5, _080F4468 @ =wStaticMotionPalIDs\n\
	ldrh r1, [r5, #0x1c]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	mov sl, r0\n\
	add r1, sl\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	movs r4, #0x96\n\
	lsls r4, r4, #1\n\
	mov r1, r8\n\
	adds r0, r4, r1\n\
	ldrh r1, [r6, #0x1e]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r3, _080F4464 @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r3\n\
	ldrh r1, [r5, #0x1e]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	add r1, sl\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	ldr r4, _080F446C @ =0x00000A14\n\
	add r8, r4\n\
	movs r0, #0x81\n\
	lsls r0, r0, #1\n\
	mov sb, r0\n\
	add r6, sb\n\
	ldrh r1, [r6]\n\
	mov r2, r8\n\
	ldrh r0, [r2, #6]\n\
	lsrs r0, r0, #6\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r3, #0x80\n\
	lsls r3, r3, #9\n\
	adds r1, r1, r3\n\
	mov r0, r8\n\
	bl LoadGraphic\n\
	ldr r0, _080F4464 @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r0\n\
	add r5, sb\n\
	ldrh r1, [r5]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	add r1, sl\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	movs r6, #0\n\
	b _080F4480\n\
	.align 2, 0\n\
_080F444C: .4byte u8_ARRAY_083863d0\n\
_080F4450: .4byte 0xFFFFF000\n\
_080F4454: .4byte u8_ARRAY_083863e8\n\
_080F4458: .4byte 0x00000DCC\n\
_080F445C: .4byte gStaticMotionGraphics\n\
_080F4460: .4byte wStaticGraphicTilenums\n\
_080F4464: .4byte gStaticMotionGraphics+12\n\
_080F4468: .4byte wStaticMotionPalIDs\n\
_080F446C: .4byte 0x00000A14\n\
_080F4470:\n\
	adds r0, r7, #0\n\
	adds r1, r6, #0\n\
	movs r2, #0\n\
	bl CreateMenuHPGauge\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
_080F4480:\n\
	ldr r0, [sp]\n\
	bl getMaxHP1x\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x1a\n\
	cmp r6, r0\n\
	blo _080F4470\n\
	ldr r1, _080F4664 @ =0x00000DCC\n\
	adds r4, r7, r1\n\
	movs r0, #0\n\
	strb r0, [r4, #0xf]\n\
	adds r0, r7, #0\n\
	movs r1, #0\n\
	movs r2, #0\n\
	bl CreateMenuComp1\n\
	ldr r2, [sp, #4]\n\
	ldrb r1, [r2, #0xc]\n\
	adds r0, r7, #0\n\
	movs r2, #0\n\
	movs r3, #0\n\
	bl createMenuWeaponIcon\n\
	str r0, [r4, #0x14]\n\
	ldrb r0, [r4, #0xf]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xf]\n\
	adds r0, r7, #0\n\
	movs r1, #1\n\
	movs r2, #0\n\
	bl CreateMenuComp1\n\
	ldr r3, [sp, #4]\n\
	ldrb r1, [r3, #0xd]\n\
	adds r0, r7, #0\n\
	movs r2, #1\n\
	movs r3, #0\n\
	bl createMenuWeaponIcon\n\
	str r0, [r4, #0x18]\n\
	ldrb r1, [r4, #0xf]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xf]\n\
	movs r6, #0\n\
	ldr r5, _080F4664 @ =0x00000DCC\n\
	adds r4, r7, r5\n\
_080F44E0:\n\
	ldr r1, [sp, #8]\n\
	adds r0, r1, r6\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xff\n\
	beq _080F44FA\n\
	ldrb r2, [r4, #0xe]\n\
	adds r0, r7, #0\n\
	adds r1, r6, #0\n\
	bl CreateSubtankIcon\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080F44FA:\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, #3\n\
	bls _080F44E0\n\
	ldr r2, _080F4664 @ =0x00000DCC\n\
	adds r4, r7, r2\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	beq _080F4520\n\
	adds r0, r7, #0\n\
	movs r1, #2\n\
	movs r2, #0\n\
	bl CreateMenuComp1\n\
	ldrb r1, [r4, #0xf]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xf]\n\
_080F4520:\n\
	ldr r3, [sp, #4]\n\
	ldrb r1, [r3, #0x17]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F453C\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F453C\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F455C\n\
_080F453C:\n\
	adds r0, r7, #0\n\
	movs r1, #3\n\
	movs r2, #0\n\
	bl CreateMenuComp1\n\
	adds r0, r7, #0\n\
	movs r1, #0\n\
	movs r2, #0\n\
	bl CreateArmorIcons\n\
	ldr r4, _080F4664 @ =0x00000DCC\n\
	adds r2, r7, r4\n\
	ldrb r1, [r2, #0xf]\n\
	movs r0, #8\n\
	orrs r0, r1\n\
	strb r0, [r2, #0xf]\n\
_080F455C:\n\
	ldr r5, [sp, #4]\n\
	ldrb r1, [r5, #0x18]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F4588\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F4588\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F4588\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F4588\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F45A8\n\
_080F4588:\n\
	adds r0, r7, #0\n\
	movs r1, #4\n\
	movs r2, #0\n\
	bl CreateMenuComp1\n\
	adds r0, r7, #0\n\
	movs r1, #0\n\
	movs r2, #1\n\
	bl CreateArmorIcons\n\
	ldr r0, _080F4664 @ =0x00000DCC\n\
	adds r2, r7, r0\n\
	ldrb r1, [r2, #0xf]\n\
	movs r0, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r2, #0xf]\n\
_080F45A8:\n\
	ldr r2, [sp, #4]\n\
	ldrb r1, [r2, #0x19]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F45E4\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F45E4\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F45E4\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F45E4\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F45E4\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F45E4\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4604\n\
_080F45E4:\n\
	adds r0, r7, #0\n\
	movs r1, #5\n\
	movs r2, #0\n\
	bl CreateMenuComp1\n\
	adds r0, r7, #0\n\
	movs r1, #0\n\
	movs r2, #2\n\
	bl CreateArmorIcons\n\
	ldr r3, _080F4664 @ =0x00000DCC\n\
	adds r2, r7, r3\n\
	ldrb r1, [r2, #0xf]\n\
	movs r0, #0x20\n\
	orrs r0, r1\n\
	strb r0, [r2, #0xf]\n\
_080F4604:\n\
	ldr r5, _080F4664 @ =0x00000DCC\n\
	adds r4, r7, r5\n\
	movs r0, #0\n\
	str r0, [r4, #0x20]\n\
	adds r0, r7, #0\n\
	movs r1, #6\n\
	movs r2, #0\n\
	bl CreateMenuComp1\n\
	ldrb r1, [r4, #0xf]\n\
	movs r0, #0x40\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xf]\n\
	movs r1, #0x38\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4638\n\
	ldr r1, _080F4668 @ =0x00000ED8\n\
	adds r0, r7, r1\n\
	ldr r2, _080F466C @ =0x08522300\n\
	ldr r1, [r2]\n\
	adds r1, r1, r2\n\
	movs r2, #0xc\n\
	movs r3, #7\n\
	bl CopyBgMap\n\
_080F4638:\n\
	ldr r2, _080F4668 @ =0x00000ED8\n\
	adds r0, r7, r2\n\
	ldr r1, _080F4670 @ =gVideoRegBuffer+6\n\
	ldrh r2, [r1]\n\
	movs r1, #0xf8\n\
	lsls r1, r1, #5\n\
	ands r1, r2\n\
	lsls r1, r1, #3\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
	bl RequestBgMapTransfer\n\
	movs r0, #2\n\
	strb r0, [r7, #2]\n\
	add sp, #0xc\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F4664: .4byte 0x00000DCC\n\
_080F4668: .4byte 0x00000ED8\n\
_080F466C: .4byte gBgMapOffsets+(24*4)\n\
_080F4670: .4byte gVideoRegBuffer+6\n\
 .syntax divided\n");
}

// 01 02 01 xx
NAKED static void MainMenuLoop_Update(struct GameState* m) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r6, r0, #0\n\
	ldr r1, _080F4710 @ =0x000064AC\n\
	adds r0, r6, r1\n\
	ldr r7, [r0]\n\
	ldr r1, _080F4714 @ =gMainMenuFocusLoops\n\
	ldrb r0, [r6, #3]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	adds r0, r6, #0\n\
	bl _call_via_r1\n\
	ldr r0, _080F4718 @ =0x00000DCC\n\
	adds r4, r6, r0\n\
	ldrb r1, [r4, #0xf]\n\
	movs r0, #0x38\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F46A2\n\
	adds r0, r6, #0\n\
	bl menu_080f54a0\n\
_080F46A2:\n\
	movs r0, #4\n\
	bl UpdateBlinkMotionState\n\
	ldrb r2, [r4, #0x10]\n\
	adds r1, r2, #0\n\
	cmp r1, #5\n\
	bhi _080F473E\n\
	ldrb r0, [r4, #0x11]\n\
	cmp r0, #0\n\
	bne _080F46D4\n\
	adds r0, r7, #0\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0x10]\n\
	cmp r1, r0\n\
	beq _080F46CE\n\
	adds r0, r2, #0\n\
	adds r0, #0xab\n\
	strb r0, [r4, #0x11]\n\
	ldrb r0, [r4, #0x11]\n\
	movs r1, #0\n\
	bl LoadBlink\n\
_080F46CE:\n\
	ldrb r0, [r4, #0x11]\n\
	cmp r0, #0\n\
	beq _080F473E\n\
_080F46D4:\n\
	ldr r1, _080F4718 @ =0x00000DCC\n\
	adds r5, r6, r1\n\
	ldrb r0, [r5, #0x11]\n\
	bl UpdateBlinkMotionState\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #3\n\
	bne _080F473E\n\
	ldrb r0, [r5, #0x11]\n\
	bl ClearBlink\n\
	ldrb r0, [r5, #0x11]\n\
	cmp r0, #0xb2\n\
	bhi _080F471C\n\
	adds r0, r7, #0\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0x10]\n\
	strb r0, [r5, #0x10]\n\
	adds r0, #0xb3\n\
	strb r0, [r5, #0x11]\n\
	ldrb r0, [r5, #0x11]\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	ldrb r0, [r5, #0x11]\n\
	bl UpdateBlinkMotionState\n\
	b _080F473E\n\
	.align 2, 0\n\
_080F4710: .4byte 0x000064AC\n\
_080F4714: .4byte gMainMenuFocusLoops\n\
_080F4718: .4byte 0x00000DCC\n\
_080F471C:\n\
	adds r0, r7, #0\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0x10]\n\
	adds r0, #0xab\n\
	movs r4, #0\n\
	strb r0, [r5, #0x11]\n\
	ldrb r0, [r5, #0x11]\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	ldrb r0, [r5, #0x11]\n\
	bl UpdateBlinkMotionState\n\
	ldrb r0, [r5, #0x11]\n\
	bl ClearBlink\n\
	strb r4, [r5, #0x11]\n\
_080F473E:\n\
	adds r0, r6, #0\n\
	bl printMainMenuString\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// 01 02 02 xx
NAKED static void MainMenuLoop_SlideOut(struct GameState* m) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r1, _080F4764 @ =0x00000E19\n\
	adds r0, r2, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	bne _080F476C\n\
	ldr r1, _080F4768 @ =gVideoRegBuffer+16\n\
	ldrh r0, [r1]\n\
	adds r0, #0x10\n\
	b _080F4772\n\
	.align 2, 0\n\
_080F4764: .4byte 0x00000E19\n\
_080F4768: .4byte gVideoRegBuffer+16\n\
_080F476C:\n\
	ldr r1, _080F47A0 @ =gVideoRegBuffer+16\n\
	ldrh r0, [r1]\n\
	subs r0, #0x10\n\
_080F4772:\n\
	strh r0, [r1]\n\
	adds r3, r1, #0\n\
	ldrh r0, [r3]\n\
	ldr r1, _080F47A4 @ =0x000001FF\n\
	ands r1, r0\n\
	strh r1, [r3]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F479C\n\
	ldr r3, _080F47A8 @ =0x00000E19\n\
	adds r0, r2, r3\n\
	ldrb r1, [r0]\n\
	subs r3, #1\n\
	adds r0, r2, r3\n\
	strb r1, [r0]\n\
	movs r0, #1\n\
	strb r0, [r2, #2]\n\
	adds r0, r2, #0\n\
	bl MainMenuLoop_Exit\n\
_080F479C:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F47A0: .4byte gVideoRegBuffer+16\n\
_080F47A4: .4byte 0x000001FF\n\
_080F47A8: .4byte 0x00000E19\n\
 .syntax divided\n");
}

// 01 02 03 xx
NAKED static void MainMenuLoop_Exit(struct GameState* m) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	ldr r1, _080F47D8 @ =0x00000DCC\n\
	adds r4, r0, r1\n\
	movs r0, #1\n\
	strb r0, [r4, #4]\n\
	ldrb r0, [r4, #3]\n\
	cmp r0, #0xff\n\
	beq _080F47C0\n\
	bl ClearBlink\n\
_080F47C0:\n\
	ldrb r0, [r4, #0x11]\n\
	cmp r0, #0\n\
	beq _080F47CA\n\
	bl ClearBlink\n\
_080F47CA:\n\
	movs r0, #4\n\
	bl ClearBlink\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F47D8: .4byte 0x00000DCC\n\
 .syntax divided\n");
}

// --------------------------------------------

// 01 02 01 00
NAKED static void MainMenuFocusLoop_NoFocus(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	adds r4, r0, #0\n\
	ldr r0, _080F4828 @ =0x00000DCC\n\
	mov sb, r0\n\
	adds r6, r4, r0\n\
	ldr r2, _080F482C @ =0x00000E17\n\
	adds r1, r4, r2\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	bl TrySlideMenu\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	cmp r3, #0\n\
	beq _080F4804\n\
	b _080F4908\n\
_080F4804:\n\
	ldr r2, _080F4830 @ =gJoypad\n\
	ldrh r1, [r2, #4]\n\
	movs r7, #1\n\
	adds r0, r7, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4858\n\
	ldrb r2, [r6]\n\
	cmp r2, #5\n\
	bhi _080F4834\n\
	adds r0, r2, #1\n\
	strb r0, [r4, #3]\n\
	ldrb r0, [r6]\n\
	cmp r0, #2\n\
	bne _080F4844\n\
	strb r3, [r6, #1]\n\
	b _080F4844\n\
	.align 2, 0\n\
_080F4828: .4byte 0x00000DCC\n\
_080F482C: .4byte 0x00000E17\n\
_080F4830: .4byte gJoypad\n\
_080F4834:\n\
	ldr r0, _080F484C @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4850\n\
	adds r0, r2, #1\n\
	strb r0, [r4, #3]\n\
_080F4844:\n\
	movs r0, #2\n\
	bl PlaySound\n\
	b _080F4908\n\
	.align 2, 0\n\
_080F484C: .4byte gCurStory\n\
_080F4850:\n\
	movs r0, #4\n\
	bl PlaySound\n\
	b _080F4908\n\
_080F4858:\n\
	movs r5, #0xff\n\
	ldrh r1, [r2, #6]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4866\n\
	movs r5, #0\n\
_080F4866:\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4870\n\
	movs r5, #1\n\
_080F4870:\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F487A\n\
	movs r5, #2\n\
_080F487A:\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4884\n\
	movs r5, #3\n\
_080F4884:\n\
	ldrb r0, [r6]\n\
	mov r8, r0\n\
	cmp r5, #0xff\n\
	beq _080F4908\n\
	ldr r0, _080F48A8 @ =u8_ARRAY_ARRAY_08386398\n\
	mov r2, r8\n\
	lsls r1, r2, #2\n\
	adds r1, r5, r1\n\
	adds r1, r1, r0\n\
	ldrb r3, [r1]\n\
	ldrb r0, [r6, #0xf]\n\
	asrs r0, r3\n\
	ands r0, r7\n\
	cmp r0, #0\n\
	beq _080F48C0\n\
	strb r3, [r6]\n\
	b _080F48F8\n\
	.align 2, 0\n\
_080F48A8: .4byte u8_ARRAY_ARRAY_08386398\n\
_080F48AC:\n\
	movs r0, #1\n\
	strb r0, [r2]\n\
	b _080F48F8\n\
_080F48B2:\n\
	ldr r0, _080F48BC @ =0x00000DCC\n\
	adds r1, r4, r0\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	b _080F48F8\n\
	.align 2, 0\n\
_080F48BC: .4byte 0x00000DCC\n\
_080F48C0:\n\
	mov r6, sb\n\
	ldr r1, _080F4914 @ =u8_ARRAY_ARRAY_083863b4\n\
	mov ip, r1\n\
	movs r7, #8\n\
_080F48C8:\n\
	cmp r3, #4\n\
	bne _080F48DC\n\
	cmp r5, #0\n\
	bne _080F48DC\n\
	adds r2, r4, r6\n\
	ldrb r1, [r2, #0xf]\n\
	adds r0, r7, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F48AC\n\
_080F48DC:\n\
	lsls r0, r3, #2\n\
	adds r0, r5, r0\n\
	add r0, ip\n\
	ldrb r3, [r0]\n\
	cmp r3, #0xff\n\
	beq _080F48B2\n\
	adds r2, r4, r6\n\
	ldrb r0, [r2, #0xf]\n\
	asrs r0, r3\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F48C8\n\
	strb r3, [r2]\n\
_080F48F8:\n\
	ldr r2, _080F4918 @ =0x00000DCC\n\
	adds r0, r4, r2\n\
	ldrb r0, [r0]\n\
	cmp r8, r0\n\
	beq _080F4908\n\
	movs r0, #1\n\
	bl PlaySound\n\
_080F4908:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F4914: .4byte u8_ARRAY_ARRAY_083863b4\n\
_080F4918: .4byte 0x00000DCC\n\
 .syntax divided\n");
}

// 01 02 01 01
NAKED static void MainMenuFocusLoop_MainWeapon(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #4\n\
	adds r5, r0, #0\n\
	ldr r1, _080F4940 @ =0x000064AC\n\
	adds r0, r5, r1\n\
	ldr r7, [r0]\n\
	ldr r2, _080F4944 @ =0x00000DCC\n\
	adds r4, r5, r2\n\
	ldr r0, _080F4948 @ =0x00000E17\n\
	adds r6, r5, r0\n\
	ldrb r2, [r6]\n\
	cmp r2, #1\n\
	beq _080F4998\n\
	cmp r2, #1\n\
	bgt _080F494C\n\
	cmp r2, #0\n\
	beq _080F4954\n\
	b _080F4A6C\n\
	.align 2, 0\n\
_080F4940: .4byte 0x000064AC\n\
_080F4944: .4byte 0x00000DCC\n\
_080F4948: .4byte 0x00000E17\n\
_080F494C:\n\
	cmp r2, #2\n\
	bne _080F4952\n\
	b _080F4A5C\n\
_080F4952:\n\
	b _080F4A6C\n\
_080F4954:\n\
	ldr r2, _080F4994 @ =0x00000E1D\n\
	adds r1, r5, r2\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r0, [r4, #0x14]\n\
	ldrb r0, [r0, #0xd]\n\
	cmp r0, #2\n\
	bhi _080F4966\n\
	b _080F4A6C\n\
_080F4966:\n\
	adds r0, r5, #0\n\
	movs r1, #0\n\
	movs r2, #0\n\
	bl CreateMenuComp2\n\
	str r0, [r4, #0x1c]\n\
	adds r1, r7, #0\n\
	adds r1, #0xb4\n\
	ldrb r1, [r1, #0xc]\n\
	strb r1, [r4, #1]\n\
	ldrb r1, [r4, #1]\n\
	lsls r1, r1, #4\n\
	adds r1, #0x44\n\
	adds r0, #0x74\n\
	strh r1, [r0]\n\
	ldr r0, [r4, #0x1c]\n\
	adds r0, #0x76\n\
	movs r1, #0x38\n\
	strh r1, [r0]\n\
	ldrb r0, [r6]\n\
	adds r0, #1\n\
	strb r0, [r6]\n\
	b _080F4A6C\n\
	.align 2, 0\n\
_080F4994: .4byte 0x00000E1D\n\
_080F4998:\n\
	ldr r3, _080F49C4 @ =gJoypad\n\
	ldrh r1, [r3, #4]\n\
	movs r0, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F49E4\n\
	ldr r0, [r4, #0x1c]\n\
	adds r0, #0x78\n\
	strb r2, [r0]\n\
	strb r2, [r4, #5]\n\
	ldrb r0, [r6]\n\
	adds r0, #1\n\
	strb r0, [r6]\n\
	ldrh r1, [r3, #4]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F49C8\n\
	movs r0, #3\n\
	bl PlaySound\n\
	b _080F4A6C\n\
	.align 2, 0\n\
_080F49C4: .4byte gJoypad\n\
_080F49C8:\n\
	adds r1, r7, #0\n\
	adds r1, #0xb4\n\
	ldrb r0, [r1, #0xd]\n\
	ldrb r2, [r4, #1]\n\
	cmp r0, r2\n\
	bne _080F49D8\n\
	ldrb r0, [r1, #0xc]\n\
	strb r0, [r1, #0xd]\n\
_080F49D8:\n\
	ldrb r0, [r4, #1]\n\
	strb r0, [r1, #0xc]\n\
	movs r0, #2\n\
	bl PlaySound\n\
	b _080F4A6C\n\
_080F49E4:\n\
	adds r0, r7, #0\n\
	adds r0, #0xb4\n\
	ldrb r1, [r0, #0x16]\n\
	movs r0, #0xc\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4A2C\n\
	ldrh r1, [r3, #6]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4A10\n\
	ldrb r0, [r4, #1]\n\
	adds r0, #1\n\
	movs r1, #3\n\
	ands r0, r1\n\
	strb r0, [r4, #1]\n\
	movs r0, #1\n\
	str r3, [sp]\n\
	bl PlaySound\n\
	ldr r3, [sp]\n\
_080F4A10:\n\
	ldrh r1, [r3, #6]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4A46\n\
	ldrb r0, [r4, #1]\n\
	adds r0, #3\n\
	movs r1, #3\n\
	ands r0, r1\n\
	strb r0, [r4, #1]\n\
	movs r0, #1\n\
	bl PlaySound\n\
	b _080F4A46\n\
_080F4A2C:\n\
	ldrh r1, [r3, #6]\n\
	movs r0, #0x30\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4A46\n\
	ldrb r0, [r4, #1]\n\
	adds r0, #1\n\
	movs r1, #1\n\
	ands r0, r1\n\
	strb r0, [r4, #1]\n\
	movs r0, #1\n\
	bl PlaySound\n\
_080F4A46:\n\
	ldr r1, _080F4A58 @ =0x00000DCC\n\
	adds r0, r5, r1\n\
	ldr r1, [r0, #0x1c]\n\
	ldrb r0, [r0, #1]\n\
	lsls r0, r0, #4\n\
	adds r0, #0x44\n\
	adds r1, #0x74\n\
	strh r0, [r1]\n\
	b _080F4A6C\n\
	.align 2, 0\n\
_080F4A58: .4byte 0x00000DCC\n\
_080F4A5C:\n\
	ldr r2, _080F4A74 @ =0x00000E1D\n\
	adds r1, r5, r2\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldrb r0, [r4, #5]\n\
	cmp r0, #0\n\
	bne _080F4A6C\n\
	strb r0, [r5, #3]\n\
_080F4A6C:\n\
	add sp, #4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F4A74: .4byte 0x00000E1D\n\
 .syntax divided\n");
}

NAKED static void MainMenuFocusLoop_SubWeapon(struct GameState* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #4\n\
	adds r5, r0, #0\n\
	ldr r1, _080F4A9C @ =0x000064AC\n\
	adds r0, r5, r1\n\
	ldr r7, [r0]\n\
	ldr r2, _080F4AA0 @ =0x00000DCC\n\
	adds r4, r5, r2\n\
	ldr r0, _080F4AA4 @ =0x00000E17\n\
	adds r6, r5, r0\n\
	ldrb r2, [r6]\n\
	cmp r2, #1\n\
	beq _080F4AF4\n\
	cmp r2, #1\n\
	bgt _080F4AA8\n\
	cmp r2, #0\n\
	beq _080F4AB0\n\
	b _080F4BC8\n\
	.align 2, 0\n\
_080F4A9C: .4byte 0x000064AC\n\
_080F4AA0: .4byte 0x00000DCC\n\
_080F4AA4: .4byte 0x00000E17\n\
_080F4AA8:\n\
	cmp r2, #2\n\
	bne _080F4AAE\n\
	b _080F4BB8\n\
_080F4AAE:\n\
	b _080F4BC8\n\
_080F4AB0:\n\
	ldr r2, _080F4AF0 @ =0x00000E1D\n\
	adds r1, r5, r2\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r0, [r0, #0xd]\n\
	cmp r0, #2\n\
	bhi _080F4AC2\n\
	b _080F4BC8\n\
_080F4AC2:\n\
	adds r0, r5, #0\n\
	movs r1, #0\n\
	movs r2, #0\n\
	bl CreateMenuComp2\n\
	str r0, [r4, #0x1c]\n\
	adds r1, r7, #0\n\
	adds r1, #0xb4\n\
	ldrb r1, [r1, #0xd]\n\
	strb r1, [r4, #1]\n\
	ldrb r1, [r4, #1]\n\
	lsls r1, r1, #4\n\
	adds r1, #0x44\n\
	adds r0, #0x74\n\
	strh r1, [r0]\n\
	ldr r0, [r4, #0x1c]\n\
	adds r0, #0x76\n\
	movs r1, #0x50\n\
	strh r1, [r0]\n\
	ldrb r0, [r6]\n\
	adds r0, #1\n\
	strb r0, [r6]\n\
	b _080F4BC8\n\
	.align 2, 0\n\
_080F4AF0: .4byte 0x00000E1D\n\
_080F4AF4:\n\
	ldr r3, _080F4B20 @ =gJoypad\n\
	ldrh r1, [r3, #4]\n\
	movs r0, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4B40\n\
	ldr r0, [r4, #0x1c]\n\
	adds r0, #0x78\n\
	strb r2, [r0]\n\
	strb r2, [r4, #5]\n\
	ldrb r0, [r6]\n\
	adds r0, #1\n\
	strb r0, [r6]\n\
	ldrh r1, [r3, #4]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4B24\n\
	movs r0, #3\n\
	bl PlaySound\n\
	b _080F4BC8\n\
	.align 2, 0\n\
_080F4B20: .4byte gJoypad\n\
_080F4B24:\n\
	adds r1, r7, #0\n\
	adds r1, #0xb4\n\
	ldrb r0, [r1, #0xc]\n\
	ldrb r2, [r4, #1]\n\
	cmp r0, r2\n\
	bne _080F4B34\n\
	ldrb r0, [r1, #0xd]\n\
	strb r0, [r1, #0xc]\n\
_080F4B34:\n\
	ldrb r0, [r4, #1]\n\
	strb r0, [r1, #0xd]\n\
	movs r0, #2\n\
	bl PlaySound\n\
	b _080F4BC8\n\
_080F4B40:\n\
	adds r0, r7, #0\n\
	adds r0, #0xb4\n\
	ldrb r1, [r0, #0x16]\n\
	movs r0, #0xc\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4B88\n\
	ldrh r1, [r3, #6]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4B6C\n\
	ldrb r0, [r4, #1]\n\
	adds r0, #1\n\
	movs r1, #3\n\
	ands r0, r1\n\
	strb r0, [r4, #1]\n\
	movs r0, #1\n\
	str r3, [sp]\n\
	bl PlaySound\n\
	ldr r3, [sp]\n\
_080F4B6C:\n\
	ldrh r1, [r3, #6]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4BA2\n\
	ldrb r0, [r4, #1]\n\
	adds r0, #3\n\
	movs r1, #3\n\
	ands r0, r1\n\
	strb r0, [r4, #1]\n\
	movs r0, #1\n\
	bl PlaySound\n\
	b _080F4BA2\n\
_080F4B88:\n\
	ldrh r1, [r3, #6]\n\
	movs r0, #0x30\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4BA2\n\
	ldrb r0, [r4, #1]\n\
	adds r0, #1\n\
	movs r1, #1\n\
	ands r0, r1\n\
	strb r0, [r4, #1]\n\
	movs r0, #1\n\
	bl PlaySound\n\
_080F4BA2:\n\
	ldr r1, _080F4BB4 @ =0x00000DCC\n\
	adds r0, r5, r1\n\
	ldr r1, [r0, #0x1c]\n\
	ldrb r0, [r0, #1]\n\
	lsls r0, r0, #4\n\
	adds r0, #0x44\n\
	adds r1, #0x74\n\
	strh r0, [r1]\n\
	b _080F4BC8\n\
	.align 2, 0\n\
_080F4BB4: .4byte 0x00000DCC\n\
_080F4BB8:\n\
	ldr r2, _080F4BD0 @ =0x00000E1D\n\
	adds r1, r5, r2\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldrb r0, [r4, #5]\n\
	cmp r0, #0\n\
	bne _080F4BC8\n\
	strb r0, [r5, #3]\n\
_080F4BC8:\n\
	add sp, #4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F4BD0: .4byte 0x00000E1D\n\
 .syntax divided\n");
}

NAKED static void MainMenuFocusLoop_Subtank(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r5, r0, #0\n\
	ldr r1, _080F4C28 @ =0x000064AC\n\
	adds r0, r5, r1\n\
	ldr r7, [r0]\n\
	movs r1, #0\n\
	movs r2, #0\n\
	movs r0, #0xbc\n\
	adds r0, r0, r7\n\
	mov r8, r0\n\
	mov r4, r8\n\
	ldr r0, _080F4C2C @ =0x00000DCC\n\
	adds r3, r5, r0\n\
_080F4BF2:\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xff\n\
	beq _080F4C06\n\
	ldrb r0, [r3, #1]\n\
	cmp r2, r0\n\
	beq _080F4C4C\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
_080F4C06:\n\
	adds r0, r1, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, #3\n\
	bls _080F4BF2\n\
_080F4C10:\n\
	ldr r1, _080F4C30 @ =0x00000E17\n\
	adds r0, r5, r1\n\
	ldrb r1, [r0]\n\
	adds r6, r0, #0\n\
	cmp r1, #4\n\
	bls _080F4C1E\n\
	b _080F4E16\n\
_080F4C1E:\n\
	lsls r0, r1, #2\n\
	ldr r1, _080F4C34 @ =_080F4C38\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080F4C28: .4byte 0x000064AC\n\
_080F4C2C: .4byte 0x00000DCC\n\
_080F4C30: .4byte 0x00000E17\n\
_080F4C34: .4byte _080F4C38\n\
_080F4C38: @ jump table\n\
	.4byte _080F4C58 @ case 0\n\
	.4byte _080F4C7C @ case 1\n\
	.4byte _080F4CC0 @ case 2\n\
	.4byte _080F4D98 @ case 3\n\
	.4byte _080F4DF2 @ case 4\n\
_080F4C4C:\n\
	ldr r2, _080F4C54 @ =0x00000E1B\n\
	adds r0, r5, r2\n\
	strb r1, [r0]\n\
	b _080F4C10\n\
	.align 2, 0\n\
_080F4C54: .4byte 0x00000E1B\n\
_080F4C58:\n\
	ldr r0, _080F4C70 @ =0x00000DCC\n\
	adds r3, r5, r0\n\
	ldr r2, _080F4C74 @ =0x00000E1D\n\
	adds r1, r5, r2\n\
	movs r2, #0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	str r2, [r3, #0x1c]\n\
	ldr r0, _080F4C78 @ =0x00000E1A\n\
	adds r1, r5, r0\n\
	movs r0, #8\n\
	b _080F4D12\n\
	.align 2, 0\n\
_080F4C70: .4byte 0x00000DCC\n\
_080F4C74: .4byte 0x00000E1D\n\
_080F4C78: .4byte 0x00000E1A\n\
_080F4C7C:\n\
	ldr r1, _080F4CB4 @ =0x00000DCC\n\
	adds r4, r5, r1\n\
	ldr r2, _080F4CB8 @ =0x00000E1D\n\
	adds r1, r5, r2\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r0, _080F4CBC @ =0x00000E1A\n\
	adds r1, r5, r0\n\
	ldrb r0, [r1]\n\
	subs r0, #1\n\
	strb r0, [r1]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	beq _080F4C9C\n\
	b _080F4E16\n\
_080F4C9C:\n\
	adds r0, r5, #0\n\
	movs r1, #0\n\
	movs r2, #0\n\
	bl CreateMenuComp2\n\
	str r0, [r4, #0x1c]\n\
	adds r0, #0x76\n\
	movs r2, #0\n\
	movs r1, #0x68\n\
	strh r1, [r0]\n\
	strb r2, [r4, #1]\n\
	b _080F4D14\n\
	.align 2, 0\n\
_080F4CB4: .4byte 0x00000DCC\n\
_080F4CB8: .4byte 0x00000E1D\n\
_080F4CBC: .4byte 0x00000E1A\n\
_080F4CC0:\n\
	ldr r2, _080F4CEC @ =gJoypad\n\
	ldrh r1, [r2, #4]\n\
	movs r4, #1\n\
	ands r4, r1\n\
	cmp r4, #0\n\
	beq _080F4D20\n\
	adds r0, r7, #0\n\
	bl GetMaxHP\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	adds r1, r7, #0\n\
	adds r1, #0xa4\n\
	movs r2, #0\n\
	ldrsh r1, [r1, r2]\n\
	cmp r0, r1\n\
	bne _080F4CF0\n\
	movs r0, #4\n\
	bl PlaySound\n\
	b _080F4E2A\n\
	.align 2, 0\n\
_080F4CEC: .4byte gJoypad\n\
_080F4CF0:\n\
	ldr r1, _080F4D08 @ =0x00000E1B\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0]\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080F4D0C\n\
	movs r0, #4\n\
	bl PlaySound\n\
	b _080F4E16\n\
	.align 2, 0\n\
_080F4D08: .4byte 0x00000E1B\n\
_080F4D0C:\n\
	ldr r2, _080F4D1C @ =0x00000E1A\n\
	adds r1, r5, r2\n\
	movs r0, #0\n\
_080F4D12:\n\
	strb r0, [r1]\n\
_080F4D14:\n\
	ldrb r0, [r6]\n\
	adds r0, #1\n\
	strb r0, [r6]\n\
	b _080F4E16\n\
	.align 2, 0\n\
_080F4D1C: .4byte 0x00000E1A\n\
_080F4D20:\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4D54\n\
	movs r0, #3\n\
	bl PlaySound\n\
	ldr r0, _080F4D4C @ =0x00000DCC\n\
	adds r2, r5, r0\n\
	ldr r0, [r2, #0x1c]\n\
	adds r0, #0x78\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	str r4, [r2, #0x1c]\n\
	ldr r2, _080F4D50 @ =0x00000E1A\n\
	adds r1, r5, r2\n\
	movs r0, #8\n\
	strb r0, [r1]\n\
	ldrb r0, [r6]\n\
	adds r0, #2\n\
	strb r0, [r6]\n\
	b _080F4E16\n\
	.align 2, 0\n\
_080F4D4C: .4byte 0x00000DCC\n\
_080F4D50: .4byte 0x00000E1A\n\
_080F4D54:\n\
	ldr r0, _080F4D94 @ =0x00000DCC\n\
	adds r4, r5, r0\n\
	ldrb r7, [r4, #1]\n\
	ldrh r6, [r2, #6]\n\
	movs r0, #0x10\n\
	ands r0, r6\n\
	cmp r0, #0\n\
	beq _080F4D6E\n\
	adds r0, r7, #1\n\
	ldrb r1, [r4, #0xe]\n\
	bl __modsi3\n\
	strb r0, [r4, #1]\n\
_080F4D6E:\n\
	movs r0, #0x20\n\
	ands r0, r6\n\
	cmp r0, #0\n\
	beq _080F4D84\n\
	ldrb r0, [r4, #1]\n\
	subs r0, #1\n\
	ldrb r1, [r4, #0xe]\n\
	adds r0, r0, r1\n\
	bl __modsi3\n\
	strb r0, [r4, #1]\n\
_080F4D84:\n\
	ldrb r4, [r4, #1]\n\
	cmp r7, r4\n\
	beq _080F4E16\n\
	movs r0, #1\n\
	bl PlaySound\n\
	b _080F4E16\n\
	.align 2, 0\n\
_080F4D94: .4byte 0x00000DCC\n\
_080F4D98:\n\
	ldr r2, _080F4DE0 @ =0x00000E1D\n\
	adds r1, r5, r2\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r0, _080F4DE4 @ =0x00000E1A\n\
	adds r4, r5, r0\n\
	ldrb r0, [r4]\n\
	subs r0, #1\n\
	strb r0, [r4]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080F4E16\n\
	ldr r1, _080F4DE8 @ =0x00000E1B\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0]\n\
	mov r2, r8\n\
	adds r1, r2, r0\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	beq _080F4DD2\n\
	subs r0, #1\n\
	strb r0, [r1]\n\
	adds r0, r7, #0\n\
	bl UseSubtank\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080F4DEC\n\
_080F4DD2:\n\
	adds r0, r7, #0\n\
	bl SortSubtank\n\
	movs r0, #2\n\
	strb r0, [r6]\n\
	b _080F4E16\n\
	.align 2, 0\n\
_080F4DE0: .4byte 0x00000E1D\n\
_080F4DE4: .4byte 0x00000E1A\n\
_080F4DE8: .4byte 0x00000E1B\n\
_080F4DEC:\n\
	movs r0, #3\n\
	strb r0, [r4]\n\
	b _080F4E16\n\
_080F4DF2:\n\
	ldr r0, _080F4E34 @ =0x00000E1D\n\
	adds r1, r5, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r2, _080F4E38 @ =0x00000E1A\n\
	adds r1, r5, r2\n\
	ldrb r0, [r1]\n\
	subs r0, #1\n\
	strb r0, [r1]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080F4E16\n\
	adds r0, r7, #0\n\
	bl SortSubtank\n\
	movs r0, #0\n\
	strb r0, [r5, #3]\n\
_080F4E16:\n\
	ldr r1, _080F4E3C @ =0x00000DCC\n\
	adds r0, r5, r1\n\
	ldr r1, [r0, #0x1c]\n\
	cmp r1, #0\n\
	beq _080F4E2A\n\
	ldrb r0, [r0, #1]\n\
	lsls r0, r0, #4\n\
	adds r0, #0x44\n\
	adds r1, #0x74\n\
	strh r0, [r1]\n\
_080F4E2A:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F4E34: .4byte 0x00000E1D\n\
_080F4E38: .4byte 0x00000E1A\n\
_080F4E3C: .4byte 0x00000DCC\n\
 .syntax divided\n");
}

NAKED static void MainMenuFocusLoop_Head(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	adds r7, r0, #0\n\
	ldr r1, _080F4E70 @ =0x000064AC\n\
	adds r0, r7, r1\n\
	ldr r0, [r0]\n\
	mov sb, r0\n\
	ldr r0, _080F4E74 @ =0x00000DCC\n\
	adds r4, r7, r0\n\
	ldr r1, [r4, #0x20]\n\
	mov r8, r1\n\
	adds r0, #0x4b\n\
	adds r6, r7, r0\n\
	ldrb r5, [r6]\n\
	cmp r5, #1\n\
	beq _080F4F14\n\
	cmp r5, #1\n\
	bgt _080F4E78\n\
	cmp r5, #0\n\
	beq _080F4E8C\n\
	b _080F5016\n\
	.align 2, 0\n\
_080F4E70: .4byte 0x000064AC\n\
_080F4E74: .4byte 0x00000DCC\n\
_080F4E78:\n\
	cmp r5, #2\n\
	bne _080F4E7E\n\
	b _080F5006\n\
_080F4E7E:\n\
	b _080F5016\n\
_080F4E80:\n\
	ldr r1, _080F4E88 @ =0x00000DCC\n\
	adds r0, r7, r1\n\
	strb r4, [r0, #1]\n\
	b _080F4EE6\n\
	.align 2, 0\n\
_080F4E88: .4byte 0x00000DCC\n\
_080F4E8C:\n\
	ldr r1, _080F4F0C @ =0x00000E1D\n\
	adds r0, r7, r1\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	ldr r0, [r4, #0x20]\n\
	cmp r0, #0\n\
	bne _080F4E9C\n\
	b _080F5016\n\
_080F4E9C:\n\
	mov r1, r8\n\
	ldrb r0, [r1, #0xd]\n\
	cmp r0, #1\n\
	bhi _080F4EA6\n\
	b _080F5016\n\
_080F4EA6:\n\
	adds r0, r7, #0\n\
	movs r1, #0\n\
	movs r2, #0\n\
	bl CreateMenuComp2\n\
	str r0, [r4, #0x1c]\n\
	strb r5, [r4, #1]\n\
	movs r4, #0\n\
	mov r0, r8\n\
	adds r0, #0x79\n\
	mov r8, r6\n\
	adds r6, r0, #0\n\
	ldrb r0, [r6]\n\
	cmp r5, r0\n\
	bhs _080F4EE6\n\
_080F4EC4:\n\
	adds r0, r7, #0\n\
	adds r1, r4, #0\n\
	bl CheckUnlockedHead\n\
	mov r1, sb\n\
	adds r1, #0xb4\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldrb r1, [r1, #0xf]\n\
	cmp r0, r1\n\
	beq _080F4E80\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	ldrb r1, [r6]\n\
	cmp r4, r1\n\
	blo _080F4EC4\n\
_080F4EE6:\n\
	ldr r0, _080F4F10 @ =0x00000DCC\n\
	adds r3, r7, r0\n\
	ldr r2, [r3, #0x1c]\n\
	ldrb r0, [r3, #1]\n\
	lsls r0, r0, #4\n\
	movs r1, #0x9c\n\
	subs r1, r1, r0\n\
	adds r2, #0x74\n\
	strh r1, [r2]\n\
	ldr r0, [r3, #0x1c]\n\
	adds r0, #0x76\n\
	movs r1, #0x38\n\
	strh r1, [r0]\n\
	mov r1, r8\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	b _080F5016\n\
	.align 2, 0\n\
_080F4F0C: .4byte 0x00000E1D\n\
_080F4F10: .4byte 0x00000DCC\n\
_080F4F14:\n\
	ldr r2, _080F4F40 @ =gJoypad\n\
	ldrh r1, [r2, #4]\n\
	movs r0, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4F5A\n\
	ldr r0, [r4, #0x1c]\n\
	adds r0, #0x78\n\
	strb r5, [r0]\n\
	strb r5, [r4, #5]\n\
	ldrb r0, [r6]\n\
	adds r0, #1\n\
	strb r0, [r6]\n\
	ldrh r1, [r2, #4]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F4F44\n\
	movs r0, #3\n\
	bl PlaySound\n\
	b _080F5016\n\
	.align 2, 0\n\
_080F4F40: .4byte gJoypad\n\
_080F4F44:\n\
	ldrb r1, [r4, #1]\n\
	adds r0, r7, #0\n\
	bl CheckUnlockedHead\n\
	mov r1, sb\n\
	adds r1, #0xb4\n\
	strb r0, [r1, #0xf]\n\
	movs r0, #2\n\
	bl PlaySound\n\
	b _080F5016\n\
_080F4F5A:\n\
	ldrb r0, [r4, #1]\n\
	mov sb, r0\n\
	ldrh r5, [r2, #6]\n\
	movs r0, #0x20\n\
	ands r0, r5\n\
	adds r6, r5, #0\n\
	cmp r0, #0\n\
	beq _080F4F7A\n\
	mov r0, sb\n\
	adds r0, #1\n\
	mov r1, r8\n\
	adds r1, #0x79\n\
	ldrb r1, [r1]\n\
	bl __modsi3\n\
	strb r0, [r4, #1]\n\
_080F4F7A:\n\
	movs r0, #0x10\n\
	ands r0, r6\n\
	cmp r0, #0\n\
	beq _080F4F94\n\
	ldrb r0, [r4, #1]\n\
	subs r0, #1\n\
	mov r1, r8\n\
	adds r1, #0x79\n\
	ldrb r1, [r1]\n\
	adds r0, r0, r1\n\
	bl __modsi3\n\
	strb r0, [r4, #1]\n\
_080F4F94:\n\
	movs r0, #0xc0\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	beq _080F4FC4\n\
	mov r2, r8\n\
	adds r2, #0x79\n\
	ldrb r0, [r2]\n\
	cmp r0, #4\n\
	bls _080F4FC4\n\
	ldrb r0, [r4, #1]\n\
	cmp r0, #3\n\
	bls _080F4FB2\n\
	subs r0, #4\n\
	strb r0, [r4, #1]\n\
	b _080F4FC4\n\
_080F4FB2:\n\
	ldrb r0, [r4, #1]\n\
	adds r1, r0, #4\n\
	ldrb r0, [r2]\n\
	cmp r1, r0\n\
	blt _080F4FC2\n\
	subs r0, #1\n\
	strb r0, [r4, #1]\n\
	b _080F4FC4\n\
_080F4FC2:\n\
	strb r1, [r4, #1]\n\
_080F4FC4:\n\
	ldr r1, _080F4FF8 @ =0x00000DCC\n\
	adds r4, r7, r1\n\
	ldrb r0, [r4, #1]\n\
	cmp sb, r0\n\
	beq _080F4FD4\n\
	movs r0, #1\n\
	bl PlaySound\n\
_080F4FD4:\n\
	ldr r2, [r4, #0x1c]\n\
	ldrb r1, [r4, #1]\n\
	movs r0, #3\n\
	ands r1, r0\n\
	lsls r1, r1, #4\n\
	movs r0, #0x9c\n\
	subs r0, r0, r1\n\
	adds r2, #0x74\n\
	strh r0, [r2]\n\
	ldrb r0, [r4, #1]\n\
	cmp r0, #3\n\
	bls _080F4FFC\n\
	ldr r0, [r4, #0x1c]\n\
	adds r0, #0x76\n\
	movs r1, #0x48\n\
	strh r1, [r0]\n\
	b _080F5016\n\
	.align 2, 0\n\
_080F4FF8: .4byte 0x00000DCC\n\
_080F4FFC:\n\
	ldr r0, [r4, #0x1c]\n\
	adds r0, #0x76\n\
	movs r1, #0x38\n\
	strh r1, [r0]\n\
	b _080F5016\n\
_080F5006:\n\
	ldr r0, _080F5024 @ =0x00000E1D\n\
	adds r1, r7, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldrb r0, [r4, #5]\n\
	cmp r0, #0\n\
	bne _080F5016\n\
	strb r0, [r7, #3]\n\
_080F5016:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F5024: .4byte 0x00000E1D\n\
 .syntax divided\n");
}

NAKED static void MainMenuFocusLoop_Body(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	adds r7, r0, #0\n\
	ldr r1, _080F5058 @ =0x000064AC\n\
	adds r0, r7, r1\n\
	ldr r0, [r0]\n\
	mov sb, r0\n\
	ldr r0, _080F505C @ =0x00000DCC\n\
	adds r4, r7, r0\n\
	ldr r1, [r4, #0x20]\n\
	mov r8, r1\n\
	adds r0, #0x4b\n\
	adds r6, r7, r0\n\
	ldrb r5, [r6]\n\
	cmp r5, #1\n\
	beq _080F5110\n\
	cmp r5, #1\n\
	bgt _080F5060\n\
	cmp r5, #0\n\
	beq _080F5074\n\
	b _080F523A\n\
	.align 2, 0\n\
_080F5058: .4byte 0x000064AC\n\
_080F505C: .4byte 0x00000DCC\n\
_080F5060:\n\
	cmp r5, #2\n\
	bne _080F5066\n\
	b _080F522A\n\
_080F5066:\n\
	b _080F523A\n\
_080F5068:\n\
	ldr r1, _080F5070 @ =0x00000DCC\n\
	adds r0, r7, r1\n\
	strb r4, [r0, #1]\n\
	b _080F50CE\n\
	.align 2, 0\n\
_080F5070: .4byte 0x00000DCC\n\
_080F5074:\n\
	ldr r1, _080F5108 @ =0x00000E1D\n\
	adds r0, r7, r1\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	ldr r0, [r4, #0x20]\n\
	cmp r0, #0\n\
	bne _080F5084\n\
	b _080F523A\n\
_080F5084:\n\
	mov r1, r8\n\
	ldrb r0, [r1, #0xd]\n\
	cmp r0, #1\n\
	bhi _080F508E\n\
	b _080F523A\n\
_080F508E:\n\
	adds r0, r7, #0\n\
	movs r1, #0\n\
	movs r2, #0\n\
	bl CreateMenuComp2\n\
	str r0, [r4, #0x1c]\n\
	strb r5, [r4, #1]\n\
	movs r4, #0\n\
	mov r0, r8\n\
	adds r0, #0x79\n\
	mov r8, r6\n\
	adds r6, r0, #0\n\
	ldrb r0, [r6]\n\
	cmp r5, r0\n\
	bhs _080F50CE\n\
_080F50AC:\n\
	adds r0, r7, #0\n\
	adds r1, r4, #0\n\
	bl CheckUnlockedBody\n\
	mov r1, sb\n\
	adds r1, #0xb4\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldrb r1, [r1, #0x10]\n\
	cmp r0, r1\n\
	beq _080F5068\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	ldrb r1, [r6]\n\
	cmp r4, r1\n\
	blo _080F50AC\n\
_080F50CE:\n\
	ldr r0, _080F510C @ =0x00000DCC\n\
	adds r5, r7, r0\n\
	ldr r4, [r5, #0x1c]\n\
	ldrb r0, [r5, #1]\n\
	movs r1, #3\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x14\n\
	movs r1, #0x9c\n\
	subs r1, r1, r0\n\
	adds r4, #0x74\n\
	strh r1, [r4]\n\
	ldr r4, [r5, #0x1c]\n\
	ldrb r0, [r5, #1]\n\
	movs r1, #3\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x14\n\
	adds r0, #0x50\n\
	adds r4, #0x76\n\
	strh r0, [r4]\n\
	mov r1, r8\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	b _080F523A\n\
	.align 2, 0\n\
_080F5108: .4byte 0x00000E1D\n\
_080F510C: .4byte 0x00000DCC\n\
_080F5110:\n\
	ldr r2, _080F5140 @ =gJoypad\n\
	ldrh r1, [r2, #4]\n\
	movs r0, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F517C\n\
	ldr r0, [r4, #0x1c]\n\
	adds r0, #0x78\n\
	strb r5, [r0]\n\
	strb r5, [r4, #5]\n\
	ldrb r0, [r6]\n\
	adds r0, #1\n\
	strb r0, [r6]\n\
	ldrh r1, [r2, #4]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r6, r0, #0x10\n\
	cmp r6, #0\n\
	beq _080F5144\n\
	movs r0, #3\n\
	bl PlaySound\n\
	b _080F523A\n\
	.align 2, 0\n\
_080F5140: .4byte gJoypad\n\
_080F5144:\n\
	ldrb r1, [r4, #1]\n\
	adds r0, r7, #0\n\
	bl CheckUnlockedBody\n\
	mov r1, sb\n\
	adds r1, #0xb4\n\
	strb r0, [r1, #0x10]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #3\n\
	bne _080F515E\n\
	strb r5, [r1, #0xe]\n\
	b _080F5174\n\
_080F515E:\n\
	cmp r0, #4\n\
	bne _080F5168\n\
	movs r0, #2\n\
	strb r0, [r1, #0xe]\n\
	b _080F5174\n\
_080F5168:\n\
	cmp r0, #5\n\
	bne _080F5172\n\
	movs r0, #3\n\
	strb r0, [r1, #0xe]\n\
	b _080F5174\n\
_080F5172:\n\
	strb r6, [r1, #0xe]\n\
_080F5174:\n\
	movs r0, #2\n\
	bl PlaySound\n\
	b _080F523A\n\
_080F517C:\n\
	ldrb r0, [r4, #1]\n\
	mov sb, r0\n\
	ldrh r5, [r2, #6]\n\
	movs r0, #0x20\n\
	ands r0, r5\n\
	adds r6, r5, #0\n\
	cmp r0, #0\n\
	beq _080F519C\n\
	mov r0, sb\n\
	adds r0, #1\n\
	mov r1, r8\n\
	adds r1, #0x79\n\
	ldrb r1, [r1]\n\
	bl __modsi3\n\
	strb r0, [r4, #1]\n\
_080F519C:\n\
	movs r0, #0x10\n\
	ands r0, r6\n\
	cmp r0, #0\n\
	beq _080F51B6\n\
	ldrb r0, [r4, #1]\n\
	subs r0, #1\n\
	mov r1, r8\n\
	adds r1, #0x79\n\
	ldrb r1, [r1]\n\
	adds r0, r0, r1\n\
	bl __modsi3\n\
	strb r0, [r4, #1]\n\
_080F51B6:\n\
	movs r0, #0xc0\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	beq _080F51E6\n\
	mov r2, r8\n\
	adds r2, #0x79\n\
	ldrb r0, [r2]\n\
	cmp r0, #3\n\
	bls _080F51E6\n\
	ldrb r0, [r4, #1]\n\
	cmp r0, #2\n\
	bls _080F51D4\n\
	subs r0, #3\n\
	strb r0, [r4, #1]\n\
	b _080F51E6\n\
_080F51D4:\n\
	ldrb r0, [r4, #1]\n\
	adds r1, r0, #3\n\
	ldrb r0, [r2]\n\
	cmp r1, r0\n\
	blt _080F51E4\n\
	subs r0, #1\n\
	strb r0, [r4, #1]\n\
	b _080F51E6\n\
_080F51E4:\n\
	strb r1, [r4, #1]\n\
_080F51E6:\n\
	ldr r1, _080F521C @ =0x00000DCC\n\
	adds r5, r7, r1\n\
	ldrb r0, [r5, #1]\n\
	cmp sb, r0\n\
	beq _080F51F6\n\
	movs r0, #1\n\
	bl PlaySound\n\
_080F51F6:\n\
	ldr r4, [r5, #0x1c]\n\
	ldrb r0, [r5, #1]\n\
	movs r1, #3\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x14\n\
	movs r1, #0x9c\n\
	subs r1, r1, r0\n\
	adds r4, #0x74\n\
	strh r1, [r4]\n\
	ldrb r0, [r5, #1]\n\
	cmp r0, #2\n\
	bls _080F5220\n\
	ldr r0, [r5, #0x1c]\n\
	adds r0, #0x76\n\
	movs r1, #0x60\n\
	strh r1, [r0]\n\
	b _080F523A\n\
	.align 2, 0\n\
_080F521C: .4byte 0x00000DCC\n\
_080F5220:\n\
	ldr r0, [r5, #0x1c]\n\
	adds r0, #0x76\n\
	movs r1, #0x50\n\
	strh r1, [r0]\n\
	b _080F523A\n\
_080F522A:\n\
	ldr r0, _080F5248 @ =0x00000E1D\n\
	adds r1, r7, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldrb r0, [r4, #5]\n\
	cmp r0, #0\n\
	bne _080F523A\n\
	strb r0, [r7, #3]\n\
_080F523A:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F5248: .4byte 0x00000E1D\n\
 .syntax divided\n");
}

NAKED static void MainMenuFocusLoop_Foot(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	adds r7, r0, #0\n\
	ldr r1, _080F527C @ =0x000064AC\n\
	adds r0, r7, r1\n\
	ldr r0, [r0]\n\
	mov sb, r0\n\
	ldr r0, _080F5280 @ =0x00000DCC\n\
	adds r4, r7, r0\n\
	ldr r1, [r4, #0x20]\n\
	mov r8, r1\n\
	adds r0, #0x4b\n\
	adds r6, r7, r0\n\
	ldrb r5, [r6]\n\
	cmp r5, #1\n\
	beq _080F5328\n\
	cmp r5, #1\n\
	bgt _080F5284\n\
	cmp r5, #0\n\
	beq _080F5298\n\
	b _080F542A\n\
	.align 2, 0\n\
_080F527C: .4byte 0x000064AC\n\
_080F5280: .4byte 0x00000DCC\n\
_080F5284:\n\
	cmp r5, #2\n\
	bne _080F528A\n\
	b _080F541A\n\
_080F528A:\n\
	b _080F542A\n\
_080F528C:\n\
	ldr r1, _080F5294 @ =0x00000DCC\n\
	adds r0, r7, r1\n\
	strb r4, [r0, #1]\n\
	b _080F52F2\n\
	.align 2, 0\n\
_080F5294: .4byte 0x00000DCC\n\
_080F5298:\n\
	ldr r1, _080F5320 @ =0x00000E1D\n\
	adds r0, r7, r1\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	ldr r0, [r4, #0x20]\n\
	cmp r0, #0\n\
	bne _080F52A8\n\
	b _080F542A\n\
_080F52A8:\n\
	mov r1, r8\n\
	ldrb r0, [r1, #0xd]\n\
	cmp r0, #1\n\
	bhi _080F52B2\n\
	b _080F542A\n\
_080F52B2:\n\
	adds r0, r7, #0\n\
	movs r1, #0\n\
	movs r2, #0\n\
	bl CreateMenuComp2\n\
	str r0, [r4, #0x1c]\n\
	strb r5, [r4, #1]\n\
	movs r4, #0\n\
	mov r0, r8\n\
	adds r0, #0x79\n\
	mov r8, r6\n\
	adds r6, r0, #0\n\
	ldrb r0, [r6]\n\
	cmp r5, r0\n\
	bhs _080F52F2\n\
_080F52D0:\n\
	adds r0, r7, #0\n\
	adds r1, r4, #0\n\
	bl CheckUnlockedFoot\n\
	mov r1, sb\n\
	adds r1, #0xb4\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldrb r1, [r1, #0x11]\n\
	cmp r0, r1\n\
	beq _080F528C\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	ldrb r1, [r6]\n\
	cmp r4, r1\n\
	blo _080F52D0\n\
_080F52F2:\n\
	ldr r0, _080F5324 @ =0x00000DCC\n\
	adds r3, r7, r0\n\
	ldr r2, [r3, #0x1c]\n\
	ldrb r1, [r3, #1]\n\
	movs r0, #3\n\
	ands r1, r0\n\
	lsls r1, r1, #4\n\
	movs r0, #0x9c\n\
	subs r0, r0, r1\n\
	adds r2, #0x74\n\
	strh r0, [r2]\n\
	ldr r1, [r3, #0x1c]\n\
	ldrb r0, [r3, #1]\n\
	lsrs r0, r0, #2\n\
	lsls r0, r0, #4\n\
	adds r0, #0x68\n\
	adds r1, #0x76\n\
	strh r0, [r1]\n\
	mov r1, r8\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	b _080F542A\n\
	.align 2, 0\n\
_080F5320: .4byte 0x00000E1D\n\
_080F5324: .4byte 0x00000DCC\n\
_080F5328:\n\
	ldr r2, _080F5354 @ =gJoypad\n\
	ldrh r1, [r2, #4]\n\
	movs r0, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F536E\n\
	ldr r0, [r4, #0x1c]\n\
	adds r0, #0x78\n\
	strb r5, [r0]\n\
	strb r5, [r4, #5]\n\
	ldrb r0, [r6]\n\
	adds r0, #1\n\
	strb r0, [r6]\n\
	ldrh r1, [r2, #4]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5358\n\
	movs r0, #3\n\
	bl PlaySound\n\
	b _080F542A\n\
	.align 2, 0\n\
_080F5354: .4byte gJoypad\n\
_080F5358:\n\
	ldrb r1, [r4, #1]\n\
	adds r0, r7, #0\n\
	bl CheckUnlockedFoot\n\
	mov r1, sb\n\
	adds r1, #0xb4\n\
	strb r0, [r1, #0x11]\n\
	movs r0, #2\n\
	bl PlaySound\n\
	b _080F542A\n\
_080F536E:\n\
	ldrb r0, [r4, #1]\n\
	mov sb, r0\n\
	ldrh r5, [r2, #6]\n\
	movs r0, #0x20\n\
	ands r0, r5\n\
	adds r6, r5, #0\n\
	cmp r0, #0\n\
	beq _080F538E\n\
	mov r0, sb\n\
	adds r0, #1\n\
	mov r1, r8\n\
	adds r1, #0x79\n\
	ldrb r1, [r1]\n\
	bl __modsi3\n\
	strb r0, [r4, #1]\n\
_080F538E:\n\
	movs r0, #0x10\n\
	ands r0, r6\n\
	cmp r0, #0\n\
	beq _080F53A8\n\
	ldrb r0, [r4, #1]\n\
	subs r0, #1\n\
	mov r1, r8\n\
	adds r1, #0x79\n\
	ldrb r1, [r1]\n\
	adds r0, r0, r1\n\
	bl __modsi3\n\
	strb r0, [r4, #1]\n\
_080F53A8:\n\
	movs r0, #0xc0\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	beq _080F53D8\n\
	mov r2, r8\n\
	adds r2, #0x79\n\
	ldrb r0, [r2]\n\
	cmp r0, #4\n\
	bls _080F53D8\n\
	ldrb r0, [r4, #1]\n\
	cmp r0, #3\n\
	bls _080F53C6\n\
	subs r0, #4\n\
	strb r0, [r4, #1]\n\
	b _080F53D8\n\
_080F53C6:\n\
	ldrb r0, [r4, #1]\n\
	adds r1, r0, #4\n\
	ldrb r0, [r2]\n\
	cmp r1, r0\n\
	blt _080F53D6\n\
	subs r0, #1\n\
	strb r0, [r4, #1]\n\
	b _080F53D8\n\
_080F53D6:\n\
	strb r1, [r4, #1]\n\
_080F53D8:\n\
	ldr r1, _080F540C @ =0x00000DCC\n\
	adds r4, r7, r1\n\
	ldrb r0, [r4, #1]\n\
	cmp sb, r0\n\
	beq _080F53E8\n\
	movs r0, #1\n\
	bl PlaySound\n\
_080F53E8:\n\
	ldr r2, [r4, #0x1c]\n\
	ldrb r1, [r4, #1]\n\
	movs r0, #3\n\
	ands r1, r0\n\
	lsls r1, r1, #4\n\
	movs r0, #0x9c\n\
	subs r0, r0, r1\n\
	adds r2, #0x74\n\
	strh r0, [r2]\n\
	ldrb r0, [r4, #1]\n\
	cmp r0, #3\n\
	bls _080F5410\n\
	ldr r0, [r4, #0x1c]\n\
	adds r0, #0x76\n\
	movs r1, #0x78\n\
	strh r1, [r0]\n\
	b _080F542A\n\
	.align 2, 0\n\
_080F540C: .4byte 0x00000DCC\n\
_080F5410:\n\
	ldr r0, [r4, #0x1c]\n\
	adds r0, #0x76\n\
	movs r1, #0x68\n\
	strh r1, [r0]\n\
	b _080F542A\n\
_080F541A:\n\
	ldr r0, _080F5438 @ =0x00000E1D\n\
	adds r1, r7, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldrb r0, [r4, #5]\n\
	cmp r0, #0\n\
	bne _080F542A\n\
	strb r0, [r7, #3]\n\
_080F542A:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F5438: .4byte 0x00000E1D\n\
 .syntax divided\n");
}

NAKED static void MainMenuFocusLoop_Escape(struct GameState* g) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r3, r0, #0\n\
	ldr r0, _080F5450 @ =0x00000E17\n\
	adds r2, r3, r0\n\
	ldrb r1, [r2]\n\
	cmp r1, #0\n\
	beq _080F5454\n\
	cmp r1, #1\n\
	beq _080F545A\n\
	b _080F549C\n\
	.align 2, 0\n\
_080F5450: .4byte 0x00000E17\n\
_080F5454:\n\
	movs r0, #1\n\
	strb r0, [r2]\n\
	b _080F549C\n\
_080F545A:\n\
	ldr r0, _080F5480 @ =gJoypad\n\
	ldrh r2, [r0, #4]\n\
	ands r1, r2\n\
	cmp r1, #0\n\
	beq _080F548C\n\
	ldr r2, _080F5484 @ =gStageRun\n\
	ldrh r1, [r2, #8]\n\
	ldr r0, _080F5488 @ =0x0000FFFE\n\
	ands r0, r1\n\
	movs r1, #0x20\n\
	orrs r0, r1\n\
	strh r0, [r2, #8]\n\
	movs r0, #3\n\
	strb r0, [r3, #1]\n\
	strb r0, [r3, #2]\n\
	movs r0, #2\n\
	bl PlaySound\n\
	b _080F549C\n\
	.align 2, 0\n\
_080F5480: .4byte gJoypad\n\
_080F5484: .4byte gStageRun\n\
_080F5488: .4byte 0x0000FFFE\n\
_080F548C:\n\
	movs r0, #2\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080F549C\n\
	strb r1, [r3, #3]\n\
	movs r0, #3\n\
	bl PlaySound\n\
_080F549C:\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// --------------------------------------------

NAKED void menu_080f54a0(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r6, r0, #0\n\
	ldr r0, _080F54C8 @ =0x00000DCC\n\
	adds r4, r6, r0\n\
	ldrb r1, [r4, #2]\n\
	lsrs r7, r1, #3\n\
	ldrb r0, [r4]\n\
	subs r2, r0, #3\n\
	lsls r0, r2, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bhi _080F5520\n\
	cmp r7, #0\n\
	beq _080F54CC\n\
	adds r0, r1, #0\n\
	adds r0, #8\n\
	strb r0, [r4, #2]\n\
	b _080F5546\n\
	.align 2, 0\n\
_080F54C8: .4byte 0x00000DCC\n\
_080F54CC:\n\
	ldrb r0, [r4, #3]\n\
	cmp r0, #0xff\n\
	bne _080F54DE\n\
	strb r2, [r4, #3]\n\
	ldrb r0, [r4, #3]\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	b _080F5510\n\
_080F54DE:\n\
	ldrb r1, [r4, #3]\n\
	ldrb r0, [r4]\n\
	subs r0, #3\n\
	cmp r1, r0\n\
	beq _080F5510\n\
	adds r0, r1, #0\n\
	bl ClearBlink\n\
	movs r0, #3\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #3\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #3\n\
	bl ClearBlink\n\
	ldrb r0, [r4]\n\
	subs r0, #3\n\
	strb r0, [r4, #3]\n\
	ldrb r0, [r4, #3]\n\
	movs r1, #0\n\
	bl LoadBlink\n\
_080F5510:\n\
	ldr r1, _080F551C @ =0x00000DCC\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0, #3]\n\
	bl UpdateBlinkMotionState\n\
	b _080F5546\n\
	.align 2, 0\n\
_080F551C: .4byte 0x00000DCC\n\
_080F5520:\n\
	adds r0, r1, #1\n\
	strb r0, [r4, #2]\n\
	ldrb r0, [r4, #3]\n\
	cmp r0, #0xff\n\
	beq _080F5546\n\
	bl ClearBlink\n\
	movs r0, #3\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #3\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #3\n\
	bl ClearBlink\n\
	movs r0, #0xff\n\
	strb r0, [r4, #3]\n\
_080F5546:\n\
	ldr r0, _080F55D8 @ =0x00000DCC\n\
	adds r1, r6, r0\n\
	movs r0, #2\n\
	ldrsb r0, [r1, r0]\n\
	cmp r0, #0\n\
	bge _080F5556\n\
	movs r0, #0\n\
	strb r0, [r1, #2]\n\
_080F5556:\n\
	ldrb r0, [r1, #2]\n\
	lsrs r5, r0, #3\n\
	cmp r7, r5\n\
	beq _080F55CE\n\
	ldr r4, _080F55DC @ =u8_ARRAY_08386378\n\
	adds r4, r5, r4\n\
	ldrb r1, [r4]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r1, _080F55E0 @ =gGraphic_Capcom\n\
	adds r0, r0, r1\n\
	ldr r1, _080F55E4 @ =gVideoRegBuffer+6\n\
	mov r8, r1\n\
	ldrh r2, [r1]\n\
	movs r1, #0xc\n\
	ands r1, r2\n\
	lsls r1, r1, #0xc\n\
	bl LoadGraphic\n\
	ldrb r1, [r4]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r1, _080F55E8 @ =gPalette_Capcom\n\
	adds r0, r0, r1\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r0, _080F55EC @ =u8_ARRAY_08386388\n\
	adds r2, r5, r0\n\
	adds r0, r7, r0\n\
	ldrb r1, [r2]\n\
	ldrb r0, [r0]\n\
	cmp r1, r0\n\
	beq _080F55CE\n\
	ldr r0, _080F55F0 @ =0x00000ED8\n\
	adds r4, r6, r0\n\
	adds r0, r1, #0\n\
	lsls r0, r0, #2\n\
	ldr r1, _080F55F4 @ =gBgMapOffsets\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	adds r1, r1, r0\n\
	adds r0, r4, #0\n\
	movs r2, #0xc\n\
	movs r3, #7\n\
	bl CopyBgMap\n\
	mov r1, r8\n\
	ldrh r0, [r1]\n\
	movs r1, #0xf8\n\
	lsls r1, r1, #5\n\
	ands r1, r0\n\
	lsls r1, r1, #3\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
	adds r0, r4, #0\n\
	bl RequestBgMapTransfer\n\
_080F55CE:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F55D8: .4byte 0x00000DCC\n\
_080F55DC: .4byte u8_ARRAY_08386378\n\
_080F55E0: .4byte gGraphic_Capcom\n\
_080F55E4: .4byte gVideoRegBuffer+6\n\
_080F55E8: .4byte gPalette_Capcom\n\
_080F55EC: .4byte u8_ARRAY_08386388\n\
_080F55F0: .4byte 0x00000ED8\n\
_080F55F4: .4byte gBgMapOffsets\n\
 .syntax divided\n");
}

// メインメニューで一番下に、 "メインでそうびしているブキ" のような文字列を表示
NAKED void printMainMenuString(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldr r1, _080F5614 @ =0x000064AC\n\
	adds r0, r4, r1\n\
	ldr r5, [r0]\n\
	ldrb r0, [r4, #3]\n\
	cmp r0, #7\n\
	bls _080F560A\n\
	b _080F5812\n\
_080F560A:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080F5618 @ =_080F561C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080F5614: .4byte 0x000064AC\n\
_080F5618: .4byte _080F561C\n\
_080F561C: @ jump table\n\
	.4byte _080F563C @ case 0\n\
	.4byte _080F568C @ case 1\n\
	.4byte _080F56B8 @ case 2\n\
	.4byte _080F56E4 @ case 3\n\
	.4byte _080F573A @ case 4\n\
	.4byte _080F5768 @ case 5\n\
	.4byte _080F5798 @ case 6\n\
	.4byte _080F57C8 @ case 7\n\
_080F563C:\n\
	ldr r0, _080F565C @ =0x00000DCC\n\
	adds r2, r4, r0\n\
	ldrb r0, [r2]\n\
	cmp r0, #6\n\
	bne _080F5678\n\
	ldr r0, _080F5660 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5668\n\
	ldr r0, _080F5664 @ =StringOfsTable\n\
	movs r1, #0x99\n\
	lsls r1, r1, #2\n\
	b _080F57D8\n\
	.align 2, 0\n\
_080F565C: .4byte 0x00000DCC\n\
_080F5660: .4byte gCurStory\n\
_080F5664: .4byte StringOfsTable\n\
_080F5668:\n\
	ldr r0, _080F5674 @ =StringOfsTable\n\
	movs r2, #0x9a\n\
	lsls r2, r2, #2\n\
	adds r0, r0, r2\n\
	b _080F57DA\n\
	.align 2, 0\n\
_080F5674: .4byte StringOfsTable\n\
_080F5678:\n\
	ldr r1, _080F5688 @ =StringOfsTable\n\
	ldrb r0, [r2]\n\
	movs r2, #0x96\n\
	lsls r2, r2, #1\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #1\n\
	b _080F57D8\n\
	.align 2, 0\n\
_080F5688: .4byte StringOfsTable\n\
_080F568C:\n\
	ldr r0, _080F56A8 @ =0x00000DCC\n\
	adds r2, r4, r0\n\
	ldr r1, _080F56AC @ =0x00000E17\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080F569C\n\
	b _080F5812\n\
_080F569C:\n\
	ldr r1, _080F56B0 @ =StringOfsTable\n\
	ldrb r0, [r2, #1]\n\
	ldr r2, _080F56B4 @ =0x00000135\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #1\n\
	b _080F57D8\n\
	.align 2, 0\n\
_080F56A8: .4byte 0x00000DCC\n\
_080F56AC: .4byte 0x00000E17\n\
_080F56B0: .4byte StringOfsTable\n\
_080F56B4: .4byte 0x00000135\n\
_080F56B8:\n\
	ldr r0, _080F56D4 @ =0x00000DCC\n\
	adds r2, r4, r0\n\
	ldr r1, _080F56D8 @ =0x00000E17\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080F56C8\n\
	b _080F5812\n\
_080F56C8:\n\
	ldr r1, _080F56DC @ =StringOfsTable\n\
	ldrb r0, [r2, #1]\n\
	ldr r2, _080F56E0 @ =0x00000135\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #1\n\
	b _080F57D8\n\
	.align 2, 0\n\
_080F56D4: .4byte 0x00000DCC\n\
_080F56D8: .4byte 0x00000E17\n\
_080F56DC: .4byte StringOfsTable\n\
_080F56E0: .4byte 0x00000135\n\
_080F56E4:\n\
	ldr r1, _080F571C @ =0x00000E17\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080F56F0\n\
	b _080F5812\n\
_080F56F0:\n\
	ldr r0, _080F5720 @ =StringOfsTable\n\
	ldr r2, _080F5724 @ =0x00000272\n\
	adds r0, r0, r2\n\
	ldrh r0, [r0]\n\
	ldr r1, _080F5728 @ =gStringData\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	movs r2, #0x12\n\
	bl PrintString\n\
	ldr r0, _080F572C @ =0x00000E1B\n\
	adds r1, r4, r0\n\
	adds r0, r5, #0\n\
	adds r0, #0xbc\n\
	ldrb r1, [r1]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #9\n\
	bhi _080F5730\n\
	movs r1, #0xc\n\
	b _080F5732\n\
	.align 2, 0\n\
_080F571C: .4byte 0x00000E17\n\
_080F5720: .4byte StringOfsTable\n\
_080F5724: .4byte 0x00000272\n\
_080F5728: .4byte gStringData\n\
_080F572C: .4byte 0x00000E1B\n\
_080F5730:\n\
	movs r1, #0xd\n\
_080F5732:\n\
	movs r2, #0x12\n\
	bl PrintNumber\n\
	b _080F5812\n\
_080F573A:\n\
	ldr r2, _080F5760 @ =0x00000DCC\n\
	adds r1, r4, r2\n\
	adds r2, #0x4b\n\
	adds r0, r4, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080F5812\n\
	ldrb r1, [r1, #1]\n\
	adds r0, r4, #0\n\
	bl CheckUnlockedFoot\n\
	ldr r1, _080F5764 @ =StringOfsTable\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	movs r2, #0x9d\n\
	lsls r2, r2, #2\n\
	adds r0, r0, r2\n\
	b _080F57D8\n\
	.align 2, 0\n\
_080F5760: .4byte 0x00000DCC\n\
_080F5764: .4byte StringOfsTable\n\
_080F5768:\n\
	ldr r0, _080F578C @ =0x00000DCC\n\
	adds r1, r4, r0\n\
	ldr r2, _080F5790 @ =0x00000E17\n\
	adds r0, r4, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080F5812\n\
	ldrb r1, [r1, #1]\n\
	adds r0, r4, #0\n\
	bl CheckUnlockedFoot\n\
	ldr r1, _080F5794 @ =StringOfsTable\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	movs r2, #0x9f\n\
	lsls r2, r2, #2\n\
	adds r0, r0, r2\n\
	b _080F57D8\n\
	.align 2, 0\n\
_080F578C: .4byte 0x00000DCC\n\
_080F5790: .4byte 0x00000E17\n\
_080F5794: .4byte StringOfsTable\n\
_080F5798:\n\
	ldr r0, _080F57BC @ =0x00000DCC\n\
	adds r1, r4, r0\n\
	ldr r2, _080F57C0 @ =0x00000E17\n\
	adds r0, r4, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080F5812\n\
	ldrb r1, [r1, #1]\n\
	adds r0, r4, #0\n\
	bl CheckUnlockedFoot\n\
	ldr r1, _080F57C4 @ =StringOfsTable\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	movs r2, #0xa2\n\
	lsls r2, r2, #2\n\
	adds r0, r0, r2\n\
	b _080F57D8\n\
	.align 2, 0\n\
_080F57BC: .4byte 0x00000DCC\n\
_080F57C0: .4byte 0x00000E17\n\
_080F57C4: .4byte StringOfsTable\n\
_080F57C8:\n\
	ldr r0, _080F57EC @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F57FC\n\
	ldr r0, _080F57F0 @ =StringOfsTable\n\
	ldr r1, _080F57F4 @ =0x00000266\n\
_080F57D8:\n\
	adds r0, r0, r1\n\
_080F57DA:\n\
	ldrh r0, [r0]\n\
	ldr r1, _080F57F8 @ =gStringData\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	movs r2, #0x12\n\
	bl PrintString\n\
	b _080F5812\n\
	.align 2, 0\n\
_080F57EC: .4byte gCurStory\n\
_080F57F0: .4byte StringOfsTable\n\
_080F57F4: .4byte 0x00000266\n\
_080F57F8: .4byte gStringData\n\
_080F57FC:\n\
	ldr r0, _080F5818 @ =StringOfsTable\n\
	movs r2, #0x9a\n\
	lsls r2, r2, #2\n\
	adds r0, r0, r2\n\
	ldrh r0, [r0]\n\
	ldr r1, _080F581C @ =gStringData\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	movs r2, #0x12\n\
	bl PrintString\n\
_080F5812:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F5818: .4byte StringOfsTable\n\
_080F581C: .4byte gStringData\n\
 .syntax divided\n");
}

NAKED u8 CheckUnlockedHead(struct GameState* g, u8 r1) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	ldr r2, _080F5894 @ =0x000064AC\n\
	adds r0, r4, r2\n\
	ldr r0, [r0]\n\
	cmp r1, #0xff\n\
	bne _080F589C\n\
	movs r2, #0\n\
	adds r3, r0, #0\n\
	adds r3, #0xb4\n\
	ldrb r1, [r3, #0x17]\n\
	movs r5, #1\n\
	adds r0, r5, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F584C\n\
	ldr r1, _080F5898 @ =0x00000DD2\n\
	adds r0, r4, r1\n\
	strb r2, [r0]\n\
	movs r2, #1\n\
_080F584C:\n\
	ldrb r1, [r3, #0x17]\n\
	movs r6, #2\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5866\n\
	ldr r1, _080F5898 @ =0x00000DD2\n\
	adds r0, r4, r1\n\
	adds r0, r0, r2\n\
	strb r5, [r0]\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
_080F5866:\n\
	ldrb r1, [r3, #0x17]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F587E\n\
	ldr r1, _080F5898 @ =0x00000DD2\n\
	adds r0, r4, r1\n\
	adds r0, r0, r2\n\
	strb r6, [r0]\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
_080F587E:\n\
	ldrb r1, [r3, #0x17]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F58AC\n\
	ldr r1, _080F5898 @ =0x00000DD2\n\
	adds r0, r4, r1\n\
	adds r0, r0, r2\n\
	movs r1, #3\n\
	strb r1, [r0]\n\
	b _080F58AC\n\
	.align 2, 0\n\
_080F5894: .4byte 0x000064AC\n\
_080F5898: .4byte 0x00000DD2\n\
_080F589C:\n\
	ldr r2, _080F58A8 @ =0x00000DD2\n\
	adds r0, r4, r2\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	b _080F58AE\n\
	.align 2, 0\n\
_080F58A8: .4byte 0x00000DD2\n\
_080F58AC:\n\
	movs r0, #0xff\n\
_080F58AE:\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED u8 CheckUnlockedBody(struct GameState* g, u8 r1) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r3, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	ldr r2, _080F595C @ =0x000064AC\n\
	adds r0, r3, r2\n\
	ldr r0, [r0]\n\
	cmp r1, #0xff\n\
	bne _080F5964\n\
	movs r2, #0\n\
	adds r4, r0, #0\n\
	adds r4, #0xb4\n\
	ldrb r1, [r4, #0x18]\n\
	movs r5, #1\n\
	adds r0, r5, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F58E0\n\
	ldr r1, _080F5960 @ =0x00000DD2\n\
	adds r0, r3, r1\n\
	strb r2, [r0]\n\
	movs r2, #1\n\
_080F58E0:\n\
	ldrb r1, [r4, #0x18]\n\
	movs r6, #2\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F58FA\n\
	ldr r1, _080F5960 @ =0x00000DD2\n\
	adds r0, r3, r1\n\
	adds r0, r0, r2\n\
	strb r5, [r0]\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
_080F58FA:\n\
	ldrb r1, [r4, #0x18]\n\
	movs r5, #4\n\
	adds r0, r5, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5914\n\
	ldr r1, _080F5960 @ =0x00000DD2\n\
	adds r0, r3, r1\n\
	adds r0, r0, r2\n\
	strb r6, [r0]\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
_080F5914:\n\
	ldrb r1, [r4, #0x18]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F592C\n\
	ldr r1, _080F5960 @ =0x00000DD2\n\
	adds r0, r3, r1\n\
	adds r0, r0, r2\n\
	strb r5, [r0]\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
_080F592C:\n\
	ldrb r1, [r4, #0x18]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5946\n\
	ldr r1, _080F5960 @ =0x00000DD2\n\
	adds r0, r3, r1\n\
	adds r0, r0, r2\n\
	movs r1, #5\n\
	strb r1, [r0]\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
_080F5946:\n\
	ldrb r1, [r4, #0x18]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5974\n\
	ldr r1, _080F5960 @ =0x00000DD2\n\
	adds r0, r3, r1\n\
	adds r0, r0, r2\n\
	movs r1, #3\n\
	strb r1, [r0]\n\
	b _080F5974\n\
	.align 2, 0\n\
_080F595C: .4byte 0x000064AC\n\
_080F5960: .4byte 0x00000DD2\n\
_080F5964:\n\
	ldr r2, _080F5970 @ =0x00000DD2\n\
	adds r0, r3, r2\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	b _080F5976\n\
	.align 2, 0\n\
_080F5970: .4byte 0x00000DD2\n\
_080F5974:\n\
	movs r0, #0\n\
_080F5976:\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED u8 CheckUnlockedFoot(struct GameState* g, u8 r1) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r3, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	ldr r2, _080F5A58 @ =0x000064AC\n\
	adds r0, r3, r2\n\
	ldr r0, [r0]\n\
	cmp r1, #0xff\n\
	bne _080F5A60\n\
	movs r2, #0\n\
	adds r4, r0, #0\n\
	adds r4, #0xb4\n\
	ldrb r1, [r4, #0x19]\n\
	movs r5, #1\n\
	adds r0, r5, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F59A8\n\
	ldr r1, _080F5A5C @ =0x00000DD2\n\
	adds r0, r3, r1\n\
	strb r2, [r0]\n\
	movs r2, #1\n\
_080F59A8:\n\
	ldrb r1, [r4, #0x19]\n\
	movs r6, #2\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F59C2\n\
	ldr r1, _080F5A5C @ =0x00000DD2\n\
	adds r0, r3, r1\n\
	adds r0, r0, r2\n\
	strb r5, [r0]\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
_080F59C2:\n\
	ldrb r1, [r4, #0x19]\n\
	movs r5, #4\n\
	adds r0, r5, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F59DC\n\
	ldr r1, _080F5A5C @ =0x00000DD2\n\
	adds r0, r3, r1\n\
	adds r0, r0, r2\n\
	strb r6, [r0]\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
_080F59DC:\n\
	ldrb r1, [r4, #0x19]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F59F6\n\
	ldr r1, _080F5A5C @ =0x00000DD2\n\
	adds r0, r3, r1\n\
	adds r0, r0, r2\n\
	movs r1, #3\n\
	strb r1, [r0]\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
_080F59F6:\n\
	ldrb r1, [r4, #0x19]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5A0E\n\
	ldr r1, _080F5A5C @ =0x00000DD2\n\
	adds r0, r3, r1\n\
	adds r0, r0, r2\n\
	strb r5, [r0]\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
_080F5A0E:\n\
	ldrb r1, [r4, #0x19]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5A28\n\
	ldr r1, _080F5A5C @ =0x00000DD2\n\
	adds r0, r3, r1\n\
	adds r0, r0, r2\n\
	movs r1, #5\n\
	strb r1, [r0]\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
_080F5A28:\n\
	ldrb r1, [r4, #0x19]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5A42\n\
	ldr r1, _080F5A5C @ =0x00000DD2\n\
	adds r0, r3, r1\n\
	adds r0, r0, r2\n\
	movs r1, #6\n\
	strb r1, [r0]\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
_080F5A42:\n\
	ldrb r1, [r4, #0x19]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F5A70\n\
	ldr r1, _080F5A5C @ =0x00000DD2\n\
	adds r0, r3, r1\n\
	adds r0, r0, r2\n\
	movs r1, #7\n\
	strb r1, [r0]\n\
	b _080F5A70\n\
	.align 2, 0\n\
_080F5A58: .4byte 0x000064AC\n\
_080F5A5C: .4byte 0x00000DD2\n\
_080F5A60:\n\
	ldr r2, _080F5A6C @ =0x00000DD2\n\
	adds r0, r3, r2\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	b _080F5A72\n\
	.align 2, 0\n\
_080F5A6C: .4byte 0x00000DD2\n\
_080F5A70:\n\
	movs r0, #0\n\
_080F5A72:\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED void SortSubtank(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	adds r2, r4, #0\n\
	adds r2, #0xb4\n\
	ldrb r3, [r2, #8]\n\
	cmp r3, #0xff\n\
	beq _080F5A98\n\
	ldrb r0, [r2, #9]\n\
	adds r1, r0, #0\n\
	cmp r1, #0xff\n\
	beq _080F5A98\n\
	cmp r3, r1\n\
	bhs _080F5A98\n\
	adds r1, r3, #0\n\
	strb r0, [r2, #8]\n\
	strb r1, [r2, #9]\n\
_080F5A98:\n\
	adds r0, r4, #0\n\
	adds r0, #0xb4\n\
	ldrb r2, [r0, #0xa]\n\
	cmp r2, #0xff\n\
	beq _080F5AB4\n\
	ldrb r3, [r0, #0xb]\n\
	adds r1, r3, #0\n\
	cmp r1, #0xff\n\
	beq _080F5AB4\n\
	cmp r2, r1\n\
	bhs _080F5AB4\n\
	adds r1, r2, #0\n\
	strb r3, [r0, #0xa]\n\
	strb r1, [r0, #0xb]\n\
_080F5AB4:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}
