#include "collision.h"
#include "global.h"
#include "weapon.h"

static void Weapon6_Init(Weapon* w);
static void Weapon6_Update(Weapon* w);
static void Weapon6_Die(Weapon* w);

// clang-format off
const WeaponRoutine gWeapon6Routine = {
    [ENTITY_INIT] =      (WeaponFunc)Weapon6_Init,
    [ENTITY_UPDATE] =    (WeaponFunc)Weapon6_Update,
    [ENTITY_DIE] =       (WeaponFunc)Weapon6_Die,
    [ENTITY_DISAPPEAR] = (WeaponFunc)DeleteWeapon,
    [ENTITY_EXIT] =      (WeaponFunc)DeleteEntity,    
};
// clang-format on

void CreateWeapon6(s32 x, s32 y) {
  struct Entity* p = AllocEntityFirst(gWeaponHeaderPtr);
  if (p != NULL) {
    INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_06);
    p->flags2 &= ~ENTITY_FLAGS2_B6;
    p->renderPrio = 16;
    p->tileNum = gWeaponTileNum[0];
    p->palID = gWeaponPalIDs[0];
    (p->coord).x = x;
    (p->coord).y = y;
    p->work[0] = 0;
  }
}

// 0x0803aaec
static void onHit(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) { return; }

// --------------------------------------------

static const struct Collision sCollision;
static const u8 sInitModes[];

static void Weapon6_Init(Weapon* p) {
  SET_WEAPON_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);
  INIT_BODY(p, &sCollision, 1, onHit);
  Weapon6_Update(p);
}

static void nop_0803abf4(void* _);
static void _Weapon6_Update(Weapon* w);

static void Weapon6_Update(Weapon* p) {
  static const WeaponFunc sUpdates1[1] = {
      (WeaponFunc)nop_0803abf4,
  };
  static const WeaponFunc sUpdates2[1] = {
      (WeaponFunc)_Weapon6_Update,
  };
  if ((p->body).status & BODY_STATUS_B2) {
    SET_WEAPON_ROUTINE(p, ENTITY_DIE);
    Weapon6_Die(p);
    return;
  }
  (sUpdates1[p->mode[1]])(p);
  (sUpdates2[p->mode[1]])(p);
}

static void Weapon6_Die(Weapon* p) {
  EXIT_BODY(p);
  SET_WEAPON_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_0803abf4(void* _) { return; }

static void _Weapon6_Update(Weapon* p) {
  switch (p->mode[2]) {
    case 0: {
      InitRotatableMotion((void*)p);
      p->flags2 &= ~DYNAMIC;
      p->tileNum = 0, p->palID = 0;
      SetSpriteAnimation(p, MOTION(SM033_FEFNIR_FIREBALL, 0));
      p->angle = 64;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 y = p->coord.y;
      p->coord.y -= PIXEL(4);
      if ((p->coord.x - (u32)PIXEL(9808) > PIXEL(304)) || (y - (u32)PIXEL(436) > PIXEL(224))) {
        SET_WEAPON_ROUTINE(p, ENTITY_DIE);
      }
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

// --------------------------------------------

static const struct Collision sCollision = {
  kind : DDP,
  faction : FACTION_ALLY,
  special : HALFABLE,
  damage : 1,
  remaining : 0,
  layer : 0x00000001,
  range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(14)},
};

static const u8 sInitModes[4] = {0, 0, 0, 0};
