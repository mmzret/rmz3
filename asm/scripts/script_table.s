    .balign 4
    .section .rodata

@ idx is StageID
.global gStageScriptList
gStageScriptList: @ 0x0834d06c
    .word gStage0ScriptList
    .word gSpaceCraftScriptList
    .word gVolcanoScriptList
    .word gOceanScriptList
    .word gRepairFactoryScriptList
    .word gOldResidentialScriptList
    .word gMissileFactoryScriptList
    .word 0x08353A4C
    .word 0x08354140
    .word 0x08354814
    .word gAreaX2ScriptList
    .word 0x08355C28
    .word 0x0835663C
    .word 0x08357788
    .word 0x08358088
    .word 0x08358E08
    .word 0x0835BD4C
    .word gResistanceBaseScriptList
