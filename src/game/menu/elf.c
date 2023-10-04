#include "blink.h"
#include "game.h"
#include "gfx.h"
#include "global.h"
#include "menu.h"
#include "story.h"
#include "text.h"
#include "widget.h"
#include "zero.h"

extern const struct Graphic gGraphic_NurseElfTab;
extern const struct Palette gPalette_NurseElfTab;
#define gGraphic_ElfTab(category) ((const struct Graphic*)((void*)&gGraphic_NurseElfTab + (category * 20)))
#define gPalette_ElfTab(category) ((const struct Palette*)((void*)&gPalette_NurseElfTab + (category * 20)))

extern const struct ColorGraphic gGraphics_ElfCategory[3];

extern const struct Graphic gGraphic_ElfMenu;
extern const struct Palette gPalette_ElfMenu;

extern const struct Graphic gGraphic_0854758C;
extern const struct Palette gPalette_0854758C;

static void printElfNames(struct GameState* g);
static void printElfMenuDescription(struct GameState* g);
static void printElfMenuBottomString(struct GameState* g);
static str_id_t getElfDescStrID(struct GameState* g, u8 r1);

static void ElfMenuLoop_Init(struct GameState* g);
static void ElfMenuLoop_Update(struct GameState* g);
static void ElfMenuLoop_SlideOut(struct GameState* g);
static void ElfMenuLoop_Exit(struct GameState* g);

// 01 02 xx xx (BYTE[0x02031978] = 3)
static const MenuLoopFunc ElfMenuLoops[4] = {
    ElfMenuLoop_Init,
    ElfMenuLoop_Update,
    ElfMenuLoop_SlideOut,
    ElfMenuLoop_Exit,
};

static void ElfMenuFocusLoop_NoFocus(struct GameState* g);
static void ElfMenuFocusLoop_OpenTab(struct GameState* g);
static void ElfMenuFocusLoop_TabSelect(struct GameState* g);
static void ElfMenuFocusLoop_ElfSelect(struct GameState* g);

static const MenuLoopFunc ElfMenuFocusLoops[4] = {
    ElfMenuFocusLoop_NoFocus,
    ElfMenuFocusLoop_OpenTab,
    ElfMenuFocusLoop_TabSelect,
    ElfMenuFocusLoop_ElfSelect,
};

const u8 u8_ARRAY_08386494[3] = {
    0,
    27,
    40,
};

const u8 u8_ARRAY_08386497[3] = {
    27,
    13,
    34,
};

// ------------------------------------------------------------------------------------------------------------------------------------

void EachMenuLoop_Elf(struct GameState* g) {
  (ElfMenuLoops[g->mode[2]])(g);
  return;
}

static void ElfMenuLoop_Init(struct GameState* g) {
  u8 i;
  const struct ColorGraphic* gfx;
  struct Zero* z = g->z2;
  LoadGraphic(&gGraphic_ElfMenu, (void*)CHAR_BASE(1));
  LoadPalette(&gPalette_ElfMenu, 0);
  CpuFastCopy(BGMAP(23), g->unk_16d8, 1920);
  RequestBgMapTransfer(g->unk_0ed8, (void*)SCREEN_BASE_16(1), 0x1000);
  for (i = 0; i < 6; i++) {
    (&((g->sceneState).menu).elf)->displayed[i] = 0;
  }
  (&((g->sceneState).menu).elf)->y = 0;
  if (((&z->unk_b4)->status).menuZeroColor == MZC_HARD) {
    (&((g->sceneState).menu).elf)->mode = 4;
  } else {
    (&((g->sceneState).menu).elf)->mode = 0;
  }
  (&((g->sceneState).menu).elf)->cursor = (&((g->sceneState).menu).elf)->tab = 0;
  (&((g->sceneState).menu).elf)->unk_a = 6;
  (&((g->sceneState).menu).elf)->unk_b = 0x10;
  (&((g->sceneState).menu).elf)->blinkID = 0;

// TODO
#if MODERN
  (&((g->sceneState).menu).elf)->unk_f = 0;
#else
  asm("mov r0, #0");
  asm("strb r0, [r1, #15]");
#endif

  gBlendRegBuffer.bldclt = 0x210;

  LOAD_STATIC_GRAPHIC(82);
  LOAD_STATIC_GRAPHIC(83);
  LOAD_STATIC_GRAPHIC(83);
  if (((&z->unk_b4)->status).menuZeroColor == MZC_HARD) {
    CreateElfMenuItem(g, 4, 0);
  } else {
    for (i = 0; i < 5; i++) {
      CreateElfMenuItem(g, i, 0);
    }
  }
  CreateElfIcon(g);
  LoadBlink(81, 0);
  g->mode[2] = 2;
}

static void ElfMenuLoop_Update(struct GameState* g) {
  struct Zero* z = g->z2;
  u8 tab = ELF_MENU->tab;
  u8 prev = g->mode[3];
  if ((g->mode[3] != 0) || (!TrySlideMenu(g))) {
    (ElfMenuFocusLoops[g->mode[3]])(g);
    UpdateBlinkMotionState(81);
    if (ELF_MENU->blinkID != 0) {
      UpdateBlinkMotionState(ELF_MENU->blinkID);
    }
    gBlendRegBuffer.bldalpha = (ELF_MENU->unk_b & 0x1F) | ((0x10 - ELF_MENU->unk_b) << 8);
    if (tab != ELF_MENU->tab) {
      LoadGraphic(gGraphic_ElfTab(ELF_MENU->tab), (void*)CHAR_BASE(1));
      LoadPalette(gPalette_ElfTab(ELF_MENU->tab), 0);
    }

    if (g->mode[3] >= 2) {
      if (tab != ELF_MENU->tab || (prev < 2)) {
#if MODERN
        LoadGraphic(&gGraphics_ElfCategory[ELF_MENU->tab].g, (void*)CHAR_BASE(1));
        LoadPalette(&gGraphics_ElfCategory[ELF_MENU->tab].pal, 0);
#else
        LoadGraphic((const struct Graphic*)(0x08547514 + (20 * ELF_MENU->tab)), (void*)CHAR_BASE(1));
        LoadPalette((const struct Palette*)(0x08547520 + (20 * ELF_MENU->tab)), 0);
#endif
      }
    } else {
      if (1 < prev) {
        LoadGraphic(&gGraphic_0854758C, (void*)CHAR_BASE(1));
        LoadPalette(&gPalette_0854758C, 0);
      }
      if ((ELF_MENU->mode == 0) && (SATELITE_1 != ELF_NONE)) {
        PrintString(STRING(100 + SATELITE_1), 21, 1);
      }
      if ((ELF_MENU->mode == 1) && (SATELITE_2 != ELF_NONE)) {
        PrintString(STRING(100 + SATELITE_2), 21, 1);
      }
    }

    printElfNames(g);
    printElfMenuDescription(g);
    printElfMenuBottomString(g);
    RequestBgMapTransfer(g->unk_0ed8, (void*)SCREEN_BASE_16(1), 0x1000);
  }
}

static void ElfMenuLoop_SlideOut(struct GameState* g) {
  if (MENU->unk_4d == 0) {
    ((struct BgOfs*)gVideoRegBuffer.bgofs[1])->x += 16;
  } else {
    ((struct BgOfs*)gVideoRegBuffer.bgofs[1])->x -= 16;
  }
  ((struct BgOfs*)gVideoRegBuffer.bgofs[1])->x &= 0x1FF;
  if ((((struct BgOfs*)gVideoRegBuffer.bgofs[1])->x & 0xFF) == 0) {
    MENU->unk_4c = MENU->unk_4d;
    g->mode[2] = 1;
    ElfMenuLoop_Exit(g);
  }
}

static void ElfMenuLoop_Exit(struct GameState* g) {
  struct ElfMenuState* m = &((g->sceneState).menu).elf;
  m->unk_f &= 3;
  m->unk_f |= (1 << 2);
  ClearBlink(81);
  if (m->blinkID != 0) {
    ClearBlink(m->blinkID);
  }
}

// --------------------------------------------

