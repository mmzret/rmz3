OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)

gSongTable = 0x0810f810;
gMPlayTable = 0x0810f75c;
gMaxLines = 0;
gNumMusicPlayers = 15;
DiskAnalysisScripts = 0x08386a78;

SECTIONS {
	. = 0x2000000;
	ewram (NOLOAD) :
	ALIGN(4)
    {
        INCLUDE "sym_ewram.txt"
    }

	. = 0x3000000;
    iwram (NOLOAD) :
    ALIGN(4)
    {
        INCLUDE "sym_iwram.txt"
    }

    . = 0x8000000;
    .text :
    ALIGN(4)
    {
		asm/crt0.o (.text);
		asm/code_080002dc.o (.text);

		asm/main.o (.text);
		asm/sio.o (.text);
		src/input.o (.text);
		asm/sram.o (.text);
		src/gfx.o (.text);
		src/sound.o (.text);
		asm/code_0800469c.o (.text);
		src/entity.o (.text);
		src/object.o (.text);
		src/syssav.o (.text);
		src/stage.o (.text);
		asm/stage.o (.text);
		src/code_08016e1c.o (.text);
		asm/code_08016db4.o (.text);

		asm/menu.o (.text);
		
		src/analysis/diskAnalysisScript.o (.text);
		src/analysis/analysis.o (.text);

		asm/minigame.o (.text);
    } =0

	lib_text :
	ALIGN(4)
	{
		src/libs/m4a_1.o (.text);
		src/libs/m4a.o (.text);
		asm/libagbsyscall.o (.text);
		src/libs/agb_sram.o (.text);
		*libgcc.a:*_call_via_rX*.o(.text);
		*libgcc.a:*_divsi3*.o(.text);
		*libgcc.a:*_dvmd_tls*.o(.text);
		*libgcc.a:*_modsi3*.o(.text);
		*libgcc.a:*_udivsi3*.o(.text);
		*libgcc.a:*_umodsi3*.o(.text);
		*libc.a:*memcpy*.o(.text);
		*libc.a:*memset*.o(.text);
	}

	.rodata :
	ALIGN(4)
	{
		src/data/data_080fea74.o (.rodata);
		data/gfx/font/font.o (.rodata);
		src/data/data_0810e23c.o (.rodata);
		src/libs/m4a_tables.o (.rodata);
		data/sound/sound.o (.rodata);
		src/data/data_08338c74.o (.rodata);
		data/data_08338de8/data_08338de8.o (.rodata);
		data/string/string.o (.rodata);
		data/texts/texts.o (.rodata);
		data/data_083856f8/data_083856f8.o (.rodata);
		data/gfx/gfx_083b8c8c/gfx_083b8c8c.o (.rodata);
		src/data/bgmaps.o (.rodata);
		data/gfx/cutscene/cutscene.o (.rodata);
		data/gfx/dialog/dialog.o (.rodata);
		data/data_085b5cd0/data_085b5cd0.o (.rodata);
		data/gfx/gfx_085d78f8/gfx_085d78f8.o (.rodata);
		data/gfx/elf/elf.o (.rodata);
		src/data/terrain.o (.rodata);
		data/terrain/terrain.o (.rodata);
		data/gfx/tileset/tileset.o (.rodata);
	} =0

    /* Discard everything not specifically mentioned above. */
	/DISCARD/ :
    {
        *(*);
    }
}