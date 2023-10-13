.include "asm/macros.inc"

.balign 4
.section .rodata

# ./tools/dumper/bin.ts ./baserom.gba 0x08355364 0x08355c70 ./data/scripts_energy_facility.bin
EnergyFacilityScripts:
  .incbin "data/scripts_energy_facility.bin"
