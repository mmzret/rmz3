#ifndef GUARD_RMZ3_ZERO_H
#define GUARD_RMZ3_ZERO_H

#include "collision.h"
#include "common.h"
#include "entity.h"
#include "gba/gba.h"
#include "types.h"

#if MODERN
#define SET_PLAYER_ROUTINE(player, routine)                                            \
  {                                                                                    \
    *(u32*)(&((player)->s).mode[0]) = routine;                                         \
    ((player)->s).onUpdate = (ZeroFunc)((*gZeroFnTable[(((player)->s).id)])[routine]); \
  }
#else
#define SET_PLAYER_ROUTINE(player, routine)        \
  {                                                \
    u32 tbl, id;                                   \
    ZeroFunc** r;                                  \
    tbl = (u32)gZeroFnTable;                       \
    id = (((player)->s).id) << 2;                  \
    r = (ZeroFunc**)(tbl + id);                    \
                                                   \
    *(u32*)((player)->s).mode = routine;           \
    ((player)->s).onUpdate = (void*)(*r)[routine]; \
  }
#endif

#if MODERN
#define INIT_PLAYER_ROUTINE(player, playerID)                                           \
  {                                                                                     \
    ((player)->s).id = playerID;                                                        \
    ((player)->s).onUpdate = (void*)((*gZeroFnTable[(((player)->s).id)])[ENTITY_INIT]); \
  }
#else
#define INIT_PLAYER_ROUTINE(player, playerID)          \
  {                                                    \
    u32 tbl;                                           \
    ZeroFunc** r;                                      \
    tbl = (u32)gZeroFnTable;                           \
    ((player)->s).id = playerID;                       \
                                                       \
    r = (ZeroFunc**)(tbl + (playerID << 2));           \
    ((player)->s).onUpdate = (void*)(*r)[ENTITY_INIT]; \
  }
#endif

enum ZeroGround {
  GROUND_IDLE,
  GROUND_WALK,
  GROUND_DASH,
};

typedef bool8 (*WeaponOKFunc)(struct Zero*);

#define HEAD ((z->unk_b4).status.head)
#define BODY(z) (((&z->unk_b4)->status).body)
#define FOOT ((z->unk_b4).status.foot)
#define SATELITES (((&z->unk_b4)->status).asset.satelites)
#define SATELITE_1 (((&z->unk_b4)->status).asset.satelites[0])
#define SATELITE_2 (((&z->unk_b4)->status).asset.satelites[1])

extern struct Zero* pZero;
extern struct Zero* pZero2;

extern const struct PlttData gZeroPalettes[9][SLOT_4BPP];
extern const struct PlttData gZeroShadowPalettes[9][SLOT_4BPP];
extern const struct PlttData gZeroShadowDashPalette[9][SLOT_4BPP];
extern const ZeroRoutine* const gZeroFnTable[PLAYER_ENTITY_COUNT];
extern const ZeroFunc PTR_ARRAY_0835e624[4];

extern const ZeroRoutine gFefnirRoutine;
extern const ZeroRoutine gPhantomMiniRoutine;
extern const ZeroRoutine gHarpuiaRoutine;
extern const ZeroRoutine gCopyXMiniRoutine;
extern const ZeroRoutine gLeviathanRoutine;
extern const ZeroRoutine gZeroMiniRoutine;

extern const struct Collision gZeroCollisions[12];

void ClearZeroStatus(struct ZeroStatus* p);
void ClearZeroStatusHard(struct ZeroStatus* p);
void ClearZeroStatusUltimate(struct ZeroStatus* p);
void FUN_080321d4(struct ZeroStatus* p);

void SaveZeroStatus(struct Zero* z, struct ZeroStatus* status);
void CopyZeroStatus(struct Zero* z, struct ZeroStatus* status);

u8 GetZeroColor(struct Zero* z);

u16 FUN_080101a8(void);
void InitPlayerHeader(struct EntityHeader* h, struct Zero* p, s16 len);
struct Zero* AllocPlayer(void);
struct Zero* AllocPlayer2(void);
void RemovePlayer(struct Zero* p);
void LoadZeroPalette(struct Entity* _, u32 color);
void LoadShadowDashPalette(struct Zero* _, u32 color);
bool8 UseSubtank(struct Zero* z);
bool8 IsDoubleHP(struct Zero* z);
u8 GetMaxHP(struct Zero* z);
u8 getMaxHP1x(struct Zero* z);
bool8 AddECrystal(struct Zero* z, u16 amount);
bool8 incrementSubtankHP(struct Zero* z);
u8 makeZeroFaster(struct Zero* z, u8 val);
u8 CountRodButton(struct Zero* z, bool8 isSubWeapon);
u8 CountButtonMashing(struct Zero* z);
void ResetZeroInput(struct Zero* z);
void resetSateliteElfPosition(struct Zero* z);
u16 GetDefaultMotion(struct Zero* z);
u8 CalcBusterBonus(struct Zero* z);
s16 CalcMaxWalkSpeed(struct Zero* z);
void FUN_080322c4(struct ZeroStatus* d);
bool8 IsButtonMashed(struct Zero* z);

void Zero_Init(struct Zero* z);
void Zero_Update(struct Zero* z);
void Zero_Die(struct Zero* z);
void Zero_Disappear(struct Zero* z);

