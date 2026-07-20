#include "anim_loader.h"
#include "collision.h"
#include "game.h"
#include "gfx.h"
#include "global.h"
#include "palette_animation.h"
#include "solid.h"

static void CielComputer_Init(struct Solid* p);
static void CielComputer_Update(struct Solid* p);
static void CielComputer_Die(Object* p);

// clang-format off
const SolidRoutine gCielComputerRoutine = {
    [ENTITY_INIT] =      (void*)CielComputer_Init,
    [ENTITY_UPDATE] =    (void*)CielComputer_Update,
    [ENTITY_DIE] =       (void*)CielComputer_Die,
    [ENTITY_DISAPPEAR] = (void*)CielComputer_Die,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

// 0x08371838
static const motion_t sMotions[5] = {
    MOTION(SM144_CIEL_COMP_0, 0), MOTION(SM145_CIEL_COMP_1, 0), MOTION(SM146_CIEL_COMP_2, 0), MOTION(SM147_CIEL_COMP_3, 0), MOTION(SM148_CIEL_COMP_4, 0),
};

static void CielComputer_Init(struct Solid* p) {
  static const struct Collision sCollisions[] = {
      {
        kind : DDP,
        faction : FACTION_NEUTRAL,
        special : CHATABLE,
        damage : 0xFF,
        layer : 0x00000001,
        range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(1)},
      },
      {
        kind : DRP,
        faction : FACTION_NEUTRAL,
        special : CHATABLE,
        damage : 0xFF,
        LAYER(0xFFFFFFFF),
        remaining : 0,
        range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
      },
  };  // 0x08371844

  motion_id_t id;
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  EnableSpriteAnimation_Normal(p);
  SET_XFLIP(p, FALSE);
  SetSpriteAnimation(p, sMotions[gSystemSavedata.cielComputer]);
  id = sMotions[gSystemSavedata.cielComputer] >> 8;
  LOAD_STATIC_GRAPHIC(id);
  INIT_BODY(p, sCollisions, 0, NULL);
  (p->s).coord.x += PIXEL(8);
  (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y) + 1;
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  CielComputer_Update((void*)p);
}

u8 GetEntityPalID(struct Entity* p);

static void CielComputer_Update(struct Solid* p) {
  UpdateSpriteAnimation(p);
  switch ((p->s).mode[1]) {
    case 0:
      if (!((p->body).status & BODY_STATUS_CHAT)) {
        return;
      }
      if (gInChat == 0) {
        return;
      }
      if (gCollisionManager.talkTo != &p->body) {
        return;
      }
      if (gSystemSavedata.cielComputer <= 3) {
        SetSpriteAnimation(p, sMotions[gSystemSavedata.cielComputer] | 1);
        if (gSystemSavedata.cielComputer == 3) {
          StartPaletteAnimation(241, ((u8)GetEntityPalID(&p->s) << 5) | 0x200);
        }
      }
      if (gSystemSavedata.cielComputer == 4) {
        StartPaletteAnimation(242, ((u8)GetEntityPalID(&p->s) << 5) | 0x200);
      }
      PlaySound(0x12A);
      SetGameMode(&gGameState, 0x00060400);
      (p->s).mode[1]++;
      break;
    case 1:
      StepPaletteAnimation(241);
      StepPaletteAnimation(242);
      if (gGameState.mode[2] == 0) {
        RemovePaletteAnimation(241);
        RemovePaletteAnimation(242);
        if (gSystemSavedata.cielComputer > 2) {
          motion_id_t id = sMotions[gSystemSavedata.cielComputer] >> 8;
          REQUEST_STATIC_GRAPHIC(id);
        }
        SetSpriteAnimation(p, sMotions[gSystemSavedata.cielComputer]);
        gInChat = 0;
        (p->s).mode[1] = 0;
      }
      break;
  }
}

static void CielComputer_Die(Object* p) { DeleteSolid(p); }
