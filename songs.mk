MID_SUBDIR = sound/songs/midi

midi: $(subst .mid,.o,$(wildcard $(MID_SUBDIR)/*.mid))

$(MID_BUILDDIR)/%.o: $(MID_SUBDIR)/%.s
	$(AS) $(ASFLAGS) -o $@ $<

clean-midi:
	@rm -f $(MID_SUBDIR)/*.{s,o}

$(MID_SUBDIR)/se_cursor.s: %.s: %.mid
	$(MID) $< $@ -G000 -P120

$(MID_SUBDIR)/se_rbase_pre_door.s: %.s: %.mid
	$(MID) $< $@ -E -G002 -P020

$(MID_SUBDIR)/se_unk_110.s: %.s: %.mid
	$(MID) $< $@ -E -G002 -P020

$(MID_SUBDIR)/se_unk_111.s: %.s: %.mid
	$(MID) $< $@ -E -G002 -P120

$(MID_SUBDIR)/se_unk_112.s: %.s: %.mid
	$(MID) $< $@ -E -P220

$(MID_SUBDIR)/se_unk_113.s: %.s: %.mid
	$(MID) $< $@ -E -P020

$(MID_SUBDIR)/se_baby_elf_laugh.s: %.s: %.mid
	$(MID) $< $@ -E -G002 -P020

$(MID_SUBDIR)/se_baby_elf_laugh_2.s: %.s: %.mid
	$(MID) $< $@ -E -G002 -P020

$(MID_SUBDIR)/se_baby_elf_117.s: %.s: %.mid
	$(MID) $< $@ -P220

$(MID_SUBDIR)/se_baby_elf_118.s: %.s: %.mid
	$(MID) $< $@ -P220

$(MID_SUBDIR)/se_baby_elf_death.s: %.s: %.mid
	$(MID) $< $@ -G002 -P020

$(MID_SUBDIR)/se_unk_11a.s: %.s: %.mid
	$(MID) $< $@ -P220

$(MID_SUBDIR)/se_camera_beep.s: %.s: %.mid
	$(MID) $< $@ -P220

$(MID_SUBDIR)/se_unk_11f.s: %.s: %.mid
	$(MID) $< $@ -P020

$(MID_SUBDIR)/se_unk_120.s: %.s: %.mid
	$(MID) $< $@ -G002 -P020

$(MID_SUBDIR)/se_unk_121.s: %.s: %.mid
	$(MID) $< $@ -G002 -P020

$(MID_SUBDIR)/se_unk_122.s: %.s: %.mid
	$(MID) $< $@ -P010

$(MID_SUBDIR)/se_sea_level.s: %.s: %.mid
	$(MID) $< $@ -P050

$(MID_SUBDIR)/se_unk_126.s: %.s: %.mid
	$(MID) $< $@ -G001 -P010

$(MID_SUBDIR)/se_unk_127.s: %.s: %.mid
	$(MID) $< $@ -G001 -P020

$(MID_SUBDIR)/se_blazin_fire_shower.s: %.s: %.mid
	$(MID) $< $@ -P020

$(MID_SUBDIR)/se_unk_129.s: %.s: %.mid
	$(MID) $< $@ -P020

$(MID_SUBDIR)/se_arcadia_ringtone.s: %.s: %.mid
	$(MID) $< $@ -P120

$(MID_SUBDIR)/se_unk_12b.s: %.s: %.mid
	$(MID) $< $@ -P020

$(MID_SUBDIR)/se_omega1_laser.s: %.s: %.mid
	$(MID) $< $@ -G001 -P020

$(MID_SUBDIR)/se_omega1_hoop.s: %.s: %.mid
	$(MID) $< $@ -G002 -P020

$(MID_SUBDIR)/se_omega1_teleport.s: %.s: %.mid
	$(MID) $< $@ -G002 -P020

$(MID_SUBDIR)/se_unk_12f.s: %.s: %.mid
	$(MID) $< $@ -P020

$(MID_SUBDIR)/se_omega_zx_buster_1.s: %.s: %.mid
	$(MID) $< $@ -G002 -P020

$(MID_SUBDIR)/se_omega_zx_131.s: %.s: %.mid
	$(MID) $< $@ -P020

$(MID_SUBDIR)/se_omega_zx_binding_ball.s: %.s: %.mid
	$(MID) $< $@ -G002 -P020

$(MID_SUBDIR)/se_omega_zx_spark_chaser.s: %.s: %.mid
	$(MID) $< $@ -P020

$(MID_SUBDIR)/se_omega_zx_laser.s: %.s: %.mid
	$(MID) $< $@ -E -G002 -P220

$(MID_SUBDIR)/se_unk_137.s: %.s: %.mid
	$(MID) $< $@ -E -P090

$(MID_SUBDIR)/se_unk_139.s: %.s: %.mid
	$(MID) $< $@ -E -P120

$(MID_SUBDIR)/se_unk_13a.s: %.s: %.mid
	$(MID) $< $@ -E -P120

$(MID_SUBDIR)/se_omegazero_damage_13b.s: %.s: %.mid
	$(MID) $< $@ -E -G002 -P020

$(MID_SUBDIR)/se_unk_13e.s: %.s: %.mid
	$(MID) $< $@ -E -G002 -P020

$(MID_SUBDIR)/se_unk_13f.s: %.s: %.mid
	$(MID) $< $@ -E -P120

$(MID_SUBDIR)/se_rock_fall.s: %.s: %.mid
	$(MID) $< $@ -E -P120

$(MID_SUBDIR)/se_unk_143.s: %.s: %.mid
	$(MID) $< $@ -E -G002 -P220

$(MID_SUBDIR)/se_unk_144.s: %.s: %.mid
	$(MID) $< $@ -E -G002 -P220

$(MID_SUBDIR)/se_claveker_atk.s: %.s: %.mid
	$(MID) $< $@ -E -G001 -P020

$(MID_SUBDIR)/se_gallisni_atk.s: %.s: %.mid
	$(MID) $< $@ -E -G001 -P220

$(MID_SUBDIR)/se_unk_147.s: %.s: %.mid
	$(MID) $< $@ -E -G000 -P020

$(MID_SUBDIR)/se_teleport.s: %.s: %.mid
	$(MID) $< $@ -G001 -P020

$(MID_SUBDIR)/se_flopper_explode.s: %.s: %.mid
	$(MID) $< $@ -G000 -P020

$(MID_SUBDIR)/se_unk_14f.s: %.s: %.mid
	$(MID) $< $@ -G000 -P020