void HandlePlayerInput_Ground(struct Zero* z);
void HandlePlayerInput_Air(struct Zero* z);
void HandlePlayerInput_Wall(struct Zero* z);
void HandlePlayerInput_Ladder(struct Zero* z);
void HandlePlayerInput_Damaged(struct Zero* z);
void HandlePlayerInput_Door2D(struct Zero* z);
void HandlePlayerInput_Door3D(struct Zero* z);
void HandlePlayerInput_Mode7(struct Zero* z);
void HandlePlayerInput_Float(struct Zero* z);
void HandlePlayerInput_Talk(struct Zero* z);
void HandlePlayerInput_Teleport(struct Zero* z);
void HandlePlayerInput_Cyber(struct Zero* z);

// ------------------------------------------------------------------------------------------------------------------------------------

void zeroNeutral2(struct Zero* z);
void zeroAir2(struct Zero* z);
void zeroWall2(struct Zero* z);
void zeroLadder2(struct Zero* z);
void zeroDamaged(struct Zero* z);
void zeroKnockBack(struct Zero* z);
void FUN_0802c010(struct Zero* z);
void zeroDoor2D(struct Zero* z);
void zeroDoor3D(struct Zero* z);
void zeroMode7(struct Zero* z);
void zeroFloat(struct Zero* z);
void zeroTalk(struct Zero* z);
void zeroTeleport(struct Zero* z);
void zeroCyberDoor(struct Zero* z);

// ------------------------------------------------------------------------------------------------------------------------------------

void ZeroAttack_Ground(struct Zero* z);
void zeroAttack(struct Zero* z);
void onSaber_GroundIdle(struct Zero* z);
void charge_saber_ground(struct Zero* z);
void recoilAttack(struct Zero* z);
void shieldAttack(struct Zero* z);
void shield_throw(struct Zero* z);
void shield_0802e1c8(struct Zero* z);
void zero_shield_0802e268(struct Zero* z);
void zeroAirAtk(struct Zero* z);
void ZeroAttack_Air(struct Zero* z);
void ZeroAttack_Wall(struct Zero* z);
void ZeroAttack_Ladder(struct Zero* z);
void zeroWallAtk(struct Zero* z);
void zeroLadderAtk(struct Zero* z);

bool8 zero_08026f90(struct Zero* z, const struct Rect* p);
s16 CalcDx(struct Zero* z);
metatile_attr_t PushoutByFloor1(struct Zero* z, const struct Rect* r1, bool8 r2);
metatile_attr_t PushoutByCeiling(struct Zero* z, const struct Rect* r1, bool8 r2);
metatile_attr_t PushoutByCeilingOnLadder(struct Zero* z, const struct Rect* r1, bool8 r2);
metatile_attr_t GetWallMetatileAttr(struct Zero* z, const struct Rect* r1, bool8 _ UNUSED);
u8 ladder_08026bb0(struct Zero* z, const struct Rect* range, bool8 _);
u8 TryLadderDown(struct Zero* z, const struct Rect* p, bool8 _);
bool8 TryGroundDash(struct Zero* z, const struct Rect* range, bool8 _);
u8 TryLadderUp(struct Zero* z, const struct Rect* p, bool8 r2);
metatile_attr_t IsOnSoftPlatform(struct Zero* z, const struct Rect* p, bool8 r2);
s16 getFallAcceleration(struct Zero* z);
s16 calcMaxFallSpeed(struct Zero* z);
metatile_attr_t PushoutWallX(struct Zero* z, const struct Rect* p, bool8 r2);
u8 TryContinueLadderDown(struct Zero* z, const struct Rect* p, bool8 r2);
bool8 PushoutByBorder(struct Zero* z, const struct Rect* p, bool8 r2);
bool8 CanWallSlide(struct Zero* z, const struct Rect* p, bool8 _);
bool8 IsForwardPressed(struct Zero* z, const struct Rect* p, bool8 _);
bool8 IsZeroAgainstWall(struct Zero* z, const struct Rect* p, bool8 _);
u8 RecoilFromHazards(struct Zero* z, const struct Rect* range);
u8 RecoilFromFloor(struct Zero* z, const struct Rect* range);
metatile_attr_t PushoutByFloor2(struct Zero* z, const struct Rect* p, bool8 r2);
bool8 IsElfUsed(struct Zero* z, cyberelf_t elfID);
bool8 isElfUsed_2(struct Zero* z, cyberelf_t elfID);
metatile_attr_t _pushoutHazardY(struct Zero* z, s32 x, s32 y, struct Coord* c);
s16 GetDashSpeed(struct Zero* z);
bool8 IsAttackOK(struct Zero* z, weapon_t* w);
void KeepMotion(struct Zero* z, motion_t m);
void FUN_08032504(struct Zero* z, motion_t m);
void FUN_0803267c(struct Zero* z, motion_t m);
void skipEventScene(struct Zero* z, struct ZeroStatus* status);
void InstantlyKilling(struct Zero* z);
s16 getWallFallSpeed(struct Zero* z);
void CheckZeroHazard(struct Zero* z);
void setStageElfFlags(struct Zero* z);
bool8 Is1000Slash(struct Zero* z);
void zero_08032724(struct Zero* z);
void SetDisableArea(struct Zero* z, s32 left, s32 top, s32 right, s32 bottom);
void HandlePlayerInput(struct Zero* z);

#endif  // GUARD_RMZ3_ZERO_H
