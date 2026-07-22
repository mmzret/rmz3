#include "menu.h"
#include "string_ids.h"

#include "cyberelf.h"
#include "game.h"
#include "gfx.h"
#include "global.h"
#include "sprite.h"
#include "text.h"
#include "weapon.h"
#include "widget.h"
#include "zero.h"

void EachMenuLoop_MainMenu(struct GameState* p);
void EachMenuLoop_ExSkill(struct GameState* g);
void EachMenuLoop_KeyConfig(struct GameState* p);
void EachMenuLoop_Elf(struct GameState* p);

// idx is BYTE[0x02031978]
// 0x083862A4
static const MenuLoopFunc sEachMenuLoops[4] = {
    EachMenuLoop_MainMenu,
    EachMenuLoop_ExSkill,
    EachMenuLoop_KeyConfig,
    EachMenuLoop_Elf,
};

// --------------------------------------------

static void MenuLoop_InitMenu(struct GameState* p);
static void MenuLoop_OpenMenu(struct GameState* p);
static void MenuLoop_Update(struct GameState* p);
static void MenuLoop_BlackOut(struct GameState* p);
static void MenuLoop_ExitMenu(struct GameState* m);

static void menu_080f39a8(struct GameState* m);

void MainLoop_Menu(struct GameState* m) {
  static const MenuLoopFunc sMenuLoops[5] = {
      MenuLoop_InitMenu, MenuLoop_OpenMenu, MenuLoop_Update, MenuLoop_BlackOut, MenuLoop_ExitMenu,
  };
  (sMenuLoops[m->mode[1]])(m);
  menu_080f39a8(m);
}

static void menu_080f394c(struct GameState* g);

// 01 00 xx xx
static void MenuLoop_InitMenu(struct GameState* g) {
  struct Zero* z;

  z = g->z2;
  g->frames = 0;
  MENU->unk_40[6] = ((&z->unk_b4)->status).weapons[0];
  MENU->unk_40[7] = ((&z->unk_b4)->status).weapons[1];
  MENU->unk_4a = ((&z->unk_b4)->status).element;
  MENU->attackMode = ((&z->unk_b4)->status).keyMap.attackMode;
  MENU->satelites[0] = ((&z->unk_b4)->status).satelites[0];
  MENU->satelites[1] = ((&z->unk_b4)->status).satelites[1];
  MENU->unk_50 = 0xFF;
  MENU->unk_4c = 0;
  menu_080f394c(g);
  gVideoRegBuffer.dispcnt &= ~DISPCNT_BGMODE_MASK;
  gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
  gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON | DISPCNT_BG1_ON | DISPCNT_OBJ_ON;
  BGCNT16(1) = BGCNT_PRIORITY(2) | BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(2) | BGCNT_TXT512x256;
  RESET_BGOFS(1);
  (sEachMenuLoops[MENU->unk_4c])(g);
  g->mode[1] = g->mode[2] = 1;
  MenuLoop_OpenMenu(g);
}

// 01 01 xx xx
static void MenuLoop_OpenMenu(struct GameState* g) {
  g->frames++;
  if (g->frames >= 16) {
    gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = FILTER_NONE;
    g->mode[1] = 2;
    MenuLoop_Update(g);
  } else {
    gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = g->frames;
  }
  menu_080f39a8(g);
}

// 01 02 xx xx
static void MenuLoop_Update(struct GameState* g) {
  MENU->unk_51 = 0;
  (sEachMenuLoops[MENU->unk_4c])(g);
  if ((MENU->unk_51 == 0) && (gJoypad[0].pressed & START_BUTTON)) {
    g->mode[1] = 3, g->mode[2] = 3;
  }
}

// 01 03 xx xx
static void MenuLoop_BlackOut(struct GameState* g) {
  g->frames--;
  if (g->frames == 0) {
    gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = FILTER_BLACK;
    g->mode[1] = 4;
    MenuLoop_ExitMenu(g);
  } else {
    gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = g->frames;
  }
}

// --------------------------------------------

struct Entity* CreateElf1(struct Zero* z, u8 breed, u8 availability, u8 _);
struct Entity* CreateElf5(struct Zero* z, u8 breed, u8 availability, u8 _);
struct Entity* CreateElf6(struct Zero* z, u8 breed, u8 availability, u8 _);
struct Entity* CreateElf7(struct Zero* z, u8 breed, u8 availability, u8 _);
struct Entity* elf_080e4bf4(struct Zero* z, u8 breed, u8 availability, u8 _);

