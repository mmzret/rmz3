    .include "asm/macros.inc"

    .balign 4
    .section .rodata

.global gFont
gFont: @ 0x080ff17c
    .incbin "graphics/font/font.4bpp"       @ gbagfx font.png font.4bpp

    .balign 4, 0

@ リザルト画面などで使うフォント
.global gFontBold
gFontBold: @ 0x0810597c
    .incbin "graphics/font/font_bold.4bpp"  @ gbagfx font_bold.png font_bold.4bpp

    .balign 4, 0

.global gFontPalette
gFontPalette: @ 0x0810697c
    .incbin "graphics/font/font.pal"

    .balign 4, 0

@ タイトル画面の「つづきから」のようなフォント
.global gFontBig
gFontBig: @ 0x08106a3c
    .incbin "graphics/font/font_big.4bpp"   @ gbagfx font_big.png font_big.4bpp

