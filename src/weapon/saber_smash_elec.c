#include "global.h"
#include "weapon.h"

// ラクサイガ雷が地面につくる電撃

static const struct Collision sCollisions[2];

void SmashElec_Init(struct Weapon* w);
void SmashElec_Update(struct Weapon* w);
void SmashElec_Die(struct Weapon* w);
void SmashElec_Disappear(struct Weapon* w);

// clang-format off
const WeaponRoutine gSmashElecRoutine = {
    [ENTITY_INIT] =      SmashElec_Init,
    [ENTITY_MAIN] =      SmashElec_Update,
    [ENTITY_DIE] =       SmashElec_Die,
    [ENTITY_DISAPPEAR] = SmashElec_Disappear,
    [ENTITY_EXIT] =      (WeaponFunc)DeleteEntity,    
};
// clang-format on

void MenuExit_SaberSmash(struct Weapon* w) {
  struct Zero* z = (struct Zero*)(w->s).unk_28;
  if (((&z->unk_b4)->status).element != ELEMENT_THUNDER || (z->unk_136 & (1 << 1))) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    (w->body).status = 0;
    (w->body).prevStatus = 0;
    (w->body).invincibleTime = 0;
    (w->s).flags &= ~COLLIDABLE;
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
  }
}

INCASM("asm/weapon/saber_smash_elec.inc");

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 4,
      unk_04 : 0x00,
      element : 0x01,
      nature : 0x02,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000004,
      range : {0x0000, 0x0000, 0x1200, 0x1200},
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
      range : {0x0000, 0x0000, 0x1200, 0x1200},
    },
};
