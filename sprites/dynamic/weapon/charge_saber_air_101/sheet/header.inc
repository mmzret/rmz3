.balign 4, 0

.global gGraphicHeader_Sprite_weapon_charge_saber_air_101
gGraphicHeader_Sprite_weapon_charge_saber_air_101:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_weapon_charge_saber_air_101_0-. @ src
	.4byte 32 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 8, BPP4 	@ rowsize(unused), props

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_weapon_charge_saber_air_101_1-. @ src
	.4byte 64 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 16, BPP4 	@ rowsize(unused), props

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_weapon_charge_saber_air_101_2-. @ src
	.4byte 1440 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 360, BPP4 	@ rowsize(unused), props

	@ Graphic 3
	.4byte gGraphicHeader_Sprite_weapon_charge_saber_air_101_3-. @ src
	.4byte 1472 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 368, BPP4 	@ rowsize(unused), props

	@ Graphic 4
	.4byte gGraphicHeader_Sprite_weapon_charge_saber_air_101_4-. @ src
	.4byte 1248 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 312, BPP4 	@ rowsize(unused), props

	@ Graphic 5
	.4byte gGraphicHeader_Sprite_weapon_charge_saber_air_101_5-. @ src
	.4byte 1280 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 320, BPP4 	@ rowsize(unused), props

	@ Graphic 6
	.4byte gGraphicHeader_Sprite_weapon_charge_saber_air_101_6-. @ src
	.4byte 1056 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 264, BPP4 	@ rowsize(unused), props

	@ Graphic 7
	.4byte gGraphicHeader_Sprite_weapon_charge_saber_air_101_7-. @ src
	.4byte 832 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 208, BPP4 	@ rowsize(unused), props

	@ Graphic 8
	.4byte gGraphicHeader_Sprite_weapon_charge_saber_air_101_8-. @ src
	.4byte 832 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 208, BPP4 	@ rowsize(unused), props

	@ Graphic 9
	.4byte gGraphicHeader_Sprite_weapon_charge_saber_air_101_9-. @ src
	.4byte 832 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 208, BPP4 	@ rowsize(unused), props

	@ Graphic 10
	.4byte gGraphicHeader_Sprite_weapon_charge_saber_air_101_10-. @ src
	.4byte 896 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 224, BPP4 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_weapon_charge_saber_air_101_0:
	.incbin "sprites/dynamic/weapon/charge_saber_air_101/sheet/0.4bpp"

gGraphicHeader_Sprite_weapon_charge_saber_air_101_1:
	.incbin "sprites/dynamic/weapon/charge_saber_air_101/sheet/1.4bpp"

gGraphicHeader_Sprite_weapon_charge_saber_air_101_2:
	.incbin "sprites/dynamic/weapon/charge_saber_air_101/sheet/2.4bpp"

gGraphicHeader_Sprite_weapon_charge_saber_air_101_3:
	.incbin "sprites/dynamic/weapon/charge_saber_air_101/sheet/3.4bpp"

gGraphicHeader_Sprite_weapon_charge_saber_air_101_4:
	.incbin "sprites/dynamic/weapon/charge_saber_air_101/sheet/4.4bpp"

gGraphicHeader_Sprite_weapon_charge_saber_air_101_5:
	.incbin "sprites/dynamic/weapon/charge_saber_air_101/sheet/5.4bpp"

gGraphicHeader_Sprite_weapon_charge_saber_air_101_6:
	.incbin "sprites/dynamic/weapon/charge_saber_air_101/sheet/6.4bpp"

gGraphicHeader_Sprite_weapon_charge_saber_air_101_7:
	.incbin "sprites/dynamic/weapon/charge_saber_air_101/sheet/7.4bpp"

gGraphicHeader_Sprite_weapon_charge_saber_air_101_8:
	.incbin "sprites/dynamic/weapon/charge_saber_air_101/sheet/8.4bpp"

gGraphicHeader_Sprite_weapon_charge_saber_air_101_9:
	.incbin "sprites/dynamic/weapon/charge_saber_air_101/sheet/9.4bpp"

gGraphicHeader_Sprite_weapon_charge_saber_air_101_10:
	.incbin "sprites/dynamic/weapon/charge_saber_air_101/sheet/10.4bpp"
