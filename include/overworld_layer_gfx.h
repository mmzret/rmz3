#ifndef GUARD_RMZ3_OW_LAYER_GFX_H
#define GUARD_RMZ3_OW_LAYER_GFX_H

#include "chunk.h"
#include "metatile.h"

struct MetatileMap;

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

void FUN_08006bb4(struct LayerGraphic* l, struct Coord* c, u32* bgmap, struct MetatileMap* mm);
void FUN_08006a10(struct LayerGraphic* l, struct Coord* c, u32* bgmap, struct MetatileMap* mm);
void FUN_08006ae0(struct LayerGraphic* l, struct Coord* c, u32* bgmap, struct MetatileMap* mm);
void FUN_080050b0(struct LayerGraphic* l, struct Coord* c, u32 mapAddr);
void FUN_08005a70(struct LayerGraphic* l, struct Coord* c, u32 mapAddr);

void ResetLayerGraphic(struct LayerGraphic* p, struct Coord* c, u16* _, Metatile* tiledata, Screen* chunks, const struct ChunkMap* map);

#endif  // GUARD_RMZ3_OW_LAYER_GFX_H
