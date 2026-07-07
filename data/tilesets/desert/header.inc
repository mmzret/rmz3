.section .rodata
.balign 4, 0

.global gDesertTilesetGraphics
gDesertTilesetGraphics:

DesertTileset0: @ 0x0876D6F8
	.4byte DesertTileset0_Tiles-. @ data: 0x0876D748 = .+80
	.4byte 9524 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x0876D704
		.4byte DesertTileset0_Pal-. @ data: 0x0876FC7C = .+9592
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

DesertTileset1: @ 0x0876D70C
	.4byte DesertTileset1_Tiles-. @ data: 0x0876FD5C = .+9808
	.4byte 15616 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	@ Palette 0x0876D718
		.4byte DesertTileset1_Pal-. @ data: 0x08773A5C = .+25412
		.2byte 224 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

DesertTileset2: @ 0x0876D720
	.4byte DesertTileset2_Tiles-. @ data: 0x08773B3C = .+25628
	.4byte 3648 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	@ Palette 0x0876D72C
		.4byte DesertTileset2_Pal-. @ data: 0x0877497C = .+29264
		.2byte 32 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

DesertTileset3: @ 0x0876D734
	.4byte DesertTileset3_Tiles-. @ data: 0x0877499C = .+29288
	.4byte 2712 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x0876D740
		.4byte DesertTileset3_Pal-. @ data: 0x08775434 = .+31988
		.2byte 32 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

DesertTileset0_Tiles:
	.incbin "data/tilesets/desert/desert0.4bpp.lz"
DesertTileset0_Pal:
	.incbin "data/tilesets/desert/desert0.gbapal"

DesertTileset1_Tiles:
	.incbin "data/tilesets/desert/desert1.4bpp"
DesertTileset1_Pal:
	.incbin "data/tilesets/desert/desert1.gbapal"

DesertTileset2_Tiles:
	.incbin "data/tilesets/desert/desert2.4bpp"
DesertTileset2_Pal:
	.incbin "data/tilesets/desert/desert2.gbapal"

DesertTileset3_Tiles:
	.incbin "data/tilesets/desert/desert3.4bpp.lz"
DesertTileset3_Pal:
	.incbin "data/tilesets/desert/desert3.gbapal"

