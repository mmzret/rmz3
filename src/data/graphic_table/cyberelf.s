  .include "asm/macros.inc"

.section .rodata
.balign 4, 0

@ Cyber Elf Mugshot + Cyberelf Category Icons
.global gElfMugshotGraphics
gElfMugshotGraphics:

MartinaA: @ Gfx0
	.4byte MartinaA_Tiles-.
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte MartinaA_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx1
	.4byte 1516
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte 2016
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx2
	.4byte 2072
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte 2572
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx3
	.4byte 2628
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte 3128
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx4
	.4byte 3184
	.4byte 496 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 3668
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx5
	.4byte 3724
	.4byte 496 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 4208
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx6
	.4byte 4264
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte 4764
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx7
	.4byte 4820
	.4byte 496 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 5304
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx8
	.4byte 5360
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte 5860
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

  @ Gfx9
	.4byte 5916
	.4byte 0 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 5904
		.2byte 0 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

NurseGreen: @ Gfx10
	.4byte NurseGreen_Tiles-.
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte NurseGreen_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx11
	.4byte 0x1934
	.4byte 0 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 0, 0 	@ rowsize(unused), props
		@ Palette
		.4byte 0x1928
		.2byte 0 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx12
	.4byte Cloppe_Tiles-.
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte Cloppe_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx13
	.4byte 6988
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte 7488
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx14
	.4byte 7544
	.4byte 508 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 8040
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx15
	.4byte SlimeC_Tiles-.
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte SlimeC_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

CheetahA: @ Gfx16
	.4byte CheetahA_Tiles-.
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte CheetahA_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

CheetahB: @ Gfx17
	.4byte CheetahB_Tiles-.
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte CheetahB_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx18
	.4byte MayaA_Tiles-.
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte 10264
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx19
	.4byte MayaB_Tiles-.
	.4byte 452 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 10760
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx20
	.4byte 10816
	.4byte 488 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 11292
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx21
	.4byte 11348
	.4byte 452 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 11788
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx22
	.4byte GambulA_Tiles-.
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte 12344
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx23
	.4byte GambulB_Tiles-.
	.4byte 396 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 12784
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx24
	.4byte Bird_Tiles-.
	.4byte 464 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte Bird_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx25
	.4byte SeaOtter_Tiles-.
	.4byte 476 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte SeaOtter_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx26
	.4byte 13868
	.4byte 500 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte 14356
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx27
	.4byte Archix_Tiles-.
	.4byte 464 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte Archix_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx28
	.4byte ByseA_Tiles-.
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte ByseA_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx29
	.4byte ByseB_Tiles-.
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte ByseB_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx30
	.4byte ByseC_Tiles-.
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte ByseC_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx31
	.4byte Dylphina_Tiles-.
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte Dylphina_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx32
	.4byte NinjaA_Tiles-.
	.4byte 504 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte NinjaA_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx33
	.4byte NinjaB_Tiles-.
	.4byte 448 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte NinjaB_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx34
	.4byte MikoElf_Tiles-.
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte MikoElf_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx35
	.4byte Clokkle_Tiles-.
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte Clokkle_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx36
	.4byte sMetallElf-.
	.4byte 484 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte sMetallElf_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx37
	.4byte Gfx37-.
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte Gfx37_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx38
	.4byte Gfx38-.
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte Gfx38_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx39
	.4byte Gfx39-.
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte Gfx39_Pal-.
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx40
	.4byte Gfx40-. @ data: 0x0863B638
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte Gfx40_Pal-. @ data: 0x0863B838
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx41
	.4byte Gfx41-. @ data: 0x0863B878
	.4byte 512 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte Gfx41_Pal-. @ data: 0x0863BA78
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx42
	.4byte Gfx42-. @ data: 0x0863BAB8
	.4byte 460 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte Gfx42_Pal-. @ data: 0x0863BC84
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

