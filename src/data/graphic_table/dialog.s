  .include "asm/macros.inc"

.section .rodata
.balign 4, 0

@ preproc を使う
gDialogGraphics:: @ 0x085a7ec4

gGraphic_MsgBox0:: @ Gfx0 in 0x085a7ec4
	.4byte MsgBox0_Tiles-. @ src
	.4byte 156 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	gPalette_MsgBox0::
		.4byte MsgBox0_Pal-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 1
	.4byte gDialogGraphics_1-. @ src
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, LZ77 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_1_Palettes-. @ src offset
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 2
	.4byte gDialogGraphics_2-. @ src
	.4byte 868 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_2_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 3
	.4byte gDialogGraphics_3-. @ src
	.4byte 868 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_3_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 4
	.4byte gDialogGraphics_4-. @ src
	.4byte 904 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_4_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 5
	.4byte gDialogGraphics_5-. @ src
	.4byte 936 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_5_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 6
	.4byte gDialogGraphics_6-. @ src
	.4byte 760 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_6_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 7
	.4byte gDialogGraphics_7-. @ src
	.4byte 988 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_7_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 8
	.4byte gDialogGraphics_8-. @ src
	.4byte 756 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_8_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 9
	.4byte gDialogGraphics_9-. @ src
	.4byte 808 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_9_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 10
	.4byte gDialogGraphics_10-. @ src
	.4byte 876 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_10_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 11
	.4byte gDialogGraphics_11-. @ src
	.4byte 1096 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_11_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 12
	.4byte gDialogGraphics_12-. @ src
	.4byte 960 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_12_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 13
	.4byte gDialogGraphics_13-. @ src
	.4byte 872 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_13_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 14
	.4byte gDialogGraphics_14-. @ src
	.4byte 940 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_14_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 15
	.4byte gDialogGraphics_15-. @ src
	.4byte 1120 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_15_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 16
	.4byte gDialogGraphics_16-. @ src
	.4byte 1020 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_16_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 17
	.4byte gDialogGraphics_17-. @ src
	.4byte 1144 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_17_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 18
	.4byte gDialogGraphics_18-. @ src
	.4byte 896 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_18_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 19
	.4byte gDialogGraphics_19-. @ src
	.4byte 896 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_19_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 20
	.4byte gDialogGraphics_20-. @ src
	.4byte 956 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_20_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 21
	.4byte gDialogGraphics_21-. @ src
	.4byte 960 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_21_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 22
	.4byte gDialogGraphics_22-. @ src
	.4byte 940 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_22_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 23
	.4byte gDialogGraphics_23-. @ src
	.4byte 952 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_23_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 24
	.4byte gDialogGraphics_24-. @ src
	.4byte 1040 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_24_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 25
	.4byte gDialogGraphics_25-. @ src
	.4byte 968 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_25_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 26
	.4byte gDialogGraphics_26-. @ src
	.4byte 748 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_26_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 27
	.4byte gDialogGraphics_27-. @ src
	.4byte 900 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_27_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 28
	.4byte gDialogGraphics_28-. @ src
	.4byte 1136 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_28_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 29
	.4byte gDialogGraphics_29-. @ src
	.4byte 1164 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_29_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 30
	.4byte gDialogGraphics_30-. @ src
	.4byte 1008 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_30_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 31
	.4byte gDialogGraphics_31-. @ src
	.4byte 912 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_31_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 32
	.4byte gDialogGraphics_32-. @ src
	.4byte 936 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_32_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 33
	.4byte gDialogGraphics_33-. @ src
	.4byte 936 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_33_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 34
	.4byte gDialogGraphics_34-. @ src
	.4byte 836 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_34_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 35
	.4byte gDialogGraphics_35-. @ src
	.4byte 1056 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_35_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 36
	.4byte gDialogGraphics_36-. @ src
	.4byte 944 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_36_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 37
	.4byte gDialogGraphics_37-. @ src
	.4byte 876 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_37_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 38
	.4byte gDialogGraphics_38-. @ src
	.4byte 912 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_38_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 39
	.4byte gDialogGraphics_39-. @ src
	.4byte 772 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_39_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 40
	.4byte gDialogGraphics_40-. @ src
	.4byte 1024 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_40_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 41
	.4byte gDialogGraphics_41-. @ src
	.4byte 1112 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_41_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 42
	.4byte gDialogGraphics_42-. @ src
	.4byte 900 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_42_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 43
	.4byte gDialogGraphics_43-. @ src
	.4byte 796 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_43_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 44
	.4byte gDialogGraphics_44-. @ src
	.4byte 772 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_44_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 45
	.4byte gDialogGraphics_45-. @ src
	.4byte 856 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_45_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 46
	.4byte gDialogGraphics_46-. @ src
	.4byte 848 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_46_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 47
	.4byte gDialogGraphics_47-. @ src
	.4byte 884 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_47_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 48
	.4byte gDialogGraphics_48-. @ src
	.4byte 952 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_48_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 49
	.4byte gDialogGraphics_49-. @ src
	.4byte 800 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_49_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 50
	.4byte gDialogGraphics_50-. @ src
	.4byte 564 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_50_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 51
	.4byte gDialogGraphics_51-. @ src
	.4byte 1112 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_51_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 52
	.4byte gDialogGraphics_52-. @ src
	.4byte 1136 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_52_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 53
	.4byte gDialogGraphics_53-. @ src
	.4byte 648 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_53_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 54
	.4byte gDialogGraphics_54-. @ src
	.4byte 820 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_54_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 55
	.4byte gDialogGraphics_55-. @ src
	.4byte 860 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_55_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 56
	.4byte gDialogGraphics_56-. @ src
	.4byte 920 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_56_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

