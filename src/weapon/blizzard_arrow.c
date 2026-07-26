#include "entity/macros.h"
#include "zero.h"
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

void BlizzardArrow_Init(Weapon* p);
void BlizzardArrow_Update(Weapon* p);
void BlizzardArrow_Die(Weapon* p);

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

void MenuExit_BlizzardArrow(Weapon* p) {
  Player* z = (Player*)p->unk_28;
  if (((&z->unk_b4)->status).element != ELEMENT_ICE) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  if (z->unk_136 & (1 << WEAPON_BUSTER)) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

struct Weapon* CreateBlizzardArrow(struct Zero* z, struct Coord* c, u8 n, bool8 xflip) {
  Weapon* w = (struct Weapon*)AllocEntityLast(gWeaponHeaderPtr);

  if (w != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_BUSTER) {
      INIT_WEAPON_ROUTINE(w, 10);
      w->flags2 &= ~ENTITY_FLAGS2_B6;
      w->renderPrio = 16;
      w->tileNum = gWeaponTileNum[0];
      w->palID = gWeaponPalIDs[0];
    } else {
      INIT_WEAPON_ROUTINE(w, 10);
      w->flags2 &= ~ENTITY_FLAGS2_B6;
      w->renderPrio = 16;
      w->tileNum = gWeaponTileNum[1];
      w->palID = gWeaponPalIDs[1];
    }
    w->unk_28 = (struct Entity*)z;
    SET_XFLIP(w, xflip);
    w->coord = *c;
    w->work[0] = n;
    w->work[1] = 0;
  }
  return w;
}

INCASM("asm/weapon/blizzard_arrow_a.inc");

// --------------------------------------------

// 0x08361624
static const s32 sBlizzardArrowYOffsets[3] = {PIXEL(0), -PIXEL(4), PIXEL(4)};
