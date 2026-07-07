.balign 4, 0

.global gGraphicHeader_Sprite_weapon_unk_129
gGraphicHeader_Sprite_weapon_unk_129:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_weapon_unk_129_0-. @ src
	.4byte 160 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 40, BPP4 	@ rowsize(unused), props

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_weapon_unk_129_1-. @ src
	.4byte 576 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, BPP4 	@ rowsize(unused), props

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_weapon_unk_129_2-. @ src
	.4byte 352 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 88, BPP4 	@ rowsize(unused), props

	@ Graphic 3
	.4byte gGraphicHeader_Sprite_weapon_unk_129_3-. @ src
	.4byte 512 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

	@ Graphic 4
	.4byte gGraphicHeader_Sprite_weapon_unk_129_4-. @ src
	.4byte 544 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 136, BPP4 	@ rowsize(unused), props

	@ Graphic 5
	.4byte gGraphicHeader_Sprite_weapon_unk_129_5-. @ src
	.4byte 512 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_weapon_unk_129_0:
	.incbin "sprites/dynamic/weapon/unk_129/sheet/0.4bpp"
	gGraphicHeader_Sprite_weapon_unk_129_0_Palettes:

gGraphicHeader_Sprite_weapon_unk_129_1:
	.incbin "sprites/dynamic/weapon/unk_129/sheet/1.4bpp"
	gGraphicHeader_Sprite_weapon_unk_129_1_Palettes:

gGraphicHeader_Sprite_weapon_unk_129_2:
	.incbin "sprites/dynamic/weapon/unk_129/sheet/2.4bpp"
	gGraphicHeader_Sprite_weapon_unk_129_2_Palettes:

gGraphicHeader_Sprite_weapon_unk_129_3:
	.incbin "sprites/dynamic/weapon/unk_129/sheet/3.4bpp"
	gGraphicHeader_Sprite_weapon_unk_129_3_Palettes:

gGraphicHeader_Sprite_weapon_unk_129_4:
	.incbin "sprites/dynamic/weapon/unk_129/sheet/4.4bpp"
	gGraphicHeader_Sprite_weapon_unk_129_4_Palettes:

gGraphicHeader_Sprite_weapon_unk_129_5:
	.incbin "sprites/dynamic/weapon/unk_129/sheet/5.4bpp"
	gGraphicHeader_Sprite_weapon_unk_129_5_Palettes:
