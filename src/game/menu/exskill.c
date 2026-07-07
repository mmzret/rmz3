#include "game.h"
#include "gfx.h"
#include "global.h"
#include "menu.h"
#include "palette_animation.h"
#include "text.h"
#include "widget/cursor_square.h"
#include "widget/exskill_icons.h"

extern const struct Graphic gGraphic_ExSkillMenu;
extern const struct Palette gPalette_ExSkillMenu;

static void ExMenuLoop_Init(struct GameState* g);
static void ExMenuLoop_Update(struct GameState* g);
static void ExMenuLoop_SlideOut(struct GameState* g);
static void ExMenuLoop_Exit(struct GameState* g);

// 01 02 xx xx (BYTE[0x02031978] = 1)

// ------------------------------------------------------------------------------------------------------------------------------------

void EachMenuLoop_ExSkill(struct GameState* g) {
  static const MenuLoopFunc ExSkillMenuLoops[4] = {
      ExMenuLoop_Init,
      ExMenuLoop_Update,
      ExMenuLoop_SlideOut,
      ExMenuLoop_Exit,
  };  // 0x0838649c
  (ExSkillMenuLoops[g->mode[2]])(g);
}

// 0x080f7a04
static void ExMenuLoop_Init(struct GameState* g) {
  u8 i;
  Player* z = g->z2;
  struct ExSkillMenuState* exskill = &((g->sceneState).menu).exskill;
  exskill->selected = 0;
  exskill->inactive = FALSE;
  LoadGraphic(&gGraphic_ExSkillMenu, (void*)CHAR_BASE(1));
  LoadPalette(&gPalette_ExSkillMenu, 0);
  CpuFastCopy(BGMAP(BG_EXSKILL_MENU), g->menuBgMap2, 960 * 2);
  RequestBgMapTransfer(g->menuBgMap1, (void*)SCREEN_BASE(1), 0x1000);
  StartPaletteAnimation(62, 0);
  StartPaletteAnimation(63, 0);
  exskill->cursor = (struct SquareCursorWidget*)CreateSquareCursor(g, TRUE, 0);
  (exskill->cursor)->px = 284;
  (exskill->cursor)->py = 40;
  LOAD_STATIC_GRAPHIC(SM069_EXSKILL_ICON);
  for (i = 0; i < 12; i++) {
    u16 exskill = ((&z->unk_b4)->status).unlockedExSkill;
    if ((exskill & (1 << i)) >> i) CreateExSkillIcon(g, i);
  }
  g->mode[2] = 2;
}

NON_MATCH static void ExMenuLoop_Update(struct GameState* g) {
#if MODERN
  struct Zero* z = g->z2;
  if (!TrySlideMenu(g)) {
    u8 prev;
    StepPaletteAnimation(62);
    StepPaletteAnimation(63);
    prev = EXSKILL_MENU->selected;
    if (gJoypad[0].field3_0x6 & DPAD_UP) {
      EXSKILL_MENU->selected = (EXSKILL_MENU->selected + 8) % 12;  // -4
    }
    if (gJoypad[0].field3_0x6 & DPAD_DOWN) {
      EXSKILL_MENU->selected = (EXSKILL_MENU->selected + 4) % 12;  // 1行にEXSKILLアイコンは4つ
    }
    if (gJoypad[0].field3_0x6 & DPAD_LEFT) {
      s32 selected = EXSKILL_MENU->selected;
      EXSKILL_MENU->selected = (((u32)selected >> 2) << 2) + ((selected + 3) % 4);  // -1
    }
    if (gJoypad[0].field3_0x6 & DPAD_RIGHT) {
      s32 selected = EXSKILL_MENU->selected;
      EXSKILL_MENU->selected = (((u32)selected >> 2) << 2) + ((selected + 1) % 4);  // +1
    }
    if (prev != EXSKILL_MENU->selected) PlaySound(SE_CURSOR);
    if (gJoypad[0].pressed & A_BUTTON) {
      if ((((&z->unk_b4)->status).unlockedExSkill & (1 << EXSKILL_MENU->selected)) >> EXSKILL_MENU->selected) {
        if (((&z->unk_b4)->status).exSkill & (1 << EXSKILL_MENU->selected)) {
          ((&z->unk_b4)->status).exSkill ^= (1 << EXSKILL_MENU->selected);
          PlaySound(SE_NO);
        } else {
          ((&z->unk_b4)->status).exSkill |= (1 << EXSKILL_MENU->selected);
          PlaySound(SE_YES);
        }
      } else {
        PlaySound(SE_NOT_ALLOWED);
      }
    }
    (EXSKILL_MENU->cursor)->px = (EXSKILL_MENU->selected & 3) * 24 + 256 + 28;
    (EXSKILL_MENU->cursor)->py = (EXSKILL_MENU->selected >> 2) * 24 + 40;

    if ((((&z->unk_b4)->status).unlockedExSkill & (1 << EXSKILL_MENU->selected)) >> EXSKILL_MENU->selected) {
      PrintString(STRING(450 + EXSKILL_MENU->selected), 2, 14);
      PrintString(STRING(463 + EXSKILL_MENU->selected), 17, 1);
    } else {
      PrintString(STRING(462), 2, 14);
      PrintString(STRING(475), 17, 1);
    }
  }
#else
  INCCODE("asm/wip/ExMenuLoop_Update.inc");
#endif
}

static void ExMenuLoop_SlideOut(struct GameState* g) {
  if ((&(g->sceneState).menu)->unk_4d == 2) {
    BGOFS(1)->x += 16;
  } else {
    BGOFS(1)->x -= 16;
  }
  BGOFS(1)->x &= 0x1FF;
  if ((BGOFS(1)->x & 0xFF) == 0) {
    (&(g->sceneState).menu)->unk_4c = (&(g->sceneState).menu)->unk_4d;
    g->mode[2] = 1;
    ExMenuLoop_Exit(g);
  }
}

static void ExMenuLoop_Exit(struct GameState* g) {
  EXSKILL_MENU->inactive = TRUE;
  RemovePaletteAnimation(62);
  RemovePaletteAnimation(63);
  (EXSKILL_MENU->cursor)->dead = TRUE;
}
