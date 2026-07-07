.balign 4, 0

.global gGraphicHeader_Sprite_weapon_unk_127
gGraphicHeader_Sprite_weapon_unk_127:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_weapon_unk_127_0-. @ src
	.4byte 160 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 40, BPP4 	@ rowsize(unused), props

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_weapon_unk_127_1-. @ src
	.4byte 576 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, BPP4 	@ rowsize(unused), props

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_weapon_unk_127_2-. @ src
	.4byte 384 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, BPP4 	@ rowsize(unused), props

	@ Graphic 3
	.4byte gGraphicHeader_Sprite_weapon_unk_127_3-. @ src
	.4byte 512 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

	@ Graphic 4
	.4byte gGraphicHeader_Sprite_weapon_unk_127_4-. @ src
	.4byte 576 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, BPP4 	@ rowsize(unused), props

	@ Graphic 5
	.4byte gGraphicHeader_Sprite_weapon_unk_127_5-. @ src
	.4byte 512 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_weapon_unk_127_0:
	.incbin "sprites/dynamic/weapon/unk_127/sheet/0.4bpp"
	gGraphicHeader_Sprite_weapon_unk_127_0_Palettes:

gGraphicHeader_Sprite_weapon_unk_127_1:
	.incbin "sprites/dynamic/weapon/unk_127/sheet/1.4bpp"
	gGraphicHeader_Sprite_weapon_unk_127_1_Palettes:

gGraphicHeader_Sprite_weapon_unk_127_2:
	.incbin "sprites/dynamic/weapon/unk_127/sheet/2.4bpp"
	gGraphicHeader_Sprite_weapon_unk_127_2_Palettes:

gGraphicHeader_Sprite_weapon_unk_127_3:
	.incbin "sprites/dynamic/weapon/unk_127/sheet/3.4bpp"
	gGraphicHeader_Sprite_weapon_unk_127_3_Palettes:

gGraphicHeader_Sprite_weapon_unk_127_4:
	.incbin "sprites/dynamic/weapon/unk_127/sheet/4.4bpp"
	gGraphicHeader_Sprite_weapon_unk_127_4_Palettes:

gGraphicHeader_Sprite_weapon_unk_127_5:
	.incbin "sprites/dynamic/weapon/unk_127/sheet/5.4bpp"
	gGraphicHeader_Sprite_weapon_unk_127_5_Palettes:
