    .include "asm/macros.inc"
     

    .balign 4
    .section .rodata

.global gBlinkCmd_000
gBlinkCmd_000:
  .4byte .+4
  .byte 0, 10
  .byte 1, 5
  .byte 2, 5
  .byte 3, 3
  .byte 4, 3
  .byte 5, 10
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_001
gBlinkCmd_001:
  .4byte .+4
  .byte 0, 10
  .byte 1, 5
  .byte 2, 5
  .byte 3, 3
  .byte 4, 3
  .byte 5, 10
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_002
gBlinkCmd_002:
  .4byte .+4
  .byte 0, 10
  .byte 1, 5
  .byte 2, 5
  .byte 3, 3
  .byte 4, 3
  .byte 5, 10
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_003
gBlinkCmd_003:
  .4byte .+4
  .byte 0, 10
  .byte 0, 254

.global gBlinkCmd_Menu
gBlinkCmd_Menu:
  .4byte .+4
  .byte 0, 30
  .byte 1, 10
  .byte 2, 10
  .byte 3, 10
  .byte 4, 30
  .byte 3, 10
  .byte 2, 10
  .byte 1, 10
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_005
gBlinkCmd_005:
  .4byte .+4
  .byte 0, 75
  .byte 1, 9
  .byte 2, 9
  .byte 3, 9
  .byte 4, 9
  .byte 5, 9
  .byte 6, 9
  .byte 7, 9
  .byte 8, 80
  .byte 7, 9
  .byte 6, 9
  .byte 5, 9
  .byte 4, 9
  .byte 3, 9
  .byte 2, 9
  .byte 1, 9
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_006
gBlinkCmd_006:
  .4byte .+4
  .byte 0, 54
  .byte 1, 6
  .byte 2, 9
  .byte 3, 15
  .byte 4, 30
  .byte 3, 15
  .byte 2, 9
  .byte 1, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_007
gBlinkCmd_007:
  .4byte .+4
  .byte 0, 80
  .byte 1, 9
  .byte 2, 9
  .byte 3, 9
  .byte 4, 9
  .byte 5, 9
  .byte 6, 9
  .byte 7, 9
  .byte 8, 80
  .byte 7, 9
  .byte 6, 9
  .byte 5, 9
  .byte 4, 9
  .byte 3, 9
  .byte 2, 9
  .byte 1, 9
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_008
gBlinkCmd_008:
  .4byte .+4
  .byte 0, 9
  .byte 1, 9
  .byte 2, 9
  .byte 3, 9
  .byte 4, 9
  .byte 5, 9
  .byte 6, 9
  .byte 7, 9
  .byte 8, 80
  .byte 9, 9
  .byte 10, 9
  .byte 11, 9
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_009
gBlinkCmd_009:
  .4byte .+4
  .byte 0, 45
  .byte 1, 12
  .byte 2, 12
  .byte 3, 12
  .byte 4, 12
  .byte 5, 12
  .byte 6, 12
  .byte 7, 12
  .byte 8, 75
  .byte 7, 12
  .byte 6, 12
  .byte 5, 12
  .byte 4, 12
  .byte 3, 12
  .byte 2, 12
  .byte 1, 12
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_010
gBlinkCmd_010:
  .4byte .+4
  .byte 0, 60
  .byte 1, 12
  .byte 2, 12
  .byte 3, 12
  .byte 4, 12
  .byte 5, 75
  .byte 4, 12
  .byte 3, 12
  .byte 2, 12
  .byte 1, 12
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_011
gBlinkCmd_011:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 2
  .byte 5, 2
  .byte 6, 2
  .byte 7, 2
  .byte 8, 2
  .byte 9, 2
  .byte 10, 2
  .byte 11, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_012
gBlinkCmd_012:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_013
gBlinkCmd_013:
  .4byte .+4
  .byte 5, 3
  .byte 4, 3
  .byte 3, 3
  .byte 2, 3
  .byte 1, 3
  .byte 0, 3
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_014
gBlinkCmd_014:
  .4byte .+4
  .byte 0, 10
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 0, 255

.global gBlinkCmd_015
gBlinkCmd_015:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 6, 3
  .byte 7, 3
  .byte 8, 3
  .byte 9, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_016
gBlinkCmd_016:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 0, 255

.global gBlinkCmd_017
gBlinkCmd_017:
  .4byte .+4
  .byte 4, 10
  .byte 3, 3
  .byte 2, 3
  .byte 1, 3
  .byte 0, 3
  .byte 0, 255

.global gBlinkCmd_018
gBlinkCmd_018:
  .4byte .+4
  .byte 4, 3
  .byte 3, 3
  .byte 2, 3
  .byte 1, 3
  .byte 0, 10
  .byte 0, 255

.global gBlinkCmd_019
gBlinkCmd_019:
  .4byte .+4
  .byte 0, 10
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 0, 255

.global gBlinkCmd_020
gBlinkCmd_020:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 6, 3
  .byte 7, 3
  .byte 8, 3
  .byte 9, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_021
gBlinkCmd_021:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 0, 255

.global gBlinkCmd_022
gBlinkCmd_022:
  .4byte .+4
  .byte 4, 10
  .byte 3, 3
  .byte 2, 3
  .byte 1, 3
  .byte 0, 3
  .byte 0, 255

.global gBlinkCmd_023
gBlinkCmd_023:
  .4byte .+4
  .byte 4, 3
  .byte 3, 3
  .byte 2, 3
  .byte 1, 3
  .byte 0, 10
  .byte 0, 255

.global gBlinkCmd_024
gBlinkCmd_024:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 2
  .byte 5, 2
  .byte 4, 2
  .byte 5, 2
  .byte 6, 2
  .byte 7, 2
  .byte 8, 2
  .byte 9, 2
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_025
gBlinkCmd_025:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_026
gBlinkCmd_026:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 2
  .byte 5, 2
  .byte 6, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 254

.global gBlinkCmd_027
gBlinkCmd_027:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_028
gBlinkCmd_028:
  .4byte .+4
  .byte 3, 4
  .byte 2, 4
  .byte 1, 4
  .byte 0, 4
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_029
gBlinkCmd_029:
  .4byte .+4
  .byte 0, 10
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_030
gBlinkCmd_030:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 6, 3
  .byte 7, 3
  .byte 8, 3
  .byte 9, 3
  .byte 10, 3
  .byte 11, 3
  .byte 12, 3
  .byte 13, 3
  .byte 14, 3
  .byte 15, 3
  .byte 16, 3
  .byte 17, 3
  .byte 18, 3
  .byte 19, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_031
gBlinkCmd_031:
  .4byte .+4
  .byte 4, 3
  .byte 3, 3
  .byte 2, 3
  .byte 1, 3
  .byte 0, 3
  .byte 0, 255

.global gBlinkCmd_032
gBlinkCmd_032:
  .4byte .+4
  .byte 0, 1
  .byte 1, 1
  .byte 2, 1
  .byte 3, 1
  .byte 4, 1
  .byte 5, 1
  .byte 6, 1
  .byte 7, 1
  .byte 8, 1
  .byte 9, 1
  .byte 10, 1
  .byte 11, 1
  .byte 12, 1
  .byte 13, 1
  .byte 14, 1
  .byte 15, 1
  .byte 16, 1
  .byte 17, 1
  .byte 18, 1
  .byte 19, 1
  .byte 20, 30
  .byte 21, 6
  .byte 22, 6
  .byte 23, 3
  .byte 24, 3
  .byte 23, 3
  .byte 22, 3
  .byte 21, 6
  .byte 20, 8
  .byte 21, 6
  .byte 22, 3
  .byte 23, 3
  .byte 24, 3
  .byte 23, 3
  .byte 22, 3
  .byte 21, 6
  .byte 20, 8
  .byte 21, 6
  .byte 22, 3
  .byte 23, 3
  .byte 24, 3
  .byte 23, 3
  .byte 22, 3
  .byte 21, 6
  .byte 20, 20
  .byte 25, 2
  .byte 26, 2
  .byte 27, 2
  .byte 28, 7
  .byte 29, 2
  .byte 30, 2
  .byte 31, 2
  .byte 32, 7
  .byte 33, 2
  .byte 34, 2
  .byte 35, 2
  .byte 36, 7
  .byte 37, 2
  .byte 38, 2
  .byte 39, 2
  .byte 40, 7
  .byte 41, 2
  .byte 42, 2
  .byte 43, 2
  .byte 0, 50
  .byte 0, 254

.global gBlinkCmd_033
gBlinkCmd_033:
  .4byte .+4
  .byte 0, 1
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 6, 3
  .byte 7, 3
  .byte 8, 3
  .byte 9, 3
  .byte 10, 3
  .byte 11, 3
  .byte 12, 2
  .byte 13, 2
  .byte 14, 2
  .byte 15, 2
  .byte 17, 2
  .byte 18, 2
  .byte 19, 32
  .byte 20, 2
  .byte 21, 2
  .byte 22, 2
  .byte 23, 2
  .byte 24, 2
  .byte 25, 2
  .byte 26, 2
  .byte 27, 6
  .byte 26, 2
  .byte 25, 2
  .byte 24, 2
  .byte 23, 2
  .byte 22, 1
  .byte 21, 1
  .byte 20, 1
  .byte 19, 8
  .byte 20, 2
  .byte 21, 2
  .byte 22, 2
  .byte 23, 2
  .byte 24, 2
  .byte 25, 2
  .byte 26, 2
  .byte 27, 6
  .byte 26, 2
  .byte 25, 2
  .byte 24, 2
  .byte 23, 2
  .byte 22, 1
  .byte 21, 1
  .byte 20, 1
  .byte 19, 32
  .byte 20, 5
  .byte 21, 5
  .byte 22, 5
  .byte 23, 5
  .byte 24, 5
  .byte 25, 5
  .byte 26, 5
  .byte 27, 32
  .byte 28, 3
  .byte 29, 3
  .byte 30, 2
  .byte 31, 20
  .byte 32, 3
  .byte 33, 3
  .byte 34, 3
  .byte 35, 20
  .byte 36, 3
  .byte 37, 3
  .byte 38, 3
  .byte 39, 20
  .byte 40, 3
  .byte 41, 3
  .byte 42, 3
  .byte 43, 50
  .byte 42, 3
  .byte 41, 3
  .byte 40, 3
  .byte 39, 3
  .byte 38, 3
  .byte 37, 3
  .byte 36, 3
  .byte 35, 3
  .byte 34, 3
  .byte 33, 3
  .byte 32, 3
  .byte 31, 20
  .byte 30, 3
  .byte 29, 3
  .byte 28, 20
  .byte 27, 3
  .byte 26, 3
  .byte 25, 3
  .byte 24, 3
  .byte 23, 3
  .byte 22, 3
  .byte 21, 3
  .byte 20, 3
  .byte 19, 32
  .byte 0, 254

.global gBlinkCmd_034
gBlinkCmd_034:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 20
  .byte 3, 12
  .byte 2, 12
  .byte 1, 12
  .byte 0, 12
  .byte 0, 254

.global gBlinkCmd_035
gBlinkCmd_035:
  .4byte .+4
  .byte 0, 10
  .byte 1, 8
  .byte 2, 6
  .byte 3, 3
  .byte 4, 3
  .byte 5, 2
  .byte 6, 15
  .byte 0, 254

.global gBlinkCmd_036
gBlinkCmd_036:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 2, 6
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 2, 6
  .byte 1, 3
  .byte 0, 20
  .byte 3, 6
  .byte 4, 6
  .byte 5, 6
  .byte 6, 6
  .byte 7, 30
  .byte 2, 10
  .byte 1, 10
  .byte 0, 30
  .byte 0, 254

.global gBlinkCmd_037
gBlinkCmd_037:
  .4byte .+4
  .byte 0, 7
  .byte 1, 5
  .byte 2, 3
  .byte 3, 2
  .byte 4, 1
  .byte 5, 25
  .byte 6, 1
  .byte 7, 2
  .byte 8, 3
  .byte 9, 5
  .byte 10, 7
  .byte 0, 254

.global gBlinkCmd_038
gBlinkCmd_038:
  .4byte .+4
  .byte 0, 1
  .byte 1, 2
  .byte 0, 1
  .byte 0, 254

.global gBlinkCmd_039
gBlinkCmd_039:
  .4byte .+4
  .byte 0, 15
  .byte 1, 12
  .byte 2, 8
  .byte 3, 5
  .byte 4, 3
  .byte 3, 5
  .byte 2, 8
  .byte 1, 12
  .byte 0, 15
  .byte 0, 254

.global gBlinkCmd_040
gBlinkCmd_040:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 4, 8
  .byte 5, 8
  .byte 6, 50
  .byte 8, 8
  .byte 9, 8
  .byte 10, 8
  .byte 11, 8
  .byte 12, 8
  .byte 13, 8
  .byte 14, 8
  .byte 15, 8
  .byte 16, 4
  .byte 17, 4
  .byte 18, 4
  .byte 19, 4
  .byte 20, 4
  .byte 21, 50
  .byte 22, 10
  .byte 23, 8
  .byte 24, 6
  .byte 25, 4
  .byte 0, 32
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_041
gBlinkCmd_041:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 4, 8
  .byte 5, 8
  .byte 6, 8
  .byte 7, 8
  .byte 8, 8
  .byte 0, 255

.global gBlinkCmd_042
gBlinkCmd_042:
  .4byte .+4
  .byte 0, 4
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_043
gBlinkCmd_043:
  .4byte .+4
  .byte 0, 60
  .byte 1, 9
  .byte 2, 9
  .byte 3, 9
  .byte 4, 9
  .byte 5, 9
  .byte 4, 9
  .byte 3, 9
  .byte 2, 9
  .byte 1, 9
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_044
gBlinkCmd_044:
  .4byte .+4
  .byte 0, 9
  .byte 1, 9
  .byte 2, 9
  .byte 3, 45
  .byte 4, 9
  .byte 5, 9
  .byte 6, 9
  .byte 7, 9
  .byte 8, 9
  .byte 9, 60
  .byte 10, 9
  .byte 11, 9
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_045
gBlinkCmd_045:
  .4byte .+4
  .byte 0, 6
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 4, 6
  .byte 5, 60
  .byte 6, 6
  .byte 7, 6
  .byte 8, 6
  .byte 9, 6
  .byte 10, 6
  .byte 11, 6
  .byte 12, 6
  .byte 13, 6
  .byte 14, 6
  .byte 15, 45
  .byte 16, 6
  .byte 17, 6
  .byte 18, 6
  .byte 19, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_046
