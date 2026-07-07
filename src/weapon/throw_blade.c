#include "collision.h"
#include "global.h"
#include "weapon.h"

// ザンエイダン

// props (56bytes, offset: 0xB4..)
struct ThrowBladeProps {
  struct Weapon* saber;  // 0xB4
  u8 unk_b8[8];          // 0xB8
  u8 element;            // 0xC0
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

void ThrowBlade_Init(struct Weapon* w);
void ThrowBlade_Update(struct Weapon* w);
void ThrowBlade_Die(struct Weapon* w);

// clang-format off
const WeaponRoutine gThrowBladeRoutine = {
    [ENTITY_INIT] =      (void*)ThrowBlade_Init,
    [ENTITY_UPDATE] =    (void*)ThrowBlade_Update,
    [ENTITY_DIE] =       (void*)ThrowBlade_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

void MenuExit_ThrowBlade(struct Weapon* p) {
  Player* z = (Player*)(p->s).unk_28;
  struct ThrowBladeProps* s = (struct ThrowBladeProps*)p->buffer;
  if ((s->element != ((&z->unk_b4)->status).element)) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

struct Weapon* CreateThrowBlade(Player* z, struct Weapon* saber, bool8 isIce) {
  struct Weapon* p = AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    struct ThrowBladeProps* s;

    if ((z->unk_b4).mainCopy == WEAPON_SABER) {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_ZANEIDAN);
      (p->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (p->s).renderPrio = 16;
      (p->s).tileNum = gWeaponTileNum[0];
      (p->s).palID = gWeaponPalIDs[0];
      if (isIce) {
        const u8 element = ((&z->unk_b4)->status).element;
        SetWeaponElement(0, element);
      }
    } else {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_ZANEIDAN);
      (p->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (p->s).renderPrio = 16;
      (p->s).tileNum = gWeaponTileNum[1];
      (p->s).palID = gWeaponPalIDs[1];
      if (isIce) {
        const u8 element = ((&z->unk_b4)->status).element;
        SetWeaponElement(1, element);
      }
    }
    (p->s).unk_28 = &z->s;
    s = (struct ThrowBladeProps*)p->buffer;
    s->saber = saber;
    s->element = ((&z->unk_b4)->status).element;
    (p->s).work[0] = isIce, (p->s).work[1] = 0;
  }
  return p;
}

INCASM("asm/weapon/throw_blade.inc");
