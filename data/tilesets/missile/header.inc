.section .rodata
.balign 4, 0

.global gMissileTilesetGraphics
gMissileTilesetGraphics:

MissileTileset0: @ 0x08761798
	.4byte MissileTileset0_Tiles-. @ data: 0x08761824 = .+140
	.4byte 7284 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087617A4
		.4byte MissileTileset0_Pal-. @ data: 0x08763498 = .+7412
		.2byte 192 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

MissileTileset1: @ 0x087617AC
	.4byte MissileTileset1_Tiles-. @ data: 0x08763558 = .+7596
	.4byte 7404 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087617B8
		.4byte MissileTileset1_Pal-. @ data: 0x08765244 = .+14988
		.2byte 192 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

MissileTileset2: @ 0x087617C0
	.4byte MissileTileset2_Tiles-. @ data: 0x08765304 = .+15172
	.4byte 5784 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087617CC
		.4byte MissileTileset2_Pal-. @ data: 0x0876699C = .+20944
		.2byte 64 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

MissileTileset3: @ 0x087617D4
	.4byte MissileTileset3_Tiles-. @ data: 0x087669DC = .+21000
	.4byte 5680 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087617E0
		.4byte MissileTileset3_Pal-. @ data: 0x0876800C = .+26668
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

MissileTileset4: @ 0x087617E8
	.4byte MissileTileset4_Tiles-. @ data: 0x087680EC = .+26884
	.4byte 5636 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087617F4
		.4byte MissileTileset4_Pal-. @ data: 0x087696F0 = .+32508
		.2byte 224 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

MissileTileset5: @ 0x087617FC
	.4byte MissileTileset5_Tiles-. @ data: 0x087697D0 = .+32724
	.4byte 11028 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x08761808
		.4byte MissileTileset5_Pal-. @ data: 0x0876C2E4 = .+43740
		.2byte 192 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

MissileTileset6: @ 0x08761810
	.4byte MissileTileset6_Tiles-. @ data: 0x0876C3A4 = .+43924
	.4byte 4724 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x0876181C
		.4byte MissileTileset6_Pal-. @ data: 0x0876D618 = .+48636
		.2byte 224 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

MissileTileset0_Tiles:
	.incbin "data/tilesets/missile/missile0.4bpp.lz"
MissileTileset0_Pal:
	.incbin "data/tilesets/missile/missile0.gbapal"

MissileTileset1_Tiles:
	.incbin "data/tilesets/missile/missile1.4bpp.lz"
MissileTileset1_Pal:
	.incbin "data/tilesets/missile/missile1.gbapal"

MissileTileset2_Tiles:
	.incbin "data/tilesets/missile/missile2.4bpp.lz"
MissileTileset2_Pal:
	.incbin "data/tilesets/missile/missile2.gbapal"

MissileTileset3_Tiles:
	.incbin "data/tilesets/missile/missile3.4bpp.lz"
MissileTileset3_Pal:
	.incbin "data/tilesets/missile/missile3.gbapal"

MissileTileset4_Tiles:
	.incbin "data/tilesets/missile/missile4.4bpp.lz"
MissileTileset4_Pal:
	.incbin "data/tilesets/missile/missile4.gbapal"

MissileTileset5_Tiles:
	.incbin "data/tilesets/missile/missile5.4bpp.lz"
MissileTileset5_Pal:
	.incbin "data/tilesets/missile/missile5.gbapal"

MissileTileset6_Tiles:
	.incbin "data/tilesets/missile/missile6.4bpp.lz"
MissileTileset6_Pal:
	.incbin "data/tilesets/missile/missile6.gbapal"

