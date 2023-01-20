ELFMUGSHOT_DIR := ./data/gfx/elf/mugshot

ELFMUGSHOT_PNGS := $(filter-out %.lz.png, $(wildcard $(ELFMUGSHOT_DIR)/*/*.png) $(wildcard $(ELFMUGSHOT_DIR)/*/*/*.png))
ELFMUGSHOT_LZ_PNGS := $(wildcard $(ELFMUGSHOT_DIR)/*/*.lz.png) $(wildcard $(ELFMUGSHOT_DIR)/*/*/*.lz.png)
ELFMUGSHOT_BIN := $(subst .png,.bin,$(ELFMUGSHOT_PNGS)) $(subst .lz.png,.bin,$(ELFMUGSHOT_LZ_PNGS))

elf-mugshot: $(ELFMUGSHOT_BIN)

$(ELFMUGSHOT_DIR)/%.bin: $(ELFMUGSHOT_DIR)/%.lz
	@cat $< $(dir $<)color.gbapal $(dir $<)grayscale.gbapal > $@

$(ELFMUGSHOT_DIR)/%.bin: $(ELFMUGSHOT_DIR)/%.4bpp
	@cat $< $(dir $<)color.gbapal $(dir $<)grayscale.gbapal > $@

$(ELFMUGSHOT_DIR)/%.lz: $(ELFMUGSHOT_DIR)/%.lz.4bpp
	@$(GBAGFX) $< $@ $(GFX_OPTS)

$(ELFMUGSHOT_DIR)/%.4bpp: $(ELFMUGSHOT_DIR)/%.png
	@$(GBAGFX) $< $@ $(GFX_OPTS)

clean-elf-mugshot:
	@rm -f $(ELFMUGSHOT_DIR)/*/*.bin $(ELFMUGSHOT_DIR)/*/*/*.bin
	@rm -f $(ELFMUGSHOT_DIR)/*/*.lz $(ELFMUGSHOT_DIR)/*/*/*.lz
	@rm -f $(ELFMUGSHOT_DIR)/*/*.4bpp $(ELFMUGSHOT_DIR)/*/*/*.4bpp
