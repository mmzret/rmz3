GFX_JSON := $(shell find data/tilesets -type f -name 'header.json') $(shell find sprites -type f -name 'header.json') $(shell find graphics/dialog -type f -name 'header.json')
GFX_HDR := $(subst .json,.o,$(GFX_JSON))

%.s: %.json
	$(GFX_JSON_CONVERTER) $< > $@

$(GFX_HDR): %.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

clean-graphic-headers:
	@rm -f $(GFX_HDR) $(subst .json,.s,$(GFX_JSON))
