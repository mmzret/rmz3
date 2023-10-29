#ifndef GUARD_RMZ3_STAGE_H
#define GUARD_RMZ3_STAGE_H

#include "common.h"
#include "entity.h"
#include "gba/gba.h"
#include "types.h"

typedef u32 (*AreaChecker)(struct Coord*);

/*
  マップ上のEntityの設計図
  ただし、どこに生成するかという座標の情報は別(同じEntityをいろんな座標に生成したいというモチベがあるため)
*/
struct EntityTemplate {
  u8 unk_00;
  u8 kind;  // Entity.type
  u8 id;
  u8 work0;
  u8 work1;
  u8 unk_05;
  u8 unk_06;
  u8 unk_07;
};  // 8 bytes

/*
  EntityTemplate をどこに生成するかを表す
  EntityTemplateCoord を 配列にする際は、X座標で昇順(小->大)に並ぶ
*/
struct EntityTemplateCoord {
  s32 x;
  s16 y;

  /*
    StageEntityManager.template のインデックス
    つまりどの EntityTemplate かを表すID
  */
  u16 idx;
};  // 8 bytes

/*
  Entityのうち、Init関数でLoadGraphicしないものを表す
  例えば、雑魚敵みたいな複数同じEntityが存在しうるやつとかが該当する？
*/
struct PreloadEntity {
  motion_id_t id;
  u8 habitat;
  u16 tileBase;
  u8 palID;
  u8 unk_05;
  u8 unk_06;
  u8 unk_07;
};  // 8 bytes

struct StageEntity {
  struct StageEntity* next;
  struct Entity* e;

  /*
    StageEntityManager.templateCoord のインデックス
    例えばレジスタンスベースなら、 templateCoord は 0x0834c1b4 なので
    idx が 1 なら 処理(0x8017c58)では 0834c1bc を指す
  */
  s16 idx;
  u16 flag;
};  // 12 bytes

/*
  0x0202fb90
  雑魚敵やNPCといった、画面内に存在する、画面外に生成されると消えるEntity(揮発性Entity)を管理する
*/
struct StageEntityManager {
  u32 entityEnabled[32];  // 1024個のbitfield
  void* unk_080;
  struct StageEntity unk_084[32];
  struct StageEntity* list;
  struct StageEntity* free;
  bool16 isMissionDone;
  u16 unk_20e;
  u8 stageID;
  u8 area;  // Stage area
  u16 remaining;
  const struct EntityTemplate* template;            // 0x08347954 のテーブルのエントリのどれかが入る
  const struct EntityTemplateCoord* templateCoord;  // sStageEntityTemplateCoord のテーブルのエントリのどれかが入る
  s32 dynamicEntityRange[2];                        // 0: StartY(top),  1: EndY(bottom) (for sStagePreloadEntities)

  /*
    EntityTemplateCoord のエントリで画面左端より左側(つまり左過ぎて画面外にあるもの)の個数
    UpdateStageEntities ではインデックスがstart以降、つまり画面左端より右側に存在する EntityTemplateCoord に対して Entity生成処理を行なっていく
  */
  u16 start;
  u8 unk_226[4];
  u16 unk_22a;
  u32 _;
};  // 560 bytes

extern const struct EntityTemplate gStage0Entity[2];
extern const struct EntityTemplate gSpaceCraftEntity[26];
extern const struct EntityTemplate gVolcanoEntity[51];
extern const struct EntityTemplate gOceanEntity[31];
extern const struct EntityTemplate gRepairFactoryEntity[38];
extern const struct EntityTemplate gOldLifeSpaceEntity[37];
extern const struct EntityTemplate gMissileFactoryEntity[35];
extern const struct EntityTemplate gTwilightDesertEntity[31];
extern const struct EntityTemplate gAnatreForestEntity[34];
extern const struct EntityTemplate gIceBaseEntity[38];
extern const struct EntityTemplate gAreaX2Entity[36];
extern const struct EntityTemplate gEnergyFacilityEntity[51];
extern const struct EntityTemplate gSnowyPlainsEntity[27];
extern const struct EntityTemplate gSunkenLibraryEntity[37];
extern const struct EntityTemplate gGiantElevatorEntity[41];
extern const struct EntityTemplate gSubArcadiaEntity[36];
extern const struct EntityTemplate gWeilLaboEntity[50];
extern const struct EntityTemplate gResistanceBaseEntity[64];

// --------------------------------------------

extern const struct PreloadEntity sStage0StaticTemplate[1];
extern const struct PreloadEntity gSpaceCraftStatic[8];
extern const struct PreloadEntity gVolcanoStatic[20];
extern const struct PreloadEntity gOceanStatic[17];
extern const struct PreloadEntity gRepairFactoryStatic[13];
extern const struct PreloadEntity gOldLifeSpaceStatic[15];
extern const struct PreloadEntity gMissileFactoryStatic[14];
extern const struct PreloadEntity gTwilightDesertStatic[13];
extern const struct PreloadEntity gAnatreForestStatic[16];
extern const struct PreloadEntity gIceBaseStatic[18];
extern const struct PreloadEntity gAreaX2Static[13];
extern const struct PreloadEntity gEnergyFacilityStatic[16];
extern const struct PreloadEntity gSnowyPlainsStatic[13];
extern const struct PreloadEntity gSunkenLibraryStatic[12];
extern const struct PreloadEntity gGiantElevatorStatic[19];
extern const struct PreloadEntity gSubArcadiaStatic[14];
extern const struct PreloadEntity gWeilLaboStatic[13];
extern const struct PreloadEntity gResistanceBaseStatic[41];

// --------------------------------------------

extern const struct EntityTemplateCoord gStage0EntityCoord[2];
extern const struct EntityTemplateCoord gSpaceCraftEntityCoord[68];
extern const struct EntityTemplateCoord gVolcanoEntityCoord[69];
extern const struct EntityTemplateCoord gOceanEntityCoord[86];
extern const struct EntityTemplateCoord gRepairFactoryEntityCoord[73];
extern const struct EntityTemplateCoord gOldLifeSpaceEntityCoord[159];
extern const struct EntityTemplateCoord gMissileFactoryEntityCoord[82];
extern const struct EntityTemplateCoord gTwilightDesertEntityCoord[59];
extern const struct EntityTemplateCoord gAnatreForestEntityCoord[56];
extern const struct EntityTemplateCoord gIceBaseEntityCoord[107];
extern const struct EntityTemplateCoord gAreaX2EntityCoord[88];
extern const struct EntityTemplateCoord gEnergyFacilityEntityCoord[118];
extern const struct EntityTemplateCoord gSnowyPlainsEntityCoord[78];
extern const struct EntityTemplateCoord gSunkenLibraryEntityCoord[99];
extern const struct EntityTemplateCoord gGiantElevatorEntityCoord[65];
extern const struct EntityTemplateCoord gSubArcadiaEntityCoord[62];
extern const struct EntityTemplateCoord gWeilLaboEntityCoord[68];
extern const struct EntityTemplateCoord gResistanceBaseEntityCoord[241];

// --------------------------------------------

extern struct StageEntityManager gStageEntityManager;
extern const AreaChecker gAreaCheckers[STAGE_COUNT];

// --------------------------------------------

void InitStageEntityManager(u8 stageID, bool8 missionDone);
struct Entity* CreateStageEntity(u8 kind, u8 id);
void DeleteStageEntity(struct CollidableEntity* e);
void FUN_080186c8(u32 top, u32 bottom);

#endif  // GUARD_RMZ3_STAGE_H