gGraphics_MsgBox:: @ Gfx57
	.4byte gDialogGraphics_57-. @ src
	.4byte 868 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, (LZ77 | BPP4) 	@ rowsize(unused), props
	gPalettes_MsgBox::
		.4byte gDialogGraphics_57_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 58
	.4byte gDialogGraphics_58-. @ src
	.4byte 148 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_58_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 59
	.4byte gDialogGraphics_59-. @ src
	.4byte 204 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_59_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 60
	.4byte gDialogGraphics_60-. @ src
	.4byte 216 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_60_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 61
	.4byte gDialogGraphics_61-. @ src
	.4byte 228 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_61_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 62
	.4byte gDialogGraphics_62-. @ src
	.4byte 244 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_62_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 63
	.4byte gDialogGraphics_63-. @ src
	.4byte 268 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_63_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 64
	.4byte gDialogGraphics_64-. @ src
	.4byte 228 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_64_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Graphic 65
	.4byte gDialogGraphics_65-. @ src
	.4byte 220 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte gDialogGraphics_65_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

MsgBox0_Tiles:
  .incbin "graphics/dialog/msgbox/0.4bpp.lz"
MsgBox0_Pal:
  .incbin "graphics/dialog/msgbox/0.gbapal"

gDialogGraphics_1:
	gDialogGraphics_1_Palettes:

gDialogGraphics_2:
	.incbin "graphics/dialog/mugshot/zero.4bpp.lz"
	gDialogGraphics_2_Palettes:
	.incbin "graphics/dialog/mugshot/zero.gbapal"

gDialogGraphics_3:
	.incbin "graphics/dialog/mugshot/blazin.4bpp.lz"
	gDialogGraphics_3_Palettes:
	.incbin "graphics/dialog/mugshot/blazin.gbapal"

gDialogGraphics_4:
	.incbin "graphics/dialog/mugshot/childre.4bpp.lz"
	gDialogGraphics_4_Palettes:
	.incbin "graphics/dialog/mugshot/childre.gbapal"

gDialogGraphics_5:
	.incbin "graphics/dialog/mugshot/hellbat.4bpp.lz"
	gDialogGraphics_5_Palettes:
	.incbin "graphics/dialog/mugshot/hellbat.gbapal"

gDialogGraphics_6:
	.incbin "graphics/dialog/mugshot/deathtanz.4bpp.lz"
	gDialogGraphics_6_Palettes:
	.incbin "graphics/dialog/mugshot/deathtanz.gbapal"

gDialogGraphics_7:
	.incbin "graphics/dialog/mugshot/cubit.4bpp.lz"
	gDialogGraphics_7_Palettes:
	.incbin "graphics/dialog/mugshot/cubit.gbapal"

gDialogGraphics_8:
	.incbin "graphics/dialog/mugshot/glacierle.4bpp.lz"
	gDialogGraphics_8_Palettes:
	.incbin "graphics/dialog/mugshot/glacierle.gbapal"

