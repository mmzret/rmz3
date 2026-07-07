.balign 4, 0

.global gGraphicHeader_Sprite_weapon_unk_104
gGraphicHeader_Sprite_weapon_unk_104:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_weapon_unk_104_0-. @ src
	.4byte 128 | (88 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_weapon_unk_104_1-. @ src
	.4byte 128 | (88 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_weapon_unk_104_2-. @ src
	.4byte 128 | (88 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 32, BPP4 	@ rowsize(unused), props

	@ Graphic 3
	.4byte gGraphicHeader_Sprite_weapon_unk_104_3-. @ src
	.4byte 256 | (88 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, BPP4 	@ rowsize(unused), props

	@ Graphic 4
	.4byte gGraphicHeader_Sprite_weapon_unk_104_4-. @ src
	.4byte 256 | (88 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, BPP4 	@ rowsize(unused), props

	@ Graphic 5
	.4byte gGraphicHeader_Sprite_weapon_unk_104_5-. @ src
	.4byte 256 | (88 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, BPP4 	@ rowsize(unused), props

	@ Graphic 6
	.4byte gGraphicHeader_Sprite_weapon_unk_104_6-. @ src
	.4byte 256 | (88 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, BPP4 	@ rowsize(unused), props

	@ Graphic 7
	.4byte gGraphicHeader_Sprite_weapon_unk_104_7-. @ src
	.4byte 256 | (88 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, BPP4 	@ rowsize(unused), props

	@ Graphic 8
	.4byte gGraphicHeader_Sprite_weapon_unk_104_8-. @ src
	.4byte 256 | (88 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, BPP4 	@ rowsize(unused), props

	@ Graphic 9
	.4byte gGraphicHeader_Sprite_weapon_unk_104_9-. @ src
	.4byte 256 | (88 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, BPP4 	@ rowsize(unused), props

	@ Graphic 10
	.4byte gGraphicHeader_Sprite_weapon_unk_104_10-. @ src
	.4byte 256 | (88 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, BPP4 	@ rowsize(unused), props

	@ Graphic 11
	.4byte gGraphicHeader_Sprite_weapon_unk_104_11-. @ src
	.4byte 256 | (88 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, BPP4 	@ rowsize(unused), props

	@ Graphic 12
	.4byte gGraphicHeader_Sprite_weapon_unk_104_12-. @ src
	.4byte 256 | (88 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, BPP4 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_weapon_unk_104_0:
	.incbin "sprites/dynamic/weapon/unk_104/sheet/0.4bpp"
	gGraphicHeader_Sprite_weapon_unk_104_0_Palettes:

gGraphicHeader_Sprite_weapon_unk_104_1:
	.incbin "sprites/dynamic/weapon/unk_104/sheet/1.4bpp"
	gGraphicHeader_Sprite_weapon_unk_104_1_Palettes:

gGraphicHeader_Sprite_weapon_unk_104_2:
	.incbin "sprites/dynamic/weapon/unk_104/sheet/2.4bpp"
	gGraphicHeader_Sprite_weapon_unk_104_2_Palettes:

gGraphicHeader_Sprite_weapon_unk_104_3:
	.incbin "sprites/dynamic/weapon/unk_104/sheet/3.4bpp"
	gGraphicHeader_Sprite_weapon_unk_104_3_Palettes:

gGraphicHeader_Sprite_weapon_unk_104_4:
	.incbin "sprites/dynamic/weapon/unk_104/sheet/4.4bpp"
	gGraphicHeader_Sprite_weapon_unk_104_4_Palettes:

gGraphicHeader_Sprite_weapon_unk_104_5:
	.incbin "sprites/dynamic/weapon/unk_104/sheet/5.4bpp"
	gGraphicHeader_Sprite_weapon_unk_104_5_Palettes:

gGraphicHeader_Sprite_weapon_unk_104_6:
	.incbin "sprites/dynamic/weapon/unk_104/sheet/6.4bpp"
	gGraphicHeader_Sprite_weapon_unk_104_6_Palettes:

gGraphicHeader_Sprite_weapon_unk_104_7:
	.incbin "sprites/dynamic/weapon/unk_104/sheet/7.4bpp"
	gGraphicHeader_Sprite_weapon_unk_104_7_Palettes:

gGraphicHeader_Sprite_weapon_unk_104_8:
	.incbin "sprites/dynamic/weapon/unk_104/sheet/8.4bpp"
	gGraphicHeader_Sprite_weapon_unk_104_8_Palettes:

gGraphicHeader_Sprite_weapon_unk_104_9:
	.incbin "sprites/dynamic/weapon/unk_104/sheet/9.4bpp"
	gGraphicHeader_Sprite_weapon_unk_104_9_Palettes:

gGraphicHeader_Sprite_weapon_unk_104_10:
	.incbin "sprites/dynamic/weapon/unk_104/sheet/10.4bpp"
	gGraphicHeader_Sprite_weapon_unk_104_10_Palettes:

gGraphicHeader_Sprite_weapon_unk_104_11:
	.incbin "sprites/dynamic/weapon/unk_104/sheet/11.4bpp"
	gGraphicHeader_Sprite_weapon_unk_104_11_Palettes:

gGraphicHeader_Sprite_weapon_unk_104_12:
	.incbin "sprites/dynamic/weapon/unk_104/sheet/12.4bpp"
	gGraphicHeader_Sprite_weapon_unk_104_12_Palettes:
