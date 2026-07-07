.balign 4, 0

.global gGraphicHeader_Sprite_weapon_unk_8b
gGraphicHeader_Sprite_weapon_unk_8b:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_weapon_unk_8b_0-. @ src
	.4byte 512 | (80 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_weapon_unk_8b_1-. @ src
	.4byte 512 | (80 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_weapon_unk_8b_2-. @ src
	.4byte 512 | (80 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

	@ Graphic 3
	.4byte gGraphicHeader_Sprite_weapon_unk_8b_3-. @ src
	.4byte 512 | (80 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_weapon_unk_8b_0:
	.incbin "sprites/dynamic/weapon/unk_8b/sheet/0.4bpp"

gGraphicHeader_Sprite_weapon_unk_8b_1:
	.incbin "sprites/dynamic/weapon/unk_8b/sheet/1.4bpp"

gGraphicHeader_Sprite_weapon_unk_8b_2:
	.incbin "sprites/dynamic/weapon/unk_8b/sheet/2.4bpp"

gGraphicHeader_Sprite_weapon_unk_8b_3:
	.incbin "sprites/dynamic/weapon/unk_8b/sheet/3.4bpp"
