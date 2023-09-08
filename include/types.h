#ifndef GUARD_RMZ3_TYPES_H
#define GUARD_RMZ3_TYPES_H

#include "gba/types.h"

typedef u16 tile_id_t;  // GBAハードのタイルID
typedef u16 KEY_INPUT;
typedef u16 SoundID;
typedef s16 SoundIDS16;
typedef u32 SoundID32;
typedef u16 TextID;
typedef u8 disk_t;
typedef u16 str_id_t;  // 08372210 のidx
typedef u8 mod_t;
typedef u8 cyberelf_t;  // Elf ID
typedef u8 char_t;      // Char code
typedef char_t* str_t;

typedef u16 motion_t;    // アクション((motion_id_t << 8) | ???)
typedef u8 motion_id_t;  // アクションID

typedef u8 weapon_t;        // WeaponID (0=バスター, 1=セイバー, 2=ロッド, 3=シールド)
typedef u32 zero_input_t;   // ZERO_INPUT_XXX
typedef u16 metatile_id_t;  // Metatile を識別するためのID

typedef u16 tileset_t;     // (StageID << 8) | TilesetIdx
typedef u8 tileset_ofs_t;  // ((TilesetIdx_0 << 4) | TilesetIdx_1), TilesetIdx_n = gOverworld.tilesets[n] の TilesetIdx

typedef u16 metatile_attr_t;  // blocking_attr_t と同じ説がある

#endif  // GUARD_RMZ3_TYPES_H
