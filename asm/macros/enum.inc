    .ifndef GUARD_MACROS_ENUM_INC
    .set GUARD_MACROS_ENUM_INC, 1

    .set __enum_inc_amount, 1
    .set __subenum_inc_amount, 1

    .macro enum_start x=0, inc_amount=1
        .set __enum__, \x
        .set __enum_inc_amount, \inc_amount
    .endm

    .macro enum constant:req
        .equiv \constant, __enum__
        enum_inc __enum__
    .endm

    .macro enum_inc x:req
        .set \x, \x + __enum_inc_amount
    .endm

    .endif // GUARD_MACROS_ENUM_INC
