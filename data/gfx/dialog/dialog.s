    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata

    graphic_start

MsgBox0Graphic: @ 0x085a7ec4
    msgbox [
        src: 0x085a83ec,
        size: 156,
        pal: 0x085a8488
    ]

NullGraphic_085a7ed8: @ 0x085a7ed8
    graphic 0x085a84a8, 0, 0, 0, LZ77
    palette 0x085a84a8, 0, 0, 0

ZeroMugshotGraphic: @ 0x085a7eec
    mugshot [
        src: 0x085a84a8,
        size: 868,
        pal: 0x085a880c
    ]

BlazinMugshotGraphic: @ 0x085a7f00
    mugshot [
        src: 0x085a882c,
        size: 868,
        pal: 0x085a8b90
    ]

ChildreMugshotGraphic: @ 0x085a7f14
    mugshot [
        src: 0x085a8bb0,
        size: 904,
        pal: 0x085a8f38
    ]

HellbatMugshotGraphic: @ 0x085a7f28
    mugshot [
        src: 0x085a8f58,
        size: 936,
        pal: 0x085a9300
    ]

DeathtanzMugshotGraphic: @ 0x085a7f3c
    mugshot [
        src: 0x085a9320,
        size: 760,
        pal: 0x085a9618
    ]

CubitMugshotGraphic: @ 0x085a7f50
    mugshot [
        src: 0x085a9638,
        size: 988,
        pal: 0x085a9a14
    ]

GlacierleMugshotGraphic: @ 0x085a7f64
    mugshot [
        src: 0x085a9a34,
        size: 756,
        pal: 0x085a9d28
    ]

VolteelMugshotGraphic: @ 0x085a7f78
    mugshot [
        src: 0x085a9d48,
        size: 808,
        pal: 0x085aa070
    ]

TretistaMugshotGraphic: @ 0x085a7f8c
    mugshot [
        src: 0x085aa090,
        size: 876,
        pal: 0x085aa3fc
    ]

BlazinHumanMugshotGraphic: @ 0x085a7fa0
    mugshot [
        src: 0x085aa41c,
        size: 1096,
        pal: 0x085aa864
    ]

ChildreHumanMugshotGraphic: @ 0x085a7fb4
    mugshot [
        src: 0x085aa884,
        size: 960,
        pal: 0x085aac44
    ]

HellbatHumanMugshotGraphic: @ 0x085a7fc8
    mugshot [
        src: 0x085aac64,
        size: 872,
        pal: 0x085aafcc
    ]

DeathtanzHumanMugshotGraphic: @ 0x085a7fdc
    mugshot [
        src: 0x085aafec,
        size: 940,
        pal: 0x085ab398
    ]

CubitHumanMugshotGraphic: @ 0x085a7ff0
    mugshot [
        src: 0x085ab3b8,
        size: 1120,
        pal: 0x085ab818
    ]

GlacierleHumanMugshotGraphic: @ 0x085a8004
    mugshot [
        src: 0x085ab838,
        size: 1020,
        pal: 0x085abc34
    ]

VolteelHumanMugshotGraphic: @ 0x085a8018
    mugshot [
        src: 0x085abc54,
        size: 1144,
        pal: 0x085ac0cc
    ]

TretistaHumanMugshotGraphic: @ 0x085a802c
    mugshot [
        src: 0x085ac0ec,
        size: 896,
        pal: 0x085ac46c
    ]

AnubisMugshotGraphic: @ 0x085a8040
    mugshot [
        src: 0x085ac48c,
        size: 896,
        pal: 0x085ac80c
    ]

HanumachineMugshotGraphic: @ 0x085a8054
    mugshot [
        src: 0x085ac82c,
        size: 956,
        pal: 0x085acbe8
    ]

BlizzackMugshotGraphic: @ 0x085a8068
    mugshot [
        src: 0x085acc08,
        size: 960,
        pal: 0x085acfc8
    ]

HarpuiaMugshotGraphic: @ 0x085a807c
    mugshot [
        src: 0x085acfe8,
        size: 940,
        pal: 0x085ad394
    ]

LeviathanMugshotGraphic: @ 0x085a8090
    mugshot [
        src: 0x085ad3b4,
        size: 952,
        pal: 0x085ad76c
    ]