gDialogGraphics_9:
	.incbin "graphics/dialog/mugshot/volteel.4bpp.lz"
	gDialogGraphics_9_Palettes:
	.incbin "graphics/dialog/mugshot/volteel.gbapal"

gDialogGraphics_10:
	.incbin "graphics/dialog/mugshot/tretista.4bpp.lz"
	gDialogGraphics_10_Palettes:
	.incbin "graphics/dialog/mugshot/tretista.gbapal"

gDialogGraphics_11:
	.incbin "graphics/dialog/mugshot/blazin_human.4bpp.lz"
	gDialogGraphics_11_Palettes:
	.incbin "graphics/dialog/mugshot/blazin_human.gbapal"

gDialogGraphics_12:
	.incbin "graphics/dialog/mugshot/childre_human.4bpp.lz"
	gDialogGraphics_12_Palettes:
	.incbin "graphics/dialog/mugshot/childre_human.gbapal"

gDialogGraphics_13:
	.incbin "graphics/dialog/mugshot/hellbat_human.4bpp.lz"
	gDialogGraphics_13_Palettes:
	.incbin "graphics/dialog/mugshot/hellbat_human.gbapal"

gDialogGraphics_14:
	.incbin "graphics/dialog/mugshot/deathtanz_human.4bpp.lz"
	gDialogGraphics_14_Palettes:
	.incbin "graphics/dialog/mugshot/deathtanz_human.gbapal"

gDialogGraphics_15:
	.incbin "graphics/dialog/mugshot/cubit_human.4bpp.lz"
	gDialogGraphics_15_Palettes:
	.incbin "graphics/dialog/mugshot/cubit_human.gbapal"

gDialogGraphics_16:
	.incbin "graphics/dialog/mugshot/glacierle_human.4bpp.lz"
	gDialogGraphics_16_Palettes:
	.incbin "graphics/dialog/mugshot/glacierle_human.gbapal"

gDialogGraphics_17:
	.incbin "graphics/dialog/mugshot/volteel_human.4bpp.lz"
	gDialogGraphics_17_Palettes:
	.incbin "graphics/dialog/mugshot/volteel_human.gbapal"

gDialogGraphics_18:
	.incbin "graphics/dialog/mugshot/tretista_human.4bpp.lz"
	gDialogGraphics_18_Palettes:
	.incbin "graphics/dialog/mugshot/tretista_human.gbapal"

gDialogGraphics_19:
	.incbin "graphics/dialog/mugshot/anubis.4bpp.lz"
	gDialogGraphics_19_Palettes:
	.incbin "graphics/dialog/mugshot/anubis.gbapal"

gDialogGraphics_20:
	.incbin "graphics/dialog/mugshot/hanumachine.4bpp.lz"
	gDialogGraphics_20_Palettes:
	.incbin "graphics/dialog/mugshot/hanumachine.gbapal"

gDialogGraphics_21:
	.incbin "graphics/dialog/mugshot/blizzack.4bpp.lz"
	gDialogGraphics_21_Palettes:
	.incbin "graphics/dialog/mugshot/blizzack.gbapal"

gDialogGraphics_22:
	.incbin "graphics/dialog/mugshot/harpuia.4bpp.lz"
	gDialogGraphics_22_Palettes:
	.incbin "graphics/dialog/mugshot/harpuia.gbapal"

gDialogGraphics_23:
	.incbin "graphics/dialog/mugshot/leviathan.4bpp.lz"
	gDialogGraphics_23_Palettes:
	.incbin "graphics/dialog/mugshot/leviathan.gbapal"

gDialogGraphics_24:
	.incbin "graphics/dialog/mugshot/fefnir.4bpp.lz"
	gDialogGraphics_24_Palettes:
	.incbin "graphics/dialog/mugshot/fefnir.gbapal"

gDialogGraphics_25:
	.incbin "graphics/dialog/mugshot/phantom.4bpp.lz"
	gDialogGraphics_25_Palettes:
	.incbin "graphics/dialog/mugshot/phantom.gbapal"

gDialogGraphics_26:
	.incbin "graphics/dialog/mugshot/x.4bpp.lz"
	gDialogGraphics_26_Palettes:
	.incbin "graphics/dialog/mugshot/x.gbapal"

gDialogGraphics_27:
	.incbin "graphics/dialog/mugshot/copy_x.4bpp.lz"
	gDialogGraphics_27_Palettes:
	.incbin "graphics/dialog/mugshot/copy_x.gbapal"

