.section .rodata
.balign 4, 0

@ タイルアニメーションで使う小さいタイルデータ (例えば、火山でドリルのように回転しているトゲは、元のタイルセットにもあるが、アニメーション時にはここにあるもので同じところを置き換えることでアニメーションさせる)
@ パレットと(パレットIDを指定する)タイルマップは、タイルセットのものを使う

.global gTilesetAnims
gTilesetAnims:

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ lava animation (part1)

MiscTileset0: @ 0x087D5A2C
	.4byte MiscTileset0_Tiles-. @ data: 0x087D6800 = .+3540
	.4byte 576 | (302 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5A38
		.4byte MiscTileset0_Pal-. @ data: 0x087D6A40 = .+4104
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset1: @ 0x087D5A40
	.4byte MiscTileset1_Tiles-. @ data: 0x087D6A40 = .+4096
	.4byte 576 | (302 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5A4C
		.4byte MiscTileset1_Pal-. @ data: 0x087D6C80 = .+4660
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset2: @ 0x087D5A54
	.4byte MiscTileset2_Tiles-. @ data: 0x087D6C80 = .+4652
	.4byte 576 | (302 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5A60
		.4byte MiscTileset2_Pal-. @ data: 0x087D6EC0 = .+5216
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset3: @ 0x087D5A68
	.4byte MiscTileset3_Tiles-. @ data: 0x087D6EC0 = .+5208
	.4byte 576 | (302 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5A74
		.4byte MiscTileset3_Pal-. @ data: 0x087D7100 = .+5772
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset4: @ 0x087D5A7C
	.4byte MiscTileset4_Tiles-. @ data: 0x087D7100 = .+5764
	.4byte 576 | (302 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5A88
		.4byte MiscTileset4_Pal-. @ data: 0x087D7340 = .+6328
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ screw spike (part1) in volcano

MiscTileset5: @ 0x087D5A90
	.4byte MiscTileset5_Tiles-. @ data: 0x087D7340 = .+6320
	.4byte 192 | (605 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5A9C
		.4byte MiscTileset5_Pal-. @ data: 0x087D7400 = .+6500
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset6: @ 0x087D5AA4
	.4byte MiscTileset6_Tiles-. @ data: 0x087D7400 = .+6492
	.4byte 192 | (605 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5AB0
		.4byte MiscTileset6_Pal-. @ data: 0x087D74C0 = .+6672
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset7: @ 0x087D5AB8
	.4byte MiscTileset7_Tiles-. @ data: 0x087D74C0 = .+6664
	.4byte 192 | (605 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5AC4
		.4byte MiscTileset7_Pal-. @ data: 0x087D7580 = .+6844
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset8: @ 0x087D5ACC
	.4byte MiscTileset8_Tiles-. @ data: 0x087D7580 = .+6836
	.4byte 192 | (605 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5AD8
		.4byte MiscTileset8_Pal-. @ data: 0x087D7640 = .+7016
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ アグニス火山の基地で、リコイルロッドで動かせる棺桶のようなコンテナ付近の背景にある、ガラス越しに見えるマグマのアニメーション (tileset: VolcanoTileset4)

MiscTileset9: @ 0x087D5AE0
	.4byte MiscTileset9_Tiles-. @ data: 0x087D7640 = .+7008
	.4byte 384 | (754 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5AEC
		.4byte MiscTileset9_Pal-. @ data: 0x087D77C0 = .+7380
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset10: @ 0x087D5AF4
	.4byte MiscTileset10_Tiles-. @ data: 0x087D77C0 = .+7372
	.4byte 384 | (754 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5B00
		.4byte MiscTileset10_Pal-. @ data: 0x087D7940 = .+7744
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset11: @ 0x087D5B08
	.4byte MiscTileset11_Tiles-. @ data: 0x087D7940 = .+7736
	.4byte 384 | (754 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5B14
		.4byte MiscTileset11_Pal-. @ data: 0x087D7AC0 = .+8108
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset12: @ 0x087D5B1C
	.4byte MiscTileset12_Tiles-. @ data: 0x087D7AC0 = .+8100
	.4byte 384 | (754 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5B28
		.4byte MiscTileset12_Pal-. @ data: 0x087D7C40 = .+8472
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset13: @ 0x087D5B30
	.4byte MiscTileset13_Tiles-. @ data: 0x087D7C40 = .+8464
	.4byte 384 | (754 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5B3C
		.4byte MiscTileset13_Pal-. @ data: 0x087D7DC0 = .+8836
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ screw spike (part2) in volcano

MiscTileset14: @ 0x087D5B44
	.4byte MiscTileset14_Tiles-. @ data: 0x087D7DC0 = .+8828
	.4byte 192 | (624 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5B50
		.4byte MiscTileset14_Pal-. @ data: 0x087D7E80 = .+9008
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset15: @ 0x087D5B58
	.4byte MiscTileset15_Tiles-. @ data: 0x087D7E80 = .+9000
	.4byte 192 | (624 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5B64
		.4byte MiscTileset15_Pal-. @ data: 0x087D7F40 = .+9180
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset16: @ 0x087D5B6C
	.4byte MiscTileset16_Tiles-. @ data: 0x087D7F40 = .+9172
	.4byte 192 | (624 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5B78
		.4byte MiscTileset16_Pal-. @ data: 0x087D8000 = .+9352
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset17: @ 0x087D5B80
	.4byte MiscTileset17_Tiles-. @ data: 0x087D8000 = .+9344
	.4byte 192 | (624 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5B8C
		.4byte MiscTileset17_Pal-. @ data: 0x087D80C0 = .+9524
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ eruption in volcano

MiscTileset18: @ 0x087D5B94
	.4byte MiscTileset18_Tiles-. @ data: 0x087D80C0 = .+9516
	.4byte 1024 | (704 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5BA0
		.4byte MiscTileset18_Pal-. @ data: 0x087D84C0 = .+10528
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset19: @ 0x087D5BA8
	.4byte MiscTileset19_Tiles-. @ data: 0x087D84C0 = .+10520
	.4byte 1024 | (704 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5BB4
		.4byte MiscTileset19_Pal-. @ data: 0x087D88C0 = .+11532
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset20: @ 0x087D5BBC
	.4byte MiscTileset20_Tiles-. @ data: 0x087D88C0 = .+11524
	.4byte 1024 | (704 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5BC8
		.4byte MiscTileset20_Pal-. @ data: 0x087D8CC0 = .+12536
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset21: @ 0x087D5BD0
	.4byte MiscTileset21_Tiles-. @ data: 0x087D8CC0 = .+12528
	.4byte 1024 | (704 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5BDC
		.4byte MiscTileset21_Pal-. @ data: 0x087D90C0 = .+13540
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset22: @ 0x087D5BE4
	.4byte MiscTileset22_Tiles-. @ data: 0x087D90C0 = .+13532
	.4byte 1024 | (704 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5BF0
		.4byte MiscTileset22_Pal-. @ data: 0x087D94C0 = .+14544
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset23: @ 0x087D5BF8
	.4byte MiscTileset23_Tiles-. @ data: 0x087D94C0 = .+14536
	.4byte 1024 | (704 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5C04
		.4byte MiscTileset23_Pal-. @ data: 0x087D98C0 = .+15548
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset24: @ 0x087D5C0C
	.4byte MiscTileset24_Tiles-. @ data: 0x087D98C0 = .+15540
	.4byte 1024 | (704 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5C18
		.4byte MiscTileset24_Pal-. @ data: 0x087D9CC0 = .+16552
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ lava river?

MiscTileset25: @ 0x087D5C20
	.4byte MiscTileset25_Tiles-. @ data: 0x087D9CC0 = .+16544
	.4byte 2048 | (32 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5C2C
		.4byte MiscTileset25_Pal-. @ data: 0x087DA4C0 = .+18580
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset26: @ 0x087D5C34
	.4byte MiscTileset26_Tiles-. @ data: 0x087DA4C0 = .+18572
	.4byte 2048 | (32 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5C40
		.4byte MiscTileset26_Pal-. @ data: 0x087DACC0 = .+20608
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset27: @ 0x087D5C48
	.4byte MiscTileset27_Tiles-. @ data: 0x087DACC0 = .+20600
	.4byte 2048 | (32 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5C54
		.4byte MiscTileset27_Pal-. @ data: 0x087DB4C0 = .+22636
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset28: @ 0x087D5C5C
	.4byte MiscTileset28_Tiles-. @ data: 0x087DB4C0 = .+22628
	.4byte 2048 | (32 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5C68
		.4byte MiscTileset28_Pal-. @ data: 0x087DBCC0 = .+24664
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ dummy? (data is 0 bytes)

MiscTileset29: @ 0x087D5C70
	.4byte MiscTileset29_Tiles-. @ data: 0x087DBCC0 = .+24656
	.4byte 0 | (32 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, NO_PAL 	@ rowsize(unused), props
	@ Palette 0x087D5C7C
		.4byte MiscTileset29_Pal-. @ data: 0x087DBCC0 = .+24644
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset30: @ 0x087D5C84
	.4byte MiscTileset30_Tiles-. @ data: 0x087DBCC0 = .+24636
	.4byte 0 | (32 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, NO_PAL 	@ rowsize(unused), props
	@ Palette 0x087D5C90
		.4byte MiscTileset30_Pal-. @ data: 0x087DBCC0 = .+24624
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset31: @ 0x087D5C98
	.4byte MiscTileset31_Tiles-. @ data: 0x087DBCC0 = .+24616
	.4byte 0 | (32 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, NO_PAL 	@ rowsize(unused), props
	@ Palette 0x087D5CA4
		.4byte MiscTileset31_Pal-. @ data: 0x087DBCC0 = .+24604
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset32: @ 0x087D5CAC
	.4byte MiscTileset32_Tiles-. @ data: 0x087DBCC0 = .+24596
	.4byte 0 | (32 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, NO_PAL 	@ rowsize(unused), props
	@ Palette 0x087D5CB8
		.4byte MiscTileset32_Pal-. @ data: 0x087DBCC0 = .+24584
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

MiscTileset33: @ 0x087D5CC0
	.4byte MiscTileset33_Tiles-. @ data: 0x087DBCC0 = .+24576
	.4byte 256 | (171 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5CCC
		.4byte MiscTileset33_Pal-. @ data: 0x087DBDC0 = .+24820
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset34: @ 0x087D5CD4
	.4byte MiscTileset34_Tiles-. @ data: 0x087DBDC0 = .+24812
	.4byte 256 | (171 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5CE0
		.4byte MiscTileset34_Pal-. @ data: 0x087DBEC0 = .+25056
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset35: @ 0x087D5CE8
	.4byte MiscTileset35_Tiles-. @ data: 0x087DBEC0 = .+25048
	.4byte 256 | (171 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5CF4
		.4byte MiscTileset35_Pal-. @ data: 0x087DBFC0 = .+25292
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset36: @ 0x087D5CFC
	.4byte MiscTileset36_Tiles-. @ data: 0x087DBFC0 = .+25284
	.4byte 256 | (171 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5D08
		.4byte MiscTileset36_Pal-. @ data: 0x087DC0C0 = .+25528
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ scrap in repair factory

MiscTileset37: @ 0x087D5D10
	.4byte MiscTileset37_Tiles-. @ data: 0x087DC0C0 = .+25520
	.4byte 768 | (457 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 192, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5D1C
		.4byte MiscTileset37_Pal-. @ data: 0x087DC3C0 = .+26276
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset38: @ 0x087D5D24
	.4byte MiscTileset38_Tiles-. @ data: 0x087DC3C0 = .+26268
	.4byte 768 | (457 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 192, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5D30
		.4byte MiscTileset38_Pal-. @ data: 0x087DC6C0 = .+27024
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset39: @ 0x087D5D38
	.4byte MiscTileset39_Tiles-. @ data: 0x087DC6C0 = .+27016
	.4byte 768 | (457 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 192, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5D44
		.4byte MiscTileset39_Pal-. @ data: 0x087DC9C0 = .+27772
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset40: @ 0x087D5D4C
	.4byte MiscTileset40_Tiles-. @ data: 0x087DC9C0 = .+27764
	.4byte 768 | (457 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 192, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5D58
		.4byte MiscTileset40_Pal-. @ data: 0x087DCCC0 = .+28520
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset41: @ 0x087D5D60
	.4byte MiscTileset41_Tiles-. @ data: 0x087DCCC0 = .+28512
	.4byte 768 | (457 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 192, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5D6C
		.4byte MiscTileset41_Pal-. @ data: 0x087DCFC0 = .+29268
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ mushroom (large shiitake)

MiscTileset42: @ 0x087D5D74
	.4byte MiscTileset42_Tiles-. @ data: 0x087DCFC0 = .+29260
	.4byte 512 | (66 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5D80
		.4byte MiscTileset42_Pal-. @ data: 0x087DD1C0 = .+29760
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset43: @ 0x087D5D88
	.4byte MiscTileset43_Tiles-. @ data: 0x087DD1C0 = .+29752
	.4byte 512 | (66 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5D94
		.4byte MiscTileset43_Pal-. @ data: 0x087DD3C0 = .+30252
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset44: @ 0x087D5D9C
	.4byte MiscTileset44_Tiles-. @ data: 0x087DD3C0 = .+30244
	.4byte 512 | (66 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5DA8
		.4byte MiscTileset44_Pal-. @ data: 0x087DD5C0 = .+30744
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset45: @ 0x087D5DB0
	.4byte MiscTileset45_Tiles-. @ data: 0x087DD5C0 = .+30736
	.4byte 512 | (66 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5DBC
		.4byte MiscTileset45_Pal-. @ data: 0x087DD7C0 = .+31236
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset46: @ 0x087D5DC4
	.4byte MiscTileset46_Tiles-. @ data: 0x087DD7C0 = .+31228
	.4byte 512 | (66 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5DD0
		.4byte MiscTileset46_Pal-. @ data: 0x087DD9C0 = .+31728
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ mushroom (enoki)

MiscTileset47: @ 0x087D5DD8
	.4byte MiscTileset47_Tiles-. @ data: 0x087DD9C0 = .+31720
	.4byte 256 | (64 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5DE4
		.4byte MiscTileset47_Pal-. @ data: 0x087DDAC0 = .+31964
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset48: @ 0x087D5DEC
	.4byte MiscTileset48_Tiles-. @ data: 0x087DDAC0 = .+31956
	.4byte 256 | (64 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5DF8
		.4byte MiscTileset48_Pal-. @ data: 0x087DDBC0 = .+32200
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset49: @ 0x087D5E00
	.4byte MiscTileset49_Tiles-. @ data: 0x087DDBC0 = .+32192
	.4byte 256 | (64 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5E0C
		.4byte MiscTileset49_Pal-. @ data: 0x087DDCC0 = .+32436
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset50: @ 0x087D5E14
	.4byte MiscTileset50_Tiles-. @ data: 0x087DDCC0 = .+32428
	.4byte 256 | (64 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5E20
		.4byte MiscTileset50_Pal-. @ data: 0x087DDDC0 = .+32672
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ mushroom (small shiitake)

MiscTileset51: @ 0x087D5E28
	.4byte MiscTileset51_Tiles-. @ data: 0x087DDDC0 = .+32664
	.4byte 128 | (196 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5E34
		.4byte MiscTileset51_Pal-. @ data: 0x087DDE40 = .+32780
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset52: @ 0x087D5E3C
	.4byte MiscTileset52_Tiles-. @ data: 0x087DDE40 = .+32772
	.4byte 128 | (196 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5E48
		.4byte MiscTileset52_Pal-. @ data: 0x087DDEC0 = .+32888
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset53: @ 0x087D5E50
	.4byte MiscTileset53_Tiles-. @ data: 0x087DDEC0 = .+32880
	.4byte 128 | (196 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5E5C
		.4byte MiscTileset53_Pal-. @ data: 0x087DDF40 = .+32996
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset54: @ 0x087D5E64
	.4byte MiscTileset54_Tiles-. @ data: 0x087DDF40 = .+32988
	.4byte 128 | (196 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5E70
		.4byte MiscTileset54_Pal-. @ data: 0x087DDFC0 = .+33104
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset55: @ 0x087D5E78
	.4byte MiscTileset55_Tiles-. @ data: 0x087DDFC0 = .+33096
	.4byte 128 | (196 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5E84
		.4byte MiscTileset55_Pal-. @ data: 0x087DE040 = .+33212
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ wood? anim in old residential

MiscTileset56: @ 0x087D5E8C
	.4byte MiscTileset56_Tiles-. @ data: 0x087DE040 = .+33204
	.4byte 384 | (320 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5E98
		.4byte MiscTileset56_Pal-. @ data: 0x087DE1C0 = .+33576
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset57: @ 0x087D5EA0
	.4byte MiscTileset57_Tiles-. @ data: 0x087DE1C0 = .+33568
	.4byte 384 | (320 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5EAC
		.4byte MiscTileset57_Pal-. @ data: 0x087DE340 = .+33940
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ ベースの司令室真ん中でふわふわしてる謎の玉みたいなやつ

MiscTileset58: @ 0x087D5EB4
	.4byte MiscTileset58_Tiles-. @ data: 0x087DE340 = .+33932
	.4byte 576 | (192 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5EC0
		.4byte MiscTileset58_Pal-. @ data: 0x087DE580 = .+34496
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset59: @ 0x087D5EC8
	.4byte MiscTileset59_Tiles-. @ data: 0x087DE580 = .+34488
	.4byte 576 | (192 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5ED4
		.4byte MiscTileset59_Pal-. @ data: 0x087DE7C0 = .+35052
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset60: @ 0x087D5EDC
	.4byte MiscTileset60_Tiles-. @ data: 0x087DE7C0 = .+35044
	.4byte 576 | (192 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5EE8
		.4byte MiscTileset60_Pal-. @ data: 0x087DEA00 = .+35608
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset61: @ 0x087D5EF0
	.4byte MiscTileset61_Tiles-. @ data: 0x087DEA00 = .+35600
	.4byte 576 | (192 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5EFC
		.4byte MiscTileset61_Pal-. @ data: 0x087DEC40 = .+36164
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset62: @ 0x087D5F04
	.4byte MiscTileset62_Tiles-. @ data: 0x087DEC40 = .+36156
	.4byte 576 | (192 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5F10
		.4byte MiscTileset62_Pal-. @ data: 0x087DEE80 = .+36720
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset63: @ 0x087D5F18
	.4byte MiscTileset63_Tiles-. @ data: 0x087DEE80 = .+36712
	.4byte 576 | (192 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5F24
		.4byte MiscTileset63_Pal-. @ data: 0x087DF0C0 = .+37276
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset64: @ 0x087D5F2C
	.4byte MiscTileset64_Tiles-. @ data: 0x087DF0C0 = .+37268
	.4byte 576 | (192 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5F38
		.4byte MiscTileset64_Pal-. @ data: 0x087DF300 = .+37832
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset65: @ 0x087D5F40
	.4byte MiscTileset65_Tiles-. @ data: 0x087DF300 = .+37824
	.4byte 576 | (192 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D5F4C
		.4byte MiscTileset65_Pal-. @ data: 0x087DF540 = .+38388
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ 氷の前線基地の終盤にある、パイプラインの結合部みたいなところ

MiscTileset66: @ 0x087D5F54
	.4byte MiscTileset66_Tiles-. @ data: 0x087DF540 = .+38380
	.4byte 512 | (532 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5F60
		.4byte MiscTileset66_Pal-. @ data: 0x087DF740 = .+38880
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset67: @ 0x087D5F68
	.4byte MiscTileset67_Tiles-. @ data: 0x087DF740 = .+38872
	.4byte 512 | (532 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5F74
		.4byte MiscTileset67_Pal-. @ data: 0x087DF940 = .+39372
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset68: @ 0x087D5F7C
	.4byte MiscTileset68_Tiles-. @ data: 0x087DF940 = .+39364
	.4byte 512 | (532 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5F88
		.4byte MiscTileset68_Pal-. @ data: 0x087DFB40 = .+39864
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset69: @ 0x087D5F90
	.4byte MiscTileset69_Tiles-. @ data: 0x087DFB40 = .+39856
	.4byte 512 | (532 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5F9C
		.4byte MiscTileset69_Pal-. @ data: 0x087DFD40 = .+40356
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset70: @ 0x087D5FA4
	.4byte MiscTileset70_Tiles-. @ data: 0x087DFD40 = .+40348
	.4byte 512 | (532 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5FB0
		.4byte MiscTileset70_Pal-. @ data: 0x087DFF40 = .+40848
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset71: @ 0x087D5FB8
	.4byte MiscTileset71_Tiles-. @ data: 0x087DFF40 = .+40840
	.4byte 512 | (532 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5FC4
		.4byte MiscTileset71_Pal-. @ data: 0x087E0140 = .+41340
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ 水没した図書館の切断された電線

MiscTileset72: @ 0x087D5FCC
	.4byte MiscTileset72_Tiles-. @ data: 0x087E0140 = .+41332
	.4byte 512 | (320 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5FD8
		.4byte MiscTileset72_Pal-. @ data: 0x087E0340 = .+41832
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset73: @ 0x087D5FE0
	.4byte MiscTileset73_Tiles-. @ data: 0x087E0340 = .+41824
	.4byte 512 | (320 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D5FEC
		.4byte MiscTileset73_Pal-. @ data: 0x087E0540 = .+42324
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset74: @ 0x087D5FF4
	.4byte MiscTileset74_Tiles-. @ data: 0x087E0540 = .+42316
	.4byte 512 | (320 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6000
		.4byte MiscTileset74_Pal-. @ data: 0x087E0740 = .+42816
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset75: @ 0x087D6008
	.4byte MiscTileset75_Tiles-. @ data: 0x087E0740 = .+42808
	.4byte 512 | (320 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6014
		.4byte MiscTileset75_Pal-. @ data: 0x087E0940 = .+43308
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset76: @ 0x087D601C
	.4byte MiscTileset76_Tiles-. @ data: 0x087E0940 = .+43300
	.4byte 512 | (320 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6028
		.4byte MiscTileset76_Pal-. @ data: 0x087E0B40 = .+43800
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset77: @ 0x087D6030
	.4byte MiscTileset77_Tiles-. @ data: 0x087E0B40 = .+43792
	.4byte 512 | (320 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D603C
		.4byte MiscTileset77_Pal-. @ data: 0x087E0D40 = .+44292
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ electric arc

MiscTileset78: @ 0x087D6044
	.4byte MiscTileset78_Tiles-. @ data: 0x087E0D40 = .+44284
	.4byte 256 | (334 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6050
		.4byte MiscTileset78_Pal-. @ data: 0x087E0E40 = .+44528
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset79: @ 0x087D6058
	.4byte MiscTileset79_Tiles-. @ data: 0x087E0E40 = .+44520
	.4byte 256 | (334 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6064
		.4byte MiscTileset79_Pal-. @ data: 0x087E0F40 = .+44764
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset80: @ 0x087D606C
	.4byte MiscTileset80_Tiles-. @ data: 0x087E0F40 = .+44756
	.4byte 256 | (334 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6078
		.4byte MiscTileset80_Pal-. @ data: 0x087E1040 = .+45000
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset81: @ 0x087D6080
	.4byte MiscTileset81_Tiles-. @ data: 0x087E1040 = .+44992
	.4byte 256 | (334 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D608C
		.4byte MiscTileset81_Pal-. @ data: 0x087E1140 = .+45236
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset82: @ 0x087D6094
	.4byte MiscTileset82_Tiles-. @ data: 0x087E1140 = .+45228
	.4byte 256 | (334 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D60A0
		.4byte MiscTileset82_Pal-. @ data: 0x087E1240 = .+45472
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Volteel Biblio "Electric Cage" (水没した図書館)

MiscTileset83: @ 0x087D60A8
	.4byte MiscTileset83_Tiles-. @ data: 0x087E1240 = .+45464
	.4byte 2048 | (64 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D60B4
		.4byte MiscTileset83_Pal-. @ data: 0x087E1A40 = .+47500
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset84: @ 0x087D60BC
	.4byte MiscTileset84_Tiles-. @ data: 0x087E1A40 = .+47492
	.4byte 2048 | (64 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D60C8
		.4byte MiscTileset84_Pal-. @ data: 0x087E2240 = .+49528
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset85: @ 0x087D60D0
	.4byte MiscTileset85_Tiles-. @ data: 0x087E2240 = .+49520
	.4byte 2048 | (64 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D60DC
		.4byte MiscTileset85_Pal-. @ data: 0x087E2A40 = .+51556
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset86: @ 0x087D60E4
	.4byte MiscTileset86_Tiles-. @ data: 0x087E2A40 = .+51548
	.4byte 2048 | (64 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D60F0
		.4byte MiscTileset86_Pal-. @ data: 0x087E3240 = .+53584
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset87: @ 0x087D60F8
	.4byte MiscTileset87_Tiles-. @ data: 0x087E3240 = .+53576
	.4byte 2048 | (64 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6104
		.4byte MiscTileset87_Pal-. @ data: 0x087E3A40 = .+55612
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ prologue snow

MiscTileset88: @ 0x087D610C
	.4byte MiscTileset88_Tiles-. @ data: 0x087E3A40 = .+55604
	.4byte 512 | (528 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6118
		.4byte MiscTileset88_Pal-. @ data: 0x087E3C40 = .+56104
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset89: @ 0x087D6120
	.4byte MiscTileset89_Tiles-. @ data: 0x087E3C40 = .+56096
	.4byte 512 | (528 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D612C
		.4byte MiscTileset89_Pal-. @ data: 0x087E3E40 = .+56596
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset90: @ 0x087D6134
	.4byte MiscTileset90_Tiles-. @ data: 0x087E3E40 = .+56588
	.4byte 512 | (528 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6140
		.4byte MiscTileset90_Pal-. @ data: 0x087E4040 = .+57088
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset91: @ 0x087D6148
	.4byte MiscTileset91_Tiles-. @ data: 0x087E4040 = .+57080
	.4byte 512 | (528 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6154
		.4byte MiscTileset91_Pal-. @ data: 0x087E4240 = .+57580
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ 兵器再生工場でミサイル基地クリア後のなんかのグラフィック

MiscTileset92: @ 0x087D615C
	.4byte MiscTileset92_Tiles-. @ data: 0x087E4240 = .+57572
	.4byte 320 | (1013 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 80, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6168
		.4byte MiscTileset92_Pal-. @ data: 0x087E4380 = .+57880
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

MiscTileset93: @ 0x087D6170
	.4byte MiscTileset93_Tiles-. @ data: 0x087E4380 = .+57872
	.4byte 128 | (588 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D617C
		.4byte MiscTileset93_Pal-. @ data: 0x087E4400 = .+57988
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset94: @ 0x087D6184
	.4byte MiscTileset94_Tiles-. @ data: 0x087E4400 = .+57980
	.4byte 128 | (588 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6190
		.4byte MiscTileset94_Pal-. @ data: 0x087E4480 = .+58096
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset95: @ 0x087D6198
	.4byte MiscTileset95_Tiles-. @ data: 0x087E4480 = .+58088
	.4byte 128 | (588 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D61A4
		.4byte MiscTileset95_Pal-. @ data: 0x087E4500 = .+58204
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset96: @ 0x087D61AC
	.4byte MiscTileset96_Tiles-. @ data: 0x087E4500 = .+58196
	.4byte 128 | (588 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D61B8
		.4byte MiscTileset96_Pal-. @ data: 0x087E4580 = .+58312
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset97: @ 0x087D61C0
	.4byte MiscTileset97_Tiles-. @ data: 0x087E4580 = .+58304
	.4byte 128 | (588 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D61CC
		.4byte MiscTileset97_Pal-. @ data: 0x087E4600 = .+58420
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ エネルギー施設のボス部屋の真ん中にあるクリスタル(コピーされたダークエルフ?) (tileset: PlantTileset1)

MiscTileset98: @ 0x087D61D4
	.4byte MiscTileset98_Tiles-. @ data: 0x087E4600 = .+58412
	.4byte 256 | (709 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D61E0
		.4byte MiscTileset98_Pal-. @ data: 0x087E4700 = .+58656
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset99: @ 0x087D61E8
	.4byte MiscTileset99_Tiles-. @ data: 0x087E4700 = .+58648
	.4byte 256 | (709 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D61F4
		.4byte MiscTileset99_Pal-. @ data: 0x087E4800 = .+58892
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset100: @ 0x087D61FC
	.4byte MiscTileset100_Tiles-. @ data: 0x087E4800 = .+58884
	.4byte 256 | (709 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6208
		.4byte MiscTileset100_Pal-. @ data: 0x087E4900 = .+59128
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ エネルギー施設の(ロコモIF直前の照明スイッチ付近の)壁の模様 (tileset: PlantTileset4, ただしパレットは一緒に使用する PlantTileset0 のものを使用してるっぽい)

MiscTileset101: @ 0x087D6210
	.4byte MiscTileset101_Tiles-. @ data: 0x087E4900 = .+59120
	.4byte 1024 | (991 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D621C
		.4byte MiscTileset101_Pal-. @ data: 0x087E4D00 = .+60132
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset102: @ 0x087D6224
	.4byte MiscTileset102_Tiles-. @ data: 0x087E4D00 = .+60124
	.4byte 1024 | (991 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6230
		.4byte MiscTileset102_Pal-. @ data: 0x087E5100 = .+61136
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset103: @ 0x087D6238
	.4byte MiscTileset103_Tiles-. @ data: 0x087E5100 = .+61128
	.4byte 1024 | (991 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6244
		.4byte MiscTileset103_Pal-. @ data: 0x087E5500 = .+62140
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset104: @ 0x087D624C
	.4byte MiscTileset104_Tiles-. @ data: 0x087E5500 = .+62132
	.4byte 1024 | (991 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6258
		.4byte MiscTileset104_Pal-. @ data: 0x087E5900 = .+63144
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset105: @ 0x087D6260
	.4byte MiscTileset105_Tiles-. @ data: 0x087E5900 = .+63136
	.4byte 1024 | (991 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D626C
		.4byte MiscTileset105_Pal-. @ data: 0x087E5D00 = .+64148
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset106: @ 0x087D6274
	.4byte MiscTileset106_Tiles-. @ data: 0x087E5D00 = .+64140
	.4byte 1024 | (991 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6280
		.4byte MiscTileset106_Pal-. @ data: 0x087E6100 = .+65152
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset107: @ 0x087D6288
	.4byte MiscTileset107_Tiles-. @ data: 0x087E6100 = .+65144
	.4byte 1024 | (991 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6294
		.4byte MiscTileset107_Pal-. @ data: 0x087E6500 = .+66156
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset108: @ 0x087D629C
	.4byte MiscTileset108_Tiles-. @ data: 0x087E6500 = .+66148
	.4byte 1024 | (991 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D62A8
		.4byte MiscTileset108_Pal-. @ data: 0x087E6900 = .+67160
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset109: @ 0x087D62B0
	.4byte MiscTileset109_Tiles-. @ data: 0x087E6900 = .+67152
	.4byte 1024 | (991 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D62BC
		.4byte MiscTileset109_Pal-. @ data: 0x087E6D00 = .+68164
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ fan at Energy Facility (tileset: PlantTileset4)

MiscTileset110: @ 0x087D62C4
	.4byte MiscTileset110_Tiles-. @ data: 0x087E6D00 = .+68156
	.4byte 1024 | (883 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D62D0
		.4byte MiscTileset110_Pal-. @ data: 0x087E7100 = .+69168
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset111: @ 0x087D62D8
	.4byte MiscTileset111_Tiles-. @ data: 0x087E7100 = .+69160
	.4byte 1024 | (883 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D62E4
		.4byte MiscTileset111_Pal-. @ data: 0x087E7500 = .+70172
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ electricity meter at Energy Facility (2個目の照明スイッチ付近) (tileset: PlantTileset0)

MiscTileset112: @ 0x087D62EC
	.4byte MiscTileset112_Tiles-. @ data: 0x087E7500 = .+70164
	.4byte 128 | (360 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D62F8
		.4byte MiscTileset112_Pal-. @ data: 0x087E7580 = .+70280
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset113: @ 0x087D6300
	.4byte MiscTileset113_Tiles-. @ data: 0x087E7580 = .+70272
	.4byte 128 | (360 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D630C
		.4byte MiscTileset113_Pal-. @ data: 0x087E7600 = .+70388
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset114: @ 0x087D6314
	.4byte MiscTileset114_Tiles-. @ data: 0x087E7600 = .+70380
	.4byte 128 | (360 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6320
		.4byte MiscTileset114_Pal-. @ data: 0x087E7680 = .+70496
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset115: @ 0x087D6328
	.4byte MiscTileset115_Tiles-. @ data: 0x087E7680 = .+70488
	.4byte 128 | (360 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6334
		.4byte MiscTileset115_Pal-. @ data: 0x087E7700 = .+70604
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ エネルギー施設の前半にある謎の液体 (tileset: PlantTileset4)

MiscTileset116: @ 0x087D633C
	.4byte MiscTileset116_Tiles-. @ data: 0x087E7700 = .+70596
	.4byte 512 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6348
		.4byte MiscTileset116_Pal-. @ data: 0x087E7900 = .+71096
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset117: @ 0x087D6350
	.4byte MiscTileset117_Tiles-. @ data: 0x087E7900 = .+71088
	.4byte 512 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D635C
		.4byte MiscTileset117_Pal-. @ data: 0x087E7B00 = .+71588
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset118: @ 0x087D6364
	.4byte MiscTileset118_Tiles-. @ data: 0x087E7B00 = .+71580
	.4byte 512 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6370
		.4byte MiscTileset118_Pal-. @ data: 0x087E7D00 = .+72080
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset119: @ 0x087D6378
	.4byte MiscTileset119_Tiles-. @ data: 0x087E7D00 = .+72072
	.4byte 512 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6384
		.4byte MiscTileset119_Pal-. @ data: 0x087E7F00 = .+72572
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset120: @ 0x087D638C
	.4byte MiscTileset120_Tiles-. @ data: 0x087E7F00 = .+72564
	.4byte 512 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6398
		.4byte MiscTileset120_Pal-. @ data: 0x087E8100 = .+73064
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset121: @ 0x087D63A0
	.4byte MiscTileset121_Tiles-. @ data: 0x087E8100 = .+73056
	.4byte 512 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D63AC
		.4byte MiscTileset121_Pal-. @ data: 0x087E8300 = .+73556
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset122: @ 0x087D63B4
	.4byte MiscTileset122_Tiles-. @ data: 0x087E8300 = .+73548
	.4byte 512 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D63C0
		.4byte MiscTileset122_Pal-. @ data: 0x087E8500 = .+74048
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset123: @ 0x087D63C8
	.4byte MiscTileset123_Tiles-. @ data: 0x087E8500 = .+74040
	.4byte 512 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D63D4
		.4byte MiscTileset123_Pal-. @ data: 0x087E8700 = .+74540
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ エネルギー施設の(5個目の照明スイッチ付近)のオブジェクト (tileset: PlantTileset4)

MiscTileset124: @ 0x087D63DC
	.4byte MiscTileset124_Tiles-. @ data: 0x087E8700 = .+74532
	.4byte 576 | (855 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D63E8
		.4byte MiscTileset124_Pal-. @ data: 0x087E8940 = .+75096
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset125: @ 0x087D63F0
	.4byte MiscTileset125_Tiles-. @ data: 0x087E8940 = .+75088
	.4byte 576 | (855 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D63FC
		.4byte MiscTileset125_Pal-. @ data: 0x087E8B80 = .+75652
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset126: @ 0x087D6404
	.4byte MiscTileset126_Tiles-. @ data: 0x087E8B80 = .+75644
	.4byte 576 | (855 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6410
		.4byte MiscTileset126_Pal-. @ data: 0x087E8DC0 = .+76208
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset127: @ 0x087D6418
	.4byte MiscTileset127_Tiles-. @ data: 0x087E8DC0 = .+76200
	.4byte 576 | (855 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (NO_PAL | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087D6424
		.4byte MiscTileset127_Pal-. @ data: 0x087E9000 = .+76764
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ ミサイル工場のコンベア (tileset: MissileTileset1)

MiscTileset128: @ 0x087D642C
	.4byte MiscTileset128_Tiles-. @ data: 0x087E9000 = .+76756
	.4byte 1024 | (832 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6438
		.4byte MiscTileset128_Pal-. @ data: 0x087E9400 = .+77768
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset129: @ 0x087D6440
	.4byte MiscTileset129_Tiles-. @ data: 0x087E9400 = .+77760
	.4byte 1024 | (832 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D644C
		.4byte MiscTileset129_Pal-. @ data: 0x087E9800 = .+78772
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset130: @ 0x087D6454
	.4byte MiscTileset130_Tiles-. @ data: 0x087E9800 = .+78764
	.4byte 1024 | (832 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6460
		.4byte MiscTileset130_Pal-. @ data: 0x087E9C00 = .+79776
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset131: @ 0x087D6468
	.4byte MiscTileset131_Tiles-. @ data: 0x087E9C00 = .+79768
	.4byte 1024 | (832 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6474
		.4byte MiscTileset131_Pal-. @ data: 0x087EA000 = .+80780
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset132: @ 0x087D647C
	.4byte MiscTileset132_Tiles-. @ data: 0x087EA000 = .+80772
	.4byte 1024 | (832 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6488
		.4byte MiscTileset132_Pal-. @ data: 0x087EA400 = .+81784
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset133: @ 0x087D6490
	.4byte MiscTileset133_Tiles-. @ data: 0x087EA400 = .+81776
	.4byte 1024 | (832 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D649C
		.4byte MiscTileset133_Pal-. @ data: 0x087EA800 = .+82788
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset134: @ 0x087D64A4
	.4byte MiscTileset134_Tiles-. @ data: 0x087EA800 = .+82780
	.4byte 1024 | (832 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D64B0
		.4byte MiscTileset134_Pal-. @ data: 0x087EAC00 = .+83792
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset135: @ 0x087D64B8
	.4byte MiscTileset135_Tiles-. @ data: 0x087EAC00 = .+83784
	.4byte 1024 | (832 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D64C4
		.4byte MiscTileset135_Pal-. @ data: 0x087EB000 = .+84796
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ ミサイル工場開始地点のコンソールパネル (tileset: MissileTileset0)

MiscTileset136: @ 0x087D64CC
	.4byte MiscTileset136_Tiles-. @ data: 0x087EB000 = .+84788
	.4byte 960 | (49 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 320, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D64D8
		.4byte MiscTileset136_Pal-. @ data: 0x087EB3C0 = .+85736
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset137: @ 0x087D64E0
	.4byte MiscTileset137_Tiles-. @ data: 0x087EB3C0 = .+85728
	.4byte 960 | (49 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 320, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D64EC
		.4byte MiscTileset137_Pal-. @ data: 0x087EB780 = .+86676
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset138: @ 0x087D64F4
	.4byte MiscTileset138_Tiles-. @ data: 0x087EB780 = .+86668
	.4byte 960 | (49 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 320, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6500
		.4byte MiscTileset138_Pal-. @ data: 0x087EBB40 = .+87616
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset139: @ 0x087D6508
	.4byte MiscTileset139_Tiles-. @ data: 0x087EBB40 = .+87608
	.4byte 960 | (49 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 320, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6514
		.4byte MiscTileset139_Pal-. @ data: 0x087EBF00 = .+88556
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ ミサイル内のパトランプ (tileset: MissileTileset3)

MiscTileset140: @ 0x087D651C
	.4byte MiscTileset140_Tiles-. @ data: 0x087EBF00 = .+88548
	.4byte 384 | (456 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6528
		.4byte MiscTileset140_Pal-. @ data: 0x087EC080 = .+88920
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset141: @ 0x087D6530
	.4byte MiscTileset141_Tiles-. @ data: 0x087EC080 = .+88912
	.4byte 384 | (456 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D653C
		.4byte MiscTileset141_Pal-. @ data: 0x087EC200 = .+89284
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset142: @ 0x087D6544
	.4byte MiscTileset142_Tiles-. @ data: 0x087EC200 = .+89276
	.4byte 384 | (456 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6550
		.4byte MiscTileset142_Pal-. @ data: 0x087EC380 = .+89648
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset143: @ 0x087D6558
	.4byte MiscTileset143_Tiles-. @ data: 0x087EC380 = .+89640
	.4byte 384 | (456 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6564
		.4byte MiscTileset143_Pal-. @ data: 0x087EC500 = .+90012
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset144: @ 0x087D656C
	.4byte MiscTileset144_Tiles-. @ data: 0x087EC500 = .+90004
	.4byte 384 | (456 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6578
		.4byte MiscTileset144_Pal-. @ data: 0x087EC680 = .+90376
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset145: @ 0x087D6580
	.4byte MiscTileset145_Tiles-. @ data: 0x087EC680 = .+90368
	.4byte 384 | (456 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D658C
		.4byte MiscTileset145_Pal-. @ data: 0x087EC800 = .+90740
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset146: @ 0x087D6594
	.4byte MiscTileset146_Tiles-. @ data: 0x087EC800 = .+90732
	.4byte 384 | (456 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D65A0
		.4byte MiscTileset146_Pal-. @ data: 0x087EC980 = .+91104
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset147: @ 0x087D65A8
	.4byte MiscTileset147_Tiles-. @ data: 0x087EC980 = .+91096
	.4byte 384 | (456 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D65B4
		.4byte MiscTileset147_Pal-. @ data: 0x087ECB00 = .+91468
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ ミサイルが着弾した後のビルの煙 (tileset: MissileTileset6)

MiscTileset148: @ 0x087D65BC
	.4byte MiscTileset148_Tiles-. @ data: 0x087ECB00 = .+91460
	.4byte 7168 | (736 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1024, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D65C8
		.4byte MiscTileset148_Pal-. @ data: 0x087EE700 = .+98616
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset149: @ 0x087D65D0
	.4byte MiscTileset149_Tiles-. @ data: 0x087EE700 = .+98608
	.4byte 7168 | (736 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1024, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D65DC
		.4byte MiscTileset149_Pal-. @ data: 0x087F0300 = .+105764
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset150: @ 0x087D65E4
	.4byte MiscTileset150_Tiles-. @ data: 0x087F0300 = .+105756
	.4byte 7168 | (736 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1024, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D65F0
		.4byte MiscTileset150_Pal-. @ data: 0x087F1F00 = .+112912
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset151: @ 0x087D65F8
	.4byte MiscTileset151_Tiles-. @ data: 0x087F1F00 = .+112904
	.4byte 7168 | (736 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1024, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6604
		.4byte MiscTileset151_Pal-. @ data: 0x087F3B00 = .+120060
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset152: @ 0x087D660C
	.4byte MiscTileset152_Tiles-. @ data: 0x087F3B00 = .+120052
	.4byte 7168 | (736 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1024, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6618
		.4byte MiscTileset152_Pal-. @ data: 0x087F5700 = .+127208
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ "巨大エレベーター"の巨大エレベーター(tileset: ElevatorTileset2)

MiscTileset153: @ 0x087D6620
	.4byte MiscTileset153_Tiles-. @ data: 0x087F5700 = .+127200
	.4byte 1920 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 320, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D662C
		.4byte MiscTileset153_Pal-. @ data: 0x087F5E80 = .+129108
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset154: @ 0x087D6634
	.4byte MiscTileset154_Tiles-. @ data: 0x087F5E80 = .+129100
	.4byte 1920 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 320, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6640
		.4byte MiscTileset154_Pal-. @ data: 0x087F6600 = .+131008
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset155: @ 0x087D6648
	.4byte MiscTileset155_Tiles-. @ data: 0x087F6600 = .+131000
	.4byte 1920 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 320, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6654
		.4byte MiscTileset155_Pal-. @ data: 0x087F6D80 = .+132908
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset156: @ 0x087D665C
	.4byte MiscTileset156_Tiles-. @ data: 0x087F6D80 = .+132900
	.4byte 1920 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 320, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6668
		.4byte MiscTileset156_Pal-. @ data: 0x087F7500 = .+134808
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset157: @ 0x087D6670
	.4byte MiscTileset157_Tiles-. @ data: 0x087F7500 = .+134800
	.4byte 1920 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 320, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D667C
		.4byte MiscTileset157_Pal-. @ data: 0x087F7C80 = .+136708
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ アナトレーの森のおめめ (tileset: ForestTileset2)

MiscTileset158: @ 0x087D6684
	.4byte MiscTileset158_Tiles-. @ data: 0x087F7C80 = .+136700
	.4byte 128 | (213 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6690
		.4byte MiscTileset158_Pal-. @ data: 0x087F7D00 = .+136816
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset159: @ 0x087D6698
	.4byte MiscTileset159_Tiles-. @ data: 0x087F7D00 = .+136808
	.4byte 128 | (213 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D66A4
		.4byte MiscTileset159_Pal-. @ data: 0x087F7D80 = .+136924
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset160: @ 0x087D66AC
	.4byte MiscTileset160_Tiles-. @ data: 0x087F7D80 = .+136916
	.4byte 128 | (213 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D66B8
		.4byte MiscTileset160_Pal-. @ data: 0x087F7E00 = .+137032
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ 海上のハイウェイ基地後半の背景の水槽みたいなやつ (tileset: WatersideTileset2)

MiscTileset161: @ 0x087D66C0
	.4byte MiscTileset161_Tiles-. @ data: 0x087F7E00 = .+137024
	.4byte 2688 | (256 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D66CC
		.4byte MiscTileset161_Pal-. @ data: 0x087F8880 = .+139700
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset162: @ 0x087D66D4
	.4byte MiscTileset162_Tiles-. @ data: 0x087F8880 = .+139692
	.4byte 2688 | (256 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D66E0
		.4byte MiscTileset162_Pal-. @ data: 0x087F9300 = .+142368
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset163: @ 0x087D66E8
	.4byte MiscTileset163_Tiles-. @ data: 0x087F9300 = .+142360
	.4byte 2688 | (256 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D66F4
		.4byte MiscTileset163_Pal-. @ data: 0x087F9D80 = .+145036
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset164: @ 0x087D66FC
	.4byte MiscTileset164_Tiles-. @ data: 0x087F9D80 = .+145028
	.4byte 2688 | (256 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6708
		.4byte MiscTileset164_Pal-. @ data: 0x087FA800 = .+147704
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset165: @ 0x087D6710
	.4byte MiscTileset165_Tiles-. @ data: 0x087FA800 = .+147696
	.4byte 2688 | (256 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D671C
		.4byte MiscTileset165_Pal-. @ data: 0x087FB280 = .+150372
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset166: @ 0x087D6724
	.4byte MiscTileset166_Tiles-. @ data: 0x087FB280 = .+150364
	.4byte 2688 | (256 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6730
		.4byte MiscTileset166_Pal-. @ data: 0x087FBD00 = .+153040
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset167: @ 0x087D6738
	.4byte MiscTileset167_Tiles-. @ data: 0x087FBD00 = .+153032
	.4byte 2688 | (256 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6744
		.4byte MiscTileset167_Pal-. @ data: 0x087FC780 = .+155708
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset168: @ 0x087D674C
	.4byte MiscTileset168_Tiles-. @ data: 0x087FC780 = .+155700
	.4byte 2688 | (256 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6758
		.4byte MiscTileset168_Pal-. @ data: 0x087FD200 = .+158376
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ 海上のハイウェイ基地の中ボス部屋のプロペラみたいなやつ (tileset: WatersideTileset2)

MiscTileset169: @ 0x087D6760
	.4byte MiscTileset169_Tiles-. @ data: 0x087FD200 = .+158368
	.4byte 512 | (128 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D676C
		.4byte MiscTileset169_Pal-. @ data: 0x087FD400 = .+158868
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset170: @ 0x087D6774
	.4byte MiscTileset170_Tiles-. @ data: 0x087FD400 = .+158860
	.4byte 512 | (128 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6780
		.4byte MiscTileset170_Pal-. @ data: 0x087FD600 = .+159360
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset171: @ 0x087D6788
	.4byte MiscTileset171_Tiles-. @ data: 0x087FD600 = .+159352
	.4byte 512 | (128 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D6794
		.4byte MiscTileset171_Pal-. @ data: 0x087FD800 = .+159852
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Volteel Biblio "Electric Cage" (ボスラッシュ部屋), tileset: WeilLaboTileset2

MiscTileset172: @ 0x087D679C
	.4byte MiscTileset172_Tiles-. @ data: 0x087FD800 = .+159844
	.4byte 2048 | (16 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D67A8
		.4byte MiscTileset172_Pal-. @ data: 0x087FE000 = .+161880
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset173: @ 0x087D67B0
	.4byte MiscTileset173_Tiles-. @ data: 0x087FE000 = .+161872
	.4byte 2048 | (16 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D67BC
		.4byte MiscTileset173_Pal-. @ data: 0x087FE800 = .+163908
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset174: @ 0x087D67C4
	.4byte MiscTileset174_Tiles-. @ data: 0x087FE800 = .+163900
	.4byte 2048 | (16 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D67D0
		.4byte MiscTileset174_Pal-. @ data: 0x087FF000 = .+165936
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset175: @ 0x087D67D8
	.4byte MiscTileset175_Tiles-. @ data: 0x087FF000 = .+165928
	.4byte 2048 | (16 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D67E4
		.4byte MiscTileset175_Pal-. @ data: 0x087FF800 = .+167964
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

MiscTileset176: @ 0x087D67EC
	.4byte MiscTileset176_Tiles-. @ data: 0x087FF800 = .+167956
	.4byte 2048 | (16 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (MAP2D | NO_PAL | BPP4) 	@ rowsize, props
	@ Palette 0x087D67F8
		.4byte MiscTileset176_Pal-. @ data: 0x08800000 = .+169992
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

MiscTileset0_Tiles:
	.incbin "data/tilesets/misc/lava0/0.4bpp"
MiscTileset0_Pal:

MiscTileset1_Tiles:
	.incbin "data/tilesets/misc/lava0/1.4bpp"
MiscTileset1_Pal:

MiscTileset2_Tiles:
	.incbin "data/tilesets/misc/lava0/2.4bpp"
MiscTileset2_Pal:

MiscTileset3_Tiles:
	.incbin "data/tilesets/misc/lava0/3.4bpp"
MiscTileset3_Pal:

MiscTileset4_Tiles:
	.incbin "data/tilesets/misc/lava0/4.4bpp"
MiscTileset4_Pal:

MiscTileset5_Tiles:
	.incbin "data/tilesets/misc/screwspike/5.4bpp"
MiscTileset5_Pal:

MiscTileset6_Tiles:
	.incbin "data/tilesets/misc/screwspike/6.4bpp"
MiscTileset6_Pal:

MiscTileset7_Tiles:
	.incbin "data/tilesets/misc/screwspike/7.4bpp"
MiscTileset7_Pal:

MiscTileset8_Tiles:
	.incbin "data/tilesets/misc/screwspike/8.4bpp"
MiscTileset8_Pal:

MiscTileset9_Tiles:
	.incbin "data/tilesets/misc/lava_glass/0.4bpp"
MiscTileset9_Pal:

MiscTileset10_Tiles:
	.incbin "data/tilesets/misc/lava_glass/1.4bpp"
MiscTileset10_Pal:

MiscTileset11_Tiles:
	.incbin "data/tilesets/misc/lava_glass/2.4bpp"
MiscTileset11_Pal:

MiscTileset12_Tiles:
	.incbin "data/tilesets/misc/lava_glass/3.4bpp"
MiscTileset12_Pal:

MiscTileset13_Tiles:
	.incbin "data/tilesets/misc/lava_glass/4.4bpp"
MiscTileset13_Pal:

MiscTileset14_Tiles:
	.incbin "data/tilesets/misc/screwspike14/0.4bpp"
MiscTileset14_Pal:

MiscTileset15_Tiles:
	.incbin "data/tilesets/misc/screwspike14/1.4bpp"
MiscTileset15_Pal:

MiscTileset16_Tiles:
	.incbin "data/tilesets/misc/screwspike14/2.4bpp"
MiscTileset16_Pal:

MiscTileset17_Tiles:
	.incbin "data/tilesets/misc/screwspike14/3.4bpp"
MiscTileset17_Pal:

MiscTileset18_Tiles:
	.incbin "data/tilesets/misc/eruption/0.4bpp"
MiscTileset18_Pal:

MiscTileset19_Tiles:
	.incbin "data/tilesets/misc/eruption/1.4bpp"
MiscTileset19_Pal:

MiscTileset20_Tiles:
	.incbin "data/tilesets/misc/eruption/2.4bpp"
MiscTileset20_Pal:

MiscTileset21_Tiles:
	.incbin "data/tilesets/misc/eruption/3.4bpp"
MiscTileset21_Pal:

MiscTileset22_Tiles:
	.incbin "data/tilesets/misc/eruption/4.4bpp"
MiscTileset22_Pal:

MiscTileset23_Tiles:
	.incbin "data/tilesets/misc/eruption/5.4bpp"
MiscTileset23_Pal:

MiscTileset24_Tiles:
	.incbin "data/tilesets/misc/eruption/6.4bpp"
MiscTileset24_Pal:

MiscTileset25_Tiles:
	.incbin "data/tilesets/misc/lavariver/0.4bpp"
MiscTileset25_Pal:

MiscTileset26_Tiles:
	.incbin "data/tilesets/misc/lavariver/1.4bpp"
MiscTileset26_Pal:

MiscTileset27_Tiles:
	.incbin "data/tilesets/misc/lavariver/2.4bpp"
MiscTileset27_Pal:

MiscTileset28_Tiles:
	.incbin "data/tilesets/misc/lavariver/3.4bpp"
MiscTileset28_Pal:

MiscTileset29_Tiles:
MiscTileset29_Pal:

MiscTileset30_Tiles:
MiscTileset30_Pal:

MiscTileset31_Tiles:
MiscTileset31_Pal:

MiscTileset32_Tiles:
MiscTileset32_Pal:

MiscTileset33_Tiles:
	.incbin "data/tilesets/misc/repair_factory_conveyor/0.4bpp"
MiscTileset33_Pal:

MiscTileset34_Tiles:
	.incbin "data/tilesets/misc/repair_factory_conveyor/1.4bpp"
MiscTileset34_Pal:

MiscTileset35_Tiles:
	.incbin "data/tilesets/misc/repair_factory_conveyor/2.4bpp"
MiscTileset35_Pal:

MiscTileset36_Tiles:
	.incbin "data/tilesets/misc/repair_factory_conveyor/3.4bpp"
MiscTileset36_Pal:

MiscTileset37_Tiles:
	.incbin "data/tilesets/misc/iron_scrap/0.4bpp"
MiscTileset37_Pal:

MiscTileset38_Tiles:
	.incbin "data/tilesets/misc/iron_scrap/1.4bpp"
MiscTileset38_Pal:

MiscTileset39_Tiles:
	.incbin "data/tilesets/misc/iron_scrap/2.4bpp"
MiscTileset39_Pal:

MiscTileset40_Tiles:
	.incbin "data/tilesets/misc/iron_scrap/3.4bpp"
MiscTileset40_Pal:

MiscTileset41_Tiles:
	.incbin "data/tilesets/misc/iron_scrap/4.4bpp"
MiscTileset41_Pal:

MiscTileset42_Tiles:
	.incbin "data/tilesets/misc/mushroom1/0.4bpp"
MiscTileset42_Pal:

MiscTileset43_Tiles:
	.incbin "data/tilesets/misc/mushroom1/1.4bpp"
MiscTileset43_Pal:

MiscTileset44_Tiles:
	.incbin "data/tilesets/misc/mushroom1/2.4bpp"
MiscTileset44_Pal:

MiscTileset45_Tiles:
	.incbin "data/tilesets/misc/mushroom1/3.4bpp"
MiscTileset45_Pal:

MiscTileset46_Tiles:
	.incbin "data/tilesets/misc/mushroom1/4.4bpp"
MiscTileset46_Pal:

MiscTileset47_Tiles:
	.incbin "data/tilesets/misc/mushroom2/0.4bpp"
MiscTileset47_Pal:

MiscTileset48_Tiles:
	.incbin "data/tilesets/misc/mushroom2/1.4bpp"
MiscTileset48_Pal:

MiscTileset49_Tiles:
	.incbin "data/tilesets/misc/mushroom2/2.4bpp"
MiscTileset49_Pal:

MiscTileset50_Tiles:
	.incbin "data/tilesets/misc/mushroom2/3.4bpp"
MiscTileset50_Pal:

MiscTileset51_Tiles:
	.incbin "data/tilesets/misc/mushroom3/0.4bpp"
MiscTileset51_Pal:

MiscTileset52_Tiles:
	.incbin "data/tilesets/misc/mushroom3/1.4bpp"
MiscTileset52_Pal:

MiscTileset53_Tiles:
	.incbin "data/tilesets/misc/mushroom3/2.4bpp"
MiscTileset53_Pal:

MiscTileset54_Tiles:
	.incbin "data/tilesets/misc/mushroom3/3.4bpp"
MiscTileset54_Pal:

MiscTileset55_Tiles:
	.incbin "data/tilesets/misc/mushroom3/4.4bpp"
MiscTileset55_Pal:

MiscTileset56_Tiles:
	.incbin "data/tilesets/misc/wood56/0.4bpp"
MiscTileset56_Pal:

MiscTileset57_Tiles:
	.incbin "data/tilesets/misc/wood56/1.4bpp"
MiscTileset57_Pal:

MiscTileset58_Tiles:
	.incbin "data/tilesets/misc/cmd_teleporter_emission/0.4bpp"
MiscTileset58_Pal:

MiscTileset59_Tiles:
	.incbin "data/tilesets/misc/cmd_teleporter_emission/1.4bpp"
MiscTileset59_Pal:

MiscTileset60_Tiles:
	.incbin "data/tilesets/misc/cmd_teleporter_emission/2.4bpp"
MiscTileset60_Pal:

MiscTileset61_Tiles:
	.incbin "data/tilesets/misc/cmd_teleporter_emission/3.4bpp"
MiscTileset61_Pal:

MiscTileset62_Tiles:
	.incbin "data/tilesets/misc/cmd_teleporter_emission/4.4bpp"
MiscTileset62_Pal:

MiscTileset63_Tiles:
	.incbin "data/tilesets/misc/cmd_teleporter_emission/5.4bpp"
MiscTileset63_Pal:

MiscTileset64_Tiles:
	.incbin "data/tilesets/misc/cmd_teleporter_emission/6.4bpp"
MiscTileset64_Pal:

MiscTileset65_Tiles:
	.incbin "data/tilesets/misc/cmd_teleporter_emission/7.4bpp"
MiscTileset65_Pal:

MiscTileset66_Tiles:
	.incbin "data/tilesets/misc/frontlinebase_pipeline/0.4bpp"
MiscTileset66_Pal:

MiscTileset67_Tiles:
	.incbin "data/tilesets/misc/frontlinebase_pipeline/1.4bpp"
MiscTileset67_Pal:

MiscTileset68_Tiles:
	.incbin "data/tilesets/misc/frontlinebase_pipeline/2.4bpp"
MiscTileset68_Pal:

MiscTileset69_Tiles:
	.incbin "data/tilesets/misc/frontlinebase_pipeline/3.4bpp"
MiscTileset69_Pal:

MiscTileset70_Tiles:
	.incbin "data/tilesets/misc/frontlinebase_pipeline/4.4bpp"
MiscTileset70_Pal:

MiscTileset71_Tiles:
	.incbin "data/tilesets/misc/frontlinebase_pipeline/5.4bpp"
MiscTileset71_Pal:

MiscTileset72_Tiles:
	.incbin "data/tilesets/misc/electricleakage/0.4bpp"
MiscTileset72_Pal:

MiscTileset73_Tiles:
	.incbin "data/tilesets/misc/electricleakage/1.4bpp"
MiscTileset73_Pal:

MiscTileset74_Tiles:
	.incbin "data/tilesets/misc/electricleakage/2.4bpp"
MiscTileset74_Pal:

MiscTileset75_Tiles:
	.incbin "data/tilesets/misc/electricleakage/3.4bpp"
MiscTileset75_Pal:

MiscTileset76_Tiles:
	.incbin "data/tilesets/misc/electricleakage/4.4bpp"
MiscTileset76_Pal:

MiscTileset77_Tiles:
	.incbin "data/tilesets/misc/electricleakage/5.4bpp"
MiscTileset77_Pal:

MiscTileset78_Tiles:
	.incbin "data/tilesets/misc/elecarc/0.4bpp"
MiscTileset78_Pal:

MiscTileset79_Tiles:
	.incbin "data/tilesets/misc/elecarc/1.4bpp"
MiscTileset79_Pal:

MiscTileset80_Tiles:
	.incbin "data/tilesets/misc/elecarc/2.4bpp"
MiscTileset80_Pal:

MiscTileset81_Tiles:
	.incbin "data/tilesets/misc/elecarc/3.4bpp"
MiscTileset81_Pal:

MiscTileset82_Tiles:
	.incbin "data/tilesets/misc/elecarc/4.4bpp"
MiscTileset82_Pal:

MiscTileset83_Tiles:
	.incbin "data/tilesets/misc/eleccage/0.4bpp"
MiscTileset83_Pal:

MiscTileset84_Tiles:
	.incbin "data/tilesets/misc/eleccage/1.4bpp"
MiscTileset84_Pal:

MiscTileset85_Tiles:
	.incbin "data/tilesets/misc/eleccage/2.4bpp"
MiscTileset85_Pal:

MiscTileset86_Tiles:
	.incbin "data/tilesets/misc/eleccage/3.4bpp"
MiscTileset86_Pal:

MiscTileset87_Tiles:
	.incbin "data/tilesets/misc/eleccage/4.4bpp"
MiscTileset87_Pal:

MiscTileset88_Tiles:
	.incbin "data/tilesets/misc/prologue_snow/0.4bpp"
MiscTileset88_Pal:

MiscTileset89_Tiles:
	.incbin "data/tilesets/misc/prologue_snow/1.4bpp"
MiscTileset89_Pal:

MiscTileset90_Tiles:
	.incbin "data/tilesets/misc/prologue_snow/2.4bpp"
MiscTileset90_Pal:

MiscTileset91_Tiles:
	.incbin "data/tilesets/misc/prologue_snow/3.4bpp"
MiscTileset91_Pal:

MiscTileset92_Tiles:
	.incbin "data/tilesets/misc/factory92.4bpp"
MiscTileset92_Pal:

MiscTileset93_Tiles:
	.incbin "data/tilesets/misc/unk93/0.4bpp"
MiscTileset93_Pal:

MiscTileset94_Tiles:
	.incbin "data/tilesets/misc/unk93/1.4bpp"
MiscTileset94_Pal:

MiscTileset95_Tiles:
	.incbin "data/tilesets/misc/unk93/2.4bpp"
MiscTileset95_Pal:

MiscTileset96_Tiles:
	.incbin "data/tilesets/misc/unk93/3.4bpp"
MiscTileset96_Pal:

MiscTileset97_Tiles:
	.incbin "data/tilesets/misc/unk93/4.4bpp"
MiscTileset97_Pal:

MiscTileset98_Tiles:
	.incbin "data/tilesets/misc/energyfacilitycrystal/0.4bpp"
MiscTileset98_Pal:

MiscTileset99_Tiles:
	.incbin "data/tilesets/misc/energyfacilitycrystal/1.4bpp"
MiscTileset99_Pal:

MiscTileset100_Tiles:
	.incbin "data/tilesets/misc/energyfacilitycrystal/2.4bpp"
MiscTileset100_Pal:

MiscTileset101_Tiles:
	.incbin "data/tilesets/misc/unk101/0.4bpp"
MiscTileset101_Pal:

MiscTileset102_Tiles:
	.incbin "data/tilesets/misc/unk101/1.4bpp"
MiscTileset102_Pal:

MiscTileset103_Tiles:
	.incbin "data/tilesets/misc/unk101/2.4bpp"
MiscTileset103_Pal:

MiscTileset104_Tiles:
	.incbin "data/tilesets/misc/unk101/3.4bpp"
MiscTileset104_Pal:

MiscTileset105_Tiles:
	.incbin "data/tilesets/misc/unk101/4.4bpp"
MiscTileset105_Pal:

MiscTileset106_Tiles:
	.incbin "data/tilesets/misc/unk101/5.4bpp"
MiscTileset106_Pal:

MiscTileset107_Tiles:
	.incbin "data/tilesets/misc/unk101/6.4bpp"
MiscTileset107_Pal:

MiscTileset108_Tiles:
	.incbin "data/tilesets/misc/unk101/7.4bpp"
MiscTileset108_Pal:

MiscTileset109_Tiles:
	.incbin "data/tilesets/misc/unk101/8.4bpp"
MiscTileset109_Pal:

MiscTileset110_Tiles:
	.incbin "data/tilesets/misc/fan/0.4bpp"
MiscTileset110_Pal:

MiscTileset111_Tiles:
	.incbin "data/tilesets/misc/fan/1.4bpp"
MiscTileset111_Pal:

MiscTileset112_Tiles:
	.incbin "data/tilesets/misc/elecmeter/0.4bpp"
MiscTileset112_Pal:

MiscTileset113_Tiles:
	.incbin "data/tilesets/misc/elecmeter/1.4bpp"
MiscTileset113_Pal:

MiscTileset114_Tiles:
	.incbin "data/tilesets/misc/elecmeter/2.4bpp"
MiscTileset114_Pal:

MiscTileset115_Tiles:
	.incbin "data/tilesets/misc/elecmeter/3.4bpp"
MiscTileset115_Pal:

MiscTileset116_Tiles:
	.incbin "data/tilesets/misc/energyfacilityliquid/0.4bpp"
MiscTileset116_Pal:

MiscTileset117_Tiles:
	.incbin "data/tilesets/misc/energyfacilityliquid/1.4bpp"
MiscTileset117_Pal:

MiscTileset118_Tiles:
	.incbin "data/tilesets/misc/energyfacilityliquid/2.4bpp"
MiscTileset118_Pal:

MiscTileset119_Tiles:
	.incbin "data/tilesets/misc/energyfacilityliquid/3.4bpp"
MiscTileset119_Pal:

MiscTileset120_Tiles:
	.incbin "data/tilesets/misc/energyfacilityliquid/4.4bpp"
MiscTileset120_Pal:

MiscTileset121_Tiles:
	.incbin "data/tilesets/misc/energyfacilityliquid/5.4bpp"
MiscTileset121_Pal:

MiscTileset122_Tiles:
	.incbin "data/tilesets/misc/energyfacilityliquid/6.4bpp"
MiscTileset122_Pal:

MiscTileset123_Tiles:
	.incbin "data/tilesets/misc/energyfacilityliquid/7.4bpp"
MiscTileset123_Pal:

MiscTileset124_Tiles:
	.incbin "data/tilesets/misc/energyfacility124/0.4bpp"
MiscTileset124_Pal:

MiscTileset125_Tiles:
	.incbin "data/tilesets/misc/energyfacility124/1.4bpp"
MiscTileset125_Pal:

MiscTileset126_Tiles:
	.incbin "data/tilesets/misc/energyfacility124/2.4bpp"
MiscTileset126_Pal:

MiscTileset127_Tiles:
	.incbin "data/tilesets/misc/energyfacility124/3.4bpp"
MiscTileset127_Pal:

MiscTileset128_Tiles:
	.incbin "data/tilesets/misc/missile_conveyor/0.4bpp"
MiscTileset128_Pal:

MiscTileset129_Tiles:
	.incbin "data/tilesets/misc/missile_conveyor/1.4bpp"
MiscTileset129_Pal:

MiscTileset130_Tiles:
	.incbin "data/tilesets/misc/missile_conveyor/2.4bpp"
MiscTileset130_Pal:

MiscTileset131_Tiles:
	.incbin "data/tilesets/misc/missile_conveyor/3.4bpp"
MiscTileset131_Pal:

MiscTileset132_Tiles:
	.incbin "data/tilesets/misc/missile_conveyor/4.4bpp"
MiscTileset132_Pal:

MiscTileset133_Tiles:
	.incbin "data/tilesets/misc/missile_conveyor/5.4bpp"
MiscTileset133_Pal:

MiscTileset134_Tiles:
	.incbin "data/tilesets/misc/missile_conveyor/6.4bpp"
MiscTileset134_Pal:

MiscTileset135_Tiles:
	.incbin "data/tilesets/misc/missile_conveyor/7.4bpp"
MiscTileset135_Pal:

MiscTileset136_Tiles:
	.incbin "data/tilesets/misc/missile_console/0.4bpp"
MiscTileset136_Pal:

MiscTileset137_Tiles:
	.incbin "data/tilesets/misc/missile_console/1.4bpp"
MiscTileset137_Pal:

MiscTileset138_Tiles:
	.incbin "data/tilesets/misc/missile_console/2.4bpp"
MiscTileset138_Pal:

MiscTileset139_Tiles:
	.incbin "data/tilesets/misc/missile_console/3.4bpp"
MiscTileset139_Pal:

MiscTileset140_Tiles:
	.incbin "data/tilesets/misc/missile_beacon_light/0.4bpp"
MiscTileset140_Pal:

MiscTileset141_Tiles:
	.incbin "data/tilesets/misc/missile_beacon_light/1.4bpp"
MiscTileset141_Pal:

MiscTileset142_Tiles:
	.incbin "data/tilesets/misc/missile_beacon_light/2.4bpp"
MiscTileset142_Pal:

MiscTileset143_Tiles:
	.incbin "data/tilesets/misc/missile_beacon_light/3.4bpp"
MiscTileset143_Pal:

MiscTileset144_Tiles:
	.incbin "data/tilesets/misc/missile_beacon_light/4.4bpp"
MiscTileset144_Pal:

MiscTileset145_Tiles:
	.incbin "data/tilesets/misc/missile_beacon_light/5.4bpp"
MiscTileset145_Pal:

MiscTileset146_Tiles:
	.incbin "data/tilesets/misc/missile_beacon_light/6.4bpp"
MiscTileset146_Pal:

MiscTileset147_Tiles:
	.incbin "data/tilesets/misc/missile_beacon_light/7.4bpp"
MiscTileset147_Pal:

MiscTileset148_Tiles:
	.incbin "data/tilesets/misc/missile_building_smoke/0.4bpp"
MiscTileset148_Pal:

MiscTileset149_Tiles:
	.incbin "data/tilesets/misc/missile_building_smoke/1.4bpp"
MiscTileset149_Pal:

MiscTileset150_Tiles:
	.incbin "data/tilesets/misc/missile_building_smoke/2.4bpp"
MiscTileset150_Pal:

MiscTileset151_Tiles:
	.incbin "data/tilesets/misc/missile_building_smoke/3.4bpp"
MiscTileset151_Pal:

MiscTileset152_Tiles:
	.incbin "data/tilesets/misc/missile_building_smoke/4.4bpp"
MiscTileset152_Pal:

MiscTileset153_Tiles:
	.incbin "data/tilesets/misc/giant_elevator_platform/0.4bpp"
MiscTileset153_Pal:

MiscTileset154_Tiles:
	.incbin "data/tilesets/misc/giant_elevator_platform/1.4bpp"
MiscTileset154_Pal:

MiscTileset155_Tiles:
	.incbin "data/tilesets/misc/giant_elevator_platform/2.4bpp"
MiscTileset155_Pal:

MiscTileset156_Tiles:
	.incbin "data/tilesets/misc/giant_elevator_platform/3.4bpp"
MiscTileset156_Pal:

MiscTileset157_Tiles:
	.incbin "data/tilesets/misc/giant_elevator_platform/4.4bpp"
MiscTileset157_Pal:

MiscTileset158_Tiles:
	.incbin "data/tilesets/misc/anatre_sphere_crystal/0.4bpp"
MiscTileset158_Pal:

MiscTileset159_Tiles:
	.incbin "data/tilesets/misc/anatre_sphere_crystal/1.4bpp"
MiscTileset159_Pal:

MiscTileset160_Tiles:
	.incbin "data/tilesets/misc/anatre_sphere_crystal/2.4bpp"
MiscTileset160_Pal:

MiscTileset161_Tiles:
	.incbin "data/tilesets/misc/ocean_aquarium/0.4bpp"
MiscTileset161_Pal:

MiscTileset162_Tiles:
	.incbin "data/tilesets/misc/ocean_aquarium/1.4bpp"
MiscTileset162_Pal:

MiscTileset163_Tiles:
	.incbin "data/tilesets/misc/ocean_aquarium/2.4bpp"
MiscTileset163_Pal:

MiscTileset164_Tiles:
	.incbin "data/tilesets/misc/ocean_aquarium/3.4bpp"
MiscTileset164_Pal:

MiscTileset165_Tiles:
	.incbin "data/tilesets/misc/ocean_aquarium/4.4bpp"
MiscTileset165_Pal:

MiscTileset166_Tiles:
	.incbin "data/tilesets/misc/ocean_aquarium/5.4bpp"
MiscTileset166_Pal:

MiscTileset167_Tiles:
	.incbin "data/tilesets/misc/ocean_aquarium/6.4bpp"
MiscTileset167_Pal:

MiscTileset168_Tiles:
	.incbin "data/tilesets/misc/ocean_aquarium/7.4bpp"
MiscTileset168_Pal:

MiscTileset169_Tiles:
	.incbin "data/tilesets/misc/ocean_propeller_pump/0.4bpp"
MiscTileset169_Pal:

MiscTileset170_Tiles:
	.incbin "data/tilesets/misc/ocean_propeller_pump/1.4bpp"
MiscTileset170_Pal:

MiscTileset171_Tiles:
	.incbin "data/tilesets/misc/ocean_propeller_pump/2.4bpp"
MiscTileset171_Pal:

MiscTileset172_Tiles:
	.incbin "data/tilesets/misc/eleccage2/0.4bpp"
MiscTileset172_Pal:

MiscTileset173_Tiles:
	.incbin "data/tilesets/misc/eleccage2/1.4bpp"
MiscTileset173_Pal:

MiscTileset174_Tiles:
	.incbin "data/tilesets/misc/eleccage2/2.4bpp"
MiscTileset174_Pal:

MiscTileset175_Tiles:
	.incbin "data/tilesets/misc/eleccage2/3.4bpp"
MiscTileset175_Pal:

MiscTileset176_Tiles:
	.incbin "data/tilesets/misc/eleccage2/4.4bpp"
MiscTileset176_Pal:
