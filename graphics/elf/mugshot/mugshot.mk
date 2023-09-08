ELFMUGSHOT_DIR := ./graphics/elf/mugshot

ELFMUGSHOT_PNGS := $(filter-out %.lz.png, $(wildcard $(ELFMUGSHOT_DIR)/*/*.png) $(wildcard $(ELFMUGSHOT_DIR)/*/*/*.png))
ELFMUGSHOT_LZ_PNGS := $(wildcard $(ELFMUGSHOT_DIR)/*/*.lz.png) $(wildcard $(ELFMUGSHOT_DIR)/*/*/*.lz.png)
ELFMUGSHOT_GFX := $(subst .png,.4bpp,$(ELFMUGSHOT_PNGS)) $(subst .lz.png,.lz,$(ELFMUGSHOT_LZ_PNGS))
ELFMUGSHOT_PAL := $(subst .png,.gbapal,$(ELFMUGSHOT_PNGS)) $(subst .lz.png,.lz.gbapal,$(ELFMUGSHOT_LZ_PNGS))

elf-mugshot: $(ELFMUGSHOT_GFX) $(ELFMUGSHOT_PAL)

