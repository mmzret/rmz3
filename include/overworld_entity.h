#ifndef GUARD_RMZ3_OW_ENTITY_H
#define GUARD_RMZ3_OW_ENTITY_H

#include "entity.h"
#include "gba/gba.h"
#include "types.h"

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

extern struct StageEntityManager gStageEntityManager;

void DeleteStageEntity(struct CollidableEntity* e);

#endif  // GUARD_RMZ3_OW_ENTITY_H