gBlinkCmd_046:
  .4byte .+4
  .byte 0, 60
  .byte 1, 9
  .byte 2, 9
  .byte 3, 9
  .byte 4, 9
  .byte 5, 27
  .byte 4, 9
  .byte 3, 9
  .byte 2, 9
  .byte 1, 9
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_047
gBlinkCmd_047:
  .4byte .+4
  .byte 0, 45
  .byte 1, 9
  .byte 2, 9
  .byte 3, 9
  .byte 4, 9
  .byte 5, 21
  .byte 4, 9
  .byte 3, 9
  .byte 2, 9
  .byte 1, 9
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_048
gBlinkCmd_048:
  .4byte .+4
  .byte 0, 6
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 4, 60
  .byte 5, 6
  .byte 6, 6
  .byte 7, 6
  .byte 8, 6
  .byte 9, 6
  .byte 10, 6
  .byte 11, 6
  .byte 12, 45
  .byte 13, 6
  .byte 14, 6
  .byte 15, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_049
gBlinkCmd_049:
  .4byte .+4
  .byte 0, 20
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 4, 6
  .byte 5, 10
  .byte 4, 6
  .byte 3, 6
  .byte 2, 6
  .byte 1, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_050
gBlinkCmd_050:
  .4byte .+4
  .byte 0, 20
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 4, 6
  .byte 5, 10
  .byte 4, 6
  .byte 3, 6
  .byte 2, 6
  .byte 1, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_051
gBlinkCmd_051:
  .4byte .+4
  .byte 0, 20
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 4, 6
  .byte 5, 10
  .byte 4, 6
  .byte 3, 6
  .byte 2, 6
  .byte 1, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_052
gBlinkCmd_052:
  .4byte .+4
  .byte 0, 30
  .byte 1, 6
  .byte 0, 10
  .byte 1, 4
  .byte 0, 20
  .byte 1, 10
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_053
gBlinkCmd_053:
  .4byte .+4
  .byte 0, 20
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 4, 6
  .byte 5, 10
  .byte 4, 6
  .byte 3, 6
  .byte 2, 6
  .byte 1, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_054
gBlinkCmd_054:
  .4byte .+4
  .byte 0, 10
  .byte 1, 10
  .byte 2, 10
  .byte 3, 10
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_055
gBlinkCmd_055:
  .4byte .+4
  .byte 0, 10
  .byte 1, 10
  .byte 2, 10
  .byte 3, 10
  .byte 4, 10
  .byte 5, 10
  .byte 4, 10
  .byte 3, 10
  .byte 2, 10
  .byte 1, 10
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_056
gBlinkCmd_056:
  .4byte .+4
  .byte 0, 10
  .byte 1, 10
  .byte 2, 10
  .byte 3, 10
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_057
gBlinkCmd_057:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 2
  .byte 5, 2
  .byte 4, 2
  .byte 3, 2
  .byte 2, 2
  .byte 1, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_058
gBlinkCmd_058:
  .4byte .+4
  .byte 0, 15
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 4, 6
  .byte 5, 15
  .byte 4, 6
  .byte 3, 6
  .byte 2, 6
  .byte 1, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_059
gBlinkCmd_059:
  .4byte .+4
  .byte 0, 60
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 4, 6
  .byte 5, 60
  .byte 4, 6
  .byte 3, 6
  .byte 2, 6
  .byte 1, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_060
gBlinkCmd_060:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 4, 4
  .byte 3, 4
  .byte 2, 4
  .byte 1, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_061
gBlinkCmd_061:
  .4byte .+4
  .byte 0, 6
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 2, 6
  .byte 1, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_062
gBlinkCmd_062:
  .4byte .+4
  .byte 0, 30
  .byte 1, 10
  .byte 2, 10
  .byte 3, 10
  .byte 4, 30
  .byte 3, 10
  .byte 2, 10
  .byte 1, 10
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_063
gBlinkCmd_063:
  .4byte .+4
  .byte 0, 20
  .byte 1, 4
  .byte 2, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 0, 254

.global gBlinkCmd_064
gBlinkCmd_064:
  .4byte .+4
  .byte 0, 20
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_065
gBlinkCmd_065:
  .4byte .+4
  .byte 0, 20
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_066
gBlinkCmd_066:
  .4byte .+4
  .byte 0, 1
  .byte 0, 254

.global gBlinkCmd_067
gBlinkCmd_067:
  .4byte .+4
  .byte 0, 1
  .byte 0, 254

.global gBlinkCmd_068
gBlinkCmd_068:
  .4byte .+4
  .byte 0, 30
  .byte 1, 10
  .byte 2, 10
  .byte 3, 10
  .byte 4, 30
  .byte 3, 10
  .byte 2, 10
  .byte 1, 10
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_069
gBlinkCmd_069:
  .4byte .+4
  .byte 4, 8
  .byte 3, 4
  .byte 2, 4
  .byte 1, 4
  .byte 0, 8
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_070
gBlinkCmd_070:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 4, 8
  .byte 5, 8
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_071
gBlinkCmd_071:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 4, 8
  .byte 5, 8
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_072
gBlinkCmd_072:
  .4byte .+4
  .byte 0, 6
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_073
gBlinkCmd_073:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_074
gBlinkCmd_074:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 2
  .byte 5, 2
  .byte 6, 2
  .byte 7, 2
  .byte 8, 2
  .byte 9, 2
  .byte 10, 2
  .byte 11, 2
  .byte 12, 2
  .byte 0, 254

.global gBlinkCmd_075
gBlinkCmd_075:
  .4byte .+4
  .byte 3, 4
  .byte 2, 4
  .byte 1, 4
  .byte 0, 4
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_076
gBlinkCmd_076:
  .4byte .+4
  .byte 12, 2
  .byte 11, 2
  .byte 10, 2
  .byte 9, 2
  .byte 8, 2
  .byte 7, 2
  .byte 6, 2
  .byte 5, 2
  .byte 4, 2
  .byte 3, 2
  .byte 2, 2
  .byte 1, 2
  .byte 0, 2
  .byte 0, 254

.global gBlinkCmd_077
gBlinkCmd_077:
  .4byte .+4
  .byte 0, 1
  .byte 1, 1
  .byte 2, 1
  .byte 3, 1
  .byte 4, 1
  .byte 5, 1
  .byte 6, 1
  .byte 7, 1
  .byte 8, 1
  .byte 9, 1
  .byte 10, 1
  .byte 11, 1
  .byte 12, 1
  .byte 13, 1
  .byte 14, 1
  .byte 15, 1
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_078
gBlinkCmd_078:
  .4byte .+4
  .byte 0, 1
  .byte 1, 1
  .byte 2, 1
  .byte 3, 1
  .byte 4, 1
  .byte 5, 1
  .byte 6, 1
  .byte 7, 1
  .byte 8, 1
  .byte 9, 1
  .byte 10, 1
  .byte 11, 1
  .byte 12, 1
  .byte 13, 1
  .byte 14, 1
  .byte 0, 255

.global gBlinkCmd_079
gBlinkCmd_079:
  .4byte .+4
  .byte 0, 10
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 10
  .byte 0, 254

.global gBlinkCmd_080
gBlinkCmd_080:
  .4byte .+4
  .byte 0, 5
  .byte 1, 5
  .byte 2, 5
  .byte 3, 6
  .byte 2, 5
  .byte 1, 5
  .byte 0, 5
  .byte 4, 5
  .byte 5, 5
  .byte 6, 10
  .byte 5, 5
  .byte 4, 5
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_081
gBlinkCmd_081:
  .4byte .+4
  .byte 0, 30
  .byte 1, 10
  .byte 2, 10
  .byte 3, 10
  .byte 4, 30
  .byte 3, 10
  .byte 2, 10
  .byte 1, 10
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_082
gBlinkCmd_082:
  .4byte .+4
  .byte 0, 30
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_083
gBlinkCmd_083:
  .4byte .+4
  .byte 0, 20
  .byte 1, 8
  .byte 2, 8
  .byte 3, 20
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_084
gBlinkCmd_084:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 1, 8
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_085
gBlinkCmd_085:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 8, 4
  .byte 2, 2
  .byte 3, 2
  .byte 8, 2
  .byte 2, 2
  .byte 3, 2
  .byte 8, 4
  .byte 4, 2
  .byte 5, 2
  .byte 6, 2
  .byte 7, 2
  .byte 6, 2
  .byte 7, 2
  .byte 4, 2
  .byte 5, 2
  .byte 8, 4
  .byte 0, 2
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 2
  .byte 5, 2
  .byte 6, 2
  .byte 7, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_086