FefnirMugshotGraphic: @ 0x085a80a4
    mugshot [
        src: 0x085ad78c,
        size: 1040,
        pal: 0x085adb9c
    ]

PhantomMugshotGraphic: @ 0x085a80b8
    mugshot [
        src: 0x085adbbc,
        size: 968,
        pal: 0x085adf84
    ]

OriginalXMugshotGraphics: @ 0x085a80cc
    mugshot [
        src: 0x085adfa4,
        size: 748,
        pal: 0x085ae290
    ]

CopyXMugshotGraphics: @ 0x085a80e0
    mugshot [
        src: 0x085ae2b0,
        size: 900,
        pal: 0x085ae634
    ]

MotherElfMugshotGraphics: @ 0x085a80f4
    mugshot [
        src: 0x085ae654,
        size: 1136,
        pal: 0x085aeac4
    ]

WeilMugshotGraphics: @ 0x085a8108
    mugshot [
        src: 0x085aeae4,
        size: 1164,
        pal: 0x085aef70
    ]

OmegaWhiteMugshotGraphics: @ 0x085a811c
    mugshot [
        src: 0x085aef90,
        size: 1008,
        pal: 0x085af380
    ]

OmegaGoldMugshotGraphics: @ 0x085a8130
    mugshot [
        src: 0x085af3a0,
        size: 912,
        pal: 0x085af730
    ]

CielMugshotGraphics: @ 0x085a8144
    mugshot [
        src: 0x085af750,
        size: 936,
        pal: 0x085afaf8
    ]

CerveauMugshotGraphics: @ 0x085a8158
    mugshot [
        src: 0x085afb18,
        size: 936,
        pal: 0x085afec0
    ]

AlouetteMugshotGraphics: @ 0x085a816c
    mugshot [
        src: 0x085afee0,
        size: 836,
        pal: 0x085b0224
    ]

AndrewMugshotGraphics: @ 0x085a8180
    mugshot [
        src: 0x085b0244,
        size: 1056,
        pal: 0x085b0664
    ]

HibouMugshotGraphics: @ 0x085a8194
    mugshot [
        src: 0x085b0684,
        size: 944,
        pal: 0x085b0a34
    ]

RocinolleMugshotGraphics: @ 0x085a81a8
    mugshot [
        src: 0x085b0a54,
        size: 876,
        pal: 0x085b0dc0
    ]

PerroquietMugshotGraphics: @ 0x085a81bc
    mugshot [
        src: 0x085b0de0,
        size: 912,
        pal: 0x085b1170
    ]

MenartMugshotGraphics: @ 0x085a81d0
    mugshot [
        src: 0x085b1190,
        size: 772,
        pal: 0x085b1494
    ]

DoigtMugshotGraphics: @ 0x085a81e4
    mugshot [
        src: 0x085b14b4,
        size: 1024,
        pal: 0x085b18b4
    ]

WeilMonitorMugshotGraphics: @ 0x085a81f8
    mugshot [
        src: 0x085b18d4,
        size: 1112,
        pal: 0x085b1d2c
    ]

AutrucheMugshotGraphics: @ 0x085a820c
    mugshot [
        src: 0x085b1d4c,
        size: 900,
        pal: 0x085b20d0
    ]

PicMugshotGraphics: @ 0x085a8220
    mugshot [
        src: 0x085b20f0,
        size: 796,
        pal: 0x085b240c
    ]

HirondelleMugshotGraphics: @ 0x085a8234
    mugshot [
        src: 0x085b242c,
        size: 772,
        pal: 0x085b2730
    ]

FauconMugshotGraphics: @ 0x085a8248
    mugshot [
        src: 0x085b2750,
        size: 856,
        pal: 0x085b2aa8
    ]

KissMugshotGraphics: @ 0x085a825c
    mugshot [
        src: 0x085b2ac8,
        size: 848,
        pal: 0x085b2e18
    ]

BrainMugshotGraphics: @ 0x085a8270
    mugshot [
        src: 0x085b2e38,
        size: 884,
        pal: 0x085b31ac
    ]

JoanMugshotGraphics: @ 0x085a8284
    mugshot [
        src: 0x085b31cc,
        size: 952,
        pal: 0x085b3584
    ]

RougeMugshotGraphics: @ 0x085a8298
    mugshot [
        src: 0x085b35a4,
        size: 800,
        pal: 0x085b38c4
    ]

