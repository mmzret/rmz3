.section .rodata
.balign 4, 0

# 現在のアドレスから gXXXTilesetGraphics までのオフセットを格納している . は現在のアドレス
.global gStageTilesetOffsets
gStageTilesetOffsets:
  .word gSnowTilesetGraphics-.
  .word gSnowTilesetGraphics-.
  .word gVolcanoTilesetGraphics-.
  .word gWatersideTilesetGraphics-.
  .word gFactoryTilesetGraphics-.
  .word gRuinTilesetGraphics-.
  .word gMissileTilesetGraphics-.
  .word gDesertTilesetGraphics-.
  .word gForestTilesetGraphics-.
  .word gAntarcticTilesetGraphics-.
  .word gAreaX2TilesetGraphics-.
  .word gPlantTilesetGraphics-.
  .word gSnowTilesetGraphics-.
  .word gWatersideTilesetGraphics-.
  .word gElevatorTilesetGraphics-.
  .word gSubArcadiaTilesetGraphics-.
  .word gWeilLaboTilesetGraphics-.
  .word gResistanceBaseTilesetGraphics-.
  .word gMiscTilesetGraphics-.
