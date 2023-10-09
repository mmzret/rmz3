#include "collision.h"
#include "global.h"
#include "weapon.h"

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 4,
      unk_04 : 0x07,
      element : 0x03,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000010,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
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
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
};

// --------------------------------------------

void BlizzardArrow_Init(struct Weapon* w);
void BlizzardArrow_Update(struct Weapon* w);
void BlizzardArrow_Die(struct Weapon* w);

// clang-format off
const WeaponRoutine gBlizzardArrowRoutine = {
    [ENTITY_INIT] =      BlizzardArrow_Init,
    [ENTITY_UPDATE] =    BlizzardArrow_Update,
    [ENTITY_DIE] =       BlizzardArrow_Die,
    [ENTITY_DISAPPEAR] = DeleteWeapon,
    [ENTITY_EXIT] =      (WeaponFunc)DeleteEntity,    
};
// clang-format on

// --------------------------------------------

void MenuExit_BlizzardArrow(struct Weapon* w) {
  struct Zero* z = (struct Zero*)(w->s).unk_28;
  if (((&z->unk_b4)->status).element != ELEMENT_ICE) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    (w->body).status = 0;
    (w->body).prevStatus = 0;
    (w->body).invincibleTime = 0;
    (w->s).flags &= ~COLLIDABLE;
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
    return;
  }
  if (z->unk_136 & (1 << 0)) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    (w->body).status = 0;
    (w->body).prevStatus = 0;
    (w->body).invincibleTime = 0;
    (w->s).flags &= ~COLLIDABLE;
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
  }
}

INCASM("asm/weapon/blizzard_arrow.inc");

// --------------------------------------------

static const s32 sBulletYCoords[3] = {0x000, -0x400, 0x400};
