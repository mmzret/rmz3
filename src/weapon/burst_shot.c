#include "collision.h"
#include "global.h"
#include "weapon.h"

// A firework of Burst shot

static const struct Collision sCollision = {
  kind : DDP,
  layer : LAYER_ALLY,
  special : HALFABLE,
  damage : 2,
  unk_04 : 0x06,
  element : 0x00,
  nature : BODY_NATURE_B1,
  comboLv : 2,
  hitzone : 0,
  unk_0a : 0x00,
  remaining : 0,
  unk_0c : 0x00000008,
  range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
};

// --------------------------------------------

void BurstShot_Init(struct Weapon* w);
void BurstShot_Update(struct Weapon* w);
void BurstShot_Die(struct Weapon* w);

// clang-format off
const WeaponRoutine gBurstShotRoutine = {
    [ENTITY_INIT] =      BurstShot_Init,
    [ENTITY_MAIN] =      BurstShot_Update,
    [ENTITY_DIE] =       BurstShot_Die,
    [ENTITY_DISAPPEAR] = DeleteWeapon,
    [ENTITY_EXIT] =      (WeaponFunc)DeleteEntity,    
};
// clang-format on

// --------------------------------------------

void MenuExit_BurstShot(struct Weapon* w) {
  struct Zero* z = (struct Zero*)(w->s).unk_28;
  if (((&z->unk_b4)->status).element != ELEMENT_FLAME || (z->unk_136 & (1 << 0))) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    (w->body).status = 0;
    (w->body).prevStatus = 0;
    (w->body).invincibleTime = 0;
    (w->s).flags &= ~COLLIDABLE;
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
  }
}

struct Weapon* CreateBurstShot(struct Zero* z, struct Weapon* p, u8 n, s32 x, s32 y) {
  struct Weapon* w = (struct Weapon*)AllocEntityFirst(gWeaponHeaderPtr);
  if (w != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_BUSTER) {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_BURST_SHOT);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[0];
      (w->s).palID = gWeaponPalIDs[0];
    } else {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_BURST_SHOT);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[1];
      (w->s).palID = gWeaponPalIDs[1];
    }
    (w->s).unk_28 = &z->s;
    (w->s).unk_2c = &p->s;
    (w->s).coord = (p->s).coord;
    (w->s).work[0] = n;
    (w->s).work[1] = 0;
    (w->s).coord.x += x;
    (w->s).coord.y += y;
  }
  return w;
}

INCASM("asm/weapon/burst_shot.inc");

static const motion_t sMotions[3] = {
    MOTION(DM083_BURST_SHOT_FIREWORK, 0x00),
    MOTION(DM083_BURST_SHOT_FIREWORK, 0x01),
    MOTION(DM083_BURST_SHOT_FIREWORK, 0x02),
};