NAKED static void ElfMenuFocusLoop_NoFocus(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	ldr r1, _080F6A7C @ =0x000064AC\n\
	adds r0, r5, r1\n\
	ldr r3, [r0]\n\
	ldr r2, _080F6A80 @ =gWindowRegBuffer\n\
	ldrh r1, [r2]\n\
	ldr r0, _080F6A84 @ =0x0000DFFF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _080F6A88 @ =0x00000DFC\n\
	adds r4, r5, r2\n\
	ldrb r0, [r4, #0xb]\n\
	cmp r0, #0xf\n\
	bhi _080F69F2\n\
	adds r0, #1\n\
	strb r0, [r4, #0xb]\n\
_080F69F2:\n\
	ldrb r7, [r4, #7]\n\
	adds r0, r3, #0\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0x1a]\n\
	cmp r0, #1\n\
	beq _080F6A2A\n\
	ldr r6, _080F6A8C @ =gJoypad\n\
	ldrh r1, [r6, #6]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F6A14\n\
	adds r0, r7, #4\n\
	movs r1, #5\n\
	bl __modsi3\n\
	strb r0, [r4, #7]\n\
_080F6A14:\n\
	ldrh r1, [r6, #6]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F6A2A\n\
	ldrb r0, [r4, #7]\n\
	adds r0, #1\n\
	movs r1, #5\n\
	bl __modsi3\n\
	strb r0, [r4, #7]\n\
_080F6A2A:\n\
	ldr r0, _080F6A88 @ =0x00000DFC\n\
	adds r4, r5, r0\n\
	ldrb r1, [r4, #7]\n\
	cmp r7, r1\n\
	beq _080F6A3A\n\
	movs r0, #1\n\
	bl PlaySound\n\
_080F6A3A:\n\
	ldr r0, _080F6A8C @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F6A76\n\
	movs r1, #0\n\
	strb r1, [r4, #6]\n\
	strb r1, [r4, #9]\n\
	movs r0, #1\n\
	strb r0, [r5, #3]\n\
	ldr r2, _080F6A90 @ =0x00000E17\n\
	adds r0, r5, r2\n\
	strb r1, [r0]\n\
	ldrb r0, [r4, #0xc]\n\
	cmp r0, #0\n\
	beq _080F6A60\n\
	bl ClearBlink\n\
_080F6A60:\n\
	movs r0, #0x4d\n\
	strb r0, [r4, #0xc]\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	ldrb r0, [r4, #0xc]\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #2\n\
	bl PlaySound\n\
_080F6A76:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F6A7C: .4byte 0x000064AC\n\
_080F6A80: .4byte gWindowRegBuffer\n\
_080F6A84: .4byte 0x0000DFFF\n\
_080F6A88: .4byte 0x00000DFC\n\
_080F6A8C: .4byte gJoypad\n\
_080F6A90: .4byte 0x00000E17\n\
 .syntax divided\n");
}

NAKED static void ElfMenuFocusLoop_OpenTab(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	ldr r1, _080F6B20 @ =0x00000DFC\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0, #0xc]\n\
	bl UpdateBlinkMotionState\n\
	ldr r3, _080F6B24 @ =0x00000E17\n\
	adds r6, r5, r3\n\
	ldrb r0, [r6]\n\
	cmp r0, #0\n\
	bne _080F6AEC\n\
	adds r0, r5, #0\n\
	bl FUN_080f70d8\n\
	movs r4, #0\n\
_080F6AB4:\n\
	adds r0, r5, #0\n\
	adds r1, r4, #0\n\
	bl createMenuCursor\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #2\n\
	bls _080F6AB4\n\
	movs r4, #0\n\
_080F6AC8:\n\
	adds r0, r5, #0\n\
	movs r1, #0\n\
	adds r2, r4, #0\n\
	bl CreateMenuComp9\n\
	adds r0, r5, #0\n\
	movs r1, #1\n\
	adds r2, r4, #0\n\
	bl CreateMenuComp9\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #5\n\
	bls _080F6AC8\n\
	ldrb r0, [r6]\n\
	adds r0, #1\n\
	strb r0, [r6]\n\
_080F6AEC:\n\
	ldr r0, _080F6B28 @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r7, #2\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F6B2C\n\
	movs r0, #0\n\
	strb r0, [r5, #3]\n\
	ldr r0, _080F6B20 @ =0x00000DFC\n\
	adds r4, r5, r0\n\
	ldrb r0, [r4, #0xc]\n\
	bl ClearBlink\n\
	movs r0, #0x4e\n\
	strb r0, [r4, #0xc]\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	ldrb r0, [r4, #0xc]\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #3\n\
	bl PlaySound\n\
	b _080F6B7E\n\
	.align 2, 0\n\
_080F6B20: .4byte 0x00000DFC\n\
_080F6B24: .4byte 0x00000E17\n\
_080F6B28: .4byte gJoypad\n\
_080F6B2C:\n\
	ldr r1, _080F6B40 @ =0x00000DFC\n\
	adds r6, r5, r1\n\
	ldrb r0, [r6, #0xb]\n\
	adds r4, r0, #0\n\
	cmp r4, #0\n\
	beq _080F6B44\n\
	subs r0, #1\n\
	strb r0, [r6, #0xb]\n\
	b _080F6B7E\n\
	.align 2, 0\n\
_080F6B40: .4byte 0x00000DFC\n\
_080F6B44:\n\
	strb r7, [r5, #3]\n\
	ldr r3, _080F6B84 @ =0x00000E17\n\
	adds r0, r5, r3\n\
	strb r4, [r0]\n\
	strb r4, [r6, #8]\n\
	ldrb r0, [r6, #0xc]\n\
	cmp r0, #0\n\
	beq _080F6B5A\n\
	bl ClearBlink\n\
	strb r4, [r6, #0xc]\n\
_080F6B5A:\n\
	ldr r2, _080F6B88 @ =gWindowRegBuffer\n\
	ldrh r1, [r2]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #6\n\
	adds r0, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	strb r7, [r2, #0xc]\n\
	ldrb r0, [r2, #0xe]\n\
	movs r1, #0x11\n\
	orrs r0, r1\n\
	strb r0, [r2, #0xe]\n\
	ldr r0, _080F6B8C @ =0x00001078\n\
	strh r0, [r2, #4]\n\
	adds r0, #0x18\n\
	strh r0, [r2, #8]\n\
	movs r0, #0x10\n\
	strb r0, [r6, #0xd]\n\
_080F6B7E:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F6B84: .4byte 0x00000E17\n\
_080F6B88: .4byte gWindowRegBuffer\n\
_080F6B8C: .4byte 0x00001078\n\
 .syntax divided\n");
}

NAKED static void ElfMenuFocusLoop_TabSelect(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r7, r0, #0\n\
	ldr r0, _080F6C00 @ =0x00000E17\n\
	adds r6, r7, r0\n\
	ldrb r0, [r6]\n\
	cmp r0, #0\n\
	bne _080F6BB8\n\
	movs r0, #0x4f\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	ldr r0, _080F6C04 @ =0x00000DFC\n\
	adds r1, r7, r0\n\
	ldrb r0, [r1, #8]\n\
	strb r0, [r1, #0xa]\n\
	ldrb r0, [r6]\n\
	adds r0, #1\n\
	strb r0, [r6]\n\
_080F6BB8:\n\
	movs r0, #0x4f\n\
	bl UpdateBlinkMotionState\n\
	ldr r0, _080F6C04 @ =0x00000DFC\n\
	adds r4, r7, r0\n\
	ldrb r3, [r4, #0xd]\n\
	lsls r1, r3, #0x18\n\
	lsrs r0, r1, #0x18\n\
	cmp r0, #0x90\n\
	bhi _080F6BDE\n\
	lsrs r0, r1, #0x1c\n\
	ldr r2, _080F6C08 @ =gWindowRegBuffer\n\
	lsls r0, r0, #0xc\n\
	movs r1, #0x90\n\
	orrs r0, r1\n\
	strh r0, [r2, #8]\n\
	adds r0, r3, #0\n\
	adds r0, #8\n\
	strb r0, [r4, #0xd]\n\
_080F6BDE:\n\
	ldr r2, _080F6C0C @ =gJoypad\n\
	ldrh r1, [r2, #4]\n\
	movs r5, #0x81\n\
	ands r5, r1\n\
	cmp r5, #0\n\
	beq _080F6C10\n\
	movs r1, #0\n\
	movs r0, #3\n\
	strb r0, [r7, #3]\n\
	strb r1, [r6]\n\
	movs r0, #0x4f\n\
	bl ClearBlink\n\
	movs r0, #2\n\
	bl PlaySound\n\
	b _080F6CB6\n\
	.align 2, 0\n\
_080F6C00: .4byte 0x00000E17\n\
_080F6C04: .4byte 0x00000DFC\n\
_080F6C08: .4byte gWindowRegBuffer\n\
_080F6C0C: .4byte gJoypad\n\
_080F6C10:\n\
	movs r0, #2\n\
	ands r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r6, r0, #0x10\n\
	cmp r6, #0\n\
	beq _080F6C50\n\
	strb r5, [r7, #3]\n\
	movs r0, #0x4f\n\
	bl ClearBlink\n\
	movs r0, #0x4e\n\
	strb r0, [r4, #0xc]\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	ldrb r0, [r4, #0xc]\n\
	bl UpdateBlinkMotionState\n\
	strb r5, [r4, #8]\n\
	ldr r2, _080F6C48 @ =gWindowRegBuffer\n\
	ldrh r1, [r2]\n\
	ldr r0, _080F6C4C @ =0x0000DFFF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #3\n\
	bl PlaySound\n\
	b _080F6CB6\n\
	.align 2, 0\n\
_080F6C48: .4byte gWindowRegBuffer\n\
_080F6C4C: .4byte 0x0000DFFF\n\
_080F6C50:\n\
	ldrb r0, [r4, #8]\n\
	mov r8, r0\n\
	ldrh r5, [r2, #6]\n\
	movs r0, #0x20\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	beq _080F6C6A\n\
	mov r0, r8\n\
	adds r0, #2\n\
	movs r1, #3\n\
	bl __modsi3\n\
	strb r0, [r4, #8]\n\
_080F6C6A:\n\
	movs r0, #0x10\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	beq _080F6C7E\n\
	ldrb r0, [r4, #8]\n\
	adds r0, #1\n\
	movs r1, #3\n\
	bl __modsi3\n\
	strb r0, [r4, #8]\n\
_080F6C7E:\n\
	ldrb r0, [r4, #8]\n\
	cmp r8, r0\n\
	beq _080F6CB6\n\
	movs r0, #0x4f\n\
	bl ClearBlink\n\
	movs r0, #0x4f\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x4f\n\
	bl UpdateBlinkMotionState\n\
	ldrb r0, [r4, #8]\n\
	strb r0, [r4, #0xa]\n\
	strb r6, [r4, #6]\n\
	strb r6, [r4, #9]\n\
	adds r0, r7, #0\n\
	bl FUN_080f70d8\n\
	movs r0, #0x10\n\
	strb r0, [r4, #0xd]\n\
	ldr r1, _080F6CC0 @ =gWindowRegBuffer\n\
	ldr r0, _080F6CC4 @ =0x00001090\n\
	strh r0, [r1, #8]\n\
	movs r0, #1\n\
	bl PlaySound\n\
_080F6CB6:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F6CC0: .4byte gWindowRegBuffer\n\
_080F6CC4: .4byte 0x00001090\n\
 .syntax divided\n");
}

NAKED static void ElfMenuFocusLoop_ElfSelect(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r6, r0, #0\n\
	ldr r1, _080F6D38 @ =0x000064AC\n\
	adds r0, r6, r1\n\
	ldr r7, [r0]\n\
	ldr r0, _080F6D3C @ =0x00000E17\n\
	adds r4, r6, r0\n\
	ldrb r0, [r4]\n\
	cmp r0, #0\n\
	bne _080F6CFA\n\
	movs r0, #0x4f\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x4f\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #0x4f\n\
	bl ClearBlink\n\
	ldrb r0, [r4]\n\
	adds r0, #1\n\
	strb r0, [r4]\n\
_080F6CFA:\n\
	ldr r1, _080F6D40 @ =0x00000DFC\n\
	adds r3, r6, r1\n\
	ldrb r5, [r3, #0xd]\n\
	lsls r1, r5, #0x18\n\
	lsrs r0, r1, #0x18\n\
	cmp r0, #0x90\n\
	bhi _080F6D1A\n\
	lsrs r0, r1, #0x1c\n\
	ldr r2, _080F6D44 @ =gWindowRegBuffer\n\
	lsls r0, r0, #0xc\n\
	movs r1, #0x90\n\
	orrs r0, r1\n\
	strh r0, [r2, #8]\n\
	adds r0, r5, #0\n\
	adds r0, #8\n\
	strb r0, [r3, #0xd]\n\
_080F6D1A:\n\
	ldrb r0, [r3, #6]\n\
	mov r8, r0\n\
	ldrb r0, [r4]\n\
	cmp r0, #1\n\
	bhi _080F6D26\n\
	b _080F6E94\n\
_080F6D26:\n\
	adds r1, r0, #0\n\
	cmp r1, #3\n\
	beq _080F6DBA\n\
	cmp r1, #3\n\
	bgt _080F6D48\n\
	cmp r1, #2\n\
	beq _080F6D64\n\
	b _080F6E94\n\
	.align 2, 0\n\
_080F6D38: .4byte 0x000064AC\n\
_080F6D3C: .4byte 0x00000E17\n\
_080F6D40: .4byte 0x00000DFC\n\
_080F6D44: .4byte gWindowRegBuffer\n\
_080F6D48:\n\
	cmp r1, #5\n\
	ble _080F6D4E\n\
	b _080F6E94\n\
_080F6D4E:\n\
	ldr r0, _080F6D60 @ =gJoypad\n\
	ldrh r0, [r0, #4]\n\
	cmp r0, #0\n\
	bne _080F6D58\n\
	b _080F6E94\n\
_080F6D58:\n\
	movs r0, #1\n\
	strb r0, [r4]\n\
	b _080F6E94\n\
	.align 2, 0\n\
_080F6D60: .4byte gJoypad\n\
_080F6D64:\n\
	ldr r0, _080F6D74 @ =gJoypad\n\
	ldrh r2, [r0, #4]\n\
	ands r1, r2\n\
	cmp r1, #0\n\
	beq _080F6D78\n\
	movs r0, #1\n\
	strb r0, [r4]\n\
	b _080F702C\n\
	.align 2, 0\n\
_080F6D74: .4byte gJoypad\n\
_080F6D78:\n\
	movs r5, #1\n\
	movs r1, #1\n\
	ands r1, r2\n\
	cmp r1, #0\n\
	beq _080F6D92\n\
	ldrb r0, [r3, #0xe]\n\
	cmp r0, #0\n\
	beq _080F6D8C\n\
	strb r5, [r4]\n\
	b _080F702C\n\
_080F6D8C:\n\
	movs r0, #3\n\
	strb r0, [r4]\n\
	b _080F70CA\n\
_080F6D92:\n\
	ldrb r4, [r3, #0xe]\n\
	ldrh r2, [r0, #6]\n\
	movs r0, #0x20\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080F6DA0\n\
	strb r1, [r3, #0xe]\n\
_080F6DA0:\n\
	movs r0, #0x10\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080F6DAA\n\
	strb r5, [r3, #0xe]\n\
_080F6DAA:\n\
	ldrb r3, [r3, #0xe]\n\
	cmp r4, r3\n\
	bne _080F6DB2\n\
	b _080F70CA\n\
_080F6DB2:\n\
	movs r0, #1\n\
	bl PlaySound\n\
	b _080F70CA\n\
_080F6DBA:\n\
	ldrb r0, [r3, #9]\n\
	adds r0, r3, r0\n\
	ldrb r4, [r0]\n\
	ldr r1, _080F6DF0 @ =gElfBreedInfo\n\
	lsls r0, r4, #2\n\
	adds r5, r0, r1\n\
	ldrb r1, [r5]\n\
	lsls r1, r1, #0x1d\n\
	ldr r0, _080F6DF4 @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	adds r0, r0, r4\n\
	ldr r0, [r0]\n\
	lsls r2, r0, #0x1b\n\
	lsrs r1, r1, #0x1d\n\
	lsrs r0, r2, #0x1e\n\
	cmp r1, r0\n\
	beq _080F6DFC\n\
	ldr r3, _080F6DF8 @ =u16_ARRAY_08371afc\n\
	adds r1, r0, #0\n\
	adds r1, #1\n\
	ldrb r2, [r5, #3]\n\
	lsls r0, r2, #1\n\
	adds r0, r0, r2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r3\n\
	b _080F6E08\n\
	.align 2, 0\n\
_080F6DF0: .4byte gElfBreedInfo\n\
_080F6DF4: .4byte gUnlockedElfPtr\n\
_080F6DF8: .4byte u16_ARRAY_08371afc\n\
_080F6DFC:\n\
	ldr r2, _080F6E4C @ =u16_ARRAY_08371afc\n\
	ldrb r1, [r5, #3]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
_080F6E08:\n\
	ldrh r2, [r0]\n\
	adds r1, r7, #0\n\
	adds r1, #0xb4\n\
	ldrh r0, [r1, #6]\n\
	subs r0, r0, r2\n\
	strh r0, [r1, #6]\n\
	movs r0, #0x28\n\
	bl PlaySound\n\
	ldr r1, _080F6E50 @ =gElfBreedInfo\n\
	lsls r0, r4, #2\n\
	adds r0, r0, r1\n\
	ldrb r5, [r0]\n\
	lsls r1, r5, #0x1d\n\
	ldr r0, _080F6E54 @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	adds r3, r0, r4\n\
	ldr r0, [r3]\n\
	lsls r2, r0, #0x1b\n\
	lsrs r1, r1, #0x1d\n\
	lsrs r0, r2, #0x1e\n\
	cmp r1, r0\n\
	beq _080F6E58\n\
	adds r1, r0, #0\n\
	adds r1, #1\n\
	movs r0, #3\n\
	ands r1, r0\n\
	lsls r1, r1, #3\n\
	ldrb r2, [r3]\n\
	movs r0, #0x19\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	b _080F6E7A\n\
	.align 2, 0\n\
_080F6E4C: .4byte u16_ARRAY_08371afc\n\
_080F6E50: .4byte gElfBreedInfo\n\
_080F6E54: .4byte gUnlockedElfPtr\n\
_080F6E58:\n\
	lsls r0, r5, #0x1a\n\
	lsrs r0, r0, #0x1d\n\
	cmp r0, #1\n\
	bne _080F6E76\n\
	ldrb r1, [r3]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F6E72\n\
	movs r0, #5\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	b _080F6E7C\n\
_080F6E72:\n\
	movs r0, #4\n\
	b _080F6E7A\n\
_080F6E76:\n\
	ldrb r0, [r3]\n\
	movs r1, #4\n\
_080F6E7A:\n\
	orrs r0, r1\n\
_080F6E7C:\n\
	strb r0, [r3]\n\
	adds r0, r6, #0\n\
	bl FUN_080f70d8\n\
	ldr r0, _080F6E90 @ =0x00000E17\n\
	adds r1, r6, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	b _080F70CA\n\
	.align 2, 0\n\
_080F6E90: .4byte 0x00000E17\n\
_080F6E94:\n\
	ldr r5, _080F6EC4 @ =gJoypad\n\
	ldrh r1, [r5, #4]\n\
	movs r4, #1\n\
	adds r3, r4, #0\n\
	ands r3, r1\n\
	cmp r3, #0\n\
	bne _080F6EA4\n\
	b _080F6FFC\n\
_080F6EA4:\n\
	ldr r0, _080F6EC8 @ =0x00000DFC\n\
	adds r1, r6, r0\n\
	ldrb r0, [r1, #9]\n\
	adds r0, r1, r0\n\
	ldrb r4, [r0]\n\
	cmp r4, #0xff\n\
	bne _080F6EB4\n\
	b _080F6FF4\n\
_080F6EB4:\n\
	ldrb r0, [r1, #7]\n\
	cmp r0, #1\n\
	beq _080F6EF0\n\
	cmp r0, #1\n\
	bgt _080F6ECC\n\
	cmp r0, #0\n\
	beq _080F6ED6\n\
	b _080F6FD8\n\
	.align 2, 0\n\
_080F6EC4: .4byte gJoypad\n\
_080F6EC8: .4byte 0x00000DFC\n\
_080F6ECC:\n\
	cmp r0, #2\n\
	beq _080F6F0C\n\
	cmp r0, #3\n\
	beq _080F6F30\n\
	b _080F6FD8\n\
_080F6ED6:\n\
	adds r1, r7, #0\n\
	adds r1, #0xb4\n\
	ldrb r2, [r1]\n\
	cmp r2, r4\n\
	bne _080F6EE4\n\
	movs r0, #0xff\n\
	b _080F6FD6\n\
_080F6EE4:\n\
	ldrb r0, [r1, #1]\n\
	cmp r0, r4\n\
	bne _080F6EEC\n\
	strb r2, [r1, #1]\n\
_080F6EEC:\n\
	strb r4, [r1]\n\
	b _080F6FD8\n\
_080F6EF0:\n\
	adds r1, r7, #0\n\
	adds r1, #0xb4\n\
	ldrb r2, [r1, #1]\n\
	cmp r2, r4\n\
	bne _080F6F00\n\
	movs r0, #0xff\n\
	strb r0, [r1, #1]\n\
	b _080F6FD8\n\
_080F6F00:\n\
	ldrb r0, [r1]\n\
	cmp r0, r4\n\
	bne _080F6F08\n\
	strb r2, [r1]\n\
_080F6F08:\n\
	strb r4, [r1, #1]\n\
	b _080F6FD8\n\
_080F6F0C:\n\
	movs r0, #0x23\n\
	bl PlaySound\n\
	ldr r1, _080F6F28 @ =0x00000121\n\
	adds r0, r7, r1\n\
	strb r4, [r0]\n\
	ldr r1, _080F6F2C @ =0x00000E1C\n\
	adds r0, r6, r1\n\
	strb r4, [r0]\n\
	movs r0, #3\n\
	strb r0, [r6, #1]\n\
	strb r0, [r6, #2]\n\
	b _080F70CA\n\
	.align 2, 0\n\
_080F6F28: .4byte 0x00000121\n\
_080F6F2C: .4byte 0x00000E1C\n\
_080F6F30:\n\
	ldr r1, _080F6F60 @ =gElfBreedInfo\n\
	lsls r0, r4, #2\n\
	adds r5, r0, r1\n\
	ldrb r1, [r5]\n\
	lsls r1, r1, #0x1d\n\
	ldr r0, _080F6F64 @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	adds r0, r0, r4\n\
	ldr r0, [r0]\n\
	lsls r2, r0, #0x1b\n\
	lsrs r1, r1, #0x1d\n\
	lsrs r0, r2, #0x1e\n\
	cmp r1, r0\n\
	beq _080F6F6C\n\
	ldr r3, _080F6F68 @ =u16_ARRAY_08371afc\n\
	adds r1, r0, #0\n\
	adds r1, #1\n\
	ldrb r2, [r5, #3]\n\
	lsls r0, r2, #1\n\
	adds r0, r0, r2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r3\n\
	b _080F6F78\n\
	.align 2, 0\n\
_080F6F60: .4byte gElfBreedInfo\n\
_080F6F64: .4byte gUnlockedElfPtr\n\
_080F6F68: .4byte u16_ARRAY_08371afc\n\
_080F6F6C:\n\
	ldr r2, _080F6F9C @ =u16_ARRAY_08371afc\n\
	ldrb r1, [r5, #3]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
_080F6F78:\n\
	ldrh r2, [r0]\n\
	adds r1, r7, #0\n\
	adds r1, #0xb4\n\
	ldrb r0, [r1]\n\
	cmp r0, r4\n\
	beq _080F6F8A\n\
	ldrb r0, [r1, #1]\n\
	cmp r0, r4\n\
	bne _080F6FA4\n\
_080F6F8A:\n\
	movs r0, #4\n\
	bl PlaySound\n\
	ldr r0, _080F6FA0 @ =0x00000E17\n\
	adds r1, r6, r0\n\
	movs r0, #5\n\
	strb r0, [r1]\n\
	b _080F70CA\n\
	.align 2, 0\n\
_080F6F9C: .4byte u16_ARRAY_08371afc\n\
_080F6FA0: .4byte 0x00000E17\n\
_080F6FA4:\n\
	ldrh r0, [r1, #6]\n\
	cmp r0, r2\n\
	bhs _080F6FC0\n\
	movs r0, #4\n\
	bl PlaySound\n\
	ldr r0, _080F6FBC @ =0x00000E17\n\
	adds r1, r6, r0\n\
	movs r0, #4\n\
	strb r0, [r1]\n\
	b _080F70CA\n\
	.align 2, 0\n\
_080F6FBC: .4byte 0x00000E17\n\
_080F6FC0:\n\
	adds r0, r6, #0\n\
	movs r1, #5\n\
	bl createMenuCursor\n\
	ldr r0, _080F6FEC @ =0x00000DFC\n\
	adds r1, r6, r0\n\
	movs r0, #0\n\
	strb r0, [r1, #0xe]\n\
	ldr r0, _080F6FF0 @ =0x00000E17\n\
	adds r1, r6, r0\n\
	movs r0, #2\n\
_080F6FD6:\n\
	strb r0, [r1]\n\
_080F6FD8:\n\
	ldr r1, _080F6FEC @ =0x00000DFC\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0, #7]\n\
	cmp r0, #3\n\
	bhi _080F70CA\n\
	movs r0, #2\n\
	bl PlaySound\n\
	b _080F70CA\n\
	.align 2, 0\n\
_080F6FEC: .4byte 0x00000DFC\n\
_080F6FF0: .4byte 0x00000E17\n\
_080F6FF4:\n\
	movs r0, #4\n\
	bl PlaySound\n\
	b _080F70CA\n\
_080F6FFC:\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F7022\n\
	ldr r0, _080F7034 @ =0x00000DFC\n\
	adds r2, r6, r0\n\
	ldrb r1, [r2, #0xf]\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F703C\n\
	ldrb r0, [r2, #9]\n\
	cmp r0, #0\n\
	bne _080F703C\n\
	ldrh r1, [r5, #6]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F706E\n\
_080F7022:\n\
	movs r0, #2\n\
	strb r0, [r6, #3]\n\
	ldr r1, _080F7038 @ =0x00000E17\n\
	adds r0, r6, r1\n\
	strb r3, [r0]\n\
_080F702C:\n\
	movs r0, #3\n\
	bl PlaySound\n\
	b _080F70CA\n\
	.align 2, 0\n\
_080F7034: .4byte 0x00000DFC\n\
_080F7038: .4byte 0x00000E17\n\
_080F703C:\n\
	ldr r0, _080F7060 @ =gJoypad\n\
	ldrh r1, [r0, #6]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F706E\n\
	ldr r0, _080F7064 @ =0x00000DFC\n\
	adds r1, r6, r0\n\
	ldrb r0, [r1, #6]\n\
	subs r0, #1\n\
	strb r0, [r1, #6]\n\
	ldrb r0, [r1, #9]\n\
	cmp r0, #0\n\
	beq _080F7068\n\
	subs r0, #1\n\
	strb r0, [r1, #9]\n\
	b _080F706E\n\
	.align 2, 0\n\
_080F7060: .4byte gJoypad\n\
_080F7064: .4byte 0x00000DFC\n\
_080F7068:\n\
	adds r0, r6, #0\n\
	bl FUN_080f70d8\n\
_080F706E:\n\
	ldr r0, _080F709C @ =gJoypad\n\
	ldrh r1, [r0, #6]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F70BA\n\
	ldr r1, _080F70A0 @ =0x00000DFC\n\
	adds r2, r6, r1\n\
	ldrb r1, [r2, #9]\n\
	cmp r1, #4\n\
	bhi _080F70A4\n\
	ldrb r0, [r2, #9]\n\
	adds r0, #1\n\
	adds r0, r2, r0\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xff\n\
	beq _080F70BA\n\
	ldrb r0, [r2, #6]\n\
	adds r0, #1\n\
	strb r0, [r2, #6]\n\
	adds r0, r1, #1\n\
	strb r0, [r2, #9]\n\
	b _080F70BA\n\
	.align 2, 0\n\
_080F709C: .4byte gJoypad\n\
_080F70A0: .4byte 0x00000DFC\n\
_080F70A4:\n\
	ldrb r1, [r2, #0xf]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F70BA\n\
	ldrb r0, [r2, #6]\n\
	adds r0, #1\n\
	strb r0, [r2, #6]\n\
	adds r0, r6, #0\n\
	bl FUN_080f70d8\n\
_080F70BA:\n\
	ldr r1, _080F70D4 @ =0x00000DFC\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0, #6]\n\
	cmp r8, r0\n\
	beq _080F70CA\n\
	movs r0, #1\n\
	bl PlaySound\n\
_080F70CA:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F70D4: .4byte 0x00000DFC\n\
 .syntax divided\n");
}

NAKED void FUN_080f70d8(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0xc\n\
	mov sl, r0\n\
	ldr r2, _080F7140 @ =0x00000DFC\n\
	add r2, sl\n\
	ldrb r1, [r2, #0xf]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #3\n\
	rsbs r1, r1, #0\n\
	ands r0, r1\n\
	strb r0, [r2, #0xf]\n\
	movs r6, #0\n\
	ldr r4, _080F7144 @ =u8_ARRAY_08386494\n\
	movs r3, #0xff\n\
_080F7100:\n\
	adds r0, r2, r6\n\
	ldrb r1, [r0]\n\
	orrs r1, r3\n\
	strb r1, [r0]\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, #5\n\
	bls _080F7100\n\
	ldr r2, _080F7140 @ =0x00000DFC\n\
	add r2, sl\n\
	ldrb r0, [r2, #6]\n\
	ldrb r1, [r2, #9]\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov r8, r0\n\
	ldrb r0, [r2, #8]\n\
	adds r0, r0, r4\n\
	ldrb r0, [r0]\n\
	mov sb, r0\n\
	movs r0, #0\n\
	mov ip, r0\n\
	ldrb r0, [r2, #7]\n\
	cmp r0, #4\n\
	bls _080F7136\n\
	b _080F7402\n\
_080F7136:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080F7148 @ =_080F714C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080F7140: .4byte 0x00000DFC\n\
_080F7144: .4byte u8_ARRAY_08386494\n\
_080F7148: .4byte _080F714C\n\
_080F714C: @ jump table\n\
	.4byte _080F7160 @ case 0\n\
	.4byte _080F7160 @ case 1\n\
	.4byte _080F7214 @ case 2\n\
	.4byte _080F72D0 @ case 3\n\
	.4byte _080F738C @ case 4\n\
_080F7160:\n\
	movs r6, #0\n\
	ldr r1, _080F71D8 @ =u8_ARRAY_08386497\n\
	ldr r2, _080F71DC @ =0x00000DFC\n\
	add r2, sl\n\
	ldrb r0, [r2, #8]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r6, r0\n\
	blo _080F7174\n\
	b _080F7402\n\
_080F7174:\n\
	ldr r0, _080F71E0 @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	str r0, [sp]\n\
	adds r3, r2, #0\n\
_080F717C:\n\
	mov r1, sb\n\
	adds r4, r6, r1\n\
	ldr r2, [sp]\n\
	adds r5, r2, r4\n\
	ldrb r2, [r5]\n\
	movs r0, #1\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080F71FA\n\
	movs r7, #2\n\
	movs r0, #2\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _080F71FA\n\
	ldr r0, _080F71E4 @ =gElfBreedInfo\n\
	lsls r1, r4, #2\n\
	adds r1, r1, r0\n\
	ldrb r1, [r1]\n\
	lsls r0, r1, #0x19\n\
	cmp r0, #0\n\
	blt _080F71B6\n\
	lsls r0, r1, #0x1a\n\
	lsrs r0, r0, #0x1d\n\
	cmp r0, #1\n\
	bne _080F71FA\n\
	movs r0, #4\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080F71FA\n\
_080F71B6:\n\
	lsls r1, r1, #0x1d\n\
	lsrs r1, r1, #0x1d\n\
	ldr r0, [r5]\n\
	lsls r0, r0, #0x1b\n\
	lsrs r0, r0, #0x1e\n\
	cmp r1, r0\n\
	bne _080F71FA\n\
	cmp r8, ip\n\
	bhi _080F71E8\n\
	mov r1, ip\n\
	mov r2, r8\n\
	subs r0, r1, r2\n\
	cmp r0, #5\n\
	bgt _080F729C\n\
	adds r0, r3, r0\n\
	strb r4, [r0]\n\
	b _080F71F0\n\
	.align 2, 0\n\
_080F71D8: .4byte u8_ARRAY_08386497\n\
_080F71DC: .4byte 0x00000DFC\n\
_080F71E0: .4byte gUnlockedElfPtr\n\
_080F71E4: .4byte gElfBreedInfo\n\
_080F71E8:\n\
	ldrb r0, [r3, #0xf]\n\
	movs r7, #1\n\
	orrs r0, r7\n\
	strb r0, [r3, #0xf]\n\
_080F71F0:\n\
	mov r0, ip\n\
	adds r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov ip, r0\n\
_080F71FA:\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	ldrb r0, [r3, #8]\n\
	ldr r1, _080F7210 @ =u8_ARRAY_08386497\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r6, r0\n\
	blo _080F717C\n\
	b _080F7402\n\
	.align 2, 0\n\
_080F7210: .4byte u8_ARRAY_08386497\n\
_080F7214:\n\
	movs r6, #0\n\
	ldr r1, _080F728C @ =u8_ARRAY_08386497\n\
	ldr r2, _080F7290 @ =0x00000DFC\n\
	add r2, sl\n\
	ldrb r0, [r2, #8]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r6, r0\n\
	blo _080F7228\n\
	b _080F7402\n\
_080F7228:\n\
	ldr r0, _080F7294 @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	str r0, [sp, #4]\n\
	adds r3, r2, #0\n\
_080F7230:\n\
	mov r2, sb\n\
	adds r4, r6, r2\n\
	ldr r7, [sp, #4]\n\
	adds r5, r7, r4\n\
	ldrb r2, [r5]\n\
	movs r0, #1\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080F72B6\n\
	movs r7, #2\n\
	movs r0, #2\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _080F72B6\n\
	ldr r0, _080F7298 @ =gElfBreedInfo\n\
	lsls r1, r4, #2\n\
	adds r1, r1, r0\n\
	ldrb r1, [r1]\n\
	lsls r0, r1, #0x19\n\
	cmp r0, #0\n\
	blt _080F72B6\n\
	lsls r0, r1, #0x1a\n\
	lsrs r0, r0, #0x1d\n\
	cmp r0, #1\n\
	bne _080F726A\n\
	movs r0, #4\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _080F72B6\n\
_080F726A:\n\
	lsls r1, r1, #0x1d\n\
	lsrs r1, r1, #0x1d\n\
	ldr r0, [r5]\n\
	lsls r0, r0, #0x1b\n\
	lsrs r0, r0, #0x1e\n\
	cmp r1, r0\n\
	bne _080F72B6\n\
	cmp r8, ip\n\
	bhi _080F72A4\n\
	mov r1, ip\n\
	mov r2, r8\n\
	subs r0, r1, r2\n\
	cmp r0, #5\n\
	bgt _080F729C\n\
	adds r0, r3, r0\n\
	strb r4, [r0]\n\
	b _080F72AC\n\
	.align 2, 0\n\
_080F728C: .4byte u8_ARRAY_08386497\n\
_080F7290: .4byte 0x00000DFC\n\
_080F7294: .4byte gUnlockedElfPtr\n\
_080F7298: .4byte gElfBreedInfo\n\
_080F729C:\n\
	ldrb r0, [r3, #0xf]\n\
	orrs r0, r7\n\
	strb r0, [r3, #0xf]\n\
	b _080F7402\n\
_080F72A4:\n\
	ldrb r0, [r3, #0xf]\n\
	movs r7, #1\n\
	orrs r0, r7\n\
	strb r0, [r3, #0xf]\n\
_080F72AC:\n\
	mov r0, ip\n\
	adds r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov ip, r0\n\
_080F72B6:\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	ldrb r0, [r3, #8]\n\
	ldr r1, _080F72CC @ =u8_ARRAY_08386497\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r6, r0\n\
	blo _080F7230\n\
	b _080F7402\n\
	.align 2, 0\n\
_080F72CC: .4byte u8_ARRAY_08386497\n\
_080F72D0:\n\
	movs r6, #0\n\
	ldr r1, _080F7348 @ =u8_ARRAY_08386497\n\
	ldr r2, _080F734C @ =0x00000DFC\n\
	add r2, sl\n\
	ldrb r0, [r2, #8]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r6, r0\n\
	blo _080F72E4\n\
	b _080F7402\n\
_080F72E4:\n\
	ldr r0, _080F7350 @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	str r0, [sp, #8]\n\
	adds r5, r2, #0\n\
_080F72EC:\n\
	mov r2, sb\n\
	adds r1, r6, r2\n\
	ldr r7, [sp, #8]\n\
	adds r3, r7, r1\n\
	ldrb r4, [r3]\n\
	movs r0, #1\n\
	ands r0, r4\n\
	adds r7, r1, #0\n\
	cmp r0, #0\n\
	beq _080F7374\n\
	movs r0, #2\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	bne _080F7374\n\
	ldr r1, _080F7354 @ =gElfBreedInfo\n\
	lsls r0, r7, #2\n\
	adds r0, r0, r1\n\
	ldrb r2, [r0]\n\
	lsls r1, r2, #0x1d\n\
	ldr r0, [r3]\n\
	lsls r0, r0, #0x1b\n\
	lsrs r1, r1, #0x1d\n\
	lsrs r0, r0, #0x1e\n\
	cmp r1, r0\n\
	bne _080F7332\n\
	lsls r1, r2, #0x1a\n\
	lsrs r0, r1, #0x1d\n\
	cmp r0, #1\n\
	beq _080F7332\n\
	cmp r0, #2\n\
	bne _080F7374\n\
	movs r0, #4\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	bne _080F7374\n\
_080F7332:\n\
	cmp r8, ip\n\
	bhi _080F7362\n\
	mov r1, ip\n\
	mov r2, r8\n\
	subs r0, r1, r2\n\
	cmp r0, #5\n\
	bgt _080F7358\n\
	adds r0, r5, r0\n\
	strb r7, [r0]\n\
	b _080F736A\n\
	.align 2, 0\n\
_080F7348: .4byte u8_ARRAY_08386497\n\
_080F734C: .4byte 0x00000DFC\n\
_080F7350: .4byte gUnlockedElfPtr\n\
_080F7354: .4byte gElfBreedInfo\n\
_080F7358:\n\
	ldrb r1, [r5, #0xf]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xf]\n\
	b _080F7402\n\
_080F7362:\n\
	ldrb r1, [r5, #0xf]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xf]\n\
_080F736A:\n\
	mov r0, ip\n\
	adds r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov ip, r0\n\
_080F7374:\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	ldrb r0, [r5, #8]\n\
	ldr r7, _080F7388 @ =u8_ARRAY_08386497\n\
	adds r0, r0, r7\n\
	ldrb r0, [r0]\n\
	cmp r6, r0\n\
	blo _080F72EC\n\
	b _080F7402\n\
	.align 2, 0\n\
_080F7388: .4byte u8_ARRAY_08386497\n\
_080F738C:\n\
	movs r6, #0\n\
	ldr r1, _080F73C8 @ =u8_ARRAY_08386497\n\
	ldr r2, _080F73CC @ =0x00000DFC\n\
	add r2, sl\n\
	ldrb r0, [r2, #8]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r6, r0\n\
	bhs _080F7402\n\
	ldr r0, _080F73D0 @ =gUnlockedElfPtr\n\
	ldr r5, [r0]\n\
	adds r4, r2, #0\n\
_080F73A4:\n\
	mov r0, sb\n\
	adds r3, r6, r0\n\
	adds r0, r5, r3\n\
	ldrb r1, [r0]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F73F0\n\
	cmp r8, ip\n\
	bhi _080F73DE\n\
	mov r1, ip\n\
	mov r7, r8\n\
	subs r0, r1, r7\n\
	cmp r0, #5\n\
	bgt _080F73D4\n\
	adds r0, r2, r0\n\
	strb r3, [r0]\n\
	b _080F73E6\n\
	.align 2, 0\n\
_080F73C8: .4byte u8_ARRAY_08386497\n\
_080F73CC: .4byte 0x00000DFC\n\
_080F73D0: .4byte gUnlockedElfPtr\n\
_080F73D4:\n\
	ldrb r0, [r2, #0xf]\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #0xf]\n\
	b _080F7402\n\
_080F73DE:\n\
	ldrb r0, [r2, #0xf]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r2, #0xf]\n\
_080F73E6:\n\
	mov r0, ip\n\
	adds r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov ip, r0\n\
_080F73F0:\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	ldrb r0, [r4, #8]\n\
	ldr r7, _080F7454 @ =u8_ARRAY_08386497\n\
	adds r0, r0, r7\n\
	ldrb r0, [r0]\n\
	cmp r6, r0\n\
	blo _080F73A4\n\
_080F7402:\n\
	mov r1, ip\n\
	mov r2, r8\n\
	subs r0, r1, r2\n\
	cmp r0, #5\n\
	bgt _080F7426\n\
	ldr r2, _080F7458 @ =0x00000DFC\n\
	add r2, sl\n\
	ldrb r1, [r2, #0xf]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F7426\n\
	ldrb r0, [r2, #6]\n\
	subs r0, #1\n\
	strb r0, [r2, #6]\n\
	mov r0, sl\n\
	bl FUN_080f70d8\n\
_080F7426:\n\
	ldr r2, _080F7458 @ =0x00000DFC\n\
	add r2, sl\n\
	ldrb r1, [r2, #9]\n\
	adds r0, r2, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xff\n\
	bne _080F7444\n\
	cmp r1, #0\n\
	beq _080F7444\n\
	ldrb r0, [r2, #6]\n\
	subs r0, #1\n\
	strb r0, [r2, #6]\n\
	ldrb r0, [r2, #9]\n\
	subs r0, #1\n\
	strb r0, [r2, #9]\n\
_080F7444:\n\
	add sp, #0xc\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F7454: .4byte u8_ARRAY_08386497\n\
_080F7458: .4byte 0x00000DFC\n\
 .syntax divided\n");
}

// エルフ名を6行分描画
static void printElfNames(struct GameState* g) {
  if (g->mode[3] > 1) {
    u16 i;
    for (i = 0; i < 6; i++) {
      if (((&MENU->elf)->displayed)[i] != ELF_NONE) {
        PrintString(STRING(((&MENU->elf)->displayed)[i] + 100), 2, 2 + (i * 2));
      }
    }

    if (((&MENU->elf)->displayed)[0] == ELF_NONE) {
      PrintString(STRING(174), 2, 2);
    }
  }
}

NAKED static void printElfMenuDescription(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	adds r7, r0, #0\n\
	ldr r1, _080F74EC @ =0x000064AC\n\
	adds r0, r7, r1\n\
	ldr r0, [r0]\n\
	mov sb, r0\n\
	ldrb r0, [r7, #3]\n\
	cmp r0, #2\n\
	beq _080F75B8\n\
	cmp r0, #2\n\
	bgt _080F74F0\n\
	cmp r0, #0\n\
	beq _080F74F6\n\
	b _080F7862\n\
	.align 2, 0\n\
_080F74EC: .4byte 0x000064AC\n\
_080F74F0:\n\
	cmp r0, #3\n\
	beq _080F75D0\n\
	b _080F7862\n\
_080F74F6:\n\
	ldr r0, _080F7514 @ =0x00000DFC\n\
	adds r2, r7, r0\n\
	ldrb r0, [r2, #7]\n\
	cmp r0, #0\n\
	bne _080F7554\n\
	mov r6, sb\n\
	adds r6, #0xb4\n\
	ldrb r0, [r6]\n\
	cmp r0, #0xff\n\
	bne _080F751C\n\
	ldr r0, _080F7518 @ =StringOfsTable\n\
	movs r1, #0xc3\n\
	lsls r1, r1, #1\n\
	b _080F762A\n\
	.align 2, 0\n\
_080F7514: .4byte 0x00000DFC\n\
_080F7518: .4byte StringOfsTable\n\
_080F751C:\n\
	ldr r5, _080F754C @ =StringOfsTable\n\
	ldrb r0, [r2, #7]\n\
	adds r0, #0xaf\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r5\n\
	ldrh r0, [r0]\n\
	ldr r4, _080F7550 @ =gStringData\n\
	adds r0, r0, r4\n\
	movs r1, #0x11\n\
	movs r2, #5\n\
	bl PrintString\n\
	ldrb r1, [r6]\n\
	adds r0, r7, #0\n\
	bl getElfDescStrID\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0xf\n\
	adds r0, r0, r5\n\
	ldrh r0, [r0]\n\
	adds r0, r0, r4\n\
	movs r1, #0x11\n\
	b _080F7834\n\
	.align 2, 0\n\
_080F754C: .4byte StringOfsTable\n\
_080F7550: .4byte gStringData\n\
_080F7554:\n\
	cmp r0, #1\n\
	bne _080F75A8\n\
	mov r6, sb\n\
	adds r6, #0xb4\n\
	ldrb r0, [r6, #1]\n\
	cmp r0, #0xff\n\
	bne _080F7570\n\
	ldr r0, _080F756C @ =StringOfsTable\n\
	movs r2, #0xc4\n\
	lsls r2, r2, #1\n\
	adds r0, r0, r2\n\
	b _080F762C\n\
	.align 2, 0\n\
_080F756C: .4byte StringOfsTable\n\
_080F7570:\n\
	ldr r5, _080F75A0 @ =StringOfsTable\n\
	ldrb r0, [r2, #7]\n\
	adds r0, #0xaf\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r5\n\
	ldrh r0, [r0]\n\
	ldr r4, _080F75A4 @ =gStringData\n\
	adds r0, r0, r4\n\
	movs r1, #0x11\n\
	movs r2, #5\n\
	bl PrintString\n\
	ldrb r1, [r6, #1]\n\
	adds r0, r7, #0\n\
	bl getElfDescStrID\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0xf\n\
	adds r0, r0, r5\n\
	ldrh r0, [r0]\n\
	adds r0, r0, r4\n\
	movs r1, #0x11\n\
	b _080F7834\n\
	.align 2, 0\n\
_080F75A0: .4byte StringOfsTable\n\
_080F75A4: .4byte gStringData\n\
_080F75A8:\n\
	ldr r1, _080F75B4 @ =StringOfsTable\n\
	ldrb r0, [r2, #7]\n\
	adds r0, #0xaf\n\
	lsls r0, r0, #1\n\
	b _080F762A\n\
	.align 2, 0\n\
_080F75B4: .4byte StringOfsTable\n\
_080F75B8:\n\
	ldr r1, _080F75C8 @ =StringOfsTable\n\
	ldr r2, _080F75CC @ =0x00000DFC\n\
	adds r0, r7, r2\n\
	ldrb r0, [r0, #8]\n\
	adds r0, #0xb5\n\
	lsls r0, r0, #1\n\
	b _080F762A\n\
	.align 2, 0\n\
_080F75C8: .4byte StringOfsTable\n\
_080F75CC: .4byte 0x00000DFC\n\
_080F75D0:\n\
	ldr r0, _080F75E0 @ =0x00000DFC\n\
	adds r2, r7, r0\n\
	ldrb r0, [r2]\n\
	cmp r0, #0xff\n\
	bne _080F75EC\n\
	ldr r0, _080F75E4 @ =StringOfsTable\n\
	ldr r1, _080F75E8 @ =0x00000252\n\
	b _080F762A\n\
	.align 2, 0\n\
_080F75E0: .4byte 0x00000DFC\n\
_080F75E4: .4byte StringOfsTable\n\
_080F75E8: .4byte 0x00000252\n\
_080F75EC:\n\
	ldrb r0, [r2, #9]\n\
	adds r0, r2, r0\n\
	ldrb r6, [r0]\n\
	ldrb r0, [r2, #7]\n\
	cmp r0, #4\n\
	bls _080F75FA\n\
	b _080F7862\n\
_080F75FA:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080F7604 @ =_080F7608\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080F7604: .4byte _080F7608\n\
_080F7608: @ jump table\n\
	.4byte _080F761C @ case 0\n\
	.4byte _080F761C @ case 1\n\
	.4byte _080F761C @ case 2\n\
	.4byte _080F7644 @ case 3\n\
	.4byte _080F7844 @ case 4\n\
_080F761C:\n\
	adds r0, r7, #0\n\
	adds r1, r6, #0\n\
	bl getElfDescStrID\n\
	ldr r1, _080F763C @ =StringOfsTable\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0xf\n\
_080F762A:\n\
	adds r0, r0, r1\n\
_080F762C:\n\
	ldrh r0, [r0]\n\
	ldr r1, _080F7640 @ =gStringData\n\
	adds r0, r0, r1\n\
	movs r1, #0x11\n\
	movs r2, #5\n\
	bl PrintString\n\
	b _080F7862\n\
	.align 2, 0\n\
_080F763C: .4byte StringOfsTable\n\
_080F7640: .4byte gStringData\n\
_080F7644:\n\
	ldr r2, _080F765C @ =0x00000E17\n\
	adds r0, r7, r2\n\
	ldrb r0, [r0]\n\
	subs r0, #1\n\
	cmp r0, #4\n\
	bls _080F7652\n\
	b _080F7862\n\
_080F7652:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080F7660 @ =_080F7664\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080F765C: .4byte 0x00000E17\n\
_080F7660: .4byte _080F7664\n\
_080F7664: @ jump table\n\
	.4byte _080F7678 @ case 0\n\
	.4byte _080F7738 @ case 1\n\
	.4byte _080F7862 @ case 2\n\
	.4byte _080F7678 @ case 3\n\
	.4byte _080F7678 @ case 4\n\
_080F7678:\n\
	ldr r1, _080F76A8 @ =gElfBreedInfo\n\
	lsls r0, r6, #2\n\
	adds r4, r0, r1\n\
	ldrb r1, [r4]\n\
	lsls r1, r1, #0x1d\n\
	ldr r0, _080F76AC @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	adds r0, r0, r6\n\
	ldr r0, [r0]\n\
	lsls r2, r0, #0x1b\n\
	lsrs r1, r1, #0x1d\n\
	lsrs r0, r2, #0x1e\n\
	cmp r1, r0\n\
	beq _080F76B4\n\
	ldr r3, _080F76B0 @ =u16_ARRAY_08371afc\n\
	adds r1, r0, #0\n\
	adds r1, #1\n\
	ldrb r2, [r4, #3]\n\
	lsls r0, r2, #1\n\
	adds r0, r0, r2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r3\n\
	b _080F76C0\n\
	.align 2, 0\n\
_080F76A8: .4byte gElfBreedInfo\n\
_080F76AC: .4byte gUnlockedElfPtr\n\
_080F76B0: .4byte u16_ARRAY_08371afc\n\
_080F76B4:\n\
	ldr r2, _080F772C @ =u16_ARRAY_08371afc\n\
	ldrb r1, [r4, #3]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
_080F76C0:\n\
	ldrh r0, [r0]\n\
	mov r8, r0\n\
	ldr r5, _080F7730 @ =StringOfsTable\n\
	movs r1, #0xbb\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	ldrh r0, [r0]\n\
	ldr r4, _080F7734 @ =gStringData\n\
	adds r0, r0, r4\n\
	movs r1, #0x11\n\
	movs r2, #5\n\
	bl PrintString\n\
	mov r0, r8\n\
	movs r1, #0x14\n\
	movs r2, #7\n\
	bl PrintNumber\n\
	ldrh r0, [r5, #0xc]\n\
	adds r0, r0, r4\n\
	movs r1, #0x15\n\
	movs r2, #7\n\
	bl PrintString\n\
	mov r0, sb\n\
	adds r0, #0xb4\n\
	ldrh r0, [r0, #6]\n\
	movs r1, #0x1a\n\
	movs r2, #7\n\
	bl PrintNumber\n\
	movs r2, #0xc2\n\
	lsls r2, r2, #1\n\
	adds r0, r5, r2\n\
	ldrh r0, [r0]\n\
	adds r0, r0, r4\n\
	movs r1, #0x1b\n\
	movs r2, #7\n\
	bl PrintString\n\
	adds r0, r7, #0\n\
	adds r1, r6, #0\n\
	bl getElfDescStrID\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0xf\n\
	adds r0, r0, r5\n\
	ldrh r0, [r0]\n\
	adds r0, r0, r4\n\
	movs r1, #0x11\n\
	movs r2, #9\n\
	bl PrintString\n\
	b _080F7862\n\
	.align 2, 0\n\
_080F772C: .4byte u16_ARRAY_08371afc\n\
_080F7730: .4byte StringOfsTable\n\
_080F7734: .4byte gStringData\n\
_080F7738:\n\
	ldr r1, _080F7774 @ =gElfBreedInfo\n\
	lsls r0, r6, #2\n\
	adds r4, r0, r1\n\
	ldrb r3, [r4]\n\
	lsls r1, r3, #0x1d\n\
	ldr r0, _080F7778 @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	adds r5, r0, r6\n\
	ldr r0, [r5]\n\
	lsls r2, r0, #0x1b\n\
	lsrs r1, r1, #0x1d\n\
	lsrs r0, r2, #0x1e\n\
	cmp r1, r0\n\
	beq _080F7784\n\
	ldr r3, _080F777C @ =u16_ARRAY_08371afc\n\
	adds r1, r0, #0\n\
	adds r1, #1\n\
	ldrb r2, [r4, #3]\n\
	lsls r0, r2, #1\n\
	adds r0, r0, r2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r3\n\
	ldrh r0, [r0]\n\
	mov r8, r0\n\
	ldr r0, _080F7780 @ =StringOfsTable\n\
	movs r1, #0xbc\n\
	lsls r1, r1, #1\n\
	b _080F77BE\n\
	.align 2, 0\n\
_080F7774: .4byte gElfBreedInfo\n\
_080F7778: .4byte gUnlockedElfPtr\n\
_080F777C: .4byte u16_ARRAY_08371afc\n\
_080F7780: .4byte StringOfsTable\n\
_080F7784:\n\
	ldr r2, _080F77B0 @ =u16_ARRAY_08371afc\n\
	ldrb r1, [r4, #3]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrh r0, [r0]\n\
	mov r8, r0\n\
	lsls r0, r3, #0x1a\n\
	lsrs r0, r0, #0x1d\n\
	cmp r0, #1\n\
	bne _080F77D8\n\
	ldrb r1, [r5]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F77B8\n\
	ldr r0, _080F77B4 @ =StringOfsTable\n\
	movs r2, #0xbe\n\
	lsls r2, r2, #1\n\
	adds r0, r0, r2\n\
	b _080F77C0\n\
	.align 2, 0\n\
_080F77B0: .4byte u16_ARRAY_08371afc\n\
_080F77B4: .4byte StringOfsTable\n\
_080F77B8:\n\
	ldr r0, _080F77D0 @ =StringOfsTable\n\
	movs r1, #0xbd\n\
	lsls r1, r1, #1\n\
_080F77BE:\n\
	adds r0, r0, r1\n\
_080F77C0:\n\
	ldrh r0, [r0]\n\
	ldr r1, _080F77D4 @ =gStringData\n\
	adds r0, r0, r1\n\
	movs r1, #0x11\n\
	movs r2, #9\n\
	bl PrintString\n\
	b _080F77EE\n\
	.align 2, 0\n\
_080F77D0: .4byte StringOfsTable\n\
_080F77D4: .4byte gStringData\n\
_080F77D8:\n\
	ldr r0, _080F783C @ =StringOfsTable\n\
	movs r2, #0xbf\n\
	lsls r2, r2, #1\n\
	adds r0, r0, r2\n\
	ldrh r0, [r0]\n\
	ldr r1, _080F7840 @ =gStringData\n\
	adds r0, r0, r1\n\
	movs r1, #0x11\n\
	movs r2, #9\n\
	bl PrintString\n\
_080F77EE:\n\
	ldr r5, _080F783C @ =StringOfsTable\n\
	movs r1, #0xbb\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	ldrh r0, [r0]\n\
	ldr r4, _080F7840 @ =gStringData\n\
	adds r0, r0, r4\n\
	movs r1, #0x11\n\
	movs r2, #5\n\
	bl PrintString\n\
	mov r0, r8\n\
	movs r1, #0x14\n\
	movs r2, #7\n\
	bl PrintNumber\n\
	ldrh r0, [r5, #0xc]\n\
	adds r0, r0, r4\n\
	movs r1, #0x15\n\
	movs r2, #7\n\
	bl PrintString\n\
	mov r0, sb\n\
	adds r0, #0xb4\n\
	ldrh r0, [r0, #6]\n\
	movs r1, #0x1a\n\
	movs r2, #7\n\
	bl PrintNumber\n\
	movs r2, #0xc2\n\
	lsls r2, r2, #1\n\
	adds r0, r5, r2\n\
	ldrh r0, [r0]\n\
	adds r0, r0, r4\n\
	movs r1, #0x1b\n\
_080F7834:\n\
	movs r2, #7\n\
	bl PrintString\n\
	b _080F7862\n\
	.align 2, 0\n\
_080F783C: .4byte StringOfsTable\n\
_080F7840: .4byte gStringData\n\
_080F7844:\n\
	adds r0, r7, #0\n\
	adds r1, r6, #0\n\
	bl getElfDescStrID\n\
	ldr r1, _080F7870 @ =StringOfsTable\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0xf\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	ldr r1, _080F7874 @ =gStringData\n\
	adds r0, r0, r1\n\
	movs r1, #0x11\n\
	movs r2, #5\n\
	bl PrintString\n\
_080F7862:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F7870: .4byte StringOfsTable\n\
_080F7874: .4byte gStringData\n\
 .syntax divided\n");
}

NAKED static void printElfMenuBottomString(struct GameState* g) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r1, _080F7894 @ =0x000064AC\n\
	adds r0, r2, r1\n\
	ldr r0, [r0]\n\
	movs r3, #0\n\
	ldrb r1, [r2, #3]\n\
	cmp r1, #2\n\
	beq _080F78AA\n\
	cmp r1, #2\n\
	bgt _080F7898\n\
	cmp r1, #0\n\
	beq _080F789E\n\
	b _080F78FC\n\
	.align 2, 0\n\
_080F7894: .4byte 0x000064AC\n\
_080F7898:\n\
	cmp r1, #3\n\
	beq _080F78AE\n\
	b _080F78FC\n\
_080F789E:\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0x1a]\n\
	cmp r0, #1\n\
	beq _080F78FC\n\
	movs r3, #0xb4\n\
	b _080F7900\n\
_080F78AA:\n\
	movs r3, #0xb8\n\
	b _080F7900\n\
_080F78AE:\n\
	ldr r1, _080F78C4 @ =0x00000DFC\n\
	adds r0, r2, r1\n\
	ldrb r0, [r0, #7]\n\
	cmp r0, #4\n\
	bhi _080F78FC\n\
	lsls r0, r0, #2\n\
	ldr r1, _080F78C8 @ =_080F78CC\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080F78C4: .4byte 0x00000DFC\n\
_080F78C8: .4byte _080F78CC\n\
_080F78CC: @ jump table\n\
	.4byte _080F78E0 @ case 0\n\
	.4byte _080F78E0 @ case 1\n\
	.4byte _080F78E4 @ case 2\n\
	.4byte _080F78E8 @ case 3\n\
	.4byte _080F78FC @ case 4\n\
_080F78E0:\n\
	movs r3, #0xb9\n\
	b _080F7900\n\
_080F78E4:\n\
	movs r3, #0xba\n\
	b _080F7900\n\
_080F78E8:\n\
	ldr r1, _080F7918 @ =0x00000E17\n\
	adds r0, r2, r1\n\
	ldrb r0, [r0]\n\
	movs r3, #0xc5\n\
	cmp r0, #4\n\
	beq _080F7900\n\
	movs r3, #0xc0\n\
	cmp r0, #5\n\
	bne _080F78FC\n\
	movs r3, #0xc6\n\
_080F78FC:\n\
	cmp r3, #0\n\
	beq _080F7914\n\
_080F7900:\n\
	ldr r1, _080F791C @ =StringOfsTable\n\
	lsls r0, r3, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	ldr r1, _080F7920 @ =gStringData\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	movs r2, #0x12\n\
	bl PrintString\n\
_080F7914:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F7918: .4byte 0x00000E17\n\
_080F791C: .4byte StringOfsTable\n\
_080F7920: .4byte gStringData\n\
 .syntax divided\n");
}

NAKED static str_id_t getElfDescStrID(struct GameState* g, u8 r1) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	lsls r1, r1, #0x18\n\
	lsrs r4, r1, #0x18\n\
	ldr r1, _080F7970 @ =0x000064AC\n\
	adds r0, r0, r1\n\
	ldr r2, [r0]\n\
	ldr r0, _080F7974 @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	adds r0, r0, r4\n\
	ldrb r1, [r0]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F7996\n\
	adds r0, r2, #0\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0x1a]\n\
	cmp r0, #2\n\
	bne _080F7980\n\
	adds r0, r4, #0\n\
	bl FUN_080e1cac\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080F7996\n\
	ldr r0, _080F7978 @ =StringOfsTable\n\
	movs r1, #0xbb\n\
	lsls r1, r1, #2\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	ldr r1, _080F797C @ =gStringData\n\
	adds r0, r0, r1\n\
	movs r1, #0x11\n\
	movs r2, #0xd\n\
	bl PrintString\n\
	b _080F7996\n\
	.align 2, 0\n\
_080F7970: .4byte 0x000064AC\n\
_080F7974: .4byte gUnlockedElfPtr\n\
_080F7978: .4byte StringOfsTable\n\
_080F797C: .4byte gStringData\n\
_080F7980:\n\
	ldr r0, _080F79C0 @ =StringOfsTable\n\
	movs r1, #0xbb\n\
	lsls r1, r1, #2\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	ldr r1, _080F79C4 @ =gStringData\n\
	adds r0, r0, r1\n\
	movs r1, #0x11\n\
	movs r2, #0xd\n\
	bl PrintString\n\
_080F7996:\n\
	ldr r0, _080F79C8 @ =gElfBreedInfo\n\
	lsls r1, r4, #2\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1]\n\
	lsls r0, r0, #0x1a\n\
	lsrs r0, r0, #0x1d\n\
	cmp r0, #2\n\
	bne _080F79E0\n\
	ldr r0, _080F79CC @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	adds r0, r0, r4\n\
	ldrb r1, [r0]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F79E0\n\
	cmp r4, #0x1a\n\
	bhi _080F79D4\n\
	ldr r1, _080F79D0 @ =0x0000010B\n\
	adds r0, r4, r1\n\
	b _080F79E4\n\
	.align 2, 0\n\
_080F79C0: .4byte StringOfsTable\n\
_080F79C4: .4byte gStringData\n\
_080F79C8: .4byte gElfBreedInfo\n\
_080F79CC: .4byte gUnlockedElfPtr\n\
_080F79D0: .4byte 0x0000010B\n\
_080F79D4:\n\
	cmp r4, #0x27\n\
	bhi _080F79E0\n\
	movs r1, #0x81\n\
	lsls r1, r1, #1\n\
	adds r0, r4, r1\n\
	b _080F79E4\n\
_080F79E0:\n\
	adds r0, r4, #0\n\
	adds r0, #0xc8\n\
_080F79E4:\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}
