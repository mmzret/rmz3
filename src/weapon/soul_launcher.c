#include "collision.h"
#include "global.h"
#include "weapon.h"

struct SoulLauncher {
  OBJECT_HDR;
  // props (56bytes, offset: 0xB4..)
  struct SoulLauncherProps {
    struct Zero* z;  // 0xB4
    u8 unk_b8[8];    // 0xB8
    u8 unk_c0;       // 0xC0
    u8 element;      // 0xC1
    u8 unk_c2[42];   // 0xC2
  } props;
};
static_assert(sizeof(struct SoulLauncher) == sizeof(struct Weapon));

static const struct Collision sCollisions[2];

void MenuExit_SoulLauncher(struct SoulLauncher* p) {
  struct Zero* z = (struct Zero*)(p->s).unk_28;
  if (((&p->props)->element != ((&z->unk_b4)->status).element) || (z->unk_136 & (1 << 2))) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

struct Entity* CreateSoulLauncher(struct Zero* z, u8 r1, u8 r2) {
  struct SoulLauncher* p = (struct SoulLauncher*)AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_ROD) {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_SOUL_LANCHER);
      (p->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (p->s).renderPrio = 16;
      (p->s).tileNum = gWeaponTileNum[0], (p->s).palID = gWeaponPalIDs[0];
    } else {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_SOUL_LANCHER);
      (p->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (p->s).renderPrio = 16;
      (p->s).tileNum = gWeaponTileNum[1], (p->s).palID = gWeaponPalIDs[1];
    }
    (p->s).unk_28 = (void*)z;
    (p->s).work[0] = r1, (p->s).work[1] = r2;
    (&p->props)->element = ((&z->unk_b4)->status).element;
  }
  return (void*)p;
}

INCASM("asm/weapon/soul_launcher.inc");

// 0x08361558
static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SOUL_LAUNCHER,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 1,
      remaining : 1,
      layer : 0x00200000,
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

void SoulLauncher_Init(struct Weapon* p);
void SoulLauncher_Update(struct Weapon* p);
void SoulLauncher_Die(struct Weapon* p);

// clang-format off
const WeaponRoutine gSoulLauncherRoutine = {
    [ENTITY_INIT] =      (void*)SoulLauncher_Init,
    [ENTITY_UPDATE] =    (void*)SoulLauncher_Update,
    [ENTITY_DIE] =       (void*)SoulLauncher_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

// 0x0836159c
static const s32 sSoulLauncherDx[4] = {-PIXEL(2), -PIXEL(1), PIXEL(1), PIXEL(2)};
