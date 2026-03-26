#ifndef GUARD_RMZ3_ENTITY_H
#define GUARD_RMZ3_ENTITY_H

#include "entity/macros.h"
//
#include "entity/boss.h"
#include "entity/elf.h"
#include "entity/enemy.h"
#include "entity/entity.h"
#include "entity/pickup.h"
#include "entity/projectile.h"
#include "entity/solid.h"
#include "entity/vfx.h"
#include "entity/weapon.h"
#include "entity/widget.h"
#include "entity/zero.h"
#include "task.h"

// size is 40 bytes
struct EntityHeader {
  struct Entity* arr;   // Entityの配列の先頭(固定)
  s16 type;             // Entityの種類
  s16 size;             // .arrの各要素(Entity)のサイズ
  s16 length;           // .arrの要素数(固定)
  s16 remaining;        // .lengthを初期値として徐々に減る
  struct Entity* last;  // fnを .arr のどのEntityまで処理したか だいたいnextを指す
  struct Entity* free;  // 空きエントリ
  struct Entity* next;
  struct Entity* prev;
  u32 unk[3];
};

extern struct Zero gZero;
extern struct EntityHeader* pCurEntityHeader;
extern struct EntityHeader* gZeroHeaderPtr;
extern struct EntityHeader* gWeaponHeaderPtr;
extern struct EntityHeader* gBossHeaderPtr;
extern struct EntityHeader* gSolidHeaderPtr;
extern struct EntityHeader* gVFXHeaderPtr;
extern struct EntityHeader* gProjectileHeaderPtr;
extern struct EntityHeader* gZakoHeaderPtr;
extern struct EntityHeader* gElfHeaderPtr;
extern struct EntityHeader* gPickupHeaderPtr;
extern struct EntityHeader* gWidgetHeaderPtr;

extern struct Zero gZero;
extern struct Weapon gWeapons[24];
extern struct Boss gBosses[5];
extern struct Enemy gEnemies[18];
extern struct Projectile gProjectiles[24];
extern struct VFX gVFXs[64];
extern struct Solid gSolids[22];
extern struct Pickup gPickups[10];
extern struct Elf gElfEntities[16];
extern struct Widget gWidgets[64];
extern u8 gEntityIDGenerator;

void InitEntityHeader(struct EntityHeader* h, s8 kind, struct Entity* arr, s16 size, s16 count);

void setCurProcessedEntityHeader(struct EntityHeader* h);
struct Entity* AllocEntityLast(struct EntityHeader* h);
struct Entity* AllocEntityFirst(struct EntityHeader* h);
void DeleteEntity(struct Entity* p);
void DeleteEntityEx(struct EntityHeader* h, struct Entity* z);
void UpdateEntities(struct EntityHeader* h);
void UpdateHazardEntities(struct EntityHeader* h);
void ignoreEntityFn(struct EntityHeader* h);
void RunDamageEffect(struct EntityHeader* h);
void RegisterHitboxes(struct EntityHeader* h);

void DrawEntity(struct EntityHeader* h, struct TaskManager* r1);
void DrawCollidableEntity(struct EntityHeader* h, struct TaskManager* r1);
struct Entity* GetNearestEntity(struct EntityHeader* h, struct Coord* c);
void InitNonAffineMotion(struct Entity* e);
void InitRotatableMotion(struct Entity* e);
u16 countSpecificEntities1(struct EntityHeader* h, u8 id);
u16 countSpecificEntities2(struct EntityHeader* h, u8 id, u8 r2, u8 r3);

// おそらく画面内かどうかを判断してEntityを生成(or削除)する処理
void UpdateStageEntities(struct Coord* viewport);

void InitNonAffineSprite(struct Sprite* s, struct MetaspriteHeader* sprites, struct Coord* c);
void InitRotatableSprite(struct Sprite* s, struct MetaspriteHeader* sprites, struct Coord* c);
void InitScalerotSprite1(struct Sprite* s, struct MetaspriteHeader* sprites, struct Coord* c);
void InitScalerotSprite2(struct Sprite* s, struct MetaspriteHeader* sprites, struct Coord* c);

void RotateSprite(struct Sprite* s, s32 angle);
void ScalerotSprite(struct Sprite* s, s32 angle);
void UpdateEntityPaletteID(struct Entity* p);
void PaintEntityWhite(struct Entity* p);
void FUN_0801779c(struct Entity* p);

bool32 isKilled(struct Entity* p);

#endif  // GUARD_RMZ3_ENTITY_H
