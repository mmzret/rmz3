#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

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

  const cmd = new Deno.Command(SCRIPT, {
    args: [args[0], args[1], `-p=void PROTOTYPE(struct Projectile* p)`, `--functype=${FUNCTYPE}`],
    stdout: 'piped',
  });
  const { stdout } = await cmd.output();
  const result = await (new TextDecoder().decode(stdout));
  console.log(result);
};

main();