gDialogGraphics_28:
	.incbin "graphics/dialog/mugshot/mother_elf.4bpp.lz"
	gDialogGraphics_28_Palettes:
	.incbin "graphics/dialog/mugshot/mother_elf.gbapal"

gDialogGraphics_29:
	.incbin "graphics/dialog/mugshot/weil.4bpp.lz"
	gDialogGraphics_29_Palettes:
	.incbin "graphics/dialog/mugshot/weil.gbapal"

gDialogGraphics_30:
	.incbin "graphics/dialog/mugshot/omega_white.4bpp.lz"
	gDialogGraphics_30_Palettes:
	.incbin "graphics/dialog/mugshot/omega_white.gbapal"

gDialogGraphics_31:
	.incbin "graphics/dialog/mugshot/omega_gold.4bpp.lz"
	gDialogGraphics_31_Palettes:
	.incbin "graphics/dialog/mugshot/omega_gold.gbapal"

gDialogGraphics_32:
	.incbin "graphics/dialog/mugshot/ciel.4bpp.lz"
	gDialogGraphics_32_Palettes:
	.incbin "graphics/dialog/mugshot/ciel.gbapal"

gDialogGraphics_33:
	.incbin "graphics/dialog/mugshot/cerveau.4bpp.lz"
	gDialogGraphics_33_Palettes:
	.incbin "graphics/dialog/mugshot/cerveau.gbapal"

gDialogGraphics_34:
	.incbin "graphics/dialog/mugshot/alouette.4bpp.lz"
	gDialogGraphics_34_Palettes:
	.incbin "graphics/dialog/mugshot/alouette.gbapal"

gDialogGraphics_35:
	.incbin "graphics/dialog/mugshot/andrew.4bpp.lz"
	gDialogGraphics_35_Palettes:
	.incbin "graphics/dialog/mugshot/andrew.gbapal"

gDialogGraphics_36:
	.incbin "graphics/dialog/mugshot/hibou.4bpp.lz"
	gDialogGraphics_36_Palettes:
	.incbin "graphics/dialog/mugshot/hibou.gbapal"

gDialogGraphics_37:
	.incbin "graphics/dialog/mugshot/rocinolle.4bpp.lz"
	gDialogGraphics_37_Palettes:
	.incbin "graphics/dialog/mugshot/rocinolle.gbapal"

gDialogGraphics_38:
	.incbin "graphics/dialog/mugshot/perroquiet.4bpp.lz"
	gDialogGraphics_38_Palettes:
	.incbin "graphics/dialog/mugshot/perroquiet.gbapal"

gDialogGraphics_39:
	.incbin "graphics/dialog/mugshot/menart.4bpp.lz"
	gDialogGraphics_39_Palettes:
	.incbin "graphics/dialog/mugshot/menart.gbapal"

gDialogGraphics_40:
	.incbin "graphics/dialog/mugshot/doigt.4bpp.lz"
	gDialogGraphics_40_Palettes:
	.incbin "graphics/dialog/mugshot/doigt.gbapal"

gDialogGraphics_41:
	.incbin "graphics/dialog/mugshot/weil_monitor.4bpp.lz"
	gDialogGraphics_41_Palettes:
	.incbin "graphics/dialog/mugshot/weil_monitor.gbapal"

gDialogGraphics_42:
	.incbin "graphics/dialog/mugshot/autruche.4bpp.lz"
	gDialogGraphics_42_Palettes:
	.incbin "graphics/dialog/mugshot/autruche.gbapal"

gDialogGraphics_43:
	.incbin "graphics/dialog/mugshot/pic.4bpp.lz"
	gDialogGraphics_43_Palettes:
	.incbin "graphics/dialog/mugshot/pic.gbapal"

gDialogGraphics_44:
	.incbin "graphics/dialog/mugshot/hirondelle.4bpp.lz"
	gDialogGraphics_44_Palettes:
	.incbin "graphics/dialog/mugshot/hirondelle.gbapal"

gDialogGraphics_45:
	.incbin "graphics/dialog/mugshot/faucon.4bpp.lz"
	gDialogGraphics_45_Palettes:
	.incbin "graphics/dialog/mugshot/faucon.gbapal"

gDialogGraphics_46:
	.incbin "graphics/dialog/mugshot/kiss.4bpp.lz"
	gDialogGraphics_46_Palettes:
	.incbin "graphics/dialog/mugshot/kiss.gbapal"

