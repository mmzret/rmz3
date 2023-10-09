#include "collision.h"
#include "global.h"
#include "weapon.h"

static const struct Collision sNormalCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 6,
      unk_04 : 0x0B,
      element : 0x00,
      nature : BODY_NATURE_B4,
      comboLv : 1,
      hitzone : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000040,
      range : {PIXEL(7), PIXEL(1), PIXEL(27), PIXEL(17)},
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
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(7), PIXEL(1), PIXEL(27), PIXEL(17)},
    },
};

static const struct Collision sIceCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 6,
      unk_04 : 0x0B,
      element : 0x00,
      nature : BODY_NATURE_B4,
      comboLv : 1,
      hitzone : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000040,
      range : {PIXEL(10), PIXEL(1), PIXEL(35), PIXEL(23)},
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
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(10), PIXEL(1), PIXEL(35), PIXEL(23)},
    },
};

// --------------------------------------------

void ThrowBlade_Init(struct Weapon* w);
void ThrowBlade_Update(struct Weapon* w);
void ThrowBlade_Die(struct Weapon* w);

// clang-format off
const WeaponRoutine gThrowBladeRoutine = {
    [ENTITY_INIT] =      ThrowBlade_Init,
    [ENTITY_UPDATE] =    ThrowBlade_Update,
    [ENTITY_DIE] =       ThrowBlade_Die,
    [ENTITY_DISAPPEAR] = DeleteWeapon,
    [ENTITY_EXIT] =      (WeaponFunc)DeleteEntity,    
};
// clang-format on

void MenuExit_ThrowBlade(struct Weapon* w) {
  struct Zero* z = (struct Zero*)(w->s).unk_28;
  if (((&w->unk_b4)->props[1][0] != ((&z->unk_b4)->status).element)) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    (w->body).status = 0;
    (w->body).prevStatus = 0;
    (w->body).invincibleTime = 0;
    (w->s).flags &= ~COLLIDABLE;
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
  }
}

struct Weapon* CreateThrowBlade(struct Zero* z, struct Weapon* saber, bool8 isIce) {
  struct Weapon* w = (struct Weapon*)AllocEntityFirst(gWeaponHeaderPtr);
  if (w != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_SABER) {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_ZANEIDAN);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[0];
      (w->s).palID = gWeaponPalIDs[0];
      if (isIce) {
        const u8 element = ((&z->unk_b4)->status).element;
        SetWeaponElement(0, element);
      }
    } else {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_ZANEIDAN);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[1];
      (w->s).palID = gWeaponPalIDs[1];
      if (isIce) {
        const u8 element = ((&z->unk_b4)->status).element;
        SetWeaponElement(1, element);
      }
    }
    (w->s).unk_28 = &z->s;
    (&w->unk_b4)->z = (struct Zero*)saber;
    (&w->unk_b4)->props[1][0] = ((&z->unk_b4)->status).element;
    (w->s).work[0] = isIce;
    (w->s).work[1] = 0;
  }
  return w;
}

INCASM("asm/weapon/throw_blade.inc");
