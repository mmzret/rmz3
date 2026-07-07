#ifndef __INCLUDE_TILESET_ANIMS_H__
#define __INCLUDE_TILESET_ANIMS_H__

#if MODERN
#define gTilesetAnimsOffset (&gStageTilesetOffsets[18])
#else
#define _gStageTilesetOffsets 0x087044B0
#define gTilesetAnimsOffset ((u32*)(_gStageTilesetOffsets + (18 * 4)))
#endif

// gTilesetAnims
#define _gTilesetAnims ((const ColorGraphic*)SELF_REL_PTR(gTilesetAnimsOffset))

// gTilesetAnims's index
#define ANIM_LAVA0 0                     // 0..4
#define ANIM_SPIKE_SCREW 5               // 5..8
#define ANIM_LAVA_GLASS 9                // 9..13, アグニス火山の基地で、リコイルロッドで動かせる棺桶のようなコンテナ付近の背景にある、ガラス越しに見えるマグマのアニメーション, tileset: VolcanoTileset4
#define ANIM_VOLCANO_14 14               // 14..17
#define ANIM_ERUPTION 18                 // 18..24
#define ANIM_LAVA_RIVER 25               // 25..28?
#define ANIM_REPAIR_FACTORY_CONVEYOR 33  // 33..36
#define ANIM_IRON_SCRAP 37               // 37..41
#define ANIM_MUSHROOM1 42                // 42..46
#define ANIM_MUSHROOM2 47                // 47..50
#define ANIM_MUSHROOM3 51                // 51..55
#define ANIM_WOOD56 56                   // 56, 57
#define ANIM_CMD_TELEPORTER_EMISSION 58  // 58..65, ベースの司令室真ん中でふわふわしてる謎の玉みたいなやつ
#define ANIM_FROSTLINE_PIPELINE 66       // 66..71, 氷の前線基地の終盤にある、パイプラインの結合部みたいなところ
#define ANIM_ELEC_LEAKAGE 72             // 72..77, 水没した図書館の切断された電線からの漏電
#define ANIM_ELECARC 78                  // 78..82
#define ANIM_ELECCAGE 83                 // 83..87, Volteel Biblio "Electric Cage" (水没した図書館)
#define ANIM_PROLOGUE_SNOW 88            // 88..91
#define ANIM_FACTORY92 92                // 92
#define ANIM_UNK93 93                    // 93..97
#define ANIM_EFACILITY_CRYSTAL 98        // 98..100, エネルギー施設のボス部屋の真ん中にあるクリスタル(コピーされたダークエルフ?)
#define ANIM_UNK101 101                  // 101..109, エネルギー施設の(ロコモIF直前の照明スイッチ付近の)壁の模様, tileset: PlantTileset4
#define ANIM_FAN 110                     // 110, 111, エネルギー施設のファン
#define ANIM_ELEC_METER 112              // 112..115, エネルギー施設の(2個目の照明スイッチ付近の)電力量計
#define ANIM_EFACILITY_LIQUID 116        // 116..123, エネルギー施設の前半にある謎の液体
#define ANIM_EFACILITY124 124            // 124..127, エネルギー施設の(5個目の照明スイッチ付近)のオブジェクト
#define ANIM_MISSILE_CONVEYOR 128        // 128..135, ミサイル工場のコンベア
#define ANIM_MISSILE_CONSOLE 136         // 136..139, ミサイル工場開始地点のコンソールパネル
#define ANIM_BEACON_LIGHT 140            // 140..147, ミサイル本体内のパトランプ
#define ANIM_BUILDING_SMOKE 148          // 148..152, ミサイルが着弾した後のビルの煙(オメガがダークエルフを取り込むところの背景), tileset: MissileTileset6
#define ANIM_GELEVATOR_PF 153            // 153..157, "巨大エレベーター"の巨大エレベーター(tileset: ElevatorTileset2)
#define ANIM_ANATRE_SPHERE 158           // 158..160, アナトレーの森のおめめ, tileset: ForestTileset2
#define ANIM_OCEAN_AQUARIUM 161          // 161..168, 海上のハイウェイ基地後半の背景の水槽みたいなやつ, tileset: WatersideTileset2
#define ANIM_PROPELLER_PUMP 169          // 169..171, 海上のハイウェイ基地の中ボス部屋のプロペラみたいなやつ, tileset: WatersideTileset2
#define ANIM_ELECCAGE2 172               // 172..176, Volteel Biblio "Electric Cage" (ボスラッシュ部屋) tileset: WeilLaboTileset2

// animID: ANIM_xxx, idx: どのアニメーションフレームかを指定する, 結果として、gTilesetAnims[animID+idx] がロードされる
#define LOAD_ANIM_TILES(animID, idx)                                                  \
  {                                                                                   \
    RequestGraphicTransfer(&(_gTilesetAnims[(animID) + (idx)].g), BG_CHAR_OFFSET(1)); \
    LoadPalette(&(_gTilesetAnims[(animID) + (idx)].pal), 0);                          \
  }

#endif  // __INCLUDE_TILESET_ANIMS_H__
