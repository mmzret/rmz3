#ifndef GUARD_RMZ3_VFX_H
#define GUARD_RMZ3_VFX_H

#include "constants/constants.h"
#include "entity.h"
#include "types.h"

// For VFX 16
// e.g. u8_ARRAY_08365c14
struct SlashedEnemy {
  motion_t m;
  u8 unk_02[2];
  Coords16 c;
  Coords16 d;
  Coords16 unk_coord_0c;
  Coords16 unk_10;
  u16 unk_14[2];
  u8 _[4];
};  // 28 bytes

typedef void (*VFXFunc)(struct VFX*);
typedef VFXFunc VFXRoutine[5];
extern const VFXRoutine* const gVFXFnTable[85];

#define INIT_VFX_ROUTINE(entity, entityID) INIT_RENDER_ENTITY(1, gVFXFnTable, entity, entityID)
#define SET_VFX_ROUTINE(entity, modeID) SET_ENTITY_ROUTINE(gVFXFnTable, entity, modeID)

void DeleteVFX(struct Entity* p);

Entity* CreateSmoke(u8 kind, Coords32* c);
void CreateParticle(Coords32* c, u8 action, bool8 isRight);
void oz_080b3820(Coords32* omegaCoord, bool8 isRight);
void CreateWallDust(Coords32* c, bool8 isRight);
struct VFX* CreateRipple(struct Zero* z, bool8 outOfSea);
Entity* CreateEmotionBubble(u8 kind, Coords32* target, Coords32* c);
struct VFX* CreateCopyXIcon(struct Zero* z, Coords32* c, u8 n);
Entity* CreateExlifeIndicator(u8 extraLife);
Entity* CreateMissionAlert(u8 kind);
struct VFX* CreateSlashedEnemy(Coords32* c, const struct SlashedEnemy* data, u8 r2, u8 r3);
Entity* FUN_080bfce8(Coords32* c, u8 r1);
Entity* CreateBossExplosion(Entity* boss, Coords32* c);
void CreateVFX31_1(s32 x, s32 y);
void CreateVFX31_2(s32 x, s32 y);
void FUN_080b81a0(Entity* e, Coords32* c, motion_t* motions, u8 len);
void FUN_080b7ffc(Entity* e, Coords32* c, motion_t* motions, u8 len);

struct ZChargeEffect;
struct ZChargeEffect* CreateChargeEffect(Player* z, struct ZChargeEffect* q, bool8 isSubWeapon);

#endif  // GUARD_RMZ3_VFX_H
