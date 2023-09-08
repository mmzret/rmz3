#include "global.h"
#include "weapon.h"

// クロールシールドの電気びりびり

void ElecShieldSweep_Init(struct Weapon* w);
void ElecShieldSweep_Update(struct Weapon* w);
void ElecShieldSweep_Die(struct Weapon* w);

// clang-format off
const WeaponRoutine gElecShieldSweepRoutine = {
    [ENTITY_INIT] =      ElecShieldSweep_Init,
    [ENTITY_MAIN] =      ElecShieldSweep_Update,
    [ENTITY_DIE] =       ElecShieldSweep_Die,
    [ENTITY_DISAPPEAR] = DeleteWeapon,
    [ENTITY_EXIT] =      (WeaponFunc)DeleteEntity,    
};
// clang-format on

void MenuExit_ShieldSweepElec(struct Weapon* w) {
  struct Zero* z = (struct Zero*)(w->s).unk_28;
  if (((&z->unk_b4)->status).element != ELEMENT_THUNDER || (z->unk_136 & (1 << 3))) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    (w->body).status = 0;
    (w->body).prevStatus = 0;
    (w->body).invincibleTime = 0;
    (w->s).flags &= ~COLLIDABLE;
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
  }
}

struct Weapon* CreateShieldSweepElec(struct Zero* z, s32 x, s32 y) {
  struct Weapon* w = (struct Weapon*)AllocEntityFirst(gWeaponHeaderPtr);
  if (w != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_SABER) {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_SHIELD_SWEEP_ELEC);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[0];
      (w->s).palID = gWeaponPalIDs[0];
    } else {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_SHIELD_SWEEP_ELEC);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[1];
      (w->s).palID = gWeaponPalIDs[1];
    }
    (w->s).unk_28 = &z->s;
    (w->s).coord.x = x;
    (w->s).coord.y = y;
    (w->s).work[0] = 0;
    (w->s).work[1] = 0;
  }
  return w;
}

INCASM("asm/weapon/shield_sweep_elec.inc");
