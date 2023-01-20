    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata

    graphic_start

CapcomLogoGraphic: @ 0x08547280
    graphic [
        src: 0x08547cf8,
        size: 2400,
        ofs: 0x0,
        chunk_size: 0x100,
        props: (LZ77 | BPP4)
    ]
    palette [
        src: 0x08548658,
        length: 16,
        lz77: 0,
        dst: 0x2
    ]

IntiLogoGraphic: @ 0x08547294
    graphic [
        src: 0x08548678,
        size: 1260,
        ofs: 0x0,
        chunk_size: 0x100,
        props: (LZ77 | BPP4)
    ]
    palette [
        src: 0x08548b64,
        length: 16,
        lz77: 0,
        dst: 0x2
    ]

Graphic_085472a8: @ 0x085472a8
    graphic [
        src: 0x08548b84,
        size: 9456,
        ofs: 256,
        chunk_size: 0x100,
        props: (LZ77 | BPP8)
    ]
    palette [
        src: 0x0854b074,
        length: 128,
        lz77: 0,
        dst: 0x6
    ]

ZeroTitleScreenGraphic: @ 0x085472bc
    graphic [
        src: 0x0854b174,
        size: 11468,
        ofs: 0,
        chunk_size: 0x100,
        props: (LZ77 | BPP4)
    ]
    palette [
        src: 0x0854de40,
        length: 32,
        lz77: 0,
        dst: 0xE
    ]

CielTitleScreenGraphic: @ 0x085472d0
    graphic [
        src: 0x0854de80,
        size: 8260,
        ofs: 0,
        chunk_size: 0x100,
        props: (LZ77 | BPP4)
    ]
    palette [
        src: 0x0854fec4,
        length: 32,
        lz77: 0,
        dst: 0xE
    ]

NullGraphics_085472e4: @ 0x085472e4
    graphic 0x0854ff04, 0, 0, 0, 0
    palette 0x0854ff04, 0, 0, 0xE

    graphic 0x0854ff04, 0, 0, 0, 0
    palette 0x0854ff04, 0, 0, 0x2

    graphic 0x0854ff04, 0, 0, 0, 0
    palette 0x0854ff04, 0, 0, 0x2

    graphic 0x0854ff04, 0, 256, 0, LZ77
    palette 0x0854ff04, 0, 0, 0x6

    graphic 0x0854ff04, 0, 0, 0, 0
    palette 0x0854ff04, 0, 0, 0

HpGaugeGraphic: @ 0x08547348
    graphic [
        src: 0x0854ff04,
        size: 6080,
        ofs: 512,
        chunk_size: 0x100,
        props: BPP4
    ]
    palette [
        src: 0x085516c4,
        length: 16,
        lz77: 0,
        dst: 1
    ]

MissionStartGraphic: @ 0x0854735c
    graphic [
        src: 0x085516e4,
        size: 1856,
        ofs: 512,
        chunk_size: 0x100,
        props: BPP4
    ]
    palette [
        src: 0x08551e24,
        length: 16,
        lz77: 0,
        dst: 1
    ]

MissionFailedGraphic: @ 0x08547370
    graphic [
        src: 0x08551e44,
        size: 804,
        ofs: 512,
        chunk_size: 0x100,
        props: (LZ77 | BPP4)
    ]
    palette [
        src: 0x08552168,
        length: 16,
        lz77: 0,
        dst: 1
    ]

Graphic_08547384: @ 0x08547384
    graphic [
        src: 0x08552188,
        size: 2368,
        ofs: 512,
        chunk_size: 0x100,
        props: BPP4
    ]
    palette [
        src: 0x08552ac8,
        length: 16,
        lz77: 0,
        dst: 1
    ]

Graphic_08547398: @ 0x08547398
    graphic [
        src: 0x08552ae8,
        size: 832,
        ofs: 512,
        chunk_size: 0x100,
        props: BPP4
    ]
    palette [
        src: 0x08552e28,
        length: 16,
        lz77: 0,
        dst: 1
    ]

StageClearGraphic: @ 0x085473ac
    graphic [
        src: 0x08552e48,
        size: 1408,
        ofs: 512,
        chunk_size: 0x100,
        props: (LZ77 | BPP4)
    ]
    palette [
        src: 0x085533c8,
        length: 16,
        lz77: 0,
        dst: 1
    ]

GameOverGraphic: @ 0x085473c0
    graphic [
        src: 0x085533e8,
        size: 1564,
        ofs: 512,
        chunk_size: 0x100,
        props: (LZ77 | BPP4)
    ]
    palette [
        src: 0x08553a04,
        length: 16,
        lz77: 0,
        dst: 1
    ]

Graphic_085473d4: @ 0x085473d4
    graphic [
        src: 0x08553a24,
        size: 1344,
        ofs: 896,
        chunk_size: 168,
        props: BPP4
    ]
    palette [
        src: 0x08553f64,
        length: 16,
        lz77: 0,
        dst: 1
    ]

TitleLogoGraphic: @ 0x085473e8
    graphic [
        src: 0x08553f84,
        size: 1152,
        ofs: 512,
        chunk_size: 0x100,
        props: BPP4
    ]
    palette [
        src: 0x08554404,
        length: 16,
        lz77: 0,
        dst: 1
    ]

NullGraphic_085473fc: @ 0x085473fc
    graphic 0x8554424, 0, 0, 0, 0
    palette 0x8554424, 0, 0, 0

MainMenuTilesetGraphic: @ 0x08547410
    graphic [
        src: 0x08554424,
        size: 7072,
        ofs: 0,
        chunk_size: 0x100,
        props: (LZ77 | BPP4)
    ]
    palette [
        src: 0x08555fc4,
        length: 112,
        lz77: 0,
        dst: 2
    ]

ExSkillMenuTilesetGraphic: @ 0x08547424

    # Todo
    .incbin "data/gfx/cutscene/cutscene.bin"
