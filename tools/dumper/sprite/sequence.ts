#!/usr/bin/env -S deno run --allow-read --unstable

import { Command } from '@cliffy/command';
import { loadU32 } from '../../common/index.ts';

const BASE = 0x0800_0000;
const SIZE = 4;

type MotionCmd = {
  frameIdx: number;
  duration: number;
};

const main = async () => {
  const { args, options } = await new Command()
    .name('sequence.ts')
    .version('1.0.0')
    .description('開始アドレス(start) から 長さNだけ、 JSONのMotionCmd構造体としてダンプします。')
    .arguments('<start>')
    .option('-l, --label=[s:string]', 'label name')
    .usage('0x083b5864')
    .parse(Deno.args);

  const rom = Deno.readFileSync('baserom.gba');
  const start = Number(args[0]);
  const length = (loadU32(rom, start, BASE) - start) / 4;

  const result: MotionCmd[][] = [];
  for (let i = 0; i < length; i++) {
    let idx = 0;
    const arr = loadU32(rom, start + SIZE * i, BASE) - BASE;
    const seq: MotionCmd[] = [];
    for (;;) {
      const frameIdx = rom[arr + (idx * 2) + 0];
      const duration = rom[arr + (idx * 2) + 1];
      seq.push({ frameIdx, duration });
      if (duration === 254 || duration === 255) {
        break;
      }
      idx++;
    }
    result.push(seq);
  }

  if (options.label && options.label !== '') {
    console.log(JSON.stringify({ label: options.label, data: result }));
  } else {
    console.log(JSON.stringify({ data: result }));
  }
};

main();