gDialogGraphics_47:
	.incbin "graphics/dialog/mugshot/brain.4bpp.lz"
	gDialogGraphics_47_Palettes:
	.incbin "graphics/dialog/mugshot/brain.gbapal"

gDialogGraphics_48:
	.incbin "graphics/dialog/mugshot/joan.4bpp.lz"
	gDialogGraphics_48_Palettes:
	.incbin "graphics/dialog/mugshot/joan.gbapal"

gDialogGraphics_49:
	.incbin "graphics/dialog/mugshot/rouge.4bpp.lz"
	gDialogGraphics_49_Palettes:
	.incbin "graphics/dialog/mugshot/rouge.gbapal"

gDialogGraphics_50:
	.incbin "graphics/dialog/mugshot/sound_only.4bpp.lz"
	gDialogGraphics_50_Palettes:
	.incbin "graphics/dialog/mugshot/sound_only.gbapal"

gDialogGraphics_51:
	.incbin "graphics/dialog/mugshot/crea.4bpp.lz"
	gDialogGraphics_51_Palettes:
	.incbin "graphics/dialog/mugshot/crea.gbapal"

gDialogGraphics_52:
	.incbin "graphics/dialog/mugshot/prea.4bpp.lz"
	gDialogGraphics_52_Palettes:
	.incbin "graphics/dialog/mugshot/prea.gbapal"

gDialogGraphics_53:
	.incbin "graphics/dialog/mugshot/sound_only2.4bpp.lz"
	gDialogGraphics_53_Palettes:
	.incbin "graphics/dialog/mugshot/sound_only2.gbapal"

gDialogGraphics_54:
	.incbin "graphics/dialog/mugshot/colbor.4bpp.lz"
	gDialogGraphics_54_Palettes:
	.incbin "graphics/dialog/mugshot/colbor.gbapal"

gDialogGraphics_55:
	.incbin "graphics/dialog/mugshot/copy_x_armor.4bpp.lz"
	gDialogGraphics_55_Palettes:
	.incbin "graphics/dialog/mugshot/copy_x_armor.gbapal"

gDialogGraphics_56:
	.incbin "graphics/dialog/mugshot/ciel_blur.4bpp.lz"
	gDialogGraphics_56_Palettes:
	.incbin "graphics/dialog/mugshot/ciel_blur.gbapal"

gDialogGraphics_57:
	.incbin "graphics/dialog/mugshot/omega_zero.4bpp.lz"
	gDialogGraphics_57_Palettes:
	.incbin "graphics/dialog/mugshot/omega_zero.gbapal"

gDialogGraphics_58:
	.incbin "graphics/dialog/msgbox/1.4bpp.lz"
	gDialogGraphics_58_Palettes:
	.incbin "graphics/dialog/msgbox/1.gbapal"

gDialogGraphics_59:
	.incbin "graphics/dialog/msgbox/2.4bpp.lz"
	gDialogGraphics_59_Palettes:
	.incbin "graphics/dialog/msgbox/2.gbapal"

gDialogGraphics_60:
	.incbin "graphics/dialog/msgbox/3.4bpp.lz"
	gDialogGraphics_60_Palettes:
	.incbin "graphics/dialog/msgbox/3.gbapal"

gDialogGraphics_61:
	.incbin "graphics/dialog/msgbox/4.4bpp.lz"
	gDialogGraphics_61_Palettes:
	.incbin "graphics/dialog/msgbox/4.gbapal"

gDialogGraphics_62:
	.incbin "graphics/dialog/msgbox/5.4bpp.lz"
	gDialogGraphics_62_Palettes:
	.incbin "graphics/dialog/msgbox/5.gbapal"

gDialogGraphics_63:
	.incbin "graphics/dialog/msgbox/6.4bpp.lz"
	gDialogGraphics_63_Palettes:
	.incbin "graphics/dialog/msgbox/6.gbapal"

gDialogGraphics_64:
	.incbin "graphics/dialog/msgbox/7.4bpp.lz"
	gDialogGraphics_64_Palettes:
	.incbin "graphics/dialog/msgbox/7.gbapal"

gDialogGraphics_65:
	.incbin "graphics/dialog/msgbox/8.4bpp.lz"
	gDialogGraphics_65_Palettes:
	.incbin "graphics/dialog/msgbox/8.gbapal"

