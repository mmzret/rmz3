.section .rodata
.balign 4, 0

.global gVolcanoTilesetGraphics
gVolcanoTilesetGraphics:

VolcanoTileset0: @ 0x08721768
	.4byte VolcanoTileset0_Tiles-. @ data: 0x087217F4 = .+140
	.4byte 16384 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	@ Palette0 0x08721774
		.4byte VolcanoTileset0_Pal-. @ data: 0x087257F4 = .+16512
		.2byte 192 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

VolcanoTileset1: @ 0x0872177C
	.4byte VolcanoTileset1_Tiles-. @ data: 0x087258B4 = .+16696
	.4byte 15360 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	@ Palette1 0x08721788
		.4byte VolcanoTileset1_Pal-. @ data: 0x087294B4 = .+32044
		.2byte 192 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

VolcanoTileset2: @ 0x08721790
	.4byte VolcanoTileset2_Tiles-. @ data: 0x08729574 = .+32228
	.4byte 14784 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	@ Palette2 0x0872179C
		.4byte VolcanoTileset2_Pal-. @ data: 0x0872CF34 = .+47000
		.2byte 192 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

VolcanoTileset3: @ 0x087217A4
	.4byte VolcanoTileset3_Tiles-. @ data: 0x0872CFF4 = .+47184
	.4byte 16256 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	@ Palette3 0x087217B0
		.4byte VolcanoTileset3_Pal-. @ data: 0x08730F74 = .+63428
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

VolcanoTileset4: @ 0x087217B8
	.4byte VolcanoTileset4_Tiles-. @ data: 0x08731054 = .+63644
	.4byte 7980 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette4 0x087217C4
		.4byte VolcanoTileset4_Pal-. @ data: 0x08732F80 = .+71612
		.2byte 192 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

VolcanoTileset5: @ 0x087217CC
	.4byte VolcanoTileset5_Tiles-. @ data: 0x08733040 = .+71796
	.4byte 7892 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette5 0x087217D8
		.4byte VolcanoTileset5_Pal-. @ data: 0x08734F14 = .+79676
		.2byte 192 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

VolcanoTileset6: @ 0x087217E0
	.4byte VolcanoTileset6_Tiles-. @ data: 0x08734FD4 = .+79860
	.4byte 5380 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette6 0x087217EC
		.4byte VolcanoTileset6_Pal-. @ data: 0x087364D8 = .+85228
		.2byte 96 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

VolcanoTileset0_Tiles:
	.incbin "data/tilesets/volcano/volcano0.4bpp"
VolcanoTileset0_Pal:
	.incbin "data/tilesets/volcano/volcano0.gbapal"

VolcanoTileset1_Tiles:
	.incbin "data/tilesets/volcano/volcano1.4bpp"
VolcanoTileset1_Pal:
	.incbin "data/tilesets/volcano/volcano1.gbapal"

VolcanoTileset2_Tiles:
	.incbin "data/tilesets/volcano/volcano2.4bpp"
VolcanoTileset2_Pal:
	.incbin "data/tilesets/volcano/volcano2.gbapal"

VolcanoTileset3_Tiles:
	.incbin "data/tilesets/volcano/volcano3.4bpp"
VolcanoTileset3_Pal:
	.incbin "data/tilesets/volcano/volcano3.gbapal"

VolcanoTileset4_Tiles:
	.incbin "data/tilesets/volcano/volcano4.4bpp.lz"
VolcanoTileset4_Pal:
	.incbin "data/tilesets/volcano/volcano4.gbapal"

VolcanoTileset5_Tiles:
	.incbin "data/tilesets/volcano/volcano5.4bpp.lz"
VolcanoTileset5_Pal:
	.incbin "data/tilesets/volcano/volcano5.gbapal"

VolcanoTileset6_Tiles:
	.incbin "data/tilesets/volcano/volcano6.4bpp.lz"
VolcanoTileset6_Pal:
	.incbin "data/tilesets/volcano/volcano6.gbapal"

