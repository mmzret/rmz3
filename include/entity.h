#ifndef GUARD_RMZ3_ENTITY_H
#define GUARD_RMZ3_ENTITY_H

#include "entity/macros.h"
//
#include "entity/entity.h"
#include "entity/player.h"
#include "entity_manager.h"
#include "renderer.h"
//
#include "player_util.h"

extern struct EntityHeader* pCurEntityHeader;
extern struct EntityHeader* gZeroHeaderPtr;
extern struct EntityHeader* gWeaponHeaderPtr;
extern struct EntityHeader* gBossHeaderPtr;
extern struct EntityHeader* gSolidHeaderPtr;
extern struct EntityHeader* gVFXHeaderPtr;
extern struct EntityHeader* gProjectileHeaderPtr;
extern struct EntityHeader* gEnemyHeaderPtr;
extern struct EntityHeader* gElfHeaderPtr;

extern Player gPlayers[1];
extern Weapon gWeapons[24];
extern struct Boss gBosses[5];
extern struct Enemy gEnemies[18];
extern struct Projectile gProjectiles[24];
extern struct VFX gVFXs[64];
extern struct Solid gSolids[22];
extern CyberElf gElfEntities[16];
extern u8 gEntityIDGenerator;

void _StartEntityListIteration(struct EntityHeader* h);
static inline struct Entity* StartEntityListIteration(struct EntityHeader* h) {
  _StartEntityListIteration(h);
  return h->cur = (h->cur)->next;  // この時点で h->cur = &h->tail なので、 (h->cur)->next で h->head が取れる
}

void _GetEntityList(struct EntityHeader* h);
static inline struct Entity* GetEntityList(struct EntityHeader* h) {
  _GetEntityList(h);
  return h->cur = (h->cur)->next;  // この時点で h->cur = &h->tail なので、 (h->cur)->next で h->head が取れる
}

static inline struct Entity* GetNextEntity(struct EntityHeader* h) { return h->cur = (h->cur)->next; }

void* AllocEntityFirst(struct EntityHeader* h);
void* AllocEntityLast(struct EntityHeader* h);
void DeleteEntity(struct Entity* p);
void DeleteEntityEx(struct EntityHeader* h, struct Entity* z);
void UpdateEntities(struct EntityHeader* h);
void UpdateHazardEntities(struct EntityHeader* h);
void RunDamageEffect(struct EntityHeader* h);
void RegisterHitboxes(struct EntityHeader* h);

void DrawEntity(struct EntityHeader* h, Renderer* r);
void DrawCollidableEntity(struct EntityHeader* h, Renderer* r);
void DrawWeapon(Renderer* r);
struct Entity* GetNearestEntity(struct EntityHeader* h, Coords32* c);

u16 countSpecificEntities1(struct EntityHeader* h, u8 id);
u16 countSpecificEntities2(struct EntityHeader* h, u8 id, u8 r2, u8 r3);

void UpdateSpawnManager(Coords32* viewport);

void InitNonAffineSprite(struct Sprite* s, struct MetaspriteHeader* sprites, Coords32* c);
void InitRotatableSprite(struct Sprite* s, struct MetaspriteHeader* sprites, Coords32* c);
void InitScalerotSprite1(struct Sprite* s, struct MetaspriteHeader* sprites, Coords32* c);
void InitScalerotSprite2(struct Sprite* s, struct MetaspriteHeader* sprites, Coords32* c);

void RotateSprite(struct Sprite* s, s32 angle);
void ScalerotSprite(struct Sprite* s, s32 angle);

#if MODERN
#define ScalerotSprite2 ScalerotSprite
#else
void ScalerotSprite2() __attribute__((alias("ScalerotSprite")));
#endif

void UpdateEntityPaletteID(struct Entity* p);
void PaintEntityWhite(struct Entity* p);

bool32 isKilled(struct Entity* p);
#define IsDead(p) (isKilled((struct Entity*)(p)))

u8 _GetEntityPaletteID(struct Entity* p);
static inline u8 GetEntityPaletteID(void* enti) { return _GetEntityPaletteID((struct Entity*)enti); }

#endif  // GUARD_RMZ3_ENTITY_H
