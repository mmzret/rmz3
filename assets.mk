include songs.mk
include stage_rules.mk
include sprite_rules.mk
include data/string/string.mk
include data/texts/texts.mk
include graphics_file_rules.mk
include graphic_header_rules.mk

ASSETS := $(SONG_ASMS) $(STAGE_HDR) $(SPRITES) $(STR_BINS) $(ALL_GRAPHICS) $(GFX_HDR) $(ZCS_TEXTS)

.PHONY: assets
assets: $(ASSETS)

.PHONY: clean-assets
clean-assets: clean-stage clean-midi clean-sprite clean-string clean-graphics clean-graphic-headers clean-texts

#### Text Rules ####

TEXTCOMP := tools/rmz-text-compiler$(EXE)

%.bin: %.txt
	$(TEXTCOMP) -f $< -o $@
%.bin: %.zc
	$(TEXTCOMP) -c --verbose -f $< -o $@
