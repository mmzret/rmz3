    .include "asm/macros.inc"

    .section .rodata

FontData: @ 0x080ff17c
    .incbin "data/gfx/font/font.4bpp"       @ gbagfx font.png font.4bpp

@ リザルト画面などで使うフォント
FontBold: @ 0x0810597c
    .incbin "data/gfx/font/font_bold.4bpp"  @ gbagfx font_bold.png font_bold.4bpp

PlttData_ARRAY_0810697c: @ 0x0810697c
    .incbin "data/gfx/font/font.gbapal"

@ タイトル画面の「つづきから」のようなフォント
FontBig: @ 0x08106a3c
    .incbin "data/gfx/font/font_big.4bpp"   @ gbagfx font_big.png font_big.4bpp