.global gCyberElfCategoryIcons
gCyberElfCategoryIcons:
  @ Gfx43
	.4byte sNurseElfIcon-. @ data: 0x0863BCC4
	.4byte 412 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte sNurseElfIcon_Pal-. @ data: 0x0863BE60
		.2byte 32 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx44
	.4byte sAnimalElfIcon-. @ data: 0x0863BE80
	.4byte 368 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte sAnimalElfIcon_Pal-. @ data: 0x0863BFF0
		.2byte 32 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx45
	.4byte sHackerElfIcon-. @ data: 0x0863C010
	.4byte 236 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte sHackerElfIcon_Pal-. @ data: 0x0863C0FC
		.2byte 32 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx46
	.4byte Gfx46-. @ data: 0x0863C11C
	.4byte 492 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte Gfx46_Pal-. @ data: 0x0863C308
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

	@ Gfx47
	.4byte Gfx47-. @ data: 0x0863C348
	.4byte 496 | (863 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, (LZ77 | BPP4) 	@ rowsize(unused), props
		@ Palette
		.4byte Gfx47_Pal-. @ data: 0x0863C538
		.2byte 64 @ bytesize
		.byte 0, 11 @ lz77(bool8), dst = PaletteID

MartinaA_Tiles:
  .incbin "graphics/cyberelf/martina_a.4bpp"
MartinaA_Pal:
  .incbin "graphics/cyberelf/martina_a.gbapal"

.incbin "graphics/cyberelf/martina_b.4bpp"
.incbin "graphics/cyberelf/martina_b.gbapal"

.incbin "graphics/cyberelf/martina_c.4bpp"
.incbin "graphics/cyberelf/martina_c.gbapal"

.incbin "graphics/cyberelf/nurse_red_a.4bpp"
.incbin "graphics/cyberelf/nurse_red_a.gbapal"

.incbin "graphics/cyberelf/nurse_red_b.4bpp.lz"
.incbin "graphics/cyberelf/nurse_red_b.gbapal"

.incbin "graphics/cyberelf/nurse_blue_a.4bpp.lz"
.incbin "graphics/cyberelf/nurse_blue_a.gbapal"

.incbin "graphics/cyberelf/nurse_blue_b.4bpp"
.incbin "graphics/cyberelf/nurse_blue_b.gbapal"

.incbin "graphics/cyberelf/nurse_blue_c.4bpp.lz"
.incbin "graphics/cyberelf/nurse_blue_c.gbapal"

.incbin "graphics/cyberelf/nurse_blue_b.4bpp"
.incbin "graphics/cyberelf/nurse_blue_b.gbapal"

NurseGreen_Tiles:
  .incbin "graphics/cyberelf/nurse_green.4bpp"
NurseGreen_Pal:
  .incbin "graphics/cyberelf/nurse_green.gbapal"

@ Gfx11, Gfx12
Cloppe_Tiles:
  .incbin "graphics/cyberelf/cloppe.4bpp"
Cloppe_Pal:
  .incbin "graphics/cyberelf/cloppe.gbapal"

@ Gfx13
SlimeA_Tiles:
  .incbin "graphics/cyberelf/slime_a.4bpp"
SlimeA_Pal:
  .incbin "graphics/cyberelf/slime_a.gbapal"

@ Gfx14
SlimeB_Tiles:
  .incbin "graphics/cyberelf/slime_b.4bpp.lz"
SlimeB_Pal:
  .incbin "graphics/cyberelf/slime_b.gbapal"

@ Gfx15
SlimeC_Tiles:
  .incbin "graphics/cyberelf/slime_c.4bpp"
SlimeC_Pal:
  .incbin "graphics/cyberelf/slime_c.gbapal"

@ Gfx16
CheetahA_Tiles:
  .incbin "graphics/cyberelf/cheetah_a.4bpp"
CheetahA_Pal:
  .incbin "graphics/cyberelf/cheetah_a.gbapal"

CheetahB_Tiles: @ Gfx17
  .incbin "graphics/cyberelf/cheetah_b.4bpp"
CheetahB_Pal:
  .incbin "graphics/cyberelf/cheetah_b.gbapal"

MayaA_Tiles: @ Gfx18
  .incbin "graphics/cyberelf/maya_a.4bpp"
  .incbin "graphics/cyberelf/maya_a.gbapal"

MayaB_Tiles: @ Gfx19
  .incbin "graphics/cyberelf/maya_b.4bpp.lz"
  .incbin "graphics/cyberelf/maya_b.gbapal"

KwappaA_Tiles: @ Gfx20
  .incbin "graphics/cyberelf/kwappa_a.4bpp.lz"
  .incbin "graphics/cyberelf/kwappa_a.gbapal"

KwappaB_Tiles: @ Gfx21
  .incbin "graphics/cyberelf/kwappa_b.4bpp.lz"
  .incbin "graphics/cyberelf/kwappa_b.gbapal"

GambulA_Tiles: @ Gfx22
  .incbin "graphics/cyberelf/gambul_a.4bpp"
  .incbin "graphics/cyberelf/gambul_a.gbapal"

GambulB_Tiles: @ Gfx23
  .incbin "graphics/cyberelf/gambul_b.4bpp.lz"
  .incbin "graphics/cyberelf/gambul_b.gbapal"

Bird_Tiles: @ Gfx24
  .incbin "graphics/cyberelf/bird.4bpp.lz"
Bird_Pal:
  .incbin "graphics/cyberelf/bird.gbapal"

SeaOtter_Tiles: @ Gfx25
  .incbin "graphics/cyberelf/sea_otter.4bpp.lz"
SeaOtter_Pal:
  .incbin "graphics/cyberelf/sea_otter.gbapal"

Bee_Tiles: @ Gfx26
  .incbin "graphics/cyberelf/bee.4bpp.lz"
Bee_Pal:
  .incbin "graphics/cyberelf/bee.gbapal"

Archix_Tiles: @ Gfx27
  .incbin "graphics/cyberelf/archix.4bpp.lz"
Archix_Pal:
  .incbin "graphics/cyberelf/archix.gbapal"

ByseA_Tiles: @ Gfx28
  .incbin "graphics/cyberelf/byse_a.4bpp"
ByseA_Pal:
  .incbin "graphics/cyberelf/byse_a.gbapal"

ByseB_Tiles: @ Gfx29
  .incbin "graphics/cyberelf/byse_b.4bpp"
ByseB_Pal:
  .incbin "graphics/cyberelf/byse_b.gbapal"

ByseC_Tiles: @ Gfx30
  .incbin "graphics/cyberelf/byse_c.4bpp"
ByseC_Pal:
  .incbin "graphics/cyberelf/byse_c.gbapal"

Dylphina_Tiles: @ Gfx31
  .incbin "graphics/cyberelf/dylphina.4bpp"
Dylphina_Pal:
  .incbin "graphics/cyberelf/dylphina.gbapal"

NinjaA_Tiles: @ Gfx32
  .incbin "graphics/cyberelf/ninja_a.4bpp.lz"
NinjaA_Pal:
  .incbin "graphics/cyberelf/ninja_a.gbapal"

NinjaB_Tiles: @ Gfx33
  .incbin "graphics/cyberelf/ninja_b.4bpp.lz"
NinjaB_Pal:
  .incbin "graphics/cyberelf/ninja_b.gbapal"

MikoElf_Tiles: @ Gfx34
  .incbin "graphics/cyberelf/miko.4bpp"
MikoElf_Pal:
  .incbin "graphics/cyberelf/miko.gbapal"

Clokkle_Tiles: @ Gfx35
  .incbin "graphics/cyberelf/clokkle.4bpp"
Clokkle_Pal:
  .incbin "graphics/cyberelf/clokkle.gbapal"

sMetallElf: @ Gfx36
  .incbin "graphics/cyberelf/metall.4bpp.lz"
sMetallElf_Pal:
  .incbin "graphics/cyberelf/metall.gbapal"

Gfx37:
  .incbin "graphics/cyberelf/armor_a.4bpp"
Gfx37_Pal:
  .incbin "graphics/cyberelf/armor_a.gbapal"

Gfx38:
  .incbin "graphics/cyberelf/armor_b.4bpp"
Gfx38_Pal:
  .incbin "graphics/cyberelf/armor_b.gbapal"

Gfx39:
  .incbin "graphics/cyberelf/stopx.4bpp"
Gfx39_Pal:
  .incbin "graphics/cyberelf/stopx.gbapal"

Gfx40:
  .incbin "graphics/cyberelf/giant_a.4bpp"
Gfx40_Pal:
  .incbin "graphics/cyberelf/giant_a.gbapal"

Gfx41:
  .incbin "graphics/cyberelf/giant_b.4bpp"
Gfx41_Pal:
  .incbin "graphics/cyberelf/giant_b.gbapal"

Gfx42:
  .incbin "graphics/cyberelf/whistle.4bpp.lz"
Gfx42_Pal:
  .incbin "graphics/cyberelf/whistle.gbapal"

sNurseElfIcon:      
  .incbin "graphics/cyberelf/type_nurse.4bpp.lz"
sNurseElfIcon_Pal:
  .incbin "graphics/cyberelf/type_nurse.gbapal"

sAnimalElfIcon:
  .incbin "graphics/cyberelf/type_animal.4bpp.lz"
sAnimalElfIcon_Pal:
  .incbin "graphics/cyberelf/type_animal.gbapal"

sHackerElfIcon:
  .incbin "graphics/cyberelf/type_hacker.4bpp.lz"
sHackerElfIcon_Pal:
  .incbin "graphics/cyberelf/type_hacker.gbapal"

Gfx46:
  .incbin "graphics/cyberelf/mottdott_a.4bpp.lz"
Gfx46_Pal:
  .incbin "graphics/cyberelf/mottdott_a.gbapal"

Gfx47:
  .incbin "graphics/cyberelf/mottdott_b.4bpp.lz"
Gfx47_Pal:
  .incbin "graphics/cyberelf/mottdott_b.gbapal"
