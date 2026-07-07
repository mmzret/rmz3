.balign 4, 0

.global gGraphicHeader_Sprite_weapon_unk_126
gGraphicHeader_Sprite_weapon_unk_126:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_weapon_unk_126_0-. @ src
	.4byte 160 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 40, BPP4 	@ rowsize(unused), props

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_weapon_unk_126_1-. @ src
	.4byte 576 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, BPP4 	@ rowsize(unused), props

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_weapon_unk_126_2-. @ src
	.4byte 384 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, BPP4 	@ rowsize(unused), props

	@ Graphic 3
	.4byte gGraphicHeader_Sprite_weapon_unk_126_3-. @ src
	.4byte 512 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

	@ Graphic 4
	.4byte gGraphicHeader_Sprite_weapon_unk_126_4-. @ src
	.4byte 544 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 136, BPP4 	@ rowsize(unused), props

	@ Graphic 5
	.4byte gGraphicHeader_Sprite_weapon_unk_126_5-. @ src
	.4byte 512 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_weapon_unk_126_0:
	.incbin "sprites/dynamic/weapon/unk_126/sheet/0.4bpp"

gGraphicHeader_Sprite_weapon_unk_126_1:
	.incbin "sprites/dynamic/weapon/unk_126/sheet/1.4bpp"

gGraphicHeader_Sprite_weapon_unk_126_2:
	.incbin "sprites/dynamic/weapon/unk_126/sheet/2.4bpp"

gGraphicHeader_Sprite_weapon_unk_126_3:
	.incbin "sprites/dynamic/weapon/unk_126/sheet/3.4bpp"

gGraphicHeader_Sprite_weapon_unk_126_4:
	.incbin "sprites/dynamic/weapon/unk_126/sheet/4.4bpp"

gGraphicHeader_Sprite_weapon_unk_126_5:
	.incbin "sprites/dynamic/weapon/unk_126/sheet/5.4bpp"
