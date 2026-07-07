.section .rodata
.balign 4, 0

.global gFactoryTilesetGraphics
gFactoryTilesetGraphics:

FactoryTileset0: @ 0x08744C34
	.4byte FactoryTileset0_Tiles-. @ data: 0x08744C98 = .+100
	.4byte 10124 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette0 0x08744C40
		.4byte FactoryTileset0_Pal-. @ data: 0x08747424 = .+10212
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

FactoryTileset1: @ 0x08744C48
	.4byte FactoryTileset1_Tiles-. @ data: 0x08747504 = .+10428
	.4byte 16128 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	@ Palette1 0x08744C54
		.4byte FactoryTileset1_Pal-. @ data: 0x0874B404 = .+26544
		.2byte 128 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

FactoryTileset2: @ 0x08744C5C
	.4byte FactoryTileset2_Tiles-. @ data: 0x0874B484 = .+26664
	.4byte 13888 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	@ Palette2 0x08744C68
		.4byte FactoryTileset2_Pal-. @ data: 0x0874EAC4 = .+40540
		.2byte 32 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

FactoryTileset3: @ 0x08744C70
	.4byte FactoryTileset3_Tiles-. @ data: 0x0874EAE4 = .+40564
	.4byte 16384 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	@ Palette3 0x08744C7C
		.4byte FactoryTileset3_Pal-. @ data: 0x08752AE4 = .+56936
		.2byte 192 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

FactoryTileset4: @ 0x08744C84
	.4byte FactoryTileset4_Tiles-. @ data: 0x08752BA4 = .+57120
	.4byte 16384 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	@ Palette4 0x08744C90
		.4byte FactoryTileset4_Pal-. @ data: 0x08756BA4 = .+73492
		.2byte 224 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

FactoryTileset0_Tiles:
	.incbin "data/tilesets/factory/factory0.4bpp.lz"
FactoryTileset0_Pal:
	.incbin "data/tilesets/factory/factory0.gbapal"

FactoryTileset1_Tiles:
	.incbin "data/tilesets/factory/factory1.4bpp"
FactoryTileset1_Pal:
	.incbin "data/tilesets/factory/factory1.gbapal"

FactoryTileset2_Tiles:
	.incbin "data/tilesets/factory/factory2.4bpp"
FactoryTileset2_Pal:
	.incbin "data/tilesets/factory/factory2.gbapal"

FactoryTileset3_Tiles:
	.incbin "data/tilesets/factory/factory3.4bpp"
FactoryTileset3_Pal:
	.incbin "data/tilesets/factory/factory3.gbapal"

FactoryTileset4_Tiles:
	.incbin "data/tilesets/factory/factory4.4bpp"
FactoryTileset4_Pal:
	.incbin "data/tilesets/factory/factory4.gbapal"