// clang-format off
const MenuElfFunc gExitMenuScripts[13] = {
    (MenuElfFunc)CreateElf0,
    (MenuElfFunc)CreateElf1,
    (MenuElfFunc)CreateNurseBElf, 
    (MenuElfFunc)CreateNurseBElf, 
    (MenuElfFunc)CreateNurseEElf, 
    (MenuElfFunc)CreateElf5, 
    (MenuElfFunc)CreateElf6, 
    (MenuElfFunc)CreateElf7, 
    (MenuElfFunc)CreateFollowerElf, 
    (MenuElfFunc)CreateSeaotterElf, 
    (MenuElfFunc)elf_080e4bf4, 
    (MenuElfFunc)elf_080e4bf4, 
    (MenuElfFunc)CreateBirdElf,
};
// clang-format on

// 01 04 xx xx
// 0x080f37e8
NAKED static void MenuLoop_ExitMenu(struct GameState* g) {
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
	bl RequestElementEffectGraphic\n\
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
	ldr r0, _080F3938 @ =gElfAvailability\n\
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
	ldr r1, _080F3940 @ =sEachMenuLoops\n\
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
_080F3938: .4byte gElfAvailability\n\
_080F393C: .4byte gPause\n\
_080F3940: .4byte sEachMenuLoops\n\
_080F3944: .4byte FUN_080f3d44\n\
_080F3948: .4byte close_menu_080f3d64\n\
 .syntax divided\n");
}

// --------------------------------------------

static void menu_080f394c(struct GameState* g) {
  Coords32* c = &g->unk_0dc4;
  c->x = PIXEL(120);
  c->y = PIXEL(80);
  ResetPivot(&g->unk_0db8, c, 0, 0);
  Renderer_Init(&g->rendererUI);
  Renderer_SetPivot(&g->rendererUI, &g->unk_0db8);
  InitWidgetHeader(&g->entityHeaders[ENTITY_WIDGET], gWidgets, 64);
}

static void menu_080f39a8(struct GameState* g) {
  g->unk_0dc4.x = PIXEL(BGOFS(1)->x & 0x1FF) + PIXEL(120);
  Renderer_Clear(&g->rendererUI);
  UpdateEntities(gWidgetHeaderPtr);
  DrawEntity(gWidgetHeaderPtr, &g->rendererUI);
  Renderer_Flush(&g->rendererUI);
}

