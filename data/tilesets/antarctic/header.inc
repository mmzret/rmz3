.section .rodata
.balign 4, 0

.global gAntarcticTilesetGraphics
gAntarcticTilesetGraphics:

AntarcticTileset0: @ 0x0877EADC
	.4byte AntarcticTileset0_Tiles-. @ data: 0x0877EB40 = .+100
	.4byte 5736 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x0877EAE8
		.4byte AntarcticTileset0_Pal-. @ data: 0x087801A8 = .+5824
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

AntarcticTileset1: @ 0x0877EAF0
	.4byte AntarcticTileset1_Tiles-. @ data: 0x08780288 = .+6040
	.4byte 11696 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x0877EAFC
		.4byte AntarcticTileset1_Pal-. @ data: 0x08783038 = .+17724
		.2byte 224 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

AntarcticTileset2: @ 0x0877EB04
	.4byte AntarcticTileset2_Tiles-. @ data: 0x08783118 = .+17940
	.4byte 9444 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x0877EB10
		.4byte AntarcticTileset2_Pal-. @ data: 0x087855FC = .+27372
		.2byte 224 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

AntarcticTileset3: @ 0x0877EB18
	.4byte AntarcticTileset3_Tiles-. @ data: 0x087856DC = .+27588
	.4byte 6868 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x0877EB24
		.4byte AntarcticTileset3_Pal-. @ data: 0x087871B0 = .+34444
		.2byte 224 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

AntarcticTileset4: @ 0x0877EB2C
	.4byte AntarcticTileset4_Tiles-. @ data: 0x08787290 = .+34660
	.4byte 8792 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x0877EB38
		.4byte AntarcticTileset4_Pal-. @ data: 0x087894E8 = .+43440
		.2byte 192 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

AntarcticTileset0_Tiles:
	.incbin "data/tilesets/antarctic/antarctic0.4bpp.lz"
AntarcticTileset0_Pal:
	.incbin "data/tilesets/antarctic/antarctic0.gbapal"

AntarcticTileset1_Tiles:
	.incbin "data/tilesets/antarctic/antarctic1.4bpp.lz"
AntarcticTileset1_Pal:
	.incbin "data/tilesets/antarctic/antarctic1.gbapal"

AntarcticTileset2_Tiles:
	.incbin "data/tilesets/antarctic/antarctic2.4bpp.lz"
AntarcticTileset2_Pal:
	.incbin "data/tilesets/antarctic/antarctic2.gbapal"

AntarcticTileset3_Tiles:
	.incbin "data/tilesets/antarctic/antarctic3.4bpp.lz"
AntarcticTileset3_Pal:
	.incbin "data/tilesets/antarctic/antarctic3.gbapal"

AntarcticTileset4_Tiles:
	.incbin "data/tilesets/antarctic/antarctic4.4bpp.lz"
AntarcticTileset4_Pal:
	.incbin "data/tilesets/antarctic/antarctic4.gbapal"

