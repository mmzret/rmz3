#include "collision.h"
#include "global.h"
#include "weapon.h"

#define PROP (w->props.soul_launcher)

static const struct Collision sCollisions[2];

void MenuExit_SoulLauncher(struct Weapon* w) {
  struct Zero* z = (struct Zero*)(w->s).unk_28;
  if (((&PROP)->element != ((&z->unk_b4)->status).element) || (z->unk_136 & (1 << 2))) {
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
    (&PROP)->element = ((&z->unk_b4)->status).element;
  }
  return w;
}

INCASM("asm/weapon/soul_launcher.inc");

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

#undef PROP
