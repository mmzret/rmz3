#!/usr/bin/env -S deno run --allow-read

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';
import { loadU32, loadU8, toHex } from '../../common/index.ts';

const BASE = 0x0800_0000;
const SIZE = 12;
const KIND = ['DDP', 'DRP', 'DRP2'];

const main = async () => {
  const { args } = await new Command()
    .name('tone_header.ts')
    .version('1.0.0')
    .description('開始アドレス(start) から 長さNだけ、 C言語のToneData構造体としてダンプします。')
    .arguments('<rom> <start> <length:number>')
    .usage('rmz3.gba 0x0810e5a4 128')
    .parse(Deno.args);

  const rom = Deno.readFileSync(args[0]);
  const start = Number(args[1]);
  const length = args[2];
  for (let i = 0; i < length; i++) {
    const addr = start + (i * SIZE);
    const tonedata = {
      type: loadU8(rom, addr, BASE),
      key: loadU8(rom, addr + 1, BASE),
      len: loadU8(rom, addr + 2, BASE),
      pan_sweep: loadU8(rom, addr + 3, BASE),
      attack: loadU8(rom, addr + 8, BASE),
      decay: loadU8(rom, addr + 9, BASE),
      sustain: loadU8(rom, addr + 10, BASE),
      release: loadU8(rom, addr + 11, BASE),
    };
    const wavaddr = loadU32(rom, addr + 4, BASE);
    let wav = `(struct WaveData *)0x${toHex(wavaddr, 8)}`;
    if (wavaddr > BASE) {
      wav = `&DirectSoundWaveData_unk_${toHex(wavaddr, 8).toLowerCase()}`;
    }
    console.log(`[${i}] = {
    type: ${tonedata.type},
    key: ${tonedata.key},
    length: ${tonedata.len},
    pan_sweep: ${tonedata.pan_sweep},
    wav: ${wav},
    attack: ${tonedata.attack},
    decay: ${tonedata.decay},
    sustain: ${tonedata.sustain},
    release: ${tonedata.release},
},`);
  }
};

main();
