# stage.json を受け取って layer.h と landscape.h を生成するルール
STAGE_JSON_CONVERTER := ./tools/dev/stage.ts

STAGE_DIR := data/stage
STAGE_OUT_DIR := include/stage

# e.g. data/stage/ocean/stage.json
STAGE_JSON := $(wildcard $(STAGE_DIR)/*/stage.json)

# e.g. ocean, ...
STAGE_NAMES := $(patsubst $(STAGE_DIR)/%/stage.json,%,$(STAGE_JSON))

# e.g. include/stage/ocean/layer.h
LAYERS := $(patsubst $(STAGE_DIR)/%/stage.json,$(STAGE_OUT_DIR)/%/layer.h,$(STAGE_JSON))
# e.g. include/stage/ocean/landscape.h
LANDSCAPES := $(patsubst $(STAGE_DIR)/%/stage.json,$(STAGE_OUT_DIR)/%/landscape.h,$(STAGE_JSON))
STAGE_HDR := $(LAYERS) $(LANDSCAPES)

.PHONY: stage
stage: $(STAGE_HDR)

# data/stage/ocean/stage.json -> include/stage/ocean/layer.h
# とりあえず layer.h を主ターゲット、 landscape.h は副作用として生成
$(LAYERS): $(STAGE_OUT_DIR)/%/layer.h: $(STAGE_DIR)/%/stage.json
	@mkdir -p $(dir $@)
	$(STAGE_JSON_CONVERTER) $<

# landscape.h が必要なときは、 layer.h が最新であることを確認する
$(LANDSCAPES): %/landscape.h: %/layer.h
	@if [ ! -f $@ ]; then rm -f $<; $(MAKE) $<; fi

.PHONY: clean-stage
clean-stage:
	rm -f $(STAGE_HDR)


