#!/usr/bin/env -S deno run --allow-read

import { Command } from '@cliffy/command';
import { addr, BASE, getU32, getU8, toHex } from '../../common/index.ts';

const SIZE = 12;

const main = async () => {
  const { args } = await new Command()
    .name('tone_header.ts')
    .version('1.0.0')
    .description('開始アドレス(start) から 長さNだけ、 C言語のToneData構造体としてダンプします。')
    .arguments('<rom> <start> <length:number>')
    .usage('rmz3.gba 0x0810e5a4 128')
    .parse(Deno.args);

  const rom = new DataView(Deno.readFileSync(args[0]).buffer);
  const start: addr = Number(args[1]);
  const length = args[2];
  for (let i = 0; i < length; i++) {
    const addr: addr = start + (i * SIZE);
    const tonedata = {
      type: getU8(rom, addr),
      key: getU8(rom, addr + 1),
      len: getU8(rom, addr + 2),
      pan_sweep: getU8(rom, addr + 3),
      attack: getU8(rom, addr + 8),
      decay: getU8(rom, addr + 9),
      sustain: getU8(rom, addr + 10),
      release: getU8(rom, addr + 11),
    };
    const wavaddr = getU32(rom, addr + 4);
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