gBlinkCmd_086:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 8, 3
  .byte 2, 3
  .byte 3, 3
  .byte 8, 4
  .byte 2, 3
  .byte 3, 3
  .byte 8, 3
  .byte 4, 3
  .byte 5, 3
  .byte 6, 3
  .byte 7, 3
  .byte 6, 3
  .byte 7, 3
  .byte 4, 3
  .byte 5, 3
  .byte 8, 8
  .byte 0, 2
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 2
  .byte 5, 2
  .byte 6, 2
  .byte 7, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_087
gBlinkCmd_087:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_088
gBlinkCmd_088:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 2, 254
  .byte 0, 0

.global gBlinkCmd_089
gBlinkCmd_089:
  .4byte .+4
  .byte 2, 3
  .byte 1, 3
  .byte 0, 3
  .byte 0, 255

.global gBlinkCmd_090
gBlinkCmd_090:
  .4byte .+4
  .byte 2, 3
  .byte 1, 3
  .byte 0, 3
  .byte 0, 255

.global gBlinkCmd_091
gBlinkCmd_091:
  .4byte .+4
  .byte 0, 16
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 4, 16
  .byte 0, 254

.global gBlinkCmd_092
gBlinkCmd_092:
  .4byte .+4
  .byte 0, 1
  .byte 0, 254

.global gBlinkCmd_093
gBlinkCmd_093:
  .4byte .+4
  .byte 0, 1
  .byte 0, 254

.global gBlinkCmd_094
gBlinkCmd_094:
  .4byte .+4
  .byte 0, 1
  .byte 0, 254

.global gBlinkCmd_095
gBlinkCmd_095:
  .4byte .+4
  .byte 0, 1
  .byte 0, 254

.global gBlinkCmd_096
gBlinkCmd_096:
  .4byte .+4
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 6, 3
  .byte 7, 3
  .byte 8, 3
  .byte 9, 3
  .byte 10, 3
  .byte 11, 3
  .byte 12, 3
  .byte 13, 3
  .byte 14, 3
  .byte 15, 3
  .byte 16, 3
  .byte 17, 3
  .byte 18, 3
  .byte 0, 1
  .byte 0, 255

.global gBlinkCmd_097
gBlinkCmd_097:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 6, 3
  .byte 7, 3
  .byte 8, 3
  .byte 9, 3
  .byte 10, 3
  .byte 11, 3
  .byte 12, 3
  .byte 13, 3
  .byte 14, 3
  .byte 15, 3
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_098
gBlinkCmd_098:
  .4byte .+4
  .byte 0, 6
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_099
gBlinkCmd_099:
  .4byte .+4
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 6, 3
  .byte 7, 3
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 8, 3
  .byte 6, 3
  .byte 7, 3
  .byte 8, 3
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 6, 3
  .byte 7, 3
  .byte 8, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_100
gBlinkCmd_100:
  .4byte .+4
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_102
gBlinkCmd_102:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_103
gBlinkCmd_103:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_104
gBlinkCmd_104:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_105
gBlinkCmd_105:
  .4byte .+4
  .byte 0, 10
  .byte 1, 10
  .byte 2, 10
  .byte 3, 10
  .byte 4, 10
  .byte 5, 10
  .byte 4, 10
  .byte 3, 10
  .byte 2, 10
  .byte 1, 10
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_106
gBlinkCmd_106:
  .4byte .+4
  .byte 0, 30
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 4, 30
  .byte 3, 8
  .byte 2, 8
  .byte 1, 8
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_107
gBlinkCmd_107:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 2
  .byte 5, 2
  .byte 6, 2
  .byte 7, 2
  .byte 6, 2
  .byte 5, 2
  .byte 4, 2
  .byte 3, 2
  .byte 2, 2
  .byte 1, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_108
gBlinkCmd_108:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_109
gBlinkCmd_109:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_110
gBlinkCmd_110:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_111
gBlinkCmd_111:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 6, 3
  .byte 7, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_112
gBlinkCmd_112:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 8, 4
  .byte 9, 4
  .byte 10, 4
  .byte 11, 4
  .byte 12, 4
  .byte 13, 4
  .byte 14, 4
  .byte 15, 4
  .byte 16, 4
  .byte 17, 24
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_113
gBlinkCmd_113:
  .4byte .+4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_114
gBlinkCmd_114:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 2
  .byte 5, 2
  .byte 6, 2
  .byte 5, 254

.global gBlinkCmd_115
gBlinkCmd_115:
  .4byte .+4
  .byte 0, 30
  .byte 1, 4
  .byte 2, 3
  .byte 3, 2
  .byte 4, 2
  .byte 5, 2
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_116
gBlinkCmd_116:
  .4byte .+4
  .byte 0, 10
  .byte 1, 10
  .byte 2, 10
  .byte 3, 10
  .byte 4, 10
  .byte 5, 10
  .byte 4, 10
  .byte 3, 10
  .byte 2, 10
  .byte 1, 10
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_117
gBlinkCmd_117:
  .4byte .+4
  .byte 0, 10
  .byte 1, 10
  .byte 2, 10
  .byte 3, 10
  .byte 4, 10
  .byte 5, 10
  .byte 4, 10
  .byte 3, 10
  .byte 2, 10
  .byte 1, 10
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_118
gBlinkCmd_118:
  .4byte .+4
  .byte 0, 10
  .byte 1, 10
  .byte 2, 10
  .byte 3, 10
  .byte 4, 10
  .byte 5, 10
  .byte 4, 10
  .byte 3, 10
  .byte 2, 10
  .byte 1, 10
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_119
gBlinkCmd_119:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_120
gBlinkCmd_120:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_121
gBlinkCmd_121:
  .4byte .+4
  .byte 0, 1
  .byte 0, 254

.global gBlinkCmd_122
gBlinkCmd_122:
  .4byte .+4
  .byte 0, 10
  .byte 1, 10
  .byte 2, 10
  .byte 3, 10
  .byte 4, 10
  .byte 5, 10
  .byte 4, 10
  .byte 3, 10
  .byte 2, 10
  .byte 1, 10
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_123
gBlinkCmd_123:
  .4byte .+4
  .byte 0, 1
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 2
  .byte 5, 2
  .byte 6, 2
  .byte 7, 2
  .byte 8, 2
  .byte 9, 2
  .byte 10, 4
  .byte 11, 4
  .byte 12, 4
  .byte 13, 6
  .byte 14, 8
  .byte 15, 1
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_124
gBlinkCmd_124:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 8, 4
  .byte 9, 4
  .byte 10, 4
  .byte 11, 4
  .byte 12, 4
  .byte 13, 4
  .byte 14, 4
  .byte 15, 4
  .byte 16, 4
  .byte 17, 80
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_125
gBlinkCmd_125:
  .4byte .+4
  .byte 0, 24
  .byte 1, 4
  .byte 2, 20
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 8, 80
  .byte 0, 254

