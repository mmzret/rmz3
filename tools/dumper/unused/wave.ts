#!/usr/bin/env -S deno run --allow-read --allow-run

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';
import { loadU32, toHex } from '../../common/index.ts';

const BASE = 0x0800_0000;
const MIN = 0x0831e9dc;
const SIZE = 12;

const main = async () => {
  const { args } = await new Command()
    .name('tone.ts')
    .version('1.0.0')
    .description('開始アドレス(start) から 長さNだけ、 C言語のToneData構造体の.wavデータをダンプします')
    .arguments('<rom> <start> <length:number>')
    .usage('rmz3.gba 0x0810e5a4 128')
    .parse(Deno.args);

  const rom = Deno.readFileSync(args[0]);
  const start = Number(args[1]);
  const length = args[2];
  for (let i = 0; i < length; i++) {
    const addr = start + (i * SIZE);
    const wave = loadU32(rom, addr + 4, BASE);
    if (wave < MIN) {
      continue;
    }
    let size = loadU32(rom, wave + 12, BASE);
    size += 4 - (size % 4);
    const from = toHex(wave, 8);
    const wave_end = wave + 16 + size;
    const to = toHex(wave_end, 8);

    // deno-fmt-ignore
    const file = `unk_${from.toLowerCase()}`;

    // deno-fmt-ignore
    const target = `sound/direct_sound_samples/${file}.bin`;

    // deno-fmt-ignore
    const cmd = `./tools/dumper/bin.ts ${args[0]} 0x${from} 0x${to} ${target}`
    // console.log(cmd);

    if (wave > BASE && wave >= MIN) {
      console.log(`  .balign 4, 0
.global DirectSoundWaveData_${file}
DirectSoundWaveData_${file}::
  .incbin "${target}"\n`);
      await Deno.run({ cmd: cmd.split(' ') }).status();
    }
  }
};

main();
