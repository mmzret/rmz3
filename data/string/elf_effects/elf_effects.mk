EE_DIR := ./data/string/elf_effects

EE_TXTS := $(wildcard $(EE_DIR)/*.txt)
EE_BINS := $(subst .txt,.bin,$(EE_TXTS))

elf-effect: $(EE_BINS)

clean-elf-effect:
	rm -f $(EE_DIR)/*.bin
