#ifndef GUARD_RMZ3_ENTITY_H
#define GUARD_RMZ3_ENTITY_H

#include "entity/boss.h"
#include "entity/elf.h"
#include "entity/enemy.h"
#include "entity/entity.h"
#include "entity/mapitem.h"
#include "entity/projectile.h"
#include "entity/solid.h"
#include "entity/vfx.h"
#include "entity/weapon.h"
#include "entity/widget.h"
#include "entity/zero.h"
#include "task.h"

// Entity.flags
#define DISPLAY (1 << 0)
#define FLIPABLE (1 << 1)
#define COLLIDABLE (1 << 2)
#define OAM_PRIO (1 << 3)  // このフラグがセットされていたらOAMの優先度に従う セットされてないなら優先度0扱い
// X_FLIP (1 << 4)
// Y_FLIP (1 << 5)
#define AFFINE (1 << 6)
#define SCRIPTED (1 << 7)  // ScriptedEntityか

// Entity.flags2
#define SCALEROT (1 << 0)
#define ENTITY_FLAG2_B1 (1 << 1)  // 意味のないフラグに見える(どちらにしろScalerotSpriteするので)
#define DYNAMIC (1 << 2)
#define ENTITY_HAZARD (1 << 3)
#define ENTITY_FLAGS2_B4 (1 << 4)
#define PALETTE_FORCED (1 << 5)
#define ENTITY_FLAGS2_B6 (1 << 6)
#define STOPPED (1 << 7)

// EntityHeader linklist end
#define END (&h->next)

// size is 40 bytes
struct EntityHeader {
  struct Entity *arr;   // Entityの配列の先頭(固定)
  s16 type;             // Entityの種類
  s16 size;             // .arrの各要素(Entity)のサイズ
  s16 length;           // .arrの要素数(固定)
  s16 remaining;        // .lengthを初期値として徐々に減る
  struct Entity *last;  // fnを .arr のどのEntityまで処理したか だいたいnextを指す
  struct Entity *free;  // 空きエントリ
  struct Entity *next;
  struct Entity *prev;
  u32 unk[3];
};

// 0x02031370
struct EntityHeaders {
  struct EntityHeader zero;           // 02037c60
  struct EntityHeader weapon;         // 02038fd0
  struct EntityHeader boss;           // 0203b6d0
  struct EntityHeader zako;           // 03004b80
  struct EntityHeader projectile;     // 03003920
  struct EntityHeader vfx;            // 03005950
  struct EntityHeader solid;          // 0203a5f0
  struct EntityHeader item;           // 02037ef0
  struct EntityHeader elf;            // 02037020
  struct EntityHeader menuComponent;  // 0203bb50
};

extern struct Zero gZero;
extern struct EntityHeader *pCurEntityHeader;
extern struct EntityHeader *gZeroHeaderPtr;
extern struct EntityHeader *gWeaponHeaderPtr;
extern struct EntityHeader *gBossHeaderPtr;
extern struct EntityHeader *gSolidHeaderPtr;
extern struct EntityHeader *gVFXHeaderPtr;
extern struct EntityHeader *gProjectileHeaderPtr;
extern struct EntityHeader *gZakoHeaderPtr;
extern struct EntityHeader *gElfHeaderPtr;
extern struct EntityHeader *gMapItemHeaderPtr;
extern struct EntityHeader *gWidgetHeaderPtr;

extern struct Zero gZero;
extern struct Weapon gWeapons[24];
extern struct Boss gBosses[5];
extern struct Enemy gEnemies[18];
extern struct Projectile gProjectiles[24];
extern struct VFX gVFXs[64];
extern struct Solid gSolids[22];
extern struct MapItem gMapItems[10];
extern struct Elf gElfEntities[16];
extern struct Widget gWidgets[64];
extern u8 gEntityIDGenerator;

void InitEntityHeader(struct EntityHeader *h, s8 kind, struct Entity *arr, s16 size, s16 count);

void setCurProcessedEntityHeader(struct EntityHeader *h);
struct Entity *AllocEntityLast(struct EntityHeader *h);
struct Entity *AllocEntityFirst(struct EntityHeader *h);
void DeleteEntity(struct Entity *p);
void DeletePlayer(struct EntityHeader *h, struct Zero *z);
void UpdateEntities(struct EntityHeader *h);
void UpdateBlockingEntities(struct EntityHeader *h);
void ignoreEntityFn(struct EntityHeader *h);
void RunDamageEffect(struct EntityHeader *h);
void RegisterHitboxes(struct EntityHeader *h);

void DrawEntity(struct EntityHeader *h, struct TaskManager *r1);
void DrawCollidableEntity(struct EntityHeader *h, struct TaskManager *r1);
struct Entity *GetNearestEntity(struct EntityHeader *h, struct Coord *c);
void InitNonAffineMotion(struct Entity *e);
void InitRotatableMotion(struct Entity *e);
u16 countSpecificEntities1(struct EntityHeader *h, u8 id);
u16 countSpecificEntities2(struct EntityHeader *h, u8 id, u8 r2, u8 r3);

// おそらく画面内かどうかを判断してEntityを生成(or削除)する処理
void UpdateStageEntities(struct Coord *viewport);

void InitNonAffineSprite(struct Sprite *s, struct MetaspriteHeader *sprites, struct Coord *c);
void InitRotatableSprite(struct Sprite *s, struct MetaspriteHeader *sprites, struct Coord *c);
void InitScalerotSprite1(struct Sprite *s, struct MetaspriteHeader *sprites, struct Coord *c);
void InitScalerotSprite2(struct Sprite *s, struct MetaspriteHeader *sprites, struct Coord *c);

void RotateSprite(struct Sprite *s, s32 angle);
void ScalerotSprite(struct Sprite *s, s32 angle);
void UpdateEntityPaletteID(struct Entity *p);
void PaintEntityWhite(struct Entity *p);

#endif  // GUARD_RMZ3_ENTITY_H
