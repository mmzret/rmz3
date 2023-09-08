#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run --unstable

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';

const FUNCTYPE = 'EnemyFunc';
const SCRIPT = './tools/dumper/tbl/tbl.ts';

const main = async () => {
  const { args } = await new Command()
    .name('enemy_table.ts')
    .version('1.0.0')
    .description('Wrapper of func_table.ts for Enemy')
    .arguments('<start> <length:string>')
    .usage('0x08366950 4')
    .parse(Deno.args);

  const cmd = [SCRIPT, args[0], args[1], `-p=void PROTOTYPE(struct Enemy* p)`, `--functype=${FUNCTYPE}`];
  const p = await Deno.run({ cmd, stdout: 'piped' });
  const result = await (new TextDecoder().decode(await p.output()));
  console.log(result);
};

main();
