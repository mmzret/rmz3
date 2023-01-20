# Dump cfg file for pokemium/gbadisasm-go@develop
# @author   Pokemium (2022-02-26)
# @category GBA

import csv
import os

cur_file_idx = 0  # main.s

file_begins = [
    # [0x0800_0000, "main"]
]

func_modes = {
    True: "thumb_func",
    False: "arm_func",
}

def load_file_delimiter(delimiter_path):
    """
    Load delimiter csv file into file_begins.

    `./cfg_dumper.csv` is sample.

    Args:
        delimiter_path (str): delimiter csv file path
    """
    if delimiter_path.endswith(".csv"):
        with open(delimiter_path) as f:
            reader = csv.reader(f, delimiter=",", quotechar='"')
            for row in reader:
                addr = int(row[0], 16)
                name = row[1]
                pair = [addr, name]

                found = False
                for elm in file_begins:
                    if elm[0] == addr:
                        found = True
                        break
                
                if not found:
                    file_begins.append(pair)



def is_thumb_function(func):
    """
    https://github.com/NationalSecurityAgency/ghidra/issues/1132#issuecomment-540840481

    Returns:
        bool: Is func THUMB?
    """
    r = currentProgram.getRegister("TMode")
    value = currentProgram.programContext.getRegisterValue(r, func.entryPoint)
    return value.unsignedValueIgnoreMask == 1


def dump_gbadisasm_config(start_addr, max=-1):
    """
    Args:
        start_addr (int): start address e.g. 0x08000000
        max (int): maximum number of functions for dump
    
    Returns:
        string: Dumped .cfg for https://github.com/camthesaxman/gbadisasm
    """
    result = ""

    i = 0
    f = getFunctionAfter(toAddr(start_addr-1))

    while True:
        result += dump_row(f)
        i += 1
        f = getFunctionAfter(f)
        if f is None:
            break
        if max >= 0 and i == max:
            break
    
    return result

def dump_row(func):
    mode = func_modes[is_thumb_function(func)]
    name = func.getName()
    addr = func.getEntryPoint()

    for elm in file_begins:
        if toAddr(elm[0]) == addr:
            return "file_begin 0x{} {}\n{} 0x{} {}\n".format(toAddr(elm[0]), elm[1], mode, addr, name)

    return "{} 0x{} {}\n".format(mode, addr, name)


def write_cfg(s):
    cwd = os.getcwd()
    filename = askString("Output Path", cwd+"/")

    if filename == "":
        filename = "rom.cfg"
    elif not filename.endswith(".cfg"):
        filename = filename + ".cfg"
    dst = cwd + "/" + filename

    print("Write cfg file into {}".format(dst))
    with open(dst, 'w') as f:
        f.write(s)

def main():
    try:
        delimiter_path = askFile("Delimiter CSV", "Open")
        load_file_delimiter(str(delimiter_path))
    except:
        pass

    if len(file_begins) == 0:
        file_begins.append([0x08000000, "main"])   # default

    result = dump_gbadisasm_config(0x08000000, -1)
    write_cfg(result)

if __name__ == "__main__":
    main()
