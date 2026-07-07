  .include "asm/macros.inc"

.section .rodata
.balign 4, 0

@ preproc を使う
gBgGraphics::

gGraphic_Capcom:: @ Gfx0 in 0x08547280
	.4byte Capcom_Tiles-. @ data: 0x08547CF8
	.4byte 2400 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
  gPalette_Capcom::
		.4byte Capcom_Pal-. @ data: 0x08548658 = .+5068
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

gGraphic_Inti:: @ Gfx1 in 0x08547294
	.4byte Inti_Tiles-. @ data: 0x08548678
	.4byte 1260 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
  gPalette_Inti::
		.4byte Inti_Pal-. @ data: 0x08548B64
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

gGraphic_085472a8:: @ Gfx2 in 0x085472A8
	.4byte 6364 @ data: 0x08548B84 = .+6364
	.4byte 9456 | (256 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP8) 	@ rowsize(unused), props
  gPalette_085472a8::
		.4byte 15808 @ data: 0x0854B074 = .+15808
		.2byte 256 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

gGraphic_TitleZero:: @ Gfx3 in 0x085472BC
	.4byte TitleZero_Tiles-. @ data: 0x0854B174
	.4byte 11468 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
  gPalette_TitleZero::
		.4byte TitleZero_Pal-. @ data: 0x0854DE40
		.2byte 64 @ bytesize
		.byte 0, 14 @ lz77(bool8), dst = PaletteID

gGraphic_TitleCiel:: @ Gfx4 in 0x085472D0
	.4byte TitleCiel_Tiles-. @ data: 0x0854DE80 = .+27568
	.4byte 8260 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
  gPalette_TitleCiel::
		.4byte TitleCiel_Pal-. @ data: 0x0854FEC4 = .+35816
		.2byte 64 @ bytesize
		.byte 0, 14 @ lz77(bool8), dst = PaletteID

	@ Gfx5 in 0x085472E4
	.4byte 35872 @ data: 0x0854FF04 = .+35872
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 35860 @ data: 0x0854FF04 = .+35860
		.2byte 0 @ bytesize
		.byte 0, 14 @ lz77(bool8), dst = PaletteID

	@ Gfx6 in 0x085472F8
	.4byte 35852 @ data: 0x0854FF04 = .+35852
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 35840 @ data: 0x0854FF04 = .+35840
		.2byte 0 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Gfx7 in 0x0854730C
	.4byte 35832 @ data: 0x0854FF04 = .+35832
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 35820 @ data: 0x0854FF04 = .+35820
		.2byte 0 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Gfx8 in 0x08547320
	.4byte 35812 @ data: 0x0854FF04 = .+35812
	.4byte 0 | (256 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, LZ77 	@ rowsize(unused), props
		@ Palette
		.4byte 35800 @ data: 0x0854FF04 = .+35800
		.2byte 0 @ bytesize
		.byte 0, 6 @ lz77(bool8), dst = PaletteID

	@ Gfx9 in 0x08547334
	.4byte 35792 @ data: 0x0854FF04 = .+35792
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 35780 @ data: 0x0854FF04 = .+35780
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

gGraphic_HUD::	@ Gfx10 in 0x08547348
	.4byte HUD_Tiles-. @ data: 0x0854FF04
	.4byte 6080 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	gPalette_HUD::
		.4byte HUD_Pal-. @ data: 0x085516C4
		.2byte 32 @ bytesize
		.byte 0, 1 @ lz77(bool8), dst = PaletteID

gGraphic_MissionStart:: @ Gfx11 in 0x0854735C
	.4byte MissionStart_Tiles-. @ data: 0x085516E4 = .+41864
	.4byte 1856 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	gPalette_MissionStart::
		.4byte MissionStart_Pal-. @ data: 0x08551E24 = .+43708
		.2byte 32 @ bytesize
		.byte 0, 1 @ lz77(bool8), dst = PaletteID

gGraphic_MissionFailed:: @ Gfx12 in 0x08547370
	.4byte MissionFailed_Tiles-. @ data: 0x08551E44 = .+43732
	.4byte 804 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	gPalette_MissionFailed::
		.4byte MissionFailed_Pal-. @ data: 0x08552168 = .+44524
		.2byte 32 @ bytesize
		.byte 0, 1 @ lz77(bool8), dst = PaletteID

	@ Gfx13 in 0x08547384
	.4byte 44548 @ data: 0x08552188 = .+44548
	.4byte 2368 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte 46904 @ data: 0x08552AC8 = .+46904
		.2byte 32 @ bytesize
		.byte 0, 1 @ lz77(bool8), dst = PaletteID

	@ Gfx14 in 0x08547398
	.4byte 46928 @ data: 0x08552AE8 = .+46928
	.4byte 832 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte 47748 @ data: 0x08552E28 = .+47748
		.2byte 32 @ bytesize
		.byte 0, 1 @ lz77(bool8), dst = PaletteID

	@ Gfx15 in 0x085473AC
	.4byte 47772 @ data: 0x08552E48 = .+47772
	.4byte 1408 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 49168 @ data: 0x085533C8 = .+49168
		.2byte 32 @ bytesize
		.byte 0, 1 @ lz77(bool8), dst = PaletteID

	@ Gfx16 in 0x085473C0
	.4byte 49192 @ data: 0x085533E8 = .+49192
	.4byte 1564 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 50744 @ data: 0x08553A04 = .+50744
		.2byte 32 @ bytesize
		.byte 0, 1 @ lz77(bool8), dst = PaletteID

gGraphic_Unk17:: @ Gfx17 in 0x085473D4
	.4byte 50768 @ data: 0x08553A24 = .+50768
	.4byte 1344 | (896 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 168, BPP4 	@ rowsize(unused), props
	gPalette_Unk17::
		.4byte 52100 @ data: 0x08553F64 = .+52100
		.2byte 32 @ bytesize
		.byte 0, 1 @ lz77(bool8), dst = PaletteID

gGraphic_LogoDemo::	@ Gfx18 in 0x085473E8
	.4byte 52124 @ data: 0x08553F84 = .+52124
	.4byte 1152 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	gPalette_LogoDemo::
		.4byte 53264 @ data: 0x08554404 = .+53264
		.2byte 32 @ bytesize
		.byte 0, 1 @ lz77(bool8), dst = PaletteID

	@ Gfx19 in 0x085473FC
	.4byte 53288 @ data: 0x08554424 = .+53288
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 53276 @ data: 0x08554424 = .+53276
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx20 in 0x08547410
	.4byte 53268 @ data: 0x08554424 = .+53268
	.4byte 7072 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 60328 @ data: 0x08555FC4 = .+60328
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

gGraphic_ExSkillMenu::	@ Gfx21 in 0x08547424
	.4byte 60544 @ data: 0x085560A4 = .+60544
	.4byte 2616 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	gPalette_ExSkillMenu::
		.4byte 63148 @ data: 0x08556ADC = .+63148
		.2byte 96 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

gGraphic_MiscMenu:: @ Gfx22 in 0x08547438
	.4byte MiscMenu_Tiles-. @ data: 0x08556B3C = .+63236
	.4byte 6740 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
  gPalette_MiscMenu::
		.4byte MiscMenu_Pal-. @ data: 0x08558590 = .+69964
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

gGraphic_ElfMenu::	@ Gfx23 in 0x0854744C
	.4byte ElfMenu_Tiles-. @ data: 0x08558670 = .+70180
	.4byte 3140 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	gPalette_ElfMenu::
		.4byte ElfMenu_Pal-. @ data: 0x085592B4 = .+73308
		.2byte 160 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

gGraphic_Zero3D:: @ Gfx24 in 0x08547460
	.4byte Zero3D0_Tiles-. @ data: 0x08559354 = .+73460
	.4byte 720 | (384 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte Zero3D0_Pal-. @ data: 0x08559624 = .+74168
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Gfx25 in 0x08547474
	.4byte 74192 @ data: 0x08559644 = .+74192
	.4byte 688 | (384 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 74868 @ data: 0x085598F4 = .+74868
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Gfx26 in 0x08547488
	.4byte 74892 @ data: 0x08559914 = .+74892
	.4byte 660 | (384 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 75540 @ data: 0x08559BA8 = .+75540
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Gfx27 in 0x0854749C
	.4byte 75564 @ data: 0x08559BC8 = .+75564
	.4byte 588 | (384 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 76140 @ data: 0x08559E14 = .+76140
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Gfx28 in 0x085474B0
	.4byte 76164 @ data: 0x08559E34 = .+76164
	.4byte 536 | (384 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 76688 @ data: 0x0855A04C = .+76688
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Gfx29 in 0x085474C4
	.4byte 76712 @ data: 0x0855A06C = .+76712
	.4byte 592 | (384 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 77292 @ data: 0x0855A2BC = .+77292
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Gfx30 in 0x085474D8
	.4byte 77316 @ data: 0x0855A2DC = .+77316
	.4byte 608 | (384 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 77912 @ data: 0x0855A53C = .+77912
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Gfx31 in 0x085474EC
	.4byte 77936 @ data: 0x0855A55C = .+77936
	.4byte 624 | (384 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 78548 @ data: 0x0855A7CC = .+78548
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

	@ Gfx32 in 0x08547500
	.4byte 78572 @ data: 0x0855A7EC = .+78572
	.4byte 636 | (384 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 79196 @ data: 0x0855AA68 = .+79196
		.2byte 32 @ bytesize
		.byte 0, 7 @ lz77(bool8), dst = PaletteID

gGraphics_ElfCat::	@ Gfx33 in 0x08547514
Graphic_ElfCat_Nurse:
	.4byte ElfCatNurse_Tiles-. @ data: 0x0855AA88 = .+79220
	.4byte 576 | (576 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 288, (MAP2D | BPP4) 	@ rowsize, props
	gPalettes_ElfCat::
		.4byte ElfCatNurse_Pal-. @ data: 0x0855ACC8 = .+79784
		.2byte 32 @ bytesize
		.byte 0, 13 @ lz77(bool8), dst = PaletteID

Graphic_ElfCat_Animal: @ Gfx34 in 0x08547528
	.4byte ElfCatAnimal_Tiles-. @ data: 0x0855ACE8 = .+79808
	.4byte 576 | (576 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 288, (MAP2D | BPP4) 	@ rowsize, props
		@ Palette
		.4byte ElfCatAnimal_Pal-. @ data: 0x0855AF28 = .+80372
		.2byte 32 @ bytesize
		.byte 0, 13 @ lz77(bool8), dst = PaletteID

Graphic_ElfCat_Hacker: @ Gfx35 in 0x0854753C
	.4byte ElfCatHacker_Tiles-. @ data: 0x0855AF48 = .+80396
	.4byte 576 | (576 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 288, (MAP2D | BPP4) 	@ rowsize, props
		@ Palette
		.4byte ElfCatHacker_Pal-. @ data: 0x0855B188 = .+80960
		.2byte 32 @ bytesize
		.byte 0, 13 @ lz77(bool8), dst = PaletteID

Graphic_SecretDickBlue: @ Gfx36 in 0x08547550
	.4byte SecretDickBlue_Tiles-. @ data: 0x0855B1A8 = .+80984
	.4byte 256 | (235 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | BPP4) 	@ rowsize, props
		@ Palette
		.4byte SecretDickBlue_Pal-. @ data: 0x0855B2A8 = .+81228
		.2byte 32 @ bytesize
		.byte 0, 8 @ lz77(bool8), dst = PaletteID

Graphic_SecretDickRed: @ Gfx37 in 0x08547564
	.4byte SecretDickRed_Tiles-. @ data: 0x0855B2C8 = .+81252
	.4byte 256 | (235 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, (MAP2D | BPP4) 	@ rowsize, props
		@ Palette
		.4byte SecretDickRed_Pal-. @ data: 0x0855B3C8 = .+81496
		.2byte 32 @ bytesize
		.byte 0, 8 @ lz77(bool8), dst = PaletteID

	@ Gfx38 in 0x08547578
	.4byte 81520 @ data: 0x0855B3E8 = .+81520
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 81508 @ data: 0x0855B3E8 = .+81508
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

gGraphic_Unk39:: @ Gfx39 in 0x0854758C
	.4byte ElfCatNone_Tiles-. @ data: 0x0855B3E8 = .+81500
	.4byte 576 | (576 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 288, (MAP2D | BPP4) 	@ rowsize, props
	gPalette_Unk39::
		.4byte ElfCatNone_Pal-. @ data: 0x0855B628 = .+82064
		.2byte 32 @ bytesize
		.byte 0, 13 @ lz77(bool8), dst = PaletteID

gGraphics_CyberElfTab:: @ Gfx40 in 0x085475A0
	.4byte ElfTabNurse_Tiles-. @ data: 0x0855B648 = .+82088
	.4byte 512 | (672 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (MAP2D | BPP4) 	@ rowsize, props
  gPalettes_CyberElfTab:: @ Palette
		.4byte ElfTabNurse_Pal-. @ data: 0x0855B848 = .+82588
		.2byte 32 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx41 in 0x085475B4
	.4byte ElfTabAnimal_Tiles-. @ data: 0x0855B868 = .+82612
	.4byte 512 | (672 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (MAP2D | BPP4) 	@ rowsize, props
		@ Palette
		.4byte ElfTabAnimal_Pal-. @ data: 0x0855BA68 = .+83112
		.2byte 32 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx42 in 0x085475C8
	.4byte ElfTabHacker_Tiles-. @ data: 0x0855BA88
	.4byte 512 | (672 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (MAP2D | BPP4) 	@ rowsize, props
		@ Palette
		.4byte ElfTabHacker_Pal-. @ data: 0x0855BC88
		.2byte 32 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

gGraphic_CodeName:: @ Gfx43 in 0x085475DC
	.4byte CodeName_Tiles-. @ data: 0x0855BCA8
	.4byte 2540 | (768 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
  gPalette_CodeName::
		.4byte CodeName_Pal-. @ data: 0x0855C694
		.2byte 32 @ bytesize
		.byte 0, 15 @ lz77(bool8), dst = PaletteID

@ ここから gGraphic_GameOverString まで Gfx44 .. Gfx101 は　タイルマップのみ?
@ 多分タイルデータは、ステージと同じものを使って、タイルマップのみこっちで用意していると思われる

	@ Gfx44 in 0x085475F0
	.4byte 86212 @ data: 0x0855C6B4 = .+86212
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 86200 @ data: 0x0855C6B4 = .+86200
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx45 in 0x08547604
	.4byte 86192 @ data: 0x0855C6B4 = .+86192
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 86180 @ data: 0x0855C6B4 = .+86180
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx46 in 0x08547618
	.4byte 86172 @ data: 0x0855C6B4 = .+86172
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 86160 @ data: 0x0855C6B4 = .+86160
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx47 in 0x0854762C
	.4byte 86152 @ data: 0x0855C6B4 = .+86152
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 86140 @ data: 0x0855C6B4 = .+86140
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx48 in 0x08547640
	.4byte 86132 @ data: 0x0855C6B4 = .+86132
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 86120 @ data: 0x0855C6B4 = .+86120
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx49 in 0x08547654
	.4byte 86112 @ data: 0x0855C6B4 = .+86112
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 86100 @ data: 0x0855C6B4 = .+86100
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx50 in 0x08547668
	.4byte 86092 @ data: 0x0855C6B4 = .+86092
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 86080 @ data: 0x0855C6B4 = .+86080
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx51 in 0x0854767C
	.4byte 86072 @ data: 0x0855C6B4 = .+86072
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 86060 @ data: 0x0855C6B4 = .+86060
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx52 in 0x08547690
	.4byte 86052 @ data: 0x0855C6B4 = .+86052
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 86040 @ data: 0x0855C6B4 = .+86040
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx53 in 0x085476A4
	.4byte 86032 @ data: 0x0855C6B4 = .+86032
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 86020 @ data: 0x0855C6B4 = .+86020
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx54 in 0x085476B8
	.4byte 86012 @ data: 0x0855C6B4 = .+86012
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 86000 @ data: 0x0855C6B4 = .+86000
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx55 in 0x085476CC
	.4byte 85992 @ data: 0x0855C6B4 = .+85992
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85980 @ data: 0x0855C6B4 = .+85980
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx56 in 0x085476E0
	.4byte 85972 @ data: 0x0855C6B4 = .+85972
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85960 @ data: 0x0855C6B4 = .+85960
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx57 in 0x085476F4
	.4byte 85952 @ data: 0x0855C6B4 = .+85952
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85940 @ data: 0x0855C6B4 = .+85940
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx58 in 0x08547708
	.4byte 85932 @ data: 0x0855C6B4 = .+85932
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85920 @ data: 0x0855C6B4 = .+85920
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx59 in 0x0854771C
	.4byte 85912 @ data: 0x0855C6B4 = .+85912
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85900 @ data: 0x0855C6B4 = .+85900
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx60 in 0x08547730
	.4byte 85892 @ data: 0x0855C6B4 = .+85892
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85880 @ data: 0x0855C6B4 = .+85880
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx61 in 0x08547744
	.4byte 85872 @ data: 0x0855C6B4 = .+85872
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85860 @ data: 0x0855C6B4 = .+85860
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx62 in 0x08547758
	.4byte 85852 @ data: 0x0855C6B4 = .+85852
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85840 @ data: 0x0855C6B4 = .+85840
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx63 in 0x0854776C
	.4byte 85832 @ data: 0x0855C6B4 = .+85832
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85820 @ data: 0x0855C6B4 = .+85820
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx64 in 0x08547780
	.4byte 85812 @ data: 0x0855C6B4 = .+85812
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85800 @ data: 0x0855C6B4 = .+85800
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx65 in 0x08547794
	.4byte 85792 @ data: 0x0855C6B4 = .+85792
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85780 @ data: 0x0855C6B4 = .+85780
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx66 in 0x085477A8
	.4byte 85772 @ data: 0x0855C6B4 = .+85772
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85760 @ data: 0x0855C6B4 = .+85760
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx67 in 0x085477BC
	.4byte 85752 @ data: 0x0855C6B4 = .+85752
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85740 @ data: 0x0855C6B4 = .+85740
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx68 in 0x085477D0
	.4byte 85732 @ data: 0x0855C6B4 = .+85732
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85720 @ data: 0x0855C6B4 = .+85720
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx69 in 0x085477E4
	.4byte 85712 @ data: 0x0855C6B4 = .+85712
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85700 @ data: 0x0855C6B4 = .+85700
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx70 in 0x085477F8
	.4byte 85692 @ data: 0x0855C6B4 = .+85692
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85680 @ data: 0x0855C6B4 = .+85680
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx71 in 0x0854780C
	.4byte 85672 @ data: 0x0855C6B4 = .+85672
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85660 @ data: 0x0855C6B4 = .+85660
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx72 in 0x08547820
	.4byte 85652 @ data: 0x0855C6B4 = .+85652
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85640 @ data: 0x0855C6B4 = .+85640
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx73 in 0x08547834
	.4byte 85632 @ data: 0x0855C6B4 = .+85632
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85620 @ data: 0x0855C6B4 = .+85620
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx74 in 0x08547848
	.4byte 85612 @ data: 0x0855C6B4 = .+85612
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85600 @ data: 0x0855C6B4 = .+85600
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx75 in 0x0854785C
	.4byte 85592 @ data: 0x0855C6B4 = .+85592
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85580 @ data: 0x0855C6B4 = .+85580
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx76 in 0x08547870
	.4byte 85572 @ data: 0x0855C6B4 = .+85572
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85560 @ data: 0x0855C6B4 = .+85560
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx77 in 0x08547884
	.4byte 85552 @ data: 0x0855C6B4 = .+85552
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85540 @ data: 0x0855C6B4 = .+85540
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx78 in 0x08547898
	.4byte 85532 @ data: 0x0855C6B4 = .+85532
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85520 @ data: 0x0855C6B4 = .+85520
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx79 in 0x085478AC
	.4byte 85512 @ data: 0x0855C6B4 = .+85512
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85500 @ data: 0x0855C6B4 = .+85500
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx80 in 0x085478C0
	.4byte 85492 @ data: 0x0855C6B4 = .+85492
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85480 @ data: 0x0855C6B4 = .+85480
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx81 in 0x085478D4
	.4byte 85472 @ data: 0x0855C6B4 = .+85472
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85460 @ data: 0x0855C6B4 = .+85460
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx82 in 0x085478E8
	.4byte 85452 @ data: 0x0855C6B4 = .+85452
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85440 @ data: 0x0855C6B4 = .+85440
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx83 in 0x085478FC
	.4byte 85432 @ data: 0x0855C6B4 = .+85432
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85420 @ data: 0x0855C6B4 = .+85420
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx84 in 0x08547910
	.4byte 85412 @ data: 0x0855C6B4 = .+85412
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85400 @ data: 0x0855C6B4 = .+85400
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx85 in 0x08547924
	.4byte 85392 @ data: 0x0855C6B4 = .+85392
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85380 @ data: 0x0855C6B4 = .+85380
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx86 in 0x08547938
	.4byte 85372 @ data: 0x0855C6B4 = .+85372
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85360 @ data: 0x0855C6B4 = .+85360
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx87 in 0x0854794C
	.4byte 85352 @ data: 0x0855C6B4 = .+85352
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85340 @ data: 0x0855C6B4 = .+85340
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx88 in 0x08547960
	.4byte 85332 @ data: 0x0855C6B4 = .+85332
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85320 @ data: 0x0855C6B4 = .+85320
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx89 in 0x08547974
	.4byte 85312 @ data: 0x0855C6B4 = .+85312
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85300 @ data: 0x0855C6B4 = .+85300
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx90 in 0x08547988
	.4byte 85292 @ data: 0x0855C6B4 = .+85292
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85280 @ data: 0x0855C6B4 = .+85280
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx91 in 0x0854799C
	.4byte 85272 @ data: 0x0855C6B4 = .+85272
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85260 @ data: 0x0855C6B4 = .+85260
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx92 in 0x085479B0
	.4byte 85252 @ data: 0x0855C6B4 = .+85252
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85240 @ data: 0x0855C6B4 = .+85240
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx93 in 0x085479C4
	.4byte 85232 @ data: 0x0855C6B4 = .+85232
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85220 @ data: 0x0855C6B4 = .+85220
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx94 in 0x085479D8
	.4byte 85212 @ data: 0x0855C6B4 = .+85212
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85200 @ data: 0x0855C6B4 = .+85200
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx95 in 0x085479EC
	.4byte 85192 @ data: 0x0855C6B4 = .+85192
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85180 @ data: 0x0855C6B4 = .+85180
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx96 in 0x08547A00
	.4byte 85172 @ data: 0x0855C6B4 = .+85172
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85160 @ data: 0x0855C6B4 = .+85160
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx97 in 0x08547A14
	.4byte 85152 @ data: 0x0855C6B4 = .+85152
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85140 @ data: 0x0855C6B4 = .+85140
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx98 in 0x08547A28
	.4byte 85132 @ data: 0x0855C6B4 = .+85132
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85120 @ data: 0x0855C6B4 = .+85120
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx99 in 0x08547A3C
	.4byte 85112 @ data: 0x0855C6B4 = .+85112
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85100 @ data: 0x0855C6B4 = .+85100
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx100 in 0x08547A50
	.4byte 85092 @ data: 0x0855C6B4 = .+85092
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85080 @ data: 0x0855C6B4 = .+85080
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx101 in 0x08547A64
	.4byte 85072 @ data: 0x0855C6B4 = .+85072
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 85060 @ data: 0x0855C6B4 = .+85060
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

gGraphic_GameOverString:: @ Gfx102 in 0x08547A78
	.4byte GameOverString_Tiles-. @ data: 0x0855C6B4
	.4byte 1404 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
  gPalette_GameOverString::
		.4byte GameOverString_Pal-. @ data: 0x0855CC30
		.2byte 64 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

	@ Gfx103 in 0x08547A8C
	.4byte dummy-. @ data: 0x0855CC70 = .+86500
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte dummy-. @ data: 0x0855CC70 = .+86488
		.2byte 0 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

	@ Gfx104 in 0x08547AA0
	.4byte dummy-. @ data: 0x0855CC70 = .+86480
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte dummy-. @ data: 0x0855CC70 = .+86468
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx105 in 0x08547AB4
	.4byte dummy-. @ data: 0x0855CC70 = .+86460
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte dummy-. @ data: 0x0855CC70 = .+86448
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx106 in 0x08547AC8
	.4byte dummy-. @ data: 0x0855CC70 = .+86440
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte dummy-. @ data: 0x0855CC70 = .+86428
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx107 in 0x08547ADC
	.4byte dummy-. @ data: 0x0855CC70 = .+86420
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte dummy-. @ data: 0x0855CC70 = .+86408
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx108 in 0x08547AF0
	.4byte dummy-. @ data: 0x0855CC70 = .+86400
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte dummy-. @ data: 0x0855CC70 = .+86388
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx109 in 0x08547B04
	.4byte dummy-. @ data: 0x0855CC70 = .+86380
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte dummy-. @ data: 0x0855CC70 = .+86368
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx110 in 0x08547B18
	.4byte dummy-. @ data: 0x0855CC70 = .+86360
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte dummy-. @ data: 0x0855CC70 = .+86348
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx111 in 0x08547B2C
	.4byte dummy-. @ data: 0x0855CC70 = .+86340
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte dummy-. @ data: 0x0855CC70 = .+86328
		.2byte 0 @ bytesize
		.byte 0, 0 @ lz77(bool8), dst = PaletteID

	@ Gfx112 in 0x08547B40
	.4byte Recap_Tiles-. @ data: 0x0855CC70 = .+86320
	.4byte 16216 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte Recap_Pal-. @ data: 0x08560BC8 = .+102524
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

gGraphic_CsOmegaShip::	@ Gfx113 in 0x08547B54
	.4byte CsOmegaShip_Tiles-. @ data: 0x08560BE8 = .+102548
	.4byte 24700 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP8) 	@ rowsize(unused), props
	gPalette_CsOmegaShip::
		.4byte CsOmegaShip_Pal-. @ data: 0x08566C64 = .+127236
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Gfx114 in 0x08547B68
	.4byte CsDarkElf_Tiles-. @ data: 0x08566D44 = .+127452
	.4byte 7596 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte CsDarkElf_Pal-. @ data: 0x08568AF0 = .+135036
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Gfx115 in 0x08547B7C
	.4byte CsOmegaCall_Tiles-. @ data: 0x08568B10 = .+135060
	.4byte 18844 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP8) 	@ rowsize(unused), props
		@ Palette
		.4byte CsOmegaCall_Pal-. @ data: 0x0856D4AC = .+153892
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Gfx116 in 0x08547B90
	.4byte 154108 @ data: 0x0856D58C = .+154108
	.4byte 27280 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP8) 	@ rowsize(unused), props
		@ Palette
		.4byte 181376 @ data: 0x0857401C = .+181376
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Gfx117 in 0x08547BA4
	.4byte 181592 @ data: 0x085740FC = .+181592
	.4byte 16324 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP8) 	@ rowsize(unused), props
		@ Palette
		.4byte 197904 @ data: 0x085780C0 = .+197904
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Gfx118 in 0x08547BB8
	.4byte 198120 @ data: 0x085781A0 = .+198120
	.4byte 16140 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP8) 	@ rowsize(unused), props
		@ Palette
		.4byte 214248 @ data: 0x0857C0AC = .+214248
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Gfx119 in 0x08547BCC
	.4byte 214464 @ data: 0x0857C18C = .+214464
	.4byte 17416 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP8) 	@ rowsize(unused), props
		@ Palette
		.4byte 231868 @ data: 0x08580594 = .+231868
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Gfx120 in 0x08547BE0
	.4byte 232084 @ data: 0x08580674 = .+232084
	.4byte 10884 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP8) 	@ rowsize(unused), props
		@ Palette
		.4byte 242956 @ data: 0x085830F8 = .+242956
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Gfx121 in 0x08547BF4
	.4byte 243172 @ data: 0x085831D8 = .+243172
	.4byte 31544 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP8) 	@ rowsize(unused), props
		@ Palette
		.4byte 274704 @ data: 0x0858AD10 = .+274704
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Gfx122 in 0x08547C08
	.4byte 274920 @ data: 0x0858ADF0 = .+274920
	.4byte 18080 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP8) 	@ rowsize(unused), props
		@ Palette
		.4byte 292988 @ data: 0x0858F490 = .+292988
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Gfx123 in 0x08547C1C
	.4byte 293204 @ data: 0x0858F570 = .+293204
	.4byte 22744 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP8) 	@ rowsize(unused), props
		@ Palette
		.4byte 315936 @ data: 0x08594E48 = .+315936
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Gfx124 in 0x08547C30
	.4byte 316152 @ data: 0x08594F28 = .+316152
	.4byte 9276 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 325416 @ data: 0x08597364 = .+325416
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Gfx125 in 0x08547C44
	.4byte 325440 @ data: 0x08597384 = .+325440
	.4byte 15380 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP8) 	@ rowsize(unused), props
		@ Palette
		.4byte 340808 @ data: 0x0859AF98 = .+340808
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Gfx126 in 0x08547C58
	.4byte 341024 @ data: 0x0859B078 = .+341024
	.4byte 9664 | (64 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 350676 @ data: 0x0859D638 = .+350676
		.2byte 32 @ bytesize
		.byte 0, 10 @ lz77(bool8), dst = PaletteID

	@ Gfx127 in 0x08547C6C
	.4byte 350700 @ data: 0x0859D658 = .+350700
	.4byte 15720 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP8) 	@ rowsize(unused), props
		@ Palette
		.4byte 366408 @ data: 0x085A13C0 = .+366408
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Gfx128 in 0x08547C80
	.4byte 366624 @ data: 0x085A14A0 = .+366624
	.4byte 2500 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 369112 @ data: 0x085A1E64 = .+369112
		.2byte 96 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

gGraphic_OpeningAnim0:: @ Gfx129 in 0x08547C94
	.4byte 369200 @ data: 0x085A1EC4 = .+369200
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, LZ77 	@ rowsize(unused), props
		@ Palette
		.4byte 369188 @ data: 0x085A1EC4 = .+369188
		.2byte 0 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

gGraphic_OpeningAnim1:: @ Gfx130 in 0x08547CA8
	.4byte 369180 @ data: 0x085A1EC4 = .+369180
	.4byte 12252 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
  gPalette_OpeningAnim1::
		.4byte 381420 @ data: 0x085A4EA0 = .+381420
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

gGraphic_OpeningAnim2:: @ Gfx131 in 0x08547CBC
	.4byte 381444 @ data: 0x085A4EC0 = .+381444
	.4byte 12184 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | NO_PAL | BPP4) 	@ rowsize(unused), props
  gPalette_OpeningAnim2:: @ Palette
		.4byte 393616 @ data: 0x085A7E58 = .+393616
		.2byte 0 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

	@ Gfx132 in 0x08547CD0
	.4byte 393608 @ data: 0x085A7E58 = .+393608
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, LZ77 	@ rowsize(unused), props
		@ Palette
		.4byte 393596 @ data: 0x085A7E58 = .+393596
		.2byte 0 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Gfx133 in 0x08547CE4
	.4byte 393588 @ data: 0x085A7E58 = .+393588
	.4byte 0 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, LZ77 	@ rowsize(unused), props
		@ Palette
		.4byte 393576 @ data: 0x085A7E58 = .+393576
		.2byte 0 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

gGraphicData::

Capcom_Tiles:
  .incbin "graphics/bg/capcom.4bpp.lz"
Capcom_Pal:
  .incbin "graphics/bg/capcom.gbapal"

Inti_Tiles:
  .incbin "graphics/bg/inti.4bpp.lz"
Inti_Pal:
  .incbin "graphics/bg/inti.gbapal"

.incbin "graphics/bg/cutscene_085472a8.bin"

TitleZero_Tiles:
  .incbin "graphics/bg/title_zero.4bpp.lz"
TitleZero_Pal:
  .incbin "graphics/bg/title_zero.gbapal"

TitleCiel_Tiles:
  .incbin "graphics/bg/title_ciel.4bpp.lz"
TitleCiel_Pal:
  .incbin "graphics/bg/title_ciel.gbapal"

HUD_Tiles:
  .incbin "graphics/bg/hp_gauge.4bpp"
HUD_Pal:
  .incbin "graphics/bg/hp_gauge.gbapal"

MissionStart_Tiles:
  .incbin "graphics/bg/mission_start.4bpp"
MissionStart_Pal:
  .incbin "graphics/bg/mission_start.gbapal"

MissionFailed_Tiles:
  .incbin "graphics/bg/mission_failed.4bpp.lz"
MissionFailed_Pal:
  .incbin "graphics/bg/mission_failed.gbapal"

.incbin "graphics/bg/gfx_08547384.4bpp"
.incbin "graphics/bg/gfx_08547384.gbapal"

.incbin "graphics/bg/gfx_08547398.4bpp"
.incbin "graphics/bg/gfx_08547398.gbapal"

.incbin "graphics/bg/stage_clear.4bpp.lz"
.incbin "graphics/bg/stage_clear.gbapal"

.incbin "graphics/bg/game_over.4bpp.lz"
.incbin "graphics/bg/game_over.gbapal"

.incbin "graphics/bg/gfx_085473d4.4bpp"
.incbin "graphics/bg/gfx_085473d4.gbapal"

.incbin "graphics/bg/title_logo.4bpp"
.incbin "graphics/bg/title_logo.gbapal"

.incbin "graphics/bg/menu_main.4bpp.lz"
.incbin "graphics/bg/menu_main.gbapal"

.incbin "graphics/bg/menu_exskill.4bpp.lz"
.incbin "graphics/bg/menu_exskill.gbapal"

MiscMenu_Tiles:
  .incbin "graphics/bg/menu_others.4bpp.lz"
MiscMenu_Pal:
  .incbin "graphics/bg/menu_others.gbapal"

ElfMenu_Tiles:
  .incbin "graphics/bg/menu_elf.4bpp.lz"
ElfMenu_Pal:
  .incbin "graphics/bg/menu_elf.gbapal"

Zero3D0_Tiles:
  .incbin "graphics/bg/zero_3d/0.4bpp.lz"
Zero3D0_Pal:
  .incbin "graphics/bg/zero_3d/0.gbapal"

.incbin "graphics/bg/zero_3d/1.4bpp.lz"
.incbin "graphics/bg/zero_3d/1.gbapal"

.incbin "graphics/bg/zero_3d/2.4bpp.lz"
.incbin "graphics/bg/zero_3d/2.gbapal"

.incbin "graphics/bg/zero_3d/3.4bpp.lz"
.incbin "graphics/bg/zero_3d/3.gbapal"

.incbin "graphics/bg/zero_3d/4.4bpp.lz"
.incbin "graphics/bg/zero_3d/4.gbapal"

.incbin "graphics/bg/zero_3d/5.4bpp.lz"
.incbin "graphics/bg/zero_3d/5.gbapal"

.incbin "graphics/bg/zero_3d/6.4bpp.lz"
.incbin "graphics/bg/zero_3d/6.gbapal"

.incbin "graphics/bg/zero_3d/7.4bpp.lz"
.incbin "graphics/bg/zero_3d/7.gbapal"

.incbin "graphics/bg/zero_3d/8.4bpp.lz"
.incbin "graphics/bg/zero_3d/8.gbapal"

ElfCatNurse_Tiles:
  .incbin "graphics/bg/str_nurse_elf.4bpp"
ElfCatNurse_Pal:
  .incbin "graphics/bg/str_nurse_elf.gbapal"

ElfCatAnimal_Tiles:
  .incbin "graphics/bg/str_animal_elf.4bpp"
ElfCatAnimal_Pal:
  .incbin "graphics/bg/str_animal_elf.gbapal"

ElfCatHacker_Tiles:
  .incbin "graphics/bg/str_hacker_elf.4bpp"
ElfCatHacker_Pal:
  .incbin "graphics/bg/str_hacker_elf.gbapal"

SecretDickBlue_Tiles:
  .incbin "graphics/bg/secret_dick_blue.4bpp"
SecretDickBlue_Pal:
  .incbin "graphics/bg/secret_dick_blue.gbapal"

SecretDickRed_Tiles:
  .incbin "graphics/bg/secret_dick_red.4bpp"
SecretDickRed_Pal:
  .incbin "graphics/bg/secret_dick_red.gbapal"

ElfCatNone_Tiles:
  .incbin "graphics/bg/str_none_elf.4bpp"
ElfCatNone_Pal:
  .incbin "graphics/bg/str_none_elf.gbapal"

ElfTabNurse_Tiles:
  .incbin "graphics/bg/elftab/nurse.4bpp"
ElfTabNurse_Pal:
  .incbin "graphics/bg/elftab/nurse.gbapal"

ElfTabAnimal_Tiles:
  .incbin "graphics/bg/elftab/animal.4bpp"
ElfTabAnimal_Pal:
  .incbin "graphics/bg/elftab/animal.gbapal"

ElfTabHacker_Tiles:
  .incbin "graphics/bg/elftab/hacker.4bpp"
ElfTabHacker_Pal:
  .incbin "graphics/bg/elftab/hacker.gbapal"

CodeName_Tiles:
  .incbin "graphics/bg/codename.4bpp.lz"
CodeName_Pal:
  .incbin "graphics/bg/codename.gbapal"

GameOverString_Tiles:
  .incbin "graphics/bg/game_over_screen.4bpp.lz"
GameOverString_Pal:
  .incbin "graphics/bg/game_over_screen.gbapal"

dummy:

Recap_Tiles:
  .incbin "graphics/bg/cutscene_recap.4bpp.lz"
Recap_Pal:
  .incbin "graphics/bg/cutscene_recap.gbapal"

CsOmegaShip_Tiles:
  .incbin "graphics/bg/8bpp/cutscene_omegaship.8bpp.lz"
CsOmegaShip_Pal:
  .incbin "graphics/bg/8bpp/cutscene_omegaship.gbapal"

CsDarkElf_Tiles:
  .incbin "graphics/bg/cutscene_darkelf.4bpp.lz"
CsDarkElf_Pal:
  .incbin "graphics/bg/cutscene_darkelf.gbapal"

CsOmegaCall_Tiles:
  .incbin "graphics/bg/8bpp/cutscene_comeon_zero.8bpp.lz"
CsOmegaCall_Pal:
  .incbin "graphics/bg/8bpp/cutscene_comeon_zero.gbapal"

.incbin "graphics/bg/8bpp/cutscene_omega_white.8bpp.lz"
.incbin "graphics/bg/8bpp/cutscene_omega_white.gbapal"

.incbin "graphics/bg/bg.bin"
