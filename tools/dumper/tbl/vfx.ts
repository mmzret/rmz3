#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run --unstable

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';

const FUNCTYPE = 'VFXFunc';
const SCRIPT = './tools/dumper/tbl/tbl.ts';

const main = async () => {
  const { args } = await new Command()
    .name('vfx_table.ts')
    .version('1.0.0')
    .description('Wrapper of func_table.ts for VFX')
    .arguments('<start> <length:string>')
    .usage('0x0836ed80 2')
    .parse(Deno.args);

  const params = [args[0], args[1], `-p=void PROTOTYPE(struct VFX* vfx)`, `--functype=${FUNCTYPE}`];
  const cmd = new Deno.Command(SCRIPT, {
    args: params,
    stdout: 'piped',
  });
  const { stdout } = await cmd.output();
  const result = await (new TextDecoder().decode(stdout));
  console.log(result);
};

main();