.global gBlinkCmd_126
gBlinkCmd_126:
  .4byte .+4
  .byte 0, 20
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 2
  .byte 5, 20
  .byte 4, 2
  .byte 3, 2
  .byte 2, 2
  .byte 1, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_127
gBlinkCmd_127:
  .4byte .+4
  .byte 0, 60
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 2
  .byte 5, 2
  .byte 6, 2
  .byte 7, 60
  .byte 8, 2
  .byte 9, 2
  .byte 10, 2
  .byte 11, 2
  .byte 12, 2
  .byte 13, 2
  .byte 14, 2
  .byte 15, 2
  .byte 16, 2
  .byte 0, 254

.global gBlinkCmd_128
gBlinkCmd_128:
  .4byte .+4
  .byte 7, 3
  .byte 8, 3
  .byte 9, 3
  .byte 10, 3
  .byte 11, 3
  .byte 12, 3
  .byte 13, 3
  .byte 0, 57
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 6, 57
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_129
gBlinkCmd_129:
  .4byte .+4
  .byte 0, 30
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 30
  .byte 5, 4
  .byte 4, 4
  .byte 3, 4
  .byte 2, 4
  .byte 1, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_130
gBlinkCmd_130:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 0, 254

.global gBlinkCmd_131
gBlinkCmd_131:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 0, 254

.global gBlinkCmd_132
gBlinkCmd_132:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 0, 254

.global gBlinkCmd_133
gBlinkCmd_133:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 4, 8
  .byte 5, 8
  .byte 6, 8
  .byte 7, 8
  .byte 6, 8
  .byte 5, 8
  .byte 4, 8
  .byte 3, 8
  .byte 2, 8
  .byte 1, 8
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_134
gBlinkCmd_134:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 4, 8
  .byte 5, 8
  .byte 6, 8
  .byte 7, 8
  .byte 6, 8
  .byte 5, 8
  .byte 4, 8
  .byte 3, 8
  .byte 2, 8
  .byte 1, 8
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_135
gBlinkCmd_135:
  .4byte .+4
  .byte 1, 2
  .byte 0, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_136
gBlinkCmd_136:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 4, 8
  .byte 5, 8
  .byte 6, 8
  .byte 7, 8
  .byte 6, 8
  .byte 5, 8
  .byte 4, 8
  .byte 3, 8
  .byte 2, 8
  .byte 1, 8
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_137
gBlinkCmd_137:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_138
gBlinkCmd_138:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_139
gBlinkCmd_139:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_140
gBlinkCmd_140:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_141
gBlinkCmd_141:
  .4byte .+4
  .byte 1, 2
  .byte 0, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_142
gBlinkCmd_142:
  .4byte .+4
  .byte 0, 2
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 8
  .byte 7, 4
  .byte 8, 4
  .byte 9, 4
  .byte 10, 4
  .byte 11, 4
  .byte 13, 4
  .byte 14, 4
  .byte 15, 4
  .byte 16, 4
  .byte 17, 4
  .byte 18, 4
  .byte 0, 32
  .byte 0, 254

.global gBlinkCmd_143
gBlinkCmd_143:
  .4byte .+4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 8, 4
  .byte 9, 4
  .byte 10, 4
  .byte 11, 4
  .byte 12, 4
  .byte 13, 4
  .byte 14, 4
  .byte 15, 4
  .byte 16, 4
  .byte 17, 4
  .byte 18, 4
  .byte 19, 4
  .byte 20, 4
  .byte 21, 4
  .byte 22, 4
  .byte 23, 4
  .byte 24, 4
  .byte 25, 4
  .byte 26, 4
  .byte 27, 4
  .byte 28, 4
  .byte 29, 4
  .byte 30, 4
  .byte 31, 4
  .byte 32, 4
  .byte 33, 4
  .byte 34, 4
  .byte 35, 4
  .byte 36, 4
  .byte 35, 4
  .byte 34, 4
  .byte 33, 4
  .byte 32, 4
  .byte 31, 4
  .byte 30, 2
  .byte 29, 2
  .byte 28, 2
  .byte 27, 2
  .byte 26, 2
  .byte 24, 2
  .byte 23, 2
  .byte 22, 2
  .byte 21, 2
  .byte 20, 2
  .byte 19, 2
  .byte 18, 2
  .byte 17, 2
  .byte 16, 2
  .byte 15, 2
  .byte 14, 2
  .byte 13, 2
  .byte 12, 2
  .byte 11, 2
  .byte 10, 2
  .byte 9, 2
  .byte 8, 2
  .byte 7, 2
  .byte 6, 2
  .byte 5, 2
  .byte 4, 2
  .byte 3, 2
  .byte 2, 2
  .byte 1, 2
  .byte 0, 32
  .byte 0, 254

.global gBlinkCmd_144
gBlinkCmd_144:
  .4byte .+4
  .byte 0, 1
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 6, 3
  .byte 7, 3
  .byte 8, 3
  .byte 9, 3
  .byte 10, 3
  .byte 11, 3
  .byte 12, 3
  .byte 13, 3
  .byte 14, 3
  .byte 15, 3
  .byte 16, 3
  .byte 17, 3
  .byte 18, 3
  .byte 19, 3
  .byte 20, 3
  .byte 21, 3
  .byte 22, 3
  .byte 23, 32
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_145
gBlinkCmd_145:
  .4byte .+4
  .byte 0, 1
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 8, 4
  .byte 9, 8
  .byte 8, 4
  .byte 7, 4
  .byte 6, 4
  .byte 5, 4
  .byte 4, 4
  .byte 3, 2
  .byte 2, 2
  .byte 1, 2
  .byte 0, 10
  .byte 0, 254

.global gBlinkCmd_146
gBlinkCmd_146:
  .4byte .+4
  .byte 0, 1
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 8, 4
  .byte 9, 8
  .byte 8, 4
  .byte 7, 4
  .byte 6, 4
  .byte 5, 4
  .byte 4, 4
  .byte 3, 2
  .byte 2, 2
  .byte 1, 2
  .byte 0, 10
  .byte 0, 254

.global gBlinkCmd_147
gBlinkCmd_147:
  .4byte .+4
  .byte 0, 5
  .byte 1, 7
  .byte 2, 7
  .byte 3, 7
  .byte 4, 7
  .byte 5, 30
  .byte 6, 7
  .byte 7, 7
  .byte 8, 7
  .byte 9, 7
  .byte 10, 15
  .byte 9, 7
  .byte 8, 7
  .byte 7, 7
  .byte 6, 7
  .byte 5, 30
  .byte 4, 7
  .byte 3, 7
  .byte 2, 7
  .byte 1, 7
  .byte 0, 10
  .byte 0, 254

.global gBlinkCmd_148
gBlinkCmd_148:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_149
gBlinkCmd_149:
  .4byte .+4
  .byte 0, 127
  .byte 1, 2
  .byte 0, 80
  .byte 1, 2
  .byte 0, 2
  .byte 1, 2
  .byte 0, 2
  .byte 1, 80
  .byte 0, 2
  .byte 1, 2
  .byte 0, 2
  .byte 1, 2
  .byte 0, 2
  .byte 1, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_150
gBlinkCmd_150:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 4, 8
  .byte 5, 8
  .byte 6, 8
  .byte 0, 254

.global gBlinkCmd_151
gBlinkCmd_151:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_152
gBlinkCmd_152:
  .4byte .+4
  .byte 3, 8
  .byte 2, 8
  .byte 1, 8
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_153
gBlinkCmd_153:
  .4byte .+4
  .byte 0, 16
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 3, 4
  .byte 2, 4
  .byte 1, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_154
