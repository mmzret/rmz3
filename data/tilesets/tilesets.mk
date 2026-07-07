# カレントディレクトリは rmz3 ルートディレクトリであることを前提
TILESET_DIR := data/tilesets

$(TILESET_DIR)/snow/snow0.4bpp: GFX_OPTS := -num_tiles 482
$(TILESET_DIR)/snow/snow2.4bpp: GFX_OPTS := -num_tiles 466
$(TILESET_DIR)/snow/snow3.4bpp: GFX_OPTS := -num_tiles 342
$(TILESET_DIR)/snow/snow5.4bpp: GFX_OPTS := -num_tiles 510
$(TILESET_DIR)/snow/snow6.4bpp: GFX_OPTS := -num_tiles 452
$(TILESET_DIR)/snow/snow8.4bpp: GFX_OPTS := -num_tiles 506
$(TILESET_DIR)/volcano/volcano2.4bpp: GFX_OPTS := -num_tiles 462
$(TILESET_DIR)/volcano/volcano3.4bpp: GFX_OPTS := -num_tiles 508
$(TILESET_DIR)/volcano/volcano4.4bpp: GFX_OPTS := -num_tiles 508
$(TILESET_DIR)/volcano/volcano5.4bpp: GFX_OPTS := -num_tiles 508
$(TILESET_DIR)/waterside/waterside1.4bpp: GFX_OPTS := -num_tiles 386
$(TILESET_DIR)/waterside/waterside3.4bpp: GFX_OPTS := -num_tiles 430
$(TILESET_DIR)/waterside/waterside4.4bpp: GFX_OPTS := -num_tiles 426
$(TILESET_DIR)/waterside/waterside5.4bpp: GFX_OPTS := -num_tiles 468
$(TILESET_DIR)/waterside/waterside6.4bpp: GFX_OPTS := -num_tiles 428
$(TILESET_DIR)/factory/factory1.4bpp: GFX_OPTS := -num_tiles 504
$(TILESET_DIR)/factory/factory2.4bpp: GFX_OPTS := -num_tiles 434
$(TILESET_DIR)/ruin/ruin1.4bpp: GFX_OPTS := -num_tiles 430
$(TILESET_DIR)/ruin/ruin2.4bpp: GFX_OPTS := -num_tiles 478
$(TILESET_DIR)/ruin/ruin3.4bpp: GFX_OPTS := -num_tiles 388
$(TILESET_DIR)/missile/missile1.4bpp: GFX_OPTS := -num_tiles 500
$(TILESET_DIR)/missile/missile2.4bpp: GFX_OPTS := -num_tiles 374
$(TILESET_DIR)/missile/missile3.4bpp: GFX_OPTS := -num_tiles 468
$(TILESET_DIR)/missile/missile6.4bpp: GFX_OPTS := -num_tiles 216
$(TILESET_DIR)/desert/desert0.4bpp: GFX_OPTS := -num_tiles 506
$(TILESET_DIR)/desert/desert1.4bpp: GFX_OPTS := -num_tiles 488
$(TILESET_DIR)/forest/forest2.4bpp: GFX_OPTS := -num_tiles 344
$(TILESET_DIR)/forest/forest3.4bpp: GFX_OPTS := -num_tiles 382
$(TILESET_DIR)/antarctic/antarctic0.4bpp: GFX_OPTS := -num_tiles 310
$(TILESET_DIR)/antarctic/antarctic2.4bpp: GFX_OPTS := -num_tiles 484
$(TILESET_DIR)/antarctic/antarctic4.4bpp: GFX_OPTS := -num_tiles 492
$(TILESET_DIR)/area_x2/area_x2_1.4bpp: GFX_OPTS := -num_tiles 504
$(TILESET_DIR)/area_x2/area_x2_2.4bpp: GFX_OPTS := -num_tiles 390
$(TILESET_DIR)/area_x2/area_x2_3.4bpp: GFX_OPTS := -num_tiles 454
$(TILESET_DIR)/plant/plant1.4bpp: GFX_OPTS := -num_tiles 420
$(TILESET_DIR)/plant/plant2.4bpp: GFX_OPTS := -num_tiles 434
$(TILESET_DIR)/plant/plant3.4bpp: GFX_OPTS := -num_tiles 342
$(TILESET_DIR)/giant_elevator/giant_elevator0.4bpp: GFX_OPTS := -num_tiles 478
$(TILESET_DIR)/giant_elevator/giant_elevator1.4bpp: GFX_OPTS := -num_tiles 452
$(TILESET_DIR)/giant_elevator/giant_elevator3.4bpp: GFX_OPTS := -num_tiles 382
$(TILESET_DIR)/giant_elevator/giant_elevator4.4bpp: GFX_OPTS := -num_tiles 468
$(TILESET_DIR)/sub_arcadia/sub_arcadia0.4bpp: GFX_OPTS := -num_tiles 506
$(TILESET_DIR)/sub_arcadia/sub_arcadia1.4bpp: GFX_OPTS := -num_tiles 510
$(TILESET_DIR)/sub_arcadia/sub_arcadia3.4bpp: GFX_OPTS := -num_tiles 508
$(TILESET_DIR)/weil_labo/weil_labo2.4bpp: GFX_OPTS := -num_tiles 238
$(TILESET_DIR)/weil_labo/weil_labo5.4bpp: GFX_OPTS := -num_tiles 358
$(TILESET_DIR)/resistance_base/resistance_base5.4bpp: GFX_OPTS := -num_tiles 338