NAKED void menu_080f39fc(struct GameState* m) {
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

static const u8 u8_ARRAY_083862fc[4] = {1, 2, 4, 8};

NAKED void menu_080f3ab0(struct GameState* m) {
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
bool8 TrySlideMenu(struct GameState* g) {
  if (gJoypad[0].pressed & B_BUTTON) {
    g->mode[1] = 3, g->mode[2] = 3;
    return TRUE;
  }
  if (gJoypad[0].pressed & L_BUTTON) {
    MENU->unk_4d = (MENU->unk_4c + 3) & 3;
    g->mode[2] = 0;
    (sEachMenuLoops[MENU->unk_4d])(g);
    PlaySound(SE_MENU_SLIDE);
    return TRUE;
  }
  if (gJoypad[0].pressed & R_BUTTON) {
    MENU->unk_4d = (MENU->unk_4c + 1) & 3;
    g->mode[2] = 0;
    (sEachMenuLoops[MENU->unk_4d])(g);
    PlaySound(SE_MENU_SLIDE);
    return TRUE;
  }
  return FALSE;
}

/**
 * @brief dstが BGMap の (0, 0) としたときに (xタイル ,yタイル) を左上として転送する
 * @param dst BGMap (0, 0) point
 * @param x Start X Tile
 * @param y Start Y Tile
 */
NAKED void CopyBgMap(u16* dst, struct BgMapHeader* src, u8 x, u8 y) {
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

void PrintNumber(u16 n, u8 x, u8 y) {
  u8 i = 0;
  while (TRUE) {
    u16 digit = n % 10;
    PrintString(STRING(digit + STR_DIGIT), x - i, y);
    n /= 10;
    if (n == 0) {
      break;
    }
    i++;
  }
}

// --------------------------------------------

struct SoulLauncher;

void MenuExit_Buster(struct Weapon* p);
void MenuExit_ShieldGuard(struct WeaponCommon* p);
void MenuExit_ShieldFly(struct Weapon* p);
void MenuExit_ReflectLaser(struct Weapon* p);
void MenuExit_SoulLauncher(struct SoulLauncher* p);
void MenuExit_BurstShot(struct Weapon* p);
void MenuExit_BlizzardArrow(struct Weapon* p);
void MenuExit_ThrowBlade(struct Weapon* p);
void MenuExit_ShieldSweep(struct WeaponCommon* p);
void MenuExit_Weapon13(struct WeaponCommon* p);
void MenuExit_SaberSmash(struct Weapon* p);
void MenuExit_ShieldSweepElec(struct Weapon* p);

void FUN_080f3d44(struct Weapon* w) {
  // clang-format off
  static const WeaponFunc PTR_ARRAY_08386300[WEAPON_MOVE_COUNT] = {
    [WEAPON_MOVE_Z_BUSTER]     =      (void*)MenuExit_Buster, 
    [WEAPON_MOVE_Z_SABER]      =      (void*)NULL, 
    [WEAPON_MOVE_SHIELD_GUARD] =      (void*)MenuExit_ShieldGuard, 
    [WEAPON_MOVE_RECOIL_ROD]   =      (void*)NULL, 
    [WEAPON_MOVE_SHIELD_FLY]   =      (void*)MenuExit_ShieldFly, 
    [WEAPON_MOVE_SABER_WAVE] =        (void*)NULL, 
    [WEAPON_MOVE_06] =                (void*)NULL, 
    [WEAPON_MOVE_REFLECT_LASER] =     (void*)MenuExit_ReflectLaser, 
    [WEAPON_MOVE_SOUL_LANCHER] =      (void*)MenuExit_SoulLauncher, 
    [WEAPON_MOVE_BURST_SHOT] =        (void*)MenuExit_BurstShot, 
    [WEAPON_MOVE_BLIZZARD_ARROW] =    (void*)MenuExit_BlizzardArrow, 
    [WEAPON_MOVE_ZANEIDAN] =          (void*)MenuExit_ThrowBlade, 
    [WEAPON_MOVE_SHIELD_SWEEP] =      (void*)MenuExit_ShieldSweep, 
    [WEAPON_MOVE_13] =                (void*)MenuExit_Weapon13, 
    [WEAPON_MOVE_RAKUSAIGA] =         (void*)MenuExit_SaberSmash, 
    [WEAPON_MOVE_SHIELD_SWEEP_ELEC] = (void*)MenuExit_ShieldSweepElec, 
    [WEAPON_MOVE_MINIGAME_ROD] =      (void*)NULL,
  };
  // clang-format on
  if (PTR_ARRAY_08386300[(w->s).id] != NULL) {
    (PTR_ARRAY_08386300[(w->s).id])(w);
  }
}

// --------------------------------------------

struct FollowerCyberElf;
struct CyberElf10;

void FUN_080e2510(struct Elf* e);
void FUN_080e2b78(struct Elf* e);
void MenuExit_FollowerElf(struct FollowerCyberElf* e);
void MenuExit_SeaOtterElf(struct Elf* e);
void MenuExit_CyberElf10(struct CyberElf10* p);
void FUN_080e58bc(struct Elf* e);

void close_menu_080f3d64(struct Elf* e) {
  // clang-format off
  static const ElfFunc PTR_ARRAY_08386344[13] = {
    [0]  = (void*)NULL, 
    [1]  = (void*)NULL, 
    [2]  = (void*)FUN_080e2510, 
    [3]  = (void*)NULL, 
    [4]  = (void*)FUN_080e2b78, 
    [5]  = (void*)NULL, 
    [6]  = (void*)NULL, 
    [7]  = (void*)NULL, 
    [8]  = (void*)MenuExit_FollowerElf, 
    [9]  = (void*)MenuExit_SeaOtterElf, 
    [10] = (void*)MenuExit_CyberElf10, 
    [11] = (void*)NULL, 
    [12] = (void*)FUN_080e58bc,
  }; // 0x08386344
  // clang-format on
  if (PTR_ARRAY_08386344[(e->s).id] != NULL) {
    (PTR_ARRAY_08386344[(e->s).id])((void*)e);
  }
}
