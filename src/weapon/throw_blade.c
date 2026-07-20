#include "collision.h"
#include "global.h"
#include "weapon.h"

// ザンエイダン

// props (56bytes, offset: 0xB4..)
struct ThrowBladeProps {
  Weapon* saber;  // 0xB4
  u8 unk_b8[8];   // 0xB8
  u8 element;     // 0xC0
  u8 unk_c1[43];
};

// 0x08361630
static const struct Collision sThrowBladeCollision_Normal[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 6,
      atkType : ATK_UNK11,
      nature : BODY_NATURE_CUT,
      comboLv : 1,
      remaining : 1,
      layer : 0x00000040,
      range : {PIXEL(7), PIXEL(1), PIXEL(27), PIXEL(17)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {PIXEL(7), PIXEL(1), PIXEL(27), PIXEL(17)},
    },
};

// 0x08361660, アイスチップ装備時
static const struct Collision sThrowBladeCollision_Ice[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 6,
      atkType : ATK_UNK11,
      nature : BODY_NATURE_CUT,
      comboLv : 1,
      remaining : 1,
      layer : 0x00000040,
      range : {PIXEL(10), PIXEL(1), PIXEL(35), PIXEL(23)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {PIXEL(10), PIXEL(1), PIXEL(35), PIXEL(23)},
    },
};

// --------------------------------------------

void ThrowBlade_Init(Weapon* w);
void ThrowBlade_Update(Weapon* w);
void ThrowBlade_Die(Weapon* w);

// clang-format off
const WeaponRoutine gThrowBladeRoutine = {
    [ENTITY_INIT] =      (void*)ThrowBlade_Init,
    [ENTITY_UPDATE] =    (void*)ThrowBlade_Update,
    [ENTITY_DIE] =       (void*)ThrowBlade_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

void MenuExit_ThrowBlade(Weapon* p) {
  Player* z = (Player*)p->unk_28;
  struct ThrowBladeProps* s = (struct ThrowBladeProps*)p->buffer;
  if ((s->element != ((&z->unk_b4)->status).element)) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

Weapon* CreateThrowBlade(Player* z, Weapon* saber, bool8 isIce) {
  Weapon* p = AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    struct ThrowBladeProps* s;

    if ((z->unk_b4).mainCopy == WEAPON_SABER) {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_ZANEIDAN);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[0];
      p->palID = gWeaponPalIDs[0];
      if (isIce) {
        const u8 element = ((&z->unk_b4)->status).element;
        SetWeaponElement(0, element);
      }
    } else {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_ZANEIDAN);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[1];
      p->palID = gWeaponPalIDs[1];
      if (isIce) {
        const u8 element = ((&z->unk_b4)->status).element;
        SetWeaponElement(1, element);
      }
    }
    p->unk_28 = &z->s;
    s = (struct ThrowBladeProps*)p->buffer;
    s->saber = saber;
    s->element = ((&z->unk_b4)->status).element;
    p->work[0] = isIce, p->work[1] = 0;
  }
  return p;
}

INCASM("asm/weapon/throw_blade.inc");
