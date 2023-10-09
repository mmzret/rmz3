#include "global.h"
#include "weapon.h"

void ShieldSweep_Init(struct Weapon* w);
void ShieldSweep_Update(struct Weapon* w);
void ShieldSweep_Die(struct Weapon* w);

// clang-format off
const WeaponRoutine gShieldSweepRoutine = {
    [ENTITY_INIT] =      ShieldSweep_Init,
    [ENTITY_UPDATE] =    ShieldSweep_Update,
    [ENTITY_DIE] =       ShieldSweep_Die,
    [ENTITY_DISAPPEAR] = DeleteWeapon,
    [ENTITY_EXIT] =      (WeaponFunc)DeleteEntity,    
};
// clang-format on

void MenuExit_ShieldSweep(struct Weapon* w) {
  if (((w->unk_b4).z)->unk_136 & (1 << 3)) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    (w->body).status = 0;
    (w->body).prevStatus = 0;
    (w->body).invincibleTime = 0;
    (w->s).flags &= ~COLLIDABLE;
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
  }
}

struct Weapon* CreateShieldSweep(struct Zero* z, struct Entity* p, u8 n) {
  struct Weapon* w;
  struct Weapon_b4* b4;
  u8 element;

  w = (struct Weapon*)AllocEntityFirst(gWeaponHeaderPtr);
  if (w != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_SHIELD) {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_SHIELD_SWEEP);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[0];
      (w->s).palID = gWeaponPalIDs[0];
      element = ((&z->unk_b4)->status).element;
      SetWeaponElement(0, element);
    } else {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_SHIELD_SWEEP);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[1];
      (w->s).palID = gWeaponPalIDs[1];
      element = ((&z->unk_b4)->status).element;
      SetWeaponElement(1, element);
    }
    b4 = (struct Weapon_b4*)(&w->unk_b4);
    b4->z = z;
    (w->s).unk_28 = p;
    (w->s).work[0] = n;
    (w->s).work[1] = 0;
  }
  return w;
}

INCASM("asm/weapon/shield_sweep.inc");
