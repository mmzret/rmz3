#ifndef GUARD_RMZ3_OW_CHUNK_H
#define GUARD_RMZ3_OW_CHUNK_H

#include "metatile.h"

// Chunk: 15x10 metatiles = 240x160 px = GBA display
// Metatile(のID)を 15x10ブロック集めて画面全体のグラフィックを表すようにしたもの
typedef metatile_id_t Chunk[15 * 10];

// ステージ全体 の　チャンクマップ
struct ChunkMap {
  // Layout
  u8 stride;       // チャンクマップの配列の1行あたりのチャンク数 (何かしらの理由でチャンクマップの長さを32の倍数にしないといけない理由があった？(昔は CpuFastSet を使っていたとか？))
  u8 nullChunkID;  // チャンクマップ上のチャンクIDがこの値のときは、そのチャンクは存在しないものとして扱う
  u8 width;        // ステージの横幅が画面何枚分か (実際のステージ幅)
  u8 height;       // ステージの縦幅が画面何枚分か

  // ここからチャンクマップデータ
  // u8 data[height][stride];
};

#endif  // GUARD_RMZ3_OW_CHUNK_H
