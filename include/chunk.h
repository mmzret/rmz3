#ifndef GUARD_RMZ3_OW_CHUNK_H
#define GUARD_RMZ3_OW_CHUNK_H

#include "metatile.h"

// Chunk: 15x10 metatiles = 240x160 px = GBA screen

// Metatile(のID)を 15x10ブロック集めて画面全体のグラフィックを表すようにしたもの
// TODO: チャンクに名前変える予定
typedef metatile_id_t Screen[15 * 10];

/*
  MetatileのTileMapである、Overworld.map(0x020029e4)に チャンク をどう配置するかのデータ
*/
// ステージ全体 の　チャンクマップ
struct ChunkMap {
  // Layout
  u8 realWidth;
  u8 skip;    // そのステージでのSKIP値を格納する
  u8 width;   // ステージの横幅が画面何枚分か
  u8 height;  // ステージの縦幅が画面何枚分か

  // ここからチャンクマップデータ
  // u8 data[height][realWidth];
};

#endif  // GUARD_RMZ3_OW_CHUNK_H