TILESET_ANIM_DIR := $(TILESET_DIR)/misc

.PHONY: clean-tileset clean-tileset-anim
clean-tileset: clean-tileset-anim
	rm -f $(wildcard $(TILESET_DIR)/snow/*.4bpp) $(wildcard $(TILESET_DIR)/snow/*.gbapal) $(wildcard $(TILESET_DIR)/snow/*.lz)
	rm -f $(wildcard $(TILESET_DIR)/volcano/*.4bpp) $(wildcard $(TILESET_DIR)/volcano/*.gbapal) $(wildcard $(TILESET_DIR)/volcano/*.lz)
	rm -f $(wildcard $(TILESET_DIR)/waterside/*.4bpp) $(wildcard $(TILESET_DIR)/waterside/*.gbapal) $(wildcard $(TILESET_DIR)/waterside/*.lz)
	rm -f $(wildcard $(TILESET_DIR)/factory/*.4bpp) $(wildcard $(TILESET_DIR)/factory/*.gbapal) $(wildcard $(TILESET_DIR)/factory/*.lz)
	rm -f $(wildcard $(TILESET_DIR)/ruin/*.4bpp) $(wildcard $(TILESET_DIR)/ruin/*.gbapal) $(wildcard $(TILESET_DIR)/ruin/*.lz)
	rm -f $(wildcard $(TILESET_DIR)/missile/*.4bpp) $(wildcard $(TILESET_DIR)/missile/*.gbapal) $(wildcard $(TILESET_DIR)/missile/*.lz)
	rm -f $(wildcard $(TILESET_DIR)/desert/*.4bpp) $(wildcard $(TILESET_DIR)/desert/*.gbapal) $(wildcard $(TILESET_DIR)/desert/*.lz)
	rm -f $(wildcard $(TILESET_DIR)/forest/*.4bpp) $(wildcard $(TILESET_DIR)/forest/*.gbapal) $(wildcard $(TILESET_DIR)/forest/*.lz)
	rm -f $(wildcard $(TILESET_DIR)/antarctic/*.4bpp) $(wildcard $(TILESET_DIR)/antarctic/*.gbapal) $(wildcard $(TILESET_DIR)/antarctic/*.lz)
	rm -f $(wildcard $(TILESET_DIR)/area_x2/*.4bpp) $(wildcard $(TILESET_DIR)/area_x2/*.gbapal) $(wildcard $(TILESET_DIR)/area_x2/*.lz)
	rm -f $(wildcard $(TILESET_DIR)/plant/*.4bpp) $(wildcard $(TILESET_DIR)/plant/*.gbapal) $(wildcard $(TILESET_DIR)/plant/*.lz)
	rm -f $(wildcard $(TILESET_DIR)/giant_elevator/*.4bpp) $(wildcard $(TILESET_DIR)/giant_elevator/*.gbapal) $(wildcard $(TILESET_DIR)/giant_elevator/*.lz)
	rm -f $(wildcard $(TILESET_DIR)/sub_arcadia/*.4bpp) $(wildcard $(TILESET_DIR)/sub_arcadia/*.gbapal) $(wildcard $(TILESET_DIR)/sub_arcadia/*.lz)
	rm -f $(wildcard $(TILESET_DIR)/weil_labo/*.4bpp) $(wildcard $(TILESET_DIR)/weil_labo/*.gbapal) $(wildcard $(TILESET_DIR)/weil_labo/*.lz)
	rm -f $(wildcard $(TILESET_DIR)/resistance_base/*.4bpp) $(wildcard $(TILESET_DIR)/resistance_base/*.gbapal) $(wildcard $(TILESET_DIR)/resistance_base/*.lz)

clean-tileset-anim:
	@rm -f $(wildcard $(TILESET_ANIM_DIR)/*.4bpp) $(wildcard $(TILESET_ANIM_DIR)/*/*.4bpp)

RULES_NO_SCAN += clean-tileset clean-tileset-anim
