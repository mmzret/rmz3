#include "collision.h"
#include "global.h"
#include "weapon.h"

static const motion_t sMotions[4];
static const struct Collision sCollisions[2];

void Weapon13_Init(Weapon* p);
void Weapon13_Update(Weapon* p);
void Weapon13_Die(Weapon* p);

// clang-format off
const WeaponRoutine gWeapon13Routine = {
    [ENTITY_INIT] =      (void*)Weapon13_Init,
    [ENTITY_UPDATE] =    (void*)Weapon13_Update,
    [ENTITY_DIE] =       (void*)Weapon13_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

void MenuExit_Weapon13(WeaponCommon* p) {
  if ((p->props).z->unk_136 & (1 << 2)) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

struct Entity* CreateWeapon13(struct Zero* z, u8 n) {
  u8 element;
  WeaponCommon* p = AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_ROD) {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_13);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[0], p->palID = gWeaponPalIDs[0];
      element = ((&z->unk_b4)->status).element;
      SetWeaponElement(0, element);
    } else {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_13);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[1], p->palID = gWeaponPalIDs[1];
      element = ((&z->unk_b4)->status).element;
      SetWeaponElement(1, element);
    }
    (p->props).z = z;
    p->work[0] = n;
    p->work[1] = ++z->unk_137;
  }
  return (void*)p;
}

INCASM("asm/weapon/unk_13_a.inc");

void Weapon13_Die(struct Weapon* p) {
  (p->s).flags &= ~DISPLAY;
  SET_WEAPON_ROUTINE(p, ENTITY_EXIT);
}

static const s8 s8_ARRAY_ARRAY_083616cc[2][4] = {
    {0xEA, 0xF5, 0x03, 0x16},
    {0xF2, 0xD8, 0x02, 0xF3},
};  // 0x083616cc

// 0x083616d4
static const u8 u8_ARRAY_083616d4[4] = {0x80, 0xC0, 0x40, 0x00};

// 0x083616d8
static const motion_t sWeapon13Animations[4] = {
    MOTION(DM104_UNK, 0),
    MOTION(DM104_UNK, 1),
    MOTION(DM104_UNK, 1),
    MOTION(DM104_UNK, 0),
};
