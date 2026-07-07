.section .rodata
.balign 4, 0

.global gPlantTilesetGraphics
gPlantTilesetGraphics:

PlantTileset0: @ 0x08791468
	.4byte PlantTileset0_Tiles-. @ data: 0x087914CC = .+100
	.4byte 16384 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	@ Palette 0x08791474
		.4byte PlantTileset0_Pal-. @ data: 0x087954CC = .+16472
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

PlantTileset1: @ 0x0879147C
	.4byte PlantTileset1_Tiles-. @ data: 0x087955AC = .+16688
	.4byte 13440 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	@ Palette 0x08791488
		.4byte PlantTileset1_Pal-. @ data: 0x08798A2C = .+30116
		.2byte 224 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

PlantTileset2: @ 0x08791490
	.4byte PlantTileset2_Tiles-. @ data: 0x08798B0C = .+30332
	.4byte 13888 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	@ Palette 0x0879149C
		.4byte PlantTileset2_Pal-. @ data: 0x0879C14C = .+44208
		.2byte 192 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

PlantTileset3: @ 0x087914A4
	.4byte PlantTileset3_Tiles-. @ data: 0x0879C20C = .+44392
	.4byte 10944 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	@ Palette 0x087914B0
		.4byte PlantTileset3_Pal-. @ data: 0x0879ECCC = .+55324
		.2byte 128 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

PlantTileset4: @ 0x087914B8
	.4byte PlantTileset4_Tiles-. @ data: 0x0879ED4C = .+55444
	.4byte 16384 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	@ Palette 0x087914C4
		.4byte PlantTileset4_Pal-. @ data: 0x087A2D4C = .+71816
		.2byte 224 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

PlantTileset0_Tiles:
	.incbin "data/tilesets/plant/plant0.4bpp"
PlantTileset0_Pal:
	.incbin "data/tilesets/plant/plant0.gbapal"

PlantTileset1_Tiles:
	.incbin "data/tilesets/plant/plant1.4bpp"
PlantTileset1_Pal:
	.incbin "data/tilesets/plant/plant1.gbapal"

PlantTileset2_Tiles:
	.incbin "data/tilesets/plant/plant2.4bpp"
PlantTileset2_Pal:
	.incbin "data/tilesets/plant/plant2.gbapal"

PlantTileset3_Tiles:
	.incbin "data/tilesets/plant/plant3.4bpp"
PlantTileset3_Pal:
	.incbin "data/tilesets/plant/plant3.gbapal"

PlantTileset4_Tiles:
	.incbin "data/tilesets/plant/plant4.4bpp"
PlantTileset4_Pal:
	.incbin "data/tilesets/plant/plant4.gbapal"

