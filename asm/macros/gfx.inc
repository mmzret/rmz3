    .ifndef GUARD_MACROS_GFX_INC
    .set GUARD_MACROS_GFX_INC, 1

    .set GFX_INC_IDX, 0

    .macro graphic_start
        .set GFX_INC_IDX, 0
    .endm

    .macro graphic src:req, size:req, ofs:req, chunk_size:req, props:req
        .4byte \src + (20*GFX_INC_IDX) - .
        .2byte \size
        .2byte \ofs << 6
        .2byte \chunk_size
        .2byte \props
        .set GFX_INC_IDX, GFX_INC_IDX+1
    .endm

    .macro graphic_raw src:req, size:req, ofs:req, chunk_size:req, props:req
        .4byte \src
        .2byte \size
        .2byte \ofs << 6
        .2byte \chunk_size
        .2byte \props
    .endm

    .macro palette src:req, length:req, lz77:req, dst:req
        .4byte \src + (20*(GFX_INC_IDX-1)) + 12 - .
        .2byte \length << 1
        .byte \lz77
        .byte \dst
    .endm

    .macro palette_raw src:req, length:req, lz77:req, dst:req
        .4byte \src
        .2byte \length << 1
        .byte \lz77
        .byte \dst
    .endm

    .macro mugshot src:req, size:req, pal:req
        graphic [
            src: \src,
            size: \size,
            ofs: 0x0,
            chunk_size: 48,
            props: (LZ77 | BPP4)
        ]
        palette [
            src: \pal,
            length: 16,
            lz77: 0,
            dst: 0
        ]
    .endm

    .macro msgbox src:req, size:req, pal:req
        graphic [
            src: \src,
            size: \size,
            ofs: 0x0,
            chunk_size: 0x100,
            props: (LZ77 | BPP4)
        ]
        palette [
            src: \pal,
            length: 16,
            lz77: 0,
            dst: 0
        ]
    .endm

    .endif // GUARD_MACROS_ENUM_INC
