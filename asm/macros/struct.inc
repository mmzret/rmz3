    .ifndef GUARD_MACROS_STRUCT_INC
    .set GUARD_MACROS_STRUCT_INC, 1

    .macro tilemap_header w:req, h:req
        .4byte 0x10001
        .2byte \w
        .2byte \h
    .endm

    .endif
