.balign 4, 0

.global gGraphicHeader_Sprite_weapon_saber_walk
gGraphicHeader_Sprite_weapon_saber_walk:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_weapon_saber_walk_0-. @ src
	.4byte 896 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 224, BPP4 	@ rowsize(unused), props

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_weapon_saber_walk_1-. @ src
	.4byte 896 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 224, BPP4 	@ rowsize(unused), props

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_weapon_saber_walk_2-. @ src
	.4byte 704 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 176, BPP4 	@ rowsize(unused), props

	@ Graphic 3
	.4byte gGraphicHeader_Sprite_weapon_saber_walk_3-. @ src
	.4byte 192 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, BPP4 	@ rowsize(unused), props

	@ Graphic 4
	.4byte gGraphicHeader_Sprite_weapon_saber_walk_4-. @ src
	.4byte 192 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, BPP4 	@ rowsize(unused), props

	@ Graphic 5
	.4byte gGraphicHeader_Sprite_weapon_saber_walk_5-. @ src
	.4byte 192 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, BPP4 	@ rowsize(unused), props

	@ Graphic 6
	.4byte gGraphicHeader_Sprite_weapon_saber_walk_6-. @ src
	.4byte 64 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 16, BPP4 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_weapon_saber_walk_0:
	.incbin "sprites/dynamic/weapon/saber_walk/sheet/0.4bpp"

gGraphicHeader_Sprite_weapon_saber_walk_1:
	.incbin "sprites/dynamic/weapon/saber_walk/sheet/1.4bpp"

gGraphicHeader_Sprite_weapon_saber_walk_2:
	.incbin "sprites/dynamic/weapon/saber_walk/sheet/2.4bpp"

gGraphicHeader_Sprite_weapon_saber_walk_3:
	.incbin "sprites/dynamic/weapon/saber_walk/sheet/3.4bpp"

gGraphicHeader_Sprite_weapon_saber_walk_4:
	.incbin "sprites/dynamic/weapon/saber_walk/sheet/4.4bpp"

gGraphicHeader_Sprite_weapon_saber_walk_5:
	.incbin "sprites/dynamic/weapon/saber_walk/sheet/5.4bpp"

gGraphicHeader_Sprite_weapon_saber_walk_6:
	.incbin "sprites/dynamic/weapon/saber_walk/sheet/6.4bpp"
