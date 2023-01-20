include data/string/disk/disk.mk
include data/string/elf_effects/elf_effects.mk
include data/string/minigame/minigame.mk

STR_DIR := ./data/string/

STR_TXTS := $(wildcard $(STR_DIR)/*.txt)
STR_BINS := $(subst .txt,.bin,$(STR_TXTS))

string: disk-text elf-effect minigame-rule $(STR_BINS)

clean-string: clean-disk-text clean-elf-effect clean-minigame-rule
	rm -f $(STR_DIR)*.bin
