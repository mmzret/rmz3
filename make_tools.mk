# This controls building executables in the `tools` folder.
# Can be invoked through the `Makefile` or standalone.

MAKEFLAGS += --no-print-directory

# Inclusive list. If you don't want a tool to be built, don't add it here.
TOOL_NAMES := gbagfx mid2agb scaninc

# TOOLDIRS = tools/gbagfx tools/mid2agb tools/scaninc
TOOL_DIRS := $(patsubst %,tools/%,$(TOOL_NAMES))

.PHONY: tools clean-tools $(TOOL_DIRS)
tools: $(TOOL_DIRS)

$(TOOL_DIRS):
	$(MAKE) -C $@

clean-tools:
	@$(foreach tooldir,$(TOOL_DIRS),$(MAKE) clean -C $(tooldir);)
