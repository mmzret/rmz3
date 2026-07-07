.section .rodata
.balign 4, 0

.global gForestTilesetGraphics
gForestTilesetGraphics:

ForestTileset0: @ 0x08775454
	.4byte ForestTileset0_Tiles-. @ data: 0x087754A4 = .+80
	.4byte 10524 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x08775460
		.4byte ForestTileset0_Pal-. @ data: 0x08777DC0 = .+10592
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

ForestTileset1: @ 0x08775468
	.4byte ForestTileset1_Tiles-. @ data: 0x08777EA0 = .+10808
	.4byte 12880 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x08775474
		.4byte ForestTileset1_Pal-. @ data: 0x0877B0F0 = .+23676
		.2byte 192 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

ForestTileset2: @ 0x0877547C
	.4byte ForestTileset2_Tiles-. @ data: 0x0877B1B0 = .+23860
	.4byte 6672 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x08775488
		.4byte ForestTileset2_Pal-. @ data: 0x0877CBC0 = .+30520
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

ForestTileset3: @ 0x08775490
	.4byte ForestTileset3_Tiles-. @ data: 0x0877CCA0 = .+30736
	.4byte 7516 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x0877549C
		.4byte ForestTileset3_Pal-. @ data: 0x0877E9FC = .+38240
		.2byte 224 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

ForestTileset0_Tiles:
	.incbin "data/tilesets/forest/forest0.4bpp.lz"
ForestTileset0_Pal:
	.incbin "data/tilesets/forest/forest0.gbapal"

ForestTileset1_Tiles:
	.incbin "data/tilesets/forest/forest1.4bpp.lz"
ForestTileset1_Pal:
	.incbin "data/tilesets/forest/forest1.gbapal"

ForestTileset2_Tiles:
	.incbin "data/tilesets/forest/forest2.4bpp.lz"
ForestTileset2_Pal:
	.incbin "data/tilesets/forest/forest2.gbapal"

ForestTileset3_Tiles:
	.incbin "data/tilesets/forest/forest3.4bpp.lz"
ForestTileset3_Pal:
	.incbin "data/tilesets/forest/forest3.gbapal"
