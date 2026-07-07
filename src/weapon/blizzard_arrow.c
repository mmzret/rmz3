#include "collision.h"
#include "global.h"
#include "weapon.h"

// 0x083615e0
static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 4,
      atkType : 7,
      element : ELEMENT_ICE,
      comboLv : 1,
      remaining : 1,
      layer : 0x00000010,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
};

// --------------------------------------------

void BlizzardArrow_Init(struct Weapon* p);
void BlizzardArrow_Update(struct Weapon* p);
void BlizzardArrow_Die(struct Weapon* p);

// clang-format off
const WeaponRoutine gBlizzardArrowRoutine = {
    [ENTITY_INIT] =      (void*)BlizzardArrow_Init,
    [ENTITY_UPDATE] =    (void*)BlizzardArrow_Update,
    [ENTITY_DIE] =       (void*)BlizzardArrow_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

// --------------------------------------------

void MenuExit_BlizzardArrow(struct Weapon* p) {
  Player* z = (Player*)(p->s).unk_28;
  if (((&z->unk_b4)->status).element != ELEMENT_ICE) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  if (z->unk_136 & (1 << WEAPON_BUSTER)) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

INCASM("asm/weapon/blizzard_arrow.inc");

// --------------------------------------------

// 0x08361624
static const s32 sBlizzardArrowYOffsets[3] = {PIXEL(0), -PIXEL(4), PIXEL(4)};
