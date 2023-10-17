#include "collision.h"
#include "global.h"
#include "weapon.h"

#define PROP (w->props.common)

static const struct Collision sCollisions[2];
static const motion_t sMotions[8];

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 10,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 1,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
};

void ReflectLaser_Init(struct Weapon* w);
void ReflectLaser_Update(struct Weapon* w);
void ReflectLaser_Die(struct Weapon* w);

// clang-format off
const WeaponRoutine gReflectLaserRoutine = {
    [ENTITY_INIT] =      ReflectLaser_Init,
    [ENTITY_UPDATE] =    ReflectLaser_Update,
    [ENTITY_DIE] =       ReflectLaser_Die,
    [ENTITY_DISAPPEAR] = DeleteWeapon,
    [ENTITY_EXIT] =      (WeaponFunc)DeleteEntity,    
};
// clang-format on

NON_MATCH void MenuExit_ReflectLaser(struct Weapon* w) {
#if MODERN
  struct Zero* z = (struct Zero*)(w->s).unk_28;
  if ((((&z->unk_b4)->status).element != 0) || (z->unk_136 & (1 << 0))) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    (w->body).status = 0;
    (w->body).prevStatus = 0;
    (w->body).invincibleTime = 0;
    (w->s).flags &= ~COLLIDABLE;
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
  }
#else
  INCCODE("asm/wip/MenuExit_ReflectLaser.inc");
#endif
}

struct Weapon* CreateReflectLaser(struct Zero* z, struct Entity* p, u8 n) {
  struct Weapon* w = (struct Weapon*)AllocEntityFirst(gWeaponHeaderPtr);
  if (w != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_BUSTER) {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_REFLECT_LASER);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[0];
      (w->s).palID = gWeaponPalIDs[0];
    } else {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_REFLECT_LASER);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[1];
      (w->s).palID = gWeaponPalIDs[1];
    }
    (w->s).unk_28 = &z->s;
    (&PROP)->z = (struct Zero*)p;
    (w->s).work[0] = n;
    (w->s).work[1] = 0;
  }
  return w;
}

#if MODERN == 0
NAKED static struct Weapon* unused_CreateReflectLaser(struct Zero* z, struct Entity* p, void* r2, u8 r3, u8 r4) { INCCODE("asm/unused/unused_CreateReflectLaser.inc"); }
#endif

INCASM("asm/weapon/reflect_laser.inc");

// clang-format off
static const motion_t sMotions[8] = {
    MOTION(DM080_SEMI_BUSTER, 0x00),
    MOTION(DM080_SEMI_BUSTER, 0x00),
    MOTION(DM080_SEMI_BUSTER, 0x00),
    MOTION(DM080_SEMI_BUSTER, 0x01),
    MOTION(DM080_SEMI_BUSTER, 0x01),
    MOTION(DM080_SEMI_BUSTER, 0x02),
    MOTION(DM080_SEMI_BUSTER, 0x02),
    MOTION(DM080_SEMI_BUSTER, 0x02),
};
// clang-format on

#undef PROP
