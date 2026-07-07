  .include "asm/macros.inc"

.section .rodata
.balign 4, 0

.global gStageTilesetOffsets
gStageTilesetOffsets:
  .4byte gSnowTilesetGraphics-.
  .4byte gSnowTilesetGraphics-.
  .4byte gVolcanoTilesetGraphics-.
  .4byte gWatersideTilesetGraphics-.
  .4byte gFactoryTilesetGraphics-.
  .4byte gRuinTilesetGraphics-.
  .4byte gMissileTilesetGraphics-.
  .4byte gDesertTilesetGraphics-.
  .4byte gForestTilesetGraphics-.
  .4byte gAntarcticTilesetGraphics-.
  .4byte gAreaX2TilesetGraphics-.
  .4byte gPlantTilesetGraphics-.
  .4byte gSnowTilesetGraphics-.
  .4byte gWatersideTilesetGraphics-.
  .4byte gElevatorTilesetGraphics-.
  .4byte gSubArcadiaTilesetGraphics-.
  .4byte gWeilLaboTilesetGraphics-.
  .4byte gResistanceBaseTilesetGraphics-.
  .4byte gTilesetAnims-.

.include "data/tilesets/snow/header.inc"
.include "data/tilesets/volcano/header.inc"
.include "data/tilesets/waterside/header.inc"
.include "data/tilesets/factory/header.inc"
.include "data/tilesets/ruin/header.inc"
.include "data/tilesets/missile/header.inc"
.include "data/tilesets/desert/header.inc"
.include "data/tilesets/forest/header.inc"
.include "data/tilesets/antarctic/header.inc"
.include "data/tilesets/area_x2/header.inc"
.include "data/tilesets/plant/header.inc"
.include "data/tilesets/giant_elevator/header.inc"
.include "data/tilesets/sub_arcadia/header.inc"
.include "data/tilesets/weil_labo/header.inc"
.include "data/tilesets/resistance_base/header.inc"
.include "data/tilesets/misc/header.inc"
