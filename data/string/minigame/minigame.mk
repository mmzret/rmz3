MG_DIR := ./data/string/minigame

MG_RULE_TXTS := $(wildcard $(MG_DIR)/*.txt)
MG_RULE_BINS := $(subst .txt,.bin,$(MG_RULE_TXTS))

minigame-rule: $(MG_RULE_BINS)

.PHONY: clean-minigame-rule
clean-minigame-rule:
	rm -f $(MG_DIR)/*.bin
