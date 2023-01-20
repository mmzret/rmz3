    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata

    graphic_start

ElfMugshotGraphics: @ 0x08635f24
    @ 0x08635f24
    graphic [
        src: 0x086362e4,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x086364e4,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08635f38
    graphic [
        src: 0x08636524,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x08636724,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08635f4c
    graphic [
        src: 0x08636764,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x08636964,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08635f60
    graphic [
        src: 0x086369a4,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x08636ba4,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08635f74
    graphic [
        src: 0x08636be4,
        size: 496,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ] 
    palette [
        src: 0x08636dd4,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08635f88
    graphic [
        src: 0x08636e14,
        size: 496,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ] 
    palette [
        src: 0x08637004,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08635f9c
    graphic [
        src: 0x08637044,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x08637244,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08635fb0
    graphic [
        src: 0x08637284,
        size: 496,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ] 
    palette [
        src: 0x08637474,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08635fc4
    graphic [
        src: 0x086374b4,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x086376b4,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08635fd8
    graphic [
        src: 0x086376f4,
        size: 0,
        ofs: 863,
        chunk_size: 0,
        props: 0
    ] 
    palette [
        src: 0x086376f4,
        length: 0,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08635fec
    graphic [
        src: 0x086376f4,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x086378f4,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08636000
    graphic [
        src: 0x08637934,
        size: 0,
        ofs: 863,
        chunk_size: 0,
        props: 0
    ] 
    palette [
        src: 0x08637934,
        length: 0,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08636014
    graphic [
        src: 0x08637934,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x08637b34,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08636028
    graphic [
        src: 0x08637b74,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x08637d74,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x0863603c
    graphic [
        src: 0x08637db4,
        size: 508,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ] 
    palette [
        src: 0x08637fb0,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08636050
    graphic [
        src: 0x08637ff0,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x086381f0,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08636064
    graphic [
        src: 0x08638230,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x08638430,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08636078
    graphic [
        src: 0x08638470,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x08638670,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x0863608c
    graphic [
        src: 0x086386b0,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x086388b0,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x086360a0
    graphic [
        src: 0x086388f0,
        size: 452,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ] 
    palette [
        src: 0x08638ab4,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x086360b4
    graphic [
        src: 0x08638af4,
        size: 488,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ] 
    palette [
        src: 0x08638cdc,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x086360c8
    graphic [
        src: 0x08638d1c,
        size: 452,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ] 
    palette [
        src: 0x08638ee0,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x086360dc
    graphic [
        src: 0x08638f20,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x08639120,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x086360f0
    graphic [
        src: 0x08639160,
        size: 396,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ] 
    palette [
        src: 0x086392ec,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08636104
    graphic [
        src: 0x0863932c,
        size: 464,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ] 
    palette [
        src: 0x086394fc,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08636118
    graphic [
        src: 0x0863953c,
        size: 476,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ] 
    palette [
        src: 0x08639718,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x0863612c
    graphic [
        src: 0x08639758,
        size: 500,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ] 
    palette [
        src: 0x0863994c,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08636140
    graphic [
        src: 0x0863998c,
        size: 464,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ] 
    palette [
        src: 0x08639b5c,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08636154
    graphic [
        src: 0x08639b9c,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x08639d9c,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08636168
    graphic [
        src: 0x08639ddc,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x08639fdc,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x0863617c
    graphic [
        src: 0x0863a01c,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x0863a21c,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08636190
    graphic [
        src: 0x0863a25c,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x0863a45c,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x086361a4
    graphic [
        src: 0x0863a49c,
        size: 504,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ]
    palette [
        src: 0x0863a694,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x086361b8
    graphic [
        src: 0x0863a6d4,
        size: 448,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ]
    palette [
        src: 0x0863a894,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x086361cc
    graphic [
        src: 0x0863a8d4,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x0863aad4,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x086361e0
    graphic [
        src: 0x0863ab14,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x0863ad14,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x086361f4
    graphic [
        src: 0x0863ad54,
        size: 484,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ]
    palette [
        src: 0x0863af38,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08636208
    graphic [
        src: 0x0863af78,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x0863b178,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x0863621c
    graphic [
        src: 0x0863b1b8,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x0863b3b8,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08636230
    graphic [
        src: 0x0863b3f8,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x0863b5f8,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08636244
    graphic [
        src: 0x0863b638,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x0863b838,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x08636258
    graphic [
        src: 0x0863b878,
        size: 512,
        ofs: 863,
        chunk_size: 32,
        props: BPP4
    ] 
    palette [
        src: 0x0863ba78,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    @ 0x0863626c
    graphic [
        src: 0x0863bab8,
        size: 460,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ]
    palette [
        src: 0x0863bc84,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

ElfTypeGraphics: @ 0x08636280
    @ Nurse, 0x08636280
    graphic [
        src: 0x0863bcc4,
        size: 412,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ]
    palette [
        src: 0x0863be60,
        length: 16,
        lz77: 0,
        dst: 0xB
    ]
    @ Animal, 0x08636294
    graphic [
        src: 0x0863be80,
        size: 368,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ]
    palette [
        src: 0x0863bff0,
        length: 16,
        lz77: 0,
        dst: 0xB
    ]
    @ Hacker, 0x086362a8
    graphic [
        src: 0x0863c010,
        size: 236,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ]
    palette [
        src: 0x0863c0fc,
        length: 16,
        lz77: 0,
        dst: 0xB
    ]

ElfNurseDMugshotGraphics: @ 0x086362bc
    @ 0x086362bc
    graphic [
        src: 0x0863c11c,
        size: 492,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ]
    palette [
        src: 0x0863c308,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]
    @ 0x086362d0
    graphic [
        src: 0x0863c348,
        size: 496,
        ofs: 863,
        chunk_size: 32,
        props: (LZ77 | BPP4)
    ]
    palette [
        src: 0x0863c538,
        length: 32,
        lz77: 0,
        dst: 0xB
    ]

    .include "data/gfx/elf/mugshot/martina/martina.s"
    .include "data/gfx/elf/mugshot/nurse_a/nurse_a.s"
    .include "data/gfx/elf/mugshot/nurse_b/nurse_b.s"
    .incbin  "data/gfx/elf/mugshot/nurse_c/nurse_c.bin"
    .incbin  "data/gfx/elf/mugshot/nurse_e/nurse_e.bin"
    .include "data/gfx/elf/mugshot/slime/slime.s"
    .include "data/gfx/elf/mugshot/cheetah/cheetah.s"
    .include "data/gfx/elf/mugshot/monkey/monkey.s"
    .include "data/gfx/elf/mugshot/frog/frog.s"
    .include "data/gfx/elf/mugshot/cow/cow.s"
    .incbin  "data/gfx/elf/mugshot/bird/bird.bin"
    .incbin  "data/gfx/elf/mugshot/sea_otter/sea_otter.bin"
    .incbin  "data/gfx/elf/mugshot/bee/bee.bin"
    .incbin  "data/gfx/elf/mugshot/archix/archix.bin"
    .include "data/gfx/elf/mugshot/byse/byse.s"
    .incbin  "data/gfx/elf/mugshot/dylphina/dylphina.bin"
    .include "data/gfx/elf/mugshot/ninja/ninja.s"
    .incbin  "data/gfx/elf/mugshot/miko/miko.bin"
    .incbin  "data/gfx/elf/mugshot/clock/clock.bin"
    .incbin  "data/gfx/elf/mugshot/metall/metall.bin"
    .include "data/gfx/elf/mugshot/armor/armor.s"
    .incbin  "data/gfx/elf/mugshot/time/time.bin"
    .include "data/gfx/elf/mugshot/giant/giant.s"
    .incbin  "data/gfx/elf/mugshot/whistle/whistle.bin"

    .incbin  "data/gfx/elf/type/nurse/nurse.bin"
    .incbin  "data/gfx/elf/type/animal/animal.bin"
    .incbin  "data/gfx/elf/type/hacker/hacker.bin"

    .include "data/gfx/elf/mugshot/nurse_d/nurse_d.s"