SoundOnlyMugshotGraphics: @ 0x085a82ac
    mugshot [
        src: 0x085b38e4,
        size: 564,
        pal: 0x085b3b18
    ]

CreaMugshotGraphics: @ 0x085a82c0
    mugshot [
        src: 0x085b3b38,
        size: 1112,
        pal: 0x085b3f90
    ]

PreaMugshotGraphics: @ 0x085a82d4
    mugshot [
        src: 0x085b3fb0,
        size: 1136,
        pal: 0x085b4420
    ]

SoundOnly2MugshotGraphics: @ 0x085a82e8
    mugshot [
        src: 0x085b4440,
        size: 648,
        pal: 0x085b46c8
    ]

ColborMugshotGraphics: @ 0x085a82fc
    mugshot [
        src: 0x085b46e8,
        size: 820,
        pal: 0x085b4a1c
    ]

ArmorCopyXMugshotGraphics: @ 0x085a8310
    mugshot [
        src: 0x085b4a3c,
        size: 860,
        pal: 0x085b4d98
    ]

BlurredCielMugshotGraphics: @ 0x085a8324
    mugshot [
        src: 0x085b4db8,
        size: 920,
        pal: 0x085b5150
    ]

OmegaZeroMugshotGraphics: @ 0x085a8338
    mugshot [
        src: 0x085b5170,
        size: 868,
        pal: 0x085b54d4
    ]

MsgBox1Graphics: @ 0x085a834c
    msgbox [
        src: 0x085b54f4,
        size: 148,
        pal: 0x085b5588
    ]

MsgBox2Graphics: @ 0x085a8360
    msgbox [
        src: 0x085b55a8,
        size: 204,
        pal: 0x085b5674
    ]

MsgBox3Graphics: @ 0x085a8374
    msgbox [
        src: 0x085b5694,
        size: 216,
        pal: 0x085b576c
    ]

MsgBox4Graphics: @ 0x085a8388
    msgbox [
        src: 0x085b578c,
        size: 228,
        pal: 0x085b5870
    ]

MsgBox5Graphics: @ 0x085a839c
    msgbox [
        src: 0x085b5890,
        size: 244,
        pal: 0x085b5984
    ]

MsgBox6Graphics: @ 0x085a83b0
    msgbox [
        src: 0x085b59a4,
        size: 268,
        pal: 0x085b5ab0
    ]

MsgBox7Graphics: @ 0x085a83c4
    msgbox [
        src: 0x085b5ad0,
        size: 228,
        pal: 0x085b5bb4
    ]

MsgBox8Graphics: @ 0x085a83d8
    msgbox [
        src: 0x085b5bd4,
        size: 220,
        pal: 0x085b5cb0
    ]

MsgBox0: @ 0x085a83ec
    .incbin "data/gfx/dialog/msgbox/0.bin"

