    .ifndef GUARD_MACROS_LABEL_INC
    .set GUARD_MACROS_LABEL_INC, 1

    .macro ds name
        .global \name
        \name\():
    .endm

    .endif
