#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run --unstable

import { Command } from '@cliffy/command';
import { loadU32, toHex } from '../common/index.ts';
import { join } from 'https://deno.land/std/path/mod.ts';
import { existsSync } from 'https://deno.land/std/fs/exists.ts';

const BASE = 0x0800_0000;
const FRAME_TBL = 0x085c0874;
const SEQ_TBL = 0x085d2d48;

const main = async () => {
  const { args, options } = await new Command()
    .name('sprite.ts')
    .version('1.0.0')
    .arguments('<id:number>')
    .option('-o, --output <dir:string>', 'output dir')
    .usage('252 -o ./sprites/static/volteel_human')
    .parse(Deno.args);

  const rom = Deno.readFileSync('baserom.gba');
  const id = Number(args[0]);
  const dir = options.output ?? '';
  if (dir !== '' && !existsSync(dir)) {
    console.error(`output dir not found: ${dir}`);
    Deno.exit(1);
  }

  {
    const addr = loadU32(rom, FRAME_TBL + (id * 4), BASE);
    const cmd = `tools/dumper/sprite/metasprite.ts 0x${toHex(addr, 8)}`;
    console.log(cmd);
    const p = await Deno.run({ cmd: cmd.split(' '), stdout: 'piped' });
    const result = formatJson(await (new TextDecoder().decode(await p.output())));
    if (dir.includes('sprites')) {
      const filepath = join(dir, 'metasprite.json');
      Deno.writeTextFileSync(filepath, result);
    } else {
      console.log(result);
    }
  }

  {
    const addr = loadU32(rom, SEQ_TBL + (id * 4), BASE);
    const cmd = `tools/dumper/sprite/sequence.ts 0x${toHex(addr, 8)} -l=gMotionCmd_SM${id}`;
    console.log(cmd);
    const p = await Deno.run({ cmd: cmd.split(' '), stdout: 'piped' });
    const result = formatJson(await (new TextDecoder().decode(await p.output())));
    if (dir.includes('sprites')) {
      const filepath = join(dir, 'sequence.json');
      Deno.writeTextFileSync(filepath, result);
    } else {
      console.log(result);
    }
  }
};

main();

const formatJson = (json: string) => {
  const data = JSON.parse(json);
  return JSON.stringify(data, null, 2);
};
