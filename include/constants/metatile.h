#ifndef GUARD_RMZ3_CONST_METATILE_H
#define GUARD_RMZ3_CONST_METATILE_H

// metatile_attr_t (Metatileの属性)

// 地面に立っている？
#define METATILE_GROUND (1 << 0)

// 壁ずり可能
#define METATILE_WALL (1 << 1)

// θ=30° くらい
#define SHAPE_2 2

// θ=45° くらい
#define SHAPE_3 3

#define SHAPE_4 4

// θ=150° くらい
#define SHAPE_9 9

// θ=170° くらい
#define SHAPE_10 10

// ここまでは地面の形でもある

// ----------------------------------------------------------------------------------------

// トゲ(マグマも？)
#define METATILE_SPIKE (1 << 4)

// 壊れた宇宙船の氷ブロックに付与
#define METATILE_ICEBLOCK (1 << 5)

// 蟻地獄
#define METATILE_ANTTRAP (1 << 10)

// 滑る(0x1000)
#define METATILE_SLIP (1 << 12)

// すり抜け床
#define METATILE_SOFT_PLATFORM (1 << 15)

// ----------------------------------------------------------------------------------------

// はしご
#define METTAILE_LADDER 0x800F

// はしご床 (=はしごの上端)
#define METTAILE_LADDER_FLOOR 0x800E

#endif  // GUARD_RMZ3_CONST_METATILE_H
