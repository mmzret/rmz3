#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

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
    [ENTITY_MAIN] =      MainNPC_Update,
    [ENTITY_DIE] =       MainNPC_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
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
void UpdateSearchConsole(struct Solid* p);
void FUN_080db930(struct Solid* p);

static void MainNPC_Update(struct Solid* p) {
  // clang-format off
  static SolidFunc const sUpdates[] = {
    FUN_080daee8,
    UpdateCiel,
    UpdateCerveau,
    UpdateBlockingColbor,
    UpdateSearchConsole,
    FUN_080db930,
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
  SET_SOLID_ROUTINE(p, ENTITY_MAIN);
  MainNPC_Update(p);
}

static void FUN_080daee8(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_DIE);
  MainNPC_Die(p);
}

static void deleteMainNPC(struct Solid* p) {
  (p->s).flags &= ~DISPLAY;
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~COLLIDABLE;
  (p->s).flags2 &= ~ENTITY_HAZARD;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

NAKED static void UpdateCiel(struct Solid* p) { INCCODE("asm/wip/UpdateCiel.inc"); }

INCASM("asm/solid/main_npc.inc");

const struct Collision Collision_ARRAY_08371380[2] = {
    {
      kind : DDP,
      layer : 2,
      special : CHATABLE,
      damage : 255,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {-PIXEL(32), PIXEL(0), PIXEL(16), PIXEL(1)},
    },
    {
      kind : DRP,
      layer : 2,
      special : CHATABLE,
      damage : 255,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};

const struct Collision Collision_ARRAY_083713b0[2] = {
    {
      kind : DDP,
      layer : 2,
      special : CHATABLE,
      damage : 255,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(32), PIXEL(0), PIXEL(16), PIXEL(1)},
    },
    {
      kind : DRP,
      layer : 2,
      special : CHATABLE,
      damage : 255,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};

const struct Collision Collision_ARRAY_083713e0[2] = {
    {
      kind : DDP,
      layer : 2,
      special : CHATABLE,
      damage : 255,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(80), PIXEL(1)},
    },
    {
      kind : DRP,
      layer : 2,
      special : CHATABLE,
      damage : 255,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};

const struct Collision Collision_ARRAY_08371410[2] = {
    {
      kind : DDP,
      layer : 2,
      special : CHATABLE,
      damage : 255,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(24), PIXEL(1)},
    },
    {
      kind : DRP,
      layer : 2,
      special : CHATABLE,
      damage : 255,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};
