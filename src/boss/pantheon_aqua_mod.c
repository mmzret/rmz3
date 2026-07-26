#include "boss.h"
#include "collision.h"
#include "global.h"
#include "overworld.h"

static const BossFunc sDeads[1];
static const BossFunc sUpdates1[9];
static const BossFunc sUpdates2[9];

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4[6];          // 0xB4
  u16 x;                 // 0xBA
  s32 y;                 // 0xBC
  u8 unk_c0[36];         // 0xC0
} PAquaMod;
static_assert(sizeof(PAquaMod) == sizeof(struct Boss));

void PantheonAquaMod_Init(PAquaMod* p);
void PantheonAquaMod_Update(PAquaMod* p);
void PantheonAquaMod_Die(PAquaMod* p);

// clang-format off
const BossRoutine gPantheonAquaModRoutine = {
    [ENTITY_INIT] =      (void*)PantheonAquaMod_Init,
    [ENTITY_UPDATE] =    (void*)PantheonAquaMod_Update,
    [ENTITY_DIE] =       (void*)PantheonAquaMod_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) { return; }

bool8 tryKillPantheonAquaMod(PAquaMod* p) {
  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_PLAYER_DEAD)) {
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    p->mode[1] = 0;
    PantheonAquaMod_Die(p);
    return TRUE;
  }
  return FALSE;
}

static void paquam_080512f8(PAquaMod* p) {
  p->x += PIXEL(1);
  (p->coord).y = p->y;
  (p->coord).y += gSineTable[COORD_TO_PIXEL(p->x)] << 2;
}

INCASM("asm/boss/pantheon_aqua_mod_a.inc");

void PantheonAquaMod_Update(PAquaMod* p) {
  struct Entity** slot = (struct Entity**)((u8*)p + 0xc0);
  if (*slot != NULL && isKilled(*slot)) {
    *slot = NULL;
  }
  if (tryKillPantheonAquaMod(p)) {
    return;
  }
  (sUpdates1[p->mode[1]])((void*)p);
  (sUpdates2[p->mode[1]])((void*)p);
}

void PantheonAquaMod_Die(PAquaMod* p) {
  (sDeads[p->mode[1]])((void*)p);
}

void nop_08051620(PAquaMod* p) {}

INCASM("asm/boss/pantheon_aqua_mod_b.inc");

void nop_08051620(PAquaMod* p);

// clang-format off
static const BossFunc sUpdates1[9] = {
    (BossFunc)nop_08051620,
    (BossFunc)nop_08051620,
    (BossFunc)nop_08051620,
    (BossFunc)nop_08051620,
    (BossFunc)nop_08051620,
    (BossFunc)nop_08051620,
    (BossFunc)nop_08051620,
    (BossFunc)nop_08051620,
    (BossFunc)nop_08051620,
};
// clang-format on

void paquamNeutral(PAquaMod* p);
void paquam_080517ac(PAquaMod* p);
void paquam_080519d0(PAquaMod* p);
void paquam_08051b8c(PAquaMod* p);
void FUN_08051cdc(PAquaMod* p);
void paquamSweepLaser(PAquaMod* p);
void paquam_08051f44(PAquaMod* p);
void paquqmRubble(PAquaMod* p);
void paqua_mod_08052240(PAquaMod* p);

// clang-format off
static const BossFunc sUpdates2[9] = {
    (BossFunc)paquamNeutral,
    (BossFunc)paquam_080517ac,
    (BossFunc)paquam_080519d0,
    (BossFunc)paquam_08051b8c,
    (BossFunc)FUN_08051cdc,
    (BossFunc)paquamSweepLaser,
    (BossFunc)paquam_08051f44,
    (BossFunc)paquqmRubble,
    (BossFunc)paqua_mod_08052240,
};
// clang-format on

// --------------------------------------------

void FUN_080523b8(PAquaMod* p);

static const BossFunc sDeads[1] = {
    (BossFunc)FUN_080523b8,
};

// --------------------------------------------

// 0x0836364c
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
      nature : 0x04,
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
      nature : 0x04,
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
      nature : 0x04,
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
static const Coords32 sElementCoord = {PIXEL(0), PIXEL(0)};
static const u8 u8_ARRAY_08363958[4] = {5, 6, 7, 8};