Mugshots: @ 0x085a84a8
    .incbin "data/gfx/dialog/mugshot/zero/zero.bin"
    .incbin "data/gfx/dialog/mugshot/blazin/blazin.bin"
    .incbin "data/gfx/dialog/mugshot/childre/childre.bin"
    .incbin "data/gfx/dialog/mugshot/hellbat/hellbat.bin"
    .incbin "data/gfx/dialog/mugshot/deathtanz/deathtanz.bin"
    .incbin "data/gfx/dialog/mugshot/cubit/cubit.bin"
    .incbin "data/gfx/dialog/mugshot/glacierle/glacierle.bin"
    .incbin "data/gfx/dialog/mugshot/volteel/volteel.bin"
    .incbin "data/gfx/dialog/mugshot/tretista/tretista.bin"
    .incbin "data/gfx/dialog/mugshot/blazin_human/blazin_human.bin"
    .incbin "data/gfx/dialog/mugshot/childre_human/childre_human.bin"
    .incbin "data/gfx/dialog/mugshot/hellbat_human/hellbat_human.bin"
    .incbin "data/gfx/dialog/mugshot/deathtanz_human/deathtanz_human.bin"
    .incbin "data/gfx/dialog/mugshot/cubit_human/cubit_human.bin"
    .incbin "data/gfx/dialog/mugshot/glacierle_human/glacierle_human.bin"
    .incbin "data/gfx/dialog/mugshot/volteel_human/volteel_human.bin"
    .incbin "data/gfx/dialog/mugshot/tretista_human/tretista_human.bin"
    .incbin "data/gfx/dialog/mugshot/anubis/anubis.bin"
    .incbin "data/gfx/dialog/mugshot/hanumachine/hanumachine.bin"
    .incbin "data/gfx/dialog/mugshot/blizzack/blizzack.bin"
    .incbin "data/gfx/dialog/mugshot/harpuia/harpuia.bin"
    .incbin "data/gfx/dialog/mugshot/leviathan/leviathan.bin"
    .incbin "data/gfx/dialog/mugshot/fefnir/fefnir.bin"
    .incbin "data/gfx/dialog/mugshot/phantom/phantom.bin"
    .incbin "data/gfx/dialog/mugshot/x/x.bin"
    .incbin "data/gfx/dialog/mugshot/copy_x/copy_x.bin"
    .incbin "data/gfx/dialog/mugshot/mother_elf/mother_elf.bin"
    .incbin "data/gfx/dialog/mugshot/weil/weil.bin"
    .incbin "data/gfx/dialog/mugshot/omega_white/omega_white.bin"
    .incbin "data/gfx/dialog/mugshot/omega_gold/omega_gold.bin"
    .incbin "data/gfx/dialog/mugshot/ciel/ciel.bin"
    .incbin "data/gfx/dialog/mugshot/cerveau/cerveau.bin"
    .incbin "data/gfx/dialog/mugshot/alouette/alouette.bin"
    .incbin "data/gfx/dialog/mugshot/andrew/andrew.bin"
    .incbin "data/gfx/dialog/mugshot/hibou/hibou.bin"
    .incbin "data/gfx/dialog/mugshot/rocinolle/rocinolle.bin"
    .incbin "data/gfx/dialog/mugshot/perroquiet/perroquiet.bin"
    .incbin "data/gfx/dialog/mugshot/menart/menart.bin"
    .incbin "data/gfx/dialog/mugshot/doigt/doigt.bin"
    .incbin "data/gfx/dialog/mugshot/weil_monitor/weil_monitor.bin"
    .incbin "data/gfx/dialog/mugshot/autruche/autruche.bin"
    .incbin "data/gfx/dialog/mugshot/pic/pic.bin"
    .incbin "data/gfx/dialog/mugshot/hirondelle/hirondelle.bin"
    .incbin "data/gfx/dialog/mugshot/faucon/faucon.bin"
    .incbin "data/gfx/dialog/mugshot/kiss/kiss.bin"
    .incbin "data/gfx/dialog/mugshot/brain/brain.bin"
    .incbin "data/gfx/dialog/mugshot/joan/joan.bin"
    .incbin "data/gfx/dialog/mugshot/rouge/rouge.bin"
    .incbin "data/gfx/dialog/mugshot/sound_only/sound_only.bin"
    .incbin "data/gfx/dialog/mugshot/crea/crea.bin"
    .incbin "data/gfx/dialog/mugshot/prea/prea.bin"
    .incbin "data/gfx/dialog/mugshot/sound_only2/sound_only2.bin"
    .incbin "data/gfx/dialog/mugshot/colbor/colbor.bin"
    .incbin "data/gfx/dialog/mugshot/copy_x_armor/copy_x_armor.bin"
    .incbin "data/gfx/dialog/mugshot/ciel_blur/ciel_blur.bin"
    .incbin "data/gfx/dialog/mugshot/omega_zero/omega_zero.bin"

MsgBox1: @ 0x085b54f4
    .incbin "data/gfx/dialog/msgbox/1.bin"

MsgBox2: @ 0x085b55a8
    .incbin "data/gfx/dialog/msgbox/2.bin"

MsgBox3: @ 0x085b5694
    .incbin "data/gfx/dialog/msgbox/3.bin"

MsgBox4: @ 0x085b578c
    .incbin "data/gfx/dialog/msgbox/4.bin"

MsgBox5: @ 0x085b5890
    .incbin "data/gfx/dialog/msgbox/5.bin"

MsgBox6: @ 0x085b59a4
    .incbin "data/gfx/dialog/msgbox/6.bin"

MsgBox7: @ 0x085b5ad0
    .incbin "data/gfx/dialog/msgbox/7.bin"

MsgBox8: @ 0x085b5bd4
    .incbin "data/gfx/dialog/msgbox/8.bin"
