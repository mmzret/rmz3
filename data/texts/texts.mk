TEXTS_DIR := ./data/texts

ZCS_00xx := $(wildcard $(TEXTS_DIR)/00xx/*.zc)
ZCS_BINS_00xx := $(subst .zc,.bin,$(ZCS_00xx))

ZCS_02xx := $(wildcard $(TEXTS_DIR)/02xx/*.zc)
ZCS_BINS_02xx := $(subst .zc,.bin,$(ZCS_02xx))

ZCS_04xx := $(wildcard $(TEXTS_DIR)/04xx/*.zc)
ZCS_BINS_04xx := $(subst .zc,.bin,$(ZCS_04xx))

ZCS_05xx := $(wildcard $(TEXTS_DIR)/05xx/*.zc)
ZCS_BINS_05xx := $(subst .zc,.bin,$(ZCS_05xx))

ZCS_06xx := $(wildcard $(TEXTS_DIR)/06xx/*.zc)
ZCS_BINS_06xx := $(subst .zc,.bin,$(ZCS_06xx))

ZCS_09xx := $(wildcard $(TEXTS_DIR)/09xx/*.zc)
ZCS_BINS_09xx := $(subst .zc,.bin,$(ZCS_09xx))

ZCS_0Axx := $(wildcard $(TEXTS_DIR)/0Axx/*.zc)
ZCS_BINS_0Axx := $(subst .zc,.bin,$(ZCS_0Axx))

ZCS_0Bxx := $(wildcard $(TEXTS_DIR)/0Bxx/*.zc)
ZCS_BINS_0Bxx := $(subst .zc,.bin,$(ZCS_0Bxx))

ZCS_0Cxx := $(wildcard $(TEXTS_DIR)/0Cxx/*.zc)
ZCS_BINS_0Cxx := $(subst .zc,.bin,$(ZCS_0Cxx))

ZCS_0Dxx := $(wildcard $(TEXTS_DIR)/0Dxx/*.zc)
ZCS_BINS_0Dxx := $(subst .zc,.bin,$(ZCS_0Dxx))

ZCS_0Exx := $(wildcard $(TEXTS_DIR)/0Exx/*.zc)
ZCS_BINS_0Exx := $(subst .zc,.bin,$(ZCS_0Exx))

ZCS_10xx := $(wildcard $(TEXTS_DIR)/10xx/*.zc)
ZCS_BINS_10xx := $(subst .zc,.bin,$(ZCS_10xx))

ZCS_13xx := $(wildcard $(TEXTS_DIR)/13xx/*.zc)
ZCS_BINS_13xx := $(subst .zc,.bin,$(ZCS_13xx))

texts-00xx: $(ZCS_BINS_00xx)
texts-02xx: $(ZCS_BINS_02xx)
texts-04xx: $(ZCS_BINS_04xx)
texts-05xx: $(ZCS_BINS_05xx)
texts-06xx: $(ZCS_BINS_06xx)
texts-09xx: $(ZCS_BINS_09xx)
texts-0Axx: $(ZCS_BINS_0Axx)
texts-0Bxx: $(ZCS_BINS_0Bxx)
texts-0Cxx: $(ZCS_BINS_0Cxx)
texts-0Dxx: $(ZCS_BINS_0Dxx)
texts-0Exx: $(ZCS_BINS_0Exx)
texts-10xx: $(ZCS_BINS_10xx)
texts-13xx: $(ZCS_BINS_13xx)

texts: texts-00xx texts-02xx texts-04xx texts-05xx texts-06xx texts-09xx texts-0Axx texts-0Bxx texts-0Cxx texts-0Dxx texts-0Exx texts-10xx texts-13xx

asm/text.o: asm/text.s texts

clean-texts:
	rm -f $(TEXTS_DIR)/*xx/*.bin
