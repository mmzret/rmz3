#include "collision.h"
#include "global.h"
#include "weapon.h"

static const struct Collision sCollision;
static const u8 sInitModes[4];

static void Weapon6_Init(struct Weapon* w);
static void Weapon6_Update(struct Weapon* w);
static void Weapon6_Die(struct Weapon* w);

// clang-format off
const WeaponRoutine gWeapon6Routine = {
    [ENTITY_INIT] =      Weapon6_Init,
    [ENTITY_UPDATE] =    Weapon6_Update,
    [ENTITY_DIE] =       Weapon6_Die,
    [ENTITY_DISAPPEAR] = DeleteWeapon,
    [ENTITY_EXIT] =      (WeaponFunc)DeleteEntity,    
};
// clang-format on

void CreateWeapon6(s32 x, s32 y) {
  struct Weapon* w = (struct Weapon*)AllocEntityLast(gWeaponHeaderPtr);
  if (w != NULL) {
    INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_06);
    (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
    (w->s).taskCol = 16;
    (w->s).tileNum = gWeaponTileNum[0];
    (w->s).palID = gWeaponPalIDs[0];
    ((w->s).coord).x = x;
    ((w->s).coord).y = y;
    (w->s).work[0] = 0;
  }
}

// 0x0803aaec
static void onHit(struct Body* body UNUSED, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) { return; }

static void Weapon6_Init(struct Weapon* w) {
  SET_WEAPON_ROUTINE(w, ENTITY_UPDATE);
  (w->s).mode[1] = sInitModes[(w->s).work[0]];
  (w->s).flags |= FLIPABLE;
  (w->s).flags |= DISPLAY;
  InitNonAffineMotion(&w->s);
  ResetDynamicMotion(&w->s);
  INIT_BODY(w, &sCollision, 1, onHit);
  Weapon6_Update(w);
}

static void nop_0803abf4(struct Weapon* w);
static void updateWeapon6(struct Weapon* w);

static void Weapon6_Update(struct Weapon* w) {
  static const WeaponFunc sUpdates1[1] = {
      nop_0803abf4,
  };
  static const WeaponFunc sUpdates2[1] = {
      updateWeapon6,
  };
  if ((w->body).status & BODY_STATUS_B2) {
    SET_WEAPON_ROUTINE(w, ENTITY_DIE);
    Weapon6_Die(w);
    return;
  }
  (sUpdates1[(w->s).mode[1]])(w);
  (sUpdates2[(w->s).mode[1]])(w);
}

static void Weapon6_Die(struct Weapon* w) {
  (w->body).status = 0;
  (w->body).prevStatus = 0;
  (w->body).invincibleTime = 0;
  (w->s).flags &= ~COLLIDABLE;
  SET_WEAPON_ROUTINE(w, ENTITY_EXIT);
}

static void nop_0803abf4(struct Weapon* w) { return; }

static void updateWeapon6(struct Weapon* w) {
  switch ((w->s).mode[2]) {
    case 0: {
      InitRotatableMotion(&w->s);
      (w->s).flags2 &= ~DYNAMIC;
      (w->s).tileNum = 0;
      (w->s).palID = 0;
      SetMotion(&w->s, MOTION(SM033_FEFNIR_FIREBALL, 0));
      (w->s).angle = 64;
      (w->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 y = (w->s).coord.y;
      (w->s).coord.y -= PIXEL(4);
      if (((w->s).coord.x - (u32)PIXEL(9808) > PIXEL(304)) || (y - (u32)PIXEL(436) > PIXEL(224))) {
        SET_WEAPON_ROUTINE(w, ENTITY_DIE);
      }
      UpdateMotionGraphic(&w->s);
      break;
    }
  }
}

// --------------------------------------------

static const struct Collision sCollision = {
  kind : DDP,
  faction : FACTION_ALLY,
  special : 1,
  damage : 1,
  unk_04 : 0x00,
  element : 0x00,
  nature : 0x00,
  comboLv : 0x00,
  hitzone : 0x00,
  hardness : 0x00,
  unk_0a : 0x00,
  remaining : 0,
  unk_0c : 0x00000001,
  range : {0x0000, 0x0000, 0x0E00, 0x0E00},
};

static const u8 sInitModes[4] = {0, 0, 0, 0};
