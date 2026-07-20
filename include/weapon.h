#ifndef GUARD_RMZ3_WEAPON_H
#define GUARD_RMZ3_WEAPON_H

#include "collision.h"
#include "constants/constants.h"
#include "entity.h"
#include "gba/gba.h"
#include "zero.h"

typedef void (*WeaponFunc)(Weapon*);
typedef WeaponFunc WeaponRoutine[5];
extern const WeaponRoutine* const gWeaponFnTable[WEAPON_MOVE_COUNT];

#define INIT_WEAPON_ROUTINE(entity, entityID) INIT_ENTITY_ROUTINE(gWeaponFnTable, entity, entityID)
#define SET_WEAPON_ROUTINE(entity, modeID) SET_ENTITY_ROUTINE(gWeaponFnTable, entity, modeID)

extern const struct Collision gSaberGeneralCollisions[2];
extern const struct Collision* const* const gSaberCollisions[25];
extern const u8 gSaberElements[4];

extern u16 gLastWeaponElements[WEAPON_KINDS];
extern u16 gWeaponElements[WEAPON_KINDS];
extern const u16 gWeaponTileNum[WEAPON_KINDS];
extern const u8 gWeaponPalIDs[WEAPON_KINDS];

void DeleteWeapon(struct Entity* p);
void SetWeaponElement(u16 n, u16 val);
void KillAllWeapons(WeaponFunc fn);
u8 GetWeaponCharge(struct Zero* z, bool8 isSubWeapon);

Weapon* CreateBlizzardArrow(struct Zero* z, Coords32* c, u8 n, bool8 xflip);

void DeleteSaber(Weapon* w);
void DeleteFlyingShield(Object* p);

Weapon* CreateWeaponBuster(struct Zero* z, Coords32* c, u8 n, bool8 xflip, bool8 yflip);
Weapon* CreateWeaponSaber(struct Zero* z, u8 r1);
Weapon* CreateBuster(struct Zero* z, s32 x, s32 y, bool8 isDirRight);
struct Entity* CreateWeaponShieldGuard(struct Zero* z, u8 n);
Weapon* CreateWeaponRod(struct Zero* z);
struct Entity* CreateWeaponShieldFly(struct Zero* z, u8 n);
struct Entity* CreateSmashElec(struct Zero* z, Coords32* c, u8 leftOrRight);
Weapon* CreateThrowBlade(struct Zero* z, Weapon* w, bool8 isIce);
struct Entity* CreateSaberWave(struct Zero* z, Weapon* w, bool8 r2);
void CreateWeapon6(s32 x, s32 y);

u8 CalcBusterBonus(struct Zero* z);
u8 CalcSaberBonus(struct Zero* z);
u8 CalcRodBonus(struct Zero* z);
u8 CalcShieldBonus(struct Zero* z);

typedef struct {
  COLLISION_OBJECT_HDR;
  struct WeaponCommonProps {
    struct Zero* z;
    /*
      props[n][0]: 属性？
      props[n][1]: 攻撃力？
      props[n][2]: bit6: イレタスの効果が乗っているか
    */
    u8 props[2][8];
    u8 unk_c8[36];
  } props;  // props (56bytes, offset: 0xB4..)
} WeaponCommon;
static_assert(sizeof(WeaponCommon) == sizeof(Weapon));

#endif  // GUARD_RMZ3_WEAPON_H
