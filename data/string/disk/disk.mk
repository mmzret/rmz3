DISK_DIR := ./data/string/disk

DISK_TXTS := $(wildcard $(DISK_DIR)/*.txt)
DISK_BINS := $(subst .txt,.bin,$(DISK_TXTS))

disk-text: $(DISK_BINS)

.PHONY: clean-disk-text
clean-disk-text:
	rm -f $(DISK_DIR)/*.bin
