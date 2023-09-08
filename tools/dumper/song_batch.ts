#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from "https://deno.land/x/cliffy@v0.25.4/command/mod.ts";

const TOOL = "./tools/dumper/song.ts";
const start = 192;
const list = [
  "bgm_omega2_battle",
  "bgm_zero_return",
  "bgm_omegazero_appear",
  "bgm_cannon_ball",
  "bgm_epilogue",
  "bgm_ending",
  "se_unk_c6",
  "se_unk_c7",
  "se_unk_c8",
  "se_cubit_transform",
  "se_cubit_jump",
  "se_unk_cb",
  "se_cubit_warp",
  "se_cubit_onibi_charge",
  "se_cubit_onibi",
  "se_cubit_kaen_guruma",
  "se_cubit_flame_rain",
  "se_cubit_damage",
  "se_cubit_death",
  "se_tretista_voice_d3",
  "se_tretista_grawl",
  "se_tretista_throw",
  "se_tretista_hell_bouncers",
  "se_tretista_assemble_puppy",
  "se_tretista_fold_pipe",
  "se_tretista_gas_voice",
  "se_tretista_gas",
  "se_tretista_laser_crow",
  "se_tretista_damage",
  "se_tretista_death",
  "se_tretista_landing",
  "bgm_darkelf",
  "se_unk_e0",
  "se_unk_e1",
  "se_unk_e2",
  "se_paqua_mod_voice_e3",
  "se_paqua_mod_voice_e4",
  "se_paqua_mod_voice_e5",
  "se_paqua_mod_laser",
  "se_omega1_growl",
  "se_omega1_death",
  "se_omegazero_voice_e9",
  "se_omegazero_voice_ea",
  "se_omegazero_voice_eb",
  "se_omegazero_voice_ec",
  "se_omegazero_voice_ed",
  "se_omegazero_charge_saber",
  "se_omegazero_ryuenjin",
  "se_omegazero_rekkoha",
  "se_omegazero_messenkou",
  "se_omegazero_damage_f2",
  "se_omegazero_meshia",
  "se_fefnir_damage",
  "se_fefnir_atk",
  "se_leviathan_damage",
  "se_leviathan_atk",
  "se_harpuia_damage",
  "se_harpuia_atk",
  "se_phantom_start",
  "se_phantom_zan",
  "se_phantom_shuriken",
  "se_phantom_retsu",
  "se_phantom_utsusemi",
  "se_phantom_damage",
  "se_phantom_se",
  "se_unk_101",
  "se_unk_102",
  "se_unk_103",
  "se_unk_104",
  "se_unk_105",
  "se_unk_106",
  "se_shell_crawler",
  "se_unk_108",
  "se_unk_109",
  "se_unk_10a",
  "se_unk_10b",
  "se_unk_10c",
];

const main = async () => {
  await new Command()
    .name("song_batch.ts")
    .version("1.0.0")
    .description("song.tsの処理を一気にやってくれるすごいやつ")
    .parse(Deno.args);

  for (let i = 0; i < list.length; i++) {
    const song = list[i];
    if (song === "mus_dummy") continue;
    console.log(`.include "sound/songs/${song}.inc"`);
    const file = await Deno.open(`sound/songs/${song}.inc`, {
      read: true,
      write: true,
      create: true,
    });
    const n = start + i;
    const cmd = `${TOOL} ${n} ${song}`;
    const p = await Deno.run({ cmd: cmd.split(" "), stdout: "piped" });
    await file.writeSync(await p.output());
    file.close();
  }
};

main();
