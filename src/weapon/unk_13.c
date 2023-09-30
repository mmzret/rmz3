#include "collision.h"
#include "global.h"
#include "weapon.h"

static const motion_t sMotions[4];
static const struct Collision sCollisions[2];

void Weapon13_Init(struct Weapon* w);
void Weapon13_Update(struct Weapon* w);
void Weapon13_Die(struct Weapon* w);

// clang-format off
const WeaponRoutine gWeapon13Routine = {
    [ENTITY_INIT] =      Weapon13_Init,
    [ENTITY_MAIN] =      Weapon13_Update,
    [ENTITY_DIE] =       Weapon13_Die,
    [ENTITY_DISAPPEAR] = DeleteWeapon,
    [ENTITY_EXIT] =      (WeaponFunc)DeleteEntity,    
};
// clang-format on

void MenuExit_Weapon13(struct Weapon* w) {
  if (((w->unk_b4).z)->unk_136 & (1 << 2)) {
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
    (&w->unk_b4)->z = z;
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
    MOTION(0x68, 0x00),
    MOTION(0x68, 0x01),
    MOTION(0x68, 0x01),
    MOTION(0x68, 0x00),
};

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
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