gBlinkCmd_154:
  .4byte .+4
  .byte 0, 30
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 4, 6
  .byte 5, 30
  .byte 4, 6
  .byte 3, 6
  .byte 2, 6
  .byte 1, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_155
gBlinkCmd_155:
  .4byte .+4
  .byte 0, 6
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 4, 6
  .byte 5, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_156
gBlinkCmd_156:
  .4byte .+4
  .byte 0, 20
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 2
  .byte 5, 20
  .byte 4, 2
  .byte 3, 2
  .byte 2, 2
  .byte 1, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_157
gBlinkCmd_157:
  .4byte .+4
  .byte 0, 6
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 4, 6
  .byte 5, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_158
gBlinkCmd_158:
  .4byte .+4
  .byte 0, 6
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 4, 6
  .byte 5, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_159
gBlinkCmd_159:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 8, 4
  .byte 9, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_160
gBlinkCmd_160:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 0, 254

.global gBlinkCmd_161
gBlinkCmd_161:
  .4byte .+4
  .byte 0, 20
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 3, 4
  .byte 2, 4
  .byte 1, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_162
gBlinkCmd_162:
  .4byte .+4
  .byte 0, 60
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 2
  .byte 5, 2
  .byte 6, 8
  .byte 7, 2
  .byte 8, 2
  .byte 9, 2
  .byte 10, 2
  .byte 11, 2
  .byte 12, 2
  .byte 0, 254

.global gBlinkCmd_163
gBlinkCmd_163:
  .4byte .+4
  .byte 0, 30
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 12
  .byte 3, 4
  .byte 2, 4
  .byte 1, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_164
gBlinkCmd_164:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_165
gBlinkCmd_165:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_166
gBlinkCmd_166:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 0, 254
  .byte 0, 0


.global gBlinkCmd_167
gBlinkCmd_167:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 2
  .byte 5, 2
  .byte 6, 2
  .byte 7, 2
  .byte 8, 2
  .byte 9, 2
  .byte 10, 2
  .byte 11, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_168
gBlinkCmd_168:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_169
gBlinkCmd_169:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 6, 3
  .byte 7, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_170
gBlinkCmd_170:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 2
  .byte 5, 2
  .byte 6, 2
  .byte 7, 2
  .byte 8, 2
  .byte 9, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_171
gBlinkCmd_171:
  .4byte .+4
  .byte 0, 1
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 8
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_172
gBlinkCmd_172:
  .4byte .+4
  .byte 0, 1
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 8
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_173
gBlinkCmd_173:
  .4byte .+4
  .byte 0, 1
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 8
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_174
gBlinkCmd_174:
  .4byte .+4
  .byte 0, 1
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 8
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_175
gBlinkCmd_175:
  .4byte .+4
  .byte 0, 1
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 8
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_176
gBlinkCmd_176:
  .4byte .+4
  .byte 0, 1
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 8
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_177
gBlinkCmd_177:
  .4byte .+4
  .byte 0, 1
  .byte 0, 255

.global gBlinkCmd_178
gBlinkCmd_178:
  .4byte .+4
  .byte 0, 1
  .byte 0, 255

.global gBlinkCmd_179
gBlinkCmd_179:
  .4byte .+4
  .byte 5, 1
  .byte 4, 3
  .byte 3, 3
  .byte 2, 3
  .byte 1, 3
  .byte 0, 1
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_180
gBlinkCmd_180:
  .4byte .+4
  .byte 5, 1
  .byte 4, 3
  .byte 3, 3
  .byte 2, 3
  .byte 1, 3
  .byte 0, 1
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_181
gBlinkCmd_181:
  .4byte .+4
  .byte 5, 1
  .byte 4, 3
  .byte 3, 3
  .byte 2, 3
  .byte 1, 3
  .byte 0, 1
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_182
gBlinkCmd_182:
  .4byte .+4
  .byte 5, 1
  .byte 4, 3
  .byte 3, 3
  .byte 2, 3
  .byte 1, 3
  .byte 0, 1
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_183
gBlinkCmd_183:
  .4byte .+4
  .byte 5, 1
  .byte 4, 3
  .byte 3, 3
  .byte 2, 3
  .byte 1, 3
  .byte 0, 1
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_184
gBlinkCmd_184:
  .4byte .+4
  .byte 5, 1
  .byte 4, 3
  .byte 3, 3
  .byte 2, 3
  .byte 1, 3
  .byte 0, 1
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_187
gBlinkCmd_187:
  .4byte .+4
  .byte 3, 1
  .byte 0, 254

.global gBlinkCmd_188
gBlinkCmd_188:
  .4byte .+4
  .byte 0, 6
  .byte 1, 6
  .byte 2, 6
  .byte 3, 12
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_189
gBlinkCmd_189:
  .4byte .+4
  .byte 0, 12
  .byte 1, 8
  .byte 2, 6
  .byte 3, 4
  .byte 4, 4
  .byte 5, 8
  .byte 2, 4
  .byte 0, 254

.global gBlinkCmd_190
gBlinkCmd_190:
  .4byte .+4
  .byte 0, 6
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 4, 6
  .byte 5, 6
  .byte 6, 6
  .byte 7, 6
  .byte 8, 30
  .byte 9, 6
  .byte 10, 6
  .byte 11, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_191
gBlinkCmd_191:
  .4byte .+4
  .byte 1, 15
  .byte 0, 15
  .byte 1, 4
  .byte 0, 4
  .byte 1, 4
  .byte 0, 4
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_192
gBlinkCmd_192:
  .4byte .+4
  .byte 0, 36
  .byte 1, 6
  .byte 0, 6
  .byte 1, 6
  .byte 0, 6
  .byte 0, 255

.global gBlinkCmd_193
gBlinkCmd_193:
  .4byte .+4
  .byte 0, 12
  .byte 1, 5
  .byte 2, 5
  .byte 3, 5
  .byte 4, 5
  .byte 5, 5
  .byte 6, 15
  .byte 5, 5
  .byte 4, 5
  .byte 3, 5
  .byte 2, 5
  .byte 1, 5
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_194
gBlinkCmd_194:
  .4byte .+4
  .byte 0, 12
  .byte 1, 5
  .byte 2, 5
  .byte 3, 5
  .byte 4, 5
  .byte 5, 5
  .byte 6, 15
  .byte 5, 5
  .byte 4, 5
  .byte 3, 5
  .byte 2, 5
  .byte 1, 5
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_195
gBlinkCmd_195:
  .4byte .+4
  .byte 0, 30
  .byte 1, 9
  .byte 2, 9
  .byte 3, 9
  .byte 4, 9
  .byte 5, 9
  .byte 6, 45
  .byte 7, 6
  .byte 8, 6
  .byte 9, 6
  .byte 10, 6
  .byte 11, 6
  .byte 10, 6
  .byte 9, 6
  .byte 8, 6
  .byte 7, 6
  .byte 6, 30
  .byte 7, 254

.global gBlinkCmd_196
gBlinkCmd_196:
  .4byte .+4
  .byte 0, 27
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 4, 6
  .byte 5, 6
  .byte 6, 6
  .byte 5, 6
  .byte 4, 6
  .byte 3, 6
  .byte 2, 6
  .byte 1, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_197
gBlinkCmd_197:
  .4byte .+4
  .byte 0, 10
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 4, 6
  .byte 5, 6
  .byte 6, 6
  .byte 7, 15
  .byte 6, 6
  .byte 5, 6
  .byte 4, 6
  .byte 3, 6
  .byte 2, 6
  .byte 1, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_198
gBlinkCmd_198:
  .4byte .+4
  .byte 0, 1
  .byte 0, 255

.global gBlinkCmd_199
gBlinkCmd_199:
  .4byte .+4
  .byte 0, 1
  .byte 0, 254

.global gBlinkCmd_200
gBlinkCmd_200:
  .4byte .+4
  .byte 0, 1
  .byte 0, 254

.global gBlinkCmd_201
gBlinkCmd_201:
  .4byte .+4
  .byte 0, 1
  .byte 0, 254

.global gBlinkCmd_202
gBlinkCmd_202:
  .4byte .+4
  .byte 0, 10
  .byte 1, 10
  .byte 2, 10
  .byte 3, 10
  .byte 4, 10
  .byte 5, 10
  .byte 4, 10
  .byte 3, 10
  .byte 2, 10
  .byte 1, 10
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_203
gBlinkCmd_203:
  .4byte .+4
  .byte 0, 8
  .byte 1, 6
  .byte 2, 6
  .byte 3, 8
  .byte 2, 6
  .byte 1, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_204
gBlinkCmd_204:
  .4byte .+4
  .byte 0, 1
  .byte 0, 254

.global gBlinkCmd_205
gBlinkCmd_205:
  .4byte .+4
  .byte 0, 2
  .byte 1, 3
  .byte 2, 2
  .byte 3, 30
  .byte 4, 1
  .byte 5, 3
  .byte 6, 1
  .byte 8, 3
  .byte 7, 1
  .byte 9, 127
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_206
gBlinkCmd_206:
  .4byte .+4
  .byte 0, 2
  .byte 1, 3
  .byte 2, 2
  .byte 3, 30
  .byte 4, 1
  .byte 5, 3
  .byte 6, 1
  .byte 8, 3
  .byte 7, 1
  .byte 9, 127
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_207
gBlinkCmd_207:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 2, 3
  .byte 0, 254

.global gBlinkCmd_208
gBlinkCmd_208:
  .4byte .+4
  .byte 0, 6
  .byte 1, 3
  .byte 2, 3
  .byte 1, 254

.global gBlinkCmd_209
gBlinkCmd_209:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 2
  .byte 5, 2
  .byte 6, 2
  .byte 7, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_210
gBlinkCmd_210:
  .4byte .+4
  .byte 0, 20
  .byte 1, 6
  .byte 2, 6
  .byte 3, 6
  .byte 4, 6
  .byte 5, 12
  .byte 4, 6
  .byte 3, 6
  .byte 2, 6
  .byte 1, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_211
gBlinkCmd_211:
  .4byte .+4
  .byte 0, 30
  .byte 1, 10
  .byte 2, 10
  .byte 3, 10
  .byte 4, 10
  .byte 5, 10
  .byte 6, 30
  .byte 0, 30
  .byte 6, 30
  .byte 0, 30
  .byte 6, 30
  .byte 7, 5
  .byte 8, 5
  .byte 9, 5
  .byte 10, 5
  .byte 0, 254

.global gBlinkCmd_212
gBlinkCmd_212:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_213
gBlinkCmd_213:
  .4byte .+4
  .byte 0, 3
  .byte 0, 254

.global gBlinkCmd_214
gBlinkCmd_214:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_215
gBlinkCmd_215:
  .4byte .+4
  .byte 0, 9
  .byte 1, 9
  .byte 2, 9
  .byte 3, 9
  .byte 4, 9
  .byte 3, 9
  .byte 2, 9
  .byte 1, 9
  .byte 0, 32
  .byte 0, 254

.global gBlinkCmd_216
gBlinkCmd_216:
  .4byte .+4
  .byte 0, 20
  .byte 1, 20
  .byte 2, 20
  .byte 3, 20
  .byte 2, 20
  .byte 1, 20
  .byte 0, 20
  .byte 0, 254

.global gBlinkCmd_217
gBlinkCmd_217:
  .4byte .+4
  .byte 0, 15
  .byte 1, 15
  .byte 2, 15
  .byte 3, 15
  .byte 4, 15
  .byte 5, 15
  .byte 6, 50
  .byte 7, 15
  .byte 8, 15
  .byte 9, 15
  .byte 10, 15
  .byte 11, 15
  .byte 12, 15
  .byte 0, 254

.global gBlinkCmd_218
gBlinkCmd_218:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 4, 8
  .byte 3, 8
  .byte 2, 8
  .byte 1, 8
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_219
gBlinkCmd_219:
  .4byte .+4
  .byte 0, 32
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 16
  .byte 4, 4
  .byte 3, 4
  .byte 2, 4
  .byte 1, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_220
gBlinkCmd_220:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 8, 4
  .byte 9, 4
  .byte 10, 4
  .byte 11, 4
  .byte 12, 4
  .byte 13, 4
  .byte 14, 4
  .byte 15, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_221
gBlinkCmd_221:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 8, 4
  .byte 9, 4
  .byte 10, 4
  .byte 11, 4
  .byte 12, 4
  .byte 13, 4
  .byte 14, 4
  .byte 15, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_222
gBlinkCmd_222:
  .4byte .+4
  .byte 0, 1
  .byte 1, 8
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 0, 254

.global gBlinkCmd_223
gBlinkCmd_223:
  .4byte .+4
  .byte 0, 8
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_224
gBlinkCmd_224:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 8, 4
  .byte 9, 4
  .byte 10, 4
  .byte 11, 4
  .byte 12, 4
  .byte 0, 254

.global gBlinkCmd_225
gBlinkCmd_225:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 4, 8
  .byte 5, 8
  .byte 6, 8
  .byte 7, 8
  .byte 8, 8
  .byte 9, 8
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_226
gBlinkCmd_226:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 6, 4
  .byte 5, 4
  .byte 4, 4
  .byte 3, 4
  .byte 2, 4
  .byte 1, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_227
gBlinkCmd_227:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 4, 8
  .byte 5, 8
  .byte 6, 8
  .byte 7, 8
  .byte 8, 8
  .byte 9, 8
  .byte 10, 8
  .byte 11, 8
  .byte 12, 8
  .byte 13, 8
  .byte 14, 8
  .byte 15, 8
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_228
gBlinkCmd_228:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 8, 4
  .byte 9, 4
  .byte 10, 4
  .byte 11, 4
  .byte 12, 4
  .byte 0, 254

.global gBlinkCmd_229
gBlinkCmd_229:
  .4byte .+4
  .byte 0, 32
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 32
  .byte 6, 4
  .byte 5, 4
  .byte 4, 4
  .byte 3, 4
  .byte 2, 4
  .byte 1, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_230
gBlinkCmd_230:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 8, 4
  .byte 9, 4
  .byte 10, 4
  .byte 11, 4
  .byte 12, 4
  .byte 13, 4
  .byte 14, 4
  .byte 0, 254

.global gBlinkCmd_231
gBlinkCmd_231:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 6, 4
  .byte 5, 4
  .byte 4, 4
  .byte 3, 4
  .byte 2, 4
  .byte 1, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_232
gBlinkCmd_232:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 6, 4
  .byte 5, 4
  .byte 4, 4
  .byte 3, 4
  .byte 2, 4
  .byte 1, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_233
gBlinkCmd_233:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 32
  .byte 6, 4
  .byte 5, 4
  .byte 4, 4
  .byte 3, 4
  .byte 2, 4
  .byte 1, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_234
gBlinkCmd_234:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 4, 8
  .byte 5, 8
  .byte 6, 8
  .byte 7, 8
  .byte 8, 8
  .byte 9, 8
  .byte 10, 8
  .byte 11, 8
  .byte 12, 8
  .byte 13, 8
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_235
gBlinkCmd_235:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 4, 8
  .byte 5, 8
  .byte 6, 8
  .byte 7, 8
  .byte 6, 8
  .byte 5, 8
  .byte 4, 8
  .byte 3, 8
  .byte 2, 8
  .byte 1, 8
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_236
gBlinkCmd_236:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 4, 8
  .byte 5, 8
  .byte 6, 8
  .byte 7, 8
  .byte 6, 8
  .byte 5, 8
  .byte 4, 8
  .byte 3, 8
  .byte 2, 8
  .byte 1, 8
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_237
gBlinkCmd_237:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 4, 8
  .byte 5, 8
  .byte 6, 8
  .byte 7, 8
  .byte 6, 8
  .byte 5, 8
  .byte 4, 8
  .byte 3, 8
  .byte 2, 8
  .byte 1, 8
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_238
gBlinkCmd_238:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 16
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 0, 254

.global gBlinkCmd_239
gBlinkCmd_239:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 16
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 0, 254

.global gBlinkCmd_240
gBlinkCmd_240:
  .4byte .+4
  .byte 0, 66
  .byte 1, 2
  .byte 2, 2
  .byte 3, 2
  .byte 4, 2
  .byte 5, 3
  .byte 6, 3
  .byte 7, 3
  .byte 8, 3
  .byte 9, 4
  .byte 10, 4
  .byte 11, 4
  .byte 12, 4
  .byte 13, 4
  .byte 14, 4
  .byte 15, 4
  .byte 16, 4
  .byte 17, 6
  .byte 18, 6
  .byte 19, 6
  .byte 20, 6
  .byte 21, 6
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_241
gBlinkCmd_241:
  .4byte .+4
  .byte 0, 2
  .byte 1, 2
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_242
gBlinkCmd_242:
  .4byte .+4
  .byte 0, 2
  .byte 1, 1
  .byte 2, 2
  .byte 3, 1
  .byte 4, 2
  .byte 5, 1
  .byte 6, 2
  .byte 7, 1
  .byte 8, 2
  .byte 9, 1
  .byte 10, 2
  .byte 11, 1
  .byte 12, 2
  .byte 13, 1
  .byte 14, 2
  .byte 15, 1
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_243
gBlinkCmd_243:
  .4byte .+4
  .byte 0, 36
  .byte 1, 4
  .byte 0, 15
  .byte 1, 4
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_244
gBlinkCmd_244:
  .4byte .+4
  .byte 0, 1
  .byte 0, 255

.global gBlinkCmd_245
gBlinkCmd_245:
  .4byte .+4
  .byte 0, 1
  .byte 0, 255

.global gBlinkCmd_246
gBlinkCmd_246:
  .4byte .+4
  .byte 0, 1
  .byte 0, 255

.global gBlinkCmd_247
gBlinkCmd_247:
  .4byte .+4
  .byte 0, 1
  .byte 0, 255

.global gBlinkCmd_248
gBlinkCmd_248:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_249
gBlinkCmd_249:
  .4byte .+4
  .byte 1, 4
  .byte 0, 4
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_250
gBlinkCmd_250:
  .4byte .+4
  .byte 0, 8
  .byte 1, 8
  .byte 2, 8
  .byte 3, 8
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_251
gBlinkCmd_251:
  .4byte .+4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 1
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_252
gBlinkCmd_252:
  .4byte .+4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 1
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_253
gBlinkCmd_253:
  .4byte .+4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 1
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_254
gBlinkCmd_254:
  .4byte .+4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 1
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_255
gBlinkCmd_255:
  .4byte .+4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 1
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_256
gBlinkCmd_256:
  .4byte .+4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 1
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_257
gBlinkCmd_257:
  .4byte .+4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 1
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_258
gBlinkCmd_258:
  .4byte .+4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 1
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_259
gBlinkCmd_259:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_260
gBlinkCmd_260:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_261
gBlinkCmd_261:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_262
gBlinkCmd_262:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 32
  .byte 6, 3
  .byte 7, 3
  .byte 8, 3
  .byte 9, 3
  .byte 10, 3
  .byte 11, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_263
gBlinkCmd_263:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 1, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 2, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 3
  .byte 3, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_264
gBlinkCmd_264:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 6, 3
  .byte 7, 3
  .byte 8, 3
  .byte 9, 3
  .byte 10, 3
  .byte 11, 3
  .byte 12, 3
  .byte 13, 3
  .byte 14, 3
  .byte 15, 3
  .byte 16, 3
  .byte 17, 3
  .byte 18, 3
  .byte 19, 3
  .byte 20, 3
  .byte 21, 3
  .byte 22, 3
  .byte 23, 3
  .byte 24, 3
  .byte 25, 3
  .byte 26, 3
  .byte 27, 3
  .byte 28, 3
  .byte 29, 3
  .byte 30, 3
  .byte 31, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_265
gBlinkCmd_265:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 6, 3
  .byte 7, 3
  .byte 8, 16
  .byte 9, 3
  .byte 10, 3
  .byte 11, 3
  .byte 12, 3
  .byte 13, 3
  .byte 14, 3
  .byte 15, 3
  .byte 16, 3
  .byte 17, 3
  .byte 18, 64
  .byte 0, 254

.global gBlinkCmd_266
gBlinkCmd_266:
  .4byte .+4
  .byte 0, 16
  .byte 1, 3
  .byte 2, 3
  .byte 3, 3
  .byte 4, 3
  .byte 5, 3
  .byte 6, 3
  .byte 7, 3
  .byte 8, 32
  .byte 7, 3
  .byte 6, 3
  .byte 5, 3
  .byte 4, 3
  .byte 3, 3
  .byte 2, 3
  .byte 1, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_267
gBlinkCmd_267:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_268
gBlinkCmd_268:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_269
gBlinkCmd_269:
  .4byte .+4
  .byte 0, 1
  .byte 1, 3
  .byte 2, 16
  .byte 3, 3
  .byte 7, 3
  .byte 4, 3
  .byte 8, 3
  .byte 5, 3
  .byte 9, 3
  .byte 6, 3
  .byte 10, 3
  .byte 0, 254

.global gBlinkCmd_270
gBlinkCmd_270:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_271
gBlinkCmd_271:
  .4byte .+4
  .byte 0, 1
  .byte 0, 255

.global gBlinkCmd_272
gBlinkCmd_272:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 0, 255
  .byte 0, 0

.global gBlinkCmd_273
gBlinkCmd_273:
  .4byte .+4
  .byte 0, 3
  .byte 1, 3
  .byte 0, 254
  .byte 0, 0

.global gBlinkCmd_274
gBlinkCmd_274:
  .4byte .+4
  .byte 0, 127
  .byte 0, 254

.global gBlinkCmd_275
gBlinkCmd_275:
  .4byte .+4
  .byte 0, 127
  .byte 0, 254

.global gBlinkCmd_276
gBlinkCmd_276:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 8, 4
  .byte 9, 4
  .byte 10, 4
  .byte 3, 254

.global gBlinkCmd_277
gBlinkCmd_277:
  .4byte .+4
  .byte 0, 1
  .byte 0, 255

.global gBlinkCmd_278
gBlinkCmd_278:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 4, 4
  .byte 5, 4
  .byte 6, 4
  .byte 7, 4
  .byte 8, 4
  .byte 9, 4
  .byte 10, 4
  .byte 3, 254

.global gBlinkCmd_279
gBlinkCmd_279:
  .4byte .+4
  .byte 0, 4
  .byte 1, 4
  .byte 2, 4
  .byte 3, 4
  .byte 0, 255
  .byte 0, 0

