include data/string/disk/disk.mk
include data/string/elf_effects/elf_effects.mk
include data/string/minigame/minigame.mk

STR_DIR := ./data/string/

STR_TXTS := $(wildcard $(STR_DIR)/*.txt)
STR_BINS := $(subst .txt,.bin,$(STR_TXTS))
STR_BINS += $(DISK_BINS) $(EE_BINS) $(MG_RULE_BINS)

.PHONY: string
string: $(STR_BINS)

.PHONY: clean-string
clean-string: clean-disk-text clean-elf-effect clean-minigame-rule
	rm -f $(STR_DIR)*.bin
