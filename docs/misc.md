# Misc

## Disable command-dash

The command-dash is triggered by the function starting with `08033708`.

So, command-dash can be disabled by preventing the execution of this function.

I mean...

```s
# Calling function 08033708 from 080335cc.
# 0x46c0 is nop instruction
080335cc = 0xc0
080335cd = 0x46
080335ce = 0xc0
080335cf = 0x46
```

## Secret Disk

Secret Disk(SD) flag is from `02036e78`. Size is 45 bytes

Each entry has following bitfields.

```
bit0: unlocked   n+0 
bit1: unlocked   n+1 
bit2: unlocked   n+2 
bit3: unlocked   n+3 
bit4: analysised n+0
bit5: analysised n+1
bit6: analysised n+2
bit7: analysised n+3
```

So, 1 byte store 4 SD flags.

## Sunken Library algorithm

Sunken Library's door coords is in `0834cdb8`. Size is 192 bytes (`Coord[24]`).

```
0834cdb8: Door idx00 Coord (s32, s32)
0834cdc0: Door idx01 Coord (s32, s32)
...
0834ce70: Door idx23 Coord (s32, s32)
```

It corresponds to the coordinates of 6x4, 24 doors in total. The mapping between the array indexes and the doors is as follows.

```
08 09 10 11 12 13
14 00 01 02 03 15
16 04 05 06 07 17
18 19 20 21 22 23
```

Door idx is in `0202fff4..0202fff7`.

```
0202fff4: Weil
0202fff5: Omega
0202fff6: Darkelf
0202fff7: Elf War
```

Calculate idx is executed on fuction `0801f7ac`. This function is executed only once, immediately after zero enters the search room.

## Mission selection

```
  Unit is 2 bytes.

  0x2030B64: Current select mission
  0x2030B66: Mission range start
  0x2030B68: Mission range end
```
