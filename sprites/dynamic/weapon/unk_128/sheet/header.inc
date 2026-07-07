.balign 4, 0

.global gGraphicHeader_Sprite_weapon_unk_128
gGraphicHeader_Sprite_weapon_unk_128:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_weapon_unk_128_0-. @ src
	.4byte 640 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 160, BPP4 	@ rowsize(unused), props

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_weapon_unk_128_1-. @ src
	.4byte 512 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_weapon_unk_128_2-. @ src
	.4byte 320 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 80, BPP4 	@ rowsize(unused), props

	@ Graphic 3
	.4byte gGraphicHeader_Sprite_weapon_unk_128_3-. @ src
	.4byte 512 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

	@ Graphic 4
	.4byte gGraphicHeader_Sprite_weapon_unk_128_4-. @ src
	.4byte 512 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_weapon_unk_128_0:
	.incbin "sprites/dynamic/weapon/unk_128/sheet/0.4bpp"
	gGraphicHeader_Sprite_weapon_unk_128_0_Palettes:

gGraphicHeader_Sprite_weapon_unk_128_1:
	.incbin "sprites/dynamic/weapon/unk_128/sheet/1.4bpp"
	gGraphicHeader_Sprite_weapon_unk_128_1_Palettes:

gGraphicHeader_Sprite_weapon_unk_128_2:
	.incbin "sprites/dynamic/weapon/unk_128/sheet/2.4bpp"
	gGraphicHeader_Sprite_weapon_unk_128_2_Palettes:

gGraphicHeader_Sprite_weapon_unk_128_3:
	.incbin "sprites/dynamic/weapon/unk_128/sheet/3.4bpp"
	gGraphicHeader_Sprite_weapon_unk_128_3_Palettes:

gGraphicHeader_Sprite_weapon_unk_128_4:
	.incbin "sprites/dynamic/weapon/unk_128/sheet/4.4bpp"
	gGraphicHeader_Sprite_weapon_unk_128_4_Palettes:
