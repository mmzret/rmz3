#include "collision.h"
#include "entity.h"
#include "game.h"
#include "global.h"
#include "solid.h"
#include "story.h"
#include "text.h"

static void MainNPC_Init(struct Solid* p);
static void MainNPC_Update(struct Solid* p);
static void MainNPC_Die(struct Solid* p);

// clang-format off
/*
  xx nn nn nn
  work[0]:
    0: ??
    1: Ciel
    2: Cerveau
    3: Hazard Colbor (until Player go to cerveru room for the first time)
    4: Search console at Sunken Library
    5: ?? (『メンテナンス・ルーム』という文字列を表示している ゼロ2の名残？)
*/
const SolidRoutine gMainNPCRoutine = {
    [ENTITY_INIT] =      MainNPC_Init,
    [ENTITY_UPDATE] =    MainNPC_Update,
    [ENTITY_DIE] =       MainNPC_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

static void initMainNPC(struct Solid* p);

static void MainNPC_Init(struct Solid* p) {
  // clang-format off
  static SolidFunc const sInitializers[] = {
    initMainNPC,
    initMainNPC,
    initMainNPC,
    initMainNPC,
    initMainNPC,
    initMainNPC,
  };
  // clang-format on
  (sInitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

static void FUN_080daee8(struct Solid* p);
static void UpdateCiel(struct Solid* p);
void UpdateCerveau(struct Solid* p);
void UpdateBlockingColbor(struct Solid* p);
static void UpdateSearchConsole(Object* p);
static void FUN_080db930(Object* p);

static void MainNPC_Update(struct Solid* p) {
  // clang-format off
  static SolidFunc const sUpdates[] = {
    (SolidFunc)FUN_080daee8,
    (SolidFunc)UpdateCiel,
    (SolidFunc)UpdateCerveau,
    (SolidFunc)UpdateBlockingColbor,
    (SolidFunc)UpdateSearchConsole,
    (SolidFunc)FUN_080db930,
  };
  // clang-format on
  (sUpdates[(p->s).work[0]])(p);
}

// --------------------------------------------

static void deleteMainNPC(struct Solid* p);

void MainNPC_Die(struct Solid* p) {
  // clang-format off
    static SolidFunc const sDeinitializers[] = {
    deleteMainNPC,
    deleteMainNPC,
    deleteMainNPC,
    deleteMainNPC,
    deleteMainNPC,
    deleteMainNPC,
  };
  // clang-format on
  (sDeinitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

static void initMainNPC(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  MainNPC_Update(p);
}

static void FUN_080daee8(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_DIE);
  MainNPC_Die(p);
}

static void deleteMainNPC(struct Solid* p) {
  (p->s).flags &= ~DISPLAY;
  EXIT_BODY(p);
  (p->s).flags2 &= ~ENTI_PHYSICS;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

NAKED static void UpdateCiel(struct Solid* p) { INCCODE("asm/wip/UpdateCiel.inc"); }

INCASM("asm/solid/main_npc.inc");

const struct Collision Collision_ARRAY_08371380[2] = {
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CHATABLE,
      damage : 255,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(32), PIXEL(0), PIXEL(16), PIXEL(1)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : CHATABLE,
      damage : 255,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};

const struct Collision Collision_ARRAY_083713b0[2] = {
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CHATABLE,
      damage : 255,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(32), PIXEL(0), PIXEL(16), PIXEL(1)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : CHATABLE,
      damage : 255,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};

const struct Collision Collision_ARRAY_083713e0[2] = {
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CHATABLE,
      damage : 255,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(80), PIXEL(1)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : CHATABLE,
      damage : 255,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};

// --------------------------------------------

static const struct Collision Collision_ARRAY_08371410[2] = {
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CHATABLE,
      damage : 255,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(24), PIXEL(1)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : CHATABLE,
      damage : 255,
      LAYER(0xFFFFFFFF),
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};

static void UpdateSearchConsole(Object* p) {
  switch (p->mode[1]) {
    case 0: {
      p->flags |= FLIPABLE;
      INIT_BODY(p, Collision_ARRAY_08371410, 64, NULL);
      p->coord.y = FUN_08009f6c(p->coord.x, p->coord.y);
      p->mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      if (((p->body).status & BODY_STATUS_CHAT) && gInChat && (gCollisionManager.talkTo == &p->body)) {
        PlaySound(SE_ARCADIA_RINGTONE);
        SetGameMode(&gGameState, GAMEMODE(MAINGAME, OVERWORLD, 7, 0));
        p->mode[1]++;
      }
      break;
    }
    case 2: {
      if (gGameState.mode[2] != 0) {
        return;
      }
      gInChat = FALSE;
      p->mode[1] = 1;
      break;
    }
    default: {
      break;
    }
  }
}

static void FUN_080db930(Object* p) {
  switch (p->mode[1]) {
    case 0: {
      if (FLAG(gCurStory.s.gameflags, FLAG_LATER4_DONE) || !FLAG(gCurStory.s.gameflags, FLAG_MISSILE_DONE)) {
        p->flags &= ~DISPLAY;
        p->flags &= ~FLIPABLE;
        EXIT_BODY(p);
        SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
        break;
      }
      p->flags |= FLIPABLE;
      INIT_BODY(p, Collision_ARRAY_08371410, 64, NULL);
      p->coord.x += PIXEL(8);
      p->coord.y = FUN_08009f6c(p->coord.x, p->coord.y);
      p->mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      if (((p->body).status & BODY_STATUS_CHAT) && gInChat && (gCollisionManager.talkTo == &p->body)) {
        PrintNormalMessage(0x1333);  // メンテナンス・ルーム 使用中…
        p->mode[1]++;
      }
      break;
    }
    case 2: {
      if ((&gTextWindow.text)->mode != 0) {
        return;
      }
      gInChat = FALSE;
      p->mode[1] = 1;
      break;
    }
    default: {
      break;
    }
  }
}
