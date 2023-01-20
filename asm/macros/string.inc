    .ifndef GUARD_MACROS_STRING_INC
    .set GUARD_MACROS_STRING_INC, 1

    .macro z3str s:req
        .string "\s"
        .byte 0xFF
    .endm

    .macro mission_abstraction area:req, boss:req, mission:req
        .string "エリア  :"
        .string "\area"
        .string "\n"
        .string "ボス   :"
        .string "\boss"
        .string "\n"
        .string "ミッション:"
        .string "\mission"
        .byte 0xFF
    .endm

    .macro z3blue s:req
        .byte 0xF7, 0x00
        .string "\s"
        .byte 0xFF
        .byte 0xF7, 0x01
        .string "\s"
        .byte 0xFF
    .endm

    .macro z3blues s:req
        .byte 0x00, 0xF7, 0x00
        .string "\s"
        .byte 0xFF
        .byte 0x00, 0xF7, 0x01
        .string "\s"
        .byte 0xFF
    .endm

    .macro disk_number_xxn s:req
        .string "<RED>"
        .string "\s"
        z3str "0</RED>"
        .string "<RED>"
        .string "\s"
        z3str "1</RED>"
        .string "<RED>"
        .string "\s"
        z3str "2</RED>"
        .string "<RED>"
        .string "\s"
        z3str "3</RED>"
        .string "<RED>"
        .string "\s"
        z3str "4</RED>"
        .string "<RED>"
        .string "\s"
        z3str "5</RED>"
        .string "<RED>"
        .string "\s"
        z3str "6</RED>"
        .string "<RED>"
        .string "\s"
        z3str "7</RED>"
        .string "<RED>"
        .string "\s"
        z3str "8</RED>"
        .string "<RED>"
        .string "\s"
        z3str "9</RED>"
    .endm

    .endif
