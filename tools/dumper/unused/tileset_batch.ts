#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run --unstable

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';
import { toHex } from '../../common/index.ts';
import { join } from 'https://deno.land/std/path/mod.ts';
import { existsSync } from 'https://deno.land/std/fs/exists.ts';

// All tileset dump are completed, so this tool is no longer needed.

const TOOL = './tools/dumper/unused/tileset.ts';

const main = async () => {
  const { args } = await new Command()
    .name('tileset_batch.ts')
    .version('1.0.0')
    .description('tileset.tsの処理を一気にやってくれるすごいやつ')
    .arguments('<header:string> <length:number> <output:string>')
    .usage('0x08721768 7 ./data/tilesets/volcano/')
    .parse(Deno.args);

  const header = Number(args[0]);
  const length = Number(args[1]);

  for (let i = 0; i < length; i++) {
    const dir = join(args[2], i.toString());
    console.log(dir);
    if (!existsSync(dir)) {
      Deno.mkdirSync(dir, { recursive: true });
    }
    const cmd = `${TOOL} 0x${toHex(header + (20 * i), 8)} -o ${dir}`;
    console.log(cmd);
    await Deno.run({ cmd: cmd.split(' ') }).status();
  }
};

main();
