  .include "asm/macros.inc"

.section .rodata
.balign 4, 0

.global gStaticMotionGraphics
gStaticMotionGraphics:
CommonEffect: @ Graphic 0
	.4byte CommonEffect_Tiles-. @ src
	.4byte 2816 | (160 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1592, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte CommonEffect_Pal-. @ src offset
		.2byte 64 @ bytesize
		.byte 0, 14 @ lz77(bool8), dst = PaletteID

	@ Graphic 1
	.4byte gStaticMotionGraphics_1-. @ src
	.4byte 1328 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 400, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_1_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 8 @ lz77(bool8), dst = PaletteID

Lemon: @ Graphic 2
	.4byte Lemon_Tiles-. @ src
	.4byte 96 | (359 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 24, (LZ77 | BPP4 | NO_PAL) 	@ rowsize(unused), props
		@ Palette
		.4byte Lemon_Pal-. @ src offset
		.2byte 0 @ bytesize
		.byte 0, 14 @ lz77(bool8), dst = PaletteID

EmotionBubble: @ Graphic 3
	.4byte EmotionBubble_Tiles-. @ src
	.4byte 192 | (362 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (BPP4 | NO_PAL) 	@ rowsize(unused), props
		@ Palette
		.4byte EmotionBubble_Pal-. @ src offset
		.2byte 0 @ bytesize
		.byte 0, 14 @ lz77(bool8), dst = PaletteID

ShotCounter: @ Graphic 4
	.4byte ShotCounter_Tiles-. @ src
	.4byte 1792 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 448, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte ShotCounter_Pal-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 5
	.4byte gStaticMotionGraphics_5-. @ src
	.4byte 128 | (896 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 56, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_5_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 6
	.4byte gStaticMotionGraphics_6-. @ src
	.4byte 3104 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 776, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_6_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 7
	.4byte gStaticMotionGraphics_7-. @ src
	.4byte 1312 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 328, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_7_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 8
	.4byte gStaticMotionGraphics_8-. @ src
	.4byte 2240 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 560, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_8_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 9
	.4byte gStaticMotionGraphics_9-. @ src
	.4byte 2228 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1056, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_9_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 10
	.4byte gStaticMotionGraphics_10-. @ src
	.4byte 1940 | (644 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 992, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_10_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 11
	.4byte gStaticMotionGraphics_11-. @ src
	.4byte 880 | (768 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 304, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_11_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 12
	.4byte gStaticMotionGraphics_12-. @ src
	.4byte 640 | (806 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 160, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_12_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Graphic 13
	.4byte gStaticMotionGraphics_13-. @ src
	.4byte 4096 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1024, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_13_Palettes-. @ src offset
		.2byte 64 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 14
	.4byte gStaticMotionGraphics_14-. @ src
	.4byte 2608 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 976, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_14_Palettes-. @ src offset
		.2byte 64 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 15
	.4byte gStaticMotionGraphics_15-. @ src
	.4byte 1444 | (634 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 824, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_15_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 16
	.4byte gStaticMotionGraphics_16-. @ src
	.4byte 1248 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 312, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_16_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 17
	.4byte gStaticMotionGraphics_17-. @ src
	.4byte 2080 | (548 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 520, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_17_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 18
	.4byte gStaticMotionGraphics_18-. @ src
	.4byte 1024 | (480 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_18_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 10 @ lz77(bool8), dst = PaletteID

	@ Graphic 19
	.4byte gStaticMotionGraphics_19-. @ src
	.4byte 3840 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 960, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_19_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 20
	.4byte gStaticMotionGraphics_20-. @ src
	.4byte 4928 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1232, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_20_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 21
	.4byte gStaticMotionGraphics_21-. @ src
	.4byte 1024 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_21_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 22
	.4byte gStaticMotionGraphics_22-. @ src
	.4byte 512 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_22_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 23
	.4byte gStaticMotionGraphics_23-. @ src
	.4byte 3040 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 760, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_23_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 24
	.4byte gStaticMotionGraphics_24-. @ src
	.4byte 2880 | (908 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 720, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_24_Palettes-. @ src offset
		.2byte 64 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

	@ Graphic 25
	.4byte gStaticMotionGraphics_25-. @ src
	.4byte 4992 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1248, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_25_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 26
	.4byte gStaticMotionGraphics_26-. @ src
	.4byte 448 | (420 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 176, (LZ77 | BPP4 | NO_PAL) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_26_Palettes-. @ src offset
		.2byte 0 @ bytesize
		.byte 0, 15 @ lz77(bool8), dst = PaletteID

	@ Graphic 27
	.4byte gStaticMotionGraphics_27-. @ src
	.4byte 608 | (420 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 176, (LZ77 | BPP4 | NO_PAL) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_27_Palettes-. @ src offset
		.2byte 0 @ bytesize
		.byte 0, 14 @ lz77(bool8), dst = PaletteID

	@ Graphic 28
	.4byte gStaticMotionGraphics_28-. @ src
	.4byte 240 | (412 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (LZ77 | BPP4 | NO_PAL) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_28_Palettes-. @ src offset
		.2byte 0 @ bytesize
		.byte 0, 15 @ lz77(bool8), dst = PaletteID

	@ Graphic 29
	.4byte gStaticMotionGraphics_29-. @ src
	.4byte 2560 | (533 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 640, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_29_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 30
	.4byte gStaticMotionGraphics_30-. @ src
	.4byte 672 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 168, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_30_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 31
	.4byte gStaticMotionGraphics_31-. @ src
	.4byte 512 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_31_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 32
	.4byte gStaticMotionGraphics_32-. @ src
	.4byte 1984 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 496, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_32_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 33
	.4byte gStaticMotionGraphics_33-. @ src
	.4byte 472 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 200, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_33_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 34
	.4byte gStaticMotionGraphics_34-. @ src
	.4byte 920 | (537 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 320, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_34_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 35
	.4byte gStaticMotionGraphics_35-. @ src
	.4byte 440 | (577 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 160, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_35_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 36
	.4byte gStaticMotionGraphics_36-. @ src
	.4byte 672 | (640 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 272, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_36_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 37
	.4byte gStaticMotionGraphics_37-. @ src
	.4byte 1508 | (674 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 936, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_37_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 38
	.4byte gStaticMotionGraphics_38-. @ src
	.4byte 820 | (800 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 440, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_38_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Graphic 39
	.4byte gStaticMotionGraphics_39-. @ src
	.4byte 3072 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 768, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_39_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 40
	.4byte gStaticMotionGraphics_40-. @ src
	.4byte 2816 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 704, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_40_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 41
	.4byte gStaticMotionGraphics_41-. @ src
	.4byte 544 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 136, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_41_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 42
	.4byte gStaticMotionGraphics_42-. @ src
	.4byte 1024 | (832 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_42_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 8 @ lz77(bool8), dst = PaletteID

	@ Graphic 43
	.4byte gStaticMotionGraphics_43-. @ src
	.4byte 3948 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1792, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_43_Palettes-. @ src offset
		.2byte 64 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 44
	.4byte gStaticMotionGraphics_44-. @ src
	.4byte 816 | (768 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 304, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_44_Palettes-. @ src offset
		.2byte 64 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 45
	.4byte gStaticMotionGraphics_45-. @ src
	.4byte 448 | (644 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 112, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_45_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Graphic 46
	.4byte gStaticMotionGraphics_46-. @ src
	.4byte 3360 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 840, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_46_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 47
	.4byte gStaticMotionGraphics_47-. @ src
	.4byte 2560 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 640, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_47_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 48
	.4byte gStaticMotionGraphics_48-. @ src
	.4byte 388 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 160, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_48_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 49
	.4byte gStaticMotionGraphics_49-. @ src
	.4byte 1612 | (544 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 616, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_49_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 50
	.4byte gStaticMotionGraphics_50-. @ src
	.4byte 896 | (640 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_50_Palettes-. @ src offset
		.2byte 64 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Graphic 51
	.4byte gStaticMotionGraphics_51-. @ src
	.4byte 2016 | (704 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1224, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_51_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

	@ Graphic 52
	.4byte gStaticMotionGraphics_52-. @ src
	.4byte 1680 | (864 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1024, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_52_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 53
	.4byte gStaticMotionGraphics_53-. @ src
	.4byte 1472 | (908 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 368, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_53_Palettes-. @ src offset
		.2byte 64 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

	@ Graphic 54
	.4byte gStaticMotionGraphics_54-. @ src
	.4byte 1276 | (768 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_54_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 55
	.4byte gStaticMotionGraphics_55-. @ src
	.4byte 1208 | (832 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1040, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_55_Palettes-. @ src offset
		.2byte 128 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 56
	.4byte gStaticMotionGraphics_56-. @ src
	.4byte 1984 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 496, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_56_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 57
	.4byte gStaticMotionGraphics_57-. @ src
	.4byte 4640 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1160, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_57_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 58
	.4byte gStaticMotionGraphics_58-. @ src
	.4byte 960 | (704 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 240, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_58_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 59
	.4byte gStaticMotionGraphics_59-. @ src
	.4byte 768 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 192, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_59_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 60
	.4byte gStaticMotionGraphics_60-. @ src
	.4byte 480 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, (LZ77 | BPP4 | NO_PAL) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_60_Palettes-. @ src offset
		.2byte 0 @ bytesize
		.byte 0, 14 @ lz77(bool8), dst = PaletteID

	@ Graphic 61
	.4byte gStaticMotionGraphics_61-. @ src
	.4byte 928 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 232, (BPP4 | NO_PAL) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_61_Palettes-. @ src offset
		.2byte 0 @ bytesize
		.byte 0, 13 @ lz77(bool8), dst = PaletteID

	@ Graphic 62
	.4byte gStaticMotionGraphics_62-. @ src
	.4byte 3200 | (640 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 800, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_62_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 63
	.4byte gStaticMotionGraphics_63-. @ src
	.4byte 2432 | (640 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 608, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_63_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 64
	.4byte gStaticMotionGraphics_64-. @ src
	.4byte 732 | (808 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 248, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_64_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 8 @ lz77(bool8), dst = PaletteID

	@ Graphic 65
	.4byte gStaticMotionGraphics_65-. @ src
	.4byte 960 | (640 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 240, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_65_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 66
	.4byte gStaticMotionGraphics_66-. @ src
	.4byte 3136 | (768 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 784, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_66_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 67
	.4byte gStaticMotionGraphics_67-. @ src
	.4byte 2784 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 696, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_67_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 68
	.4byte gStaticMotionGraphics_68-. @ src
	.4byte 1024 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_68_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

ExSkillIcon: @ Graphic 69
	.4byte gStaticMotionGraphics_69-. @ src
	.4byte 4608 | (864 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1152, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_69_Palettes-. @ src offset
		.2byte 64 @ bytesize
		.byte 0, 10 @ lz77(bool8), dst = PaletteID

	@ Graphic 70
	.4byte gStaticMotionGraphics_70-. @ src
	.4byte 3584 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1568, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_70_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 71
	.4byte gStaticMotionGraphics_71-. @ src
	.4byte 1024 | (708 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_71_Palettes-. @ src offset
		.2byte 96 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 72
	.4byte gStaticMotionGraphics_72-. @ src
	.4byte 256 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_72_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 73
	.4byte gStaticMotionGraphics_73-. @ src
	.4byte 436 | (640 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 160, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_73_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 74
	.4byte gStaticMotionGraphics_74-. @ src
	.4byte 1692 | (660 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 736, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_74_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 75
	.4byte gStaticMotionGraphics_75-. @ src
	.4byte 2560 | (752 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 640, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_75_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Graphic 76
	.4byte gStaticMotionGraphics_76-. @ src
	.4byte 6656 | (752 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1664, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_76_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Graphic 77
	.4byte gStaticMotionGraphics_77-. @ src
	.4byte 1932 | (608 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 880, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_77_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 78
	.4byte gStaticMotionGraphics_78-. @ src
	.4byte 1328 | (718 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 608, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_78_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Graphic 79
	.4byte gStaticMotionGraphics_79-. @ src
	.4byte 736 | (794 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 240, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_79_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 8 @ lz77(bool8), dst = PaletteID

	@ Graphic 80
	.4byte gStaticMotionGraphics_80-. @ src
	.4byte 464 | (824 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_80_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

	@ Graphic 81
	.4byte gStaticMotionGraphics_81-. @ src
	.4byte 4064 | (840 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1016, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_81_Palettes-. @ src offset
		.2byte 64 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 82
	.4byte gStaticMotionGraphics_82-. @ src
	.4byte 1004 | (879 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 656, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_82_Palettes-. @ src offset
		.2byte 64 @ bytesize
		.byte 0, 8 @ lz77(bool8), dst = PaletteID

	@ Graphic 83
	.4byte gStaticMotionGraphics_83-. @ src
	.4byte 1264 | (961 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 504, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_83_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 10 @ lz77(bool8), dst = PaletteID

	@ Graphic 84
	.4byte gStaticMotionGraphics_84-. @ src
	.4byte 2580 | (592 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1200, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_84_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 85
	.4byte gStaticMotionGraphics_85-. @ src
	.4byte 472 | (742 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 200, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_85_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 86
	.4byte gStaticMotionGraphics_86-. @ src
	.4byte 1176 | (767 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_86_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Graphic 87
	.4byte gStaticMotionGraphics_87-. @ src
	.4byte 772 | (831 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 408, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_87_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 8 @ lz77(bool8), dst = PaletteID

	@ Graphic 88
	.4byte gStaticMotionGraphics_88-. @ src
	.4byte 1664 | (895 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 416, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_88_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

	@ Graphic 89
	.4byte gStaticMotionGraphics_89-. @ src
	.4byte 2288 | (768 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 816, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_89_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 90
	.4byte gStaticMotionGraphics_90-. @ src
	.4byte 1152 | (896 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 288, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_90_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 91
	.4byte gStaticMotionGraphics_91-. @ src
	.4byte 3280 | (576 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1272, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_91_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 92
	.4byte gStaticMotionGraphics_92-. @ src
	.4byte 1544 | (735 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 584, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_92_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 93
	.4byte gStaticMotionGraphics_93-. @ src
	.4byte 1432 | (808 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 640, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_93_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 94
	.4byte gStaticMotionGraphics_94-. @ src
	.4byte 380 | (888 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 280, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_94_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 95
	.4byte gStaticMotionGraphics_95-. @ src
	.4byte 300 | (923 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 152, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_95_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 96
	.4byte gStaticMotionGraphics_96-. @ src
	.4byte 1028 | (942 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_96_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Graphic 97
	.4byte gStaticMotionGraphics_97-. @ src
	.4byte 304 | (1006 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_97_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 8 @ lz77(bool8), dst = PaletteID

	@ Graphic 98
	.4byte gStaticMotionGraphics_98-. @ src
	.4byte 3032 | (576 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1008, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_98_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 99
	.4byte gStaticMotionGraphics_99-. @ src
	.4byte 1468 | (702 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 864, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_99_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 100
	.4byte gStaticMotionGraphics_100-. @ src
	.4byte 960 | (810 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 480, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_100_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

Omega1wSword: @ Graphic 101
	.4byte Omega1wSword_Tiles-. @ src
	.4byte 4492 | (826 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1864, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte Omega1wSword_Pal-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 8 @ lz77(bool8), dst = PaletteID

	@ Graphic 102
	.4byte gStaticMotionGraphics_102-. @ src
	.4byte 1536 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_102_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 103
	.4byte gStaticMotionGraphics_103-. @ src
	.4byte 4256 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1064, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_103_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 104
	.4byte gStaticMotionGraphics_104-. @ src
	.4byte 1344 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 336, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_104_Palettes-. @ src offset
		.2byte 64 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 105
	.4byte gStaticMotionGraphics_105-. @ src
	.4byte 3040 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 760, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_105_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 106
	.4byte gStaticMotionGraphics_106-. @ src
	.4byte 2412 | (640 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1136, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_106_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 107
	.4byte gStaticMotionGraphics_107-. @ src
	.4byte 1536 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_107_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 108
	.4byte gStaticMotionGraphics_108-. @ src
	.4byte 1280 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 320, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_108_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 109
	.4byte gStaticMotionGraphics_109-. @ src
	.4byte 3040 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 760, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_109_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 110
	.4byte gStaticMotionGraphics_110-. @ src
	.4byte 6400 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1600, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_110_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 111
	.4byte gStaticMotionGraphics_111-. @ src
	.4byte 512 | (800 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_111_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 112
	.4byte gStaticMotionGraphics_112-. @ src
	.4byte 1632 | (800 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 408, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_112_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 113
	.4byte gStaticMotionGraphics_113-. @ src
	.4byte 1504 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 376, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_113_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 114
	.4byte gStaticMotionGraphics_114-. @ src
	.4byte 1632 | (560 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 408, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_114_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 115
	.4byte gStaticMotionGraphics_115-. @ src
	.4byte 2560 | (560 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 640, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_115_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

Deathlock: @ Graphic 116, 0x085d8208
	.4byte Deathlock_Tiles-. @ src
	.4byte 3040 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 760, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte Deathlock_Pal-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 117
	.4byte gStaticMotionGraphics_117-. @ src
	.4byte 1568 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 392, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_117_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 118
	.4byte gStaticMotionGraphics_118-. @ src
	.4byte 1120 | (624 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 280, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_118_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 119
	.4byte gStaticMotionGraphics_119-. @ src
	.4byte 2048 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_119_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 120
	.4byte gStaticMotionGraphics_120-. @ src
	.4byte 992 | (480 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 248, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_120_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 10 @ lz77(bool8), dst = PaletteID

	@ Graphic 121
	.4byte gStaticMotionGraphics_121-. @ src
	.4byte 5408 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1352, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_121_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 122
	.4byte gStaticMotionGraphics_122-. @ src
	.4byte 960 | (480 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 240, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_122_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 10 @ lz77(bool8), dst = PaletteID

	@ Graphic 123
	.4byte gStaticMotionGraphics_123-. @ src
	.4byte 2656 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 664, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_123_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

	@ Graphic 124
	.4byte gStaticMotionGraphics_124-. @ src
	.4byte 1120 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 280, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_124_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

	@ Graphic 125
	.4byte gStaticMotionGraphics_125-. @ src
	.4byte 1920 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 480, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_125_Palettes-. @ src offset
		.2byte 96 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

	@ Graphic 126
	.4byte gStaticMotionGraphics_126-. @ src
	.4byte 2560 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 640, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_126_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 127
	.4byte gStaticMotionGraphics_127-. @ src
	.4byte 244 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_127_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 128
	.4byte gStaticMotionGraphics_128-. @ src
	.4byte 2928 | (656 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1832, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_128_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 129
	.4byte gStaticMotionGraphics_129-. @ src
	.4byte 900 | (737 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 480, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_129_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Graphic 130
	.4byte gStaticMotionGraphics_130-. @ src
	.4byte 1452 | (737 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 432, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_130_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 131
	.4byte gStaticMotionGraphics_131-. @ src
	.4byte 3128 | (576 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1280, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_131_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Graphic 132
	.4byte gStaticMotionGraphics_132-. @ src
	.4byte 2108 | (736 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 824, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_132_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 8 @ lz77(bool8), dst = PaletteID

	@ Graphic 133
	.4byte gStaticMotionGraphics_133-. @ src
	.4byte 2676 | (859 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 944, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_133_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

	@ Graphic 134
	.4byte gStaticMotionGraphics_134-. @ src
	.4byte 1260 | (576 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_134_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 135
	.4byte gStaticMotionGraphics_135-. @ src
	.4byte 1940 | (640 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 992, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_135_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 136
	.4byte gStaticMotionGraphics_136-. @ src
	.4byte 560 | (764 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 304, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_136_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Graphic 137
	.4byte gStaticMotionGraphics_137-. @ src
	.4byte 2560 | (560 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 640, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_137_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 138
	.4byte gStaticMotionGraphics_138-. @ src
	.4byte 1312 | (560 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 328, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_138_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 139
	.4byte gStaticMotionGraphics_139-. @ src
	.4byte 1732 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1832, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_139_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 140
	.4byte gStaticMotionGraphics_140-. @ src
	.4byte 2780 | (656 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 976, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_140_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 141
	.4byte gStaticMotionGraphics_141-. @ src
	.4byte 0 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_141_Palettes-. @ src offset
		.2byte 0 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Graphic 142
	.4byte gStaticMotionGraphics_142-. @ src
	.4byte 1344 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 336, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_142_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 143 (サイバーエルフのグラフィック用を動的に読み込むためのダミー)
	.4byte gStaticMotionGraphics_143-. @ src
	.4byte 0 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_143_Palettes-. @ src offset
		.2byte 0 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 144
	.4byte gStaticMotionGraphics_144-. @ src
	.4byte 616 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 304, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_144_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 145
	.4byte gStaticMotionGraphics_145-. @ src
	.4byte 724 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 320, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_145_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 146
	.4byte gStaticMotionGraphics_146-. @ src
	.4byte 924 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 424, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_146_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 147
	.4byte gStaticMotionGraphics_147-. @ src
	.4byte 696 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 424, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_147_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 148
	.4byte gStaticMotionGraphics_148-. @ src
	.4byte 792 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 320, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_148_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 149
	.4byte gStaticMotionGraphics_149-. @ src
	.4byte 2232 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 896, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_149_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Graphic 150
	.4byte gStaticMotionGraphics_150-. @ src
	.4byte 2628 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1064, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_150_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 3 @ lz77(bool8), dst = PaletteID

	@ Graphic 151
	.4byte gStaticMotionGraphics_151-. @ src
	.4byte 544 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 136, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_151_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 152
	.4byte gStaticMotionGraphics_152-. @ src
	.4byte 4064 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1016, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_152_Palettes-. @ src offset
		.2byte 64 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 153
	.4byte gStaticMotionGraphics_153-. @ src
	.4byte 1632 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 408, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_153_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 154
	.4byte gStaticMotionGraphics_154-. @ src
	.4byte 768 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 192, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_154_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 155
	.4byte gStaticMotionGraphics_155-. @ src
	.4byte 1024 | (640 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_155_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 156
	.4byte gStaticMotionGraphics_156-. @ src
	.4byte 384 | (768 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_156_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 157
	.4byte gStaticMotionGraphics_157-. @ src
	.4byte 1024 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_157_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 158
	.4byte gStaticMotionGraphics_158-. @ src
	.4byte 136 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_158_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 159
	.4byte gStaticMotionGraphics_159-. @ src
	.4byte 140 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_159_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 160
	.4byte gStaticMotionGraphics_160-. @ src
	.4byte 132 | (640 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_160_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 161
	.4byte gStaticMotionGraphics_161-. @ src
	.4byte 144 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_161_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 162
	.4byte gStaticMotionGraphics_162-. @ src
	.4byte 384 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_162_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 163
	.4byte gStaticMotionGraphics_163-. @ src
	.4byte 960 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 240, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_163_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 164
	.4byte gStaticMotionGraphics_164-. @ src
	.4byte 608 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 152, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_164_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 165
	.4byte gStaticMotionGraphics_165-. @ src
	.4byte 576 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_165_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 166
	.4byte gStaticMotionGraphics_166-. @ src
	.4byte 576 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_166_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 167
	.4byte gStaticMotionGraphics_167-. @ src
	.4byte 404 | (442 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_167_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Graphic 168
	.4byte gStaticMotionGraphics_168-. @ src
	.4byte 396 | (442 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_168_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Graphic 169
	.4byte gStaticMotionGraphics_169-. @ src
	.4byte 424 | (442 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_169_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Graphic 170
	.4byte gStaticMotionGraphics_170-. @ src
	.4byte 228 | (458 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 88, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_170_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Graphic 171
	.4byte gStaticMotionGraphics_171-. @ src
	.4byte 164 | (458 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 88, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_171_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Graphic 172
	.4byte gStaticMotionGraphics_172-. @ src
	.4byte 216 | (458 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 88, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_172_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Graphic 173
	.4byte gStaticMotionGraphics_173-. @ src
	.4byte 108 | (469 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_173_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Graphic 174
	.4byte gStaticMotionGraphics_174-. @ src
	.4byte 100 | (469 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_174_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Graphic 175
	.4byte gStaticMotionGraphics_175-. @ src
	.4byte 116 | (469 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_175_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Graphic 176
	.4byte gStaticMotionGraphics_176-. @ src
	.4byte 136 | (473 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 40, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_176_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Graphic 177
	.4byte gStaticMotionGraphics_177-. @ src
	.4byte 148 | (473 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 40, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_177_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Graphic 178
	.4byte gStaticMotionGraphics_178-. @ src
	.4byte 124 | (473 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 40, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_178_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Graphic 179
	.4byte gStaticMotionGraphics_179-. @ src
	.4byte 24 | (796 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 8, (LZ77 | BPP4 | NO_PAL) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_179_Palettes-. @ src offset
		.2byte 0 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 180
	.4byte gStaticMotionGraphics_180-. @ src
	.4byte 3616 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 904, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_180_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 181
	.4byte gStaticMotionGraphics_181-. @ src
	.4byte 384 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_181_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 182
	.4byte gStaticMotionGraphics_182-. @ src
	.4byte 928 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 232, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_182_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 183
	.4byte gStaticMotionGraphics_183-. @ src
	.4byte 256 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, (BPP4 | NO_PAL) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_183_Palettes-. @ src offset
		.2byte 0 @ bytesize
		.byte 0, 14 @ lz77(bool8), dst = PaletteID

	@ Graphic 184
	.4byte gStaticMotionGraphics_184-. @ src
	.4byte 3936 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 984, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_184_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 185
	.4byte gStaticMotionGraphics_185-. @ src
	.4byte 612 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 248, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_185_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

	@ Graphic 186
	.4byte gStaticMotionGraphics_186-. @ src
	.4byte 1412 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 408, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_186_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 187
	.4byte Alouette_Tiles-. @ src
	.4byte 1824 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 456, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte Alouette_Pal-. @ src offset
		.2byte 96 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 188
	.4byte gStaticMotionGraphics_188-. @ src
	.4byte 388 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 104, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_188_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 189
	.4byte gStaticMotionGraphics_189-. @ src
	.4byte 560 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 160, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_189_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 190
	.4byte gStaticMotionGraphics_190-. @ src
	.4byte 368 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_190_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 191
	.4byte gStaticMotionGraphics_191-. @ src
	.4byte 468 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 120, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_191_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 192
	.4byte gStaticMotionGraphics_192-. @ src
	.4byte 360 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 88, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_192_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 193
	.4byte gStaticMotionGraphics_193-. @ src
	.4byte 448 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 120, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_193_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 194
	.4byte gStaticMotionGraphics_194-. @ src
	.4byte 1524 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_194_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 195
	.4byte gStaticMotionGraphics_195-. @ src
	.4byte 1044 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 328, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_195_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 196
	.4byte gStaticMotionGraphics_196-. @ src
	.4byte 980 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 320, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_196_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 197
	.4byte gStaticMotionGraphics_197-. @ src
	.4byte 348 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_197_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 198
	.4byte gStaticMotionGraphics_198-. @ src
	.4byte 540 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 192, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_198_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 199
	.4byte gStaticMotionGraphics_199-. @ src
	.4byte 400 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 104, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_199_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 200
	.4byte gStaticMotionGraphics_200-. @ src
	.4byte 1280 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 320, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_200_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 201
	.4byte gStaticMotionGraphics_201-. @ src
	.4byte 412 | (544 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 168, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_201_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 202
	.4byte gStaticMotionGraphics_202-. @ src
	.4byte 408 | (565 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 192, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_202_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 203
	.4byte gStaticMotionGraphics_203-. @ src
	.4byte 2048 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_203_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 204
	.4byte gStaticMotionGraphics_204-. @ src
	.4byte 156 | (996 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_204_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Graphic 205
	.4byte gStaticMotionGraphics_205-. @ src
	.4byte 3664 | (740 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 2048, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_205_Palettes-. @ src offset
		.2byte 128 @ bytesize
		.byte 0, 8 @ lz77(bool8), dst = PaletteID

	@ Graphic 206
	.4byte gStaticMotionGraphics_206-. @ src
	.4byte 3840 | (740 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 2048, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_206_Palettes-. @ src offset
		.2byte 128 @ bytesize
		.byte 0, 8 @ lz77(bool8), dst = PaletteID

	@ Graphic 207
	.4byte gStaticMotionGraphics_207-. @ src
	.4byte 396 | (676 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_207_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Graphic 208
	.4byte gStaticMotionGraphics_208-. @ src
	.4byte 3632 | (740 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 2048, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_208_Palettes-. @ src offset
		.2byte 128 @ bytesize
		.byte 0, 8 @ lz77(bool8), dst = PaletteID

	@ Graphic 209
	.4byte gStaticMotionGraphics_209-. @ src
	.4byte 320 | (368 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 80, (BPP4 | NO_PAL) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_209_Palettes-. @ src offset
		.2byte 0 @ bytesize
		.byte 0, 15 @ lz77(bool8), dst = PaletteID

	@ Graphic 210
	.4byte gStaticMotionGraphics_210-. @ src
	.4byte 864 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 216, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_210_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 211
	.4byte gStaticMotionGraphics_211-. @ src
	.4byte 32 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 8, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_211_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 212
	.4byte gStaticMotionGraphics_212-. @ src
	.4byte 4224 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1056, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_212_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 213
	.4byte gStaticMotionGraphics_213-. @ src
	.4byte 2400 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 600, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_213_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 214
	.4byte gStaticMotionGraphics_214-. @ src
	.4byte 5280 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1320, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_214_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 215
	.4byte gStaticMotionGraphics_215-. @ src
	.4byte 864 | (768 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 216, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_215_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 216
	.4byte gStaticMotionGraphics_216-. @ src
	.4byte 896 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 224, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_216_Palettes-. @ src offset
		.2byte 96 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 217
	.4byte gStaticMotionGraphics_217-. @ src
	.4byte 544 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 136, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_217_Palettes-. @ src offset
		.2byte 96 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 218
	.4byte gStaticMotionGraphics_218-. @ src
	.4byte 1504 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 376, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_218_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 219
	.4byte gStaticMotionGraphics_219-. @ src
	.4byte 4064 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1016, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_219_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 220
	.4byte gStaticMotionGraphics_220-. @ src
	.4byte 1792 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 448, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_220_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 221
	.4byte gStaticMotionGraphics_221-. @ src
	.4byte 3008 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 752, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_221_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 222
	.4byte gStaticMotionGraphics_222-. @ src
	.4byte 1792 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 448, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_222_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 223
	.4byte gStaticMotionGraphics_223-. @ src
	.4byte 672 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 168, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_223_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 224
	.4byte gStaticMotionGraphics_224-. @ src
	.4byte 704 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 176, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_224_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 225
	.4byte gStaticMotionGraphics_225-. @ src
	.4byte 5096 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 1952, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_225_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 226
	.4byte gStaticMotionGraphics_226-. @ src
	.4byte 832 | (380 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 208, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_226_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Graphic 227
	.4byte gStaticMotionGraphics_227-. @ src
	.4byte 832 | (380 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 208, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_227_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Graphic 228
	.4byte gStaticMotionGraphics_228-. @ src
	.4byte 832 | (380 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 208, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_228_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Graphic 229
	.4byte gStaticMotionGraphics_229-. @ src
	.4byte 192 | (380 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_229_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Graphic 230
	.4byte gStaticMotionGraphics_230-. @ src
	.4byte 608 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 152, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_230_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 231
	.4byte gStaticMotionGraphics_231-. @ src
	.4byte 448 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 112, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_231_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 232
	.4byte gStaticMotionGraphics_232-. @ src
	.4byte 512 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_232_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 233
	.4byte gStaticMotionGraphics_233-. @ src
	.4byte 960 | (556 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 568, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_233_Palettes-. @ src offset
		.2byte 160 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 234
	.4byte gStaticMotionGraphics_234-. @ src
	.4byte 912 | (628 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 448, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_234_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 10 @ lz77(bool8), dst = PaletteID

	@ Graphic 235
	.4byte gStaticMotionGraphics_235-. @ src
	.4byte 1024 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (BPP4 | NO_PAL) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_235_Palettes-. @ src offset
		.2byte 0 @ bytesize
		.byte 0, 14 @ lz77(bool8), dst = PaletteID

	@ Graphic 236
	.4byte gStaticMotionGraphics_236-. @ src
	.4byte 688 | (968 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 448, (LZ77 | BPP4 | NO_PAL) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_236_Palettes-. @ src offset
		.2byte 0 @ bytesize
		.byte 0, 13 @ lz77(bool8), dst = PaletteID

	@ Graphic 237
	.4byte gStaticMotionGraphics_237-. @ src
	.4byte 592 | (912 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 184, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_237_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Graphic 238
	.4byte gStaticMotionGraphics_238-. @ src
	.4byte 448 | (362 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 112, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_238_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 15 @ lz77(bool8), dst = PaletteID

	@ Graphic 239
	.4byte gStaticMotionGraphics_239-. @ src
	.4byte 848 | (768 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 312, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_239_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 5 @ lz77(bool8), dst = PaletteID

	@ Graphic 240
	.4byte gStaticMotionGraphics_240-. @ src
	.4byte 1176 | (807 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 392, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_240_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 241
	.4byte gStaticMotionGraphics_241-. @ src
	.4byte 384 | (856 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 160, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_241_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Graphic 242
	.4byte gStaticMotionGraphics_242-. @ src
	.4byte 412 | (876 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_242_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 8 @ lz77(bool8), dst = PaletteID

	@ Graphic 243
	.4byte gStaticMotionGraphics_243-. @ src
	.4byte 248 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_243_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Graphic 244
	.4byte gStaticMotionGraphics_244-. @ src
	.4byte 536 | (942 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 376, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_244_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Graphic 245
	.4byte gStaticMotionGraphics_245-. @ src
	.4byte 628 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 216, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_245_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 246
	.4byte gStaticMotionGraphics_246-. @ src
	.4byte 352 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 88, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_246_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 247
	.4byte gStaticMotionGraphics_247-. @ src
	.4byte 516 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 160, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_247_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 248
	.4byte gStaticMotionGraphics_248-. @ src
	.4byte 740 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 208, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_248_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 249
	.4byte gStaticMotionGraphics_249-. @ src
	.4byte 540 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_249_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 250
	.4byte gStaticMotionGraphics_250-. @ src
	.4byte 512 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 160, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_250_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 251
	.4byte gStaticMotionGraphics_251-. @ src
	.4byte 1012 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 328, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_251_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 252
	.4byte gStaticMotionGraphics_252-. @ src
	.4byte 536 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 168, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_252_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 253
	.4byte gStaticMotionGraphics_253-. @ src
	.4byte 288 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 72, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gStaticMotionGraphics_253_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

CommonEffect_Tiles:
	.incbin "sprites/static/effects/sheet.4bpp.lz"
CommonEffect_Pal:
	.incbin "sprites/static/effects/effects.gbapal"

gStaticMotionGraphics_1:
	.incbin "sprites/static/1/sheet.4bpp.lz"
	gStaticMotionGraphics_1_Palettes:
	.incbin "sprites/static/1/sheet.gbapal"

Lemon_Tiles:
	.incbin "sprites/static/lemon/sheet.4bpp.lz"
Lemon_Pal:

EmotionBubble_Tiles:
	.incbin "sprites/static/emotion_bubble/sheet.4bpp"
EmotionBubble_Pal:

ShotCounter_Tiles:
	.incbin "sprites/static/enemy/shotcounter/sheet.4bpp"
ShotCounter_Pal:
	.incbin "sprites/static/enemy/shotcounter/sheet.gbapal"

gStaticMotionGraphics_5:
	.incbin "sprites/static/gravel/sheet.4bpp.lz"
gStaticMotionGraphics_5_Palettes:
	.incbin "sprites/static/gravel/sheet.gbapal"

gStaticMotionGraphics_6:
	.incbin "sprites/static/enemy/batring/sheet.4bpp"
gStaticMotionGraphics_6_Palettes:
	.incbin "sprites/static/enemy/batring/sheet.gbapal"

gStaticMotionGraphics_7:
	.incbin "sprites/static/enemy/grand_cannon/sheet.4bpp"
gStaticMotionGraphics_7_Palettes:
	.incbin "sprites/static/enemy/grand_cannon/sheet.gbapal"

gStaticMotionGraphics_8:
	.incbin "sprites/static/enemy/pillar_cannon/sheet.4bpp"
	gStaticMotionGraphics_8_Palettes:
	.incbin "sprites/static/enemy/pillar_cannon/sheet.gbapal"

gStaticMotionGraphics_9:
	.incbin "sprites/static/omega_white/hand/sheet.4bpp.lz"
	gStaticMotionGraphics_9_Palettes:
	.incbin "sprites/static/omega_white/hand/sheet.gbapal"

gStaticMotionGraphics_10:
	.incbin "sprites/static/omega_white/ring/sheet.4bpp.lz"
gStaticMotionGraphics_10_Palettes:
	.incbin "sprites/static/omega_white/ring/sheet.gbapal"

gStaticMotionGraphics_11:
	.incbin "sprites/static/omega_white/recover/sheet.4bpp.lz"
gStaticMotionGraphics_11_Palettes:
	.incbin "sprites/static/omega_white/recover/sheet.gbapal"

gStaticMotionGraphics_12:
	.incbin "sprites/static/omega_white/rubble/sheet.4bpp"
gStaticMotionGraphics_12_Palettes:
	.incbin "sprites/static/omega_white/rubble/sheet.gbapal"

gStaticMotionGraphics_13:
	.incbin "sprites/static/enemy/shrimpolin/sheet.4bpp"
gStaticMotionGraphics_13_Palettes:
	.incbin "sprites/static/enemy/shrimpolin/shrimpolin.gbapal"

gStaticMotionGraphics_14:
	.incbin "sprites/static/menu/chip_icon/sheet.4bpp.lz"
gStaticMotionGraphics_14_Palettes:
	.incbin "sprites/static/menu/chip_icon/chip_icon.gbapal"

gStaticMotionGraphics_15:
	.incbin "sprites/static/menu/main_menu/sheet.4bpp.lz"
gStaticMotionGraphics_15_Palettes:
	.incbin "sprites/static/menu/main_menu/sheet.gbapal"

gStaticMotionGraphics_16:
	.incbin "sprites/static/enemy/icebon/icebon/sheet.4bpp"
gStaticMotionGraphics_16_Palettes:
	.incbin "sprites/static/enemy/icebon/icebon/sheet.gbapal"

gStaticMotionGraphics_17:
	.incbin "sprites/static/enemy/icebon/ice/sheet.4bpp"
gStaticMotionGraphics_17_Palettes:
	.incbin "sprites/static/enemy/icebon/ice/sheet.gbapal"

gStaticMotionGraphics_18:
	.incbin "sprites/static/door_2d/blue/sheet.4bpp"
gStaticMotionGraphics_18_Palettes:
	.incbin "sprites/static/door_2d/blue/sheet.gbapal"

gStaticMotionGraphics_19:
	.incbin "sprites/static/enemy/pantheon_hunter/sheet.4bpp"
gStaticMotionGraphics_19_Palettes:
	.incbin "sprites/static/enemy/pantheon_hunter/sheet.gbapal"

gStaticMotionGraphics_20:
	.incbin "sprites/static/enemy/pantheon_guardian/sheet.4bpp"
gStaticMotionGraphics_20_Palettes:
	.incbin "sprites/static/enemy/pantheon_guardian/sheet.gbapal"

gStaticMotionGraphics_21:
	.incbin "sprites/static/enemy/top_gabyoall/sheet.4bpp"
	gStaticMotionGraphics_21_Palettes:
	.incbin "sprites/static/enemy/top_gabyoall/sheet.gbapal"

gStaticMotionGraphics_22:
	.incbin "sprites/static/enemy/flopper/sheet.4bpp"
	gStaticMotionGraphics_22_Palettes:
	.incbin "sprites/static/enemy/flopper/sheet.gbapal"

gStaticMotionGraphics_23:
	.incbin "sprites/static/enemy/gyro_cannon/sheet.4bpp"
	gStaticMotionGraphics_23_Palettes:
	.incbin "sprites/static/enemy/gyro_cannon/sheet.gbapal"

gStaticMotionGraphics_24:
	.incbin "sprites/static/enemy/sharkseal_x/sheet.4bpp"
gStaticMotionGraphics_24_Palettes:
	.incbin "sprites/static/enemy/sharkseal_x/sharkseal_x.gbapal"

gStaticMotionGraphics_25:
	.incbin "sprites/static/enemy/lamplort/sheet.4bpp"
gStaticMotionGraphics_25_Palettes:
	.incbin "sprites/static/enemy/lamplort/sheet.gbapal"

gStaticMotionGraphics_26:
	.incbin "sprites/static/element_effect/thunder/sheet.4bpp.lz"
gStaticMotionGraphics_26_Palettes:

gStaticMotionGraphics_27:
	.incbin "sprites/static/element_effect/flame/sheet.4bpp.lz"
gStaticMotionGraphics_27_Palettes:

gStaticMotionGraphics_28:
	.incbin "sprites/static/element_effect/ice/sheet.4bpp.lz"
gStaticMotionGraphics_28_Palettes:

gStaticMotionGraphics_29:
	.incbin "sprites/static/enemy/lemmingles/sheet.4bpp"
	gStaticMotionGraphics_29_Palettes:
	.incbin "sprites/static/enemy/lemmingles/sheet.gbapal"

gStaticMotionGraphics_30:
	.incbin "sprites/static/enemy/lemmingles_nest/sheet.4bpp"
	gStaticMotionGraphics_30_Palettes:
	.incbin "sprites/static/enemy/lemmingles_nest/sheet.gbapal"

gStaticMotionGraphics_31:
	.incbin "sprites/static/volcano/bomb/sheet.4bpp"
	gStaticMotionGraphics_31_Palettes:
	.incbin "sprites/static/volcano/bomb/sheet.gbapal"

gStaticMotionGraphics_32:
	.incbin "sprites/static/32/sheet.4bpp"
	gStaticMotionGraphics_32_Palettes:
	.incbin "sprites/static/32/sheet.gbapal"

gStaticMotionGraphics_33:
	.incbin "sprites/static/fefnir_fireball/sheet.4bpp.lz"
gStaticMotionGraphics_33_Palettes:
	.incbin "sprites/static/fefnir_fireball/sheet.gbapal"

gStaticMotionGraphics_34:
	.incbin "sprites/static/enemy/carryarm/sheet.4bpp.lz"
	gStaticMotionGraphics_34_Palettes:
	.incbin "sprites/static/enemy/carryarm/sheet.gbapal"

gStaticMotionGraphics_35:
	.incbin "sprites/static/container/container/sheet.4bpp.lz"
gStaticMotionGraphics_35_Palettes:
	.incbin "sprites/static/container/container/sheet.gbapal"

gStaticMotionGraphics_36:
	.incbin "sprites/static/childre/36/sheet.4bpp.lz"
gStaticMotionGraphics_36_Palettes:
	.incbin "sprites/static/childre/36/sheet.gbapal"

gStaticMotionGraphics_37:
	.incbin "sprites/static/childre/ear_shot/sheet.4bpp.lz"
gStaticMotionGraphics_37_Palettes:
	.incbin "sprites/static/childre/ear_shot/sheet.gbapal"

gStaticMotionGraphics_38:
	.incbin "sprites/static/childre/38/sheet.4bpp.lz"
gStaticMotionGraphics_38_Palettes:
	.incbin "sprites/static/childre/38/sheet.gbapal"

gStaticMotionGraphics_39:
	.incbin "sprites/static/enemy/pantheon_aqua/sheet.4bpp"
	gStaticMotionGraphics_39_Palettes:
	.incbin "sprites/static/enemy/pantheon_aqua/sheet.gbapal"

gStaticMotionGraphics_40:
	.incbin "sprites/static/enemy/snakecord/sheet.4bpp"
	gStaticMotionGraphics_40_Palettes:
	.incbin "sprites/static/enemy/snakecord/sheet.gbapal"

gStaticMotionGraphics_41:
	.incbin "sprites/static/hammer/sheet.4bpp"
	gStaticMotionGraphics_41_Palettes:
	.incbin "sprites/static/hammer/sheet.gbapal"

gStaticMotionGraphics_42:
	.incbin "sprites/static/enemy/purple_nerple/sheet.4bpp"
	gStaticMotionGraphics_42_Palettes:
	.incbin "sprites/static/enemy/purple_nerple/sheet.gbapal"

gStaticMotionGraphics_43:
	.incbin "sprites/static/wormer/body/sheet.4bpp.lz"
gStaticMotionGraphics_43_Palettes:
	.incbin "sprites/static/wormer/body/body.gbapal"

gStaticMotionGraphics_44:
	.incbin "sprites/static/wormer/rock_drone/sheet.4bpp.lz"
gStaticMotionGraphics_44_Palettes:
	.incbin "sprites/static/wormer/rock_drone/rock_drone.gbapal"

gStaticMotionGraphics_45:
	.incbin "sprites/static/minigame/phantom/mine/sheet.4bpp"
	gStaticMotionGraphics_45_Palettes:
	.incbin "sprites/static/minigame/phantom/mine/sheet.gbapal"

gStaticMotionGraphics_46:
	.incbin "sprites/static/enemy/volcaire/sheet.4bpp"
	gStaticMotionGraphics_46_Palettes:
	.incbin "sprites/static/enemy/volcaire/sheet.gbapal"

gStaticMotionGraphics_47:
	.incbin "sprites/static/enemy/tile_cannon/sheet.4bpp"
	gStaticMotionGraphics_47_Palettes:
	.incbin "sprites/static/enemy/tile_cannon/sheet.gbapal"

gStaticMotionGraphics_48:
	.incbin "sprites/static/baby_elf/48/sheet.4bpp.lz"
	gStaticMotionGraphics_48_Palettes:
	.incbin "sprites/static/baby_elf/48/sheet.gbapal"

gStaticMotionGraphics_49:
	.incbin "sprites/static/baby_elf/49/sheet.4bpp.lz"
	gStaticMotionGraphics_49_Palettes:
	.incbin "sprites/static/baby_elf/49/sheet.gbapal"

gStaticMotionGraphics_50:
	.incbin "sprites/static/baby_elf/50/sheet.4bpp.lz"
gStaticMotionGraphics_50_Palettes:
	.incbin "sprites/static/baby_elf/50/50.gbapal"

gStaticMotionGraphics_51:
	.incbin "sprites/static/baby_elf/51/sheet.4bpp.lz"
	gStaticMotionGraphics_51_Palettes:
	.incbin "sprites/static/baby_elf/51/sheet.gbapal"

gStaticMotionGraphics_52:
	.incbin "sprites/static/baby_elf/52/sheet.4bpp.lz"
	gStaticMotionGraphics_52_Palettes:
	.incbin "sprites/static/baby_elf/52/sheet.gbapal"

gStaticMotionGraphics_53:
	.incbin "sprites/static/enemy/shelluno/sheet.4bpp"
gStaticMotionGraphics_53_Palettes:
	.incbin "sprites/static/enemy/shelluno/shelluno.gbapal"

gStaticMotionGraphics_54:
	.incbin "sprites/static/deathtanz/rock/sheet.4bpp.lz"
	gStaticMotionGraphics_54_Palettes:
	.incbin "sprites/static/deathtanz/rock/sheet.gbapal"

gStaticMotionGraphics_55:
	.incbin "sprites/static/deathtanz/projectile/sheet.4bpp.lz"
gStaticMotionGraphics_55_Palettes:
	.incbin "sprites/static/deathtanz/projectile/projectile.gbapal"

gStaticMotionGraphics_56:
	.incbin "sprites/static/enemy/heavy_cannon/sheet.4bpp"
gStaticMotionGraphics_56_Palettes:
	.incbin "sprites/static/enemy/heavy_cannon/sheet.gbapal"

gStaticMotionGraphics_57:
	.incbin "sprites/static/volcano/geyser/sheet.4bpp"
	gStaticMotionGraphics_57_Palettes:
	.incbin "sprites/static/volcano/geyser/sheet.gbapal"

gStaticMotionGraphics_58:
	.incbin "sprites/static/volcano/geyser_platform/sheet.4bpp"
	gStaticMotionGraphics_58_Palettes:
	.incbin "sprites/static/volcano/geyser_platform/sheet.gbapal"

gStaticMotionGraphics_59:
	.incbin "sprites/static/volcano/lava_river_platform/sheet.4bpp"
	gStaticMotionGraphics_59_Palettes:
	.incbin "sprites/static/volcano/lava_river_platform/sheet.gbapal"

gStaticMotionGraphics_60:
	.incbin "sprites/static/exlife_indicator/sheet.4bpp.lz"
gStaticMotionGraphics_60_Palettes:

gStaticMotionGraphics_61:
	.incbin "sprites/static/61/sheet.4bpp"
gStaticMotionGraphics_61_Palettes:

gStaticMotionGraphics_62:
	.incbin "sprites/static/enemy/beetank/sheet.4bpp"
gStaticMotionGraphics_62_Palettes:
	.incbin "sprites/static/enemy/beetank/sheet.gbapal"

gStaticMotionGraphics_63:
	.incbin "sprites/static/enemy/swordy/sheet.4bpp"
	gStaticMotionGraphics_63_Palettes:
	.incbin "sprites/static/enemy/swordy/sheet.gbapal"

gStaticMotionGraphics_64:
	.incbin "sprites/static/iceball/sheet.4bpp.lz"
gStaticMotionGraphics_64_Palettes:
	.incbin "sprites/static/iceball/sheet.gbapal"

gStaticMotionGraphics_65:
	.incbin "sprites/static/enemy/puffy/body/sheet.4bpp"
gStaticMotionGraphics_65_Palettes:
	.incbin "sprites/static/enemy/puffy/body/sheet.gbapal"

gStaticMotionGraphics_66:
	.incbin "sprites/static/enemy/puffy/bubble/sheet.4bpp"
	gStaticMotionGraphics_66_Palettes:
	.incbin "sprites/static/enemy/puffy/bubble/sheet.gbapal"

gStaticMotionGraphics_67:
	.incbin "sprites/static/enemy/crossbyne/sheet.4bpp"
	gStaticMotionGraphics_67_Palettes:
	.incbin "sprites/static/enemy/crossbyne/sheet.gbapal"

gStaticMotionGraphics_68:
	.incbin "sprites/static/old_residential/fall_rock/sheet.4bpp"
	gStaticMotionGraphics_68_Palettes:
	.incbin "sprites/static/old_residential/fall_rock/sheet.gbapal"

gStaticMotionGraphics_69:
	.incbin "sprites/static/menu/exskill_icon/sheet.4bpp"
gStaticMotionGraphics_69_Palettes:
	.incbin "sprites/static/menu/exskill_icon/exskill_icon.gbapal"

gStaticMotionGraphics_70:
	.incbin "sprites/static/bee_server/sheet.4bpp.lz"
gStaticMotionGraphics_70_Palettes:
	.incbin "sprites/static/bee_server/sheet.gbapal"

gStaticMotionGraphics_71:
	.incbin "sprites/static/enemy/mellnet/sheet.4bpp"
gStaticMotionGraphics_71_Palettes:
	.incbin "sprites/static/enemy/mellnet/mellnet.gbapal"

gStaticMotionGraphics_72:
	.incbin "sprites/static/72/sheet.4bpp"
	gStaticMotionGraphics_72_Palettes:
	.incbin "sprites/static/72/sheet.gbapal"

gStaticMotionGraphics_73:
	.incbin "sprites/static/anubis/rod/sheet.4bpp.lz"
	gStaticMotionGraphics_73_Palettes:
	.incbin "sprites/static/anubis/rod/sheet.gbapal"

gStaticMotionGraphics_74:
	.incbin "sprites/static/anubis/sand/sheet.4bpp.lz"
	gStaticMotionGraphics_74_Palettes:
	.incbin "sprites/static/anubis/sand/sheet.gbapal"

gStaticMotionGraphics_75:
	.incbin "sprites/static/anubis/coffin/sheet.4bpp"
	gStaticMotionGraphics_75_Palettes:
	.incbin "sprites/static/anubis/coffin/sheet.gbapal"

gStaticMotionGraphics_76:
	.incbin "sprites/static/enemy/pantheon_zombie/sheet.4bpp"
	gStaticMotionGraphics_76_Palettes:
	.incbin "sprites/static/enemy/pantheon_zombie/sheet.gbapal"

gStaticMotionGraphics_77:
	.incbin "sprites/static/pantheon_aqua_mod/body/sheet.4bpp.lz"
	gStaticMotionGraphics_77_Palettes:
	.incbin "sprites/static/pantheon_aqua_mod/body/sheet.gbapal"

gStaticMotionGraphics_78:
	.incbin "sprites/static/pantheon_aqua_mod/projectile/sheet.4bpp.lz"
	gStaticMotionGraphics_78_Palettes:
	.incbin "sprites/static/pantheon_aqua_mod/projectile/sheet.gbapal"

gStaticMotionGraphics_79:
	.incbin "sprites/static/pantheon_aqua_mod/rock/sheet.4bpp.lz"
	gStaticMotionGraphics_79_Palettes:
	.incbin "sprites/static/pantheon_aqua_mod/rock/sheet.gbapal"

gStaticMotionGraphics_80:
	.incbin "sprites/static/80/sheet.4bpp.lz"
	gStaticMotionGraphics_80_Palettes:
	.incbin "sprites/static/80/sheet.gbapal"

gStaticMotionGraphics_81:
	.incbin "sprites/static/mother_elf/81/sheet.4bpp"
gStaticMotionGraphics_81_Palettes:
	.incbin "sprites/static/mother_elf/81/81.gbapal"

gStaticMotionGraphics_82:
	.incbin "sprites/static/menu/elf_menu/sheet.4bpp.lz"
	gStaticMotionGraphics_82_Palettes:
	.incbin "sprites/static/menu/elf_menu/elf_menu.gbapal"

gStaticMotionGraphics_83:
	.incbin "sprites/static/menu/elf_menu_icon/sheet.4bpp.lz"
	gStaticMotionGraphics_83_Palettes:
	.incbin "sprites/static/menu/elf_menu_icon/sheet.gbapal"

gStaticMotionGraphics_84:
	.incbin "sprites/static/locomo_if/body/sheet.4bpp.lz"
gStaticMotionGraphics_84_Palettes:
	.incbin "sprites/static/locomo_if/body/sheet.gbapal"

gStaticMotionGraphics_85:
	.incbin "sprites/static/locomo_if/platform/sheet.4bpp.lz"
gStaticMotionGraphics_85_Palettes:
	.incbin "sprites/static/locomo_if/platform/sheet.gbapal"

gStaticMotionGraphics_86:
	.incbin "sprites/static/locomo_if/flame/sheet.4bpp.lz"
gStaticMotionGraphics_86_Palettes:
	.incbin "sprites/static/locomo_if/flame/sheet.gbapal"

gStaticMotionGraphics_87:
	.incbin "sprites/static/locomo_if/chill/sheet.4bpp.lz"
gStaticMotionGraphics_87_Palettes:
	.incbin "sprites/static/locomo_if/chill/sheet.gbapal"

gStaticMotionGraphics_88:
	.incbin "sprites/static/locomo_if/ice/sheet.4bpp"
gStaticMotionGraphics_88_Palettes:
	.incbin "sprites/static/locomo_if/ice/sheet.gbapal"

gStaticMotionGraphics_89:
	.incbin "sprites/static/glacierle/hand/sheet.4bpp.lz"
	gStaticMotionGraphics_89_Palettes:
	.incbin "sprites/static/glacierle/hand/sheet.gbapal"

gStaticMotionGraphics_90:
	.incbin "sprites/static/glacierle/icicle/sheet.4bpp"
	gStaticMotionGraphics_90_Palettes:
	.incbin "sprites/static/glacierle/icicle/sheet.gbapal"

gStaticMotionGraphics_91:
	.incbin "sprites/static/copy_x/fire_shot/sheet.4bpp.lz"
	gStaticMotionGraphics_91_Palettes:
	.incbin "sprites/static/copy_x/fire_shot/sheet.gbapal"

gStaticMotionGraphics_92:
	.incbin "sprites/static/copy_x/elec_shot/sheet.4bpp.lz"
	gStaticMotionGraphics_92_Palettes:
	.incbin "sprites/static/copy_x/elec_shot/sheet.gbapal"

gStaticMotionGraphics_93:
	.incbin "sprites/static/copy_x/normal_shot/sheet.4bpp.lz"
	gStaticMotionGraphics_93_Palettes:
	.incbin "sprites/static/copy_x/normal_shot/sheet.gbapal"

gStaticMotionGraphics_94:
	.incbin "sprites/static/copy_x/sliding_spark/sheet.4bpp.lz"
	gStaticMotionGraphics_94_Palettes:
	.incbin "sprites/static/copy_x/sliding_spark/sheet.gbapal"

gStaticMotionGraphics_95:
	.incbin "sprites/static/copy_x/charge_effect/sheet.4bpp.lz"
	gStaticMotionGraphics_95_Palettes:
	.incbin "sprites/static/copy_x/charge_effect/sheet.gbapal"

gStaticMotionGraphics_96:
	.incbin "sprites/static/copy_x/reflect_laser/sheet.4bpp.lz"
	gStaticMotionGraphics_96_Palettes:
	.incbin "sprites/static/copy_x/reflect_laser/sheet.gbapal"

gStaticMotionGraphics_97:
	.incbin "sprites/static/copy_x/97/sheet.4bpp.lz"
	gStaticMotionGraphics_97_Palettes:
	.incbin "sprites/static/copy_x/97/sheet.gbapal"

gStaticMotionGraphics_98:
	.incbin "sprites/static/blizzack/ice/sheet.4bpp.lz"
	gStaticMotionGraphics_98_Palettes:
	.incbin "sprites/static/blizzack/ice/sheet.gbapal"

gStaticMotionGraphics_99:
	.incbin "sprites/static/blizzack/chill/sheet.4bpp.lz"
	gStaticMotionGraphics_99_Palettes:
	.incbin "sprites/static/blizzack/chill/sheet.gbapal"

gStaticMotionGraphics_100:
	.incbin "sprites/static/blizzack/shoulder/sheet.4bpp.lz"
	gStaticMotionGraphics_100_Palettes:
	.incbin "sprites/static/blizzack/shoulder/sheet.gbapal"

Omega1wSword_Tiles:
	.incbin "sprites/static/omega_white/sword/sheet.4bpp.lz"
Omega1wSword_Pal:
	.incbin "sprites/static/omega_white/sword/sheet.gbapal"

gStaticMotionGraphics_102:
	.incbin "sprites/static/enemy/eye_cannon/sheet.4bpp"
	gStaticMotionGraphics_102_Palettes:
	.incbin "sprites/static/enemy/eye_cannon/sheet.gbapal"

gStaticMotionGraphics_103:
	.incbin "sprites/static/enemy/gallisni/sheet.4bpp"
	gStaticMotionGraphics_103_Palettes:
	.incbin "sprites/static/enemy/gallisni/sheet.gbapal"

gStaticMotionGraphics_104:
	.incbin "sprites/static/enemy/capsule_cannon/sheet.4bpp"
gStaticMotionGraphics_104_Palettes:
	.incbin "sprites/static/enemy/capsule_cannon/capsule_cannon.gbapal"

gStaticMotionGraphics_105:
	.incbin "sprites/static/enemy/pantheon_bomber/sheet.4bpp"
	gStaticMotionGraphics_105_Palettes:
	.incbin "sprites/static/enemy/pantheon_bomber/sheet.gbapal"

gStaticMotionGraphics_106:
	.incbin "sprites/static/hanumachine_obj/sheet.4bpp.lz"
	gStaticMotionGraphics_106_Palettes:
	.incbin "sprites/static/hanumachine_obj/sheet.gbapal"

gStaticMotionGraphics_107:
	.incbin "sprites/static/enemy/mothjiro/sheet.4bpp"
	gStaticMotionGraphics_107_Palettes:
	.incbin "sprites/static/enemy/mothjiro/sheet.gbapal"

gStaticMotionGraphics_108:
	.incbin "sprites/static/sub_arcadia_platform/sheet.4bpp"
	gStaticMotionGraphics_108_Palettes:
	.incbin "sprites/static/sub_arcadia_platform/sheet.gbapal"

gStaticMotionGraphics_109:
	.incbin "sprites/static/enemy/pantheon_base/sheet.4bpp"
	gStaticMotionGraphics_109_Palettes:
	.incbin "sprites/static/enemy/pantheon_base/sheet.gbapal"

gStaticMotionGraphics_110:
	.incbin "sprites/static/enemy/carrybee_g/sheet.4bpp"
	gStaticMotionGraphics_110_Palettes:
	.incbin "sprites/static/enemy/carrybee_g/sheet.gbapal"

gStaticMotionGraphics_111:
	.incbin "sprites/static/rocket/sheet.4bpp"
	gStaticMotionGraphics_111_Palettes:
	.incbin "sprites/static/rocket/sheet.gbapal"

gStaticMotionGraphics_112:
	.incbin "sprites/static/anatre_cube/sheet.4bpp"
	gStaticMotionGraphics_112_Palettes:
	.incbin "sprites/static/anatre_cube/sheet.gbapal"

gStaticMotionGraphics_113:
	.incbin "sprites/static/enemy/generator_cannon/sheet.4bpp"
	gStaticMotionGraphics_113_Palettes:
	.incbin "sprites/static/enemy/generator_cannon/sheet.gbapal"

gStaticMotionGraphics_114:
	.incbin "sprites/static/enemy/keaton/sheet.4bpp"
	gStaticMotionGraphics_114_Palettes:
	.incbin "sprites/static/enemy/keaton/sheet.gbapal"

gStaticMotionGraphics_115:
	.incbin "sprites/static/resistance_base/elevator/default/sheet.4bpp"
	gStaticMotionGraphics_115_Palettes:
	.incbin "sprites/static/resistance_base/elevator/default/sheet.gbapal"

@ ./tools/dumper/gfx.ts 0x085d8208 ./sprites/static/enemy/deathlock/sheet.png -- -width 4 -object
Deathlock_Tiles:
	.incbin "sprites/static/enemy/deathlock/sheet.4bpp"
Deathlock_Pal:
	.incbin "sprites/static/enemy/deathlock/sheet.gbapal"

gStaticMotionGraphics_117:
	.incbin "sprites/static/enemy/claveker/sheet.4bpp"
	gStaticMotionGraphics_117_Palettes:
	.incbin "sprites/static/enemy/claveker/sheet.gbapal"

gStaticMotionGraphics_118:
	.incbin "sprites/static/lever_switch/red/sheet.4bpp"
	gStaticMotionGraphics_118_Palettes:
	.incbin "sprites/static/lever_switch/red/sheet.gbapal"

gStaticMotionGraphics_119:
	.incbin "sprites/static/enemy/seimeran/sheet.4bpp"
	gStaticMotionGraphics_119_Palettes:
	.incbin "sprites/static/enemy/seimeran/sheet.gbapal"

gStaticMotionGraphics_120:
	.incbin "sprites/static/door_2d/gray/horizontal/sheet.4bpp"
	gStaticMotionGraphics_120_Palettes:
	.incbin "sprites/static/door_2d/gray/horizontal/sheet.gbapal"

gStaticMotionGraphics_121:
	.incbin "sprites/static/enemy/turtloid_s/sheet.4bpp"
	gStaticMotionGraphics_121_Palettes:
	.incbin "sprites/static/enemy/turtloid_s/sheet.gbapal"

gStaticMotionGraphics_122:
	.incbin "sprites/static/door_2d/gray/vertical/sheet.4bpp"
	gStaticMotionGraphics_122_Palettes:
	.incbin "sprites/static/door_2d/gray/vertical/sheet.gbapal"

gStaticMotionGraphics_123:
	.incbin "sprites/static/teleportal/sheet.4bpp"
	gStaticMotionGraphics_123_Palettes:
	.incbin "sprites/static/teleportal/sheet.gbapal"

gStaticMotionGraphics_124:
	.incbin "sprites/static/area_x2_platform/sheet.4bpp"
	gStaticMotionGraphics_124_Palettes:
	.incbin "sprites/static/area_x2_platform/sheet.gbapal"

gStaticMotionGraphics_125:
	.incbin "sprites/static/weil_labo_platform/sheet.4bpp"
gStaticMotionGraphics_125_Palettes:
	.incbin "sprites/static/weil_labo_platform/weil_labo_platform.gbapal"

gStaticMotionGraphics_126:
	.incbin "sprites/static/enemy/petatria/sheet.4bpp"
	gStaticMotionGraphics_126_Palettes:
	.incbin "sprites/static/enemy/petatria/sheet.gbapal"

gStaticMotionGraphics_127:
	.incbin "sprites/static/disabled_disk/sheet.4bpp.lz"
	gStaticMotionGraphics_127_Palettes:
	.incbin "sprites/static/disabled_disk/sheet.gbapal"

gStaticMotionGraphics_128:
	.incbin "sprites/static/128/sheet.4bpp.lz"
	gStaticMotionGraphics_128_Palettes:
	.incbin "sprites/static/128/sheet.gbapal"

gStaticMotionGraphics_129:
	.incbin "sprites/static/subtank2/sheet.4bpp.lz"
	gStaticMotionGraphics_129_Palettes:
	.incbin "sprites/static/subtank2/sheet.gbapal"

gStaticMotionGraphics_130:
	.incbin "sprites/static/prologue/mob/sheet.4bpp.lz"
	gStaticMotionGraphics_130_Palettes:
	.incbin "sprites/static/prologue/mob/sheet.gbapal"

gStaticMotionGraphics_131:
	.incbin "sprites/static/prologue/cutscene_mob/sheet.4bpp.lz"
	gStaticMotionGraphics_131_Palettes:
	.incbin "sprites/static/prologue/cutscene_mob/sheet.gbapal"

gStaticMotionGraphics_132:
	.incbin "sprites/static/prologue/cutscene_zero/sheet.4bpp.lz"
gStaticMotionGraphics_132_Palettes:
	.incbin "sprites/static/prologue/cutscene_zero/sheet.gbapal"

gStaticMotionGraphics_133:
	.incbin "sprites/static/prologue/cutscene_ciel/sheet.4bpp.lz"
	gStaticMotionGraphics_133_Palettes:
	.incbin "sprites/static/prologue/cutscene_ciel/sheet.gbapal"

gStaticMotionGraphics_134:
	.incbin "sprites/static/phantom/ninja_star/sheet.4bpp.lz"
	gStaticMotionGraphics_134_Palettes:
	.incbin "sprites/static/phantom/ninja_star/sheet.gbapal"

gStaticMotionGraphics_135:
	.incbin "sprites/static/phantom/135/sheet.4bpp.lz"
	gStaticMotionGraphics_135_Palettes:
	.incbin "sprites/static/phantom/135/sheet.gbapal"

gStaticMotionGraphics_136:
	.incbin "sprites/static/phantom/makibishi/sheet.4bpp.lz"
gStaticMotionGraphics_136_Palettes:
	.incbin "sprites/static/phantom/makibishi/sheet.gbapal"

gStaticMotionGraphics_137:
	.incbin "sprites/static/resistance_base/elevator/wood/sheet.4bpp"
	gStaticMotionGraphics_137_Palettes:
	.incbin "sprites/static/resistance_base/elevator/wood/sheet.gbapal"

gStaticMotionGraphics_138:
	.incbin "sprites/static/resistance_base/elevator/mmx/sheet.4bpp"
	gStaticMotionGraphics_138_Palettes:
	.incbin "sprites/static/resistance_base/elevator/mmx/sheet.gbapal"

gStaticMotionGraphics_139:
	.incbin "sprites/static/energy_facility_btn/sheet.4bpp.lz"
	gStaticMotionGraphics_139_Palettes:
	.incbin "sprites/static/energy_facility_btn/sheet.gbapal"

gStaticMotionGraphics_140:
	.incbin "sprites/static/resistance/mob/sheet.4bpp.lz"
	gStaticMotionGraphics_140_Palettes:
	.incbin "sprites/static/resistance/mob/sheet.gbapal"

gStaticMotionGraphics_141:
  gStaticMotionGraphics_141_Palettes:

gStaticMotionGraphics_142:
	.incbin "sprites/static/enemy/shotloid/sheet.4bpp"
	gStaticMotionGraphics_142_Palettes:
	.incbin "sprites/static/enemy/shotloid/sheet.gbapal"

gStaticMotionGraphics_143:
  gStaticMotionGraphics_143_Palettes:

gStaticMotionGraphics_144:
	.incbin "sprites/static/resistance_base/ciel_comp/0/sheet.4bpp.lz"
	gStaticMotionGraphics_144_Palettes:
	.incbin "sprites/static/resistance_base/ciel_comp/0/sheet.gbapal"

gStaticMotionGraphics_145:
	.incbin "sprites/static/resistance_base/ciel_comp/1/sheet.4bpp.lz"
	gStaticMotionGraphics_145_Palettes:
	.incbin "sprites/static/resistance_base/ciel_comp/1/sheet.gbapal"

gStaticMotionGraphics_146:
	.incbin "sprites/static/resistance_base/ciel_comp/2/sheet.4bpp.lz"
	gStaticMotionGraphics_146_Palettes:
	.incbin "sprites/static/resistance_base/ciel_comp/2/sheet.gbapal"

gStaticMotionGraphics_147:
	.incbin "sprites/static/resistance_base/ciel_comp/3/sheet.4bpp.lz"
	gStaticMotionGraphics_147_Palettes:
	.incbin "sprites/static/resistance_base/ciel_comp/3/sheet.gbapal"

gStaticMotionGraphics_148:
	.incbin "sprites/static/resistance_base/ciel_comp/4/sheet.4bpp.lz"
	gStaticMotionGraphics_148_Palettes:
	.incbin "sprites/static/resistance_base/ciel_comp/4/sheet.gbapal"

gStaticMotionGraphics_149:
	.incbin "sprites/static/logo/megaman/sheet.4bpp.lz"
	gStaticMotionGraphics_149_Palettes:
	.incbin "sprites/static/logo/megaman/sheet.gbapal"

gStaticMotionGraphics_150:
	.incbin "sprites/static/logo/z/sheet.4bpp.lz"
	gStaticMotionGraphics_150_Palettes:
	.incbin "sprites/static/logo/z/sheet.gbapal"

gStaticMotionGraphics_151:
	.incbin "sprites/static/missile_platform/sheet.4bpp"
	gStaticMotionGraphics_151_Palettes:
	.incbin "sprites/static/missile_platform/sheet.gbapal"

gStaticMotionGraphics_152:
	.incbin "sprites/static/mother_elf/152/sheet.4bpp"
	gStaticMotionGraphics_152_Palettes:
	.incbin "sprites/static/mother_elf/152/152.gbapal"

gStaticMotionGraphics_153:
	.incbin "sprites/static/volcano/coffin/sheet.4bpp"
	gStaticMotionGraphics_153_Palettes:
	.incbin "sprites/static/volcano/coffin/sheet.gbapal"

gStaticMotionGraphics_154:
	.incbin "sprites/static/giant_elevator_pier/sheet.4bpp"
	gStaticMotionGraphics_154_Palettes:
	.incbin "sprites/static/giant_elevator_pier/sheet.gbapal"

gStaticMotionGraphics_155:
	.incbin "sprites/static/giant_elevator_platform/sheet.4bpp"
	gStaticMotionGraphics_155_Palettes:
	.incbin "sprites/static/giant_elevator_platform/sheet.gbapal"

gStaticMotionGraphics_156:
	.incbin "sprites/static/156/sheet.4bpp"
	gStaticMotionGraphics_156_Palettes:
	.incbin "sprites/static/156/sheet.gbapal"

gStaticMotionGraphics_157:
	.incbin "sprites/static/smoke_157/sheet.4bpp"
	gStaticMotionGraphics_157_Palettes:
	.incbin "sprites/static/smoke_157/sheet.gbapal"

gStaticMotionGraphics_158:
	.incbin "sprites/static/minigame/zero/sheet.4bpp.lz"
	gStaticMotionGraphics_158_Palettes:
	.incbin "sprites/static/minigame/zero/sheet.gbapal"

gStaticMotionGraphics_159:
	.incbin "sprites/static/minigame/copy_x/sheet.4bpp.lz"
	gStaticMotionGraphics_159_Palettes:
	.incbin "sprites/static/minigame/copy_x/sheet.gbapal"

gStaticMotionGraphics_160:
	.incbin "sprites/static/minigame/phantom/icon/sheet.4bpp.lz"
	gStaticMotionGraphics_160_Palettes:
	.incbin "sprites/static/minigame/phantom/icon/sheet.gbapal"

gStaticMotionGraphics_161:
	.incbin "sprites/static/minigame/harpuia/sheet.4bpp.lz"
	gStaticMotionGraphics_161_Palettes:
	.incbin "sprites/static/minigame/harpuia/sheet.gbapal"

gStaticMotionGraphics_162:
	.incbin "sprites/static/resistance_base/painting/mmbn/sheet.4bpp"
	gStaticMotionGraphics_162_Palettes:
	.incbin "sprites/static/resistance_base/painting/mmbn/sheet.gbapal"

gStaticMotionGraphics_163:
	.incbin "sprites/static/resistance_base/graffiti/zero1/sheet.4bpp"
	gStaticMotionGraphics_163_Palettes:
	.incbin "sprites/static/resistance_base/graffiti/zero1/sheet.gbapal"

gStaticMotionGraphics_164:
	.incbin "sprites/static/resistance_base/graffiti/ciel/sheet.4bpp"
	gStaticMotionGraphics_164_Palettes:
	.incbin "sprites/static/resistance_base/graffiti/ciel/sheet.gbapal"

gStaticMotionGraphics_165:
	.incbin "sprites/static/resistance_base/graffiti/zero2/sheet.4bpp"
	gStaticMotionGraphics_165_Palettes:
	.incbin "sprites/static/resistance_base/graffiti/zero2/sheet.gbapal"

gStaticMotionGraphics_166:
	.incbin "sprites/static/resistance_base/painting/ciel/sheet.4bpp"
	gStaticMotionGraphics_166_Palettes:
	.incbin "sprites/static/resistance_base/painting/ciel/sheet.gbapal"

gStaticMotionGraphics_167:
	.incbin "sprites/static/life_energy/default/sheet.4bpp.lz"
	gStaticMotionGraphics_167_Palettes:
	.incbin "sprites/static/life_energy/default/sheet.gbapal"

gStaticMotionGraphics_168:
	.incbin "sprites/static/life_energy/x/sheet.4bpp.lz"
	gStaticMotionGraphics_168_Palettes:
	.incbin "sprites/static/life_energy/x/sheet.gbapal"

gStaticMotionGraphics_169:
	.incbin "sprites/static/life_energy/tank/sheet.4bpp.lz"
	gStaticMotionGraphics_169_Palettes:
	.incbin "sprites/static/life_energy/tank/sheet.gbapal"

gStaticMotionGraphics_170:
	.incbin "sprites/static/ecrystal/default/sheet.4bpp.lz"
gStaticMotionGraphics_170_Palettes:
	.incbin "sprites/static/ecrystal/default/sheet.gbapal"

gStaticMotionGraphics_171:
	.incbin "sprites/static/ecrystal/ball/sheet.4bpp.lz"
gStaticMotionGraphics_171_Palettes:
	.incbin "sprites/static/ecrystal/ball/sheet.gbapal"

gStaticMotionGraphics_172:
	.incbin "sprites/static/ecrystal/green/sheet.4bpp.lz"
	gStaticMotionGraphics_172_Palettes:
	.incbin "sprites/static/ecrystal/green/sheet.gbapal"

gStaticMotionGraphics_173:
	.incbin "sprites/static/exlife/default/sheet.4bpp.lz"
	gStaticMotionGraphics_173_Palettes:
	.incbin "sprites/static/exlife/default/sheet.gbapal"

gStaticMotionGraphics_174:
	.incbin "sprites/static/exlife/blue/sheet.4bpp.lz"
	gStaticMotionGraphics_174_Palettes:
	.incbin "sprites/static/exlife/blue/sheet.gbapal"

gStaticMotionGraphics_175:
	.incbin "sprites/static/exlife/green/sheet.4bpp.lz"
	gStaticMotionGraphics_175_Palettes:
	.incbin "sprites/static/exlife/green/sheet.gbapal"

gStaticMotionGraphics_176:
	.incbin "sprites/static/result_disk/default/sheet.4bpp.lz"
gStaticMotionGraphics_176_Palettes:
	.incbin "sprites/static/result_disk/default/sheet.gbapal"

gStaticMotionGraphics_177:
	.incbin "sprites/static/result_disk/blue/sheet.4bpp.lz"
gStaticMotionGraphics_177_Palettes:
	.incbin "sprites/static/result_disk/blue/sheet.gbapal"

gStaticMotionGraphics_178:
	.incbin "sprites/static/result_disk/red/sheet.4bpp.lz"
gStaticMotionGraphics_178_Palettes:
	.incbin "sprites/static/result_disk/red/sheet.gbapal"

gStaticMotionGraphics_179:
	.incbin "sprites/static/179/sheet.4bpp.lz"
	gStaticMotionGraphics_179_Palettes:

gStaticMotionGraphics_180:
	.incbin "sprites/static/ocean/childre_ship/sheet.4bpp"
	gStaticMotionGraphics_180_Palettes:
	.incbin "sprites/static/ocean/childre_ship/sheet.gbapal"

gStaticMotionGraphics_181:
	.incbin "sprites/static/ocean/sea_level_button/sheet.4bpp"
	gStaticMotionGraphics_181_Palettes:
	.incbin "sprites/static/ocean/sea_level_button/sheet.gbapal"

gStaticMotionGraphics_182:
	.incbin "sprites/static/ocean/182/sheet.4bpp"
	gStaticMotionGraphics_182_Palettes:
	.incbin "sprites/static/ocean/182/sheet.gbapal"

gStaticMotionGraphics_183:
	.incbin "sprites/static/ocean/childre_ship_sonic_wave/sheet.4bpp"
	gStaticMotionGraphics_183_Palettes:

gStaticMotionGraphics_184:
	.incbin "sprites/static/x/sheet.4bpp"
	gStaticMotionGraphics_184_Palettes:
	.incbin "sprites/static/x/sheet.gbapal"

gStaticMotionGraphics_185:
	.incbin "sprites/static/omega_zx_floating_rock/sheet.4bpp.lz"
	gStaticMotionGraphics_185_Palettes:
	.incbin "sprites/static/omega_zx_floating_rock/sheet.gbapal"

gStaticMotionGraphics_186:
	.incbin "sprites/static/186/sheet.4bpp.lz"
	gStaticMotionGraphics_186_Palettes:
	.incbin "sprites/static/186/sheet.gbapal"

Alouette_Tiles:
	.incbin "sprites/static/resistance/alouette/sheet.4bpp"
Alouette_Pal:
	.incbin "sprites/static/resistance/alouette/alouette.gbapal"

gStaticMotionGraphics_188:
	.incbin "sprites/static/resistance/kiss/sheet.4bpp.lz"
gStaticMotionGraphics_188_Palettes:
	.incbin "sprites/static/resistance/kiss/sheet.gbapal"

gStaticMotionGraphics_189:
	.incbin "sprites/static/resistance/faucon/sheet.4bpp.lz"
	gStaticMotionGraphics_189_Palettes:
	.incbin "sprites/static/resistance/faucon/sheet.gbapal"

gStaticMotionGraphics_190:
	.incbin "sprites/static/resistance/hirondelle/sheet.4bpp.lz"
	gStaticMotionGraphics_190_Palettes:
	.incbin "sprites/static/resistance/hirondelle/sheet.gbapal"

gStaticMotionGraphics_191:
	.incbin "sprites/static/resistance/autruche/sheet.4bpp.lz"
	gStaticMotionGraphics_191_Palettes:
	.incbin "sprites/static/resistance/autruche/sheet.gbapal"

gStaticMotionGraphics_192:
	.incbin "sprites/static/resistance/rocinolle/sheet.4bpp.lz"
	gStaticMotionGraphics_192_Palettes:
	.incbin "sprites/static/resistance/rocinolle/sheet.gbapal"

gStaticMotionGraphics_193:
	.incbin "sprites/static/resistance/doigt/sheet.4bpp.lz"
	gStaticMotionGraphics_193_Palettes:
	.incbin "sprites/static/resistance/doigt/sheet.gbapal"

gStaticMotionGraphics_194:
	.incbin "sprites/static/resistance/cerveau/sheet.4bpp.lz"
	gStaticMotionGraphics_194_Palettes:
	.incbin "sprites/static/resistance/cerveau/sheet.gbapal"

gStaticMotionGraphics_195:
	.incbin "sprites/static/resistance/hibou/sheet.4bpp.lz"
	gStaticMotionGraphics_195_Palettes:
	.incbin "sprites/static/resistance/hibou/sheet.gbapal"

gStaticMotionGraphics_196:
	.incbin "sprites/static/resistance/andrew/sheet.4bpp.lz"
	gStaticMotionGraphics_196_Palettes:
	.incbin "sprites/static/resistance/andrew/sheet.gbapal"

gStaticMotionGraphics_197:
	.incbin "sprites/static/resistance/menart/sheet.4bpp.lz"
	gStaticMotionGraphics_197_Palettes:
	.incbin "sprites/static/resistance/menart/sheet.gbapal"

gStaticMotionGraphics_198:
	.incbin "sprites/static/resistance/perroquiet/sheet.4bpp.lz"
	gStaticMotionGraphics_198_Palettes:
	.incbin "sprites/static/resistance/perroquiet/sheet.gbapal"

gStaticMotionGraphics_199:
	.incbin "sprites/static/resistance/pic/sheet.4bpp.lz"
	gStaticMotionGraphics_199_Palettes:
	.incbin "sprites/static/resistance/pic/sheet.gbapal"

gStaticMotionGraphics_200:
	.incbin "sprites/static/smoke/sheet.4bpp"
	gStaticMotionGraphics_200_Palettes:
	.incbin "sprites/static/smoke/sheet.gbapal"

gStaticMotionGraphics_201:
	.incbin "sprites/static/resistance/operator/sheet.4bpp.lz"
	gStaticMotionGraphics_201_Palettes:
	.incbin "sprites/static/resistance/operator/sheet.gbapal"

gStaticMotionGraphics_202:
	.incbin "sprites/static/resistance_base/202/sheet.4bpp.lz"
	gStaticMotionGraphics_202_Palettes:
	.incbin "sprites/static/resistance_base/202/sheet.gbapal"

gStaticMotionGraphics_203:
	.incbin "sprites/static/iceblock/sheet.4bpp"
	gStaticMotionGraphics_203_Palettes:
	.incbin "sprites/static/iceblock/sheet.gbapal"

gStaticMotionGraphics_204:
	.incbin "sprites/static/resistance_base/204/sheet.4bpp.lz"
	gStaticMotionGraphics_204_Palettes:
	.incbin "sprites/static/resistance_base/204/sheet.gbapal"

gStaticMotionGraphics_205:
	.incbin "sprites/static/mission_mugshot/first4/sheet.4bpp.lz"
	gStaticMotionGraphics_205_Palettes:
	.incbin "sprites/static/mission_mugshot/first4/first4.gbapal"

gStaticMotionGraphics_206:
	.incbin "sprites/static/mission_mugshot/middle4/sheet.4bpp.lz"
	gStaticMotionGraphics_206_Palettes:
	.incbin "sprites/static/mission_mugshot/middle4/middle4.gbapal"

gStaticMotionGraphics_207:
	.incbin "sprites/static/mission_mugshot/done/sheet.4bpp.lz"
gStaticMotionGraphics_207_Palettes:
	.incbin "sprites/static/mission_mugshot/done/sheet.gbapal"

gStaticMotionGraphics_208:
	.incbin "sprites/static/mission_mugshot/later4/sheet.4bpp.lz"
	gStaticMotionGraphics_208_Palettes:
	.incbin "sprites/static/mission_mugshot/later4/later4.gbapal"

gStaticMotionGraphics_209:
	.incbin "sprites/static/number/sheet.4bpp"
	gStaticMotionGraphics_209_Palettes:

gStaticMotionGraphics_210:
	.incbin "sprites/static/lever_switch/yellow/sheet.4bpp"
	gStaticMotionGraphics_210_Palettes:
	.incbin "sprites/static/lever_switch/yellow/sheet.gbapal"

gStaticMotionGraphics_211:
	.incbin "sprites/static/menu/border/sheet.4bpp"
	gStaticMotionGraphics_211_Palettes:
	.incbin "sprites/static/menu/border/sheet.gbapal"

gStaticMotionGraphics_212:
	.incbin "sprites/static/enemy/pantheon_fist/sheet.4bpp"
	gStaticMotionGraphics_212_Palettes:
	.incbin "sprites/static/enemy/pantheon_fist/sheet.gbapal"

gStaticMotionGraphics_213:
	.incbin "sprites/static/enemy/cattatank/sheet.4bpp"
	gStaticMotionGraphics_213_Palettes:
	.incbin "sprites/static/enemy/cattatank/sheet.gbapal"

gStaticMotionGraphics_214:
	.incbin "sprites/static/enemy/spearook/sheet.4bpp"
	gStaticMotionGraphics_214_Palettes:
	.incbin "sprites/static/enemy/spearook/sheet.gbapal"

gStaticMotionGraphics_215:
	.incbin "sprites/static/215/sheet.4bpp"
	gStaticMotionGraphics_215_Palettes:
	.incbin "sprites/static/215/sheet.gbapal"

gStaticMotionGraphics_216:
	.incbin "sprites/static/resistance_base/cat/216/sheet.4bpp"
	gStaticMotionGraphics_216_Palettes:
	.incbin "sprites/static/resistance_base/cat/216/216.gbapal"

gStaticMotionGraphics_217:
	.incbin "sprites/static/resistance_base/cat/217/sheet.4bpp"
	gStaticMotionGraphics_217_Palettes:
	.incbin "sprites/static/resistance_base/cat/217/217.gbapal"

gStaticMotionGraphics_218:
	.incbin "sprites/static/resistance_base/seagull/sheet.4bpp"
	gStaticMotionGraphics_218_Palettes:
	.incbin "sprites/static/resistance_base/seagull/sheet.gbapal"

gStaticMotionGraphics_219:
	.incbin "sprites/static/enemy/shellcrawler/sheet.4bpp"
	gStaticMotionGraphics_219_Palettes:
	.incbin "sprites/static/enemy/shellcrawler/sheet.gbapal"

gStaticMotionGraphics_220:
	.incbin "sprites/static/enemy/cannon_hopper/sheet.4bpp"
	gStaticMotionGraphics_220_Palettes:
	.incbin "sprites/static/enemy/cannon_hopper/sheet.gbapal"

gStaticMotionGraphics_221:
	.incbin "sprites/static/enemy/mettaur/sheet.4bpp"
	gStaticMotionGraphics_221_Palettes:
	.incbin "sprites/static/enemy/mettaur/sheet.gbapal"

gStaticMotionGraphics_222:
	.incbin "sprites/static/structural_steel/sheet.4bpp"
	gStaticMotionGraphics_222_Palettes:
	.incbin "sprites/static/structural_steel/sheet.gbapal"

gStaticMotionGraphics_223:
	.incbin "sprites/static/light_switch/sheet.4bpp"
	gStaticMotionGraphics_223_Palettes:
	.incbin "sprites/static/light_switch/sheet.gbapal"

gStaticMotionGraphics_224:
	.incbin "sprites/static/rubble/sheet.4bpp"
	gStaticMotionGraphics_224_Palettes:
	.incbin "sprites/static/rubble/sheet.gbapal"

gStaticMotionGraphics_225:
	.incbin "sprites/static/omega_white/body/sheet.4bpp.lz"
gStaticMotionGraphics_225_Palettes:
	.incbin "sprites/static/omega_white/body/sheet.gbapal"

gStaticMotionGraphics_226:
	.incbin "sprites/static/container/crashed/0.4bpp"
	gStaticMotionGraphics_226_Palettes:
	.incbin "sprites/static/container/crashed/0.gbapal"

gStaticMotionGraphics_227:
	.incbin "sprites/static/container/crashed/1.4bpp"
	gStaticMotionGraphics_227_Palettes:
	.incbin "sprites/static/container/crashed/1.gbapal"

gStaticMotionGraphics_228:
	.incbin "sprites/static/container/crashed/2.4bpp"
	gStaticMotionGraphics_228_Palettes:
	.incbin "sprites/static/container/crashed/2.gbapal"

gStaticMotionGraphics_229:
	.incbin "sprites/static/subtank/sheet.4bpp"
	gStaticMotionGraphics_229_Palettes:
	.incbin "sprites/static/subtank/sheet.gbapal"

gStaticMotionGraphics_230:
	.incbin "sprites/static/resistance_base/flying_fish/sheet.4bpp"
	gStaticMotionGraphics_230_Palettes:
	.incbin "sprites/static/resistance_base/flying_fish/sheet.gbapal"

gStaticMotionGraphics_231:
	.incbin "sprites/static/resistance_base/plant/sheet.4bpp"
	gStaticMotionGraphics_231_Palettes:
	.incbin "sprites/static/resistance_base/plant/sheet.gbapal"

gStaticMotionGraphics_232:
	.incbin "sprites/static/ciel_minigame/232/sheet.4bpp.lz"
gStaticMotionGraphics_232_Palettes:
	.incbin "sprites/static/ciel_minigame/232/sheet.gbapal"

gStaticMotionGraphics_233:
	.incbin "sprites/static/ciel_minigame/233/sheet.4bpp.lz"
gStaticMotionGraphics_233_Palettes:
	.incbin "sprites/static/ciel_minigame/233/233.gbapal"

gStaticMotionGraphics_234:
	.incbin "sprites/static/ciel_minigame/234/sheet.4bpp.lz"
gStaticMotionGraphics_234_Palettes:
	.incbin "sprites/static/ciel_minigame/234/sheet.gbapal"

gStaticMotionGraphics_235:
	.incbin "sprites/static/235/sheet.4bpp"
gStaticMotionGraphics_235_Palettes:

gStaticMotionGraphics_236:
	.incbin "sprites/static/spark/sheet.4bpp.lz"
gStaticMotionGraphics_236_Palettes:

gStaticMotionGraphics_237:
	.incbin "sprites/static/rock_237/sheet.4bpp.lz"
gStaticMotionGraphics_237_Palettes:
	.incbin "sprites/static/rock_237/sheet.gbapal"

gStaticMotionGraphics_238:
	.incbin "sprites/static/238/sheet.4bpp"
	gStaticMotionGraphics_238_Palettes:
	.incbin "sprites/static/238/sheet.gbapal"

gStaticMotionGraphics_239:
	.incbin "sprites/static/fish/angel_fish/sheet.4bpp.lz"
	gStaticMotionGraphics_239_Palettes:
	.incbin "sprites/static/fish/angel_fish/sheet.gbapal"

gStaticMotionGraphics_240:
	.incbin "sprites/static/fish/sea_bream/sheet.4bpp.lz"
	gStaticMotionGraphics_240_Palettes:
	.incbin "sprites/static/fish/sea_bream/sheet.gbapal"

gStaticMotionGraphics_241:
	.incbin "sprites/static/fish/crab/sheet.4bpp.lz"
	gStaticMotionGraphics_241_Palettes:
	.incbin "sprites/static/fish/crab/sheet.gbapal"

gStaticMotionGraphics_242:
	.incbin "sprites/static/fish/school/sheet.4bpp.lz"
	gStaticMotionGraphics_242_Palettes:
	.incbin "sprites/static/fish/school/sheet.gbapal"

gStaticMotionGraphics_243:
	.incbin "sprites/static/243/sheet.4bpp.lz"
	gStaticMotionGraphics_243_Palettes:
	.incbin "sprites/static/243/sheet.gbapal"

gStaticMotionGraphics_244:
	.incbin "sprites/static/copy_x_minigame_slot/sheet.4bpp.lz"
	gStaticMotionGraphics_244_Palettes:
	.incbin "sprites/static/copy_x_minigame_slot/sheet.gbapal"

gStaticMotionGraphics_245:
	.incbin "sprites/static/boss_human/hellbat/sheet.4bpp.lz"
	gStaticMotionGraphics_245_Palettes:
	.incbin "sprites/static/boss_human/hellbat/sheet.gbapal"

gStaticMotionGraphics_246:
	.incbin "sprites/static/boss_human/childre/sheet.4bpp.lz"
	gStaticMotionGraphics_246_Palettes:
	.incbin "sprites/static/boss_human/childre/sheet.gbapal"

gStaticMotionGraphics_247:
	.incbin "sprites/static/boss_human/blazin/sheet.4bpp.lz"
	gStaticMotionGraphics_247_Palettes:
	.incbin "sprites/static/boss_human/blazin/sheet.gbapal"

gStaticMotionGraphics_248:
	.incbin "sprites/static/boss_human/deathtanz/sheet.4bpp.lz"
	gStaticMotionGraphics_248_Palettes:
	.incbin "sprites/static/boss_human/deathtanz/sheet.gbapal"

gStaticMotionGraphics_249:
	.incbin "sprites/static/boss_human/glacierle/sheet.4bpp.lz"
	gStaticMotionGraphics_249_Palettes:
	.incbin "sprites/static/boss_human/glacierle/sheet.gbapal"

gStaticMotionGraphics_250:
	.incbin "sprites/static/boss_human/cubit/sheet.4bpp.lz"
	gStaticMotionGraphics_250_Palettes:
	.incbin "sprites/static/boss_human/cubit/sheet.gbapal"

gStaticMotionGraphics_251:
	.incbin "sprites/static/boss_human/tretista/sheet.4bpp.lz"
	gStaticMotionGraphics_251_Palettes:
	.incbin "sprites/static/boss_human/tretista/sheet.gbapal"

gStaticMotionGraphics_252:
	.incbin "sprites/static/boss_human/volteel/sheet.4bpp.lz"
	gStaticMotionGraphics_252_Palettes:
	.incbin "sprites/static/boss_human/volteel/sheet.gbapal"

gStaticMotionGraphics_253:
	.incbin "sprites/static/253/sheet.4bpp"
	gStaticMotionGraphics_253_Palettes:
	.incbin "sprites/static/253/sheet.gbapal"

