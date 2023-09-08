#ifndef GUARD_RMZ3_WEAPON_H
#define GUARD_RMZ3_WEAPON_H

#include "collision.h"
#include "constants/constants.h"
#include "entity.h"
#include "gba/gba.h"
#include "zero.h"

#if MODERN
#define SET_WEAPON_ROUTINE(w, routine)                                   \
  {                                                                      \
    *(u32 *)(&(w->s).mode[0]) = routine;                                 \
    (w->s).onUpdate = (void *)((*gWeaponFnTable[((w->s).id)])[routine]); \
  }
#else
#define SET_WEAPON_ROUTINE(w, routine)       \
  {                                          \
    u32 tbl, id;                             \
    WeaponFunc **r;                          \
    tbl = (u32)gWeaponFnTable;               \
    id = ((w->s).id) << 2;                   \
    r = (WeaponFunc **)(tbl + id);           \
                                             \
    *(u32 *)(w->s).mode = routine;           \
    (w->s).onUpdate = (void *)(*r)[routine]; \
  }
#endif

#if MODERN
#define INIT_WEAPON_ROUTINE(w, weaponID)                                     \
  {                                                                          \
    (w->s).id = weaponID;                                                    \
    (w->s).onUpdate = (void *)((*gWeaponFnTable[((w->s).id)])[ENTITY_INIT]); \
  }
#else
#define INIT_WEAPON_ROUTINE(w, weaponID)         \
  {                                              \
    u32 tbl;                                     \
    WeaponFunc **r;                              \
    tbl = (u32)gWeaponFnTable;                   \
    (w->s).id = weaponID;                        \
                                                 \
    r = (WeaponFunc **)(tbl + (weaponID << 2));  \
    (w->s).onUpdate = (void *)(*r)[ENTITY_INIT]; \
  }
#endif

enum WeaponCharge {
  NO_CHARGE,
  SEMI_CHARGE,
  FULL_CHARGE,
};

extern const WeaponRoutine *const gWeaponFnTable[WEAPON_MOVE_COUNT];
extern const WeaponRoutine gBusterRoutine;
extern const WeaponRoutine gSaberRoutine;
extern const WeaponRoutine gShieldGuardRoutine;
extern const WeaponRoutine gRodRoutine;
extern const WeaponRoutine gShieldFlyRoutine;
extern const WeaponRoutine gSaberWaveRoutine;
extern const WeaponRoutine gWeapon6Routine;
extern const WeaponRoutine gReflectLaserRoutine;
extern const WeaponRoutine gSoulLauncherRoutine;
extern const WeaponRoutine gBurstShotRoutine;
extern const WeaponRoutine gBlizzardArrowRoutine;
extern const WeaponRoutine gThrowBladeRoutine;
extern const WeaponRoutine gShieldSweepRoutine;
extern const WeaponRoutine gWeapon13Routine;
// ...
extern const WeaponRoutine gSmashElecRoutine;
extern const WeaponRoutine gElecShieldSweepRoutine;
extern const WeaponRoutine gWeapon16Routine;

extern const struct Collision gSemiBulletCollisions[2];
extern const struct Collision gFullBulletCollisions[2];
extern const struct Collision gLaserShotCollisions[2];
extern const struct Collision gBurstShotCollisions[2];
extern const struct Collision gBlizzardArrowCollisions[2];
extern const struct Collision Hitbox_ARRAY_0835efc4[2];
extern const struct Collision gSaberGeneralCollisions[2];
extern const struct Collision *const *const gSaberCollisions[25];
extern const u8 gSaberElements[4];

extern u16 gLastWeaponElements[WEAPON_KINDS];
extern u16 gWeaponElements[WEAPON_KINDS];
extern const u16 gWeaponTileNum[WEAPON_KINDS];
extern const u8 gWeaponPalIDs[WEAPON_KINDS];

void DrawWeapon(struct TaskManager *p);
void DeleteWeapon(struct Weapon *w);
void SetWeaponElement(u16 n, u16 val);
void KillAllWeapons(WeaponFunc fn);
u8 GetWeaponCharge(struct Zero *z, bool8 isSubWeapon);

struct Weapon *CreateBlizzardArrow(struct Zero *z, struct Coord *c, u8 n, bool8 xflip);

void DeleteSaber(struct Weapon *w);

struct Weapon *CreateWeaponBuster(struct Zero *z, struct Coord *c, u8 n, bool8 xflip, bool8 yflip);
struct Weapon *CreateWeaponSaber(struct Zero *z, u8 r1);
struct Weapon *CreateBuster(struct Zero *z, s32 x, s32 y, bool8 isDirRight);
struct Weapon *CreateWeaponShieldGuard(struct Zero *z, u8 n);
struct Weapon *CreateWeaponRod(struct Zero *z);
struct Weapon *CreateWeaponShieldFly(struct Zero *z, u8 n);
struct Weapon *CreateSmashElec(struct Zero *z, struct Coord *c, u8 leftOrRight);
struct Weapon *CreateThrowBlade(struct Zero *z, struct Weapon *w, bool8 isIce);
struct Weapon *CreateSaberWave(struct Zero *z, struct Weapon *w, bool8 r2);

u8 CalcBusterBonus(struct Zero *z);
u8 CalcSaberBonus(struct Zero *z);
u8 CalcRodBonus(struct Zero *z);
u8 CalcShieldBonus(struct Zero *z);

void MenuExit_Buster(struct Weapon *w);
void MenuExit_ShieldGuard(struct Weapon *w);
void MenuExit_ShieldFly(struct Weapon *w);
void MenuExit_ReflectLaser(struct Weapon *w);
void MenuExit_SoulLauncher(struct Weapon *w);
void MenuExit_BurstShot(struct Weapon *w);
void MenuExit_BlizzardArrow(struct Weapon *w);
void MenuExit_ThrowBlade(struct Weapon *w);
void MenuExit_ShieldSweep(struct Weapon *w);
void MenuExit_Weapon13(struct Weapon *w);
void MenuExit_SaberSmash(struct Weapon *w);
void MenuExit_ShieldSweepElec(struct Weapon *w);

#endif  // GUARD_RMZ3_WEAPON_H
