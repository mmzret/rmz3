#include "collision.h"
#include "global.h"
#include "weapon.h"

static const struct Collision sCollisions[2];

void MenuExit_SoulLauncher(struct Weapon* w) {
  struct Zero* z = (struct Zero*)(w->s).unk_28;
  if (((&w->unk_b4)->props[1][1] != ((&z->unk_b4)->status).element) || (z->unk_136 & (1 << 2))) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    (w->body).status = 0;
    (w->body).prevStatus = 0;
    (w->body).invincibleTime = 0;
    (w->s).flags &= ~COLLIDABLE;
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
  }
}

struct Weapon* CreateSoulLauncher(struct Zero* z, u8 r1, u8 r2) {
  struct Weapon* w = (struct Weapon*)AllocEntityFirst(gWeaponHeaderPtr);
  if (w != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_ROD) {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_SOUL_LANCHER);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[0];
      (w->s).palID = gWeaponPalIDs[0];
    } else {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_SOUL_LANCHER);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[1];
      (w->s).palID = gWeaponPalIDs[1];
    }
    (w->s).unk_28 = &z->s;
    (w->s).work[0] = r1;
    (w->s).work[1] = r2;
    (&w->unk_b4)->props[1][1] = ((&z->unk_b4)->status).element;
  }
  return w;
}

INCASM("asm/weapon/soul_launcher.inc");

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 1,
      unk_04 : 0x0D,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00200000,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
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
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
};

// --------------------------------------------

void SoulLauncher_Init(struct Weapon* w);
void SoulLauncher_Update(struct Weapon* w);
void SoulLauncher_Die(struct Weapon* w);

// clang-format off
const WeaponRoutine gSoulLauncherRoutine = {
    [ENTITY_INIT] =      SoulLauncher_Init,
    [ENTITY_UPDATE] =    SoulLauncher_Update,
    [ENTITY_DIE] =       SoulLauncher_Die,
    [ENTITY_DISAPPEAR] = DeleteWeapon,
    [ENTITY_EXIT] =      (WeaponFunc)DeleteEntity,    
};
// clang-format on

const s32 s32_ARRAY_0836159c[4] = {-0x200, -0x100, 0x100, 0x200};
