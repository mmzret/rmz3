#include "collision.h"
#include "global.h"
#include "weapon.h"

#define PROP (w->props.common)

static const motion_t sMotions[4];
static const struct Collision sCollisions[2];

void Weapon13_Init(struct Weapon* w);
void Weapon13_Update(struct Weapon* w);
void Weapon13_Die(struct Weapon* w);

// clang-format off
const WeaponRoutine gWeapon13Routine = {
    [ENTITY_INIT] =      Weapon13_Init,
    [ENTITY_UPDATE] =    Weapon13_Update,
    [ENTITY_DIE] =       Weapon13_Die,
    [ENTITY_DISAPPEAR] = DeleteWeapon,
    [ENTITY_EXIT] =      (WeaponFunc)DeleteEntity,    
};
// clang-format on

void MenuExit_Weapon13(struct Weapon* w) {
  if ((PROP.z)->unk_136 & (1 << 2)) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    (w->body).status = 0;
    (w->body).prevStatus = 0;
    (w->body).invincibleTime = 0;
    (w->s).flags &= ~COLLIDABLE;
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
  }
}

struct Weapon* CreateWeapon13(struct Zero* z, u8 n) {
  u8 element;
  struct Weapon* w = (struct Weapon*)AllocEntityFirst(gWeaponHeaderPtr);
  if (w != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_ROD) {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_13);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[0];
      (w->s).palID = gWeaponPalIDs[0];
      element = ((&z->unk_b4)->status).element;
      SetWeaponElement(0, element);
    } else {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_13);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[1];
      (w->s).palID = gWeaponPalIDs[1];
      element = ((&z->unk_b4)->status).element;
      SetWeaponElement(1, element);
    }
    (&PROP)->z = z;
    (w->s).work[0] = n;
    (w->s).work[1] = ++z->unk_137;
  }
  return w;
}

INCASM("asm/weapon/unk_13.inc");

const s8 s8_ARRAY_ARRAY_083616cc[2][4] = {
    {0xEA, 0xF5, 0x03, 0x16},
    {0xF2, 0xD8, 0x02, 0xF3},
};

const u8 u8_ARRAY_083616d4[4] = {0x80, 0xC0, 0x40, 0x00};

static const motion_t sMotions[4] = {
    MOTION(DM104_UNK, 0),
    MOTION(DM104_UNK, 1),
    MOTION(DM104_UNK, 1),
    MOTION(DM104_UNK, 0),
};

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      element : ELEMENT_THUNDER,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 1,
      remaining : 1,
      layer : 0x00000004,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
};

#undef PROP
