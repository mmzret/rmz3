#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run --unstable

import { Command } from '@cliffy/command';

const FUNCTYPE = 'ProjectileFunc';
const SCRIPT = './tools/dumper/tbl/tbl.ts';

const main = async () => {
  const { args } = await new Command()
    .name('projectile_table.ts')
    .version('1.0.0')
    .description('Wrapper of func_table.ts for Projectile')
    .arguments('<start> <length:string>')
    .usage('0x0836b350 2')
    .parse(Deno.args);

  const cmd = [SCRIPT, args[0], args[1], `-p=void PROTOTYPE(struct Projectile* p)`, `--functype=${FUNCTYPE}`];
  const p = await Deno.run({ cmd, stdout: 'piped' });
  const result = await (new TextDecoder().decode(await p.output()));
  console.log(result);
};

main();
