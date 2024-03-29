#include "boss.h"
#include "collision.h"
#include "global.h"
#include "overworld.h"

void PantheonAquaMod_Init(struct Boss* p);
void PantheonAquaMod_Update(struct Boss* p);
void PantheonAquaMod_Die(struct Boss* p);

// clang-format off
const BossRoutine gPantheonAquaModRoutine = {
    [ENTITY_INIT] =      PantheonAquaMod_Init,
    [ENTITY_UPDATE] =    PantheonAquaMod_Update,
    [ENTITY_DIE] =       PantheonAquaMod_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

static void onCollision(struct Body* body UNUSED, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) { return; }

bool8 tryKillPantheonAquaMod(struct Boss* p) {
  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_FAIL)) {
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    (p->s).mode[1] = 0;
    PantheonAquaMod_Die(p);
    return TRUE;
  }
  return FALSE;
}

static void paquam_080512f8(struct Boss* p) {
  (p->props.paquam).x += PIXEL(1);
  (p->s).coord.y = (p->props.paquam).y;
  (p->s).coord.y += gSineTable[COORD_TO_PIXEL((p->props.paquam).x)] << 2;
}

INCASM("asm/boss/pantheon_aqua_mod.inc");

void nop_08051620(struct Boss* p);

// clang-format off
static const BossFunc sUpdates1[9] = {
    nop_08051620,
    nop_08051620,
    nop_08051620,
    nop_08051620,
    nop_08051620,
    nop_08051620,
    nop_08051620,
    nop_08051620,
    nop_08051620,
};
// clang-format on

void paquamNeutral(struct Boss* p);
void paquam_080517ac(struct Boss* p);
void paquam_080519d0(struct Boss* p);
void paquam_08051b8c(struct Boss* p);
void FUN_08051cdc(struct Boss* p);
void paquamSweepLaser(struct Boss* p);
void paquam_08051f44(struct Boss* p);
void paquqmRubble(struct Boss* p);
void paqua_mod_08052240(struct Boss* p);

// clang-format off
static const BossFunc sUpdates2[9] = {
    paquamNeutral,
    paquam_080517ac,
    paquam_080519d0,
    paquam_08051b8c,
    FUN_08051cdc,
    paquamSweepLaser,
    paquam_08051f44,
    paquqmRubble,
    paqua_mod_08052240,
};
// clang-format on

// --------------------------------------------

void FUN_080523b8(struct Boss* p);

static const BossFunc sDeads[1] = {
    FUN_080523b8,
};

// --------------------------------------------

static const struct Collision sCollisions[32] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(45), PIXEL(15)},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(35)},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 255,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(27), PIXEL(7), PIXEL(18), PIXEL(18)},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 255,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(27), PIXEL(7), PIXEL(18), PIXEL(18)},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(14), PIXEL(12), PIXEL(12)},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(45), PIXEL(15)},
    },
    [7] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(35)},
    },
    [8] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(14), PIXEL(12), PIXEL(12)},
    },
    [9] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(45), PIXEL(15)},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(35)},
    },
    [11] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 255,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(27), PIXEL(7), PIXEL(18), PIXEL(18)},
    },
    [12] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(14), PIXEL(12), PIXEL(12)},
    },
    [13] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(45), PIXEL(15)},
    },
    [14] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(35)},
    },
    [15] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 255,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(27), PIXEL(7), PIXEL(18), PIXEL(18)},
    },
    [16] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(14), PIXEL(12), PIXEL(12)},
    },
    [17] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(45), PIXEL(15)},
    },
    [18] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(35)},
    },
    [19] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 255,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(30), -PIXEL(15), PIXEL(18), PIXEL(18)},
    },
    [20] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 255,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(27), PIXEL(7), PIXEL(18), PIXEL(18)},
    },
    [21] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(14), PIXEL(12), PIXEL(12)},
    },
    [22] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(45), PIXEL(15)},
    },
    [23] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(35)},
    },
    [24] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 255,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(27), PIXEL(7), PIXEL(18), PIXEL(18)},
    },
    [25] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 255,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(30), -PIXEL(15), PIXEL(18), PIXEL(18)},
    },
    [26] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(14), PIXEL(12), PIXEL(12)},
    },
    [27] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(45), PIXEL(15)},
    },
    [28] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(35)},
    },
    [29] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 255,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(10), PIXEL(7), PIXEL(18), PIXEL(18)},
    },
    [30] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 255,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(10), PIXEL(7), PIXEL(18), PIXEL(18)},
    },
    [31] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(14), PIXEL(12), PIXEL(12)},
    },
};

// --------------------------------------------

static const u8 sInitModes[4] = {1, 4, 0, 0};
static const struct Coord sElementCoord = {PIXEL(0), PIXEL(0)};
static const u8 u8_ARRAY_08363958[4] = {5, 6, 7, 8};
