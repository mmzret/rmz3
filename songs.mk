MID2AGB := tools/mid2agb/mid2agb$(EXE)
MIDI_DIR := sound/songs/midi

# sound/songs/midi/*.s
MIDI_ASMS = $(subst .mid,.s,$(wildcard $(MIDI_DIR)/*.mid))

SONG_ASMS = $(wildcard sound/songs/*.s) $(MIDI_ASMS)

.PHONY: midi clean-midi
midi: $(MIDI_ASMS)

clean-midi:
	@rm -f $(MIDI_ASMS)

# target-specific variables でmidファイルごとにオプションを指定
# TODO: midiファイル全部記述したら、1番使われてるオプションをデフォルトにする
MID2AGB_FLAGS := 

$(MIDI_DIR)/se_cursor.s: MID2AGB_FLAGS := -G000 -P120
$(MIDI_DIR)/se_rbase_pre_door.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_omegazero_meshia.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_fefnir_damage.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_fefnir_atk.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_leviathan_damage.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_leviathan_atk.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_harpuia_damage.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_harpuia_atk.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_phantom_shuriken.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_phantom_retsu.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_phantom_utsusemi.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_phantom_damage.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_phantom_se.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_unk_101.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_unk_103.s: MID2AGB_FLAGS := -E -P020
$(MIDI_DIR)/se_unk_104.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_unk_105.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_unk_106.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_shell_crawler.s: MID2AGB_FLAGS := -E -P020
$(MIDI_DIR)/se_unk_108.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_unk_109.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_unk_10a.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_unk_110.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_unk_111.s: MID2AGB_FLAGS := -E -G002 -P120
$(MIDI_DIR)/se_unk_112.s: MID2AGB_FLAGS := -E -P220
$(MIDI_DIR)/se_unk_113.s: MID2AGB_FLAGS := -E -P020
$(MIDI_DIR)/se_baby_elf_laugh.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_baby_elf_laugh_2.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_baby_elf_117.s: MID2AGB_FLAGS := -P220
$(MIDI_DIR)/se_baby_elf_118.s: MID2AGB_FLAGS := -P220
$(MIDI_DIR)/se_baby_elf_death.s: MID2AGB_FLAGS := -G002 -P020
$(MIDI_DIR)/se_unk_11a.s: MID2AGB_FLAGS := -P220
$(MIDI_DIR)/se_camera_beep.s: MID2AGB_FLAGS := -P220
$(MIDI_DIR)/se_unk_11f.s: MID2AGB_FLAGS := -P020
$(MIDI_DIR)/se_unk_120.s: MID2AGB_FLAGS := -G002 -P020
$(MIDI_DIR)/se_unk_121.s: MID2AGB_FLAGS := -G002 -P020
$(MIDI_DIR)/se_unk_122.s: MID2AGB_FLAGS := -P010
$(MIDI_DIR)/se_sea_level.s: MID2AGB_FLAGS := -P050
$(MIDI_DIR)/se_unk_126.s: MID2AGB_FLAGS := -G001 -P010
$(MIDI_DIR)/se_unk_127.s: MID2AGB_FLAGS := -G001 -P020
$(MIDI_DIR)/se_blazin_fire_shower.s: MID2AGB_FLAGS := -P020
$(MIDI_DIR)/se_unk_129.s: MID2AGB_FLAGS := -P020
$(MIDI_DIR)/se_arcadia_ringtone.s: MID2AGB_FLAGS := -P120
$(MIDI_DIR)/se_unk_12b.s: MID2AGB_FLAGS := -P020
$(MIDI_DIR)/se_omega1_laser.s: MID2AGB_FLAGS := -G001 -P020
$(MIDI_DIR)/se_omega1_hoop.s: MID2AGB_FLAGS := -G002 -P020
$(MIDI_DIR)/se_omega1_teleport.s: MID2AGB_FLAGS := -G002 -P020
$(MIDI_DIR)/se_unk_12f.s: MID2AGB_FLAGS := -P020
$(MIDI_DIR)/se_omega_zx_buster_1.s: MID2AGB_FLAGS := -G002 -P020
$(MIDI_DIR)/se_omega_zx_131.s: MID2AGB_FLAGS := -P020
$(MIDI_DIR)/se_omega_zx_binding_ball.s: MID2AGB_FLAGS := -G002 -P020
$(MIDI_DIR)/se_omega_zx_spark_chaser.s: MID2AGB_FLAGS := -P020
$(MIDI_DIR)/se_omega_zx_laser.s: MID2AGB_FLAGS := -G002 -P220
$(MIDI_DIR)/se_unk_137.s: MID2AGB_FLAGS := -E -P090
$(MIDI_DIR)/se_unk_139.s: MID2AGB_FLAGS := -E -P120
$(MIDI_DIR)/se_unk_13a.s: MID2AGB_FLAGS := -E -P120
$(MIDI_DIR)/se_omegazero_damage_13b.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_unk_13e.s: MID2AGB_FLAGS := -E -G002 -P020
$(MIDI_DIR)/se_unk_13f.s: MID2AGB_FLAGS := -E -P120
$(MIDI_DIR)/se_rock_fall.s: MID2AGB_FLAGS := -E -P120
$(MIDI_DIR)/se_unk_143.s: MID2AGB_FLAGS := -E -G002 -P220
$(MIDI_DIR)/se_unk_144.s: MID2AGB_FLAGS := -E -G002 -P220
$(MIDI_DIR)/se_claveker_atk.s: MID2AGB_FLAGS := -E -G001 -P020
$(MIDI_DIR)/se_gallisni_atk.s: MID2AGB_FLAGS := -E -G001 -P220
$(MIDI_DIR)/se_unk_147.s: MID2AGB_FLAGS := -E -G000 -P020
$(MIDI_DIR)/se_teleport.s: MID2AGB_FLAGS := -G001 -P020
$(MIDI_DIR)/se_flopper_explode.s: MID2AGB_FLAGS := -G000 -P020
$(MIDI_DIR)/se_unk_14f.s: MID2AGB_FLAGS := -G000 -P020

$(MIDI_ASMS): %.s: %.mid
	$(MID2AGB) $< $@ $(MID2AGB_FLAGS)
