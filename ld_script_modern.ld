OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)
MEMORY {
    ewram   : ORIGIN = 0x02000000, LENGTH = 4M - 4k
    iwram   : ORIGIN = 0x03000000, LENGTH = 32k
	  rom     : ORIGIN = (0x08000000), LENGTH = 32M
}

gMaxLines = 0;
gNumMusicPlayers = 15;

SECTIONS {
	. = 0x2000000;
	ewram (NOLOAD) :
	ALIGN(4)
    {
      src/ewram.o(ewram_data);
    } >ewram = 0x00

	. = 0x3000000;
    iwram (NOLOAD) :
    ALIGN(4)
    {
        src/libs/m4a.o(.bss.code);
        src/iwram.o(iwram_data);
    } >iwram = 0x00

    . = 0x8000000;
    .text :
    ALIGN(4)
    {
      asm/rom_header.o (.text*);
			asm/crt0.o (.text);
			src/sprite2.o (.text);
			src/sprite2.o (.rodata);
			src/sprite2.o (.data);
      src/mmbn4.o (.rodata);
			src/mmbn4.o (.text);
			src/main.o (.text);
      /* INCLUDE "linker/text.txt" */
      *(.text*);
    } >rom = 0x00

	.data :
	ALIGN(4)
	{
		*(.data*);
	} >rom = 0x00

	.rodata :
	ALIGN(4)
	{
    /* INCLUDE "linker/rodata.txt" */
		*(.rodata*);
    INCLUDE "linker/rodata_sprite.txt"
    INCLUDE "linker/rodata_tileset.txt"
	} >rom = 0x00

    /* Discard everything not specifically mentioned above. */
	/DISCARD/ :
    {
        *(*);
    }
}