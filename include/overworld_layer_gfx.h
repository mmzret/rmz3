#ifndef GUARD_RMZ3_OW_LAYER_GFX_H
#define GUARD_RMZ3_OW_LAYER_GFX_H

#include "chunk.h"
#include "metatile.h"

// 地形レイヤのMetatileのマップデータ (ステージ全体分)
//   MetatileMap[0]:            ステージ全体の横幅(メタタイル単位)
//   MetatileMap[1]:            使われてない(Alignment?)
//   MetatileMap[2..89099]:     ステージ全体のメタタイルIDのマップデータ (89100個分, つまり横幅*縦幅分) = (metatile_id_t map[89100/width16][width16])
//   MetatileMap[89100..89101]: 使われてない(CpuFastSet のために32バイトアラインメントされる必要があるためそのパディング？)
typedef u16 MetatileMap[2 + 89100 + 2];

// StageLayer構造体のうち、BGマップへの描画に必要な情報
struct LayerGraphic {
  struct Coord c;
  u16 bgofs[2];  // BGOFS(x, y) 参照: 08006dac
  // 以下のポインタは 全部ROMのアドレスを指す読み取り専用のもの
  Metatile* tiledata;          // 02002240, 020022c8, e.g. 086f9fec, メタタイルID を GBAのタイルマップx4 への変換テーブル (4bppデータとかではない)
  Screen* chunks;              // chunks[ChankID] -> 15x10のメタタイルIDの配列
  const struct ChunkMap* map;  // このステージレイヤ　のチャンクマップ (ステージ全体分)
};  // 24 bytes

void UpdateBGOFS(struct LayerGraphic* p, struct BgOfs* bgofs);

void FUN_08006bb4(struct LayerGraphic* l, struct Coord* c, u32* bgmap, MetatileMap* mm);
void FUN_08006a10(struct LayerGraphic* l, struct Coord* c, u32* bgmap, MetatileMap* mm);
void FUN_08006ae0(struct LayerGraphic* l, struct Coord* c, u32* bgmap, u16* tilemap);
void FUN_080050b0(struct LayerGraphic* l, struct Coord* c, u32 mapAddr);
void FUN_08005a70(struct LayerGraphic* l, struct Coord* c, u32 mapAddr);

void ResetLayerGraphic(struct LayerGraphic* p, struct Coord* c, u16* _, Metatile* tiledata, Screen* chunks, const struct ChunkMap* map);

#endif  // GUARD_RMZ3_OW_LAYER_GFX_H
