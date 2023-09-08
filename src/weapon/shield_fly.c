#include "collision.h"
#include "global.h"
#include "mission.h"
#include "weapon.h"

static const u8 sElements[4];
static const motion_t sShieldFlyMotions[3][4];
static const WeaponFunc sShieldFlyUpdates[5];

bool32 shield_0803a5fc(struct Weapon* w);
static void onHit(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED);

static void ShieldFly_Init(struct Weapon* w);
static void ShieldFly_Update(struct Weapon* w);
static void ShieldFly_Die(struct Weapon* w);

NAKED void MenuExit_ShieldFly(struct Weapon* w) { INCCODE("asm/todo/MenuExit_ShieldFly.inc"); }

struct Weapon* CreateWeaponShieldFly(struct Zero* z, u8 r1) {
  struct Weapon* w;

  KillAllWeapons(DeleteSaber);
  w = (struct Weapon*)AllocEntityFirst(gWeaponHeaderPtr);
  if (w != NULL) {
    u8 element;

    if ((z->unk_b4).mainCopy == WEAPON_SHIELD) {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_SHIELD_FLY);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[0];
      (w->s).palID = gWeaponPalIDs[0];
      element = sElements[((&z->unk_b4)->status).element];
      SetWeaponElement(0, element);

    } else {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_SHIELD_FLY);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[1];
      (w->s).palID = gWeaponPalIDs[1];
      element = sElements[((&z->unk_b4)->status).element];
      SetWeaponElement(1, element);
    }

    (&w->unk_b4)->z = z;
    (w->s).work[0] = z->unk_127;
    (w->s).work[1] = r1;
    (&w->unk_b4)->props[1][1] = ((&z->unk_b4)->status).element;
  }
  return w;
}

static void ShieldFly_Init(struct Weapon* w) {
  struct Weapon_b4* b4;
  SET_WEAPON_ROUTINE(w, ENTITY_MAIN);
  InitNonAffineMotion(&w->s);
  ResetDynamicMotion(&w->s);
  (w->s).flags |= DISPLAY;
  (w->s).flags |= FLIPABLE;
  SetMotion(&w->s, sShieldFlyMotions[(w->s).work[1]][(w->s).work[0]]);
  PlaySound(SE_CHARGE_SHIELD_VOICE);
  b4 = &w->unk_b4;
  b4->props[1][2] = 1;
  ShieldFly_Update(w);
}

static void ShieldFly_Update(struct Weapon* w) {
  struct Weapon_b4* b4 = &w->unk_b4;
  struct Zero* z = b4->z;
  if (z->elfMotion != 0) {
    SET_WEAPON_ROUTINE(w, ENTITY_DIE);
    return;
  }
  if (((z->body).status & BODY_STATUS_DEAD) || ((z->body).hp == 0)) {
    SET_WEAPON_ROUTINE(w, ENTITY_DIE);
    return;
  }
  if ((b4->props[1][2] != 0) && ((w->body).status & BODY_STATUS_BLOCKED)) {
    PlaySound(SE_BLOCKED);
    b4->props[1][2] = 0;
  }

  {
    struct Zero_b4* b4 = &z->unk_b4;
    if ((b4->status).mainWeapon == WEAPON_SHIELD) {
      (z->restriction).mainCharge = TRUE;
    } else {
      (z->restriction).subCharge = TRUE;
    }
  }
  (sShieldFlyUpdates[(w->s).mode[1]])(w);
  UpdateMotionGraphic(&w->s);

  if (((w->s).mode[1] == 2) && shield_0803a5fc(w)) {
    SET_WEAPON_ROUTINE(w, ENTITY_DIE);
  }
}

static void ShieldFly_Die(struct Weapon* w) {
  (w->s).flags &= ~DISPLAY;
  SET_WEAPON_ROUTINE(w, ENTITY_EXIT);
}

static void onHit(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  if ((body->hitboxFlags & BODY_STATUS_B2) && (gMission.weaponCount[WEAPON_SHIELD] < 0xFFFF)) {
    gMission.weaponCount[WEAPON_SHIELD]++;
  }
}

INCASM("asm/weapon/shield_fly.inc");

static const motion_t sShieldFlyMotions[3][4] = {
    {
        MOTION(0x6D, 0x00),
        MOTION(0x70, 0x00),
        MOTION(0x72, 0x00),
        MOTION(0x74, 0x00),
    },
    {
        MOTION(0x6D, 0x03),
        MOTION(0x70, 0x01),
        MOTION(0x72, 0x01),
        MOTION(0x74, 0x01),
    },
    {
        MOTION(0x6D, 0x03),
        MOTION(0x70, 0x01),
        MOTION(0x72, 0x01),
        MOTION(0x74, 0x01),
    },
};

static const u8 sElements[4] = {0, 1, 2, 3};
const u8 u8_ARRAY_08361288[4] = {5, 8, 11, 0};

const s16 s16_ARRAY_0836128c[8] = {
    0x1C00, -0x1300, 0x1A00, -0x1500, 0x1800, -0x1400, 0x1A00, -0x1000,
};

const s16 s16_ARRAY_0836129c[8] = {
    0x1C00, -0x1200, 0x1C00, -0x1500, 0x1600, -0x1400, 0x1B00, -0x0F00,
};

const struct Collision Collision_ARRAY_083612ac[2] = {
    {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x03,
      element : 0x00,
      nature : 0x12,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00010000,
      range : {0x0000, 0x0000, 0x2600, 0x1000},
    },
    {
      kind : DRP,
      layer : 0,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x2600, 0x1000},
    },
};

const struct Collision Collision_ARRAY_083612dc[2] = {
    {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x03,
      element : 0x00,
      nature : 0x12,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00010000,
      range : {0x0000, 0x0000, 0x2200, 0x2200},
    },
    {
      kind : DRP,
      layer : 0,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x2200, 0x2200},
    },
};

// --------------------------------------------

void shield_08039d3c(struct Weapon* w);
void shield_08039e28(struct Weapon* w);
void shield_08039ffc(struct Weapon* w);
void shield_0803a108(struct Weapon* w);
void shield_0803a3b4(struct Weapon* w);

// clang-format off
static const WeaponFunc sShieldFlyUpdates[5] = {
    shield_08039d3c,
    shield_08039e28,
    shield_08039ffc,
    shield_0803a108,
    shield_0803a3b4,
};
// clang-format on

// --------------------------------------------

// clang-format off
const WeaponRoutine gShieldFlyRoutine = {
    [ENTITY_INIT] =      ShieldFly_Init,
    [ENTITY_MAIN] =      ShieldFly_Update,
    [ENTITY_DIE] =       ShieldFly_Die,
    [ENTITY_DISAPPEAR] = DeleteWeapon,
    [ENTITY_EXIT] =      (WeaponFunc)DeleteEntity,    
};
// clang-format on

const u8 u8_ARRAY_08361334[4] = {1, 3, 4, 0};
